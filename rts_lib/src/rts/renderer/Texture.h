#pragma once

#include <SDL.h>
#include <string>

#include "TextureLib.h"

class Texture
{
public:
	Texture();
	Texture(const std::string& path);
	Texture(SDL_Surface* surface);
	virtual ~Texture();

	SDL_Texture* LoadTexture(const std::string& path);

	void SetTexture(SDL_Surface* surf);

	int32_t GetWidth() const { return m_Width; }
	int32_t GetHeight() const { return m_Height; }

	SDL_Texture* GetTexture() const { return m_Texture; }

	void Render(int32_t x, int32_t y);
	void Render(int32_t x, int32_t y, int32_t w, int32_t h);

private:
	SDL_Texture* m_Texture = nullptr;
	int32_t m_Width = 0, m_Height = 0;
};