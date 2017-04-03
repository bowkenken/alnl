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
* $Id: GameMusic.cpp,v 1.34 2014/01/07 23:55:39 bowkenken Exp $
***************************************************************/

////////////////////////////////////////////////////////////////
// BGM の管理
////////////////////////////////////////////////////////////////

#define GAME_MUSIC_CPP	1
#include "inc.h"

#ifdef D_MFC
# pragma comment( lib, "SDL_mixer.lib" )
#endif

////////////////////////////////////////////////////////////////

static void donePlayEnding();
static void donePlayEffect();

////////////////////////////////////////////////////////////////
// BGM リストの初期化
// const char *dir : BGM ディレクトリ
////////////////////////////////////////////////////////////////

void MusicData::init( const char *dir )
{
	// BGMの検索を設定

	FileList::setStrDirSelMusic( STR_DEFAULT_MUSIC_DIR_NAME );
	FileList fls;

	//

	fls.reset( dir, STR_MUSIC_FILE_EXT );
	for( long n = 0; n < LOOP_MAX_100; n++ ){
		std::string path = fls.next();
		if( path.length() <= 0 )
			break;

		name.push_back( path );
	}
}

////////////////////////////////////////////////////////////////
// コンストラクタ
////////////////////////////////////////////////////////////////

GameMusic::GameMusic()
{
#if	defined( HAVE_SDL2_SDL_MIXER_H ) || defined( HAVE_SDL_MIXER_H )
	music = NULL;
#endif

#if	defined( HAVE_SDL2_SDL_MIXER_H ) || defined( HAVE_SDL_MIXER_H )
	audioRate = 22050;
	audioFormat = AUDIO_S16;
	audioChannels = 2;
	audioBuffers = 1024;
#else
	audioRate = 22050;
	audioFormat = 0;
	audioChannels = 2;
	audioBuffers = 1024;
#endif

	currentKind = MUSIC_KIND_NULL;
	currentIdx = 0;
	currentName = "";
	prevKind = MUSIC_KIND_NULL;
	prevIdx = 0;
}

////////////////////////////////////////////////////////////////
// デストラクタ
////////////////////////////////////////////////////////////////

GameMusic::~GameMusic()
{
	this->close();
}

////////////////////////////////////////////////////////////////
// 初期化
////////////////////////////////////////////////////////////////

void GameMusic::init()
{
	audioBuffers = (int)g_audio_buf_siz;

#if	defined( HAVE_SDL2_SDL_MIXER_H ) || defined( HAVE_SDL_MIXER_H )
	if( Mix_OpenAudio( audioRate, audioFormat, audioChannels,
			audioBuffers ) ){
		return;
	}
	Mix_QuerySpec( &audioRate, &audioFormat, &audioChannels );
#endif

	// title

	musicTitle.init( "title/" );

	// game over

	musicGameOver.init( "game_over/" );

	// ending

	musicEnding.init( "ending/" );
	musicTheEnd.init( "ending/the_end/" );

	// town

	musicTown.init( "town/main/" );

	// shop

	lsMusicShop.resize( SHOP_N_MAX_N );

	lsMusicShop[SHOP_N_NULL] = new MusicData( "town/main/" );
	lsMusicShop[SHOP_N_BAR] = new MusicData( "town/bar/" );
	lsMusicShop[SHOP_N_INN] = new MusicData( "town/inn/" );
	lsMusicShop[SHOP_N_WPN] = new MusicData( "town/weapon/" );
	lsMusicShop[SHOP_N_ARMOR] = new MusicData( "town/armor/" );
	lsMusicShop[SHOP_N_MAGIC] = new MusicData( "town/magic/" );
	lsMusicShop[SHOP_N_TEMPLE] = new MusicData( "town/temple/" );
	lsMusicShop[SHOP_N_ALCHEMY] = new MusicData( "town/alchemy/" );
	lsMusicShop[SHOP_N_MUSIC] = new MusicData( "town/music/" );
	lsMusicShop[SHOP_N_GROCERY] = new MusicData( "town/grocery/" );
	lsMusicShop[SHOP_N_RESTAURANT] = new MusicData( "town/restaurant/" );
	lsMusicShop[SHOP_N_TEAROOM] = new MusicData( "town/tearoom/" );
	lsMusicShop[SHOP_N_TOBACCO] = new MusicData( "town/tobacco/" );
	lsMusicShop[SHOP_N_PET_SHOP] = new MusicData( "town/pet_shop/" );

	// dungeon

	for( long i = 0; i < LS_MUSIC_DUN_MAX_N; i++ ){
		char dir[127 + 1];
		sn_printf( dir, 127, "dungeon/stage%02ld/",
				(long)(i + 1) );

		lsMusicDun.push_back( new MusicData( dir ) );
	}

	// battle

	for( long i = 0; i < LS_MUSIC_BATTLE_MAX_N; i++ ){
		char dir[127 + 1];
		sn_printf( dir, 127, "battle/stage%02ld/",
				(long)(i + 1) );

		lsMusicBattle.push_back( new MusicData( dir ) );
	}

	musicBattleBoss.init( "battle/boss/" );

	// last boss

	musicLastBoss.init( "dungeon/last" );
	musicBattleLastBoss.init( "battle/boss/last" );

	// ME

	lsMusicEffect.resize( ME_KIND_MAX_N );

	lsMusicEffect[ME_KIND_INN] = new MusicData( "effect/inn/" );
	lsMusicEffect[ME_KIND_TEMPLE] = new MusicData( "effect/temple/" );

	// 音量

	setVolume( get_music_volume_rate() );
}

////////////////////////////////////////////////////////////////
// BGM 処理を終了する
////////////////////////////////////////////////////////////////

void GameMusic::close()
{
#if	defined( HAVE_SDL2_SDL_MIXER_H ) || defined( HAVE_SDL_MIXER_H )
	if( music != NULL ){
		Mix_HaltMusic();
		Mix_FreeMusic( music );
		music = NULL;
	}
#endif
}

////////////////////////////////////////////////////////////////
// BGM の音量を設定
////////////////////////////////////////////////////////////////

void GameMusic::setVolume( rate_t rate )
{
#if	defined( HAVE_SDL2_SDL_MIXER_H ) || defined( HAVE_SDL_MIXER_H )
	Mix_VolumeMusic( MIX_MAX_VOLUME * rate / _100_PERCENT );
#endif
}

////////////////////////////////////////////////////////////////
// シーンに合せた BGM の再生
////////////////////////////////////////////////////////////////

void GameMusic::playScene()
{
	switch( get_scene() ){
	case SCENE_N_NULL:
		break;
	case SCENE_N_INIT:
		break;
	case SCENE_N_TITLE:
		play( MUSIC_KIND_TITLE );
		break;
	case SCENE_N_OPENING:
		break;
	case SCENE_N_TOWN:
		play( MUSIC_KIND_TOWN );
		break;
	case SCENE_N_SHOP:
		play( MUSIC_KIND_SHOP );
		break;
	case SCENE_N_DUN:
		play( MUSIC_KIND_DUN );
		break;
	case SCENE_N_BATTLE:
		play( MUSIC_KIND_BATTLE );
		break;
	case SCENE_N_BATTLE_BOSS:
		play( MUSIC_KIND_BATTLE_BOSS );
		break;
	case SCENE_N_LAST_BOSS:
		playLastScene();
		break;
	case SCENE_N_GAME_OVER:
		break;
	case SCENE_N_GAME_OVER_WAIT:
		break;
	case SCENE_N_GAME_OVER_END:
		play( MUSIC_KIND_GAME_OVER );
		break;
	case SCENE_N_ENDING:
		break;
	case SCENE_N_ENDING_EPILOGUE:
		play( MUSIC_KIND_ENDING );
		break;
	case SCENE_N_ENDING_SPACE:
		break;
	case SCENE_N_ENDING_STAFF_ROLL:
		break;
	case SCENE_N_ENDING_END:
		break;
	case SCENE_N_SEL_MBR_GRAPH:
		break;
	case SCENE_N_MAX_N:
		break;
	}
}

////////////////////////////////////////////////////////////////
// ラスボスのシーンに合せた BGM の再生
////////////////////////////////////////////////////////////////

void GameMusic::playLastScene()
{
	switch( get_last_scene() ){
	case LAST_SCENE_N_NULL:
		break;
	case LAST_SCENE_N_ENTER:
		play( MUSIC_KIND_LAST_BOSS );
		break;
	case LAST_SCENE_N_ENCOUNTER:
	case LAST_SCENE_N_ENCOUNTER_CUT_IN:
	case LAST_SCENE_N_ENCOUNTER_WORDS:
	case LAST_SCENE_N_ENCOUNTER_CUT_OUT:
	case LAST_SCENE_N_ENCOUNTER_CUT_END:
	case LAST_SCENE_N_EXEL:
	case LAST_SCENE_N_EXEL_ENTER:
	case LAST_SCENE_N_EXEL_CUT_IN:
	case LAST_SCENE_N_EXEL_WORDS:
	case LAST_SCENE_N_EXEL_CUT_OUT:
	case LAST_SCENE_N_EXEL_CUT_END:
	case LAST_SCENE_N_EXEL_HYPER:
		break;
	case LAST_SCENE_N_EXEL_BATTLE:
		play( MUSIC_KIND_BATTLE_BOSS );
		break;
	case LAST_SCENE_N_EXEL_DIE:
		play( MUSIC_KIND_LAST_BOSS );
		break;
	case LAST_SCENE_N_EXELER:
	case LAST_SCENE_N_EXELER_CUT_IN:
	case LAST_SCENE_N_EXELER_WORDS:
	case LAST_SCENE_N_EXELER_CUT_OUT:
	case LAST_SCENE_N_EXELER_CUT_END:
	case LAST_SCENE_N_EXELER_ENTER:
	case LAST_SCENE_N_EXELER_HYPER:
		break;
	case LAST_SCENE_N_EXELER_BATTLE:
		play( MUSIC_KIND_BATTLE_BOSS );
		break;
	case LAST_SCENE_N_EXELER_DIE:
		play( MUSIC_KIND_LAST_BOSS );
		break;
	case LAST_SCENE_N_XEX:
	case LAST_SCENE_N_XEX_CUT_IN:
	case LAST_SCENE_N_XEX_WORDS:
	case LAST_SCENE_N_XEX_CUT_OUT:
	case LAST_SCENE_N_XEX_CUT_END:
		break;
	case LAST_SCENE_N_XX_ENTER:
	case LAST_SCENE_N_XX_WORDS:
		break;
	case LAST_SCENE_N_XX_BATTLE:
		play( MUSIC_KIND_BATTLE_LAST_BOSS );
	case LAST_SCENE_N_XX_DIE:
		break;
	case LAST_SCENE_N_END:
	case LAST_SCENE_N_MAX_N:
		break;
	}
}

////////////////////////////////////////////////////////////////
// BGM の再生
// music_kind_t kind : BGM の種類
// long idx : BGM リストのインデックス
////////////////////////////////////////////////////////////////

void GameMusic::play( music_kind_t kind, long idx )
{
	switch( kind ){
	case MUSIC_KIND_NULL:
		break;
	case MUSIC_KIND_TITLE:
		playTitle( idx );
		break;
	case MUSIC_KIND_GAME_OVER:
		playGameOver( idx );
		break;
	case MUSIC_KIND_ENDING:
		playEnding( idx );
		break;
	case MUSIC_KIND_THE_END:
		playTheEnd( idx );
		break;
	case MUSIC_KIND_TOWN:
		playTown( idx );
		break;
	case MUSIC_KIND_SHOP:
		playShop( idx );
		break;
	case MUSIC_KIND_DUN:
		playDun( idx );
		break;
	case MUSIC_KIND_LAST_BOSS:
		playLastBoss( idx );
		break;
	case MUSIC_KIND_BATTLE:
		playBattle( idx );
		break;
	case MUSIC_KIND_BATTLE_BOSS:
		playBattleBoss( idx );
		break;
	case MUSIC_KIND_BATTLE_LAST_BOSS:
		playBattleLastBoss( idx );
		break;
	case MUSIC_KIND_EFFECT:
		playEffect( idx );
		break;
	case MUSIC_KIND_MAX_N:
		break;
	}
}

////////////////////////////////////////////////////////////////
// 1 つ前の曲を再演奏
////////////////////////////////////////////////////////////////

void GameMusic::replayPrev()
{
	play( prevKind, prevIdx );
}

////////////////////////////////////////////////////////////////
// 現在の曲を再演奏
////////////////////////////////////////////////////////////////

void GameMusic::replay()
{
	music_kind_t kind = currentKind;
	long idx = currentIdx;

	currentKind = MUSIC_KIND_NULL;
	currentIdx = 0;

	currentName = "";

	play( kind, idx );
}

////////////////////////////////////////////////////////////////
// タイトル画面の BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playTitle( long idx )
{
	setCurrent( MUSIC_KIND_TITLE, idx );

	return playRandm( &musicTitle );
}

////////////////////////////////////////////////////////////////
// タイトル画面の BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playGameOver( long idx )
{
	setCurrent( MUSIC_KIND_GAME_OVER, idx );

	return playRandm( &musicGameOver );
}

////////////////////////////////////////////////////////////////
// エンディングの BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playEnding( long idx )
{
	setCurrent( MUSIC_KIND_ENDING, idx );

	return playRandm( &musicEnding, 1, donePlayEnding );
}

////////////////////////////////////////////////////////////////
// エンディングの最後の BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playTheEnd( long idx )
{
	setCurrent( MUSIC_KIND_THE_END, idx );

	return playRandm( &musicTheEnd );
}

////////////////////////////////////////////////////////////////
// 街の BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playTown( long idx )
{
	setCurrent( MUSIC_KIND_TOWN, idx );

	return playRandm( &musicTown );
}

////////////////////////////////////////////////////////////////
// 店の BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playShop( long idx )
{
	if( idx >= SHOP_N_MAX_N )
		return "";

	setCurrent( MUSIC_KIND_SHOP, idx );

	if( idx <= -1 )
		idx = get_cur_shop_n();

	return playRandm( lsMusicShop[idx] );
}

////////////////////////////////////////////////////////////////
// 迷宮の BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playDun( long idx )
{
	setCurrent( MUSIC_KIND_DUN, idx );

	if( idx <= -1 ){
		dun_t *dun = get_dun();
		if( dun == NULL )
			idx = -1;
		else
			idx = dun->lev;
	}

	idx = labs( idx );
	if( idx > 0 )
		idx--;

	idx /= DUN_LEV_BOSS;
	idx %= LS_MUSIC_DUN_MAX_N;

	return playRandm( lsMusicDun[idx] );
}

////////////////////////////////////////////////////////////////
// ラスボスの BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playLastBoss( long idx )
{
	setCurrent( MUSIC_KIND_LAST_BOSS, idx );

	return playRandm( &musicLastBoss );
}

////////////////////////////////////////////////////////////////
// 戦闘の BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playBattle( long idx )
{
	setCurrent( MUSIC_KIND_BATTLE, idx );

	if( idx <= -1 ){
		dun_t *dun = get_dun();
		if( dun == NULL )
			idx = 0;
		else
			idx = dun->lev;
	}

	idx = labs( idx );
	if( idx > 0 )
		idx--;

	idx /= DUN_LEV_BOSS;
	idx %= LS_MUSIC_DUN_MAX_N;

	return playRandm( lsMusicBattle[idx] );
}

////////////////////////////////////////////////////////////////
// ボス戦の BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playBattleBoss( long idx )
{
	setCurrent( MUSIC_KIND_BATTLE_BOSS, idx );

	return playRandm( &musicBattleBoss );
}

////////////////////////////////////////////////////////////////
// ラスボス戦の BGM の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playBattleLastBoss( long idx )
{
	setCurrent( MUSIC_KIND_BATTLE_LAST_BOSS, idx );

	return playRandm( &musicBattleLastBoss );
}

////////////////////////////////////////////////////////////////
// ME の再生
// long idx : BGM リストのインデックス
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playEffect( long idx )
{
	if( idx <= ME_KIND_NULL )
		return "";
	if( idx >= ME_KIND_MAX_N )
		return "";

	setCurrent( MUSIC_KIND_EFFECT, idx );

	if( idx <= -1 ){
		idx = ME_KIND_TEMPLE;
	}

	return playRandm( lsMusicEffect[idx], 1, donePlayEffect );
}

////////////////////////////////////////////////////////////////
// 現在の BGM を設定
// music_kind_t kind : BGM の種類
// long idx : BGM リストのインデックス
////////////////////////////////////////////////////////////////

void GameMusic::setCurrent( music_kind_t kind, long idx )
{
	if( (currentKind != kind) || (currentIdx != idx) ){
		if( currentKind != MUSIC_KIND_EFFECT ){
			prevKind = currentKind;
			prevIdx = currentIdx;
		}
	}

	currentKind = kind;
	currentIdx = idx;
}

////////////////////////////////////////////////////////////////
// リストからランダムに選んで BGM を再生
// MusicData *p : BGM のリスト
// long nRepeat : 再生回数
// void (*func)() : 終了時のコールバック
// return : BGM ファイルのパス
////////////////////////////////////////////////////////////////

std::string GameMusic::playRandm(
	MusicData *p, long nRepeat, void (*func)() )
{
	if( p == NULL )
		return "";

	long size = (long)(p->name.size());
	if( size <= 0 )
		return "";

	long idx = gui_randm( size );
	// fprintf( stderr, "playRandm: idx[%ld]/size[%ld]\n", idx, size );
	std::string name = p->name[idx];

	if( name == "" )
		return name;
	if( name == currentName )
		return name;
	currentName = name;

	if( nRepeat > 0 )
		nRepeat--;
	else
		nRepeat = -1;

#if	defined( HAVE_SDL2_SDL_MIXER_H ) || defined( HAVE_SDL_MIXER_H )
	Mix_HaltMusic();

	music = Mix_LoadMUS( name.c_str() );
	Mix_PlayMusic( music, nRepeat );

	if( func != NULL )
		Mix_HookMusicFinished( func );
#endif

	return name;
}

////////////////////////////////////////////////////////////////
// エンディングの 1 曲目の BGM の終了時の処理
////////////////////////////////////////////////////////////////

void donePlayEnding()
{
	change_scene_gui( SCENE_N_ENDING_STAFF_ROLL );
	gMusic.playTheEnd( 0 );
}

////////////////////////////////////////////////////////////////
// ME (Music Effect) の終了時の処理
////////////////////////////////////////////////////////////////

void donePlayEffect()
{
	gMusic.replayPrev();
}
