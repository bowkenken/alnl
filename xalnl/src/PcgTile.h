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

#ifndef PCG_TILE_H
#define PCG_TILE_H	1

////////////////////////////////////////////////////////////////
// マップ・タイル
////////////////////////////////////////////////////////////////

#include <vector>

#include "GameMisc.h"

#ifdef D_MFC
# include "xalnl-dows/Dir3d.h"
#endif //D_MFC

////////////////////////////////////////////////////////////////

class Pcg;

////////////////////////////////////////////////////////////////

class PcgTileSet {
public:
	std::string name;
	std::string image;

	long imageWidth;
	long imageHeight;
	long tileWidth;
	long tileHeight;

	long margin;
	long spacing;
	long firstGId;

	Pcg imagePcg;

private:

public:
	PcgTileSet()
	{
		name = "";
		image = "";

		imageWidth = 0;
		imageHeight = 0;
		tileWidth = 0;
		tileHeight = 0;

		margin = 0;
		spacing = 0;
		firstGId = 0;
	};
	~PcgTileSet(){};

	bool loadImage();

private:
};

////////////////////////////////////////////////////////////////

class PcgTileLayer {
public:
	std::string name;

	long width;
	long height;

	std::string type;
	bool visible;
	long opacity;

	long dataNum;
	std::vector<long> data;

	layer_kind_t kind;

private:

public:
	PcgTileLayer()
	{
		name = "";

		width = 0;
		height = 0;

		type = "";
		visible = false;
		opacity = 0;

		dataNum = 0;

		kind = LAYER_KIND_NULL;
	};
	~PcgTileLayer(){};

private:
};

////////////////////////////////////////////////////////////////

class PcgTile {
public:
	std::string path;
	std::string tileJson;

	long version;
	std::string orientation;
	std::string renderOrder;

	long width;
	long height;
	long tileWidth;
	long tileHeight;

	long nextObjectId;

	long tileSetsNum;
	std::vector<PcgTileSet *> tileSets;

	long tileLayersNum;
	std::vector<PcgTileLayer *> tileLayers;

private:

public:
	PcgTile();
	~PcgTile();

	void init();
	void reset();

	void setPath( std::string path );
	void setTileJsonData( std::string jsonData );
	void parse( std::string scriptString );

	void loadTileSets();

private:
/*
	void init();
	void reset();

	void setPath( std::string path );
	void setTileJsonData( std::string jsonData );
	void parse( std::string scriptString );
*/
};

#endif /* PCG_TILE_H */
