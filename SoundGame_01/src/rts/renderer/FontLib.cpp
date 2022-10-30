#include "rtspch.h"
#include "FontLib.h"

#include "rts/core/Log.h"

std::unordered_map<std::string, std::unordered_map<int32_t, TTF_Font*>> FontLib::m_Fonts = std::unordered_map<std::string, std::unordered_map<int32_t, TTF_Font*>>();

bool FontLib::AddFont(const std::string& path, int32_t pointSize, const std::string& name)
{
    auto font = LoadFont(path.c_str(), pointSize);
    if (font == nullptr) return false;

    if (name != "")
    {
        return AddFont(font, name, pointSize);
    }

    auto lastSlash = name.find_last_of("/\\");
    lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
    auto lastDot = name.rfind('.');
    auto count = lastDot == std::string::npos ? path.size() - lastSlash : lastDot - lastSlash;
    return AddFont(font, path.substr(lastSlash, count), pointSize);
}

bool FontLib::AddFont(TTF_Font* font, const std::string& name, int32_t pointSize)
{
    auto it = m_Fonts.find(name);
    if (it == m_Fonts.end())
    {
        return m_Fonts.emplace(name, std::unordered_map<int32_t, TTF_Font*>{ {pointSize, font}}).second;
    }

    it->second[pointSize] = font;
    return true;
}

TTF_Font* FontLib::LoadFont(const std::string& path, int32_t pointSize)
{
    TTF_Font* font = TTF_OpenFont(path.c_str(), pointSize);
    if (font == NULL) {
        LOG_WARN("Failed to load font from '{}'", path);
        return nullptr;
    }
    return font;
}

TTF_Font* FontLib::GetFont(const std::string& name, int32_t pointSize)
{
    auto it = m_Fonts.find(name);
    if (it != m_Fonts.end())
    {
        auto it2 = it->second.find(pointSize);
        if (it2 != it->second.end())
        {
            return it2->second;
        }
    }
    LOG_WARN("Could not find font '{}':{}", name, pointSize);
    return nullptr;
}

bool FontLib::RemoveFont(const std::string& name, int32_t pointSize)
{
    auto it = m_Fonts.find(name);
    if (it == m_Fonts.end())
    {

        LOG_WARN("Tried to remove non-existing font '{}'", name);
        return false;
    }

    if (pointSize == -1)
    {
        m_Fonts.erase(name);
        return true;
    }

    auto it2 = it->second.find(pointSize);
    if (it2 == it->second.end())
    {
        LOG_WARN("Tried to remove non-existing font '{}':{}", name, pointSize);
        return false;
    }
    it->second.erase(it2);
    return true;
}
