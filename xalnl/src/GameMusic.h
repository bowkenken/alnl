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
* $Id: GameMusic.h,v 1.18 2014/01/07 23:44:46 bowkenken Exp $
***************************************************************/

#ifndef GAME_MUSIC_H
#define GAME_MUSIC_H	1

////////////////////////////////////////////////////////////////
// BGM の管理
////////////////////////////////////////////////////////////////

#include <vector>

#ifdef HAVE_SDL2_SDL_H
# include <SDL2/SDL.h>
#endif // HAVE_SDL2_SDL_H

#ifdef HAVE_SDL2_SDL_MIXER_H
# include <SDL2/SDL_mixer.h>
#endif // HAVE_SDL2_SDL_MIXER_H

#include "town.h"
#include "music-kind.h"

#include "GameMisc.h"

////////////////////////////////////////////////////////////////

// BGM データ・ディレクトリ
#define STR_DEFAULT_MUSIC_DIR_NAME	"xalnl-" VERSION "/"
// BGM のファイル名の拡張子
#define	STR_MUSIC_FILE_EXT	"ogg mp3"

#define	LS_MUSIC_DUN_MAX_N	10
#define	LS_MUSIC_BATTLE_MAX_N	LS_MUSIC_DUN_MAX_N

////////////////////////////////////////////////////////////////

// BGM のデータ
class MusicData {
public:
	std::vector<std::string> name;

private:

public:
	MusicData(){
	};
	MusicData( const char *dir ){
		init( dir );
	};
	~MusicData(){
	};

	void init( const char *dir );

private:
};

// BGM のデータのリスト
typedef std::vector<MusicData *> LsMusicData;

////////////////////////////////////////////////////////////////

class GameMusic {
public:
private:
#ifdef	HAVE_SDL2_SDL_MIXER_H
	Mix_Music *music;
#endif

	int audioRate;
	unsigned short audioFormat;
	int audioChannels;
	int audioBuffers;

	music_kind_t currentKind;
	music_kind_t prevKind;
	long currentIdx;
	long prevIdx;
	std::string currentName;

	MusicData musicTitle;
	MusicData musicGameOver;
	MusicData musicEnding;
	MusicData musicTheEnd;
	MusicData musicTown;
	LsMusicData lsMusicShop;
	LsMusicData lsMusicDun;
	MusicData musicLastBoss;
	LsMusicData lsMusicBattle;
	MusicData musicBattleBoss;
	MusicData musicBattleLastBoss;
	LsMusicData lsMusicEffect;

public:
	GameMusic();
	~GameMusic();
	void init();
	void close();

	void setVolume( rate_t rate );

	void playScene();
	void playLastScene();
	void play( music_kind_t kind, long idx = -1 );
	void replayPrev();
	void replay();
	std::string playTitle( long idx );
	std::string playGameOver( long idx );
	std::string playEnding( long idx );
	std::string playTheEnd( long idx );
	std::string playTown( long idx );
	std::string playShop( long idx );
	std::string playDun( long idx );
	std::string playLastBoss( long idx );
	std::string playBattle( long idx );
	std::string playBattleBoss( long idx );
	std::string playBattleLastBoss( long idx );
	std::string playEffect( long idx );

private:
	void setCurrent( music_kind_t kind, long idx );
	std::string playRandm(
		MusicData *p, long nRepeat = -1,
		void (*func)() = NULL );
};

#endif /* GAME_MUSIC_H */
