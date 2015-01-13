#ifndef H_CKRGB_LIBCKRGB_DEF
#define H_CKRGB_LIBCKRGB_DEF

#include <inttypes.h>

#ifdef CKRGB_STATIC
	#define CKRGB_API
#else
	#ifdef CKRGB_BUILD
		#define CKRGB_API __declspec(dllexport)
	#else
		#define CKRGB_API __declspec(dllimport)
	#endif
#endif

#ifndef NULL
	#define NULL (0)
#endif

#define CKRGB_VERSION_MAJOR 0
#define CKRGB_VERSION_MINOR 1

#define CKRGB_ERROR_SUCCESS                     0
#define CKRGB_ERROR_UNKNOWN                     1
#define CKRGB_ERROR_INVALID_PARAMETER           2
#define CKRGB_ERROR_NOT_INITIALIZED             3
#define CKRGB_ERROR_COULD_NOT_START_USB_CONTEXT 4
#define CKRGB_ERROR_COULD_NOT_FIND_USB_DEVICES  5
#define CKRGB_ERROR_INTERFACE_NOT_FOUND         6
#define CKRGB_ERROR_DEVICE_BUSY                 7
#define CKRGB_ERROR_NO_DEVICE                   8
#define CKRGB_ERROR_NOT_CLAIMED                 9
#define CKRGB_ERROR_TIMEOUT                     10
#define CKRGB_ERROR_BAD_CONTROL_REQUEST         11

#define CKRGB_FALSE (0x00)
#define CKRGB_TRUE  (0x01)

typedef int ckrgb_error;
typedef char ckrgb_bool;
typedef unsigned char ckrgb_component;

struct ckrgb_color {
	ckrgb_component r, g, b;
};

typedef struct ckrgb_keyboard ckrgb_keyboard;

CKRGB_API enum ckrgb_keyboard_type {
	CKRGB_KEYBOARD_TYPE_K65 = 0,
	CKRGB_KEYBOARD_TYPE_K70,
	CKRGB_KEYBOARD_TYPE_K95,

	CKRGB_KEYBOARD_TYPE_COUNT
};

CKRGB_API enum ckrgb_keymap {
	CKRGB_KEYMAP_US = 0,
	CKRGB_KEYMAP_UK,

	CKRGB_KEYMAP_COUNT
};

CKRGB_API enum ckrgb_key {
	CKRGB_KEY_A = 0,
	CKRGB_KEY_B,
	CKRGB_KEY_C,
	CKRGB_KEY_D,
	CKRGB_KEY_E,
	CKRGB_KEY_F,
	CKRGB_KEY_G,
	CKRGB_KEY_H,
	CKRGB_KEY_I,
	CKRGB_KEY_J,
	CKRGB_KEY_K,
	CKRGB_KEY_L,
	CKRGB_KEY_M,
	CKRGB_KEY_N,
	CKRGB_KEY_O,
	CKRGB_KEY_P,
	CKRGB_KEY_Q,
	CKRGB_KEY_R,
	CKRGB_KEY_S,
	CKRGB_KEY_T,
	CKRGB_KEY_U,
	CKRGB_KEY_V,
	CKRGB_KEY_W,
	CKRGB_KEY_X,
	CKRGB_KEY_Y,
	CKRGB_KEY_Z,
	CKRGB_KEY_F1,
	CKRGB_KEY_F2,
	CKRGB_KEY_F3,
	CKRGB_KEY_F4,
	CKRGB_KEY_F5,
	CKRGB_KEY_F6,
	CKRGB_KEY_F7,
	CKRGB_KEY_F8,
	CKRGB_KEY_F9,
	CKRGB_KEY_F10,
	CKRGB_KEY_F11,
	CKRGB_KEY_F12,
	CKRGB_KEY_NUM0,
	CKRGB_KEY_NUM1,
	CKRGB_KEY_NUM2,
	CKRGB_KEY_NUM3,
	CKRGB_KEY_NUM4,
	CKRGB_KEY_NUM5,
	CKRGB_KEY_NUM6,
	CKRGB_KEY_NUM7,
	CKRGB_KEY_NUM8,
	CKRGB_KEY_NUM9,
	CKRGB_KEY_MINUS,
	CKRGB_KEY_EQUALS,
	CKRGB_KEY_NUMPAD0,
	CKRGB_KEY_NUMPAD1,
	CKRGB_KEY_NUMPAD2,
	CKRGB_KEY_NUMPAD3,
	CKRGB_KEY_NUMPAD4,
	CKRGB_KEY_NUMPAD5,
	CKRGB_KEY_NUMPAD6,
	CKRGB_KEY_NUMPAD7,
	CKRGB_KEY_NUMPAD8,
	CKRGB_KEY_NUMPAD9,
	CKRGB_KEY_NUMLOCK,
	CKRGB_KEY_NUMPADDIVIDE,
	CKRGB_KEY_NUMPADMULTIPLY,
	CKRGB_KEY_NUMPADMINUS,
	CKRGB_KEY_NUMPADPLUS,
	CKRGB_KEY_NUMPADENTER,
	CKRGB_KEY_NUMPADDECIMAL,
	CKRGB_KEY_ARROWUP,
	CKRGB_KEY_ARROWDOWN,
	CKRGB_KEY_ARROWLEFT,
	CKRGB_KEY_ARROWRIGHT,
	CKRGB_KEY_MEDIASTOP,
	CKRGB_KEY_MEDIAPREV,
	CKRGB_KEY_MEDIAPLAYPAUSE,
	CKRGB_KEY_MEDIANEXT,
	CKRGB_KEY_MUTE,
	CKRGB_KEY_VOLUMEUP,
	CKRGB_KEY_VOLUMEDOWN,
	CKRGB_KEY_DELETE,
	CKRGB_KEY_INSERT,
	CKRGB_KEY_END,
	CKRGB_KEY_HOME,
	CKRGB_KEY_PAGEDOWN,
	CKRGB_KEY_PAGEUP,
	CKRGB_KEY_LSHIFT,
	CKRGB_KEY_RSHIFT,
	CKRGB_KEY_LCTRL,
	CKRGB_KEY_RCTRL,
	CKRGB_KEY_BACKSLASH,
	CKRGB_KEY_FORWARDSLASH,
	CKRGB_KEY_LSYSTEM,
	CKRGB_KEY_RSYSTEM,
	CKRGB_KEY_LALT,
	CKRGB_KEY_RALT,
	CKRGB_KEY_RBRACKET,
	CKRGB_KEY_LBRACKET,
	CKRGB_KEY_PRINTSCREEN,
	CKRGB_KEY_SCOLLLOCK,
	CKRGB_KEY_PAUSEBREAK,
	CKRGB_KEY_WINLOCK,
	CKRGB_KEY_BRIGHTNESS,
	CKRGB_KEY_COMMA,
	CKRGB_KEY_PERIOD,
	CKRGB_KEY_HASH,
	CKRGB_KEY_SEMICOLON,
	CKRGB_KEY_ESCAPE,
	CKRGB_KEY_TILDE,
	CKRGB_KEY_TAB,
	CKRGB_KEY_CAPSLOCK,
	CKRGB_KEY_BACKSPACE,
	CKRGB_KEY_ENTER,
	CKRGB_KEY_SPACE,
	CKRGB_KEY_CONTEXTMENU,
	CKRGB_KEY_QUOTE,
	CKRGB_KEY_MACRORECORD,
	CKRGB_KEY_MACROMODE1,
	CKRGB_KEY_MACROMODE2,
	CKRGB_KEY_MACROMODE3,
	CKRGB_KEY_G1,
	CKRGB_KEY_G2,
	CKRGB_KEY_G3,
	CKRGB_KEY_G4,
	CKRGB_KEY_G5,
	CKRGB_KEY_G6,
	CKRGB_KEY_G7,
	CKRGB_KEY_G8,
	CKRGB_KEY_G9,
	CKRGB_KEY_G10,
	CKRGB_KEY_G11,
	CKRGB_KEY_G12,
	CKRGB_KEY_G13,
	CKRGB_KEY_G14,
	CKRGB_KEY_G15,
	CKRGB_KEY_G16,
	CKRGB_KEY_G17,
	CKRGB_KEY_G18,

	CKRGB_KEY_COUNT,
	CKRGB_KEY_MISSING
};

#endif