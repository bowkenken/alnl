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
* $Id: DemoTitle.h,v 1.12 2014/01/07 23:44:46 bowkenken Exp $
***************************************************************/

#ifndef DEMO_TITLE_H
#define DEMO_TITLE_H	1

////////////////////////////////////////////////////////////////
// タイトル・デモ
////////////////////////////////////////////////////////////////

#ifdef D_GTK
# include <gtk/gtk.h>
#endif /* D_GTK */

#ifdef D_MFC
# include "xalnl-dows/stdafx.h"
# include "xalnl-dows/xalnl-dows.h"
# include "xalnl-dows/Dir3dText.h"
#endif // D_MFC

#include "Pcg.h"

////////////////////////////////////////////////////////////////

#define TITLE_MAX_ROW	3
#define TITLE_MAX_COL	16

////////////////////////////////////////////////////////////////

class DemoTitle {
public:

private:
	// ランダムに選ばれたタイトル画像のファイル番号
	long nTitleRandmSelN;
	// タイトル画像のファイル数
	long nTitleN;
	// タイトルの画像
	Pcg pcgTitle;

	// ゲーム名のアニメ用座標
	long len;
	long w, h;
	long baseX, baseY;
	long mx[TITLE_MAX_ROW][TITLE_MAX_COL];
	long my[TITLE_MAX_ROW][TITLE_MAX_COL];
	long x[TITLE_MAX_ROW][TITLE_MAX_COL];
	long y[TITLE_MAX_ROW][TITLE_MAX_COL];

#ifdef D_GTK
	// フォントのスタイル
	GtkStyle *pTitleStyle;
#endif // D_GTK
	
#ifdef D_MAC
	// フォントのスタイル
	void *pTitleStyle;
#endif // D_MAC
	
#ifdef D_IPHONE
	// フォントのスタイル
	void *pTitleStyle;
#endif // D_IPHONE
	
#ifdef D_MFC
	// フォントのスタイル
	void *pTitleStyle;
	LOGFONT mTitleFontDesc;
	CFont *pTitleFont;

	CDir3dText mD3Title;
#endif // D_MFC

public:
	DemoTitle();
	~DemoTitle();
	void init();

	bool draw();

private:
	void initAnime();
	void drawTitle0( long frame );
	void drawTitle1( long frame );
	void drawTitle2( long frame );
	void drawTitle3( long frame );
	void drawTitle4( long frame );
	void drawTitle5( long frame );
	void drawTitle6( long frame );

	void drawTitleString();
	void drawTitleCharStd( long x, long y, char c );
	void drawTitleChar(
		long r, long g, long b,
		long x, long y, char c );
};

#endif // DEMO_TITLE_H
