#pragma once

#include <string>
#include <cstdint>
#include <unordered_map>
#include <SDL_ttf.h>

#include "Font.h"

class FontLib
{
public:
	FontLib() = delete;
	virtual ~FontLib() = delete;
	FontLib(const FontLib& other) = delete;

	static bool AddFont(const std::string& path, int32_t pointSize, const std::string& name = "");
	static bool AddFont(std::shared_ptr<Font> font, const std::string& name, int32_t pointSize);

	static std::shared_ptr<Font> LoadFont(const std::string& path, int32_t pointSize);

	static std::shared_ptr<Font> GetFont(const std::string& name, int32_t pointSize);

	static bool RemoveFont(const std::string& name, int32_t pointSize = -1);

private:
	static std::unordered_map<std::string, std::unordered_map<int32_t, std::shared_ptr<Font>>> m_Fonts;
};

