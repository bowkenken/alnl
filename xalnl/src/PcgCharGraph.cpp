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
	init();
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
	backSlashChar = "";

	row = 0;
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

	init();
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
// CG の文字列のゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getPcgCharGraphWSCstring(
	Local<String> property, const AccessorInfo &info
)
{
	// fprintf( stderr, "getPcgCharGraphWSCstring(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgCharGraph *ptr = static_cast<PcgCharGraph *>(wrap->Value());
	WSCstring value = "";

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	if( name == "graphPath" )
		value = ptr->graphPath;
	else if( name == "charPath" )
		value = ptr->charPath;
	else if( name == "cgJson" )
		value = ptr->cgJson;
	else if( name == "backSlashChar" )
		value = ptr->backSlashChar;
	// fprintf( stderr, "value: [%s]\n", value.c_str() );//

	// fprintf( stderr, "getPcgCharGraphWSCstring(): end\n" );//
	return String::New( value );
}

////////////////////////////////////////////////////////////////
// CG の文字列のセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setPcgCharGraphWSCstring(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	// fprintf( stderr, "setPcgCharGraphWSCstring(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgCharGraph *ptr = static_cast<PcgCharGraph *>(wrap->Value());
	String::Utf8Value str( value );

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	if( name == "graphPath" )
		ptr->graphPath = *str;
	else if( name == "charPath" )
		ptr->charPath = *str;
	else if( name == "cgJson" )
		ptr->cgJson = *str;
	else if( name == "backSlashChar" )
		ptr->backSlashChar = *str;
	// fprintf( stderr, "value: [%s]\n", str->c_str() );//

	// fprintf( stderr, "setPcgCharGraphWSCstring(): end\n" );//
}

////////////////////////////////////////////////////////////////
// CG の数値のゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getPcgCharGraphLong(
	Local<String> property, const AccessorInfo &info
)
{
	// fprintf( stderr, "getPcgCharGraphLong(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgCharGraph *ptr = static_cast<PcgCharGraph *>(wrap->Value());
	long value = 0;

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	if( name == "versionMajor" )
		value = ptr->versionMajor;
	else if( name == "versionMinor" )
		value = ptr->versionMinor;
	else if( name == "versionPatch" )
		value = ptr->versionPatch;
	else if( name == "charWidth" )
		value = ptr->charWidth;
	else if( name == "charHeight" )
		value = ptr->charHeight;
	else if( name == "width" )
		value = ptr->width;
	else if( name == "height" )
		value = ptr->height;
	else if( name == "rulerColumnLineHead" )
		value = ptr->rulerColumnLineHead;
	else if( name == "rulerColumnLineTail" )
		value = ptr->rulerColumnLineTail;
	else if( name == "rulerRowCharHead" )
		value = ptr->rulerRowCharHead;
	else if( name == "rulerColumnLineTail" )
		value = ptr->rulerColumnLineTail;
	else if( name == "row" )
		value = ptr->row;
	// fprintf( stderr, "value: [%ld]\n", value );//

	// fprintf( stderr, "getPcgCharGraphLong(): end\n" );//
	return Integer::New( value );
}

////////////////////////////////////////////////////////////////
// CG の数値のセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setPcgCharGraphLong(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	// fprintf( stderr, "setPcgCharGraphLong(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	PcgCharGraph *ptr = static_cast<PcgCharGraph *>(wrap->Value());
	long n = value->Int32Value();

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	if( name == "versionMajor" )
		ptr->versionMajor = n;
	else if( name == "versionMinor" )
		ptr->versionMinor = n;
	else if( name == "versionPatch" )
		ptr->versionPatch = n;
	else if( name == "charWidth" )
		ptr->charWidth = n;
	else if( name == "charHeight" )
		ptr->charHeight = n;
	else if( name == "width" )
		ptr->width = n;
	else if( name == "height" )
		ptr->height = n;
	else if( name == "rulerColumnLineHead" )
		ptr->rulerColumnLineHead = n;
	else if( name == "rulerColumnLineTail" )
		ptr->rulerColumnLineTail = n;
	else if( name == "rulerRowCharHead" )
		ptr->rulerRowCharHead = n;
	else if( name == "rulerColumnLineTail" )
		ptr->rulerColumnLineTail = n;
	else if( name == "row" )
		ptr->row = n;
	// fprintf( stderr, "value: [%ld]\n", n );//

	// fprintf( stderr, "setPcgCharGraphLong(): end\n" );//
}

////////////////////////////////////////////////////////////////
// CG のタイルのゲッター
// Local<String> property : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

Handle<Value> getPcgCharGraphTile(
	Local<String> property, const AccessorInfo &info
)
{
	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	PcgCharGraph *cgPtr = static_cast<PcgCharGraph *>(ptr);
	std::string value;

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	if( name == "tile" ){
		value = cgPtr->tile[cgPtr->row];
	} else if( name == "color" ){
		value = cgPtr->color[cgPtr->row];
	}

	return String::New( value.c_str() );
}

////////////////////////////////////////////////////////////////
// CG のタイルのセッター
// Local<String> property :
// Local<Value> value : 
// const AccessorInfo &info : 
////////////////////////////////////////////////////////////////

void setPcgCharGraphTile(
	Local<String> property, Local<Value> value,
	const AccessorInfo &info
)
{
	// fprintf( stderr, "setTile(): begin\n" );//

	Local<Object> self = info.Holder();
	Local<External> wrap;
	wrap = Local<External>::Cast( self->GetInternalField( 0 ) );

	void *ptr = wrap->Value();
	PcgCharGraph *cgPtr = static_cast<PcgCharGraph *>(ptr);
	// fprintf( stderr, "setTile(): cgPtr: %p\n", cgPtr );//
	String::Utf8Value str( value );
	// fprintf( stderr, "setTile(): Utf8Value OK\n" );//
	std::string s = *str;
	// fprintf( stderr, "setTile(): std::string OK\n" );//
	// fprintf( stderr, "setTile(): cgPtr->row[%ld]\n", cgPtr->row );//
	// fprintf( stderr, "setTile(): s.c_str()[%s]\n", s.c_str() );//

	String::Utf8Value sTmp( property );
	std::string name = static_cast<std::string>(*sTmp);
	// fprintf( stderr, "name: [%s]\n", name.c_str() );//

	if( name == "tile" ){
		for( long i = cgPtr->tile.size(); i <= cgPtr->row; i++ )
			cgPtr->tile.push_back( "" );

		cgPtr->tile[cgPtr->row] = WSCstring(s.c_str());
	} else if( name == "color" ){
		for( long i = cgPtr->color.size(); i <= cgPtr->row; i++ )
			cgPtr->color.push_back( "" );

		cgPtr->color[cgPtr->row] = WSCstring(s.c_str());
	}

	// fprintf( stderr, "setTile(): end\n" );//
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
			getPcgCharGraphWSCstring, setPcgCharGraphWSCstring );
	aTemplate->SetAccessor( String::New( "charPath" ),
			getPcgCharGraphWSCstring, setPcgCharGraphWSCstring );
	aTemplate->SetAccessor( String::New( "cgJson" ),
			getPcgCharGraphWSCstring, setPcgCharGraphWSCstring );
	aTemplate->SetAccessor( String::New( "versionMajor" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "versionMinor" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "versionPatch" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "charWidth" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "charHeight" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "width" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "height" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "rulerColumnLineHead" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "rulerColumnLineTail" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "rulerRowCharHead" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "rulerColumnLineTail" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "backSlashChar" ),
			getPcgCharGraphWSCstring, setPcgCharGraphWSCstring );
	aTemplate->SetAccessor( String::New( "row" ),
			getPcgCharGraphLong, setPcgCharGraphLong );
	aTemplate->SetAccessor( String::New( "tile" ),
			getPcgCharGraphTile, setPcgCharGraphTile );
	aTemplate->SetAccessor( String::New( "color" ),
			getPcgCharGraphTile, setPcgCharGraphTile );

	Local<Object> aObject = aTemplate->NewInstance();
	aObject->SetInternalField( 0, External::New( this ) );
	aContext->Global()->Set( String::New( "gPcgCharGraph" ), aObject );

	Handle<String> aSource = String::New( scriptString.c_str() );
	Handle<Script> aScript = Script::Compile( aSource );
	// Handle<Value> aResult = aScript->Run();
	aScript->Run();
	aContext.Dispose();

	// fprintf( stderr, "script:\n" ); //
	// fprintf( stderr, "----begin----\n" ); //
	// fprintf( stderr, "%s", scriptString.c_str() ); //
	// fprintf( stderr, "----end----\n" ); //

	// fprintf( stderr, "\n" ); //
	// fprintf( stderr, "graphPath: [%s]\n", graphPath.c_str() ); //
	// fprintf( stderr, "charPath: [%s]\n", charPath.c_str() ); //
	// fprintf( stderr, "versionMajor: [%ld]\n", versionMajor ); //
	// fprintf( stderr, "versionMinor: [%ld]\n", versionMinor ); //
	// fprintf( stderr, "versionPatch: [%ld]\n", versionPatch ); //
	// fprintf( stderr, "charWidth: [%ld]\n", charWidth ); //
	// fprintf( stderr, "charHeight: [%ld]\n", charHeight ); //
	// fprintf( stderr, "width: [%ld]\n", width ); //
	// fprintf( stderr, "height: [%ld]\n", height ); //
	// fprintf( stderr, "rulerColumnLineHead: [%ld]\n",
	// 		rulerColumnLineHead ); //
	// fprintf( stderr, "rulerColumnLineTail: [%ld]\n",
	// 		rulerColumnLineTail ); //
	// fprintf( stderr, "rulerRowCharHead: [%ld]\n",
	//		rulerRowCharHead ); //
	// fprintf( stderr, "rulerRowCharTail: [%ld]\n",
	//		rulerRowCharTail ); //
	// fprintf( stderr, "backSlashChar: [%s]\n",
	//		backSlashChar.c_str() ); //

#if	0
	fprintf( stderr, "\n" );//

	unsigned long tileMaxRow
			= rulerColumnLineHead + height
			+ rulerColumnLineTail;
	if( tileMaxRow > tile.size() )
		tileMaxRow = tile.size();

	fprintf( stderr, "tile: [\n" ); //
	for( unsigned long i = 0; i < tileMaxRow; i++ ){
		if( !tile[i] )
			break;

		fprintf( stderr, "%s\n", tile[i].c_str() ); //
	}
	fprintf( stderr, "]\n" ); //

	unsigned long colorMaxRow
			= rulerColumnLineHead + height
			+ rulerColumnLineTail;
	if( colorMaxRow > color.size() )
		colorMaxRow = color.size();
	colorMaxRow = 1;//@@@

	fprintf( stderr, "color: [\n" ); //
	for( unsigned long i = 0; i < colorMaxRow; i++ ){
		if( !color[i] )
			break;

		fprintf( stderr, "%s\n", color[i].c_str() ); //
	}
	fprintf( stderr, "]\n" ); //
#endif
}
