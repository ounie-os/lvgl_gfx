/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_cont_1;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_label_3;
	lv_obj_t *screen_label_8;
	lv_obj_t *screen_label_9;
	lv_obj_t *screen_imgbtn_1;
	lv_obj_t *screen_imgbtn_1_label;
	lv_obj_t *screen_cont_2;
	lv_obj_t *screen_label_6;
	lv_obj_t *screen_label_7;
	lv_obj_t *screen_label_10;
	lv_obj_t *screen_label_11;
	lv_obj_t *screen_label_12;
	lv_obj_t *screen_label_13;
	lv_obj_t *screen_label_14;
	lv_obj_t *screen_label_15;
	lv_obj_t *screen_cont_3;
	lv_obj_t *screen_label_16;
	lv_obj_t *screen_label_17;
	lv_obj_t *screen_label_18;
	lv_obj_t *screen_label_19;
	lv_obj_t *screen_label_20;
	lv_obj_t *screen_label_23;
	lv_obj_t *screen_label_24;
	lv_obj_t *screen_label_25;
	lv_obj_t *screen_label_26;
	lv_obj_t *screen_label_27;
	lv_obj_t *screen_cont_4;
	lv_obj_t *screen_label_22;
	lv_obj_t *screen_img_1;
	lv_obj_t *screen_cont_5;
	lv_obj_t *screen_bar_1;
	lv_obj_t *screen_label_28;
	lv_obj_t *screen_label_21;
	lv_obj_t *screen_1;
	bool screen_1_del;
	lv_obj_t *screen_1_tabview_1;
	lv_obj_t *screen_1_tabview_1_tab_1;
	lv_obj_t *screen_1_tabview_1_tab_2;
	lv_obj_t *screen_1_tabview_1_tab_3;
	lv_obj_t *screen_1_tabview_1_tab_4;
	lv_obj_t *screen_1_tabview_2;
	lv_obj_t *screen_1_tabview_2_tab_1;
	lv_obj_t *screen_1_tabview_2_tab_2;
	lv_obj_t *screen_1_tabview_2_tab_3;
	lv_obj_t *screen_1_tabview_2_tab_4;
	lv_obj_t *screen_1_tabview_2_tab_5;
	lv_obj_t *screen_1_label_125;
	lv_obj_t *screen_1_label_124;
	lv_obj_t *screen_1_label_123;
	lv_obj_t *screen_1_label_122;
	lv_obj_t *screen_1_ta_64;
	lv_obj_t *screen_1_btn_35;
	lv_obj_t *screen_1_btn_35_label;
	lv_obj_t *screen_1_btn_34;
	lv_obj_t *screen_1_btn_34_label;
	lv_obj_t *screen_1_btn_33;
	lv_obj_t *screen_1_btn_33_label;
	lv_obj_t *screen_1_label_121;
	lv_obj_t *screen_1_label_120;
	lv_obj_t *screen_1_ta_63;
	lv_obj_t *screen_1_ta_62;
	lv_obj_t *screen_1_ta_61;
	lv_obj_t *screen_1_label_119;
	lv_obj_t *screen_1_label_118;
	lv_obj_t *screen_1_label_117;
	lv_obj_t *screen_1_label_116;
	lv_obj_t *screen_1_ta_60;
	lv_obj_t *screen_1_ta_59;
	lv_obj_t *screen_1_label_115;
	lv_obj_t *screen_1_label_114;
	lv_obj_t *screen_1_label_113;
	lv_obj_t *screen_1_label_112;
	lv_obj_t *screen_1_label_111;
	lv_obj_t *screen_1_btn_32;
	lv_obj_t *screen_1_btn_32_label;
	lv_obj_t *screen_1_label_126;
	lv_obj_t *screen_1_label_127;
	lv_obj_t *screen_1_label_128;
	lv_obj_t *screen_1_label_107;
	lv_obj_t *screen_1_label_106;
	lv_obj_t *screen_1_label_105;
	lv_obj_t *screen_1_label_104;
	lv_obj_t *screen_1_ta_58;
	lv_obj_t *screen_1_btn_31;
	lv_obj_t *screen_1_btn_31_label;
	lv_obj_t *screen_1_btn_30;
	lv_obj_t *screen_1_btn_30_label;
	lv_obj_t *screen_1_btn_29;
	lv_obj_t *screen_1_btn_29_label;
	lv_obj_t *screen_1_label_103;
	lv_obj_t *screen_1_label_102;
	lv_obj_t *screen_1_ta_57;
	lv_obj_t *screen_1_ta_56;
	lv_obj_t *screen_1_ta_55;
	lv_obj_t *screen_1_label_101;
	lv_obj_t *screen_1_label_100;
	lv_obj_t *screen_1_label_99;
	lv_obj_t *screen_1_label_98;
	lv_obj_t *screen_1_ta_54;
	lv_obj_t *screen_1_ta_53;
	lv_obj_t *screen_1_label_97;
	lv_obj_t *screen_1_label_96;
	lv_obj_t *screen_1_label_95;
	lv_obj_t *screen_1_label_94;
	lv_obj_t *screen_1_label_93;
	lv_obj_t *screen_1_btn_28;
	lv_obj_t *screen_1_btn_28_label;
	lv_obj_t *screen_1_label_92;
	lv_obj_t *screen_1_ta_52;
	lv_obj_t *screen_1_label_91;
	lv_obj_t *screen_1_label_108;
	lv_obj_t *screen_1_label_109;
	lv_obj_t *screen_1_label_110;
	lv_obj_t *screen_1_label_141;
	lv_obj_t *screen_1_label_140;
	lv_obj_t *screen_1_label_139;
	lv_obj_t *screen_1_btn_39;
	lv_obj_t *screen_1_btn_39_label;
	lv_obj_t *screen_1_btn_38;
	lv_obj_t *screen_1_btn_38_label;
	lv_obj_t *screen_1_btn_37;
	lv_obj_t *screen_1_btn_37_label;
	lv_obj_t *screen_1_label_138;
	lv_obj_t *screen_1_ta_69;
	lv_obj_t *screen_1_ta_68;
	lv_obj_t *screen_1_ta_67;
	lv_obj_t *screen_1_label_137;
	lv_obj_t *screen_1_label_136;
	lv_obj_t *screen_1_label_135;
	lv_obj_t *screen_1_label_134;
	lv_obj_t *screen_1_ta_66;
	lv_obj_t *screen_1_ta_65;
	lv_obj_t *screen_1_label_133;
	lv_obj_t *screen_1_label_132;
	lv_obj_t *screen_1_label_131;
	lv_obj_t *screen_1_label_130;
	lv_obj_t *screen_1_label_129;
	lv_obj_t *screen_1_btn_36;
	lv_obj_t *screen_1_btn_36_label;
	lv_obj_t *screen_1_label_142;
	lv_obj_t *screen_1_label_143;
	lv_obj_t *screen_1_label_144;
	lv_obj_t *screen_1_label_149;
	lv_obj_t *screen_1_label_148;
	lv_obj_t *screen_1_label_147;
	lv_obj_t *screen_1_label_146;
	lv_obj_t *screen_1_ta_71;
	lv_obj_t *screen_1_label_145;
	lv_obj_t *screen_1_ta_70;
	lv_obj_t *screen_1_btn_40;
	lv_obj_t *screen_1_btn_40_label;
	lv_obj_t *screen_1_label_150;
	lv_obj_t *screen_1_label_151;
	lv_obj_t *screen_1_label_157;
	lv_obj_t *screen_1_label_156;
	lv_obj_t *screen_1_ta_73;
	lv_obj_t *screen_1_label_155;
	lv_obj_t *screen_1_label_154;
	lv_obj_t *screen_1_ta_72;
	lv_obj_t *screen_1_label_153;
	lv_obj_t *screen_1_btn_41;
	lv_obj_t *screen_1_btn_41_label;
	lv_obj_t *screen_1_label_152;
	lv_obj_t *screen_1_label_158;
	lv_obj_t *screen_1_cont_7;
	lv_obj_t *screen_1_label_62;
	lv_obj_t *screen_1_label_63;
	lv_obj_t *screen_1_label_64;
	lv_obj_t *screen_1_ta_38;
	lv_obj_t *screen_1_label_65;
	lv_obj_t *screen_1_ta_39;
	lv_obj_t *screen_1_label_66;
	lv_obj_t *screen_1_label_67;
	lv_obj_t *screen_1_label_68;
	lv_obj_t *screen_1_ddlist_2;
	lv_obj_t *screen_1_ta_40;
	lv_obj_t *screen_1_ta_41;
	lv_obj_t *screen_1_label_69;
	lv_obj_t *screen_1_sw_1;
	lv_obj_t *screen_1_label_70;
	lv_obj_t *screen_1_btn_15;
	lv_obj_t *screen_1_btn_15_label;
	lv_obj_t *screen_1_btn_16;
	lv_obj_t *screen_1_btn_16_label;
	lv_obj_t *screen_1_btn_17;
	lv_obj_t *screen_1_btn_17_label;
	lv_obj_t *screen_1_ddlist_1;
	lv_obj_t *screen_1_btn_19;
	lv_obj_t *screen_1_btn_19_label;
	lv_obj_t *screen_1_btn_21;
	lv_obj_t *screen_1_btn_21_label;
	lv_obj_t *screen_1_btn_22;
	lv_obj_t *screen_1_btn_22_label;
	lv_obj_t *screen_1_imgbtn_2;
	lv_obj_t *screen_1_imgbtn_2_label;
	lv_obj_t *screen_1_canvas_1;
	lv_obj_t *screen_1_img_1;
	lv_obj_t *screen_1_cont_8;
	lv_obj_t *screen_1_label_71;
	lv_obj_t *screen_1_ddlist_3;
	lv_obj_t *screen_1_label_72;
	lv_obj_t *screen_1_label_73;
	lv_obj_t *screen_1_label_74;
	lv_obj_t *screen_1_label_75;
	lv_obj_t *screen_1_label_76;
	lv_obj_t *screen_1_label_77;
	lv_obj_t *screen_1_ta_42;
	lv_obj_t *screen_1_ta_43;
	lv_obj_t *screen_1_ta_44;
	lv_obj_t *screen_1_ta_45;
	lv_obj_t *screen_1_ddlist_4;
	lv_obj_t *screen_1_table_1;
	lv_obj_t *screen_1_btn_23;
	lv_obj_t *screen_1_btn_23_label;
	lv_obj_t *screen_1_btn_24;
	lv_obj_t *screen_1_btn_24_label;
	lv_obj_t *screen_1_btn_25;
	lv_obj_t *screen_1_btn_25_label;
	lv_obj_t *screen_1_ddlist_7;
	lv_obj_t *screen_1_label_171;
	lv_obj_t *screen_1_ddlist_6;
	lv_obj_t *screen_1_btn_43;
	lv_obj_t *screen_1_btn_43_label;
	lv_obj_t *screen_1_label_170;
	lv_obj_t *screen_1_ta_78;
	lv_obj_t *screen_1_label_169;
	lv_obj_t *screen_1_label_168;
	lv_obj_t *screen_1_label_167;
	lv_obj_t *screen_1_label_166;
	lv_obj_t *screen_1_ta_77;
	lv_obj_t *screen_1_label_165;
	lv_obj_t *screen_1_ta_76;
	lv_obj_t *screen_1_label_164;
	lv_obj_t *screen_1_label_163;
	lv_obj_t *screen_1_ta_75;
	lv_obj_t *screen_1_label_162;
	lv_obj_t *screen_1_label_161;
	lv_obj_t *screen_1_ddlist_5;
	lv_obj_t *screen_1_label_160;
	lv_obj_t *screen_1_btn_42;
	lv_obj_t *screen_1_btn_42_label;
	lv_obj_t *screen_1_label_159;
	lv_obj_t *screen_1_ta_74;
	lv_obj_t *screen_1_label_1;
	lv_obj_t *screen_1_imgbtn_1;
	lv_obj_t *screen_1_imgbtn_1_label;
	lv_obj_t *g_kb_top_layer;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);
void setup_scr_screen_1(lv_ui *ui);
LV_IMG_DECLARE(_setting_alpha_48x45);
LV_IMG_DECLARE(_camera_alpha_69x66);
LV_IMG_DECLARE(_return_alpha_44x40);

LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_12)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_18)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_15)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_20)


#ifdef __cplusplus
}
#endif
#endif
