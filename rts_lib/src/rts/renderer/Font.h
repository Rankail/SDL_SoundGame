#pragma once

#include <SDL_ttf.h>
#include <cstdint>
#include <string>

class Font
{
public:
	Font(const std::string& path, int32_t pointSize);
	virtual ~Font();

	TTF_Font* LoadFont(const std::string& path, int32_t pointSize);

	TTF_Font* GetFont() const { return m_Font; }

private:
	TTF_Font* m_Font;
};