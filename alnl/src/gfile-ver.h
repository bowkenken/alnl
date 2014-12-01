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
* $Id: gfile-ver.h,v 1.80 2014/01/07 23:40:42 bowkenken Exp $
***************************************************************/

#ifndef	GFILE_VER_H
#define	GFILE_VER_H

/***************************************************************
* ファイルのバージョン監理
***************************************************************/

#define	STR_GAME_RC_HEAD	"# L&L - run command file version "
#define	STR_GAME_CONF_HEAD	"# L&L - configure file version "
#define	STR_GAME_DATA_HEAD	"# L&L - data file version "
#define	STR_GAME_REPLAY_HEAD	"# L&L - replay file version "
#define	STR_GRAPH_CONF_HEAD	"# L&L - graphic configure - version "


/***************************************************************
* 設定ファイル ~/.alnl/usr/lnl.conf
* History:
* 0.1.0
*   2014/06/26
*   初期化
***************************************************************/

#define	GAME_CONF_VER_MJR	1
#define	GAME_CONF_VER_MNR	0
#define	GAME_CONF_VER_PAT	24


/***************************************************************
* キャラクタ・データ
* ~/.alnl/save/bin/save??.bin
* ~/.alnl/save/txt/save??.txt
* ~/.alnl/save/cnf/conf??.txt
* History:
* 0.1.0
*   2014/06/26
*   初期化
***************************************************************/

#define	GAME_DATA_VER_MJR	1
#define	GAME_DATA_VER_MNR	2
#define	GAME_DATA_VER_PAT	41


/***************************************************************
* グラフィック設定
* ~/.alnl/xalnl/graph/???/xalnl-conf.txt
* History:
* 0.1.0
*   2014/06/26
*   初期化
***************************************************************/

#define	GRAPH_CONF_VER_MJR	1
#define	GRAPH_CONF_VER_MNR	0
#define	GRAPH_CONF_VER_PAT	0


#endif	/* GFILE_VER_H */
