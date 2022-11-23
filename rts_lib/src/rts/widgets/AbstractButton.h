#pragma once

#include "rts/renderer/FontLib.h"
#include "rts/widgets/Text.h"
#include "rts/events/MouseEvent.h"

enum ButtonState
{
	IDLE = 0,
	CLICKED,
	HELD,
	RELEASED
};

enum ButtonType
{
	NONE = 0,
	TEXTURE,
	BASIC
};

struct ButtonProperties
{
	Color backgroundColor;
	Color backgroundColorActive;
	Color textColor;
	std::shared_ptr<Texture> texture;
	std::shared_ptr<Font> font;

	ButtonProperties(const Color& bgColor, const Color& bgColorActive, const Color& textColor, std::shared_ptr<Font> font)
		: backgroundColor(bgColor), backgroundColorActive(bgColorActive), textColor(textColor), font(font)
	{
	}

	ButtonProperties(const Color& bgColor, const Color& bgColorActive, const Color& textColor, const std::string& fontName, int32_t pointSize)
		: backgroundColor(bgColor), backgroundColorActive(bgColorActive), textColor(textColor), font(FontLib::GetFont(fontName, pointSize))
	{
	}

};

class AbstractButton : public Drawable
{
public:
	AbstractButton();

	virtual void SetProperties(const ButtonProperties& properties) = 0;

	void SetText(const std::string& text);
	void SetFont(const std::string& font, int32_t pointSize);
	void SetFont(std::shared_ptr<Font> font);
	void SetTextColor(Color color);

	ButtonType GetButtonType() const { return m_Type; }

	ButtonState GetStatus() const;
	bool IsHovered() const;

	void OnEvent(Event& e);
	bool OnMouseClicked(MouseButtonPressedEvent& e);
	bool OnMouseReleased(MouseButtonReleasedEvent& e);
	bool OnMouseMoved(MouseMovedEvent& e);

	virtual void Update(float dt) override;

	virtual void Render() = 0;

protected:
	const ButtonType m_Type = ButtonType::NONE;

	bool m_Hover;
	bool m_Pressed = false;
	bool m_PrevPressed = false;

	std::shared_ptr<Text> m_Text;
};