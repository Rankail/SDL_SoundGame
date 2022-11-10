#pragma once

#include <cstdint>

typedef struct Color
{
	uint8_t r, g, b, a;
	Color(uint8_t r = 0x00, uint8_t g = 0x00, uint8_t b = 0x00, uint8_t a = 0xFF)
		: r(r), g(g), b(b), a(a) {}
	SDL_Color toSDL() { return SDL_Color{ r, g, b, a }; }
	inline bool operator==(const Color& o) const { return this->r == o.r && this->g == o.g && this->b == o.b && this->a == o.a; }
	bool operator!=(const Color& o) const { return !operator==(o); }
	operator bool() const { return this->r != 0 || this->g != 0 || this->b != 0 || this->a != 0; }
} Color;

namespace Colors {
	static const Color WHITE(0xFF, 0xFF, 0xFF), BLACK(0),
		GREY(0x88, 0x88, 0x88), DARK_GREY(0x44, 0x44, 0x44), LIGHT_GREY(0xBB, 0xBB, 0xBB),
		RED(0xFF), DARK_RED(0x88), LIGHT_RED(0xFF, 0x88, 0x88),
		GREEN(0, 0xFF), DARK_GREEN(0, 0x88), LIGHT_GREEN(0x88, 0xFF, 0x88),
		BLUE(0, 0, 0xFF), DARK_BLUE(0, 0, 0x88), LIGHT_BLUE(0x88, 0x88, 0xFF),
		YELLOW(0xFF, 0xFF), VIOLET(0xFF, 0, 0xFF), TURQOISE(0, 0xFF, 0xFF),
		ORANGE(0xFF, 0x88), BROWN(0x88, 0x44), OLIVE(0x88, 0xFF), PURPLE(0x88, 0, 0xFF),
		PINK(0xFF, 0, 0x88),
		NONE(0, 0, 0, 0);
}