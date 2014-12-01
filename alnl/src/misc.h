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
* $Id: misc.h,v 1.24 2014/01/07 23:40:42 bowkenken Exp $
***************************************************************/

#ifndef	MISC_H
#define	MISC_H

/***************************************************************
* その他
***************************************************************/

#define	FLG_NULL	0

/* 数値入力の最大桁数 */
#define	FIGURE_MAX_N	10

/* パイ */
#define	DBL_PI	3.14159265358979323846

/***************************************************************
* マップ上の顔文字
***************************************************************/

#define	FACE_MJR_NULL	' '
#define	FACE_MNR_NULL	' '
#define	FACE_MJR_ERR	'?'
#define	FACE_MNR_ERR	'?'

/***************************************************************
* 無限ループ防止用の最大ループ数
***************************************************************/

#define	LOOP_MAX_100	128
#define	LOOP_MAX_200	256
#define	LOOP_MAX_500	512
#define	LOOP_MAX_1000	1024
#define	LOOP_MAX_4000	4096
#define	LOOP_MAX_10000	10240

/***************************************************************
* ブーリアン
***************************************************************/

typedef char	bool_t;

#ifndef	FALSE
# define	FALSE	0
#endif	/* FALSE */
#ifndef	TRUE
# define	TRUE	1
#endif	/* TRUE */

/***************************************************************
* 百分率(%)
***************************************************************/

typedef long	rate_t;

#define	_100_PERCENT	((rate_t)100)	/* 100% */
#define	MODIFIED_MIN_RATE	1	/* 修正値の最小値 */

/***************************************************************
* 比率(N:M)
***************************************************************/

typedef long	ratio_t;

/***************************************************************
* 金貨
***************************************************************/

typedef long	gold_t;

/* 999,999,999 */
#define	GOLD_MAX	999999999

/***************************************************************
* 座標
***************************************************************/

typedef struct {
	long	x, y;
} pos_t;

/***************************************************************
* バージョン
***************************************************************/

typedef struct {
	/* メジャー・バージョン */
	long	mjr;
	/* マイナー・バージョン */
	long	mnr;
	/* パッチ・レベル */
	long	pat;
} ver_t;

#endif	/* MISC_H */