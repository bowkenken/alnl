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

#ifdef D_WS
# include <WSCstring.h>
#endif //D_WS

#ifdef D_GTK
# include "GtkWSCstring.h"
#endif //D_GTK

#ifdef D_MAC
# include "MacWSCstring.h"
#endif //D_MAC

#ifdef D_IPHONE
# include "IPhoneWSCstring.h"
#endif //D_IPHONE

#ifdef D_MFC
# include "MfcWSCstring.h"
# include "xalnl-dows/Dir3d.h"
#endif //D_MFC

////////////////////////////////////////////////////////////////
// レイヤーの種類
////////////////////////////////////////////////////////////////

// オブジェクトの種類を決定するレイヤーの名前の接頭字
#define STR_MAP_LAYER_NAME_OBJECT	"_object_"
// 閉じたドアを描画するレイヤーの名前の接頭字
#define STR_MAP_LAYER_NAME_DOOR_CLOSE	"_door_close_"
// 開いたドアを描画するレイヤーの名前の接頭字
#define STR_MAP_LAYER_NAME_DOOR_OPEN	"_door_open_"
// 隠されたドアを描画するレイヤーの名前の接頭字
#define STR_MAP_LAYER_NAME_DOOR_SECRET	"_door_secret_"
// 閉じた窓を描画するレイヤーの名前の接頭字
#define STR_MAP_LAYER_NAME_WINDOW_CLOSE	"_window_close_"
// 開いた窓を描画するレイヤーの名前の接頭字
#define STR_MAP_LAYER_NAME_WINDOW_OPEN	"_window_open_"
// 消えたランプを描画するレイヤーの名前の接頭字
#define STR_MAP_LAYER_NAME_LAMP_OFF	"_lamp_off_"
// 灯ったランプを描画するレイヤーの名前の接頭字
#define STR_MAP_LAYER_NAME_LAMP_ON	"_lamp_on_"
// キャラクタを描画するレイヤーの名前の接頭字
#define STR_MAP_LAYER_NAME_CHR	"_char_"

// マップ・レイヤーの種類
typedef enum {
	MAP_LAYER_KIND_NULL,
	MAP_LAYER_KIND_OBJECT,
	MAP_LAYER_KIND_DOOR_CLOSE,
	MAP_LAYER_KIND_DOOR_OPEN,
	MAP_LAYER_KIND_DOOR_SECRET,
	MAP_LAYER_KIND_WINDOW_CLOSE,
	MAP_LAYER_KIND_WINDOW_OPEN,
	MAP_LAYER_KIND_LAMP_OFF,
	MAP_LAYER_KIND_LAMP_ON,
	MAP_LAYER_KIND_CHR,
	MAP_LAYER_KIND_MAX,
} MapLayerKind;

////////////////////////////////////////////////////////////////

class Pcg;

////////////////////////////////////////////////////////////////

class PcgTileSet {
public:
	WSCstring name;
	WSCstring image;

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
	WSCstring name;

	long width;
	long height;

	WSCstring type;
	bool visible;
	long opacity;

	long dataNum;
	std::vector<long> data;

	MapLayerKind kind;

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

		kind = MAP_LAYER_KIND_NULL;
	};
	~PcgTileLayer(){};

private:
};

////////////////////////////////////////////////////////////////

class PcgTile {
public:
	WSCstring path;
	WSCstring tileJson;

	long version;
	WSCstring orientation;
	WSCstring renderOrder;

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

	void setPath( WSCstring path );
	void setTileJsonData( WSCstring jsonData );
	void parse( WSCstring scriptString );

	void loadTileSets();

private:
/*
	void init();
	void reset();

	void setPath( WSCstring path );
	void setTileJsonData( WSCstring jsonData );
	void parse( WSCstring scriptString );
*/
};

#endif /* PCG_TILE_H */
