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
	sParserScriptTile = "";
	pTileWestTried = NULL;

	sParserScriptCharGraph = "";
	aCharGraph.clear();

	aMapLayerWestTried.clear();
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
	// fprintf( stderr, "PcgMap::init(): begin\n" ); //

	initPcgTile();
	initPcgCharGraph();

	// タイル

	// fprintf( stderr, "\n" ); //
	// fprintf( stderr, "readJsonFileTile()\n" ); //
	readJsonFileTile();
	// fprintf( stderr, "loadParserFileTile()\n" ); //
	loadParserFileTile();

	// fprintf( stderr, "parsePcgTile()\n" ); //
	parsePcgTile();

	// キャラグラ

	// fprintf( stderr, "\n" ); //
	// fprintf( stderr, "readJsonFileCharGraph()\n" ); //
	readJsonFileCharGraph();
	// fprintf( stderr, "loadParserFileCharGraph()\n" ); //
	loadParserFileCharGraph();

	// fprintf( stderr, "parsePcgCharGraph()\n" ); //
	parsePcgCharGraph();

	// fprintf( stderr, "transMap()\n" ); //
	transMap();

	// fprintf( stderr, "reset_all()\n" ); //
	resetTownPtn();

	// fprintf( stderr, "resetTownMap()\n" ); //
	resetTownMap();

	// fprintf( stderr, "PcgMap::init(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// タイルの初期化
////////////////////////////////////////////////////////////////

void PcgMap::initPcgTile()
{
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
	aCharGraph.clear();
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
	WSCstring path = "";
	path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	path = FileList::jointDir( path,
			"map/xalnl-3.4.20/read-tile-json.js" );

	sParserScriptTile = loadParserFile( path );
}

////////////////////////////////////////////////////////////////
// キャラグラのパーサ・スクリプトの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::loadParserFileCharGraph()
{
	WSCstring path = "";
	path = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
	path = FileList::jointDir( path,
			"map/xalnl-3.4.20/read-cg-json.js" );

	sParserScriptCharGraph = loadParserFile( path );
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

void PcgMap::readJsonFileTile()
{
	// fprintf( stderr, "readJsonFileTile(): begin\n" ); //

	// パターン検索を設定

	WSCstring dirBase = "xalnl-3.4.20/";
	WSCstring dirSub = "west/town/tried/";
	WSCstring ext = STR_JSON_FILE_EXT;

	FileList::setStrDirSelMap( dirBase );
	FileList fls;

	// ファイルを検索

	fls.reset( dirSub, ext );
	// fprintf( stderr, "FileList::getBaseDir(): [%s]\n",
	// 		fls.getBaseDir().c_str() ); //

	WSCstring selPath = "";
	for( long n = 0; n < LOOP_MAX_100; n++ ){
		WSCstring path = fls.next();
		if( path.getChars() <= 0 )
			break;
		// fprintf( stderr, "path: [%s]\n", path.c_str() ); //

		if( gui_randm( n + 1 ) == 0 ){
			selPath = path;
		}
	}

	if( selPath.getChars() <= 0 ){
		WSCstring dir = "";
		dir = FileList::jointDir( get_home_dir(), STR_DIR_BASE );
		dir = FileList::jointDir( dir, dirSub );

		print_err( "Directory is empty: '%s*%s'",
				dir.c_str(), ext.c_str() ); //@@@
		exit_game( EXIT_FAILURE );
	}

	pTileWestTried->setPath( selPath );
	pTileWestTried->setTileJsonData( readJsonFile( selPath ) );

	// fprintf( stderr, "readJsonFileTile(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// キャラグラの JSON ファイルの読み込み
////////////////////////////////////////////////////////////////

void PcgMap::readJsonFileCharGraph()
{
	// fprintf( stderr, "readCharGraphJsonFile(): begin\n" ); //

	// パターン検索を設定

	WSCstring dirBase = "xalnl-3.4.20/";
	WSCstring dirSub = "west/town/_tile/";
	WSCstring ext = STR_GRAPH_FILE_EXT;

	FileList::setStrDirSelMap( dirBase );
	FileList fls;

	// ファイルを検索

	fls.reset( dirSub, ext );
	// fprintf( stderr, "FileList::getBaseDir(): [%s]\n",
	//		fls.getBaseDir().c_str() ); //

	for( long i = 0; i < LOOP_MAX_100; i++ ){
		WSCstring path = fls.next();
		if( path.getChars() <= 0 )
			break;
		// fprintf( stderr, "path: [%s]\n", path.c_str() ); //

		PcgCharGraph *cg = new PcgCharGraph;
		cg->setPath( path );
		WSCstring pathJson = cg->charPath;
		// fprintf( stderr, "pathJson: [%s]\n", pathJson.c_str() ); //

		cg->setCgJsonData( readJsonFile( pathJson ) );
		aCharGraph.push_back( cg );
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
	// fprintf( stderr, "parse: [%s]\n", path.c_str() ); //
	pTileWestTried->parse( sParserScriptTile );
}

////////////////////////////////////////////////////////////////
// キャラグラのパース
////////////////////////////////////////////////////////////////

void PcgMap::parsePcgCharGraph()
{
	long size = aCharGraph.size();
	for( long i = 0; i < size; i++ ){
		// fprintf( stderr, "parse: [%s]\n",
		//		aCharGraph[i]->charPath.c_str() ); //

		aCharGraph[i]->parse( sParserScriptCharGraph );
	}
}

////////////////////////////////////////////////////////////////
// マップ・チップを文字に変換
////////////////////////////////////////////////////////////////

void PcgMap::transMap()
{
	aMapLayerWestTried.clear();

	for( long i = 0; i < pTileWestTried->tileLayersNum; i++ ){
		aMapLayerWestTried.push_back( new PcgMapLayer );
		transMapLayer( aMapLayerWestTried[i],
				pTileWestTried,
				pTileWestTried->tileLayers[i] );
	}

#if	0
	long objLayer = 1;
	PcgMapLayer integrateMap;
	integrateMap.mjrFace.clear();
	integrateMap.mnrFace.clear();

	PcgTileLayer *tile = pTileWestTried->tileLayers[0];

	for( long y = 0; y < tile->height; y++ ){
		integrateMap.mjrFace.push_back( "" );
		integrateMap.mnrFace.push_back( "" );

		for( long x = 0; x < tile->width; x++ ){
			integrateMap.mjrFace[y] += FACE_MJR_NULL;
			integrateMap.mnrFace[y] += FACE_MNR_NULL;
		}
	}

	for( long i = 0; i < pTileWestTried->tileLayersNum - objLayer; i++ ){
		for( long y = 0; y < tile->height; y++ ){
			for( long x = 0; x < tile->width; x++ ){
				char mjr = aMapLayerWestTried[i]
						->mjrFace[y][x];
				char mnr = aMapLayerWestTried[i]
						->mnrFace[y][x];

				if( mjr != FACE_MJR_TRANS )
					integrateMap.mjrFace[y][x] = mjr;
				if( mnr != FACE_MNR_TRANS )
					integrateMap.mnrFace[y][x] = mnr;
			}
		}
	}

	fprintf( stderr, "----\n" );
	for( long y = 0; y < tile->height; y++ ){
		for( long x = 0; x < tile->width; x++ ){
			fprintf( stderr, "%c%c",
					integrateMap.mjrFace[y][x],
					integrateMap.mnrFace[y][x] );
		}
		fprintf( stderr, "\n" );
	}
	fprintf( stderr, "----\n" );
#endif
}

////////////////////////////////////////////////////////////////
// マップ・チップを文字に変換
// PcgMapLayer *map : 変換先マップ・レイヤー
// PcgTile *pcgTile : 変換元タイル
// PcgTileLayer *tile : 変換元タイル・レイヤー
////////////////////////////////////////////////////////////////

void PcgMap::transMapLayer(
	PcgMapLayer *map, PcgTile *pcgTile, PcgTileLayer *tile
)
{
	// fprintf( stderr, "\n" ); //
	// fprintf( stderr, "transMapLayer(): begin\n" ); //

	if( pcgTile == NULL )
		return;
	if( tile == NULL )
		return;
	if( map == NULL )
		return;

	map->name = tile->name;
	map->width = tile->width;
	map->height = tile->height;

	map->mjrFace.clear();
	map->mnrFace.clear();
	map->mjrColor.clear();
	map->mnrColor.clear();

	// fprintf( stderr, ": [%s]\n", tile->name.c_str() ); //
	// fprintf( stderr, "tile->width: [%ld]\n", tile->width ); //
	// fprintf( stderr, "tile->height: [%ld]\n", tile->height ); //

	for( long y = 0; y < tile->height; y++ ){
		// fprintf( stderr, "[" ); //

		map->mjrFace.push_back( "" );
		map->mnrFace.push_back( "" );
		map->mjrColor.push_back( "" );
		map->mnrColor.push_back( "" );

		for( long x = 0; x < tile->width; x++ ){
			// fprintf( stderr, "x, y: [%ld][%ld]\n", x, y ); //

			long dataIdx = calcDataIndex( tile, x, y );
			// fprintf( stderr, "dataIdx: [%ld]\n", dataIdx ); //
			if( dataIdx <= -1 )
				break;

			long data = tile->data[dataIdx];
			// fprintf( stderr, "data: [%ld]\n", data ); //
			if( data <= 0 ){
				map->mjrFace[y] += FACE_MJR_TRANS;
				map->mnrFace[y] += FACE_MNR_TRANS;
				map->mjrColor[y] += FACE_MJR_NULL;
				map->mnrColor[y] += FACE_MNR_NULL;
				// fprintf( stderr, "  " ); //
				continue;
			}

			long nSets = searchTileSets( pcgTile, data );
			long gid = pcgTile->tileSets[nSets]->firstGId;
			long setsIdx = data - gid;
			// fprintf( stderr, "nSets: [%ld]\n", nSets ); //
			// fprintf( stderr, "gid: [%ld]\n", gid ); //
			// fprintf( stderr, "setsIdx: [%ld]\n", setsIdx ); //
			if( setsIdx <= -1 )
				break;

			long cgIdx = searchCharGraphIndex( pcgTile, nSets );
			// fprintf( stderr, "cgIdx: [%ld]\n", cgIdx ); //
			if( cgIdx <= -1 )
				break;

			long xIdx = setsIdx % aCharGraph[cgIdx]->width;
			long yIdx = setsIdx / aCharGraph[cgIdx]->width;
			xIdx *= aCharGraph[cgIdx]->charWidth;
			xIdx += aCharGraph[cgIdx]->rulerColumnLineHead;
			yIdx += aCharGraph[cgIdx]->rulerRowCharHead;
			// fprintf( stderr, "width: [%ld]\n",
			// 		aCharGraph[cgIdx]->width ); //
			// fprintf( stderr, "height: [%ld]\n",
			// 		aCharGraph[cgIdx]->height ); //
			// fprintf( stderr, "xIdx: [%ld]\n", xIdx ); //
			// fprintf( stderr, "yIdx: [%ld]\n", yIdx ); //

#if	0
			for( long i = 0; i < yIdx; i++ ){
				fprintf( stderr, "[%s]\n", aCharGraph[cgIdx]
						->tile[i].c_str() ); //
			}
			// exit_game( 0 ); //
#endif

			char mjr = aCharGraph[cgIdx]->tile[yIdx][xIdx + 0];
			char mnr = aCharGraph[cgIdx]->tile[yIdx][xIdx + 1];
			map->mjrFace[y] += mjr;
			map->mnrFace[y] += mnr;
			// fprintf( stderr, "[%c%c]\n", mjr, mnr ); //
			// fprintf( stderr, "%c%c", mjr, mnr ); //

			mjr = aCharGraph[cgIdx]->color[yIdx][xIdx + 0];
			mnr = aCharGraph[cgIdx]->color[yIdx][xIdx + 1];
			map->mjrColor[y] += mjr;
			map->mnrColor[y] += mnr;
		}

		// fprintf( stderr, "]\n" ); //
	}

	// fprintf( stderr, "transMapLayer(): end\n" ); //
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
// return : キャラグラのインデックス
////////////////////////////////////////////////////////////////

long PcgMap::searchCharGraphIndex( PcgTile *tile, long nSets )
{
	// fprintf( stderr, "searchCharGraphIndex(): begin\n" ); //
	if( tile == NULL )
		return -1;
	if( nSets <= -1 )
		return -1;

	WSCstring name = tile->tileSets[nSets]->image;
	if( name.getChars() <= 0 )
		return -1;

	WSCstring sName1 = FileList::getFileName( name );
	for( unsigned long i = 0; i < aCharGraph.size(); i++ ){
		WSCstring sName2 = FileList::getFileName(
				aCharGraph[i]->graphPath );

		// fprintf( stderr, "i: %ld\n", i ); //
		// fprintf( stderr, "name: [%s][%s]\n",
		// 		sName1.c_str(), sName2.c_str() );
		if( sName1 == sName2 )
			return i;
	}

	// fprintf( stderr, "searchCharGraphIndex(): end\n" ); //
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
	// fprintf( stderr, "transMapToTownPtn(): begin\n" ); //

	// fprintf( stderr, "initTownPtn()\n" ); //
	initTownPtn();

	const char *name = LAYER_NAME_OBJECT;
	const long len = strlen( name );

	for( unsigned long i = 0; i < aMapLayerWestTried.size(); i++ ){
		// fprintf( stderr, "name: [%s]\n",
		// 		aMapLayerWestTried[i]->name.c_str() ); //
		if( strncmp( aMapLayerWestTried[i]->name.c_str(),
				name, len ) == 0 ){
			transMapLayerToTownPtn(
					&townPtn,
					aMapLayerWestTried[i] );
			break;
		}
	}

	// fprintf( stderr, "transMapToTownPtn(): end\n" ); //
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
	// fprintf( stderr, "transMapLayerToTownPtn(): begin\n" ); //

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

	// fprintf( stderr, "transMapLayerToTownPtn(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// キャラ・グラで街のマップを上書き
////////////////////////////////////////////////////////////////

void PcgMap::resetTownMap()
{
	if( get_dun_lev() != DUN_LEV_GROUND )
		return;

	transMapToTownMap();
}

////////////////////////////////////////////////////////////////
// キャラ・グラを街のマップに変換
////////////////////////////////////////////////////////////////

void PcgMap::transMapToTownMap()
{
	// fprintf( stderr, "transMapToTownMap(): begin\n" ); //

	// レイヤーの割り当て

	dun_t *dun = get_dun();
	free_mem( dun->map.cg_layer_ls );
	dun->map.cg_layer_ls = NULL;

	long nMax = static_cast<long>(aMapLayerWestTried.size());
	dun->map.cg_layer_max_n = nMax;
	if( nMax <= 0 )
		return;

	dun->map.cg_layer_ls = static_cast<cg_layer_t *>(alloc_mem(
			sizeof( cg_layer_t ) * nMax, FALSE ));

	//

	dun->map.cg_layer_obj_n = 0;
	dun->map.cg_layer_chr_n = nMax - 1;

	const char *nameObj = LAYER_NAME_OBJECT;
	const char *nameChr = LAYER_NAME_CHAR;
	const long lenObj = strlen( nameObj );
	const long lenChr = strlen( nameChr );

	// パターンに変換

	for( long n = 0; n < nMax; n++ ){
		// fprintf( stderr, "name: [%s]\n",
		// 		aMapLayerWestTried[i]->name.c_str() ); //
		if( strncmp( aMapLayerWestTried[n]->name.c_str(),
				nameObj, lenObj ) == 0 ){
			dun->map.cg_layer_obj_n = n;
		}
		if( strncmp( aMapLayerWestTried[n]->name.c_str(),
				nameChr, lenChr ) == 0 ){
			dun->map.cg_layer_chr_n = n;
		}

		transMapLayerToTownMap(
				&(dun->map.cg_layer_ls[n]),
				aMapLayerWestTried[n] );
	}

	// fprintf( stderr, "transMapToTownMap(): end\n" ); //
}

////////////////////////////////////////////////////////////////
// マップ・レイヤーを街のマップに変換
// cg_layer_t *cg_layer : 変換先マップ
// const PcgMapLayer *layer : 変換元マップ・レイヤー
////////////////////////////////////////////////////////////////

void PcgMap::transMapLayerToTownMap(
	cg_layer_t *cg_layer, const PcgMapLayer *layer
)
{
	// fprintf( stderr, "transMapLayerToTownMap(): begin\n" ); //

	if( cg_layer == NULL )
		return;
	if( layer == NULL )
		return;

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

	// fprintf( stderr, "transMapLayerToTownMap(): end\n" ); //
}
