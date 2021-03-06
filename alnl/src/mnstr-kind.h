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
* $Id: mnstr-kind.h,v 1.17 2014/01/07 23:40:42 bowkenken Exp $
***************************************************************/

#ifndef	MNSTR_KIND_H
#define	MNSTR_KIND_H

/***************************************************************
* モンスターの種類
***************************************************************/

/* モンスターの種類のリスト */

typedef enum {
	MNSTR_KIND_NULL,
	/* 神 */
	/* ドラゴン */
	MNSTR_KIND_A_GOLD_DRAGON,
	MNSTR_KIND_A_SILVER_DRAGON,
	MNSTR_KIND_A_COPPER_DRAGON,
	MNSTR_KIND_A_RED_DRAGON,
	MNSTR_KIND_A_BLUE_DRAGON,
	MNSTR_KIND_A_GREEN_DRAGON,
	MNSTR_KIND_A_YELLOW_DRAGON,
	MNSTR_KIND_A_WHITE_DRAGON,
	MNSTR_KIND_A_BLACK_DRAGON,
	MNSTR_KIND_M_GOLD_DRAGON,
	MNSTR_KIND_M_SILVER_DRAGON,
	MNSTR_KIND_M_COPPER_DRAGON,
	MNSTR_KIND_M_RED_DRAGON,
	MNSTR_KIND_M_BLUE_DRAGON,
	MNSTR_KIND_M_GREEN_DRAGON,
	MNSTR_KIND_M_YELLOW_DRAGON,
	MNSTR_KIND_M_WHITE_DRAGON,
	MNSTR_KIND_M_BLACK_DRAGON,
	/* 幻獣 */
	MNSTR_KIND_PHOENIX,
	MNSTR_KIND_UNICORN,
	MNSTR_KIND_PYON_PYON,
	/* 妖精 */
	MNSTR_KIND_LEPRECHAUN,
	/* 精霊 */
	MNSTR_KIND_FIRE_ELEMENTAL,
	MNSTR_KIND_SALAMANDER,
	MNSTR_KIND_WATER_ELEMENTAL,
	MNSTR_KIND_UNDINE,
	MNSTR_KIND_AIR_ELEMENTAL,
	MNSTR_KIND_SYLPH,
	MNSTR_KIND_EARTH_ELEMENTAL,
	MNSTR_KIND_GNOME,
	MNSTR_KIND_WILL_O_WISP,
	MNSTR_KIND_SHADE,
	/* 植物 */
	MNSTR_KIND_VENUS_FLY_TRAP,
	MNSTR_KIND_SLIME,
	MNSTR_KIND_SPORE,
	/* 動物 */
	MNSTR_KIND_GIANT_BAT,
	MNSTR_KIND_GIANT_RAT,
	MNSTR_KIND_GIANT_SNAKE,
	MNSTR_KIND_VIPER_SNAKE,
	MNSTR_KIND_CAT,
	MNSTR_KIND_DOG,
	MNSTR_KIND_WOLF,
	/* 昆虫 */
	MNSTR_KIND_GIANT_CENTIPEDE,
	MNSTR_KIND_GIANT_BEE,
	MNSTR_KIND_GIANT_SCORPION,
	MNSTR_KIND_GIANT_ANT,
	MNSTR_KIND_GIANT_SPIDER,
	MNSTR_KIND_ACID_FLY,
	MNSTR_KIND_GIANT_BEETLE,
	/* 人間 */
	MNSTR_KIND_FIGHTER,
	MNSTR_KIND_MONK,
	MNSTR_KIND_HUNTER,
	MNSTR_KIND_THIEF,
	MNSTR_KIND_WIZARD,
	MNSTR_KIND_SUMMONER,
	MNSTR_KIND_PRIEST,
	MNSTR_KIND_SHAMAN,
	MNSTR_KIND_BARD,
	MNSTR_KIND_NINJA,
	MNSTR_KIND_BISHOP,
	MNSTR_KIND_FARMER,
	MNSTR_KIND_CRAFTSMAN,
	MNSTR_KIND_MERCHANT,
	/* 半人 */
	MNSTR_KIND_HARPY,
	MNSTR_KIND_ANDRO_SCORPION,
	MNSTR_KIND_LAMIA,
	MNSTR_KIND_CENTAUR,
	MNSTR_KIND_BIRD_MAN,
	MNSTR_KIND_WEREWOLF,
	MNSTR_KIND_MINOTAUR,
	MNSTR_KIND_MEDUSA,
	/* 巨人 */
	MNSTR_KIND_YETI,
	MNSTR_KIND_OGRE,
	MNSTR_KIND_TROLL,
	MNSTR_KIND_MORMIN_TROLL,
	MNSTR_KIND_FIRE_GIANT,
	MNSTR_KIND_FROST_GIANT,
	MNSTR_KIND_CLOUD_GIANT,
	MNSTR_KIND_MOUNTAIN_GIANT,
	MNSTR_KIND_CYCLOPS,
	/* 巨大生物 */
	/* 水棲生物 */
	/* 魔法生物 */
	MNSTR_KIND_INVISIBLE_STALKER,
	MNSTR_KIND_GARGOYLE,
	MNSTR_KIND_MIMIC,
	MNSTR_KIND_WOOD_GOLEM,
	MNSTR_KIND_BONE_GOLEM,
	MNSTR_KIND_FLESH_GOLEM,
	MNSTR_KIND_STONE_GOLEM,
	MNSTR_KIND_IRON_GOLEM,
	MNSTR_KIND_GAS_CLOUD,
	/* 合成獣 */
	MNSTR_KIND_HIPPOGRIFF,
	MNSTR_KIND_GRIFFON,
	MNSTR_KIND_MANTICORE,
	MNSTR_KIND_CHIMERA,
	/* アンデッド */
	MNSTR_KIND_POLTERGEIST,
	MNSTR_KIND_SKELETON,
	MNSTR_KIND_ZOMBIE,
	MNSTR_KIND_GHOUL,
	MNSTR_KIND_GHOST,
	MNSTR_KIND_WIGHT,
	MNSTR_KIND_MUMMY,
	MNSTR_KIND_DURAHAN,
	MNSTR_KIND_BANSHEE,
	MNSTR_KIND_WRAITH,
	MNSTR_KIND_VAMPIRE,
	MNSTR_KIND_SPIRIT,
	/* 妖魔 */
	MNSTR_KIND_KOBOLD,
	MNSTR_KIND_GNOLL,
	MNSTR_KIND_GOBLIN,
	MNSTR_KIND_HOBGOBLIN,
	MNSTR_KIND_GREMLIN,
	MNSTR_KIND_ORK,
	MNSTR_KIND_EFREET,
	MNSTR_KIND_DJINNI,
	/* 魔獣 */
	MNSTR_KIND_RUST_MONSTER,
	MNSTR_KIND_HELLHOUND,
	MNSTR_KIND_HYDRA,
	MNSTR_KIND_COCKATRICE,
	MNSTR_KIND_WYVERN,
	MNSTR_KIND_CERBERUS,
	MNSTR_KIND_GORGON,
	MNSTR_KIND_BASILISK,
	/* 悪魔 */
	MNSTR_KIND_IMP,
	MNSTR_KIND_JACK_O_LANTERN,
	MNSTR_KIND_SUCCUBUS,
	MNSTR_KIND_INCUBUS,
	MNSTR_KIND_LESSER_DAEMON,
	MNSTR_KIND_GREATER_DAEMON,
	/* 中ボス */
	MNSTR_KIND_HIGH_RE_HOO,
	MNSTR_KIND_GREAT_MINOTAUR,
	MNSTR_KIND_BILLION_ELEMENTAL,
	MNSTR_KIND_CYBERN,
	MNSTR_KIND_GIGANTIC_CENTIPEDE,
	MNSTR_KIND_MEDUSA_ZOMBIE,
	MNSTR_KIND_BLACK_UNICORN,
	MNSTR_KIND_VAMPIRE_LORD,
	MNSTR_KIND_RELATIVISTIC_DAEMON,
	MNSTR_KIND_ETERNAL_DRAGON,
	/* ラスボス */
	MNSTR_KIND_EXEL,
	MNSTR_KIND_EXELER,
	MNSTR_KIND_XEX,
	MNSTR_KIND_XX,
	/**/
	MNSTR_KIND_MAX_N,
} mnstr_kind_t;

/***************************************************************
* モンスターの顔
***************************************************************/

/* 神 */

#define	FACE_MJR_MNSTR_GOD	'+'

#define	FACE_MNR_MNSTR_COATL	'c'		/*@@@*/
#define	FACE_MNR_MNSTR_NAGA	'n'		/*@@@*/

/* ドラゴン */

#define	FACE_MJR_MNSTR_DRAGON	'D'

#define	FACE_MNR_MNSTR_ETERNAL_DRAGON	'X'
/* Ancient dragon */
#define	FACE_MNR_MNSTR_A_GOLD_DRAGON	'G'	/* RESI_KIND_SLAS,斬撃 */
#define	FACE_MNR_MNSTR_A_SILVER_DRAGON	'S'	/* RESI_KIND_KNOC,殴打 */
#define	FACE_MNR_MNSTR_A_COPPER_DRAGON	'C'	/* RESI_KIND_STIN,刺突 */
#define	FACE_MNR_MNSTR_A_RED_DRAGON	'R'	/* RESI_KIND_HEAT,火熱 */
#define	FACE_MNR_MNSTR_A_BLUE_DRAGON	'B'	/* RESI_KIND_COLD,水冷 */
#define	FACE_MNR_MNSTR_A_YELLOW_DRAGON	'Y'	/* RESI_KIND_MIND,風心 */
#define	FACE_MNR_MNSTR_A_GREEN_DRAGON	'E'	/* RESI_KIND_ACID,土酸 */
#define	FACE_MNR_MNSTR_A_WHITE_DRAGON	'W'	/* RESI_KIND_ELEC,光雷 */
#define	FACE_MNR_MNSTR_A_BLACK_DRAGON	'K'	/* RESI_KIND_POIS,闇毒 */
/* Minor dragon */
#define	FACE_MNR_MNSTR_M_GOLD_DRAGON	'g'	/* RESI_KIND_SLAS,斬撃 */
#define	FACE_MNR_MNSTR_M_SILVER_DRAGON	's'	/* RESI_KIND_KNOC,殴打 */
#define	FACE_MNR_MNSTR_M_COPPER_DRAGON	'c'	/* RESI_KIND_STIN,刺突 */
#define	FACE_MNR_MNSTR_M_RED_DRAGON	'r'	/* RESI_KIND_HEAT,火熱 */
#define	FACE_MNR_MNSTR_M_BLUE_DRAGON	'b'	/* RESI_KIND_COLD,水冷 */
#define	FACE_MNR_MNSTR_M_YELLOW_DRAGON	'y'	/* RESI_KIND_MIND,風心 */
#define	FACE_MNR_MNSTR_M_GREEN_DRAGON	'e'	/* RESI_KIND_ACID,土酸 */
#define	FACE_MNR_MNSTR_M_WHITE_DRAGON	'w'	/* RESI_KIND_ELEC,光雷 */
#define	FACE_MNR_MNSTR_M_BLACK_DRAGON	'k'	/* RESI_KIND_POIS,闇毒 */

/* 幻獣 */

#define	FACE_MJR_MNSTR_ILLUSORY	'L'

#define	FACE_MNR_MNSTR_PHOENIX	'x'
#define	FACE_MNR_MNSTR_UNICORN	'u'
#define	FACE_MNR_MNSTR_PEGASUS	'g'		/*@@@*/
#define	FACE_MNR_MNSTR_PYON_PYON	'p'

/* 妖精 */

#define	FACE_MJR_MNSTR_FAIRY	'F'

#define	FACE_MNR_MNSTR_PIXY	'p'		/*@@@*/
#define	FACE_MNR_MNSTR_SPRITE	's'		/*@@@*/
#define	FACE_MNR_MNSTR_DRYAD	'd'		/*@@@*/
#define	FACE_MNR_MNSTR_BROWNIE	'b'		/*@@@*/
#define	FACE_MNR_MNSTR_LEPRECHAUN	'l'

/* 精霊 */

#define	FACE_MJR_MNSTR_ELEMENTAL	'E'

#define	FACE_MNR_MNSTR_BILLION_ELEMENTAL	'B'
#define	FACE_MNR_MNSTR_FIRE_ELEMENTAL	'f'
#define	FACE_MNR_MNSTR_SALAMANDER	's'
#define	FACE_MNR_MNSTR_WATER_ELEMENTAL	'w'
#define	FACE_MNR_MNSTR_UNDINE	'u'
#define	FACE_MNR_MNSTR_AIR_ELEMENTAL	'a'
#define	FACE_MNR_MNSTR_SYLPH	'y'
#define	FACE_MNR_MNSTR_EARTH_ELEMENTAL	'e'
#define	FACE_MNR_MNSTR_GNOME	'g'
#define	FACE_MNR_MNSTR_WILL_O_WISP	'o'
#define	FACE_MNR_MNSTR_SHADE	'd'

/* 植物 */

#define	FACE_MJR_MNSTR_PLANT	'P'

#define	FACE_MNR_MNSTR_VENUS_FLY_TRAP	'f'
#define	FACE_MNR_MNSTR_SLIME	's'
#define	FACE_MNR_MNSTR_SPORE	'p'
#define	FACE_MNR_MNSTR_MANDRAKE	'm'		/*@@@*/
#define	FACE_MNR_MNSTR_TREANT	't'		/*@@@*/

/* 動物 */

#define	FACE_MJR_MNSTR_ANIMAL	'A'

#define	FACE_MNR_MNSTR_BAT	'b'
#define	FACE_MNR_MNSTR_RAT	'r'
#define	FACE_MNR_MNSTR_SNAKE	's'
#define	FACE_MNR_MNSTR_CAT	'c'
#define	FACE_MNR_MNSTR_DOG	'd'
#define	FACE_MNR_MNSTR_WOLF	'w'
#define	FACE_MNR_MNSTR_ELEPHANT	'e'		/*@@@*/
#define	FACE_MNR_MNSTR_LIZARD	'z'		/*@@@*/
#define	FACE_MNR_MNSTR_TIGER	't'		/*@@@*/
#define	FACE_MNR_MNSTR_BEAR	'a'		/*@@@*/
#define	FACE_MNR_MNSTR_HORSE	'h'		/*@@@*/

/* 昆虫 */

#define	FACE_MJR_MNSTR_INSECT	'I'

#define	FACE_MNR_MNSTR_CENTIPEDE	'c'
#define	FACE_MNR_MNSTR_BEE	'b'
#define	FACE_MNR_MNSTR_SCORPION	'p'
#define	FACE_MNR_MNSTR_ANT	'a'
#define	FACE_MNR_MNSTR_SPIDER	's'
#define	FACE_MNR_MNSTR_FLY	'f'
#define	FACE_MNR_MNSTR_BEETLE	't'

/* 人間、亜人間 */

#define	FACE_MJR_MNSTR_HUMAN	'H'

#define	FACE_MNR_MNSTR_FIGHTER	'f'
#define	FACE_MNR_MNSTR_MONK	'm'
#define	FACE_MNR_MNSTR_HUNTER	'h'
#define	FACE_MNR_MNSTR_THIEF	't'
#define	FACE_MNR_MNSTR_WIZARD	'w'
#define	FACE_MNR_MNSTR_SUMMONER	's'
#define	FACE_MNR_MNSTR_PRIEST	'p'
#define	FACE_MNR_MNSTR_SHAMAN	'a'
#define	FACE_MNR_MNSTR_BARD	'b'
#define	FACE_MNR_MNSTR_NINJA	'n'
#define	FACE_MNR_MNSTR_BISHOP	'i'
#define	FACE_MNR_MNSTR_CAVEMAN	'c'		/*@@@*/
#define	FACE_MNR_MNSTR_HAG	'g'		/*@@@*/
#define	FACE_MNR_MNSTR_FARMER	'u'
#define	FACE_MNR_MNSTR_CRAFTSMAN	'u'
#define	FACE_MNR_MNSTR_MERCHANT	'u'

/* 半人 */

#define	FACE_MJR_MNSTR_HYBRID	'Y'

#define	FACE_MNR_MNSTR_GREAT_MINOTAUR	'M'
#define	FACE_MNR_MNSTR_MEDUSA_ZOMBIE	'D'
#define	FACE_MNR_MNSTR_HARPY	'h'
#define	FACE_MNR_MNSTR_ANDRO_SCORPION	's'
#define	FACE_MNR_MNSTR_LAMIA	'l'
#define	FACE_MNR_MNSTR_CENTAUR	'c'
#define	FACE_MNR_MNSTR_BIRD_MAN	'b'
#define	FACE_MNR_MNSTR_LYCANTHROPE	'p'
#define	FACE_MNR_MNSTR_MINOTAUR	'm'
#define	FACE_MNR_MNSTR_MEDUSA	'd'
#define	FACE_MNR_MNSTR_SPHINX	'x'		/*@@@*/
#define	FACE_MNR_MNSTR_LIZARDMAN	'z'		/*@@@*/
#define	FACE_MNR_MNSTR_GILLMAN	'g'		/*@@@*/
#define	FACE_MNR_MNSTR_SIREN	'r'		/*@@@*/
#define	FACE_MNR_MNSTR_SCYLLA	'y'		/*@@@*/
#define	FACE_MNR_MNSTR_SATYR	'a'		/*@@@*/

/* 巨人 */

#define	FACE_MJR_MNSTR_GIANT	'G'

#define	FACE_MNR_MNSTR_HIGH_RE_HOO	'H'
#define	FACE_MNR_MNSTR_YETI	'y'
#define	FACE_MNR_MNSTR_OGRE	'o'
#define	FACE_MNR_MNSTR_TROLL	't'
#define	FACE_MNR_MNSTR_FIRE_GIANT	'f'
#define	FACE_MNR_MNSTR_FROST_GIANT	'r'
#define	FACE_MNR_MNSTR_CLOUD_GIANT	'l'
#define	FACE_MNR_MNSTR_MOUNTAIN_GIANT	'm'
#define	FACE_MNR_MNSTR_HILL_GIANT	'h'		/*@@@*/
#define	FACE_MNR_MNSTR_CYCLOPS	'c'
#define	FACE_MNR_MNSTR_HUMBABA	'b'		/*@@@*/

/* 巨大生物 */

#define	FACE_MJR_MNSTR_HUGE	'B'

#define	FACE_MNR_MNSTR_GIGANTIC_CENTIPEDE	'C'
#define	FACE_MNR_MNSTR_WORM	'w'		/*@@@*/
#define	FACE_MNR_MNSTR_DINOSAUR	'd'		/*@@@*/
#define	FACE_MNR_MNSTR_ROC	'r'		/*@@@*/

/* 水棲生物 */

#define	FACE_MJR_MNSTR_AQUATIC	'Q'

#define	FACE_MNR_MNSTR_KRAKEN	'k'		/*@@@*/
#define	FACE_MNR_MNSTR_SEA_SERPENT	's'		/*@@@*/
#define	FACE_MNR_MNSTR_MERMAN	'm'		/*@@@*/
#define	FACE_MNR_MNSTR_MERMAID	'w'		/*@@@*/

/* 魔法生物 */

#define	FACE_MJR_MNSTR_MAGICAL	'M'

#define	FACE_MNR_MNSTR_CYBERN	'C'
#define	FACE_MNR_MNSTR_INVISIBLE_STALKER	'v'
#define	FACE_MNR_MNSTR_GARGOYLE	'g'
#define	FACE_MNR_MNSTR_MIMIC	'&'
#define	FACE_MNR_MNSTR_WOOD_GOLEM	'w'
#define	FACE_MNR_MNSTR_BONE_GOLEM	'b'
#define	FACE_MNR_MNSTR_FLESH_GOLEM	'f'
#define	FACE_MNR_MNSTR_STONE_GOLEM	's'
#define	FACE_MNR_MNSTR_IRON_GOLEM	'i'
#define	FACE_MNR_MNSTR_GAS_CLOUD	'c'
#define	FACE_MNR_MNSTR_HOMUNCULUS	'h'		/*@@@*/

/* 合成獣 */

#define	FACE_MJR_MNSTR_COMPOUND	'C'

#define	FACE_MNR_MNSTR_HIPPOGRIFF	'h'
#define	FACE_MNR_MNSTR_GRIFFON	'g'
#define	FACE_MNR_MNSTR_MANTICORE	'm'
#define	FACE_MNR_MNSTR_CHIMERA	'c'

/* アンデッド */

#define	FACE_MJR_MNSTR_UNDEAD	'U'

#define	FACE_MNR_MNSTR_VAMPIRE_LORD	'V'
#define	FACE_MNR_MNSTR_POLTERGEIST	'p'
#define	FACE_MNR_MNSTR_SKELETON	's'
#define	FACE_MNR_MNSTR_ZOMBIE	'z'
#define	FACE_MNR_MNSTR_GHOUL	'h'
#define	FACE_MNR_MNSTR_GHOST	'g'
#define	FACE_MNR_MNSTR_WIGHT	'w'
#define	FACE_MNR_MNSTR_MUMMY	'm'
#define	FACE_MNR_MNSTR_DURAHAN	'u'
#define	FACE_MNR_MNSTR_BANSHEE	'b'
#define	FACE_MNR_MNSTR_WRAITH	'r'
#define	FACE_MNR_MNSTR_VAMPIRE	'v'
#define	FACE_MNR_MNSTR_SPIRIT	't'
#define	FACE_MNR_MNSTR_DOPPELGANGER	'd'		/*@@@*/

/* 妖魔 */

#define	FACE_MJR_MNSTR_EVIL	'V'

#define	FACE_MNR_MNSTR_KOBOLD	'k'
#define	FACE_MNR_MNSTR_GOBLIN	'g'
#define	FACE_MNR_MNSTR_GREMLIN	'm'
#define	FACE_MNR_MNSTR_HOBGOBLIN	'h'
#define	FACE_MNR_MNSTR_ORK	'o'
#define	FACE_MNR_MNSTR_GNOLL	'n'
#define	FACE_MNR_MNSTR_INCUBUS	'i'
#define	FACE_MNR_MNSTR_SUCCUBUS	's'
#define	FACE_MNR_MNSTR_EFREET	'e'
#define	FACE_MNR_MNSTR_DJINNI	'j'

/* 魔獣 */

#define	FACE_MJR_MNSTR_EVIL_BEAST	'W'

#define	FACE_MNR_MNSTR_BLACK_UNICORN	'U'
#define	FACE_MNR_MNSTR_RUST_MONSTER	'r'
#define	FACE_MNR_MNSTR_HELLHOUND	'h'
#define	FACE_MNR_MNSTR_HYDRA	'y'
#define	FACE_MNR_MNSTR_COCKATRICE	'k'
#define	FACE_MNR_MNSTR_WYVERN	'w'
#define	FACE_MNR_MNSTR_CERBERUS	'c'
#define	FACE_MNR_MNSTR_GORGON	'g'
#define	FACE_MNR_MNSTR_BASILISK	'b'
#define	FACE_MNR_MNSTR_BEHOLDER	'e'		/*@@@*/

/* 悪魔 */

#define	FACE_MJR_MNSTR_DEVIL	'X'

#define	FACE_MNR_MNSTR_XX	'X'
#define	FACE_MNR_MNSTR_XEX	'E'
#define	FACE_MNR_MNSTR_EXELER	'R'
#define	FACE_MNR_MNSTR_EXEL	'L'
#define	FACE_MNR_MNSTR_RELATIVISTIC_DAEMON	'V'
#define	FACE_MNR_MNSTR_IMP	'i'
#define	FACE_MNR_MNSTR_JACK_O_LANTERN	'j'
#define	FACE_MNR_MNSTR_MIND_FLAYER	'm'		/*@@@*/
#define	FACE_MNR_MNSTR_BEHEMOTH	'b'		/*@@@*/
#define	FACE_MNR_MNSTR_LESSER_DAEMON	'd'
#define	FACE_MNR_MNSTR_GREATER_DAEMON	'D'

#endif	/* MNSTR_KIND_H */
