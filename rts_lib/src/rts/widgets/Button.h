#pragma once

#include "rts/renderer/Text.h"
#include "rts/events/MouseEvent.h"

enum class ButtonState
{
	IDLE, CLICKED, HELD, RELEASED
};

class Button : public Drawable
{
public:
	Button(); //TODO
	virtual ~Button();

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

	std::shared_ptr<Text> m_Text;
};