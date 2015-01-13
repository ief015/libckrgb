#include "keyboard.h"
#include <stdlib.h>
#include <memory.h>

unsigned char keymap_us[CKRGB_KEY_COUNT+2] = {
	0x0F,
	0x4C,
	0x34,
	0x27,
	0x26,
	0x33,
	0x3F,
	0x4B,
	0x62,
	0x57,
	0x63,
	0x6F,
	0x64,
	0x58,
	0x6E,
	0x7A,
	0x0E,
	0x32,
	0x1B,
	0x3E,
	0x56,
	0x40,
	0x1A,
	0x28,
	0x4A,
	0x1C,
	0x0C,
	0x18,
	0x24,
	0x30,
	0x3C,
	0x48,
	0x54,
	0x60,
	0x6C,
	0x78,
	0x84,
	0x06,
	0x79,
	0x0D,
	0x19,
	0x25,
	0x31,
	0x3D,
	0x49,
	0x55,
	0x61,
	0x6D,
	0x85,
	0x07,
	0x81,
	0x5D,
	0x69,
	0x75,
	0x39,
	0x45,
	0x51,
	0x09,
	0x15,
	0x21,
	0x50,
	0x5C,
	0x68,
	0x74,
	0x80,
	0x8C,
	0x8D,
	0x67,
	0x7F,
	0x73,
	0x8B,
	0x20,
	0x2C,
	0x38,
	0x44,
	0x14,
	0xFF, //> TODO: keycode for VOLUMEUP
	0xFF, //> TODO: keycode for VOLUMEDOWN
	0x2B,
	0x36,
	0x37,
	0x42,
	0x43,
	0x4E,
	0x04,
	0x4F,
	0x05,
	0x5B,
	0x66,
	0x88,
	0x11,
	0x65,
	0x1D,
	0x59,
	0x5A,
	0x86,
	0x12,
	0x1E,
	0x2A,
	0x08,
	0x89,
	0x70,
	0x7C,
	0xFF, //> Hash is not found on US keyboards
	0x7B,
	0x00,
	0x01,
	0x02,
	0x03,
	0x1F,
	0x7E,
	0x35,
	0x71,
	0x87,
	0x0b,
	0x17,
	0x23,
	0x2f,
	0x0a,
	0x16,
	0x22,
	0x2e,
	0x3a,
	0x46,
	0x52,
	0x5e,
	0x6a,
	0x76,
	0x3b,
	0x47,
	0x53,
	0x5f,
	0x6b,
	0x77,
	0x83,
	0x8f,

	0xFF, //> Include COUNT as nonexistant key.
	0xFF  //> Include MISSING as nonexistant key.
};

unsigned char keymap_uk[CKRGB_KEY_COUNT+2] = {
	0x0F,
	0x4C,
	0x34,
	0x27,
	0x26,
	0x33,
	0x3F,
	0x4B,
	0x62,
	0x57,
	0x63,
	0x6F,
	0x64,
	0x58,
	0x6E,
	0x7A,
	0x0E,
	0x32,
	0x1B,
	0x3E,
	0x56,
	0x40,
	0x1A,
	0x28,
	0x4A,
	0x1C,
	0x0C,
	0x18,
	0x24,
	0x30,
	0x3C,
	0x48,
	0x54,
	0x60,
	0x6C,
	0x78,
	0x84,
	0x06,
	0x79,
	0x0D,
	0x19,
	0x25,
	0x31,
	0x3D,
	0x49,
	0x55,
	0x61,
	0x6D,
	0x85,
	0x07,
	0x81,
	0x5D,
	0x69,
	0x75,
	0x39,
	0x45,
	0x51,
	0x09,
	0x15,
	0x21,
	0x50,
	0x5C,
	0x68,
	0x74,
	0x80,
	0x8C,
	0x8D,
	0x67,
	0x7F,
	0x73,
	0x8B,
	0x20,
	0x2C,
	0x38,
	0x44,
	0x14,
	0xFF, //> TODO: keycode for VOLUMEUP
	0xFF, //> TODO: keycode for VOLUMEDOWN
	0x2B,
	0x36,
	0x37,
	0x42,
	0x43,
	0x4E,
	0x04,
	0x4F,
	0x05,
	0x5B,
	0x66,
	0x88,
	0x11,
	0x65,
	0x1D,
	0x59,
	0x5A,
	0x86,
	0x12,
	0x1E,
	0x2A,
	0x08,
	0x89,
	0x70,
	0x7C,
	0x72,
	0x7B,
	0x00,
	0x01,
	0x02,
	0x03,
	0x1F,
	0x7E,
	0x35,
	0x71,
	0x87,
	0x0b,
	0x17,
	0x23,
	0x2f,
	0x0a,
	0x16,
	0x22,
	0x2e,
	0x3a,
	0x46,
	0x52,
	0x5e,
	0x6a,
	0x76,
	0x3b,
	0x47,
	0x53,
	0x5f,
	0x6b,
	0x77,
	0x83,
	0x8f,

	0xFF, //> Include COUNT as nonexistant key.
	0xFF  //> Include MISSING as nonexistant key.
};

#define K_HEIGHT  7
#define K65_WIDTH 18
#define K70_WIDTH 22
#define K95_WIDTH 25

enum ckrgb_key key_matrix_us_k65[K_HEIGHT][K65_WIDTH] = {
  {CKRGB_KEY_MISSING,  CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING,   CKRGB_KEY_BRIGHTNESS,   CKRGB_KEY_MUTE,        CKRGB_KEY_VOLUMEDOWN, CKRGB_KEY_VOLUMEUP,  CKRGB_KEY_WINLOCK,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING},
  {CKRGB_KEY_ESCAPE,   CKRGB_KEY_MISSING, CKRGB_KEY_F1,      CKRGB_KEY_F2,      CKRGB_KEY_F3,      CKRGB_KEY_F4,      CKRGB_KEY_F5,      CKRGB_KEY_F6,      CKRGB_KEY_F7,      CKRGB_KEY_F8,      CKRGB_KEY_MISSING,   CKRGB_KEY_F9,           CKRGB_KEY_F10,         CKRGB_KEY_F11,        CKRGB_KEY_F12,       CKRGB_KEY_PRINTSCREEN, CKRGB_KEY_SCOLLLOCK, CKRGB_KEY_PAUSEBREAK},
  {CKRGB_KEY_TILDE,    CKRGB_KEY_NUM1,    CKRGB_KEY_NUM2,    CKRGB_KEY_NUM3,    CKRGB_KEY_NUM4,    CKRGB_KEY_NUM5,    CKRGB_KEY_NUM6,    CKRGB_KEY_NUM7,    CKRGB_KEY_NUM8,    CKRGB_KEY_NUM9,    CKRGB_KEY_NUM0,      CKRGB_KEY_MINUS,        CKRGB_KEY_EQUALS,      CKRGB_KEY_BACKSPACE,  CKRGB_KEY_BACKSPACE, CKRGB_KEY_INSERT,      CKRGB_KEY_HOME,      CKRGB_KEY_PAGEUP},
  {CKRGB_KEY_TAB,      CKRGB_KEY_Q,       CKRGB_KEY_W,       CKRGB_KEY_E,       CKRGB_KEY_R,       CKRGB_KEY_T,       CKRGB_KEY_Y,       CKRGB_KEY_U,       CKRGB_KEY_I,       CKRGB_KEY_O,       CKRGB_KEY_P,         CKRGB_KEY_LBRACKET,     CKRGB_KEY_RBRACKET,    CKRGB_KEY_MISSING,    CKRGB_KEY_BACKSLASH, CKRGB_KEY_DELETE,      CKRGB_KEY_END,       CKRGB_KEY_PAGEDOWN},
  {CKRGB_KEY_CAPSLOCK, CKRGB_KEY_A,       CKRGB_KEY_S,       CKRGB_KEY_D,       CKRGB_KEY_F,       CKRGB_KEY_G,       CKRGB_KEY_H,       CKRGB_KEY_J,       CKRGB_KEY_K,       CKRGB_KEY_L,       CKRGB_KEY_SEMICOLON, CKRGB_KEY_QUOTE,        CKRGB_KEY_ENTER,       CKRGB_KEY_ENTER,      CKRGB_KEY_ENTER,     CKRGB_KEY_MISSING,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING},
  {CKRGB_KEY_LSHIFT,   CKRGB_KEY_MISSING, CKRGB_KEY_Z,       CKRGB_KEY_X,       CKRGB_KEY_C,       CKRGB_KEY_V,       CKRGB_KEY_B,       CKRGB_KEY_N,       CKRGB_KEY_M,       CKRGB_KEY_COMMA,   CKRGB_KEY_PERIOD,    CKRGB_KEY_FORWARDSLASH, CKRGB_KEY_RSHIFT,      CKRGB_KEY_RSHIFT,     CKRGB_KEY_RSHIFT,    CKRGB_KEY_MISSING,     CKRGB_KEY_ARROWUP,   CKRGB_KEY_MISSING},
  {CKRGB_KEY_LCTRL,    CKRGB_KEY_LSYSTEM, CKRGB_KEY_LALT,    CKRGB_KEY_LALT,    CKRGB_KEY_MISSING, CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_RALT,      CKRGB_KEY_RSYSTEM,      CKRGB_KEY_CONTEXTMENU, CKRGB_KEY_RCTRL,      CKRGB_KEY_RCTRL,     CKRGB_KEY_ARROWLEFT,   CKRGB_KEY_ARROWDOWN, CKRGB_KEY_ARROWRIGHT}
};

enum ckrgb_key key_matrix_us_k70[K_HEIGHT][K70_WIDTH] = {
  {CKRGB_KEY_MISSING,  CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,      CKRGB_KEY_MISSING,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,   CKRGB_KEY_BRIGHTNESS,  CKRGB_KEY_WINLOCK,   CKRGB_KEY_MISSING,    CKRGB_KEY_MISSING,     CKRGB_KEY_MUTE,         CKRGB_KEY_MISSING,        CKRGB_KEY_MISSING},
  {CKRGB_KEY_ESCAPE,   CKRGB_KEY_MISSING, CKRGB_KEY_F1,      CKRGB_KEY_F2,      CKRGB_KEY_F3,      CKRGB_KEY_F4,      CKRGB_KEY_F5,      CKRGB_KEY_F6,      CKRGB_KEY_F7,      CKRGB_KEY_F8,      CKRGB_KEY_MISSING,   CKRGB_KEY_F9,           CKRGB_KEY_F10,         CKRGB_KEY_F11,       CKRGB_KEY_F12,       CKRGB_KEY_PRINTSCREEN, CKRGB_KEY_SCOLLLOCK, CKRGB_KEY_PAUSEBREAK, CKRGB_KEY_MEDIASTOP,   CKRGB_KEY_MEDIAPREV,    CKRGB_KEY_MEDIAPLAYPAUSE, CKRGB_KEY_MEDIANEXT},
  {CKRGB_KEY_TILDE,    CKRGB_KEY_NUM1,    CKRGB_KEY_NUM2,    CKRGB_KEY_NUM3,    CKRGB_KEY_NUM4,    CKRGB_KEY_NUM5,    CKRGB_KEY_NUM6,    CKRGB_KEY_NUM7,    CKRGB_KEY_NUM8,    CKRGB_KEY_NUM9,    CKRGB_KEY_NUM0,      CKRGB_KEY_MINUS,        CKRGB_KEY_EQUALS,      CKRGB_KEY_BACKSPACE, CKRGB_KEY_BACKSPACE, CKRGB_KEY_INSERT,      CKRGB_KEY_HOME,      CKRGB_KEY_PAGEUP,     CKRGB_KEY_NUMLOCK,     CKRGB_KEY_NUMPADDIVIDE, CKRGB_KEY_NUMPADMULTIPLY, CKRGB_KEY_NUMPADMINUS},
  {CKRGB_KEY_TAB,      CKRGB_KEY_Q,       CKRGB_KEY_W,       CKRGB_KEY_E,       CKRGB_KEY_R,       CKRGB_KEY_T,       CKRGB_KEY_Y,       CKRGB_KEY_U,       CKRGB_KEY_I,       CKRGB_KEY_O,       CKRGB_KEY_P,         CKRGB_KEY_LBRACKET,     CKRGB_KEY_RBRACKET,    CKRGB_KEY_MISSING,   CKRGB_KEY_BACKSLASH, CKRGB_KEY_DELETE,      CKRGB_KEY_END,       CKRGB_KEY_PAGEDOWN,   CKRGB_KEY_NUMPAD7,     CKRGB_KEY_NUMPAD8,      CKRGB_KEY_NUMPAD9,        CKRGB_KEY_NUMPADPLUS},
  {CKRGB_KEY_CAPSLOCK, CKRGB_KEY_A,       CKRGB_KEY_S,       CKRGB_KEY_D,       CKRGB_KEY_F,       CKRGB_KEY_G,       CKRGB_KEY_H,       CKRGB_KEY_J,       CKRGB_KEY_K,       CKRGB_KEY_L,       CKRGB_KEY_SEMICOLON, CKRGB_KEY_QUOTE,        CKRGB_KEY_ENTER,       CKRGB_KEY_ENTER,     CKRGB_KEY_ENTER,     CKRGB_KEY_MISSING,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,    CKRGB_KEY_NUMPAD4,     CKRGB_KEY_NUMPAD5,      CKRGB_KEY_NUMPAD6,        CKRGB_KEY_NUMPADPLUS},
  {CKRGB_KEY_LSHIFT,   CKRGB_KEY_MISSING, CKRGB_KEY_Z,       CKRGB_KEY_X,       CKRGB_KEY_C,       CKRGB_KEY_V,       CKRGB_KEY_B,       CKRGB_KEY_N,       CKRGB_KEY_M,       CKRGB_KEY_COMMA,   CKRGB_KEY_PERIOD,    CKRGB_KEY_FORWARDSLASH, CKRGB_KEY_RSHIFT,      CKRGB_KEY_RSHIFT,    CKRGB_KEY_RSHIFT,    CKRGB_KEY_MISSING,     CKRGB_KEY_ARROWUP,   CKRGB_KEY_MISSING,    CKRGB_KEY_NUMPAD1,     CKRGB_KEY_NUMPAD2,      CKRGB_KEY_NUMPAD3,        CKRGB_KEY_NUMPADENTER},
  {CKRGB_KEY_LCTRL,    CKRGB_KEY_LSYSTEM, CKRGB_KEY_LALT,    CKRGB_KEY_LALT,    CKRGB_KEY_MISSING, CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_RALT,      CKRGB_KEY_RSYSTEM,      CKRGB_KEY_CONTEXTMENU, CKRGB_KEY_RCTRL,     CKRGB_KEY_RCTRL,     CKRGB_KEY_ARROWLEFT,   CKRGB_KEY_ARROWDOWN, CKRGB_KEY_ARROWRIGHT, CKRGB_KEY_NUMPAD0,     CKRGB_KEY_NUMPAD0,      CKRGB_KEY_NUMPADDECIMAL,  CKRGB_KEY_NUMPADENTER}
};

enum ckrgb_key key_matrix_us_k95[K_HEIGHT][K95_WIDTH] = {
  {CKRGB_KEY_MISSING,  CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MACRORECORD, CKRGB_KEY_MACROMODE1, CKRGB_KEY_MACROMODE2, CKRGB_KEY_MACROMODE3, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,      CKRGB_KEY_MISSING,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,   CKRGB_KEY_BRIGHTNESS,  CKRGB_KEY_WINLOCK,   CKRGB_KEY_MISSING,    CKRGB_KEY_MISSING,     CKRGB_KEY_MUTE,         CKRGB_KEY_MISSING,        CKRGB_KEY_MISSING},
  {CKRGB_KEY_G1,       CKRGB_KEY_G2,      CKRGB_KEY_G3,      CKRGB_KEY_ESCAPE,      CKRGB_KEY_MISSING,    CKRGB_KEY_F1,         CKRGB_KEY_F2,         CKRGB_KEY_F3,      CKRGB_KEY_F4,      CKRGB_KEY_F5,      CKRGB_KEY_F6,      CKRGB_KEY_F7,      CKRGB_KEY_F8,      CKRGB_KEY_MISSING,   CKRGB_KEY_F9,           CKRGB_KEY_F10,         CKRGB_KEY_F11,       CKRGB_KEY_F12,       CKRGB_KEY_PRINTSCREEN, CKRGB_KEY_SCOLLLOCK, CKRGB_KEY_PAUSEBREAK, CKRGB_KEY_MEDIASTOP,   CKRGB_KEY_MEDIAPREV,    CKRGB_KEY_MEDIAPLAYPAUSE, CKRGB_KEY_MEDIANEXT},
  {CKRGB_KEY_G4,       CKRGB_KEY_G5,      CKRGB_KEY_G6,      CKRGB_KEY_TILDE,       CKRGB_KEY_NUM1,       CKRGB_KEY_NUM2,       CKRGB_KEY_NUM3,       CKRGB_KEY_NUM4,    CKRGB_KEY_NUM5,    CKRGB_KEY_NUM6,    CKRGB_KEY_NUM7,    CKRGB_KEY_NUM8,    CKRGB_KEY_NUM9,    CKRGB_KEY_NUM0,      CKRGB_KEY_MINUS,        CKRGB_KEY_EQUALS,      CKRGB_KEY_BACKSPACE, CKRGB_KEY_BACKSPACE, CKRGB_KEY_INSERT,      CKRGB_KEY_HOME,      CKRGB_KEY_PAGEUP,     CKRGB_KEY_NUMLOCK,     CKRGB_KEY_NUMPADDIVIDE, CKRGB_KEY_NUMPADMULTIPLY, CKRGB_KEY_NUMPADMINUS},
  {CKRGB_KEY_G7,       CKRGB_KEY_G8,      CKRGB_KEY_G9,      CKRGB_KEY_TAB,         CKRGB_KEY_Q,          CKRGB_KEY_W,          CKRGB_KEY_E,          CKRGB_KEY_R,       CKRGB_KEY_T,       CKRGB_KEY_Y,       CKRGB_KEY_U,       CKRGB_KEY_I,       CKRGB_KEY_O,       CKRGB_KEY_P,         CKRGB_KEY_LBRACKET,     CKRGB_KEY_RBRACKET,    CKRGB_KEY_MISSING,   CKRGB_KEY_BACKSLASH, CKRGB_KEY_DELETE,      CKRGB_KEY_END,       CKRGB_KEY_PAGEDOWN,   CKRGB_KEY_NUMPAD7,     CKRGB_KEY_NUMPAD8,      CKRGB_KEY_NUMPAD9,        CKRGB_KEY_NUMPADPLUS},
  {CKRGB_KEY_G10,      CKRGB_KEY_G11,     CKRGB_KEY_G12,     CKRGB_KEY_CAPSLOCK,    CKRGB_KEY_A,          CKRGB_KEY_S,          CKRGB_KEY_D,          CKRGB_KEY_F,       CKRGB_KEY_G,       CKRGB_KEY_H,       CKRGB_KEY_J,       CKRGB_KEY_K,       CKRGB_KEY_L,       CKRGB_KEY_SEMICOLON, CKRGB_KEY_QUOTE,        CKRGB_KEY_ENTER,       CKRGB_KEY_ENTER,     CKRGB_KEY_ENTER,     CKRGB_KEY_MISSING,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,    CKRGB_KEY_NUMPAD4,     CKRGB_KEY_NUMPAD5,      CKRGB_KEY_NUMPAD6,        CKRGB_KEY_NUMPADPLUS},
  {CKRGB_KEY_G13,      CKRGB_KEY_G14,     CKRGB_KEY_G15,     CKRGB_KEY_LSHIFT,      CKRGB_KEY_MISSING,    CKRGB_KEY_Z,          CKRGB_KEY_X,          CKRGB_KEY_C,       CKRGB_KEY_V,       CKRGB_KEY_B,       CKRGB_KEY_N,       CKRGB_KEY_M,       CKRGB_KEY_COMMA,   CKRGB_KEY_PERIOD,    CKRGB_KEY_FORWARDSLASH, CKRGB_KEY_RSHIFT,      CKRGB_KEY_RSHIFT,    CKRGB_KEY_RSHIFT,    CKRGB_KEY_MISSING,     CKRGB_KEY_ARROWUP,   CKRGB_KEY_MISSING,    CKRGB_KEY_NUMPAD1,     CKRGB_KEY_NUMPAD2,      CKRGB_KEY_NUMPAD3,        CKRGB_KEY_NUMPADENTER},
  {CKRGB_KEY_G16,      CKRGB_KEY_G17,     CKRGB_KEY_G18,     CKRGB_KEY_LCTRL,       CKRGB_KEY_LSYSTEM,    CKRGB_KEY_LALT,       CKRGB_KEY_LALT,       CKRGB_KEY_MISSING, CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_RALT,      CKRGB_KEY_RSYSTEM,      CKRGB_KEY_CONTEXTMENU, CKRGB_KEY_RCTRL,     CKRGB_KEY_RCTRL,     CKRGB_KEY_ARROWLEFT,   CKRGB_KEY_ARROWDOWN, CKRGB_KEY_ARROWRIGHT, CKRGB_KEY_NUMPAD0,     CKRGB_KEY_NUMPAD0,      CKRGB_KEY_NUMPADDECIMAL,  CKRGB_KEY_NUMPADENTER}
};

enum ckrgb_key key_matrix_uk_k65[K_HEIGHT][K65_WIDTH] = {
  {CKRGB_KEY_MISSING,  CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING,   CKRGB_KEY_BRIGHTNESS,   CKRGB_KEY_MUTE,        CKRGB_KEY_VOLUMEDOWN, CKRGB_KEY_VOLUMEUP,  CKRGB_KEY_WINLOCK,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING},
  {CKRGB_KEY_ESCAPE,   CKRGB_KEY_MISSING,   CKRGB_KEY_F1,      CKRGB_KEY_F2,      CKRGB_KEY_F3,      CKRGB_KEY_F4,      CKRGB_KEY_F5,      CKRGB_KEY_F6,      CKRGB_KEY_F7,      CKRGB_KEY_F8,      CKRGB_KEY_MISSING,   CKRGB_KEY_F9,           CKRGB_KEY_F10,         CKRGB_KEY_F11,        CKRGB_KEY_F12,       CKRGB_KEY_PRINTSCREEN, CKRGB_KEY_SCOLLLOCK, CKRGB_KEY_PAUSEBREAK},
  {CKRGB_KEY_TILDE,    CKRGB_KEY_NUM1,      CKRGB_KEY_NUM2,    CKRGB_KEY_NUM3,    CKRGB_KEY_NUM4,    CKRGB_KEY_NUM5,    CKRGB_KEY_NUM6,    CKRGB_KEY_NUM7,    CKRGB_KEY_NUM8,    CKRGB_KEY_NUM9,    CKRGB_KEY_NUM0,      CKRGB_KEY_MINUS,        CKRGB_KEY_EQUALS,      CKRGB_KEY_BACKSPACE,  CKRGB_KEY_BACKSPACE, CKRGB_KEY_INSERT,      CKRGB_KEY_HOME,      CKRGB_KEY_PAGEUP},
  {CKRGB_KEY_TAB,      CKRGB_KEY_Q,         CKRGB_KEY_W,       CKRGB_KEY_E,       CKRGB_KEY_R,       CKRGB_KEY_T,       CKRGB_KEY_Y,       CKRGB_KEY_U,       CKRGB_KEY_I,       CKRGB_KEY_O,       CKRGB_KEY_P,         CKRGB_KEY_LBRACKET,     CKRGB_KEY_RBRACKET,    CKRGB_KEY_ENTER,      CKRGB_KEY_ENTER,     CKRGB_KEY_DELETE,      CKRGB_KEY_END,       CKRGB_KEY_PAGEDOWN},
  {CKRGB_KEY_CAPSLOCK, CKRGB_KEY_A,         CKRGB_KEY_S,       CKRGB_KEY_D,       CKRGB_KEY_F,       CKRGB_KEY_G,       CKRGB_KEY_H,       CKRGB_KEY_J,       CKRGB_KEY_K,       CKRGB_KEY_L,       CKRGB_KEY_SEMICOLON, CKRGB_KEY_QUOTE,        CKRGB_KEY_HASH,        CKRGB_KEY_ENTER,      CKRGB_KEY_ENTER,     CKRGB_KEY_MISSING,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING},
  {CKRGB_KEY_LSHIFT,   CKRGB_KEY_BACKSLASH, CKRGB_KEY_Z,       CKRGB_KEY_X,       CKRGB_KEY_C,       CKRGB_KEY_V,       CKRGB_KEY_B,       CKRGB_KEY_N,       CKRGB_KEY_M,       CKRGB_KEY_COMMA,   CKRGB_KEY_PERIOD,    CKRGB_KEY_FORWARDSLASH, CKRGB_KEY_RSHIFT,      CKRGB_KEY_RSHIFT,     CKRGB_KEY_RSHIFT,    CKRGB_KEY_MISSING,     CKRGB_KEY_ARROWUP,   CKRGB_KEY_MISSING},
  {CKRGB_KEY_LCTRL,    CKRGB_KEY_LSYSTEM,   CKRGB_KEY_LALT,    CKRGB_KEY_LALT,    CKRGB_KEY_MISSING, CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_RALT,      CKRGB_KEY_RSYSTEM,      CKRGB_KEY_CONTEXTMENU, CKRGB_KEY_RCTRL,      CKRGB_KEY_RCTRL,     CKRGB_KEY_ARROWLEFT,   CKRGB_KEY_ARROWDOWN, CKRGB_KEY_ARROWRIGHT}
};

enum ckrgb_key key_matrix_uk_k70[K_HEIGHT][K70_WIDTH] = {
  {CKRGB_KEY_MISSING,  CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,      CKRGB_KEY_MISSING,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,   CKRGB_KEY_BRIGHTNESS,  CKRGB_KEY_WINLOCK,   CKRGB_KEY_MISSING,    CKRGB_KEY_MISSING,   CKRGB_KEY_MUTE,         CKRGB_KEY_MISSING,        CKRGB_KEY_MISSING},
  {CKRGB_KEY_ESCAPE,   CKRGB_KEY_MISSING,   CKRGB_KEY_F1,      CKRGB_KEY_F2,      CKRGB_KEY_F3,      CKRGB_KEY_F4,      CKRGB_KEY_F5,      CKRGB_KEY_F6,      CKRGB_KEY_F7,      CKRGB_KEY_F8,      CKRGB_KEY_MISSING,   CKRGB_KEY_F9,           CKRGB_KEY_F10,         CKRGB_KEY_F11,       CKRGB_KEY_F12,       CKRGB_KEY_PRINTSCREEN, CKRGB_KEY_SCOLLLOCK, CKRGB_KEY_PAUSEBREAK, CKRGB_KEY_MEDIASTOP, CKRGB_KEY_MEDIAPREV,    CKRGB_KEY_MEDIAPLAYPAUSE, CKRGB_KEY_MEDIANEXT},
  {CKRGB_KEY_TILDE,    CKRGB_KEY_NUM1,      CKRGB_KEY_NUM2,    CKRGB_KEY_NUM3,    CKRGB_KEY_NUM4,    CKRGB_KEY_NUM5,    CKRGB_KEY_NUM6,    CKRGB_KEY_NUM7,    CKRGB_KEY_NUM8,    CKRGB_KEY_NUM9,    CKRGB_KEY_NUM0,      CKRGB_KEY_MINUS,        CKRGB_KEY_EQUALS,      CKRGB_KEY_BACKSPACE, CKRGB_KEY_BACKSPACE, CKRGB_KEY_INSERT,      CKRGB_KEY_HOME,      CKRGB_KEY_PAGEUP,     CKRGB_KEY_NUMLOCK,   CKRGB_KEY_NUMPADDIVIDE, CKRGB_KEY_NUMPADMULTIPLY, CKRGB_KEY_NUMPADMINUS},
  {CKRGB_KEY_TAB,      CKRGB_KEY_Q,         CKRGB_KEY_W,       CKRGB_KEY_E,       CKRGB_KEY_R,       CKRGB_KEY_T,       CKRGB_KEY_Y,       CKRGB_KEY_U,       CKRGB_KEY_I,       CKRGB_KEY_O,       CKRGB_KEY_P,         CKRGB_KEY_LBRACKET,     CKRGB_KEY_RBRACKET,    CKRGB_KEY_ENTER,     CKRGB_KEY_ENTER,     CKRGB_KEY_DELETE,      CKRGB_KEY_END,       CKRGB_KEY_PAGEDOWN,   CKRGB_KEY_NUMPAD7,   CKRGB_KEY_NUMPAD8,      CKRGB_KEY_NUMPAD9,        CKRGB_KEY_NUMPADPLUS},
  {CKRGB_KEY_CAPSLOCK, CKRGB_KEY_A,         CKRGB_KEY_S,       CKRGB_KEY_D,       CKRGB_KEY_F,       CKRGB_KEY_G,       CKRGB_KEY_H,       CKRGB_KEY_J,       CKRGB_KEY_K,       CKRGB_KEY_L,       CKRGB_KEY_SEMICOLON, CKRGB_KEY_QUOTE,        CKRGB_KEY_HASH,        CKRGB_KEY_ENTER,     CKRGB_KEY_ENTER,     CKRGB_KEY_MISSING,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,    CKRGB_KEY_NUMPAD4,   CKRGB_KEY_NUMPAD5,      CKRGB_KEY_NUMPAD6,        CKRGB_KEY_NUMPADPLUS},
  {CKRGB_KEY_LSHIFT,   CKRGB_KEY_BACKSLASH, CKRGB_KEY_Z,       CKRGB_KEY_X,       CKRGB_KEY_C,       CKRGB_KEY_V,       CKRGB_KEY_B,       CKRGB_KEY_N,       CKRGB_KEY_M,       CKRGB_KEY_COMMA,   CKRGB_KEY_PERIOD,    CKRGB_KEY_FORWARDSLASH, CKRGB_KEY_RSHIFT,      CKRGB_KEY_RSHIFT,    CKRGB_KEY_RSHIFT,    CKRGB_KEY_MISSING,     CKRGB_KEY_ARROWUP,   CKRGB_KEY_MISSING,    CKRGB_KEY_NUMPAD1,   CKRGB_KEY_NUMPAD2,      CKRGB_KEY_NUMPAD3,        CKRGB_KEY_NUMPADENTER},
  {CKRGB_KEY_LCTRL,    CKRGB_KEY_LSYSTEM,   CKRGB_KEY_LALT,    CKRGB_KEY_LALT,    CKRGB_KEY_MISSING, CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_RALT,      CKRGB_KEY_RSYSTEM,      CKRGB_KEY_CONTEXTMENU, CKRGB_KEY_RCTRL,     CKRGB_KEY_RCTRL,     CKRGB_KEY_ARROWLEFT,   CKRGB_KEY_ARROWDOWN, CKRGB_KEY_ARROWRIGHT, CKRGB_KEY_NUMPAD0,   CKRGB_KEY_NUMPAD0,      CKRGB_KEY_NUMPADDECIMAL,  CKRGB_KEY_NUMPADENTER}
};

enum ckrgb_key key_matrix_uk_k95[K_HEIGHT][K95_WIDTH] = {
  {CKRGB_KEY_MISSING,  CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING, CKRGB_KEY_MACRORECORD,  CKRGB_KEY_MACROMODE1, CKRGB_KEY_MACROMODE2, CKRGB_KEY_MACROMODE3, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,      CKRGB_KEY_MISSING,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,   CKRGB_KEY_BRIGHTNESS,  CKRGB_KEY_WINLOCK,   CKRGB_KEY_MISSING,    CKRGB_KEY_MISSING,     CKRGB_KEY_MUTE,         CKRGB_KEY_MISSING,        CKRGB_KEY_MISSING},
  {CKRGB_KEY_G1,       CKRGB_KEY_G2,        CKRGB_KEY_G3,      CKRGB_KEY_ESCAPE,       CKRGB_KEY_MISSING,    CKRGB_KEY_F1,         CKRGB_KEY_F2,         CKRGB_KEY_F3,      CKRGB_KEY_F4,      CKRGB_KEY_F5,      CKRGB_KEY_F6,      CKRGB_KEY_F7,      CKRGB_KEY_F8,      CKRGB_KEY_MISSING,   CKRGB_KEY_F9,           CKRGB_KEY_F10,         CKRGB_KEY_F11,       CKRGB_KEY_F12,       CKRGB_KEY_PRINTSCREEN, CKRGB_KEY_SCOLLLOCK, CKRGB_KEY_PAUSEBREAK, CKRGB_KEY_MEDIASTOP,   CKRGB_KEY_MEDIAPREV,    CKRGB_KEY_MEDIAPLAYPAUSE, CKRGB_KEY_MEDIANEXT},
  {CKRGB_KEY_G4,       CKRGB_KEY_G5,        CKRGB_KEY_G6,      CKRGB_KEY_TILDE,        CKRGB_KEY_NUM1,       CKRGB_KEY_NUM2,       CKRGB_KEY_NUM3,       CKRGB_KEY_NUM4,    CKRGB_KEY_NUM5,    CKRGB_KEY_NUM6,    CKRGB_KEY_NUM7,    CKRGB_KEY_NUM8,    CKRGB_KEY_NUM9,    CKRGB_KEY_NUM0,      CKRGB_KEY_MINUS,        CKRGB_KEY_EQUALS,      CKRGB_KEY_BACKSPACE, CKRGB_KEY_BACKSPACE, CKRGB_KEY_INSERT,      CKRGB_KEY_HOME,      CKRGB_KEY_PAGEUP,     CKRGB_KEY_NUMLOCK,     CKRGB_KEY_NUMPADDIVIDE, CKRGB_KEY_NUMPADMULTIPLY, CKRGB_KEY_NUMPADMINUS},
  {CKRGB_KEY_G7,       CKRGB_KEY_G8,        CKRGB_KEY_G9,      CKRGB_KEY_TAB,          CKRGB_KEY_Q,          CKRGB_KEY_W,          CKRGB_KEY_E,          CKRGB_KEY_R,       CKRGB_KEY_T,       CKRGB_KEY_Y,       CKRGB_KEY_U,       CKRGB_KEY_I,       CKRGB_KEY_O,       CKRGB_KEY_P,         CKRGB_KEY_LBRACKET,     CKRGB_KEY_RBRACKET,    CKRGB_KEY_ENTER,     CKRGB_KEY_ENTER,     CKRGB_KEY_DELETE,      CKRGB_KEY_END,       CKRGB_KEY_PAGEDOWN,   CKRGB_KEY_NUMPAD7,     CKRGB_KEY_NUMPAD8,      CKRGB_KEY_NUMPAD9,        CKRGB_KEY_NUMPADPLUS},
  {CKRGB_KEY_G10,      CKRGB_KEY_G11,       CKRGB_KEY_G12,     CKRGB_KEY_CAPSLOCK,     CKRGB_KEY_A,          CKRGB_KEY_S,          CKRGB_KEY_D,          CKRGB_KEY_F,       CKRGB_KEY_G,       CKRGB_KEY_H,       CKRGB_KEY_J,       CKRGB_KEY_K,       CKRGB_KEY_L,       CKRGB_KEY_SEMICOLON, CKRGB_KEY_QUOTE,        CKRGB_KEY_HASH,        CKRGB_KEY_ENTER,     CKRGB_KEY_ENTER,     CKRGB_KEY_MISSING,     CKRGB_KEY_MISSING,   CKRGB_KEY_MISSING,    CKRGB_KEY_NUMPAD4,     CKRGB_KEY_NUMPAD5,      CKRGB_KEY_NUMPAD6,        CKRGB_KEY_NUMPADPLUS},
  {CKRGB_KEY_G13,      CKRGB_KEY_G14,       CKRGB_KEY_G15,     CKRGB_KEY_LSHIFT,       CKRGB_KEY_BACKSLASH,  CKRGB_KEY_Z,          CKRGB_KEY_X,          CKRGB_KEY_C,       CKRGB_KEY_V,       CKRGB_KEY_B,       CKRGB_KEY_N,       CKRGB_KEY_M,       CKRGB_KEY_COMMA,   CKRGB_KEY_PERIOD,    CKRGB_KEY_FORWARDSLASH, CKRGB_KEY_RSHIFT,      CKRGB_KEY_RSHIFT,    CKRGB_KEY_RSHIFT,    CKRGB_KEY_MISSING,     CKRGB_KEY_ARROWUP,   CKRGB_KEY_MISSING,    CKRGB_KEY_NUMPAD1,     CKRGB_KEY_NUMPAD2,      CKRGB_KEY_NUMPAD3,        CKRGB_KEY_NUMPADENTER},
  {CKRGB_KEY_G16,      CKRGB_KEY_G17,       CKRGB_KEY_G18,     CKRGB_KEY_LCTRL,        CKRGB_KEY_LSYSTEM,    CKRGB_KEY_LALT,       CKRGB_KEY_LALT,       CKRGB_KEY_MISSING, CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_SPACE,   CKRGB_KEY_MISSING, CKRGB_KEY_MISSING, CKRGB_KEY_RALT,      CKRGB_KEY_RSYSTEM,      CKRGB_KEY_CONTEXTMENU, CKRGB_KEY_RCTRL,     CKRGB_KEY_RCTRL,     CKRGB_KEY_ARROWLEFT,   CKRGB_KEY_ARROWDOWN, CKRGB_KEY_ARROWRIGHT, CKRGB_KEY_NUMPAD0,     CKRGB_KEY_NUMPAD0,      CKRGB_KEY_NUMPADDECIMAL,  CKRGB_KEY_NUMPADENTER}
};

ckrgb_keyboard* ckrgb_keyboard_new(libusb_device* device, enum ckrgb_keyboard_type kt)
{
	int i = sizeof(ckrgb_keyboard);
	ckrgb_keyboard* kb = (ckrgb_keyboard*)malloc(sizeof(ckrgb_keyboard));
	
	memset(kb, 0, sizeof(ckrgb_keyboard));

	if (libusb_open(device, &kb->pHandle))
	{
		free(kb);
		return NULL;
	}

	kb->eType   = kt;
	kb->eKeyMap = CKRGB_KEYMAP_US;

	kb->height = 7;
	switch(kt)
	{
	case CKRGB_KEYBOARD_TYPE_K65:
		kb->width = 18;
		break;
	case CKRGB_KEYBOARD_TYPE_K70:
		kb->width = 22;
		break;
	case CKRGB_KEYBOARD_TYPE_K95:
		kb->width = 25;
		break;
	}

	return kb;
}

void ckrgb_keyboard_delete(ckrgb_keyboard* kb)
{
	if (kb->bClaimed)
		libusb_release_interface(kb->pHandle, 0);

	libusb_close(kb->pHandle);
	free(kb);
}

ckrgb_error ckrgb_keyboard_claim(ckrgb_keyboard* kb)
{
	int err = libusb_claim_interface(kb->pHandle, 3);

	if (err)
	{
		switch(err)
		{
		case LIBUSB_ERROR_NOT_FOUND: return CKRGB_ERROR_INTERFACE_NOT_FOUND;
		case LIBUSB_ERROR_BUSY:      return CKRGB_ERROR_DEVICE_BUSY;
		case LIBUSB_ERROR_NO_DEVICE: return CKRGB_ERROR_NO_DEVICE;
		default:                     return CKRGB_ERROR_UNKNOWN;
		}
	}
	else
	{
		kb->bClaimed = CKRGB_TRUE;
	}

	return CKRGB_ERROR_SUCCESS;
}

ckrgb_error ckrgb_keyboard_unclaim(ckrgb_keyboard* kb)
{
	int err = libusb_release_interface(kb->pHandle, 0);

	if (err)
	{
		switch(err)
		{
		case LIBUSB_ERROR_NOT_FOUND: return CKRGB_ERROR_INTERFACE_NOT_FOUND;
		case LIBUSB_ERROR_BUSY:      return CKRGB_ERROR_DEVICE_BUSY;
		case LIBUSB_ERROR_NO_DEVICE: return CKRGB_ERROR_NO_DEVICE;
		default:                     return CKRGB_ERROR_UNKNOWN;
		}
	}
	else
	{
		kb->bClaimed = CKRGB_FALSE;
	}

	return err;
}

void get_key_pos_us_k65(enum ckrgb_key key, int* x, int* y)
{
	for (int iy = 0; iy < K_HEIGHT; ++iy)
		for (int ix = 0; ix < K65_WIDTH; ++ix)
			if (key_matrix_us_k65[iy][ix] == key)
				*x = ix, *y = iy;
}

void get_key_pos_us_k70(enum ckrgb_key key, int* x, int* y)
{
	for (int iy = 0; iy < K_HEIGHT; ++iy)
		for (int ix = 0; ix < K70_WIDTH; ++ix)
			if (key_matrix_us_k70[iy][ix] == key)
				*x = ix, *y = iy;
}

void get_key_pos_us_k95(enum ckrgb_key key, int* x, int* y)
{
	for (int iy = 0; iy < K_HEIGHT; ++iy)
		for (int ix = 0; ix < K95_WIDTH; ++ix)
			if (key_matrix_us_k95[iy][ix] == key)
				*x = ix, *y = iy;
}

void get_key_pos_uk_k65(enum ckrgb_key key, int* x, int* y)
{
	for (int iy = 0; iy < K_HEIGHT; ++iy)
		for (int ix = 0; ix < K65_WIDTH; ++ix)
			if (key_matrix_uk_k65[iy][ix] == key)
				*x = ix, *y = iy;
}

void get_key_pos_uk_k70(enum ckrgb_key key, int* x, int* y)
{
	for (int iy = 0; iy < K_HEIGHT; ++iy)
		for (int ix = 0; ix < K70_WIDTH; ++ix)
			if (key_matrix_uk_k70[iy][ix] == key)
				*x = ix, *y = iy;
}

void get_key_pos_uk_k95(enum ckrgb_key key, int* x, int* y)
{
	for (int iy = 0; iy < K_HEIGHT; ++iy)
		for (int ix = 0; ix < K95_WIDTH; ++ix)
			if (key_matrix_uk_k95[iy][ix] == key)
				*x = ix, *y = iy;
}

void ckrgb_keyboard_key_pos(enum ckrgb_keyboard_type kt, enum ckrgb_keymap km, enum ckrgb_key key, int* x, int* y)
{
	if (km == CKRGB_KEYMAP_US)
	{
		switch (kt)
		{
		case CKRGB_KEYBOARD_TYPE_K65:
			get_key_pos_us_k65(key, x, y);
			break;
		case CKRGB_KEYBOARD_TYPE_K70:
			get_key_pos_us_k70(key, x, y);
			break;
		case CKRGB_KEYBOARD_TYPE_K95:
			get_key_pos_us_k95(key, x, y);
			break;
		}
	}
	else if (km == CKRGB_KEYMAP_UK)
	{
		switch (kt)
		{
		case CKRGB_KEYBOARD_TYPE_K65:
			get_key_pos_uk_k65(key, x, y);
			break;
		case CKRGB_KEYBOARD_TYPE_K70:
			get_key_pos_uk_k70(key, x, y);
			break;
		case CKRGB_KEYBOARD_TYPE_K95:
			get_key_pos_uk_k95(key, x, y);
			break;
		}
	}
}

void ckrgb_keyboard_set_keycode(ckrgb_keyboard* kb, unsigned char keycode, unsigned char r, unsigned char g, unsigned char b)
{
	if (keycode == 0xFF) //> Ignore code 0xFF
		return;

	/*
	r = (unsigned char)((7.f/255.f)*r);
	g = (unsigned char)((7.f/255.f)*g);
	b = (unsigned char)((7.f/255.f)*b);

	kb->pBuffer[keycode].r = 7 - r;
	kb->pBuffer[keycode].g = 7 - g;
	kb->pBuffer[keycode].b = 7 - b;
	*/

	kb->pBuffer[keycode].r = r;
	kb->pBuffer[keycode].g = g;
	kb->pBuffer[keycode].b = b;
}

void ckrgb_keyboard_get_keycode(ckrgb_keyboard* kb, unsigned char keycode, unsigned char* r, unsigned char* g, unsigned char* b)
{
	if (keycode == 0xFF) //> Ignore code 0xFF
		return;

	(*r) = kb->pBuffer[keycode].r;
	(*g) = kb->pBuffer[keycode].g;
	(*b) = kb->pBuffer[keycode].b;
}

void ckrgb_keyboard_set_key(ckrgb_keyboard* kb, enum ckrgb_key key, unsigned char r, unsigned char g, unsigned char b)
{
	if (kb->eKeyMap == CKRGB_KEYMAP_US)
		ckrgb_keyboard_set_keycode(kb, keymap_us[key], r, g, b);
	else if (kb->eKeyMap == CKRGB_KEYMAP_UK)
		ckrgb_keyboard_set_keycode(kb, keymap_uk[key], r, g, b);
}

void ckrgb_keyboard_get_key(ckrgb_keyboard* kb, enum ckrgb_key key, unsigned char* r, unsigned char* g, unsigned char* b)
{
	if (kb->eKeyMap == CKRGB_KEYMAP_US)
		ckrgb_keyboard_get_keycode(kb, keymap_us[key], r, g, b);
	else if (kb->eKeyMap == CKRGB_KEYMAP_UK)
		ckrgb_keyboard_get_keycode(kb, keymap_uk[key], r, g, b);
}

void ckrgb_keyboard_set_pos(ckrgb_keyboard* kb, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
	if (x < 0 || x >= kb->width || y < 0 || y >= kb->height)
		return;

	if (kb->eKeyMap == CKRGB_KEYMAP_US)
	{
		switch (kb->eType)
		{
		case CKRGB_KEYBOARD_TYPE_K65:
			ckrgb_keyboard_set_key(kb, key_matrix_us_k65[y][x], r, g, b);
			break;
		case CKRGB_KEYBOARD_TYPE_K70:
			ckrgb_keyboard_set_key(kb, key_matrix_us_k70[y][x], r, g, b);
			break;
		case CKRGB_KEYBOARD_TYPE_K95:
			ckrgb_keyboard_set_key(kb, key_matrix_us_k95[y][x], r, g, b);
			break;
		}
	}
	else if (kb->eKeyMap == CKRGB_KEYMAP_UK)
	{
		switch (kb->eType)
		{
		case CKRGB_KEYBOARD_TYPE_K65:
			ckrgb_keyboard_set_key(kb, key_matrix_uk_k65[y][x], r, g, b);
			break;
		case CKRGB_KEYBOARD_TYPE_K70:
			ckrgb_keyboard_set_key(kb, key_matrix_uk_k70[y][x], r, g, b);
			break;
		case CKRGB_KEYBOARD_TYPE_K95:
			ckrgb_keyboard_set_key(kb, key_matrix_uk_k95[y][x], r, g, b);
			break;
		}
	}
}

void ckrgb_keyboard_get_pos(ckrgb_keyboard* kb, int x, int y, unsigned char* r, unsigned char* g, unsigned char* b)
{
	if (x < 0 || x >= kb->width || y < 0 || y >= kb->height)
		return;

	if (kb->eKeyMap == CKRGB_KEYMAP_US)
	{
		switch (kb->eType)
		{
		case CKRGB_KEYBOARD_TYPE_K65:
			ckrgb_keyboard_get_key(kb, key_matrix_us_k65[y][x], r, g, b);
			break;
		case CKRGB_KEYBOARD_TYPE_K70:
			ckrgb_keyboard_get_key(kb, key_matrix_us_k70[y][x], r, g, b);
			break;
		case CKRGB_KEYBOARD_TYPE_K95:
			ckrgb_keyboard_get_key(kb, key_matrix_us_k95[y][x], r, g, b);
			break;
		}
	}
	else if (kb->eKeyMap == CKRGB_KEYMAP_UK)
	{
		switch (kb->eType)
		{
		case CKRGB_KEYBOARD_TYPE_K65:
			ckrgb_keyboard_get_key(kb, key_matrix_uk_k65[y][x], r, g, b);
			break;
		case CKRGB_KEYBOARD_TYPE_K70:
			ckrgb_keyboard_get_key(kb, key_matrix_uk_k70[y][x], r, g, b);
			break;
		case CKRGB_KEYBOARD_TYPE_K95:
			ckrgb_keyboard_get_key(kb, key_matrix_uk_k95[y][x], r, g, b);
			break;
		}
	}
}

unsigned char process_component(unsigned char val)
{
	return 7 - (unsigned char)((7.f/255.f) * val);
}

ckrgb_error ckrgb_keyboard_flush_buffer(ckrgb_keyboard* kb)
{
	unsigned char data[5][64] = {0};
	int i, err;

	if (!kb->bClaimed)
		return CKRGB_ERROR_NOT_CLAIMED;

	/* Credits to CalcProgrammer1 for
	   reverse engineering the protocol. */

	data[0][0] = 0x7F;
	data[0][1] = 0x01;
	data[0][2] = 0x3C;

	data[1][0] = 0x7F;
	data[1][1] = 0x02;
	data[1][2] = 0x3C;
	
	data[2][0] = 0x7F;
	data[2][1] = 0x03;
	data[2][2] = 0x3C;
	
	data[3][0] = 0x7F;
	data[3][1] = 0x04;
	data[3][2] = 0x24;
	
	data[4][0] = 0x07;
	data[4][1] = 0x27;
	data[4][2] = 0xD8;

	// Red.
	for (i = 0; i < 60; ++i)
		data[0][i+4] = (process_component(kb->pBuffer[i*2+1].r) << 4) |
		                process_component(kb->pBuffer[i*2].r);
	for (i = 0; i < 12; ++i)
		data[1][i+4] = (process_component(kb->pBuffer[i*2+121].r) << 4) |
		                process_component(kb->pBuffer[i*2+120].r);

	// Green.
	for (i = 0; i < 48; ++i)
		data[1][i+16] = (process_component(kb->pBuffer[i*2+1].g) << 4) |
		                 process_component(kb->pBuffer[i*2].g);
	for (i = 0; i < 24; ++i)
		data[2][i+4] = (process_component(kb->pBuffer[i*2+97].g) << 4) |
		                process_component(kb->pBuffer[i*2+96].g);

	// Blue.
	for (i = 0; i < 36; ++i)
		data[2][i+28] = (process_component(kb->pBuffer[i*2+1].b) << 4) |
		                 process_component(kb->pBuffer[i*2].b);
	for (i = 0; i < 36; ++i)
		data[3][i+4] = (process_component(kb->pBuffer[i*2+73].b) << 4) |
		                process_component(kb->pBuffer[i*2+72].b);
	
	// Transfer data.
	for (i = 0; i < 5; ++i)
	{
		// Perform USB control message to keyboard
		//
		// Request Type:  0x21
		// Request:       0x09
		// Value          0x0300
		// Index:         0x03
		// Size:          64

		err = libusb_control_transfer(kb->pHandle, 0x21, 0x09, 0x0300, 0x03, data[i], 64, 1000);

		if (err < 0)
		{
			switch(err)
			{
			case LIBUSB_ERROR_TIMEOUT:   return CKRGB_ERROR_TIMEOUT;
			case LIBUSB_ERROR_PIPE:      return CKRGB_ERROR_BAD_CONTROL_REQUEST;
			case LIBUSB_ERROR_NO_DEVICE: return CKRGB_ERROR_NO_DEVICE;
			default:                     return CKRGB_ERROR_UNKNOWN;
			}
		}
	}

	return CKRGB_ERROR_SUCCESS;
}