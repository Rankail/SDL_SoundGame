#pragma once
#include <cstdint>

typedef struct Color
{
	uint8_t r, g, b, a;
	Color(uint8_t r = 0x00, uint8_t g = 0x00, uint8_t b = 0x00, uint8_t a = 0xFF)
		: r(r), g(g), b(b), a(a) {}
} Color;

namespace Colors {
	static const Color WHITE(0xFF, 0xFF, 0xFF), BLACK(0),
		GREY(0x88, 0x88, 0x88), DARK_GREY(0x44, 0x44, 0x44), LIGHT_GREY(0xBB, 0xBB, 0xBB),
		RED(0xFF), DARK_RED(0x88), LIGHT_RED(0xFF, 0x88, 0x88),
		GREEN(0, 0xFF), DARK_GREEN(0, 0x88), LIGHT_GREEN(0x88, 0xFF, 0x88),
		BLUE(0, 0, 0xFF), DARK_BLUE(0, 0, 0x88), LIGHT_BLUE(0x88, 0x88, 0xFF),
		YELLOW(0xFF, 0xFF), VIOLET(0xFF, 0, 0xFF), TURQOISE(0, 0xFF, 0xFF),
		ORANGE(0xFF, 0x88), BROWN(0x88, 0x44), OLIVE(0x88, 0xFF), PURPLE(0x88, 0, 0xFF),
		PINK(0xFF, 0, 0x88);
}