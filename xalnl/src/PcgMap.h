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

class PcgCharGraph;

////////////////////////////////////////////////////////////////

class PcgMap {
public:

private:
	WSCstring sCharGraphParserFile;

	PcgCharGraph *pCgWestTried;

public:
	PcgMap();
	~PcgMap();

	void initPcgCharGraph();
	void init();
	void reset();

private:
/*
	void initPcgCharGraph();
	void init();
	void reset();
*/

	void loadCharGraphParserFile();
	void parsePcgCharGraph();
};

#endif /* PCG_MAP_H */
