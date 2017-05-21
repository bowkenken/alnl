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
* $Id: DemoEnding.cpp,v 1.21 2014/01/07 23:55:39 bowkenken Exp $
***************************************************************/

////////////////////////////////////////////////////////////////
// エンディング・デモ
////////////////////////////////////////////////////////////////

#define DEMO_ENDING_CPP
#include "inc.h"

////////////////////////////////////////////////////////////////

#define	ENDING_EPILOGUE_TIME	48
#define	ENDING_SPACE_TIME	(5 * 60)

// エンディング画像のディレクトリ
#define STR_ENDING_EPILOGUE_DIR_NAME	"ending/epilogue/"

#define ENDING_FONT_POINT	24
#define ENDING_FONT_DOT	24

static const char *gStrEnding[EPILOGUE_LINE_MAX_N + 1];

static const long FRAME_PER_CHAR = 6;
static const long WAIT_FRAME_CHAR = 18;

#ifdef	D_MFC
static const long skipFrameEpilogue = 1;
static const long skipFrameSpace = 1;
#else
# if	0
static const long skipFrameEpilogue = 6;
static const long skipFrameSpace = 1;
# else
static const long skipFrameEpilogue = 6;
static const long skipFrameSpace = 2;
# endif
#endif

////////////////////////////////////////////////////////////////
// コンストラクタ
////////////////////////////////////////////////////////////////

DemoEnding::DemoEnding()
{
	pStyle = NULL;
	flagSkipScene = false;
}

////////////////////////////////////////////////////////////////
// デストラクタ
////////////////////////////////////////////////////////////////

DemoEnding::~DemoEnding()
{
#ifdef D_MFC
	if( pFont != NULL ){
		delete pFont;
		pFont = NULL;
	}
#endif // D_MFC
}

////////////////////////////////////////////////////////////////
// 初期化
////////////////////////////////////////////////////////////////

void DemoEnding::init()
{
	space.init();

	// エンディング画像の検索を設定

	std::string dir = STR_DEFAULT_GRAPH_DIR_NAME;
	std::string ext = STR_GRAPH_FILE_EXT;

	FileList::setStrDirSelGraph( dir );
	FileList ls;

	// エンディング画像を検索

	nMaxFile = 0;
	ls.reset( STR_ENDING_EPILOGUE_DIR_NAME, ext );
	long j = 0;
	for( j = 0; j < LOOP_MAX_1000; j++ ){
		std::string path = ls.next();
		if( path.length() <= 0 )
			break;
	}
	nMaxFile = j;

	// エンディング画像をランダムに選択

	if( nMaxFile > 0 )
		nRandmSel = randm( nMaxFile );
	else
		nRandmSel = -1;

	// エンディング画像を読み込む

	if( nRandmSel > -1 ){
		ls.reset( STR_ENDING_EPILOGUE_DIR_NAME, ext );
		for( long j = 0; j < LOOP_MAX_1000; j++ ){
			std::string path = ls.next();
			if( path.length() <= 0 )
				break;
			if( j == nRandmSel ){
				pcgEpilogue.init( path );
				break;
			}
		}
	}

#ifdef D_GTK
	if( g_flg_gui_gl ){
		// デフォルトのスタイルを設定
		if( pStyle == NULL )
			pStyle = (void *)1;
# ifdef D_GL
		// エンディング画像の検索を設定

		std::string dir = STR_DEFAULT_GRAPH_DIR_NAME;
		std::string ext = STR_FONT_FILE_EXT;

		FileList::setStrDirSelGraph( dir );
		FileList ls;

		// エンディング画像を検索

		long nMaxFile = 0;
		ls.reset( STR_FONT_DIR_NAME, ext );

		long j = 0;
		for( j = 0; j < LOOP_MAX_1000; j++ ){
			std::string path = ls.next();
			if( path.length() <= 0 )
				break;
		}
		nMaxFile = j;

		// エンディング画像をランダムに選択

		if( nMaxFile > 0 )
			nRandmSel = randm( nMaxFile );
		else
			nRandmSel = -1;

		// エンディング画像を読み込む

		std::string path;
		if( nRandmSel > -1 ){
			ls.reset( STR_FONT_DIR_NAME, ext );
			for( long j = 0; j < LOOP_MAX_1000; j++ ){
				path = ls.next();
				if( path.length() <= 0 )
					break;
				if( j == nRandmSel ){
					break;
				}
			}
		}

		FTGL::FTGLfont *pFont = FTGL::ftglCreatePixmapFont(
				path.c_str() );
		if( pFont == NULL ){
			pStyle = NULL;
			::print_err( "Error: Load font file '%s'\n",
					path.c_str() );
			::exit_game( EXIT_FAILURE );
		} else {
			FTGL::ftglSetFontFaceSize( pFont,
					ENDING_FONT_POINT,
					ENDING_FONT_POINT );
			pStyle = pFont;
		}
# endif // D_GL
	} else {
		// デフォルトのスタイルを設定

		if( pStyle == NULL ){
			pStyle = gtk_style_copy(
					gtk_widget_get_default_style() );
		}
		GtkStyle *ps = (GtkStyle *)pStyle;
		if( ps->fg_gc[GTK_STATE_NORMAL] == NULL ){
			ps->fg_gc[GTK_STATE_NORMAL]
					= gdk_gc_new( gMapDrawingArea->window );
		}
		if( ps->bg_gc[GTK_STATE_NORMAL] == NULL ){
			ps->bg_gc[GTK_STATE_NORMAL]
					= gdk_gc_new( gMapDrawingArea->window );
		}

		// フォントを初期化

		char buf[32];
		sprintf( buf, "%ld", (long)(ENDING_FONT_POINT * 10) );
		std::string sFontPoint = buf;
		std::string sFontName = "";
		sFontName += "-*-*-*-i-normal-*-*-";
		sFontName += sFontPoint;
		sFontName += "-*,-*";

		gtk_style_set_font( ps,
				gdk_fontset_load( sFontName.c_str() ) );
	}
#endif // D_GTK

#ifdef D_MFC
	// デフォルトのスタイルを設定

	if( pStyle == NULL )
		pStyle = (void *)1;

	// フォントを初期化

	LONG h = ENDING_FONT_DOT;
	mFontDesc.lfHeight = h;
	mFontDesc.lfWidth = 0;
	mFontDesc.lfEscapement = 0;
	mFontDesc.lfOrientation = 0;
	mFontDesc.lfWeight = FW_NORMAL;
	mFontDesc.lfItalic = FALSE;
	mFontDesc.lfUnderline = FALSE;
	mFontDesc.lfStrikeOut = FALSE;
	mFontDesc.lfCharSet = SHIFTJIS_CHARSET;
	mFontDesc.lfOutPrecision = OUT_DEFAULT_PRECIS;
	mFontDesc.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	mFontDesc.lfQuality = DEFAULT_QUALITY;
	mFontDesc.lfPitchAndFamily = (FIXED_PITCH | FF_MODERN);
	strcpy( mFontDesc.lfFaceName, "Pica" );

	pFont = new CFont;
	pFont->CreateFontIndirect( &mFontDesc );

	mD3.Create( &mFontDesc );
#endif // D_MFC

	initAnime();
}

////////////////////////////////////////////////////////////////
// アニメーションの初期化
////////////////////////////////////////////////////////////////

void DemoEnding::initAnime()
{
	waitTime = 0;
	frame = 0;

	if( get_lang_kind() == LANG_KIND_ENGLISH ){
		x_dot = ENDING_FONT_DOT / 2;
		y_dot = ENDING_FONT_DOT;
	} else {
		x_dot = ENDING_FONT_DOT;
		y_dot = ENDING_FONT_DOT;
	}

	long k = 0;
	for( long i = 0; i < EPILOGUE_LINE_MAX_N; i++ ){
		gStrEnding[i] = &(MSG_EPILOGUE[k]);
		gStrEnding[i + 1] = NULL;

		for( long j = 0; j < EPILOGUE_MAX_LEN; j++ ){
			if( MSG_EPILOGUE[k] == '\0' )
				break;
			if( MSG_EPILOGUE[k] == '\n' ){
				k++;
				break;
			}
			k++;
		}
		if( MSG_EPILOGUE[k] == '\0' )
			break;
	}

	len = 1;
	for( long i = 0; i < EPILOGUE_LINE_MAX_N; i++ ){
		if( gStrEnding[i] == NULL )
			break;

		long k = 0;
		long j = 0;
		for( ; j < EPILOGUE_MAX_LEN; j++ ){
			if( gStrEnding[i][k] == '\0' )
				break;
			if( gStrEnding[i][k] == '\n' ){
				k++;
				break;
			}

			k += get_next_char_len( &(gStrEnding[i][k]) );
		}

		baseX[i] = j * x_dot;

		len = max_l( len, j );
	}
}

////////////////////////////////////////////////////////////////
// エンディング画面の描画
// return : エラーが無かったか?
////////////////////////////////////////////////////////////////

bool DemoEnding::draw()
{
	frame++;

	if( get_scene() == SCENE_N_ENDING ){
		gPcgDun.scrollTile( 0, 0 );

		// シーン切り替え
		waitTime = 0;
		change_scene_gui( SCENE_N_ENDING_EPILOGUE );
	}

	// エピローグ

	if( get_scene() == SCENE_N_ENDING_EPILOGUE ){
		// 初期化
		if( waitTime <= 0 ){
			waitTime = time( NULL ) + ENDING_EPILOGUE_TIME;
			frame = 0;
		}

		// フレームを間引く
		if( (frame % skipFrameEpilogue) != 0 )
			return true;

		if( !flagSkipScene && (time( NULL ) < waitTime) ){
			// 描画
			return drawEpilogue();
		} else {
			flagSkipScene = false;

			// シーン切り替え
			waitTime = 0;
			change_scene_gui( SCENE_N_ENDING_SPACE );
		}
	}

	// 宇宙

	if( get_scene() == SCENE_N_ENDING_SPACE ){
		// 初期化
		if( waitTime <= 0 ){
			waitTime = time( NULL ) + ENDING_SPACE_TIME;
			frame = 0;
		}

		// フレームを間引く
		if( (frame % skipFrameSpace) != 0 )
			return true;

		if( !flagSkipScene && (time( NULL ) < waitTime) ){
			// 描画
			return drawSpace( false );
		} else {
			flagSkipScene = false;

			// シーン切り替え
			waitTime = 0;
			change_scene_gui( SCENE_N_ENDING_STAFF_ROLL );
		}
	}

	// スタッフ・ロール

	if( get_scene() == SCENE_N_ENDING_STAFF_ROLL ){
		// フレームを間引く
		if( (frame % skipFrameSpace) != 0 )
			return true;

		if( !flagSkipScene ){
			// 描画
			return drawSpace( true );
		} else {
			flagSkipScene = false;

			// シーン切り替え
			waitTime = 0;
			change_scene_gui( SCENE_N_ENDING_END );
		}
	}

	// The End

	if( get_scene() == SCENE_N_ENDING_END ){
		// フレームを間引く
		if( (frame % skipFrameSpace) != 0 )
			return true;

		// 描画
		return drawSpace( true );
	}

	return true;
}

////////////////////////////////////////////////////////////////
// エピローグの描画
// return : エラーが無かったか?
////////////////////////////////////////////////////////////////

bool DemoEnding::drawEpilogue()
{
	if( nRandmSel <= -1 )
		return false;

#ifdef D_GTK
	if( g_flg_gui_gl ){
# ifdef D_GL
		// 背景を塗りつぶす

		double x = gPcgDun.getScrollBarX();
		double y = gPcgDun.getScrollBarY();
		double w = gPcgDun.getScrollBarW();
		double h = gPcgDun.getScrollBarH();

		double x1 = 0.0;
		double y1 = 0.0;
		double x2 = -(x1 + w);
		double y2 = +(y1 + h);
		double z1 = 1.0;
		double z2 = Pcg::depthBeginZ * 2;
		::glMatrixMode( GL_PROJECTION );
		::glLoadIdentity();
		::glOrtho( x1, x2, y2, y1, z1, z2 );

		::glMatrixMode( GL_MODELVIEW );
		::glLoadIdentity();
		::glClearColor( 1.0, 1.0, 1.0, 1.0 );
		::glEnable( GL_DEPTH );
		::glEnable( GL_DEPTH_TEST );
		::glEnable( GL_TEXTURE_2D );
		::glEnable( GL_BLEND );
		::glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		::glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,
				GL_MODULATE);
		::glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		double cx = x;
		double cy = y;
		double cz = 0.0;
		::gluLookAt(
				cx, cy, cz,
				cx, cy, (cz + 1.0),
				0.0, 1.0, 0.0 );

		Pcg::depthZ = Pcg::depthBeginZ;
# endif // D_GL
	} else {
		// 背景を塗りつぶす

		GtkStyle *ps = (GtkStyle *)pStyle;
		GdkDrawable *d = gPcgDun.getWBuf()->getPixMap();
		GdkGC *gc = ps->bg_gc[GTK_STATE_NORMAL];
		gdk_draw_rectangle( d, gc, TRUE,
				0, 0,
				gMapDrawingArea->allocation.width,
				gMapDrawingArea->allocation.height );
	}
#endif // D_GTK

	// 背景画像を描画

	long sx = gPcgDun.getScrollBarX();
	long sy = gPcgDun.getScrollBarY();
	long sw = gPcgDun.getScrollBarW();
	long sh = gPcgDun.getScrollBarH();

	long ww = pcgEpilogue.getWidth();
	long hh = pcgEpilogue.getHeight();
	long xx = sx + (sw - ww) / 2;
	long yy = sy + sh - hh;

	pcgEpilogue.draw( gPcgDun.getWBuf(), xx, yy, ww, hh );

	// ストーリーを描画

	drawEpilogueStory( frame );

	return true;
}

////////////////////////////////////////////////////////////////
// 宇宙の描画
// bool flagDrawStaffRoll : スタッフ・ロールを描画するか?
// return : エラーが無かったか?
////////////////////////////////////////////////////////////////

bool DemoEnding::drawSpace( bool flagDrawStaffRoll )
{
	return space.draw( flagDrawStaffRoll );
}

////////////////////////////////////////////////////////////////
// エピローグの描画 (ストーリー)
// long frame : 現在のフレーム
////////////////////////////////////////////////////////////////

void DemoEnding::drawEpilogueStory( long frame )
{
	if( pStyle == NULL )
		init();

	long n = 0;
	long nDraw;
	if( get_lang_kind() == LANG_KIND_ENGLISH )
		nDraw = (2 * frame / FRAME_PER_CHAR) - WAIT_FRAME_CHAR;
	else
		nDraw = (frame / FRAME_PER_CHAR) - WAIT_FRAME_CHAR;

	long sw = gPcgDun.getScrollBarW();
	long sh = gPcgDun.getScrollBarH();

	for( long i = 0; i < EPILOGUE_LINE_MAX_N; i++ ){
		if( gStrEnding[i] == NULL )
			break;

		long k = 0;
		for( long j = 0; j < len; j++ ){
			if( gStrEnding[i][k] == '\0' )
				break;
			if( gStrEnding[i][k] == '\n' ){
				k++;
				break;
			}

			if( n < nDraw ){
				long bx = (sw - baseX[i]) / 2;
				long by = sh / 2;
				long mx = bx + (j * x_dot);
				long my = by + (i * y_dot);
				x[i][j] = mx;
				y[i][j] = my;
			} else {
				x[i][j] = sw * 2;
				y[i][j] = sh * 2;
			}

			n++;
			k += get_next_char_len( &(gStrEnding[i][k]) );
		}
	}

	drawString();
}

////////////////////////////////////////////////////////////////
// エンディング文字列の描画
////////////////////////////////////////////////////////////////

void DemoEnding::drawString()
{
	for( long i = 0; i < EPILOGUE_LINE_MAX_N; i++ ){
		if( gStrEnding[i] == NULL )
			break;

		long k = 0;
		for( long j = 0; j < len; j++ ){
			if( gStrEnding[i][k] == '\0' )
				break;
			if( gStrEnding[i][k] == '\n' ){
				k++;
				break;
			}

			const char *p = &(gStrEnding[i][k]);

			drawCharStd( x[i][j], y[i][j],
					get_next_char_str( p ) );

			k += get_next_char_len( p );
		}
	}
}

////////////////////////////////////////////////////////////////
// エンディング文字の描画
////////////////////////////////////////////////////////////////

void DemoEnding::drawCharStd( long x, long y, const char *str )
{
	drawChar( 0x00, 0x00, 0x00, x + 1, y + 1, str );
	drawChar( 0x00, 0x00, 0x00, x - 1, y - 1, str );
	drawChar( 0xff, 0xff, 0xff, x, y, str );
}

////////////////////////////////////////////////////////////////
// エンディング文字の描画
////////////////////////////////////////////////////////////////

void DemoEnding::drawChar(
	long r, long g, long b,
	long x, long y, const char *str )
{
	if( str == NULL )
		return;

	r &= 0xff;
	g &= 0xff;
	b &= 0xff;

#ifdef D_GTK
	if( g_flg_gui_gl ){
# ifdef D_GL
		double xf = (double)x;
		double yf = (double)y;
		double zf = (double)Pcg::depthZ;
		double wf = (double)ENDING_FONT_DOT / 256.0;
		double hf = (double)ENDING_FONT_DOT / 256.0;
		double lwf = (double)ENDING_FONT_DOT / 16.0;
		Pcg::depthZ -= Pcg::depthDZ;

		double rf = (double)r / 255.0;
		double gf = (double)g / 255.0;
		double bf = (double)b / 255.0;

		::glPushMatrix();
		::glPushAttrib( GL_LINE_BIT );
		::glEnable( GL_DEPTH_TEST );
		::glDisable( GL_TEXTURE_2D );

		::glColor3d( rf, gf, bf );
		::glLineWidth( lwf );

		::glTranslated( xf, yf, zf );
		::glRotatef( 180, 1.0, 0.0, 0.0 );
		::glScaled( wf, hf, 0.0 );

#  if 1
		FTGL::FTGLfont *pFont = (FTGL::FTGLfont *)pStyle;
		::glRasterPos2d( xf, yf );
		FTGL::ftglRenderFont( pFont, str, FTGL::RENDER_ALL );
#  else
		::glutStrokeString( GLUT_STROKE_MONO_ROMAN,
				reinterpret_cast<const unsigned char *>
				( str ) );
#  endif

		::glPopAttrib();
		::glPopMatrix();
# endif // D_GL
	} else {
		GdkColor color;
		color.pixel = 0;
		color.red = (r << 8) | r;
		color.green = (g << 8) | g;
		color.blue = (b << 8) | b;

		GtkStyle *ps = (GtkStyle *)pStyle;
		GdkDrawable *d = gPcgDun.getWBuf()->getPixMap();
		GdkFont *font = gtk_style_get_font( ps );
		GdkGC *gc = ps->fg_gc[GTK_STATE_NORMAL];

		gdk_color_alloc( gdk_colormap_get_system(), &color );
		gdk_gc_set_foreground( gc, &color );

		gdk_draw_string( d, font, gc, x, y, str );
	}
#endif // D_GTK

#ifdef D_MFC
	D3DCOLOR color = D3DCOLOR_XRGB( r, g, b );

	mD3.Begin();
	mD3.Draw( x, y, color, str );
	mD3.End();
#endif // D_MFC
}

////////////////////////////////////////////////////////////////
// エンディングのシーンをスキップ
////////////////////////////////////////////////////////////////

void DemoEnding::skipScene()
{
	flagSkipScene = true;
}
