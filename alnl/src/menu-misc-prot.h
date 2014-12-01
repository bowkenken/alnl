/* menu-misc.c */

#ifdef __cplusplus
extern "C" {
#endif

void	init_var_misc_menu( void );
void	reset_static_misc_menu( void );
void	init_misc_menu( void );
char	*cb_menu_misc( menu_t **pp, menu_t **dflt );
char	*cb_menu_info( menu_t **pp, menu_t **dflt );
char	*cb_menu_continue_exec( menu_t **pp, menu_t **dflt );
bool_t	chk_continue_exec_mode( long *c, bool_t *p_flg_clr_key_buf );
bool_t	get_continue_exec_mode( void );
bool_t	toggle_continue_exec_mode( void );
bool_t	clr_continue_exec_mode( void );
char	*cb_menu_stairs( menu_t **pp, menu_t **dflt );
char	*cb_menu_stairs_up( menu_t **pp, menu_t **dflt );
char	*cb_menu_stairs_down( menu_t **pp, menu_t **dflt );
char	*cb_menu_stairs_last_boss( menu_t **pp, menu_t **dflt );
char	*cb_menu_srch( menu_t **pp, menu_t **dflt );
char	*cb_menu_srch_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_srch_exec( menu_t **pp, menu_t **dflt );
char	*cb_menu_srch_exec_all( menu_t **pp, menu_t **dflt );
char	*cb_menu_srch_cancel_all( menu_t **pp, menu_t **dflt );
char	*cb_menu_srch_sel_mbr( menu_t **pp, menu_t **dflt );
char	*cb_menu_srch_auto_off( menu_t **pp, menu_t **dflt );
char	*cb_menu_show_map_hint( menu_t **pp, menu_t **dflt );
void	show_map_hint( long x, long y );
void	show_map_hint_chr( long x, long y );
void	show_map_hint_obj( long x, long y );
const char	*get_str_map_hint_chr( long x, long y );
const char	*get_str_map_hint_obj( long x, long y );
char	*cb_menu_chr_data( menu_t **pp, menu_t **dflt );
char	*menu_sel_mbr_data( long sel_mbr_n );
char	*menu_sel_pet_data( long sel_pet_n );
long	menu_show_mbr_data( mbr_t *mbr, long *page_n, data_n_t *data_n );
long	menu_edit_mbr_data( mbr_t *mbr, long *page_n, data_n_t *data_n );
long	menu_mbr_data(
	mbr_t *org_p, long *page_n, data_n_t *data_n,
	mbr_data_edit_kind_t edit_kind
);
long	menu_mbr_data_sub(
	mbr_t *org_p, long *page_n, data_n_t *data_n,
	mbr_data_edit_kind_t edit_kind
);
void	set_data_n( data_n_t data_n );
long	get_mbr_data_page_n( void );
void	set_mbr_data_page_n( long n );
mbr_data_edit_kind_t	get_mbr_data_edit_kind( void );
void	exec_menu_edit_mbr_data(
	mbr_t *mbr, data_n_t n, long *mbr_dn, long *page_dn
);
bool_t	exec_menu_ask_edit_mbr_data( mbr_t *org_p, mbr_t *mbr_p );
void	sel_mbr_graph_file( mbr_t *mbr );
char	*menu_sel_mnstr_data( mnstr_t *mnstr );
char	*cb_menu_switch_stat_mode( menu_t **pp, menu_t **dflt );
char	*cb_menu_gold( menu_t **pp, menu_t **dflt );
char	*cb_menu_collect_gold( menu_t **pp, menu_t **dflt );
char	*cb_menu_divide_gold( menu_t **pp, menu_t **dflt );
char	*cb_menu_give_gold( menu_t **pp, menu_t **dflt );
char	*menu_mbr_give_gold( mbr_t *mbr_from );
char	*cb_menu_formation( menu_t **pp, menu_t **dflt );
void	set_menu_formation( menu_t *ls, menu_t **dflt, long mbr_n );
char	*cb_menu_formation_sel_n( menu_t **pp, menu_t **dflt );
char	*cb_menu_position( menu_t **pp, menu_t **dflt );
char	*exec_menu_position( mbr_t *mbr );
char	*cb_menu_position_sel( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_move( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_move_abs( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_move_stop( menu_t **pp, menu_t **dflt );
void	move_crsr_abs( long x, long y );
void	move_crsr_rel( long dx, long dy );
char	*cb_menu_crsr_quick_move( menu_t **pp, menu_t **dflt );
void	jump_crsr( long dx, long dy );
char	*cb_menu_crsr_ind_square( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_ind_square_num( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_ind_square_mbr( menu_t **pp, menu_t **dflt );
void	menu_crsr_ind_square_set_mbr( long mbr_n );
char	*cb_menu_crsr_ind_square_party( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_scroll( menu_t **pp, menu_t **dflt );
void	crsr_scroll( long dx, long dy );
char	*cb_menu_crsr_move_mbr( menu_t **pp, menu_t **dflt );
char	*menu_crsr_move_mbr_n( long mbr_n );
char	*menu_crsr_move_mbr( mbr_t *mbr );
char	*cb_menu_crsr_center( menu_t **pp, menu_t **dflt );
void	chk_scroll( bool_t flg_gui );
void	scroll_smooth( void );
void	scroll_center( void );
void	scroll_half_page( void );
void	move_crsr_mbr_trgt( mbr_t *mbr );
char	*cb_menu_crsr_next_pos_mbr( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_next_pos_mnstr( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_next_pos_item( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_next_pos_door( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_next_pos_obj( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_next_pos_square( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_next_pos_all( menu_t **pp, menu_t **dflt );
char	*cb_menu_crsr_prev_pos( menu_t **pp, menu_t **dflt );
bool_t	next_pos_mbr( long d );
bool_t	next_pos_mnstr( long d );
bool_t	next_pos_mnstr_sub( long *dx, long *dy, long d );
bool_t	next_pos_item( long d );
bool_t	next_pos_obj( long d );
bool_t	next_pos_item_obj( long d, bool_t flg_item );
bool_t	next_pos_item_obj_sub( long *dx, long *dy, long d, bool_t flg_item );
bool_t	next_pos_door( long d );
bool_t	next_pos_square( long d );
bool_t	next_pos_all( long d );
bool_t	prev_pos( void );
char	*cb_menu_msg( menu_t **pp, menu_t **dflt );
char	*cb_menu_back_log( menu_t **pp, menu_t **dflt );
char	*exec_back_log( void );
char	*cb_menu_ls_msg( menu_t **pp, menu_t **dflt );
char	*cb_menu_scroll_msg( menu_t **pp, menu_t **dflt );
char	*cb_menu_ls_key_item( menu_t **pp, menu_t **dflt );
char	*cb_menu_ls_mnstr( menu_t **pp, menu_t **dflt );
char	*cb_menu_set_dflt_cnf( menu_t **pp, menu_t **dflt );
char	*cb_menu_cnf( menu_t **pp, menu_t **dflt );
char	*cb_menu_mbr_flg( menu_t **pp, menu_t **dflt );
char	*cb_menu_mbr_flg_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_auto_fight( menu_t **pp, menu_t **dflt );
char	*cb_menu_auto_door( menu_t **pp, menu_t **dflt );
char	*cb_menu_avoid_trap( menu_t **pp, menu_t **dflt );
char	*cb_menu_auto_reload( menu_t **pp, menu_t **dflt );
char	*cb_menu_actual_fighting( menu_t **pp, menu_t **dflt );
char	*cb_menu_space_select( menu_t **pp, menu_t **dflt );
char	*cb_menu_reset_file_config( menu_t **pp, menu_t **dflt );
char	*cb_menu_reset_file_crsr_ptn( menu_t **pp, menu_t **dflt );
char	*cb_menu_reset_file_town_ptn( menu_t **pp, menu_t **dflt );
char	*cb_menu_lang( menu_t **pp, menu_t **dflt );
char	*cb_menu_lang_ls( menu_t **pp, menu_t **dflt );
char	*cb_menu_lang_ls_sel( menu_t **pp, menu_t **dflt );
char	*cb_menu_lang_ls_priority( menu_t **pp, menu_t **dflt );
char	*cb_menu_window( menu_t **pp, menu_t **dflt );
char	*cb_menu_scroll_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_scroll_page( menu_t **pp, menu_t **dflt );
char	*cb_menu_scroll_smooth( menu_t **pp, menu_t **dflt );
char	*cb_menu_scroll_center( menu_t **pp, menu_t **dflt );
void	set_scroll_page( void );
void	set_scroll_smooth( void );
void	set_scroll_center( void );
char	*cb_menu_redraw_every_turn( menu_t **pp, menu_t **dflt );
char	*cb_menu_mul_msg_line( menu_t **pp, menu_t **dflt );
char	*cb_menu_stat_bar_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_stat_bar_hint_chr( menu_t **pp, menu_t **dflt );
char	*cb_menu_stat_bar_hint_obj( menu_t **pp, menu_t **dflt );
char	*cb_menu_screen_size_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_screen_size_auto( menu_t **pp, menu_t **dflt );
char	*cb_menu_screen_size_col( menu_t **pp, menu_t **dflt );
char	*cb_menu_screen_size_row( menu_t **pp, menu_t **dflt );
char	*cb_menu_screen_size_message( menu_t **pp, menu_t **dflt );
char	*cb_menu_screen_size_map( menu_t **pp, menu_t **dflt );
char	*cb_menu_vfx( menu_t **pp, menu_t **dflt );
char	*cb_menu_vfx_mbr( menu_t **pp, menu_t **dflt );
char	*cb_menu_vfx_mnstr( menu_t **pp, menu_t **dflt );
char	*cb_menu_vfx_wait( menu_t **pp, menu_t **dflt );
char	*cb_menu_vfx_measure_clk_tck( menu_t **pp, menu_t **dflt );
char	*cb_menu_color( menu_t **pp, menu_t **dflt );
char	*cb_menu_color_sel( menu_t **pp, menu_t **dflt );
char	*cb_menu_fg_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_bg_init( menu_t **pp, menu_t **dflt );
void	menu_color_init( menu_t **pp, menu_t **dflt, int color );
char	*cb_menu_fg( menu_t **pp, menu_t **dflt );
char	*cb_menu_bg( menu_t **pp, menu_t **dflt );
void	set_fg_color( curs_attr_t *attr, int color );
void	set_bg_color( curs_attr_t *attr, int color );
char	*cb_menu_attr_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_attr( menu_t **pp, menu_t **dflt );
void	set_color_attr( curs_attr_t *attr, bool_t flg_on, chtype_t ch );
void	rev_color_attr( curs_attr_t *attr, chtype_t ch );
char	*cb_menu_crsr_ptn( menu_t **pp, menu_t **dflt );
char	*cb_menu_main_crsr_ptn_sel( menu_t **pp, menu_t **dflt );
char	*cb_menu_sub_crsr_ptn_sel( menu_t **pp, menu_t **dflt );
char	*cb_menu_demo( menu_t **pp, menu_t **dflt );
char	*cb_menu_skip_cut_in( menu_t **pp, menu_t **dflt );
char	*cb_menu_star_cui( menu_t **pp, menu_t **dflt );
char	*cb_menu_star_gui( menu_t **pp, menu_t **dflt );
char	*cb_menu_key_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_clr_key_buf_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_clr_key_buf_every( menu_t **pp, menu_t **dflt );
char	*cb_menu_clr_key_buf_menu( menu_t **pp, menu_t **dflt );
char	*cb_menu_echo_key( menu_t **pp, menu_t **dflt );
char	*cb_menu_set_key( menu_t **pp, menu_t **dflt );
char	*cb_menu_set_key_reg_macro( menu_t **pp, menu_t **dflt );
char	*cb_menu_unset_key( menu_t **pp, menu_t **dflt );
char	*cb_menu_func( menu_t **pp, menu_t **dflt );
char	*cb_menu_mouse( menu_t **pp, menu_t **dflt );
char	*cb_menu_func_exec( menu_t **pp, menu_t **dflt );
char	*cb_menu_func_edit( menu_t **pp, menu_t **dflt );
char	*cb_menu_func_set_reg_macro( menu_t **pp, menu_t **dflt );
char	*cb_menu_func_unset( menu_t **pp, menu_t **dflt );
long	get_func_draw_n( long n );
char	*cb_menu_mouse_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_mouse_move_crsr_dflt( menu_t **pp, menu_t **dflt );
long	get_cui_mouse_double_click_msec( void );
void	set_cui_mouse_double_click_msec( long msec );
char	*cb_menu_mouse_double_click( menu_t **pp, menu_t **dflt );
char	*cb_menu_audio( menu_t **pp, menu_t **dflt );
char	*cb_menu_music_volume( menu_t **pp, menu_t **dflt );
char	*cb_menu_sound_volume( menu_t **pp, menu_t **dflt );
rate_t	get_music_volume_rate( void );
rate_t	set_music_volume_rate( rate_t rate );
rate_t	get_sound_volume_rate( void );
rate_t	set_sound_volume_rate( rate_t rate );
char	*cb_menu_mute_audio( menu_t **pp, menu_t **dflt );
void	mute_audio( bool_t flg );
char	*cb_menu_replay_music( menu_t **pp, menu_t **dflt );
char	*cb_menu_set_audio_buf_siz( menu_t **pp, menu_t **dflt );
char	*cb_menu_joystick_sel_n_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_joystick_sel_kind_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_joystick_macro_init( menu_t **pp, menu_t **dflt );
char	*cb_menu_joystick_sel_n( menu_t **pp, menu_t **dflt );
char	*cb_menu_joystick_sel_kind( menu_t **pp, menu_t **dflt );
char	*cb_menu_user( menu_t **pp, menu_t **dflt );
void	clr_user_menu( void );
void	add_user_menu( char *name, char *cmd );
char	*get_user_menu_name( long n );
char	*get_user_menu_cmd( long n );
char	*cb_menu_user_sel( menu_t **pp, menu_t **dflt );
char	*cb_menu_user_new( menu_t **pp, menu_t **dflt );
char	*cb_menu_user_new_reg_macro( menu_t **pp, menu_t **dflt );
char	*menu_user_new_sub(
	menu_t **pp, menu_t **dflt, bool_t flg_reg_macro
);
char	*cb_menu_user_arrange_up( menu_t **pp, menu_t **dflt );
char	*cb_menu_user_arrange_down( menu_t **pp, menu_t **dflt );
char	*cb_menu_user_arrange_top( menu_t **pp, menu_t **dflt );
char	*cb_menu_user_arrange_bottom( menu_t **pp, menu_t **dflt );
char	*cb_menu_user_remove( menu_t **pp, menu_t **dflt );
void	set_edit_user_menu( menu_t *ls, menu_call_back_t func, char *ttl );
char	*cb_menu_user_arrange_up_sel( menu_t **pp, menu_t **dflt );
char	*cb_menu_user_arrange_down_sel( menu_t **pp, menu_t **dflt );
char	*arrange_menu_user_1( long n, long d );
char	*cb_menu_user_arrange_top_sel( menu_t **pp, menu_t **dflt );
char	*cb_menu_user_arrange_bottom_sel( menu_t **pp, menu_t **dflt );
char	*cb_menu_user_remove_sel( menu_t **pp, menu_t **dflt );
char	*cb_menu_set_dflt_system( menu_t **pp, menu_t **dflt );
char	*cb_menu_system( menu_t **pp, menu_t **dflt );
char	*cb_menu_replay_load( menu_t **pp, menu_t **dflt );
char	*cb_menu_replay_save( menu_t **pp, menu_t **dflt );
char	*cb_menu_replay_debug( menu_t **pp, menu_t **dflt );
char	*cb_menu_replay_bug_repo( menu_t **pp, menu_t **dflt );
long	menu_replay_sel_load( void );
char	*cb_menu_replay_sel_load( menu_t **pp, menu_t **dflt );
char	*cb_menu_command( menu_t **pp, menu_t **dflt );
char	*cb_menu_set_dflt_wizard( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_teleport_party( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_recall( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_on_light( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_off_light( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_add_turn_hour( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_add_turn_minute( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_add_turn_turn( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_up_exp( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_up_lev( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_scene( menu_t **pp, menu_t **dflt );
char	*cb_menu_wizard_last_scene( menu_t **pp, menu_t **dflt );
char	*cb_menu_out_map_file( menu_t **pp, menu_t **dflt );
char	*cb_menu_shell( menu_t **pp, menu_t **dflt );
char	*cb_menu_about_game( menu_t **pp, menu_t **dflt );
char	*cb_menu_exit( menu_t **pp, menu_t **dflt );
void	set_menu_dflt_misc( menu_t *p );
void	set_menu_dflt_cnf( menu_t *p );
void	set_menu_dflt_system( menu_t *p );
void	set_menu_dflt_wizard( menu_t *p );
bool_t	*get_ls_flg_srch( void );
menu_t	*get_ls_menu_move_crsr( void );
flg_scroll_t	get_flg_scroll( void );
flg_scroll_t	set_flg_scroll( flg_scroll_t flg );
bool_t	get_flg_mbr_data_change_page_is_crsr( void );
void	check_memory_menu_misc_c( void );

#ifdef __cplusplus
}
#endif