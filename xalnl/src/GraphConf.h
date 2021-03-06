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
* $Id: GraphConf.h,v 1.10 2014/01/07 23:44:46 bowkenken Exp $
***************************************************************/

#ifndef GRAPH_CONF_H
#define GRAPH_CONF_H	1

////////////////////////////////////////////////////////////////
// グラフィック設定
////////////////////////////////////////////////////////////////

#include "GameMisc.h"
#include "GraphConfToken.h"

////////////////////////////////////////////////////////////////

class GraphConf {

	// プライベート・メンバー変数
private:

	GraphConf *prev;
	GraphConf *next;

	std::string sDir;

	std::string title;
	long scale;
	long tile_size_x;
	long tile_size_y;
	std::string character_patern;
	std::string pc_patern;
	std::string monster_patern;
	std::string wall_patern;
	std::string town_wall_patern;
	std::string dungeon_wall_patern;
	std::string door_patern;
	std::string signboard_patern;
	bool text_mode;
	long font_size_point;
	long font_size_dot;

	// パブリック・メンバー変数
public:

	// パブリック・メンバー関数
public:

	GraphConf();
	~GraphConf();

	void setHead();
	GraphConf *getPrev();
	GraphConf *getNext();
	void insert( GraphConf *ls );

	void setDir( std::string dir );
	std::string getDir();

	bool setNum( GraphConfToken token, long n );
	bool setStr( GraphConfToken token, std::string str );
	long getNum( GraphConfToken token );
	std::string getStr( GraphConfToken token );

	// プライベート・メンバー関数
private:

};

#endif /* GRAPH_CONF_H */
