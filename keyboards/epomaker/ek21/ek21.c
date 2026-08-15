/* Copyright 2025 Epomaker
 * Copyright 2025 Epomaker <https://github.com/Epomaker>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../lib/rdr_lib/rdr_common.h"

void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

led_config_t g_led_config = { {
	{ NO_LED   , 1        , 2        , 3        , 4        , 0         },
    { 5        , 6        , 7        , 8        , NO_LED   , NO_LED    },
	{ 9        , 10       , 11       , 12       , NO_LED   , NO_LED    },
	{ 13       , 14       , 15       , NO_LED   , NO_LED   , NO_LED    },
	{ 16       , NO_LED   , 17       , 18       , NO_LED   , NO_LED    },
	{ 19       , 20       , 21       , NO_LED   , NO_LED   , NO_LED    }
},{
    { 82,  10},  { 102, 10},  { 122, 10},  { 132, 10}, { 142, 10},
    { 82,  20},  { 102, 20},  { 122, 20},  { 142, 20},
    { 82,  30},  { 102, 30},  { 122, 30},  { 142, 30},
    { 82,  40},  { 102, 40},  { 122, 40},
    { 82,  50},  { 102, 50},  { 122, 50},
                 {  92, 60},  { 122, 60},  { 142, 60}
}, {
    1,  1,  1,  1,  1,
    1,  1,  1,  1,
    1,  1,  1,  1,
    1,  1,  1,
    1,  1,  1,
        1,  1,  1
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();
    return false;
}

void notify_usb_device_state_change_user(enum usb_device_state usb_device_state)  {
    if (Keyboard_Info.Key_Mode == QMK_USB_MODE) {
        if(usb_device_state == USB_DEVICE_STATE_CONFIGURED) {
            Usb_If_Ok = true;//usb枚举完成
            Usb_If_Ok_Led = true;
            Usb_If_Ok_Delay = 0;
        } else {
            Usb_If_Ok = false;
		    Usb_If_Ok_Led = false;
        }
    } else {
        Usb_If_Ok = false;
	    Usb_If_Ok_Led = false;
    }
}

void housekeeping_task_user(void) {
    User_Keyboard_Reset();
    es_chibios_user_idle_loop_hook();
}

void board_init(void) {
    User_Keyboard_Init();
}

void keyboard_post_init_user(void) {
    User_Keyboard_Post_Init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {   /*键盘只要有按键按下就会调用此函数*/
    Usb_Change_Mode_Delay = 0;                                      /*只要有按键就不会进入休眠*/
    Usb_Change_Mode_Wakeup = false;

    return Key_Value_Dispose(keycode, record);
}