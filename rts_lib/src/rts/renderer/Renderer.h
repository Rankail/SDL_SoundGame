#pragma once

#include <cstdint>
#include "rts/renderer/Colors.h"

class Texture;
class Text;

class Renderer
{
public:
	static void Init();
	static void Shutdown();

	static void Clear();
	static void Present();

	static void SetClearColor(Color color);

	static void SetColor(Color color);
	static void SetColor(uint8_t r = 0x00, uint8_t g = 0x00, uint8_t b = 0x00, uint8_t a = 0xFF);

	static void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h);
	static void FillRect(int32_t x, int32_t y, int32_t w, int32_t h);

	static void RenderTexture(SDL_Texture* tex, int32_t x, int32_t y, int32_t w, int32_t h);

	static SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface);

};