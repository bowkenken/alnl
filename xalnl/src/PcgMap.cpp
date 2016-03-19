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
***************************************************************/

////////////////////////////////////////////////////////////////
// マップ
////////////////////////////////////////////////////////////////

#define	PCG_MAP_CPP	1
#include "inc.h"

////////////////////////////////////////////////////////////////
// コンストラクタ
////////////////////////////////////////////////////////////////

PcgMap::PcgMap()
{
	pTileWestTried = NULL;
}

////////////////////////////////////////////////////////////////
// デストラクタ
////////////////////////////////////////////////////////////////

PcgMap::~PcgMap()
{
}

////////////////////////////////////////////////////////////////
// 初期化
////////////////////////////////////////////////////////////////

void PcgMap::init()
{
	if( !g_flg_gui )
		return;

	// fprintf( stderr, "PcgMap::init(): begin\n" ); //

	initPcgTile();
	initPcgCharGraph();

	// パターン検索を設定

	//@@@
	//WSCstring path = cnf->getDir();
	//long w = path.getWords( "/" );
	//WSCstring dir = path.getWord( w - 1, "/" );

	//WSCstring ext = STR_GRAPH_FILE_EXT;

	//FileList::setStrDirSelGraph( dir );
	//FileList fls;

	// タイル

	// fprintf( stderr, "\n" ); //
	// fprintf( stderr, "readTileJsonFile()\n" ); //
	readTileJsonFile();
	// fprintf( stderr, "loadTileParserFile()\n" ); //
	loadTileParserFile();

	// fprintf( stderr, "parsePcgTile()\n" ); //
	parsePcgTile();

	// キャラグラ

	// fprintf( stderr, "\n" ); //
	// fprintf( stderr, "readCharGraphJsonFile()\n" ); //
	readCharGraphJsonFile();
	// fprintf( stderr, "loadCharGraphParserFile()\n" ); //
	loadCharGraphParserFile();

	// fprintf( stderr, "parsePcgCharGraph()\n" ); //
	parsePcgCharGraph();

	// fprintf( stderr, "PcgMap::init(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// タイルの初期化
////////////////////////////////////////////////////////////////

void PcgMap::initPcgTile()
{
	if( !g_flg_gui )
		return;

	if( pTileWestTried != NULL )
		delete pTileWestTried;
	pTileWestTried = new PcgTile;
	pTileWestTried->init();
}

////////////////////////////////////////////////////////////////
// キャラグラの初期化
////////////////////////////////////////////////////////////////

void PcgMap::initPcgCharGraph()
{
	if( !g_flg_gui )
		return;

	aCharGraph.clear();
}

////////////////////////////////////////////////////////////////
// リセット
////////////////////////////////////////////////////////////////

void PcgMap::reset()
{
	if( !g_flg_gui )
		return;

	if( g_flg_text_mode )
		return;
}

////////////////////////////////////////////////////////////////
// タイルのパーサ・スクリプトの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::loadTileParserFile()
{
	WSCstring path = "";
	path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	path = FileList::jointDir( path,
			"map/xalnl-3.4.20/read-tile-json.js" );

	sTileParserScript = loadParserFile( path );
}

////////////////////////////////////////////////////////////////
// キャラグラのパーサ・スクリプトの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::loadCharGraphParserFile()
{
	WSCstring path = "";
	path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	path = FileList::jointDir( path,
			"map/xalnl-3.4.20/read-cg-json.js" );

	sCharGraphParserScript = loadParserFile( path );
}

////////////////////////////////////////////////////////////////
// パーサ・スクリプトの読み込み
////////////////////////////////////////////////////////////////

WSCstring PcgMap::loadParserFile( WSCstring path )
{
	// fprintf( stderr, "loadParserFile(): begin\n" ); //

	// fprintf( stderr, "fopen: '%s'\n", path.c_str() ); //
	FILE *fp = fopen( path, "r" );
	if( fp == NULL )
		return "";

	WSCstring str = "";

	// fprintf( stderr, "----\n" ); //
	while( !feof( fp ) ){
		int c = fgetc( fp );
		if( c == EOF )
			break;

		str += c;
		// fprintf( stderr, "%c", c ); //
	}
	// fprintf( stderr, "----\n" ); //

	fclose( fp );
	// fprintf( stderr, "fclose: OK\n" ); //

	// fprintf( stderr, "loadParserFile(): end\n" ); //
	return str;
}

////////////////////////////////////////////////////////////////
// タイルの JSON ファイルの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::readTileJsonFile()
{
	WSCstring path = "";
	path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	path = FileList::jointDir( path,
			"map/xalnl-3.4.20/west/town/tried/"
			"tried.json" );

	sTileJson = readJsonFile( path );
}

////////////////////////////////////////////////////////////////
// キャラグラの JSON ファイルの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::readCharGraphJsonFile()
{
//@@@	WSCstring dir = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
//@@@	dir = FileList::jointDir( path, "west/town/_tile/" );
//@@@	dir = FileList::jointDir( path, "map/west/town/tried/_tile/" );
//@@@			"town-obj-alnl.png.cg.json"

	// fprintf( stderr, "readCharGraphJsonFile(): begin\n" ); //

	// パターン検索を設定

	WSCstring dirBase = "xalnl-3.4.20/";
	WSCstring dirSub = "west/town/_tile/";
	WSCstring ext = STR_GRAPH_FILE_EXT;

	FileList::setStrDirSelMap( dirBase );
	FileList fls;

	// ファイルを検索

	//@@@ aCharGraph.clear();
	fls.reset( dirSub, ext );
	// fprintf( stderr, "FileList::getBaseDir(): [%s]\n",
	//		fls.getBaseDir().c_str() ); //

	for( long i = 0; i < LOOP_MAX_100; i++ ){
		WSCstring path = fls.next();
		// fprintf( stderr, "path: [%s]\n", path.c_str() ); //
		if( path.getChars() <= 0 )
			break;

		PcgCharGraph *cg = new PcgCharGraph();
		cg->setPath( path );
		WSCstring pathJson = cg->charPath;
//@@@
//pathJson = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
//pathJson = FileList::jointDir( pathJson, "map/xalnl-3.4.20/west/town/_tile/" );
//pathJson = FileList::jointDir( pathJson, "town-obj-alnl.png.cg.json" );
//@@@
		fprintf( stderr, "pathJson: [%s]\n", pathJson.c_str() ); //

		cg->setCgJsonData( readJsonFile( pathJson ) );
		aCharGraph.push_back( *cg );
	}

	// fprintf( stderr, "readCharGraphJsonFile(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// JSON ファイルの読み込み
////////////////////////////////////////////////////////////////

WSCstring PcgMap::readJsonFile( WSCstring path )
{
	// fprintf( stderr, "readJsonFile(): begin\n" ); //

	// fprintf( stderr, "fopen: '%s'\n", path.c_str() ); //
	FILE *fp = fopen( path, "r" );
	if( fp == NULL )
		return "";

	WSCstring str = "";

	// fprintf( stderr, "----\n" ); //
	while( !feof( fp ) ){
		int c = fgetc( fp );
		if( c == EOF )
			break;

		str += c;
		// fprintf( stderr, "%c", c ); //
	}
	// fprintf( stderr, "----\n" ); //

	fclose( fp );
	// fprintf( stderr, "fclose: OK\n" ); //

	// fprintf( stderr, "readJsonFile(): end\n" ); //
	return str;
}

////////////////////////////////////////////////////////////////
// タイルのパース
////////////////////////////////////////////////////////////////

void PcgMap::parsePcgTile()
{
	if( !g_flg_gui )
		return;

	WSCstring path = "";
	path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	path = FileList::jointDir( path,
			"map/xalnl-3.4.20/west/town/tried/"
			"tried.json" );

	// fprintf( stderr, "parse: [%s]\n", path.c_str() ); //
	pTileWestTried->setPath( path );
	pTileWestTried->setTileJsonData( sTileJson );
	pTileWestTried->parse( sTileParserScript );
}

////////////////////////////////////////////////////////////////
// キャラグラのパース
////////////////////////////////////////////////////////////////

void PcgMap::parsePcgCharGraph()
{
	if( !g_flg_gui )
		return;

	//@@@WSCstring path = "";
	//@@@path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	//@@@path = FileList::jointDir( path,
	//@@@		"map/west/town/tried/_tile/"
	//@@@		"town-obj-alnl.png" );

	long size = aCharGraph.size();
	for( long i = 0; i < size; i++ ){
		// fprintf( stderr, "parse: [%s]\n",
		//		aCharGraph[i].charPath.c_str() ); //

		aCharGraph[i].parse( sCharGraphParserScript );
	}
}
