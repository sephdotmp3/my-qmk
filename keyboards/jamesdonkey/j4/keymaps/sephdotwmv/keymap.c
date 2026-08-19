/* Copyright 2024 @ James Donkey
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

#include QMK_KEYBOARD_H
#include "common.h"

enum layers {
    _BASE,
    _FN,
    _MEH_ISH
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi_87(
        KC_ESC,                       KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,         KC_F6,         KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_F11,        KC_F12,         KC_PSCR,       KC_SCRL,       KC_PAUSE,
        KC_GRV,        KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          KC_MINS,       KC_EQL,        KC_BSPC,        KC_INS,        KC_HOME,       KC_PGUP,
        KC_TAB,        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_LBRC,       KC_RBRC,       KC_BSLS,        KC_DEL,        KC_END,        KC_PGDN,
        KC_CAPS,       KC_A,          KC_S,          KC_D,          KC_F,          KC_G,          KC_H,          KC_J,          KC_K,          KC_L,          KC_SCLN,       KC_QUOT,                      KC_ENT,
        KC_LSFT,                      KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_N,          KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,                      KC_RSFT,                       KC_UP,
        KC_LCTL,       KC_LGUI,       KC_LALT,                                                    KC_SPC,                                                     KC_RALT,       MO(_FN),       MO(_MEH_ISH),  KC_RCTL,        KC_LEFT,       KC_DOWN,       KC_RGHT),

    [_FN] = LAYOUT_ansi_87(
        _______,                      KC_BRID,       KC_BRIU,       KC_TASK,       KC_FILE,       RGB_VAD,       RGB_VAI,       KC_MPRV,       KC_MPLY,       KC_MNXT,       KC_MUTE,       KC_VOLD,       KC_VOLU,        KC_PSCR,       KC_CTANA,      RGB_TOG,
        _______,       BT_HST1,       BT_HST2,       BT_HST3,       P2P4G,         _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,        _______,       _______,       _______,
        RGB_TOG,       RGB_MOD,       RGB_VAI,       RGB_HUI,       RGB_SAI,       RGB_SPI,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,        _______,       _______,       _______,
        _______,       RGB_RMOD,      RGB_VAD,       RGB_HUD,       RGB_SAD,       RGB_SPD,       _______,       _______,       _______,       _______,       _______,       _______,                      _______,
        _______,                      _______,       _______,       _______,       _______,       BAT_LVL,       NK_TOGG,       _______,       _______,       _______,       _______,                      _______,                       _______,
        _______,       GU_TOGG,       _______,                                                    _______,                                                    _______,       _______,       _______,       _______,        _______,       _______,       _______),

    [_MEH_ISH] = LAYOUT_ansi_87(
        MEH(KC_ESC),                  MEH(KC_F1),    MEH(KC_F2),    MEH(KC_F3),    MEH(KC_F4),    MEH(KC_F5),    MEH(KC_F6),    MEH(KC_F7),    MEH(KC_F8),    MEH(KC_F9),    MEH(KC_F10),   MEH(KC_F11),   MEH(KC_F12),    KC_PSCR,       KC_SCRL,       KC_PAUSE,
        MEH(KC_GRV),   MEH(KC_1),     MEH(KC_2),     MEH(KC_3),     MEH(KC_4),     MEH(KC_5),     MEH(KC_6),     MEH(KC_7),     MEH(KC_8),     MEH(KC_9),     MEH(KC_0),     MEH(KC_MINS),  MEH(KC_EQL),   _______,        MEH(KC_INS),   MEH(KC_HOME),  MEH(KC_PGUP),
        MEH(KC_TAB),   MEH(KC_Q),     MEH(KC_W),     MEH(KC_E),     MEH(KC_R),     MEH(KC_T),     MEH(KC_Y),     MEH(KC_U),     MEH(KC_I),     MEH(KC_O),     MEH(KC_P),     MEH(KC_LBRC),  MEH(KC_RBRC),  MEH(KC_BSLS),   MEH(KC_DEL),   MEH(KC_END),   MEH(KC_PGDN),
        _______,       MEH(KC_A),     MEH(KC_S),     MEH(KC_D),     MEH(KC_F),     MEH(KC_G),     MEH(KC_H),     MEH(KC_J),     MEH(KC_K),     MEH(KC_L),     MEH(KC_SCLN),  MEH(KC_QUOT),                 _______,
        _______,                      MEH(KC_Z),     MEH(KC_X),     MEH(KC_C),     MEH(KC_V),     MEH(KC_B),     MEH(KC_N),     MEH(KC_M),     MEH(KC_COMM),  MEH(KC_DOT),   MEH(KC_SLSH),                 _______,                       MEH(KC_UP),
        _______,       _______,       _______,                                                    MEH(KC_SPC),                                                _______,       _______,       _______,       _______,        MEH(KC_LEFT),  MEH(KC_DOWN),  MEH(KC_RGHT)),
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_common(keycode, record)) {
        return false;
    }

    return true;
}
