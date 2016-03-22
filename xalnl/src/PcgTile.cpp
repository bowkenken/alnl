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

	tileSetsNum = 0;
	tileLayersNum = 0;
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

	tileSetsNum = 0;
	tileLayersNum = 0;
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
// JSON の文字列のゲッター
// Local<String> property : メンバー名
// const AccessorInfo &info : オブジェクトのポインタ取得用
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
// JSON の文字列のセッター
// Local<String> property : メンバー名
// Local<Value> value : セットする文字列
// const AccessorInfo &info : オブジェクトのポインタ取得用
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
// JSON の数値のゲッター
// Local<String> property : メンバー名
// const AccessorInfo &info : オブジェクトのポインタ取得用
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
	else if( name == "tileSetsNum" )
		value = ptr->tileSetsNum;
	else if( name == "tileLayersNum" )
		value = ptr->tileLayersNum;
	// fprintf( stderr, "value: [%ld]\n", value );//

	// fprintf( stderr, "getPcgTileLong(): end\n" );//
	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// JSON の数値のセッター
// Local<String> property : メンバー名
// Local<Value> value : セットする数値
// const AccessorInfo &info : オブジェクトのポインタ取得用
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
	else if( name == "tileSetsNum" )
		ptr->tileSetsNum = n;
	else if( name == "tileLayersNum" )
		ptr->tileLayersNum = n;
	// fprintf( stderr, "value: [%ld]\n", n );//

	// fprintf( stderr, "setPcgTileLong(): end\n" );//
}

////////////////////////////////////////////////////////////////
// JSON のタイル・セットの文字列のゲッター
// Local<String> property : メンバー名
// const AccessorInfo &info : オブジェクトのポインタ取得用
////////////////////////////////////////////////////////////////

Handle<Value> getPcgTileSetsWSCstring(
	Local<String> property, const AccessorInfo &info
)
{
	// fprintf( stderr, "getPcgTileSetsWSCstring(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgTile *ptr = static_cast<PcgTile *>(wrap->Value());
	WSCstring value = "";

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	for( long i = ptr->tileSets.size(); i <= ptr->tileSetsNum; i++ )
		ptr->tileSets.push_back( new PcgTileSet );

	if( name == "name" )
		value = ptr->tileSets[ptr->tileSetsNum]->name;
	else if( name == "image" )
		value = ptr->tileSets[ptr->tileSetsNum]->image;
	// fprintf( stderr, "value: [%s]\n", value.c_str() );//

	// fprintf( stderr, "getPcgTileSetsWSCstring(): end\n" );//
	return String::New( value );
}

////////////////////////////////////////////////////////////////
// JSON のタイル・セットの文字列のセッター
// Local<String> property : メンバー名
// Local<Value> value : セットする文字列
// const AccessorInfo &info : オブジェクトのポインタ取得用
////////////////////////////////////////////////////////////////

void setPcgTileSetsWSCstring(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	// fprintf( stderr, "setPcgTileSetsWSCstring(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgTile *ptr = static_cast<PcgTile *>(wrap->Value());
	String::Utf8Value str( value );

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	for( long i = ptr->tileSets.size(); i <= ptr->tileSetsNum; i++ )
		ptr->tileSets.push_back( new PcgTileSet );

	if( name == "name" )
		ptr->tileSets[ptr->tileSetsNum]->name = *str;
	else if( name == "image" )
		ptr->tileSets[ptr->tileSetsNum]->image = *str;
	// fprintf( stderr, "value: [%s]\n", str->c_str() );//

	// fprintf( stderr, "setPcgTileSetsWSCstring(): end\n" );//
}

////////////////////////////////////////////////////////////////
// JSON のタイル・セットの数値のゲッター
// Local<String> property : メンバー名
// const AccessorInfo &info : オブジェクトのポインタ取得用
////////////////////////////////////////////////////////////////

Handle<Value> getPcgTileSetsLong(
	Local<String> property, const AccessorInfo &info
)
{
	// fprintf( stderr, "getPcgTileSetsLong(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgTile *ptr = static_cast<PcgTile *>(wrap->Value());
	long value = 0;

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	for( long i = ptr->tileSets.size(); i <= ptr->tileSetsNum; i++ )
		ptr->tileSets.push_back( new PcgTileSet );

	if( name == "imageWidth" )
		value = ptr->tileSets[ptr->tileSetsNum]->imageWidth;
	else if( name == "imageHeight" )
		value = ptr->tileSets[ptr->tileSetsNum]->imageHeight;
	else if( name == "tileWidth" )
		value = ptr->tileSets[ptr->tileSetsNum]->tileWidth;
	else if( name == "tileHeight" )
		value = ptr->tileSets[ptr->tileSetsNum]->tileHeight;
	else if( name == "margin" )
		value = ptr->tileSets[ptr->tileSetsNum]->margin;
	else if( name == "spacing" )
		value = ptr->tileSets[ptr->tileSetsNum]->spacing;
	else if( name == "firstGId" )
		value = ptr->tileSets[ptr->tileSetsNum]->firstGId;
	// fprintf( stderr, "value: [%ld]\n", value );//

	// fprintf( stderr, "getPcgTileSetsLong(): end\n" );//
	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// JSON のタイル・セットの数値のセッター
// Local<String> property : メンバー名
// Local<Value> value : セットする数値
// const AccessorInfo &info : オブジェクトのポインタ取得用
////////////////////////////////////////////////////////////////

void setPcgTileSetsLong(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	// fprintf( stderr, "setPcgTileSetsLong(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgTile *ptr = static_cast<PcgTile *>(wrap->Value());
	long n = value->Int32Value();

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	for( long i = ptr->tileSets.size(); i <= ptr->tileSetsNum; i++ )
		ptr->tileSets.push_back( new PcgTileSet );

	if( name == "imageWidth" )
		ptr->tileSets[ptr->tileSetsNum]->imageWidth = n;
	else if( name == "imageHeight" )
		ptr->tileSets[ptr->tileSetsNum]->imageHeight = n;
	else if( name == "tileWidth" )
		ptr->tileSets[ptr->tileSetsNum]->tileWidth = n;
	else if( name == "tileHeight" )
		ptr->tileSets[ptr->tileSetsNum]->tileHeight = n;
	else if( name == "margin" )
		ptr->tileSets[ptr->tileSetsNum]->margin = n;
	else if( name == "spacing" )
		ptr->tileSets[ptr->tileSetsNum]->spacing = n;
	else if( name == "firstGId" )
		ptr->tileSets[ptr->tileSetsNum]->firstGId = n;
	// fprintf( stderr, "value: [%ld]\n", n );//

	// fprintf( stderr, "setPcgTileSetsLong(): end\n" );//
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

	// タイル

	Handle<ObjectTemplate> aTemplateTile = ObjectTemplate::New();
	aTemplateTile->SetInternalFieldCount( 1 );

	aTemplateTile->SetAccessor( String::New( "tileJson" ),
			getPcgTileWSCstring, setPcgTileWSCstring );
	aTemplateTile->SetAccessor( String::New( "version" ),
			getPcgTileLong, setPcgTileLong );
	aTemplateTile->SetAccessor( String::New( "orientation" ),
			getPcgTileWSCstring, setPcgTileWSCstring );
	aTemplateTile->SetAccessor( String::New( "renderOrder" ),
			getPcgTileWSCstring, setPcgTileWSCstring );
	aTemplateTile->SetAccessor( String::New( "width" ),
			getPcgTileLong, setPcgTileLong );
	aTemplateTile->SetAccessor( String::New( "height" ),
			getPcgTileLong, setPcgTileLong );
	aTemplateTile->SetAccessor( String::New( "tileWidth" ),
			getPcgTileLong, setPcgTileLong );
	aTemplateTile->SetAccessor( String::New( "tileHeight" ),
			getPcgTileLong, setPcgTileLong );
	aTemplateTile->SetAccessor( String::New( "nextObjectId" ),
			getPcgTileLong, setPcgTileLong );
	aTemplateTile->SetAccessor( String::New( "tileSetsNum" ),
			getPcgTileLong, setPcgTileLong );

	Local<Object> aObjectTile = aTemplateTile->NewInstance();
	aObjectTile->SetInternalField( 0, External::New( this ) );
	aContext->Global()->Set( String::New( "gPcgTile" ),
			aObjectTile );

	// タイル・セット

	Handle<ObjectTemplate> aTemplateTileSets = ObjectTemplate::New();
	aTemplateTileSets->SetInternalFieldCount( 1 );

	aTemplateTileSets->SetAccessor( String::New( "name" ),
			getPcgTileSetsWSCstring, setPcgTileSetsWSCstring );
	aTemplateTileSets->SetAccessor( String::New( "image" ),
			getPcgTileSetsWSCstring, setPcgTileSetsWSCstring );
	aTemplateTileSets->SetAccessor( String::New( "imageWidth" ),
			getPcgTileSetsLong, setPcgTileSetsLong );
	aTemplateTileSets->SetAccessor( String::New( "imageHeight" ),
			getPcgTileSetsLong, setPcgTileSetsLong );
	aTemplateTileSets->SetAccessor( String::New( "tileWidth" ),
			getPcgTileSetsLong, setPcgTileSetsLong );
	aTemplateTileSets->SetAccessor( String::New( "tileHeight" ),
			getPcgTileSetsLong, setPcgTileSetsLong );
	aTemplateTileSets->SetAccessor( String::New( "margin" ),
			getPcgTileSetsLong, setPcgTileSetsLong );
	aTemplateTileSets->SetAccessor( String::New( "spacing" ),
			getPcgTileSetsLong, setPcgTileSetsLong );
	aTemplateTileSets->SetAccessor( String::New( "firstGId" ),
			getPcgTileSetsLong, setPcgTileSetsLong );

	Local<Object> aObjectTileSets = aTemplateTileSets->NewInstance();
	aObjectTileSets->SetInternalField( 0, External::New( this ) );
	aContext->Global()->Set( String::New( "gPcgTileSets" ),
			aObjectTileSets );

	//

	Handle<String> aSource = String::New( scriptString.c_str() );
	Handle<Script> aScript = Script::Compile( aSource );
	aScript->Run();
	aContext.Dispose();

#if	1
	// fprintf( stderr, "script:\n" );//
	// fprintf( stderr, "----begin----\n" );//
	// fprintf( stderr, "%s", scriptString.c_str() );//
	// fprintf( stderr, "----end----\n" );//

	// fprintf( stderr, "tileJson: [%s]\n", tileJson.c_str() );//
	fprintf( stderr, "\n" );//
	fprintf( stderr, "version: [%ld]\n", version );//
	fprintf( stderr, "orientation: [%s]\n", orientation.c_str() );//
	fprintf( stderr, "renderOrder: [%s]\n", renderOrder.c_str() );//
	fprintf( stderr, "width: [%ld]\n", width );//
	fprintf( stderr, "height: [%ld]\n", height );//
	fprintf( stderr, "tileWidth: [%ld]\n", tileWidth );//
	fprintf( stderr, "tileHeight: [%ld]\n", tileHeight );//
	fprintf( stderr, "nextObjectId: [%ld]\n", nextObjectId );//

	for( long i = 0; i < tileSetsNum; i++ ){
		fprintf( stderr, "\n" );//
		fprintf( stderr, "i/n: [%ld]/[%ld]\n",
				i, tileSetsNum );//
		fprintf( stderr, "name: [%s]\n",
				tileSets[i]->name.c_str() );//
		fprintf( stderr, "image: [%s]\n",
				tileSets[i]->image.c_str() );//
		fprintf( stderr, "imageWidth: [%ld]\n",
				tileSets[i]->imageWidth );//
		fprintf( stderr, "imageHeight: [%ld]\n",
				tileSets[i]->imageHeight );//
		fprintf( stderr, "tileWidth: [%ld]\n",
				tileSets[i]->tileWidth );//
		fprintf( stderr, "tileHeight: [%ld]\n",
				tileSets[i]->tileHeight );//
		fprintf( stderr, "margin: [%ld]\n",
				tileSets[i]->margin );//
		fprintf( stderr, "spacing: [%ld]\n",
				tileSets[i]->spacing );//
		fprintf( stderr, "firstGId: [%ld]\n",
				tileSets[i]->firstGId );//
	}
#endif
}
