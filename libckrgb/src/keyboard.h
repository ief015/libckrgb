#ifndef H_CKRGB_KEYBOARD
#define H_CKRGB_KEYBOARD

#include <libusb-1.0/libusb.h>
#include <libckrgb.h>

unsigned char keymap_us[];
unsigned char keymap_uk[];

struct ckrgb_keyboard {
	libusb_device_handle* pHandle;
	struct ckrgb_color    pBuffer[144];
	ckrgb_bool            bClaimed;

	enum ckrgb_keyboard_type eType;
	enum ckrgb_keymap        eKeyMap;
	
	int width;
	int height;
};

ckrgb_keyboard* ckrgb_keyboard_new(libusb_device* device, enum ckrgb_keyboard_type kt);
void ckrgb_keyboard_delete(ckrgb_keyboard* kb);

ckrgb_error ckrgb_keyboard_claim(ckrgb_keyboard* kb);
ckrgb_error ckrgb_keyboard_unclaim(ckrgb_keyboard* kb);

void ckrgb_keyboard_key_pos(enum ckrgb_keyboard_type kt, enum ckrgb_keymap km, enum ckrgb_key key, int* x, int* y);

void ckrgb_keyboard_set_keycode(ckrgb_keyboard* kb, unsigned char keycode, unsigned char r, unsigned char g, unsigned char b);
void ckrgb_keyboard_get_keycode(ckrgb_keyboard* kb, unsigned char keycode, unsigned char* r, unsigned char* g, unsigned char* b);
void ckrgb_keyboard_set_key(ckrgb_keyboard* kb, enum ckrgb_key key, unsigned char r, unsigned char g, unsigned char b);
void ckrgb_keyboard_get_key(ckrgb_keyboard* kb, enum ckrgb_key key, unsigned char* r, unsigned char* g, unsigned char* b);
void ckrgb_keyboard_set_pos(ckrgb_keyboard* kb, int x, int y, unsigned char r, unsigned char g, unsigned char b);
void ckrgb_keyboard_get_pos(ckrgb_keyboard* kb, int x, int y, unsigned char* r, unsigned char* g, unsigned char* b);
ckrgb_error ckrgb_keyboard_flush_buffer(ckrgb_keyboard* kb);

#endif