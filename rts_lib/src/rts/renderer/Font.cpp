#include "rtspch.h"

#include "Font.h"

Font::Font(const std::string& path, int32_t pointSize)
{
	m_Font = LoadFont(path, pointSize);
}

Font::~Font()
{
	TTF_CloseFont(m_Font);
}

TTF_Font* Font::LoadFont(const std::string& path, int32_t pointSize)
{
    TTF_Font* font = TTF_OpenFont(path.c_str(), pointSize);
    if (font == NULL) {
        LOG_WARN("Failed to load font from '{}'", path);
        return nullptr;
    }
    m_Font = font;
    return font;
}
