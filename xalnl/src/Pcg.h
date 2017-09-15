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
* $Id: Pcg.h,v 1.24 2014/01/07 23:44:46 bowkenken Exp $
***************************************************************/

#ifndef PCG_H
#define PCG_H	1

////////////////////////////////////////////////////////////////
// グラフィック・パターン管理
////////////////////////////////////////////////////////////////

#if defined( HAVE_SDL2_SDL_H )
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_opengl.h>
#elif defined( HAVE_SDL_SDL_H )
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_opengl.h>
#endif // HAVE_SDL2_SDL_H

#ifdef D_GL
# include <GL/gl.h>
# include <GL/glx.h>
# include <GL/glu.h>
# include <GL/glut.h>
# include <GL/freeglut_ext.h>
# include <FTGL/ftgl.h>
#endif // D_GL

#ifdef D_WS
# include <WSCimageSet.h>
# include <WSDmwindowDev.h>
#endif // D_WS

#ifdef D_GTK
# include "GtkWSDimage.h"
# include "GtkWSDmwindowDev.h"
#endif // D_GTK

#ifdef D_MAC
# include "MacWSDimage.h"
# include "MacWSDmwindowDev.h"
#endif // D_MAC

#ifdef D_IPHONE
# include "IPhoneWSDimage.h"
# include "IPhoneWSDmwindowDev.h"
#endif // D_IPHONE

#ifdef D_MFC
# include "MfcWSDimage.h"
# include "MfcWSDmwindowDev.h"
#endif // D_MFC

#include "GameMisc.h"

class Pcg {
private:
	// 描画可能待ちの最大待ち時間のデフォルト（ミリ秒）
	static const long nWaitReadyMSecDflt = 100;
	// 描画可能待ちの最大待ち時間（ミリ秒）
	long nWaitReadyMSec;

	// グラフィック・ファイルのパス名
	std::string sPath;
	// グラフィック・パターン
	WSDimage *pImage;

	// パターンのサイズ
	long	nWidth;
	long	nHeight;
	// 2^n に正規化後のパターンのサイズ
	long	nWidthPad;
	long	nHeightPad;

public:
	// リストの次の項目
	Pcg *next;
	// 大型化した時のパターン
	Pcg *hyper_boss;
	// パターンのバリエーションの使用比率
	ratio_t nRatio;
	// パターンのバリエーションの使用率
	rate_t nRate;
	char mjr, mnr;

	static const double depthBeginZ;
	static const double depthDZ;
	// 現在の Z's バッファの深さ
	static double depthZ;

#ifdef D_GL
	// パターンのテクスチャ
	GLuint texName;
#endif // D_GL

public:
	Pcg()
	{
		nWaitReadyMSec = nWaitReadyMSecDflt;

		pImage = NULL;
		next = NULL;
		hyper_boss = NULL;
		nRatio = (ratio_t)1;
		nRate = _100_PERCENT;
		mjr = FACE_MJR_NULL;
		mnr = FACE_MNR_NULL;

		nWidth = 0;
		nHeight = 0;
	}
	~Pcg()
	{
		if( hyper_boss != NULL ){
			delete hyper_boss;
			hyper_boss = NULL;
		}

		if( pImage != NULL ){
			pImage->destroyImage();
			delete pImage;
			pImage = NULL;
		}
	}

	void init( std::string path );
	void load( std::string path );
	void loadTextureGL();
	void ena();
	void dis();

	std::string getPath();
	std::string getName();

	long getWidth();
	long getHeight();

	bool waitReady( WSDmwindowDev *mDev );

	bool beginAlpha();
	bool endAlpha();

	bool draw( WSDmwindowDev *mDev,
			long x, long y, long dx, long dy );
	bool drawFix( WSDmwindowDev *mDev,
			long x, long y, long dx, long dy );
	bool drawIdx( WSDmwindowDev *mDev,
			long x, long y, long w, long h,
			long idxX, long idxY,
			long sizeX, long sizeY );
	bool drawOffset( WSDmwindowDev *mDev,
			long x, long y, long w, long h,
			long offsetX, long offsetY );

	long lToPow2( long n );

private:
};

#endif /* PCG_H */
