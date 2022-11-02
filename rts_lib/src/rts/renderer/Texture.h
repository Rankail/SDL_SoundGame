#pragma once

#include <SDL.h>
#include <string>

#include "TextureLib.h"

class Texture
{
public:
	Texture(const std::string& path);
	virtual ~Texture();

	SDL_Texture* LoadTexture(const std::string& path);

	int32_t GetWidth() const { return m_Width; }
	int32_t GetHeight() const { return m_Height; }

	SDL_Texture* GetTexture() const { return m_Handle; }

private:
	SDL_Texture* m_Handle;
	int32_t m_Width, m_Height;
};