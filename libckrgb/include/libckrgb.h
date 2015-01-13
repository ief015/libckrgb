#ifndef H_CKRGB_LIBCKRGB
#define H_CKRGB_LIBCKRGB

#include "libckrgb_def.h"

CKRGB_API ckrgb_error ckrgb_init();
CKRGB_API void ckrgb_exit();

CKRGB_API ckrgb_keyboard* ckrgb_get_keyboard(size_t idx);
CKRGB_API size_t ckrgb_get_keyboard_count();

CKRGB_API ckrgb_error ckrgb_claim_keyboard(ckrgb_keyboard* kb);
CKRGB_API ckrgb_error ckrgb_unclaim_keyboard(ckrgb_keyboard* kb);
CKRGB_API ckrgb_bool  ckrgb_is_keyboard_claimed(ckrgb_keyboard* kb);
CKRGB_API ckrgb_error ckrgb_set_keymap(ckrgb_keyboard* kb, enum ckrgb_keymap km);
CKRGB_API enum ckrgb_keymap ckrgb_get_keymap(ckrgb_keyboard* kb);
CKRGB_API enum ckrgb_keyboard_type ckrgb_get_keyboard_type(ckrgb_keyboard* kb);

CKRGB_API int ckrgb_get_keyboard_width(ckrgb_keyboard* kb);
CKRGB_API int ckrgb_get_keyboard_height(ckrgb_keyboard* kb);

CKRGB_API ckrgb_error ckrgb_get_key_pos(enum ckrgb_keyboard_type kt, enum ckrgb_keymap km, enum ckrgb_key key, int* x, int* y);
CKRGB_API ckrgb_error ckrgb_get_key_pos_keyboard(ckrgb_keyboard* kb, enum ckrgb_key key, int* x, int* y);
//CKRGB_API ckrgb_error ckrgb_get_key_at_pos()

CKRGB_API ckrgb_error ckrgb_set_key_color(ckrgb_keyboard* kb, enum ckrgb_key key, unsigned char r, unsigned char g, unsigned char b);
CKRGB_API ckrgb_error ckrgb_get_key_color(ckrgb_keyboard* kb, enum ckrgb_key key, unsigned char* r, unsigned char* g, unsigned char* b);
CKRGB_API ckrgb_error ckrgb_set_pos_color(ckrgb_keyboard* kb, int x, int y, unsigned char r, unsigned char g, unsigned char b);
CKRGB_API ckrgb_error ckrgb_get_pos_color(ckrgb_keyboard* kb, int x, int y, unsigned char* r, unsigned char* g, unsigned char* b);
CKRGB_API ckrgb_error ckrgb_flush_buffer(ckrgb_keyboard* kb);

CKRGB_API const char* ckrgb_get_error_description(ckrgb_error err);

#endif