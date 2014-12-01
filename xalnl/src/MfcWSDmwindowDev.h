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
* $Id: MfcWSDmwindowDev.h,v 1.7 2014/01/07 23:44:46 bowkenken Exp $
***************************************************************/

#ifndef MFC_WSD_MWINDOW_DEV_H
#define MFC_WSD_MWINDOW_DEV_H	1

#include "xalnl-dows/stdafx.h"

#include "MfcMisc.h"

class WSDmwindowDev
{
private:
	void *pPixMap;

public:
	WSDmwindowDev();
	static WSDmwindowDev *getNewInstance();
	void createPixmap( long nSizeX, long nSizeY );

	void *getPixMap();

	WSCbool getReady();

	void copyToWindow(
		WSDmwindowDev *dst,
		long srcX, long srcY,
		long w, long h,
		long dstX, long dstY );
};

#endif // MFC_WSD_MWINDOW_DEV_H
