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

#include "GameMisc.h"

long getWordNum( std::string str, std::string delim )
{
	if( delim.length() <= 0 )
		return 0;

	size_t pos = 0;
	long n = 1;
	for( ; ; n++ ){
		pos = str.find( delim, pos );
		if( pos == std::string::npos )
			break;

		pos += delim.length();
	}

	return n;
}

long getWordPos( std::string str, long n, std::string delim )
{
	size_t pos = 0;
	for( long i = 0; i < n; i++ ){
		pos = str.find( delim, pos );
		if( pos == std::string::npos )
			return -1;

		pos += delim.length();
	}

	return (long)pos;
}

std::string getWord( std::string str, long n, std::string delim )
{
	long maxN = ::getWordNum( str, delim ) - 1;
	if( n > maxN )
		return "";
	if( n < 0 )
		return "";

	long n1 = ::getWordPos( str, n, delim );
	long n2 = ::getWordPos( str, n + 1, delim );
	if( n1 <= -1 )
		n1 = 0;
	if( n2 <= -1 )
		n2 = str.length() + 1;

	return( str.substr( n1, n2 - n1 - 1 ) );
}
