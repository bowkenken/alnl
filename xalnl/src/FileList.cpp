/***************************************************************
* L&L - Labyrinths & Legends
* Copyright (c) 1993-2014 YOSHIMURA Tomohiko All rights reserved.
* 
* Created by BowKenKen
*   URL: https://sourceforge.jp/projects/lnl/
* 
* License is GPL
* 
* 本プログラムはフリー・ソフトウェアです。
* あなたは、 Free Software Foundation が公表した
*  GNU 一般公有使用許諾の「バージョン２」
* 或はそれ以降の各バージョンの中からいずれかを選択し、
* そのバージョンが定める条項に従って本プログラムを
* 再頒布または変更することができます。
* 
* 本プログラムは有用とは思いますが、頒布にあたっては、
* 市場性及び特定目的適合性についての暗黙の保証を含めて,
* いかなる保証も行ないません。
* 詳細については GNU 一般公有使用許諾書をお読みください。
* 
* あなたは、本プログラムと一緒に GNU 一般公有使用許諾書
* の写しを受け取っているはずです。そうでない場合は、
*   Free Software Foundation, Inc.,
*   59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
* へ手紙を書いてください。
* 
* $Id: FileList.cpp,v 1.27 2014/01/07 23:55:39 bowkenken Exp $
***************************************************************/

#define FILE_LIST_CPP	1
#include "inc.h"

////////////////////////////////////////////////////////////////
// ファイル検索のコンストラクタ
////////////////////////////////////////////////////////////////

FileList::FileList()
{
	sDirBase = "";
	sDirSub = "";
	sDirFullPath = "";
	sExt = "";
	bFlagExist = false;

#ifdef D_MFC
	bFlagUseWin32ApiFind = true;
	bFlagOpen = false;
#else // D_MFC
	dpFile = NULL;
#endif // D_MFC
}

////////////////////////////////////////////////////////////////
// ファイル検索のデストラクタ
////////////////////////////////////////////////////////////////

FileList::~FileList()
{
#ifndef D_MFC
	if( dpFile != NULL ){
		closedir( dpFile );
		dpFile = NULL;
	}
#endif // D_MFC
}

////////////////////////////////////////////////////////////////
// 検索のリセット
// std::string dirSub : 基準からの相対パス
// std::string ext : 拡張子のリスト
// return : エラーが無かったか？
////////////////////////////////////////////////////////////////

bool FileList::reset( std::string dirSub, std::string ext )
{
#ifdef D_MFC
	if( bFlagOpen ){
		if( bFlagUseWin32ApiFind )
			::FindClose( hFindFile );
		else
			finder.Close();

		bFlagOpen = false;
	}
#else // D_MFC
	if( dpFile != NULL ){
		closedir( dpFile );
		dpFile = NULL;
	}
#endif // D_MFC

	sDirBase = jointDir( getBaseDir(), "" );
	sDirSub = jointDir( dirSub, "" );
	sDirFullPath = jointDir( sDirBase, sDirSub );

	make_dir( sDirFullPath.c_str() );

	sExt = ext;
	bFlagExist = false;

#ifdef D_MFC
	std::string path = jointDir( sDirFullPath, "*.*" );
	path.replaceString( "/", "\\", 0 );

	if( bFlagUseWin32ApiFind ){
		ZeroMemory( &findData, sizeof( findData ) );
		hFindFile = ::FindFirstFile( path, &findData );
		if( hFindFile == INVALID_HANDLE_VALUE )
			return false;

		findData.dwFileAttributes = 0
				| FILE_ATTRIBUTE_ARCHIVE
				| FILE_ATTRIBUTE_COMPRESSED
				| FILE_ATTRIBUTE_READONLY
				;
	} else {
		if( !finder.FindFile( path ) )
			return false;

# if 0
//@@@
		finder.MatchesMask( 0
				| FILE_ATTRIBUTE_ARCHIVE
				| FILE_ATTRIBUTE_COMPRESSED
				| FILE_ATTRIBUTE_READONLY
		);
# endif
	}

	bFlagOpen = true;
#else // D_MFC
	dpFile = opendir( sDirFullPath.c_str() );
	if( dpFile == NULL )
		return false;
#endif // D_MFC

	return true;
}

////////////////////////////////////////////////////////////////
// 次のファイルを検索
// 見つからなかったらディレクトリをさかのぼる
// return : 見つかったファイルの絶対パス
////////////////////////////////////////////////////////////////

std::string FileList::next()
{
	for( long i = 0; i < LOOP_MAX_100; i++ ){
		std::string path = nextNode();

		if( path.length() > 0 )
			return path;
		if( bFlagExist )
			return "";

		// ディレクトリを根に向かって遡る

		for( long j = 0; j < LOOP_MAX_100; j++ ){
			long nWords = ::getWordNum( sDirSub, "/" );
			if( nWords <= 1 )
				return "";

			long nPos = ::getWordPos( sDirSub, nWords - 2, "/" );
			if( nPos > -1 )
				sDirSub.erase( nPos, std::string::npos );
			if( reset( sDirSub, sExt ) )
				break;
		}
	}

	return "";
}

////////////////////////////////////////////////////////////////
// 次のファイルを検索
// return : 見つかったファイルの絶対パス
////////////////////////////////////////////////////////////////

std::string FileList::nextNode()
{
#ifdef D_MFC
	if( !bFlagOpen )
		return "";
#else // D_MFC
	if( dpFile == NULL )
		return "";
#endif // D_MFC

	while( 1 ){
#ifdef D_MFC
		std::string name;

		if( bFlagUseWin32ApiFind ){
			if( !::FindNextFile( hFindFile, &findData ) )
				break;

			if( findData.dwFileAttributes
					& (FILE_ATTRIBUTE_DIRECTORY) ){
				continue;
			}

			name = jointDir( sDirFullPath,
					findData.cFileName );
		} else {
			if( !finder.FindNextFile() )
				break;

			if( finder.IsDirectory() )
				continue;

			name = finder.GetFilePath();
		}
		name.replaceString( "\\", "/", 0 );
#else // D_MFC
		struct dirent *buf = readdir( dpFile );
		if( buf == NULL )
			break;

		std::string fileName = buf->d_name;
# ifdef D_DOWS
		fileName.replaceString( "\\", "/", 0 );
# endif // D_DOWS
		std::string name = jointDir( sDirFullPath, fileName );

		struct stat statBuf;
		stat( name.c_str(), &statBuf );
		if( S_ISDIR( statBuf.st_mode ) )
			continue;
#endif // D_MFC

		std::string ext = getExt( name );
		long nExtMaxN = ::getWordNum( sExt, " " );
		for( long i = 0; i < nExtMaxN; i++ ){
			std::string curExt = getWord( sExt, i, " " );

			if( curExt == ext ){
				bFlagExist = true;
				return name;
			}
		}
	}

#ifdef D_MFC
	if( bFlagUseWin32ApiFind )
		::FindClose( hFindFile );
	else
		finder.Close();

	bFlagOpen = false;
#endif // D_MFC

	return "";
}

////////////////////////////////////////////////////////////////
// 基準ディレクトリを返す
// return : 基準ディレクトリ
////////////////////////////////////////////////////////////////

std::string FileList::getBaseDir()
{
	std::string dir = jointDir( get_home_dir(), STR_DIR_BASE );
	dir = jointDir( dir, sDirBaseSelGraph );

	return dir;
}

////////////////////////////////////////////////////////////////
// 基準ディレクトリを設定する (マップ)
// std::string dir : 基準ディレクトリ
// return : 基準ディレクトリ
////////////////////////////////////////////////////////////////

std::string FileList::setStrDirSelMap( std::string dir )
{
	sDirBaseSelGraph = jointDir( "map/", dir );

	return sDirBaseSelGraph;
}

////////////////////////////////////////////////////////////////
// 基準ディレクトリを設定する (画像)
// std::string dir : 基準ディレクトリ
// return : 基準ディレクトリ
////////////////////////////////////////////////////////////////

std::string FileList::setStrDirSelGraph( std::string dir )
{
	sDirBaseSelGraph = jointDir( "graph/", dir );

	return sDirBaseSelGraph;
}

////////////////////////////////////////////////////////////////
// 基準ディレクトリを設定する (BGM)
// std::string dir : 基準ディレクトリ
// return : 基準ディレクトリ
////////////////////////////////////////////////////////////////

std::string FileList::setStrDirSelMusic( std::string dir )
{
	sDirBaseSelGraph = jointDir( "music/", dir );

	return sDirBaseSelGraph;
}

////////////////////////////////////////////////////////////////
// 基準ディレクトリを設定する (SE)
// std::string dir : 基準ディレクトリ
// return : 基準ディレクトリ
////////////////////////////////////////////////////////////////

std::string FileList::setStrDirSelSound( std::string dir )
{
	sDirBaseSelGraph = jointDir( "sound/", dir );

	return sDirBaseSelGraph;
}

////////////////////////////////////////////////////////////////
// ディレクトリどうしを "/" を補間して連結する
// std::string dir1 : ディレクトリ名
// std::string dir2 : ディレクトリ名
// return : 補間後のディレクトリ名
////////////////////////////////////////////////////////////////

std::string FileList::jointDir(
	std::string dir1, std::string dir2 )
{
	const std::string sSlash = "/";

	int n = dir1.length() - 1;
	if( n < 0 )
		return( dir2 );

	if( dir1[n] == '/' )
		return( dir1 + dir2 );
	else
		return( dir1 + sSlash + dir2 );
}

////////////////////////////////////////////////////////////////
// パス名からディレクトリ名を切り出す
// std::string path : パス名
// return : ディレクトリ名
////////////////////////////////////////////////////////////////

std::string FileList::getDir( std::string path )
{
	for( long i = path.length() - 1; i >= 0; i-- ){
		if( path[i] == '/' ){
			path.erase( i + 1, path.length() - 1 - i );

			return path;
		}
	}

	return "";
}

////////////////////////////////////////////////////////////////
// パス名からファイル名を切り出す
// std::string path : パス名
// return : ファイル名
////////////////////////////////////////////////////////////////

std::string FileList::getFileName( std::string path )
{
	long w = ::getWordNum( path, "/" );
	std::string name = ::getWord( path, w - 1, "/" );

	return name;
}

////////////////////////////////////////////////////////////////
// ファイル名の拡張子部分を返す
// std::string name : ファイル名
// return : 拡張子
////////////////////////////////////////////////////////////////

std::string FileList::getExt( std::string name )
{
	for( long i = name.length() - 1; i >= 0; i-- ){
		if( name[i] == '.' ){
			name.erase( 0, i + 1 );

			return name;
		}
	}

	return "";
}
