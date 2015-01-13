#include <libckrgb.h>
#include "keyboard.h"
#include <libusb-1.0/libusb.h>

#define CORSAIR_VID        0x1B1C
//#define CORSAIR_K65RGB_PID 0x1B12 // TODO: could be wrong, this is just a guess
#define CORSAIR_K70RGB_PID 0x1B13
#define CORSAIR_K95RGB_PID 0x1B11

libusb_context*  usb_context;
ckrgb_keyboard** keyboards;
size_t           keyboards_count;

CKRGB_API ckrgb_error ckrgb_init()
{
	int i, j;
	libusb_device** devices;
	ssize_t num_devices;
	struct libusb_device_descriptor desc;

	usb_context     = NULL;
	keyboards       = NULL;
	keyboards_count = 0;

	// Initialize libusb
	if (libusb_init(&usb_context))
		return CKRGB_ERROR_COULD_NOT_START_USB_CONTEXT;

	// Create a list of USB devices.
	num_devices = libusb_get_device_list(usb_context, &devices);

	if (num_devices < 0)
	{
		libusb_exit(usb_context);
		usb_context = NULL;
		return CKRGB_ERROR_COULD_NOT_FIND_USB_DEVICES;
	}

	keyboards_count = 0;

	// Count the number of Corsair RGB keyboards.
	for (i = 0; i < num_devices; ++i)
	{
		if (!libusb_get_device_descriptor(devices[i], memset(&desc, 0, sizeof(desc))))
		{
			if (desc.idVendor == CORSAIR_VID)
			{
				switch (desc.idProduct)
				{
				//case CORSAIR_K65RGB_PID:
				case CORSAIR_K70RGB_PID:
				case CORSAIR_K95RGB_PID:
					keyboards_count++;
					break;
				}
			}
		}
	}

	// Build array of RGB keyboard objects.
	if (keyboards_count > 0)
	{
		j = 0;
		keyboards = (ckrgb_keyboard**)malloc(keyboards_count * sizeof(ckrgb_keyboard*));

		for (i = 0; i < num_devices; ++i)
		{
			if (!libusb_get_device_descriptor(devices[i], memset(&desc, 0, sizeof(desc))))
			{
				if (desc.idVendor == CORSAIR_VID)
				{
					switch (desc.idProduct)
					{
					/* case CORSAIR_K65RGB_PID:
						keyboards[j++] = ckrgb_keyboard_new(devices[i], CKRGB_KEYBOARD_TYPE_K65);
						break; */
					case CORSAIR_K70RGB_PID:
						keyboards[j++] = ckrgb_keyboard_new(devices[i], CKRGB_KEYBOARD_TYPE_K70);
						break;
					case CORSAIR_K95RGB_PID:
						keyboards[j++] = ckrgb_keyboard_new(devices[i], CKRGB_KEYBOARD_TYPE_K95);
						break;
					}
				}
			}
		}
	}

	libusb_free_device_list(devices, 1);

	return CKRGB_ERROR_SUCCESS;
}

CKRGB_API void ckrgb_exit()
{
	size_t i = 0;

	if (usb_context == NULL)
		return;

	// Delete RGB keyboard objects.
	for (; i < keyboards_count;)
		ckrgb_keyboard_delete(keyboards[i++]);

	// Uninitialize libusb.
	libusb_exit(usb_context);
}

CKRGB_API ckrgb_keyboard* ckrgb_get_keyboard(size_t idx)
{
	if (keyboards == NULL || idx >= keyboards_count)
		return NULL;

	return keyboards[idx];
}

CKRGB_API size_t ckrgb_get_keyboard_count()
{
	return keyboards_count;
}

CKRGB_API ckrgb_error ckrgb_claim_keyboard(ckrgb_keyboard* kb)
{
	if (!usb_context)
		return CKRGB_ERROR_NOT_INITIALIZED;
	if (!kb)
		return CKRGB_ERROR_INVALID_PARAMETER;

	return ckrgb_keyboard_claim(kb);
}

CKRGB_API ckrgb_error ckrgb_unclaim_keyboard(ckrgb_keyboard* kb)
{
	if (!usb_context)
		return CKRGB_ERROR_NOT_INITIALIZED;
	if (!kb)
		return CKRGB_ERROR_INVALID_PARAMETER;

	return ckrgb_keyboard_unclaim(kb);
}

CKRGB_API ckrgb_bool ckrgb_is_keyboard_claimed(ckrgb_keyboard* kb)
{
	if (kb)
		return kb->bClaimed;

	return CKRGB_FALSE;
}

CKRGB_API ckrgb_error ckrgb_set_keymap(ckrgb_keyboard* kb, enum ckrgb_keymap km)
{
	if (!usb_context)
		return CKRGB_ERROR_NOT_INITIALIZED;
	if (!kb)
		return CKRGB_ERROR_INVALID_PARAMETER;
	if (km < 0 || km >= CKRGB_KEYMAP_COUNT)
		return CKRGB_ERROR_INVALID_PARAMETER;

	kb->eKeyMap = km;
	return CKRGB_ERROR_SUCCESS;
}

CKRGB_API enum ckrgb_keymap ckrgb_get_keymap(ckrgb_keyboard* kb)
{
	if (!kb)
		CKRGB_KEYMAP_COUNT;

	return kb->eKeyMap;
}

CKRGB_API enum ckrgb_keyboard_type ckrgb_get_keyboard_type(ckrgb_keyboard* kb)
{
	if (!kb)
		return CKRGB_KEYBOARD_TYPE_COUNT;

	return kb->eType;
}

CKRGB_API int ckrgb_get_keyboard_width(ckrgb_keyboard* kb)
{
	if (!kb)
		return 0;

	return kb->width;
}

CKRGB_API int ckrgb_get_keyboard_height(ckrgb_keyboard* kb)
{
	if (!kb)
		return 0;

	return kb->height;
}

CKRGB_API ckrgb_error ckrgb_get_key_pos(enum ckrgb_keyboard_type kt, enum ckrgb_keymap km, enum ckrgb_key key, int* x, int* y)
{
	if (!x || !y)
		return CKRGB_ERROR_INVALID_PARAMETER;
	if (kt < 0 || kt >= CKRGB_KEYBOARD_TYPE_COUNT)
		return CKRGB_ERROR_INVALID_PARAMETER;
	if (km < 0 || km >= CKRGB_KEYMAP_COUNT)
		return CKRGB_ERROR_INVALID_PARAMETER;

	ckrgb_keyboard_key_pos(kt, km, key, x, y);

	return CKRGB_ERROR_SUCCESS;
}

CKRGB_API ckrgb_error ckrgb_get_key_pos_keyboard(ckrgb_keyboard* kb, enum ckrgb_key key, int* x, int* y)
{
	if (!kb)
		return CKRGB_ERROR_INVALID_PARAMETER;

	return ckrgb_get_key_pos(kb->eType, kb->eKeyMap, key, x, y);
}

CKRGB_API ckrgb_error ckrgb_set_key_color(ckrgb_keyboard* kb, enum ckrgb_key key, unsigned char r, unsigned char g, unsigned char b)
{
	if (!kb)
		return CKRGB_ERROR_INVALID_PARAMETER;

	ckrgb_keyboard_set_key(kb, key, r, g, b);

	return CKRGB_ERROR_SUCCESS;
}

CKRGB_API ckrgb_error ckrgb_get_key_color(ckrgb_keyboard* kb, enum ckrgb_key key, unsigned char* r, unsigned char* g, unsigned char* b)
{
	if (!kb)
		return CKRGB_ERROR_INVALID_PARAMETER;

	ckrgb_keyboard_get_key(kb, key, r, g, b);

	return CKRGB_ERROR_SUCCESS;
}

CKRGB_API ckrgb_error ckrgb_set_pos_color(ckrgb_keyboard* kb, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
	if (!kb)
		return CKRGB_ERROR_INVALID_PARAMETER;

	ckrgb_keyboard_set_pos(kb, x, y, r, g, b);

	return CKRGB_ERROR_SUCCESS;
}

CKRGB_API ckrgb_error ckrgb_get_pos_color(ckrgb_keyboard* kb, int x, int y, unsigned char* r, unsigned char* g, unsigned char* b)
{
	if (!kb)
		return CKRGB_ERROR_INVALID_PARAMETER;

	ckrgb_keyboard_get_pos(kb, x, y, r, g, b);

	return CKRGB_ERROR_SUCCESS;
}

CKRGB_API ckrgb_error ckrgb_flush_buffer(ckrgb_keyboard* kb)
{
	if (!usb_context)
		return CKRGB_ERROR_NOT_INITIALIZED;
	if (!kb)
		return CKRGB_ERROR_INVALID_PARAMETER;

	return ckrgb_keyboard_flush_buffer(kb);
}

CKRGB_API const char* ckrgb_get_error_description(ckrgb_error err)
{
	switch(err)
	{
	case CKRGB_ERROR_SUCCESS: return "operation successful";
	case CKRGB_ERROR_UNKNOWN: return "unknown error occured";
	case CKRGB_ERROR_INVALID_PARAMETER: return "an invalid parameter was caught";
	case CKRGB_ERROR_NOT_INITIALIZED: return "libckrgb was not initialized";
	case CKRGB_ERROR_COULD_NOT_START_USB_CONTEXT: return "could not initalize USB context";
	case CKRGB_ERROR_COULD_NOT_FIND_USB_DEVICES: return "could not list USB devices";
	case CKRGB_ERROR_INTERFACE_NOT_FOUND: return "requested interface does not exist";
	case CKRGB_ERROR_DEVICE_BUSY: return "device is already being used and cannot be claimed";
	case CKRGB_ERROR_NO_DEVICE: return "device could not be found or has been disconnected";
	case CKRGB_ERROR_NOT_CLAIMED: return "device has not been claimed";
	case CKRGB_ERROR_TIMEOUT: return "device timed out";
	case CKRGB_ERROR_BAD_CONTROL_REQUEST: return "control request not supported by the device";
	}
	return "";
}
