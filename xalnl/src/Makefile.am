#

# Debug

if CHK_DEBUG
#CFLAGS_DEBUG = -p -DDEBUG -DD_TEST_TRAP
CFLAGS_DEBUG = -p -DDEBUG
else
CFLAGS_DEBUG = -DNDEBUG
endif

# Clock

if CHK_DEF_CLK_TCK
CFLAGS_CLK_TCK = '-DCLK_TCK=1000000'
endif

AM_CFLAGS = $(CFLAGS_DEBUG) $(CFLAGS_CLK_TCK) -Wall \
	-DD_GTK `pkg-config --cflags gtk+-2.0` \
	`sdl-config --cflags ` \
	-DD_CUI_MOUSE -DD_GL
AM_CXXFLAGS = $(CFLAGS_DEBUG) $(CFLAGS_CLK_TCK) -Wall \
	-DD_GTK `pkg-config --cflags gtk+-2.0` \
	`sdl-config --cflags ` \
	-DD_CUI_MOUSE -DD_GL
AM_LDFLAGS = `pkg-config \--libs gtk+-2.0 \--libs gthread-2.0` \
	`sdl-config --libs` -lSDL_image -lSDL_mixer \
	-lGL -lGLU -lglut -lX11 \
	-lv8
#xalnl_LDADD = `pkg-config \--libs gtk+-2.0 \--libs gthread-2.0` \
#	`sdl-config --libs` -lSDL_mixer -lv8

bin_PROGRAMS = xalnl
xalnl_SOURCES = \
	FileList.cpp FileList.h GameThread.cpp GameThread.h GlobalVar.cpp \
	GlobalVar.h GtkMisc.h GtkWSCstring.cpp GtkWSCstring.h \
	GtkWSDimage.h GtkWSDmwindowDev.cpp GtkWSDmwindowDev.h \
	GuiInputString.cpp GuiInputString.h GuiMenu.cpp GuiMenu.h \
	GuiMessage.cpp GuiMessage.h GuiMisc.cpp GuiMisc.h GuiNum.cpp \
	GuiNum.h GuiStat.cpp GuiStat.h GuiWords.cpp GuiWords.h \
	GuiReplay.cpp GuiReplay.h GuiClassEdit.cpp GuiClassEdit.h \
	GuiSkillEdit.cpp GuiSkillEdit.h \
	GuiChrSheet.cpp GuiChrSheet.h \
	Key.cpp Key.h \
	CuiMouse.cpp CuiMouse.h \
	MouseMap.cpp MouseMap.h MouseMotion.cpp MouseMotion.h \
	Pcg.cpp Pcg.h PcgDun.cpp PcgDun.h PcgDunTab.h \
	PcgMap.cpp PcgMap.h \
	PcgTile.cpp PcgTile.h \
	PcgCharGraph.cpp PcgCharGraph.h \
	DemoTitle.cpp DemoTitle.h DemoGameOver.cpp DemoGameOver.h \
	DemoEnding.cpp DemoEnding.h DemoSpace.cpp DemoSpace.h \
	DemoLastBoss.cpp DemoLastBoss.h DemoCutIn.cpp DemoCutIn.h \
	GuiLastBoss.cpp GuiLastBoss.h \
	SelConf.h SelConf.cpp \
	GraphConf.h GraphConf.cpp GraphConfToken.h \
	SelMbrGraph.cpp SelMbrGraph.h \
	GameMusic.cpp GameMusic.h music-kind.h \
	GameSound.cpp GameSound.h sound-kind.h \
	GameJoystick.cpp GameJoystick.h \
	WinPos.cpp WinPos.h \
	abl-kind.h \
	call-prot.h call.cpp \
	chr-prot.h chr.c chr.h config-win.h \
	class-dflt-tab.h class-tab.h \
	skill.c skill.h skill-prot.h skill-tab.h \
	config.h crsr-ptn.h curs-def.h curs-prot.h curs.c curs.h \
	draw-prot.h draw-tab.h draw.c draw.h \
	dun-prot.h dun-tab.h dun.c dun.h \
	map-event-prot.h map-event.c map-event.h \
	extern.h fight-prot.h fight.c fight.h \
	fx-prot.h fx.c fx.h \
	gf-conf.c gf-crsr.c gf-gconf.c gf-outmap.c gf-replay.c gf-save.c \
	gf-town.c gfile-prot.h gfile-tab.h gfile-ver.h gfile.c gfile.h \
	gmain-prot.h gmain.c gmain.h \
	item-acce-tab.h item-anthology-tab.h item-armor-tab.h \
	item-coin-tab.h item-food-tab.h item-inst-tab.h item-kind.h \
	item-light-tab.h item-pipe-tab.h item-potion-tab.h item-prot.h \
	item-range-tab.h item-rare-goods-tab.h item-scroll-tab.h \
	item-stick-tab.h item-tab.h item-tobacco-tab.h item-wpn-tab.h \
	item-randm-art.h item-randm-art-tab.h \
	item.c item.h \
	main-gtk-prot.h \
	main-gtk.cpp main-prot.h \
	main-ws-prot.h main-x-prot.h main-x.c main-x.h \
	menu-prot.h menu-tab.h menu.c menu.h \
	menu-main-prot.h menu-main-tab.h menu-main.c \
	menu-misc-prot.h menu-misc-tab.h menu-misc.c inc.h \
	menu-amark-prot.h menu-amark-tab.h menu-amark.c menu-amark.h \
	menu-town-prot.h menu-town-tab.h menu-town.c town-prot.h \
	fx-menu-tab.h \
	misc-prot.h misc.c misc.h \
	mnstr-act-prot.h mnstr-act.c \
	mnstr-gen-tab.h mnstr-kind.h mnstr-prot.h mnstr-tab.h \
	mnstr.c mnstr.h msg-eng.h msg-jpn-sjis.h msg-jpn-utf8.h msg-jpn.h \
	msg-prot.h msg-t.h msg.c msg.h nest-flg-prot.h nest-flg.c \
	nest-flg.h party-prot.h party.c party.h pet-prot.h pet.c pet.h \
	play-rep-prot.h play-rep.c play-rep.h \
	replay-prot.h replay.c replay.h \
	request-prot.h request-tab.h request.c request.h resi.h \
	rumor-tab.h \
	scene-prot.h scene.c scene.h \
	spell-gen-tab.h spell-kind.h spell-prot.h spell-tab.h \
	spell.c spell.h \
	stay-inn-kind.h \
	town-tab.h town.c town.h trap-prot.h trap.c trap.h turn-prot.h \
	turn.c turn.h ver.h vfx-kind.h win-kind.h joy-kind.h \
	key-item.c key-item.h key-item-prot.h \
	last-boss.c last-boss.h last-boss-prot.h last-boss-tab.h \
	ending-ep.c ending-ep.h ending-ep-prot.h \
	ending-space.c ending-space.h ending-space-prot.h 

#	MapFormDraw.cpp MapFormInit.cpp MapFormMouseMove.cpp \
#	MapFormMousePress.cpp MapFormMouseRellease.cpp MapFormResize.cpp \
#	MapScrollXDraw.cpp MapScrollXValCh.cpp MapScrollYDraw.cpp \
#	MapScrollYValCh.cpp \
#	MapWin.cpp MapWin.h MapWinInit.cpp \
#	MenuBtnCancelActivate.cpp MenuBtnNextPageActivate.cpp \
#	MenuBtnPrevPageActivate.cpp \
#	MenuWin.cpp MenuWin.h MenuWinInit.cpp \
#	StatWinDADraw.cpp \
#	StatWinDAInit.cpp StatWinIdx.h StatWinResize.cpp \
#	InpStrWinInit.cpp \
#	main-unix-prot.h main-unix.c \
#	main-win-prot.h main-win.c \
#	main-dos-prot.h main-dos.c \
#	xalnl.cpp \
#

#bin_SCRIPTS = msg.h
msg-jpn-utf8.h: msg-jpn.h 
	./msg-cv-utf8

msg.h: msg-eng.h msg-jpn.h msg-jpn-utf8.h
	./msg-def

EXTRA_DIST = \
	msg-def msg-def-sub msg-cv-utf8 town-ptn.xpm \
	main-dos.c main-dos-prot.h \
	MapFormDraw.cpp MapFormInit.cpp MapFormMouseMove.cpp \
	MapFormMousePress.cpp MapFormMouseRellease.cpp MapFormResize.cpp \
	MapScrollXDraw.cpp MapScrollXValCh.cpp MapScrollYDraw.cpp \
	MapScrollYValCh.cpp \
	MapWin.cpp MapWin.h MapWinInit.cpp \
	MenuBtnCancelActivate.cpp MenuBtnNextPageActivate.cpp \
	MenuBtnPrevPageActivate.cpp \
	MenuWin.cpp MenuWin.h MenuWinInit.cpp \
	StatWinDADraw.cpp \
	StatWinDAInit.cpp StatWinIdx.h StatWinResize.cpp \
	InpStrWinInit.cpp \
	main-unix-prot.h main-unix.c \
	main-dows-prot.h main-dows.cpp \
	main-dos-prot.h main-dos.c \
	xalnl.cpp
