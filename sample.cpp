/* SAMPLE.CPP
 * Author: Nathan Cousins
 *
 * An assortment of examples on how to use libckrgb.
 * At this time, this code only compiles under Windows.
 */


#include <iostream>
#include <time.h>
#include <math.h>
#include <libckrgb.hpp>
#include <Windows.h>

ckrgb_keyboard* keyboard = NULL;

inline int randomi(int max) { return (rand() % max); }
inline int randomi(int min, int max) { return (rand() % (max + min) - min); }
inline float randomf() { return (rand() / static_cast<float>(RAND_MAX)); }

// Check for an error from libckrgb calls. Prints to stderr if an error is found.
ckrgb_error chkerr(ckrgb_error code)
{
	if (code)
		std::cerr << "CKRGB Error: " << ckrgb_get_error_description(code) << std::endl;
	
	return code;
}

// Clears all keys to a single colour.
void fill(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0)
{
	for (int i = 0; i < CKRGB_KEY_COUNT; ++i)
	{
		chkerr(ckrgb_set_key_color(keyboard, (ckrgb_key)i, r, g, b));
	}
}

// Draw a rectangle.
void draw_rect(float x, float y, float width, float height, unsigned char r, unsigned char g, unsigned char b)
{
	unsigned char xi = static_cast<unsigned char>(round(x));
	unsigned char yi = static_cast<unsigned char>(round(y));
	unsigned char wi = static_cast<unsigned char>(round(width));
	unsigned char hi = static_cast<unsigned char>(round(height));

	for (int dx = xi; dx < xi+wi; ++dx)
		for (int dy = yi; dy < yi+hi; ++dy)
			chkerr(ckrgb_set_pos_color(keyboard, dx, dy, r, g, b));
}

// Flush light buffer to keyboard.
void display()
{
	chkerr(ckrgb_flush_buffer(keyboard));
}

// Calculate RGB from HSL. Values are scalar between 0 -> 1.
void from_hsl(float h, float s, float l, float* r, float* g, float* b)
{
	if (h < 0.f)
		h = 0.f;
	else if (h > 1.f)
		h = 1.f;

	if (s < 0.f)
		s = 0.f;
	else if (s > 1.f)
		s = 1.f;

	if (l < 0.f)
		l = 0.f;
	else if (l > 1.f)
		l = 1.f;

	float rgb[3] = { 0.f, 0.f, 0.f };

	if (l > 0.f)
	{
		if (s == 0.f)
		{
			rgb[0] = l;
			rgb[1] = l;
			rgb[2] = l;
		}
		else
		{
			float temp1, temp2, arr[3] = { h + 1.f / 3.f, h, h - 1.f / 3.f };
			temp2 = (l <= 0.5f) ? (l * (1.f + s)) : (l + s - (l * s));
			temp1 = 2.f * l - temp2;

			for (int i = 0; i < 3; ++i)
			{
				if (arr[i] < 0.f)
					arr[i] += 1.f;
				if (arr[i] > 1.f)
					arr[i] -= 1.f;

				if (6.f * arr[i] < 1.f)
					rgb[i] = temp1 + (temp2 - temp1) * arr[i] * 6.f;
				else if (2.f * arr[i] < 1.f)
					rgb[i] = temp2;
				else if (3.f * arr[i] < 2.f)
					rgb[i] = temp1 + (temp2 - temp1) * ((2.f/3.f) - arr[i]) * 6.f;
				else
					rgb[i] = temp1;
			}
		}
	}
	
	(*r) = rgb[0];
	(*g) = rgb[1];
	(*b) = rgb[2];
}

// Perform a lambda function for each key.
// Provided function must have parameters: (float fx, float fy, float& r, float& g, float& b)
template <class Func>
void for_each(Func func)
{
	float fx, fy;
	int x, y;
	const float WIDTH  = (float)ckrgb_get_keyboard_width(keyboard),
	            HEIGHT = (float)ckrgb_get_keyboard_height(keyboard);

	for (int i = 0; i < CKRGB_KEY_COUNT; ++i)
	{
		ckrgb_key key = static_cast<ckrgb_key>(i);
		float r = 0.f, g = 0.f, b = 0.f;

		chkerr(ckrgb_get_key_pos_keyboard(keyboard, key, &x, &y));
		fx = x / WIDTH;
		fy = y / HEIGHT;

		func(fx, fy, r, g, b);

		chkerr(ckrgb_set_key_color(keyboard, key,
			static_cast<unsigned char>(r*255.f),
			static_cast<unsigned char>(g*255.f),
			static_cast<unsigned char>(b*255.f)));
	}
}

// ROUTINE
// Cycle through all keys.
void r_cycle()
{
	for (int k = 0; k < CKRGB_KEY_COUNT; ++k)
	{
		fill();
		chkerr(ckrgb_set_key_color(keyboard, (ckrgb_key)k, 255, 255, 255));
		display();
		Sleep(50);
	}
}

// ROUTINE
// Cycle all columns and rows of keys.
void r_cycle_lines()
{
	const int width =  ckrgb_get_keyboard_width(keyboard),
	          height = ckrgb_get_keyboard_height(keyboard);

	// Columns
	for (int x = 0; x < width; ++x)
	{
		fill();
		draw_rect(static_cast<float>(x), 0.f, 1.f, static_cast<float>(height), 255, 255, 255);
		display();
		Sleep(500);
	}

	// Rows
	for (int y = 0; y < height; ++y)
	{
		fill();
		draw_rect(0.f, static_cast<float>(y), static_cast<float>(width), 1.f, 255, 255, 255);
		display();
		Sleep(500);
	}
}

// ROUTINE
// A spasm of random colours for each key.
void r_random(int iterations)
{
	for (int i = 0; i < iterations; ++i)
	{
		for (int k = 0; k < CKRGB_KEY_COUNT; ++k)
		{
			chkerr(ckrgb_set_key_color(keyboard, (ckrgb_key)k, randomi(256), randomi(256), randomi(256)));
		}
		display();
		Sleep(20);
	}
}

// ROUTINE
// Bouncing square.
void r_bouncy(int iterations)
{
	float x, y, vx, vy;
	const float w = 2.f, h = 2.f;
	const float scrw = (float)ckrgb_get_keyboard_width(keyboard),
		        scrh = (float)ckrgb_get_keyboard_height(keyboard);
	x = randomf() * (scrw - w);
	y = randomf() * (scrh - w);

	vx = randomf() * 2.f * 3.1415926f;
	vy = cos(vx);
	vx = sin(vx);
	
	for(int t = 0; t < iterations; ++t)
	{
		x += vx;
		y += vy;

		if (x < 0.f)
		{
			vx = -vx;
			x = 0.f;
		}
		else if (x+w > scrw)
		{
			vx = -vx;
			x = scrw-w;
		}
		if (y < 0.f)
		{
			vy = -vy;
			y = 0.f;
		}
		else if (y+h > scrh)
		{
			vy = -vy;
			y = scrh-h;
		}

		fill();
		draw_rect(x, y, w, h, 255, 0, 0);
		display();
		Sleep(20);
	}
}

// ROUTINE
// Simple scrolling rainbow.
void r_rainbow(int iterations)
{
	const float F_LENGTH     = 1.0f;
	const float F_SPEED      = -0.02f;
	const float F_SATURATION = 1.0f;
	const float F_LUMINOSITY = 0.5f;

	for (int i = 0; i < iterations; ++i)
	{
		for_each([&](float x, float y, float& r, float& g, float& b) {
			x = (x / F_LENGTH) + (i * F_SPEED);
			from_hsl(x - floor(x), F_SATURATION, F_LUMINOSITY, &r, &g, &b);
		});
		display();
		Sleep(20);
	}
}

int main()
{
	// Initialize libckrgb
	if (chkerr(ckrgb_init()))
		return 1;
	atexit(ckrgb_exit);

	if (!ckrgb_get_keyboard_count())
	{
		std::cerr <<
			"No Kxx RGB keyboard found! Exiting..." << std::endl;
		return 1;
	}

	// Retrieve and claim keyboard.
	keyboard = ckrgb_get_keyboard(0);
	chkerr(ckrgb_claim_keyboard(keyboard));

	bool cont = true;
	while(cont)
	{
		// Clear to white.
		fill(128, 128, 128);

		// Flush light buffer.
		display();

		// Perform selection...
		std::cout
			<< "Select a test routine:" << std::endl
			<< "[Q] <QUIT>" << std::endl
			<< "[1] Cycle keys" << std::endl
			<< "[2] Cycle lines" << std::endl
			<< "[3] Random colours" << std::endl
			<< "[4] Bouncy square" << std::endl
			<< "[5] Rainbow" << std::endl;

		char selection;
		std::cin >> selection;
		selection = tolower(selection);

		switch (selection)
		{
		case 'q':
			cont = false;
			break;
		case '1':
			r_cycle();
			break;
		case '2':
			r_cycle_lines();
			break;
		case '3':
			r_random(250);
			break;
		case '4':
			r_bouncy(250);
			break;
		case '5':
			r_rainbow(250);
			break;
		}
	}

	return 0;
}