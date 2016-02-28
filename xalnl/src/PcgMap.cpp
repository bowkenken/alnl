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
	pCgWestTried = NULL;
}

////////////////////////////////////////////////////////////////
// デストラクタ
////////////////////////////////////////////////////////////////

PcgMap::~PcgMap()
{
}

////////////////////////////////////////////////////////////////
// キャラグラの初期化
////////////////////////////////////////////////////////////////

void PcgMap::initPcgCharGraph()
{
	if( !g_flg_gui )
		return;

	if( pCgWestTried != NULL )
		delete pCgWestTried;
	pCgWestTried = new PcgCharGraph;
	pCgWestTried->init();
}

////////////////////////////////////////////////////////////////
// 初期化
////////////////////////////////////////////////////////////////

void PcgMap::init()
{
	if( !g_flg_gui )
		return;

	initPcgCharGraph();

	// パターン検索を設定

	//@@@WSCstring path = cnf->getDir();
	//long w = path.getWords( "/" );
	//WSCstring dir = path.getWord( w - 1, "/" );

	//WSCstring ext = STR_GRAPH_FILE_EXT;

	//FileList::setStrDirSelGraph( dir );
	//FileList fls;

	loadCharGraphParserFile();

	parsePcgCharGraph();
}

////////////////////////////////////////////////////////////////
// リセット
////////////////////////////////////////////////////////////////

void PcgMap::reset()
{
	if( !g_flg_gui )
		return;

	//@@@resetUpdateFlg();

	if( g_flg_text_mode )
		return;

	//@@@resetMap();
}

////////////////////////////////////////////////////////////////
// キャラグラのパーサ・スクリプトの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::loadCharGraphParserFile()
{
	// fprintf( stderr, "loadCharGraphParserFile(): begin\n" );

	WSCstring path = "";
	path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	path = FileList::jointDir( path, "map/read-cg-json.js" );

	FILE *fp = fopen( path, "r" );
	if( fp == NULL )
		return;
	// fprintf( stderr, "fopen: '%s'\n", path.c_str() );

	sCharGraphParserFile = "";

	// fprintf( stderr, "----\n" );
	while( !feof( fp ) ){
		int c = fgetc( fp );
		if( c == EOF )
			break;

		sCharGraphParserFile += c;
		// fprintf( stderr, "%c", c );
	}
	// fprintf( stderr, "----\n" );

	fclose( fp );
	// fprintf( stderr, "fclose: OK\n" );
	// fprintf( stderr, "loadCharGraphParserFile(): end\n" );
}

////////////////////////////////////////////////////////////////
// キャラグラのパース
////////////////////////////////////////////////////////////////

void PcgMap::parsePcgCharGraph()
{
	if( !g_flg_gui )
		return;

	WSCstring path = "";
	path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	path = FileList::jointDir( path,
			"map/west/tried/_tile/town-obj-alnl.png" );

	pCgWestTried->setPath( path );

	//@@@ pCgWestTried->@@@();
}

