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

////////////////////////////////////////////////////////////////
// マップ
////////////////////////////////////////////////////////////////

#define	PCG_CHAR_GRAPH_CPP	1
#include "inc.h"

////////////////////////////////////////////////////////////////

const char *STR_CG_FILE_EXT = ".cg.json";

////////////////////////////////////////////////////////////////
// コンストラクタ
////////////////////////////////////////////////////////////////

PcgCharGraph::PcgCharGraph()
{
	graphPath = "";
	charPath = "";

	versionMajor = 0;
	versionMinor = 0;
	versionPatch = 0;

	charWidth = 0;
	charHeight = 0;

	width = 0;
	height = 0;

	rulerColumnLineHead = 0;
	rulerColumnLineTail = 0;
	rulerRowCharHead = 0;
	rulerRowCharTail = 0;
	backSlashChar = '\0';

	tile = "";
	color = "";
}

////////////////////////////////////////////////////////////////
// デストラクタ
////////////////////////////////////////////////////////////////

PcgCharGraph::~PcgCharGraph()
{
}

////////////////////////////////////////////////////////////////
// 初期化
////////////////////////////////////////////////////////////////

void PcgCharGraph::init()
{
	if( !g_flg_gui )
		return;
}

////////////////////////////////////////////////////////////////
// リセット
////////////////////////////////////////////////////////////////

void PcgCharGraph::reset()
{
	if( !g_flg_gui )
		return;

	if( g_flg_text_mode )
		return;
}

////////////////////////////////////////////////////////////////
// CG ファイルのパスを設定
// WSCstring path : 元タイルのパス
////////////////////////////////////////////////////////////////

void PcgCharGraph::setPath( WSCstring path )
{
	graphPath = path;
	charPath = path;

	if( path != "" )
		charPath += STR_CG_FILE_EXT;
}

