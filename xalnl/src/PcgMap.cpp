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
// グローバル・インスタンス
////////////////////////////////////////////////////////////////

PcgMap gPcgMap;

////////////////////////////////////////////////////////////////
// コンストラクタ
////////////////////////////////////////////////////////////////

PcgMap::PcgMap()
{
	parserScriptTile = "";
	parserScriptCharGraph = "";

	tileTowns.clear();

	charGraphsTown.clear();
	charGraphsWorld.clear();

	mapLayersTowns.clear();
	mapLayersWorld.clear();

	currentTownMapKey = TOWN_MAP_KEY_TRIED;
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
	// close_game( 0 ); //
	// ::fprintf( stderr, "PcgMap::init(): begin\n" ); //

	initPcgTile();
	initPcgCharGraph();

	// タイル

	// ::fprintf( stderr, "\n" ); //
	// ::fprintf( stderr, "readJsonFileTile()\n" ); //
	readJsonFileTileAll();
	// ::fprintf( stderr, "loadParserFileTile()\n" ); //
	loadParserFileTile();

	// ::fprintf( stderr, "parsePcgTile()\n" ); //
	parsePcgTile();

	// キャラグラ

	// ::fprintf( stderr, "\n" ); //
	// ::fprintf( stderr, "readJsonFileCharGraphAll()\n" ); //
	readJsonFileCharGraphAll();
	// ::fprintf( stderr, "loadParserFileCharGraph()\n" ); //
	loadParserFileCharGraph();

	// ::fprintf( stderr, "parsePcgCharGraphAll()\n" ); //
	parsePcgCharGraphAll();

	// 文字に変換

	// ::fprintf( stderr, "transMap()\n" ); //
	transMapAll();

	// 街マップ

	// ::fprintf( stderr, "reset_all()\n" ); //
	resetTownPtn();

	// ::fprintf( stderr, "resetTownMap()\n" ); //
	resetTownMap();

	// ::fprintf( stderr, "loadTileSets()\n" ); //
	tileTowns[TOWN_MAP_KEY_TRIED]->loadTileSets();

	// ワールド・マップ

	// ::fprintf( stderr, "resetWorldMap()\n" ); //
	resetWorldMap();

	// ::fprintf( stderr, "loadTileSets()\n" ); //
	tileWorld->loadTileSets();

	// ::fprintf( stderr, "PcgMap::init(): end\n" ); //
	// exit( 0 ); //
}

////////////////////////////////////////////////////////////////
// タイルの初期化
////////////////////////////////////////////////////////////////

void PcgMap::initPcgTile()
{
	for( TileTownsItr itr = tileTowns.begin();
			itr != tileTowns.end(); ++itr ){
		if( itr->second != NULL ){
			delete itr->second;
			itr->second = NULL;
		}
	}
	tileTowns.clear();
}

////////////////////////////////////////////////////////////////
// キャラグラの初期化
////////////////////////////////////////////////////////////////

void PcgMap::initPcgCharGraph()
{
	charGraphsTown.clear();
	charGraphsWorld.clear();
}

////////////////////////////////////////////////////////////////
// リセット
////////////////////////////////////////////////////////////////

void PcgMap::reset()
{
	init();
}

////////////////////////////////////////////////////////////////
// タイルのパーサ・スクリプトの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::loadParserFileTile()
{
	std::string path = "";
	path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	path = FileList::jointDir( path,
			"map/xalnl-3.4.20/read-tile-json.js" );

	parserScriptTile = loadParserFile( path );
}

////////////////////////////////////////////////////////////////
// キャラグラのパーサ・スクリプトの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::loadParserFileCharGraph()
{
	std::string path = "";
	path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	path = FileList::jointDir( path,
			"map/xalnl-3.4.20/read-cg-json.js" );

	parserScriptCharGraph = loadParserFile( path );
}

////////////////////////////////////////////////////////////////
// パーサ・スクリプトの読み込み
////////////////////////////////////////////////////////////////

std::string PcgMap::loadParserFile( std::string path )
{
	// ::fprintf( stderr, "loadParserFile(): begin\n" ); //

	// ::fprintf( stderr, "fopen: '%s'\n", path.c_str() ); //
	FILE *fp = fopen( path.c_str(), "r" );
	if( fp == NULL )
		return "";

	std::string str = "";

	// ::fprintf( stderr, "----\n" ); //
	while( !feof( fp ) ){
		int c = fgetc( fp );
		if( c == EOF )
			break;

		str += c;
		// ::fprintf( stderr, "%c", c ); //
	}
	// ::fprintf( stderr, "----\n" ); //

	fclose( fp );
	// ::fprintf( stderr, "fclose: OK\n" ); //

	// ::fprintf( stderr, "loadParserFile(): end\n" ); //
	return str;
}

////////////////////////////////////////////////////////////////
// 全てのタイルの JSON ファイルの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::readJsonFileTileAll()
{
	// 街マップ

	town_map_tab_t *tab = ::get_town_map_tab();
	for( long i = 0; i < LOOP_MAX_1000; i++ ){
		if( tab[i].key == NULL )
			break;
		if( tab[i].file_path == NULL )
			continue;

		if( tileTowns[tab[i].key] == NULL )
			tileTowns[tab[i].key] = new PcgTile;

		readJsonFileTile( &(tileTowns[tab[i].key]),
				tab[i].file_path );
	}

	// ワールド・マップ

	readJsonFileTile( &tileWorld, "world/" );
}

////////////////////////////////////////////////////////////////
// タイルの JSON ファイルの読み込み
// PcgTile **tile : 読み込み先のタイル
// std::string dirSub : ファイルの相対パス
////////////////////////////////////////////////////////////////

void PcgMap::readJsonFileTile( PcgTile **tile, std::string dirSub )
{
	// ::fprintf( stderr, "readJsonFileTile(): begin\n" ); //

	// パターン検索を設定

	std::string dirBase = "xalnl-3.4.20/";
	std::string ext = STR_JSON_FILE_EXT;

	FileList::setStrDirSelMap( dirBase );
	FileList fls;

	// ファイルを検索

	fls.reset( dirSub, ext );
	// ::fprintf( stderr, "FileList::getBaseDir(): [%s]\n", //
	// 		fls.getBaseDir().c_str() ); //

	std::string selPath = "";
	for( long n = 0; n < LOOP_MAX_100; n++ ){
		std::string path = fls.next();
		if( path.length() <= 0 )
			break;
		// ::fprintf( stderr, "path: [%s]\n", path.c_str() ); //

		if( gui_randm( n + 1 ) == 0 ){
			selPath = path;
		}
	}

	if( selPath.length() <= 0 ){
		std::string dir = "";
		dir = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
		dir = FileList::jointDir( dir, dirSub );

		// print_err( "Directory is empty: '%s*%s'",
		// 		dir.c_str(), ext.c_str() ); //@@@
		exit_game( EXIT_FAILURE );
	}

	if( *tile == NULL ){
		*tile = new PcgTile;
		(*tile)->init();
	}
	(*tile)->setPath( selPath );
	(*tile)->setTileJsonData( readJsonFile( selPath ) );

	// ::fprintf( stderr, "readJsonFileTile(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// 全てのキャラグラの JSON ファイルの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::readJsonFileCharGraphAll()
{
	readJsonFileCharGraph( &charGraphsTown, "west/town/tile/" );
	readJsonFileCharGraph( &charGraphsWorld, "world/_tile/" );
}

////////////////////////////////////////////////////////////////
// キャラグラの JSON ファイルの読み込み
// CharGraphVec *cgs : 読み込み先のキャラグラ
// std::string dirSub : ファイルの相対パス
////////////////////////////////////////////////////////////////

void PcgMap::readJsonFileCharGraph( CharGraphVec *cgs, std::string dirSub )
{
	// ::fprintf( stderr, "readJsonFileCharGraph(): begin\n" ); //

	if( cgs == NULL )
		return;

	// パターン検索を設定

	std::string dirBase = "xalnl-3.4.20/";
	std::string ext = STR_GRAPH_FILE_EXT;

	FileList::setStrDirSelMap( dirBase );
	FileList fls;

	// ファイルを検索

	fls.reset( dirSub, ext );
	// ::fprintf( stderr, "FileList::getBaseDir(): [%s]\n", //
	// 		fls.getBaseDir().c_str() ); //

	for( long i = 0; i < LOOP_MAX_100; i++ ){
		std::string path = fls.next();
		if( path.length() <= 0 )
			break;
		// ::fprintf( stderr, "path: [%s]\n", path.c_str() ); //

		PcgCharGraph *cg = new PcgCharGraph;
		cg->setPath( path );
		std::string pathJson = cg->charPath;
		// ::fprintf( stderr, "pathJson: [%s]\n", pathJson.c_str() ); //

		cg->setCgJsonData( readJsonFile( pathJson ) );
		cgs->push_back( cg );
	}

	// ::fprintf( stderr, "readJsonFileCharGraph(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// JSON ファイルの読み込み
////////////////////////////////////////////////////////////////

std::string PcgMap::readJsonFile( std::string path )
{
	// ::fprintf( stderr, "readJsonFile(): begin\n" ); //

	// ::fprintf( stderr, "fopen: '%s'\n", path.c_str() ); //
	FILE *fp = fopen( path.c_str(), "r" );
	if( fp == NULL )
		return "";

	std::string str = "";

	// ::fprintf( stderr, "----\n" ); //
	while( !feof( fp ) ){
		int c = fgetc( fp );
		if( c == EOF )
			break;

		str += c;
		// ::fprintf( stderr, "%c", c ); //
	}
	// ::fprintf( stderr, "----\n" ); //

	fclose( fp );
	// ::fprintf( stderr, "fclose: OK\n" ); //

	// ::fprintf( stderr, "readJsonFile(): end\n" ); //
	return str;
}

////////////////////////////////////////////////////////////////
// タイルのパース
////////////////////////////////////////////////////////////////

void PcgMap::parsePcgTile()
{
	// 街マップ

	for( TileTownsItr itr = tileTowns.begin();
			itr != tileTowns.end(); ++itr ){
		if( itr->second == NULL )
			continue;

		// ::fprintf( stderr, "parse: [%s]\n", //
		//		itr->first.c_str() ); //
		itr->second->parse( parserScriptTile );
	}

	// ワールド・マップ

	if( tileWorld != NULL )
		tileWorld->parse( parserScriptTile );
}

////////////////////////////////////////////////////////////////
// 全てのキャラグラのパース
////////////////////////////////////////////////////////////////

void PcgMap::parsePcgCharGraphAll()
{
	parsePcgCharGraph( &charGraphsTown );
	parsePcgCharGraph( &charGraphsWorld );
}

////////////////////////////////////////////////////////////////
// キャラグラのパース
// CharGraphVec *cgs : パースするキャラグラ
////////////////////////////////////////////////////////////////

void PcgMap::parsePcgCharGraph( CharGraphVec *cgs )
{
	if( cgs == NULL )
		return;

	long size = cgs->size();
	for( long i = 0; i < size; i++ ){
		// ::fprintf( stderr, "parse: [%s]\n", //
		// 		(*cgs)[i]->charPath.c_str() ); //

		(*cgs)[i]->parse( parserScriptCharGraph );
	}
}

////////////////////////////////////////////////////////////////
// 全てのマップ・チップを文字に変換
////////////////////////////////////////////////////////////////

void PcgMap::transMapAll()
{
	// 街マップ

	// ::fprintf( stderr, "transMapAll(): Towns\n" ); //
	for( TileTownsItr itr = tileTowns.begin();
			itr != tileTowns.end(); ++itr ){
		if( itr->second == NULL )
			continue;

		transMap( mapLayersTowns[itr->first],
				itr->second, &charGraphsTown );
	}

	// ワールド・マップ

	// ::fprintf( stderr, "transMapAll(): World\n" ); //
	transMap( mapLayersWorld, tileWorld, &charGraphsWorld );
}

////////////////////////////////////////////////////////////////
// マップ・チップを文字に変換
// std::vector<PcgMapLayer *> &layers :変換先のレイヤー
// PcgTile *tile : 変換元のタイル
// CharGraphVec *cgs : 変換元のキャラグラ
////////////////////////////////////////////////////////////////

void PcgMap::transMap(
	std::vector<PcgMapLayer *> &layers,
	PcgTile *tile,
	CharGraphVec *cgs
)
{
	if( tile == NULL )
		return;
	if( cgs == NULL )
		return;

	// ::fprintf( stderr, "transMap(): begin\n" ); //

	for( std::vector<PcgMapLayer *>::iterator itr = layers.begin();
			itr != layers.end(); ++itr ){
		if( *itr == NULL )
			continue;

		delete *itr;
		*itr = NULL;
	}
	layers.clear();

	for( long i = 0; i < tile->tileLayersNum; i++ ){
		layers.push_back( new PcgMapLayer );
		transMapLayer( layers[i], tile, tile->tileLayers[i], cgs );
	}

#if	0

	// デバッグ用マップ出力

	::fprintf( stderr, "map\n" );

	long objLayer = 1;
	PcgMapLayer integrateMap;
	integrateMap.mjrFace.clear();
	integrateMap.mnrFace.clear();

	PcgTileLayer *tileLayer = tile->tileLayers[0];

	for( long y = 0; y < tileLayer->height; y++ ){
		integrateMap.mjrFace.push_back( "" );
		integrateMap.mnrFace.push_back( "" );

		for( long x = 0; x < tileLayer->width; x++ ){
			integrateMap.mjrFace[y] += FACE_MJR_NULL;
			integrateMap.mnrFace[y] += FACE_MNR_NULL;
		}
	}

	for( long i = 0; i < tile->tileLayersNum - objLayer; i++ ){
		::fprintf( stderr, "layers[%ld]->name: [%s]\n",
				i, layers[i]->name.c_str() );

		::fprintf( stderr, "layers[%ld]->visible: ", i );
		if( layers[i]->visible )
			::fprintf( stderr, "[true]\n" );
		else
			::fprintf( stderr, "[false]\n" );

		if( !layers[i]->visible )
			continue;

		for( long y = 0; y < tileLayer->height; y++ ){
			for( long x = 0; x < tileLayer->width; x++ ){
				char mjr = layers[i]->mjrFace[y][x];
				char mnr = layers[i]->mnrFace[y][x];

				if( mjr != FACE_MJR_TRANS )
					integrateMap.mjrFace[y][x] = mjr;
				if( mnr != FACE_MNR_TRANS )
					integrateMap.mnrFace[y][x] = mnr;
			}
		}
	}

	::fprintf( stderr, "----\n" );
	for( long y = 0; y < tileLayer->height; y++ ){
		for( long x = 0; x < tileLayer->width; x++ ){
			::fprintf( stderr, "%c%c",
					integrateMap.mjrFace[y][x],
					integrateMap.mnrFace[y][x] );
		}
		::fprintf( stderr, "\n" );
	}
	::fprintf( stderr, "----\n" );
#endif

	// ::fprintf( stderr, "transMap(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// マップ・チップを文字に変換
// PcgMapLayer *map : 変換先のマップ・レイヤー
// PcgTile *pcgTile : 変換元のタイル
// PcgTileLayer *tile : 変換元のタイル・レイヤー
// CharGraphVec *cgs : 変換元のキャラグラ
////////////////////////////////////////////////////////////////

void PcgMap::transMapLayer(
	PcgMapLayer *map,
	PcgTile *pcgTile,
	PcgTileLayer *tile,
	CharGraphVec *cgs
)
{
	// close_game( 0 ); //
	// ::fprintf( stderr, "\n" ); //
	// ::fprintf( stderr, "transMapLayer(): begin\n" ); //

	if( map == NULL )
		return;
	if( pcgTile == NULL )
		return;
	if( tile == NULL )
		return;
	if( cgs == NULL )
		return;

	map->name = tile->name;
	map->width = tile->width;
	map->height = tile->height;
	map->visible = tile->visible;

	map->mjrFace.clear();
	map->mnrFace.clear();
	map->mjrColor.clear();
	map->mnrColor.clear();

	// ::fprintf( stderr, "tile->name: [%s]\n", tile->name.c_str() ); //
	// ::fprintf( stderr, "tile->width: [%ld]\n", tile->width ); //
	// ::fprintf( stderr, "tile->height: [%ld]\n", tile->height ); //
	// ::fprintf( stderr, "tile->visible: [%d]\n", tile->visible ); //

	for( long y = 0; y < tile->height; y++ ){
		// ::fprintf( stderr, "[\n" ); //

		map->mjrFace.push_back( "" );
		map->mnrFace.push_back( "" );
		map->mjrColor.push_back( "" );
		map->mnrColor.push_back( "" );

		for( long x = 0; x < tile->width; x++ ){
			// ::fprintf( stderr, "\t x, y: [%ld][%ld]\n",
			// 		x, y ); //

			long dataIdx = calcDataIndex( tile, x, y );
			// ::fprintf( stderr, "\t dataIdx: [%ld]\n",
			// 		dataIdx ); //
			if( dataIdx <= -1 )
				break;

			long data = tile->data[dataIdx];
			// ::fprintf( stderr, "\t data: [%ld]\n", data ); //
			if( data <= 0 ){
				map->mjrFace[y] += FACE_MJR_TRANS;
				map->mnrFace[y] += FACE_MNR_TRANS;
				map->mjrColor[y] += FACE_MJR_NULL;
				map->mnrColor[y] += FACE_MNR_NULL;
				// ::fprintf( stderr, "  " ); //
				continue;
			}

			long nSets = searchTileSets( pcgTile, data );
			if( nSets <= -1 )
				break;

			if( pcgTile->tileSets[nSets] == NULL )
				break;

			long gid = pcgTile->tileSets[nSets]->firstGId;
			long setsIdx = data - gid;
			// ::fprintf( stderr, "\t nSets: [%ld]\n", nSets ); //
			// ::fprintf( stderr, "\t gid: [%ld]\n", gid ); //
			// ::fprintf( stderr, "\t setsIdx: [%ld]\n",
			// 		setsIdx ); //
			if( setsIdx <= -1 )
				break;

			long cgIdx = searchCharGraphIndex(
					pcgTile, nSets, cgs );
			// ::fprintf( stderr, "\t cgIdx: [%ld]\n", cgIdx ); //
			if( cgIdx <= -1 )
				break;

			if( (*cgs)[cgIdx] == NULL )
				break;

			long xIdx = setsIdx % (*cgs)[cgIdx]->width;
			long yIdx = setsIdx / (*cgs)[cgIdx]->width;
			xIdx *= (*cgs)[cgIdx]->charWidth;
			xIdx += (*cgs)[cgIdx]->rulerColumnLineHead;
			yIdx += (*cgs)[cgIdx]->rulerRowCharHead;
			// ::fprintf( stderr, "\t width: [%ld]\n", //
			// 		(*cgs)[cgIdx]->width ); //
			// ::fprintf( stderr, "\t height: [%ld]\n", //
			// 		(*cgs)[cgIdx]->height ); //
			// ::fprintf( stderr, "\t xIdx: [%ld]\n", xIdx ); //
			// ::fprintf( stderr, "\t yIdx: [%ld]\n", yIdx ); //

#if	0
			for( size_t i = 0; i < (*cgs)[cgIdx]
					->tile.size(); i++ ){
				// ::fprintf( stderr, "[%s]\n", //
				// 		(*cgs)[cgIdx] //
				// 		->tile[i].c_str() ); //
			}
			// exit_game( 0 ); //
#endif

			char mjr = (*cgs)[cgIdx]->tile[yIdx][xIdx + 0];
			char mnr = (*cgs)[cgIdx]->tile[yIdx][xIdx + 1];
			map->mjrFace[y] += mjr;
			map->mnrFace[y] += mnr;
			// ::fprintf( stderr, "\t [%c%c]\n", mjr, mnr ); //
			// ::fprintf( stderr, "\t %c%c", mjr, mnr ); //

			mjr = (*cgs)[cgIdx]->color[yIdx][xIdx + 0];
			mnr = (*cgs)[cgIdx]->color[yIdx][xIdx + 1];
			map->mjrColor[y] += mjr;
			map->mnrColor[y] += mnr;
		}

		// ::fprintf( stderr, "]\n" ); //
		// exit_game( 0 ); //
	}

	// ::fprintf( stderr, "transMapLayer(): end\n" ); //
	// exit_game( 0 ); //
}

////////////////////////////////////////////////////////////////
// 二次元の座標から一次元の添字へ変換
// PcgTileLayer *tile : タイル・レイヤー
// long x : X 座標
// long y : Y 座標
// return : 添字
////////////////////////////////////////////////////////////////

long PcgMap::calcDataIndex( PcgTileLayer *tile, long x, long y )
{
	if( tile == NULL )
		return -1;
	if( x < 0 )
		return -1;
	if( x >= tile->width )
		return -1;
	if( y < 0 )
		return -1;
	if( y >= tile->height )
		return -1;

	return( (y * tile->width) + x );
}

////////////////////////////////////////////////////////////////
// タイル・セットが参照しているキャラグラのインデックスを探す
// PcgTile *tile : タイル
// long nSets : タイル・セットのインデックス
// CharGraphVec *cgs : キャラグラ
// return : キャラグラのインデックス
////////////////////////////////////////////////////////////////

long PcgMap::searchCharGraphIndex(
	PcgTile *tile, long nSets, CharGraphVec *cgs
)
{
	// ::fprintf( stderr, "searchCharGraphIndex(): begin\n" ); //
	// ::fprintf( stderr, "tile: [%p]\n", tile ); //
	// ::fprintf( stderr, "nSets: [%ld]\n", nSets ); //
	// ::fprintf( stderr, "cgs: [%p]\n", cgs ); //
	if( tile == NULL )
		return -1;
	if( nSets <= -1 )
		return -1;

	std::string name = tile->tileSets[nSets]->image;
	// ::fprintf( stderr, "image name: [%s]\n", name.c_str() ); //
	if( name.length() <= 0 )
		return -1;

	std::string sName1 = FileList::getFileName( name );
	// ::fprintf( stderr, "(*cgs).size(): [%ld]\n", //
	//		(*cgs).size() ); //
	for( unsigned long i = 0; i < cgs->size(); i++ ){
		std::string sName2 = FileList::getFileName(
				(*cgs)[i]->graphPath );

		// ::fprintf( stderr, "i: %ld\n", i ); //
		// ::fprintf( stderr, "name: [%s][%s]\n", //
		// 		sName1.c_str(), sName2.c_str() ); //
		if( sName1 == sName2 )
			return i;
	}

	// ::fprintf( stderr, "searchCharGraphIndex(): end\n" ); //
	return -1;
}

////////////////////////////////////////////////////////////////
// 一次元の添字を含む範囲のタイル・セットを探す
// PcgTile *tile : タイル
// long data : 一次元の添字
// return : タイル・セットのインデックス
////////////////////////////////////////////////////////////////

long PcgMap::searchTileSets( PcgTile *tile, long data )
{
	if( tile == NULL )
		return -1;

	if( tile->tileSets.size() < static_cast<unsigned long>(
			tile->tileSetsNum) ){
		return -1;
	}

	for( long i = tile->tileSetsNum - 1; i >= 0; i-- ){
		if( tile->tileSets[i] == NULL )
			return -1;

		if( tile->tileSets[i]->firstGId <= data ){
			return i;
		}
	}

	return -1;
}

////////////////////////////////////////////////////////////////
// 街のパターンを初期化
////////////////////////////////////////////////////////////////

void PcgMap::initTownPtn()
{
	townPtn.col_str_len = 2;
	townPtn.col_n = 0;

	for( long i = 0; i < TOWN_PTN_COL_MAX_N; i++ ){
		townPtn.col_mjr[i] = FACE_MJR_NULL;
		townPtn.col_mnr[i] = FACE_MNR_NULL;
	}

	for( long y = 0; y < MAP_MAX_Y; y++ ){
		for( long x = 0; x < MAP_MAX_X; x++ ){
			townPtn.map_mjr[y][x] = FACE_MJR_FLOOR;
			townPtn.map_mnr[y][x] = FACE_MNR_FLOOR;
		}
	}

	set_town_ptn_col_count( &townPtn );
}

////////////////////////////////////////////////////////////////
// キャラ・グラで街のパターンを上書き
////////////////////////////////////////////////////////////////

void PcgMap::resetTownPtn()
{
	transMapToTownPtn();

	town_ptn_t *pTownPtn = get_town_ptn();
	*pTownPtn = townPtn;
}

////////////////////////////////////////////////////////////////
// キャラ・グラを街のパターンに変換
////////////////////////////////////////////////////////////////

void PcgMap::transMapToTownPtn()
{
	// ::fprintf( stderr, "transMapToTownPtn(): begin\n" ); //

	// ::fprintf( stderr, "initTownPtn()\n" ); //
	initTownPtn();

	const char *name = LAYER_NAME_OBJECT;
	const long len = strlen( name );

	std::vector<PcgMapLayer *> &layers
			= mapLayersTowns[currentTownMapKey];

	for( unsigned long i = 0; i < layers.size(); i++ ){
		// ::fprintf( stderr, "name: [%s]\n", //
		// 		layers[i]->name.c_str() ); //
		if( strncmp( layers[i]->name.c_str(),
				name, len ) == 0 ){
			transMapLayerToTownPtn(
					&townPtn,
					layers[i] );
			break;
		}
	}

	// ::fprintf( stderr, "transMapToTownPtn(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// マップ・レイヤーを街のパターンに変換
// town_ptn_t *ptn : 変換先パターン
// const PcgMapLayer *layer : 変換元マップ・レイヤー
////////////////////////////////////////////////////////////////

void PcgMap::transMapLayerToTownPtn(
	town_ptn_t *ptn, const PcgMapLayer *layer
)
{
	// ::fprintf( stderr, "transMapLayerToTownPtn(): begin\n" ); //

	if( ptn == NULL )
		return;
	if( layer == NULL )
		return;

	long w = min_l( MAP_MAX_X, layer->width );
	long h = min_l( MAP_MAX_Y, layer->height );

	long y = 0;
	for( y = 0; y < h; y++ ){
		long x = 0;
		for( x = 0; x < w; x++ ){
			ptn->map_mjr[y][x] = layer->mjrFace[y][x];
			ptn->map_mnr[y][x] = layer->mnrFace[y][x];
#if	0
			if( ptn->map_mjr[y][x] != FACE_MJR_DOOR_CLOSE ){
				ptn->map_mjr[y][x] = FACE_MJR_FLOOR;
				ptn->map_mnr[y][x] = FACE_MNR_FLOOR;
			}
#endif
		}
		for( ; x < MAP_MAX_X; x++ ){
			ptn->map_mjr[y][x] = FACE_MJR_FLOOR;
			ptn->map_mnr[y][x] = FACE_MNR_FLOOR;
		}
	}
	for( ; y < MAP_MAX_Y; y++ ){
		for( long x = 0; x < MAP_MAX_X; x++ ){
			ptn->map_mjr[y][x] = FACE_MJR_FLOOR;
			ptn->map_mnr[y][x] = FACE_MNR_FLOOR;
		}
	}

	set_town_ptn_col_count( ptn );

	// ::fprintf( stderr, "transMapLayerToTownPtn(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// キャラ・グラで街のマップを上書き
////////////////////////////////////////////////////////////////

void PcgMap::resetTownMap()
{
	if( get_dun_lev() != DUN_LEV_GROUND )
		return;

	all_map_t *map = get_all_map( MAP_SCALE_DETAIL );
	std::vector<PcgMapLayer *> &layers
			= mapLayersTowns[currentTownMapKey];

	transMapToCgMap( map, layers );
}

////////////////////////////////////////////////////////////////
// キャラ・グラでワールド・マップを上書き
////////////////////////////////////////////////////////////////

void PcgMap::resetWorldMap()
{
	all_map_t *map = get_all_map( MAP_SCALE_WORLD );
	std::vector<PcgMapLayer *> &layers
			= mapLayersWorld;

	for( long y = 0; y < MAP_MAX_Y; y++ ){
		for( long x = 0; x < MAP_MAX_X; x++ ){
			map->sect[y][x] = 'z';
			map->obj.flg[y][x] = FLG_MAP_OBJ_FIND;

			map->chr.mjr[y][x] = FACE_MJR_NULL;
			map->chr.mnr[y][x] = FACE_MNR_NULL;
			map->chr.flg[y][x] = FLG_NULL;

			map->total.mjr[y][x] = FACE_MJR_NULL;
			map->total.mnr[y][x] = FACE_MNR_NULL;
			map->total.flg[y][x] = FLG_NULL;

			map->light_depth_obj[y][x] = +1;
			map->light_depth_chr[y][x] = 0;

			map->chr_p[y][x] = NULL;
		}
	}

	transMapToCgMap( map, layers );
}

////////////////////////////////////////////////////////////////
// キャラ・グラをマップに変換
////////////////////////////////////////////////////////////////

void PcgMap::transMapToCgMap(
	all_map_t *map, std::vector<PcgMapLayer *> &layers
)
{
	// ::fprintf( stderr, "transMapToCgMap(): begin\n" ); //

	if( map == NULL )
		return;

	// レイヤーの割り当て

	free_mem( map->cg_layer_ls );
	map->cg_layer_ls = NULL;

	long nMax = static_cast<long>(layers.size());
	map->cg_layer_max_n = nMax;
	if( nMax <= 0 )
		return;

	map->cg_layer_ls = static_cast<cg_layer_t *>(alloc_mem(
			sizeof( cg_layer_t ) * nMax, FALSE ));

	// 予約レイヤー番号の初期化

	map->cg_layer_obj_n = 0;
	map->cg_layer_chr_n = nMax - 1;

	// パターンに変換

	for( long n = 0; n < nMax; n++ ){
		// ::fprintf( stderr, "name: [%s]\n", //
		// 		layers[n]->name.c_str() ); //

		layer_kind_t kind = trans_layer_name_to_kind(
				layers[n]->name.c_str() );
		map->cg_layer_ls[n].kind = kind;

		if( kind == LAYER_KIND_OBJECT )
			map->cg_layer_obj_n = n;
		if( kind == LAYER_KIND_CHR )
			map->cg_layer_chr_n = n;

		transMapLayerToCgMap(
				&(map->cg_layer_ls[n]),
				layers[n] );
	}
	// ::fprintf( stderr, "cg_layer_obj_n: [%ld]\n", //
	// 		map->cg_layer_obj_n ); //
	// ::fprintf( stderr, "cg_layer_chr_n: [%ld]\n", //
	// 		map->cg_layer_chr_n ); //

	// ::fprintf( stderr, "transMapToCgMap(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// マップ・レイヤーをマップに変換
// cg_layer_t *cg_layer : 変換先マップ
// const PcgMapLayer *layer : 変換元マップ・レイヤー
////////////////////////////////////////////////////////////////

void PcgMap::transMapLayerToCgMap(
	cg_layer_t *cg_layer, const PcgMapLayer *layer
)
{
	// ::fprintf( stderr, "transMapLayerToCgMap(): begin\n" ); //

	if( cg_layer == NULL )
		return;
	if( layer == NULL )
		return;

	cg_layer->flg_visible = layer->visible;

	long w = min_l( MAP_MAX_X, layer->width );
	long h = min_l( MAP_MAX_Y, layer->height );

	long y = 0;
	for( y = 0; y < h; y++ ){
		long x = 0;
		for( x = 0; x < w; x++ ){
			cg_layer->mjr_face[y][x] = layer->mjrFace[y][x];
			cg_layer->mnr_face[y][x] = layer->mnrFace[y][x];
			cg_layer->mjr_color[y][x] = layer->mjrColor[y][x];
			cg_layer->mnr_color[y][x] = layer->mnrColor[y][x];
		}
		for( ; x < MAP_MAX_X; x++ ){
			cg_layer->mjr_face[y][x] = FACE_MJR_TRANS;
			cg_layer->mnr_face[y][x] = FACE_MNR_TRANS;
			cg_layer->mjr_color[y][x] = FACE_MJR_NULL;
			cg_layer->mnr_color[y][x] = FACE_MJR_NULL;
		}
	}
	for( ; y < MAP_MAX_Y; y++ ){
		for( long x = 0; x < MAP_MAX_X; x++ ){
			cg_layer->mjr_face[y][x] = FACE_MJR_TRANS;
			cg_layer->mnr_face[y][x] = FACE_MNR_TRANS;
			cg_layer->mjr_color[y][x] = FACE_MJR_NULL;
			cg_layer->mnr_color[y][x] = FACE_MJR_NULL;
		}
	}

	// ::fprintf( stderr, "transMapLayerToCgMap(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// 現在のマップ・チップを返す
// return : マップ・チップ
////////////////////////////////////////////////////////////////

PcgTile *PcgMap::getPcgTile()
{
	switch( get_dun()->scale ){
	case MAP_SCALE_DETAIL:
		return tileTowns[TOWN_MAP_KEY_TRIED];
	case MAP_SCALE_WIDE:
	case MAP_SCALE_WORLD:
		return tileWorld;
	case MAP_SCALE_MAX_N:
	case MAP_SCALE_CURRENT_N:
		return NULL;
	}

	return NULL;
}
