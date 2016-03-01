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

using namespace v8;

////////////////////////////////////////////////////////////////

const char *STR_CG_FILE_EXT = ".cg.json";

////////////////////////////////////////////////////////////////
// コンストラクタ
////////////////////////////////////////////////////////////////

PcgCharGraph::PcgCharGraph()
{
	graphPath = "";
	charPath = "";

	cgJson = "{}";

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
// CG ファイルのパス名を設定
// WSCstring path : 元タイルのパス名
////////////////////////////////////////////////////////////////

void PcgCharGraph::setPath( WSCstring path )
{
	graphPath = path;
	charPath = path;

	if( path != "" )
		charPath += STR_CG_FILE_EXT;
}

////////////////////////////////////////////////////////////////
// CG ファイルの内容を設定
// WSCstring path : CG ファイルの内容
////////////////////////////////////////////////////////////////

void PcgCharGraph::setCgJsonData( WSCstring jsonData )
{
	cgJson = jsonData;
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getGraphPath(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	WSCstring value;
	value = (static_cast<PcgCharGraph *>(ptr))->graphPath;

	return String::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setGraphPath(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	String::Utf8Value str( value );
	(static_cast<PcgCharGraph *>(ptr))->graphPath
			= *str;
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getCharPath(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	WSCstring value;
	value = (static_cast<PcgCharGraph *>(ptr))->charPath;

	return String::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setCharPath(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	String::Utf8Value str( value );
	(static_cast<PcgCharGraph *>(ptr))->charPath
			= *str;
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getCgJson(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	WSCstring value;
	value = (static_cast<PcgCharGraph *>(ptr))->cgJson;

	return String::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setCgJson(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	String::Utf8Value str( value );
	(static_cast<PcgCharGraph *>(ptr))->cgJson
			= *str;
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getVersionMajor(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->versionMajor;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setVersionMajor(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setVersionMajor(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->versionMajor
			= value->Int32Value();

	fprintf( stderr, "value: [%ld]\n", (long)(value->Int32Value()) );//
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getVersionMinor(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->versionMinor;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setVersionMinor(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setVersionMinor(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->versionMinor
			= value->Int32Value();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getVersionPatch(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->versionPatch;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setVersionPatch(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setVersionPatch(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->versionPatch
			= value->Int32Value();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getCharWidth(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->charWidth;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setCharWidth(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setCharWidth(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->charWidth
			= value->Int32Value();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getCharHeight(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->charHeight;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setCharHeight(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setCharHeight(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->charHeight
			= value->Int32Value();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getWidth(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->width;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setWidth(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setWidth(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->width
			= value->Int32Value();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getHeight(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->height;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setHeight(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setHeight(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->height
			= value->Int32Value();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getRulerColumnLineHead(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->rulerColumnLineHead;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setRulerColumnLineHead(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setRulerColumnLineHead(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->rulerColumnLineHead
			= value->Int32Value();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getRulerColumnLineTail(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->rulerColumnLineTail;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setRulerColumnLineTail(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setRulerColumnLineTail(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->rulerColumnLineTail
			= value->Int32Value();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getRulerRowCharHead(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->rulerRowCharHead;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setRulerRowCharHead(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setRulerRowCharHead(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->rulerRowCharHead
			= value->Int32Value();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getRulerRowCharTail(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	long value;
	value = (static_cast<PcgCharGraph *>(ptr))->rulerRowCharTail;

	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setRulerRowCharTail(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setRulerRowCharTail(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	(static_cast<PcgCharGraph *>(ptr))->rulerRowCharTail
			= value->Int32Value();
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getBackSlashChar(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	char value[2];
	value[0] = (static_cast<PcgCharGraph *>(ptr))->backSlashChar;
	value[1] = '\0';

	return String::New( value );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setBackSlashChar(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setBackSlashChar(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	String::Utf8Value str( value );
	(static_cast<PcgCharGraph *>(ptr))->backSlashChar
			= (*str)[0];
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getTile(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	std::string value;
	value = (static_cast<PcgCharGraph *>(ptr))->tile;

	return String::New( value.c_str() );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setTile(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setTile(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	String::Utf8Value str( value );
	(static_cast<PcgCharGraph *>(ptr))->tile
			= *str;
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getColor(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	std::string value;
	value = (static_cast<PcgCharGraph *>(ptr))->color;

	return String::New( value.c_str() );
}

////////////////////////////////////////////////////////////////
// タイル・ファイルのパスのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setColor(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	fprintf( stderr, "setColor(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	String::Utf8Value str( value );
	(static_cast<PcgCharGraph *>(ptr))->color
			= *str;
}

////////////////////////////////////////////////////////////////
// キャラグラのパース
// WSCstring scriptString : キャラグラのパース用スクリプト
////////////////////////////////////////////////////////////////

void PcgCharGraph::parse( WSCstring scriptString )
{
	HandleScope aHandleScope;

	Handle<ObjectTemplate> aGlobal = ObjectTemplate::New();
	//@@@ aGlobal->Set( String::New( "foo" ),
	//@@@		FunctionTemplate::New( foo_bar ) );

	Persistent<Context> aContext = Context::New( NULL, aGlobal );
	Context::Scope aContextScope( aContext );

	Handle<ObjectTemplate> aTemplate = ObjectTemplate::New();
	aTemplate->SetInternalFieldCount( 1 );
	aTemplate->SetAccessor( String::New( "graphPath" ),
			getGraphPath, setGraphPath );
	aTemplate->SetAccessor( String::New( "charPath" ),
			getCharPath, setCharPath );
	aTemplate->SetAccessor( String::New( "cgJson" ),
			getCgJson, setCgJson );
	aTemplate->SetAccessor( String::New( "versionMajor" ),
			getVersionMajor, setVersionMajor );
	aTemplate->SetAccessor( String::New( "versionMinor" ),
			getVersionMinor, setVersionMinor );
	aTemplate->SetAccessor( String::New( "versionPatch" ),
			getVersionPatch, setVersionPatch );
	aTemplate->SetAccessor( String::New( "charWidth" ),
			getCharWidth, setCharWidth );
	aTemplate->SetAccessor( String::New( "charHeight" ),
			getCharHeight, setCharHeight );
	aTemplate->SetAccessor( String::New( "width" ),
			getWidth, setWidth );
	aTemplate->SetAccessor( String::New( "height" ),
			getHeight, setHeight );
	aTemplate->SetAccessor( String::New( "rulerColumnLineHead" ),
			getRulerColumnLineHead, setRulerColumnLineHead );
	aTemplate->SetAccessor( String::New( "rulerColumnLineTail" ),
			getRulerColumnLineTail, setRulerColumnLineTail );
	aTemplate->SetAccessor( String::New( "rulerRowCharHead" ),
			getRulerRowCharHead, setRulerRowCharHead );
	aTemplate->SetAccessor( String::New( "rulerColumnLineTail" ),
			getRulerColumnLineTail, setRulerColumnLineTail );
	aTemplate->SetAccessor( String::New( "backSlashChar" ),
			getBackSlashChar, setBackSlashChar );
	aTemplate->SetAccessor( String::New( "tile" ),
			getTile, setTile );
	aTemplate->SetAccessor( String::New( "color" ),
			getColor, setColor );

	Local<Object> aObject = aTemplate->NewInstance();
	aObject->SetInternalField( 0, External::New( this ) );
	aContext->Global()->Set( String::New( "gPcgCharGraph" ), aObject );

	Handle<String> aSource = String::New( scriptString.c_str() );
	Handle<Script> aScript = Script::Compile( aSource );
	// Handle<Value> aResult = aScript->Run();
	aScript->Run();
	aContext.Dispose();

	// fprintf( stderr, "script:\n" );
	// fprintf( stderr, "----begin----\n" );
	// fprintf( stderr, "%s", scriptString.c_str() );
	// fprintf( stderr, "----end----\n" );

	fprintf( stderr, "graphPath: [%s]\n", graphPath.c_str() );
	fprintf( stderr, "charPath: [%s]\n", charPath.c_str() );
	fprintf( stderr, "versionMajor: [%ld]\n", versionMajor );
	fprintf( stderr, "versionMinor: [%ld]\n", versionMinor );
	fprintf( stderr, "versionPatch: [%ld]\n", versionPatch );
	fprintf( stderr, "charWidth: [%ld]\n", charWidth );
	fprintf( stderr, "charHeight: [%ld]\n", charHeight );
	fprintf( stderr, "width: [%ld]\n", width );
	fprintf( stderr, "height: [%ld]\n", height );
	fprintf( stderr, "rulerColumnLineHead: [%ld]\n", rulerColumnLineHead );
	fprintf( stderr, "rulerColumnLineTail: [%ld]\n", rulerColumnLineTail );
	fprintf( stderr, "rulerRowCharHead: [%ld]\n", rulerRowCharHead );
	fprintf( stderr, "rulerRowCharTail: [%ld]\n", rulerRowCharTail );
	fprintf( stderr, "backSlashChar: [%c]\n", backSlashChar );

	const char *str = tile.c_str();
	long w = width * charWidth + rulerRowCharHead + rulerRowCharTail;
	fprintf( stderr, "tile: [" );
	for( long i = 0; str[i] != '\0'; i++ ){
		if( (i % w) == 0 )
			fprintf( stderr, "\n" );

		fprintf( stderr, "%c", str[i] );
	}
	fprintf( stderr, "\n]\n" );

	fprintf( stderr, "color: [%s]\n", color.c_str() );
}

