#pragma once

#include "rts/widgets/Text.h"
#include "rts/events/MouseEvent.h"
#include "rts/renderer/FontLib.h"

enum ButtonState
{
	IDLE = 0,
	CLICKED,
	HELD,
	RELEASED
};

struct ButtonProperties
{
	Color backgroundColor;
	Color backgroundColorActive;
	Color textColor;
	std::shared_ptr<Font> font;

	ButtonProperties(const Color& bgColor, const Color& bgColorActive, const Color& textColor, std::shared_ptr<Font> font)
		: backgroundColor(bgColor), backgroundColorActive(bgColorActive), textColor(textColor), font(font)
	{}

	ButtonProperties(const Color& bgColor, const Color& bgColorActive, const Color& textColor, const std::string& fontName, int32_t pointSize)
		: backgroundColor(bgColor), backgroundColorActive(bgColorActive), textColor(textColor), font(FontLib::GetFont(fontName, pointSize))
	{}

};

class Button : public Drawable
{
protected:
	virtual void SizePosUpdateBefore() override;
	virtual void SizePosUpdateAfter() override;

public:
	Button();
	virtual ~Button();
	
	void SetProperties(ButtonProperties& properties);

	void SetText(const std::string& text);
	void SetFont(const std::string& font, int32_t pointSize);
	void SetFont(std::shared_ptr<Font> font);
	void SetTextColor(Color color);
	void SetBackgroundColor(Color color);
	void SetActiveBackgroundColor(Color color);


	ButtonState GetStatus();
	bool IsHovered();

	void OnEvent(Event& e);
	bool OnMouseClicked(MouseButtonPressedEvent& e);
	bool OnMouseReleased(MouseButtonReleasedEvent& e);
	bool OnMouseMoved(MouseMovedEvent& e);

	virtual void Update(float dt) override;
	virtual void Render() override; //TODO

private:
	bool m_Hover;
	bool m_Pressed = false;
	bool m_PrevPressed = false;

	Color m_BgColor = Colors::NONE;
	Color m_BgActive = Colors::NONE;

	std::shared_ptr<Text> m_Text;
};