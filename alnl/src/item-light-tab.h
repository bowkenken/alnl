/* This file was generated by awk's script */
/* cv-tab.awk : *.csv -> *_tab.h */
/* rcv-tab.awk: *.csv <- *_tab.h */
	{
		NULL, N_MSG_ITEM_UNKNOWN,
		NULL, N_MSG_ITEM_UNKNOWN,
		LIGHT_KIND_NULL, (rate_t)0,
		DUN_MAX_LEV_BASE, DUN_MAX_LEV_BASE, 0,
		0, 0,
		0, FALSE,
		WISH_LEVEL_NULL, 0,
	},
	{
		NULL, N_MSG_LIGHT_TORCH,
		NULL, N_MSG_LIGHT_TORCH,
		LIGHT_KIND_TORCH, (rate_t)80,
		0, DUN_MAX_LEV_BASE, -1,
		0, 50,
		LIGHT_MAX_TURN_TORCH, FALSE,
		WISH_LEVEL_NULL, 0,
	},
	{
		NULL, N_MSG_LIGHT_LANTERN,
		NULL, N_MSG_LIGHT_LANTERN,
		LIGHT_KIND_LANTERN, (rate_t)80,
		0, DUN_MAX_LEV_BASE, -1,
		700, 10,
		LIGHT_MAX_TURN_LANTERN, TRUE,
		WISH_LEVEL_NULL, 0,
	},
	{
		NULL, N_MSG_LIGHT_LAMP,
		NULL, N_MSG_LIGHT_LAMP,
		LIGHT_KIND_LAMP, (rate_t)80,
		0, DUN_MAX_LEV_BASE, -1,
		700, 10,
		LIGHT_MAX_TURN_LAMP, TRUE,
		WISH_LEVEL_NULL, 0,
	},
	{
		NULL, N_MSG_LIGHT_LAMP,
		NULL, N_MSG_LIGHT_LAMP_ARMAGEDDON,
		LIGHT_KIND_LAMP, (rate_t)5,
		100, DUN_MAX_LEV_BASE, -1,
		50000, 10,
		LIGHT_MAX_TURN_LAMP, TRUE,
		WISH_LEVEL_ARMAGEDDON, 1,
	},
	{
		NULL, N_MSG_LIGHT_LAMP,
		NULL, N_MSG_LIGHT_LAMP_DAEMON,
		LIGHT_KIND_LAMP, (rate_t)10,
		50, DUN_MAX_LEV_BASE, -1,
		40000, 10,
		LIGHT_MAX_TURN_LAMP, TRUE,
		WISH_LEVEL_DAEMON, 3,
	},
	{
		NULL, N_MSG_LIGHT_LAMP,
		NULL, N_MSG_LIGHT_LAMP_DJINNI,
		LIGHT_KIND_LAMP, (rate_t)10,
		50, DUN_MAX_LEV_BASE, -1,
		40000, 10,
		LIGHT_MAX_TURN_LAMP, TRUE,
		WISH_LEVEL_DJINNI, 3,
	},
	{
		NULL, N_MSG_NULL,
		NULL, N_MSG_NULL,
		LIGHT_KIND_NULL, (rate_t)0,
		DUN_MAX_LEV_BASE, DUN_MAX_LEV_BASE, 0,
		0, 0,
		0, FALSE,
		WISH_LEVEL_NULL, 0,
	},
