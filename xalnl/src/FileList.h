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
* $Id: FileList.h,v 1.31 2014/03/15 01:49:46 bowkenken Exp $
***************************************************************/

#ifndef FILE_LIST_H
#define FILE_LIST_H	1

#if HAVE_UNISTD_H
# include <unistd.h>
#endif // HAVE_UNISTD_H

#include <stdlib.h>
#include <stdio.h>

#if !defined( D_DOS ) && !defined( D_DOWS )
# include <dirent.h>
# include <sys/stat.h>
#endif

#ifdef D_MFC
# include "xalnl-dows/stdafx.h"
#endif // D_GTK

#include "GameMisc.h"

////////////////////////////////////////////////////////////////
// 指定された拡張子のファイルを検索する
// 見つからなかったら、ディレクトリ階層を基準ディレクトリ
// まで、さかのぼる
////////////////////////////////////////////////////////////////

#if	defined( D_DOS ) || defined( D_MFC )
# define	STR_DIR_BASE	"_alnl/xalnl/"
#else
# define	STR_DIR_BASE	".alnl/xalnl/"
#endif

#define	STR_DIR_BASE_GRAPH	STR_DIR_BASE "graph/"

static std::string sDirBaseSelGraph = "default/";

class FileList {
public:

private:
	// 基準ディレクトリ
	std::string sDirBase;
	// 基準ディレクトリからの相対パス
	std::string sDirSub;
	// フルパス
	std::string sDirFullPath;

	// 拡張子のリスト。スペースで区切る
	std::string sExt;

	// １つでもファイルが見つかったか？
	// 見つかったらディレクトリはさかのぼらない
	bool bFlagExist;

#ifdef D_MFC
	// ファイル・サーチ

	bool bFlagUseWin32ApiFind;

	WIN32_FIND_DATA findData;
	HANDLE hFindFile;

	CFileFind finder;

	bool bFlagOpen;
#else // D_MFC
	// サーチ中のディレクトリ
	DIR *dpFile;
#endif // D_MFC

public:
	FileList();
	~FileList();

	bool reset( std::string dir, std::string ext );
	std::string next();

	std::string getBaseDir();

	static std::string setStrDirSelMap( std::string dir );
	static std::string setStrDirSelGraph( std::string dir );
	static std::string setStrDirSelMusic( std::string dir );
	static std::string setStrDirSelSound( std::string dir );

	static std::string jointDir(
		std::string dir1, std::string dir2 );
	static std::string getDir( std::string path );
	static std::string getFileName( std::string path );
	static std::string getExt( std::string name );

private:
	std::string nextNode();
};

#endif /* FILE_LIST_H */
