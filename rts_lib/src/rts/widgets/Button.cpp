#include "rtspch.h"

#include "Button.h"
#include "rts/events/EventManager.h"

Button::Button()
{
}

Button::~Button()
{
}

bool Button::IsHovered()
{
	return m_Hover;
}

bool Button::IsClicked()
{
	return m_Pressed && !m_PrevPressed;
}

bool Button::IsHeld()
{
	return m_Pressed && m_PrevPressed && m_Hover;
}

bool Button::IsReleased()
{
	return !m_Pressed && m_PrevPressed;
}

void Button::OnEvent(Event& e)
{
	EventSplitter splitter(e);
	splitter.Dispatch<MouseButtonPressedEvent>(BIND_FN(Button::OnMouseClicked));
	splitter.Dispatch<MouseButtonReleasedEvent>(BIND_FN(Button::OnMouseReleased));
}

bool Button::OnMouseClicked(MouseButtonPressedEvent& e)
{
	if (e.GetMouseButton() == SDL_BUTTON_LEFT && m_Hover)
	{
		m_Pressed = true;
		return true;
	}
	return false;
}

bool Button::OnMouseReleased(MouseButtonReleasedEvent& e)
{
	if (e.GetMouseButton() == SDL_BUTTON_LEFT && m_Pressed)
	{
		m_Pressed = false;
		m_PrevPressed = m_Hover;
		return true;
	}
	return false;
}

void Button::Update()
{
	m_PrevPressed = m_Pressed;
}

void Button::Render()
{
}
