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
// マップ・タイル
////////////////////////////////////////////////////////////////

#define	PCG_TILE_CPP	1
#include "inc.h"

using namespace v8;

////////////////////////////////////////////////////////////////
// コンストラクタ
////////////////////////////////////////////////////////////////

PcgTile::PcgTile()
{
	version = 0;
	orientation = "";
	renderOrder = "";

	width = 0;
	height = 0;
	tileWidth = 0;
	tileHeight = 0;

	nextObjectId = 0;
}

////////////////////////////////////////////////////////////////
// デストラクタ
////////////////////////////////////////////////////////////////

PcgTile::~PcgTile()
{
}

////////////////////////////////////////////////////////////////
// 初期化
////////////////////////////////////////////////////////////////

void PcgTile::init()
{
	if( !g_flg_gui )
		return;

	version = 0;
	orientation = "";
	renderOrder = "";

	width = 0;
	height = 0;
	tileWidth = 0;
	tileHeight = 0;

	nextObjectId = 0;
}

////////////////////////////////////////////////////////////////
// リセット
////////////////////////////////////////////////////////////////

void PcgTile::reset()
{
	if( !g_flg_gui )
		return;

	if( g_flg_text_mode )
		return;

	init();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパス名を設定
// WSCstring path : タイル・ファイルのパス名
////////////////////////////////////////////////////////////////

void PcgTile::setPath( WSCstring path )
{
}

////////////////////////////////////////////////////////////////
// タイル・ファイルの内容を設定
// WSCstring path : タイル・ファイルの内容
////////////////////////////////////////////////////////////////

void PcgTile::setTileJsonData( WSCstring jsonData )
{
	tileJson = jsonData;
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getPcgTileWSCstring(
	Local<String> property, const AccessorInfo &info
)
{
	// fprintf( stderr, "getPcgTileWSCstring(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgTile *ptr = static_cast<PcgTile *>(wrap->Value());
	WSCstring value = "";

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	if( name == "tileJson" )
		value = ptr->tileJson;
	else if( name == "orientation" )
		value = ptr->orientation;
	else if( name == "renderOrder" )
		value = ptr->renderOrder;
	// fprintf( stderr, "value: [%s]\n", value.c_str() );//

	// fprintf( stderr, "getPcgTileWSCstring(): end\n" );//
	return String::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setPcgTileWSCstring(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	// fprintf( stderr, "setPcgTileWSCstring(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgTile *ptr = static_cast<PcgTile *>(wrap->Value());
	String::Utf8Value str( value );

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	if( name == "tileJson" )
		ptr->tileJson = *str;
	else if( name == "orientation" )
		ptr->orientation = *str;
	else if( name == "renderOrder" )
		ptr->renderOrder = *str;
	// fprintf( stderr, "value: [%s]\n", str->c_str() );//

	// fprintf( stderr, "setPcgTileWSCstring(): end\n" );//
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getPcgTileLong(
	Local<String> property, const AccessorInfo &info
)
{
	// fprintf( stderr, "getPcgTileLong(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgTile *ptr = static_cast<PcgTile *>(wrap->Value());
	long value = 0;

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	if( name == "version" )
		value = ptr->version;
	else if( name == "width" )
		value = ptr->width;
	else if( name == "height" )
		value = ptr->height;
	else if( name == "tileWidth" )
		value = ptr->tileWidth;
	else if( name == "tileHeight" )
		value = ptr->tileHeight;
	else if( name == "nextObjectId" )
		value = ptr->nextObjectId;
	// fprintf( stderr, "value: [%ld]\n", value );//

	// fprintf( stderr, "getPcgTileLong(): end\n" );//
	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setPcgTileLong(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	// fprintf( stderr, "setPcgTileLong(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgTile *ptr = static_cast<PcgTile *>(wrap->Value());
	long n = value->Int32Value();

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	if( name == "version" )
		ptr->version = n;
	else if( name == "width" )
		ptr->width = n;
	else if( name == "height" )
		ptr->height = n;
	else if( name == "tileWidth" )
		ptr->tileWidth = n;
	else if( name == "tileHeight" )
		ptr->tileHeight = n;
	else if( name == "nextObjectId" )
		ptr->nextObjectId = n;
	// fprintf( stderr, "value: [%ld]\n", n );//

	// fprintf( stderr, "setPcgTileLong(): end\n" );//
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパース
// WSCstring scriptString : キャラグラのパース用スクリプト
////////////////////////////////////////////////////////////////

void PcgTile::parse( WSCstring scriptString )
{
	HandleScope aHandleScope;

	Handle<ObjectTemplate> aGlobal = ObjectTemplate::New();

	Persistent<Context> aContext = Context::New( NULL, aGlobal );
	Context::Scope aContextScope( aContext );

	Handle<ObjectTemplate> aTemplate = ObjectTemplate::New();
	aTemplate->SetInternalFieldCount( 1 );
	aTemplate->SetAccessor( String::New( "tileJson" ),
			getPcgTileWSCstring, setPcgTileWSCstring );
	aTemplate->SetAccessor( String::New( "version" ),
			getPcgTileLong, setPcgTileLong );
	aTemplate->SetAccessor( String::New( "orientation" ),
			getPcgTileWSCstring, setPcgTileWSCstring );
	aTemplate->SetAccessor( String::New( "renderOrder" ),
			getPcgTileWSCstring, setPcgTileWSCstring );
	aTemplate->SetAccessor( String::New( "width" ),
			getPcgTileLong, setPcgTileLong );
	aTemplate->SetAccessor( String::New( "height" ),
			getPcgTileLong, setPcgTileLong );
	aTemplate->SetAccessor( String::New( "tileWidth" ),
			getPcgTileLong, setPcgTileLong );
	aTemplate->SetAccessor( String::New( "tileHeight" ),
			getPcgTileLong, setPcgTileLong );
	aTemplate->SetAccessor( String::New( "nextObjectId" ),
			getPcgTileLong, setPcgTileLong );

	Local<Object> aObject = aTemplate->NewInstance();
	aObject->SetInternalField( 0, External::New( this ) );
	aContext->Global()->Set( String::New( "gPcgTile" ), aObject );

	Handle<String> aSource = String::New( scriptString.c_str() );
	Handle<Script> aScript = Script::Compile( aSource );
	aScript->Run();
	aContext.Dispose();

	// fprintf( stderr, "script:\n" );//
	// fprintf( stderr, "----begin----\n" );//
	// fprintf( stderr, "%s", scriptString.c_str() );//
	// fprintf( stderr, "----end----\n" );//

	// fprintf( stderr, "tileJson: [%s]\n", tileJson.c_str() );//
	fprintf( stderr, "version: [%ld]\n", version );//
	fprintf( stderr, "orientation: [%s]\n", orientation.c_str() );//
	fprintf( stderr, "renderOrder: [%s]\n", renderOrder.c_str() );//
	fprintf( stderr, "width: [%ld]\n", width );//
	fprintf( stderr, "height: [%ld]\n", height );//
	fprintf( stderr, "tileWidth: [%ld]\n", tileWidth );//
	fprintf( stderr, "tileHeight: [%ld]\n", tileHeight );//
	fprintf( stderr, "nextObjectId: [%ld]\n", nextObjectId );//
}
