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
	void SetActiveBackgroundColor(Color color);

	virtual void SizePosUpdateBefore() override;
	virtual void SizePosUpdateAfter() override;

	bool IsHovered();
	bool IsClicked();
	bool IsHeld();
	bool IsReleased();

	void OnEvent(Event& e);
	bool OnMouseClicked(MouseButtonPressedEvent& e);
	bool OnMouseReleased(MouseButtonReleasedEvent& e);
	bool OnMouseMoved(MouseMovedEvent& e);

	void Update();
	void Render(); //TODO

private:
	bool m_Hover;
	bool m_Pressed = false;
	bool m_PrevPressed = false;

	Color m_BgColor = Colors::NONE;
	Color m_BgActive = Colors::NONE;

	std::shared_ptr<Text> m_Text;
};