#pragma once

#include "rts/widgets/Text.h"
#include "rts/events/MouseEvent.h"

enum class ButtonState
{
	IDLE, CLICKED, HELD, RELEASED
};

class Button : public Drawable
{
public:
	Button();
	virtual ~Button();

	void SetText(const std::string& text);
	void SetFont(const std::string& font, int32_t pointSize);
	void SetFont(std::shared_ptr<Font> font);
	void SetTextColor(Color color);
	void SetBackgroundColor(Color color);

	virtual void SetPos(int32_t x, int32_t y) override;
	virtual void SetX(int32_t x) override;
	virtual void SetY(int32_t y) override;

	bool IsHovered();
	bool IsClicked();
	bool IsHeld();
	bool IsReleased();

	void OnEvent(Event& e);
	bool OnMouseClicked(MouseButtonPressedEvent& e);
	bool OnMouseReleased(MouseButtonReleasedEvent& e);

	void Update();
	void Render(); //TODO

private:
	bool m_Hover;
	bool m_Pressed = false;
	bool m_PrevPressed = false;

	Color m_BgColor = Colors::NONE;

	std::shared_ptr<Text> m_Text;
};