#pragma once

#include <cstdint>

class Renderer
{
public:
	static Init();

	static SetColor(Color color);
	static SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
};