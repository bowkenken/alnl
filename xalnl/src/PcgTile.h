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
// キャラグラ
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

class PcgTileSet {
public:
	WSCstring name;
	WSCstring image;

	long imagewidth;
	long imageheight;
	long tilewidth;
	long tileheight;

	long margin;
	long spacing;
	long firstgid;

private:

public:
	PcgTileSet()
	{
		name = "";
		image = "";

		imagewidth = 0;
		imageheight = 0;
		tilewidth = 0;
		tileheight = 0;

		margin = 0;
		spacing = 0;
		firstgid = 0;
	};
	~PcgTileSet(){};

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

	std::vector<long> data;

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
	};
	~PcgTileLayer(){};

private:
};

////////////////////////////////////////////////////////////////

class PcgTile {
public:
	WSCstring tileJson;

	long version;
	WSCstring orientation;
	WSCstring renderOrder;

	long width;
	long height;
	long tileWidth;
	long tileHeight;

	long nextObjectId;

	//@@@ std::vector<PcgTileSet> sets;
	// std::vector<PcgTileLayer> layers;

private:

public:
	PcgTile();
	~PcgTile();

	void init();
	void reset();

	void setPath( WSCstring path );
	void setTileJsonData( WSCstring jsonData );
	void parse( WSCstring scriptString );

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
