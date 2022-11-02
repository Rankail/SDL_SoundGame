#include "rtspch.h"

#include "Text.h"

#include "rts/renderer/FontLib.h"

void Text::CreateTexture()
{
	SDL_Surface* tempSurf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), m_Color.toSDL());
	if (tempSurf == NULL)
	{
		LOG_WARN("Failed to create Text-Surface");
		return;
	}
	m_Texture = std::make_shared<Texture>(tempSurf);
}

Text::Text(const std::string& text, const std::string& font, int32_t pointSize, Color color)
	: m_Text(text), m_Font(FontLib::GetFont(font, pointSize)), m_Color(color)
{
	CreateTexture();
}

Text::Text(const std::string& text, std::shared_ptr<Font> font, Color color)
	: m_Text(text), m_Font(font), m_Color(color)
{
	CreateTexture();
}

Text::~Text()
{
}

void Text::SetText(const std::string& text)
{
	m_Text = text;
	CreateTexture();
}

void Text::SetColor(Color color)
{
	m_Color = color;
	CreateTexture();
}

void Text::SetFont(std::shared_ptr<Font> font)
{
	m_Font = font;
	CreateTexture();
}

void Text::SetFont(const std::string& font, int32_t pointSize)
{
	m_Font = FontLib::GetFont(font, pointSize);
	CreateTexture();
}
