#pragma once

#include <string>
#include <cstdint>
#include <unordered_map>
#include <SDL_ttf.h>

class FontLib
{
public:
	FontLib() = delete;
	~FontLib() = delete;
	FontLib(const FontLib& other) = delete;

	static bool AddFont(const std::string& path, int32_t pointSize, const std::string& name = "");
	static bool AddFont(TTF_Font* font, const std::string& name, int32_t pointSize);

	static TTF_Font* LoadFont(const std::string& path, int32_t pointSize);

	static TTF_Font* GetFont(const std::string& name, int32_t pointSize);

	static bool RemoveFont(const std::string& name, int32_t pointSize = -1);

private:
	static std::unordered_map<std::string, std::unordered_map<int32_t, TTF_Font*>> m_Fonts;
};

