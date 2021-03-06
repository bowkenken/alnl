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

#ifndef PCG_MAP_H
#define PCG_MAP_H	1

////////////////////////////////////////////////////////////////
// マップ
////////////////////////////////////////////////////////////////

#include <vector>
#include <map>

#include "GameMisc.h"

////////////////////////////////////////////////////////////////

// デフォルトのディレクトリ
#define STR_DEFAULT_MAP_DIR_NAME	"map/"

// パターンのファイル名の拡張子
#if	defined( D_WS )
# define	STR_GRAPH_FILE_EXT	\
		"png jpg jpeg bmp " \
		"PNG JPG JPEG BMP " \
		"Bmp"
#elif	defined( D_GTK )
# define	STR_GRAPH_FILE_EXT	\
		"png xpm jpg jpeg tif pnm bmp gif " \
		"PNG XPM JPG JPEG TIF PNM BMP GIF " \
		"Bmp"
#elif	defined( D_IPHONE )
# define	STR_GRAPH_FILE_EXT	\
		"png jpg jpeg bmp " \
		"PNG JPG JPEG BMP " \
		"Bmp"
#elif	defined( D_MFC )
# define	STR_GRAPH_FILE_EXT	\
		"png jpg jpeg bmp " \
		"PNG JPG JPEG BMP " \
		"Bmp"
#else
# define	STR_GRAPH_FILE_EXT	\
		"png jpg jpeg bmp " \
		"PNG JPG JPEG BMP " \
		"Bmp"
#endif

#define	STR_JSON_FILE_EXT	"json JSON"

////////////////////////////////////////////////////////////////

class PcgTileLayer;
class PcgTile;
class PcgCharGraph;

////////////////////////////////////////////////////////////////

class PcgMapLayer {
public:
	std::string name;
	long width;
	long height;
	bool visible;

	std::vector<std::string> mjrFace;
	std::vector<std::string> mnrFace;

	std::vector<std::string> mjrField;
	std::vector<std::string> mnrField;

	std::vector<std::string> mjrColor;
	std::vector<std::string> mnrColor;

private:

public:

private:
};

typedef std::string TownMapKey;
typedef std::map<TownMapKey, PcgTile *>::iterator TileTownsItr;
typedef std::map<TownMapKey, std::vector<PcgMapLayer *> >
		MapLayersTownsItr;
typedef std::vector<PcgCharGraph *> CharGraphVec;

////////////////////////////////////////////////////////////////

class PcgMap {
public:

private:
	std::string parserScriptTile;
	std::string parserScriptCharGraph;

	std::map<TownMapKey, PcgTile *> tileTowns;
	PcgTile *tileWorld;

	CharGraphVec charGraphsTown;
	CharGraphVec charGraphsWorld;

	std::map<TownMapKey, std::vector<PcgMapLayer *> >
			mapLayersTowns;
	std::vector<PcgMapLayer *> mapLayersWorld;

	town_ptn_t townPtn;

	TownMapKey currentTownMapKey;

public:
	PcgMap();
	~PcgMap();

	void init();
	void initPcgTile();
	void initPcgCharGraph();
	void reset();

	long calcDataIndex( PcgTileLayer *tile, long x, long y );
	long searchTileSets( PcgTile *tile, long data );

	PcgTile *getPcgTile();

private:
/*
	void init();
	void initPcgTile();
	void initPcgCharGraph();
	void reset();
*/

	void loadParserFileTile();
	void loadParserFileCharGraph();
	std::string loadParserFile( std::string path );

	void readJsonFileTileAll();
	void readJsonFileTile( PcgTile **tile, std::string dirSub );
	void readJsonFileCharGraphAll();
	void readJsonFileCharGraph( CharGraphVec *cgs, std::string dirSub );
	std::string readJsonFile( std::string path );

	void parsePcgTile();
	void parsePcgCharGraphAll();
	void parsePcgCharGraph( CharGraphVec *cgs );

	void transMapAll();
	void transMap( PcgTile *tile, std::vector<PcgMapLayer *> &layers );
	void transMap(
		std::vector<PcgMapLayer *> &layers,
		PcgTile *tile,
		CharGraphVec *cgs
	);
	void transMapLayer(
		PcgMapLayer *map,
		PcgTile *pcgTile,
		PcgTileLayer *tile,
		CharGraphVec *cgs
	);

/*
	long calcDataIndex( PcgTileLayer *tile, long x, long y );
*/
	long searchCharGraphIndex(
		PcgTile *tile, long nSets, CharGraphVec *cgs
	);
/*
	long searchTileSets( PcgTile *tile, long data );
*/

	void initTownPtn();
	void resetTownPtn();
	void transMapToTownPtn();
	void transMapLayerToTownPtn(
		town_ptn_t *ptn, const PcgMapLayer *layer
	);

	void resetTownMap();
	void resetWorldMap();
	void transMapToCgMap(
		all_map_t *map, std::vector<PcgMapLayer *> &layers
	);
	void transMapLayerToCgMap(
		cg_layer_t *cg_layer, const PcgMapLayer *layer
	);

/*
	PcgTile *getPcgTile();
*/
};

////////////////////////////////////////////////////////////////
// グローバル・インスタンス
////////////////////////////////////////////////////////////////

extern PcgMap gPcgMap;

#endif /* PCG_MAP_H */
