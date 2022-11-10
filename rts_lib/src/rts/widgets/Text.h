#pragma once

#include "rts/renderer/Texture.h"
#include "rts/renderer/Colors.h"
#include "rts/renderer/Font.h"
#include "rts/widgets/Drawable.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>

class Text : public Drawable
{
private:
	void CreateTexture();

public:
	Text();
	Text(const std::string& text, const std::string& font, int32_t pointSize, Color color = Colors::WHITE);
	Text(const std::string& text, std::shared_ptr<Font> font, Color color = Colors::WHITE);
	virtual ~Text();

	std::shared_ptr<Texture> GetTexture() const { return m_Texture; }
	std::string GetText() const { return m_Text; }
	Color GetColor() const { return m_Color; }
	std::shared_ptr<Font> GetFont() const { return m_Font; }
	int32_t GetWidth() const { return m_Texture->GetWidth(); }
	int32_t GetHeight() const { return m_Texture->GetHeight(); }

	void SetText(const std::string& text);
	void SetColor(Color color);
	void SetFont(std::shared_ptr<Font> font);
	void SetFont(const std::string& font, int32_t pointSize);

	bool IsCreated() const { return m_Texture != nullptr; }

	void Render();

private:
	std::shared_ptr<Font> m_Font;
	Color m_Color = Colors::NONE;
	std::string m_Text = "";

	std::shared_ptr<Texture> m_Texture;
};