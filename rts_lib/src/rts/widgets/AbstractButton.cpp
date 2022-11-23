#include "rtspch.h"
#include "AbstractButton.h"

#include "rts/events/EventManager.h"

AbstractButton::AbstractButton()
	: m_Text(std::make_shared<Text>())
{}

void AbstractButton::SetText(const std::string& text)
{
	m_Text->SetText(text);
	SizePosUpdate();
}

void AbstractButton::SetFont(const std::string& font, int32_t pointSize)
{
	m_Text->SetFont(font, pointSize);
	SizePosUpdate();
}

void AbstractButton::SetFont(std::shared_ptr<Font> font)
{
	m_Text->SetFont(font);
	SizePosUpdate();
}

void AbstractButton::SetTextColor(Color color)
{
	m_Text->SetColor(color);
}

ButtonState AbstractButton::GetStatus() const
{
	if (m_Pressed)
	{
		if (!m_PrevPressed) return ButtonState::CLICKED;
		if (m_Hover) return ButtonState::HELD;
		return ButtonState::IDLE;
	}
	if (m_PrevPressed) return ButtonState::RELEASED;
	return ButtonState::IDLE;
}

bool AbstractButton::IsHovered() const
{
	return m_Hover;
}

void AbstractButton::OnEvent(Event& e)
{
	EventSplitter splitter(e);
	splitter.Dispatch<MouseButtonPressedEvent>(BIND_FN(AbstractButton::OnMouseClicked));
	splitter.Dispatch<MouseButtonReleasedEvent>(BIND_FN(AbstractButton::OnMouseReleased));
	splitter.Dispatch<MouseMovedEvent>(BIND_FN(AbstractButton::OnMouseMoved));
}

bool AbstractButton::OnMouseClicked(MouseButtonPressedEvent& e)
{
	if (e.GetMouseButton() == SDL_BUTTON_LEFT && m_Hover)
	{
		m_Pressed = true;
		return true;
	}
	return false;
}

bool AbstractButton::OnMouseReleased(MouseButtonReleasedEvent& e)
{
	if (e.GetMouseButton() == SDL_BUTTON_LEFT && m_Pressed)
	{
		m_Pressed = false;
		m_PrevPressed = m_Hover;
		return true;
	}
	return false;
}

bool AbstractButton::OnMouseMoved(MouseMovedEvent& e)
{
	m_Hover = (e.GetX() >= m_TLX && e.GetY() >= m_TLY && e.GetX() < m_TLX + GetWidth() && e.GetY() < m_TLY + GetHeight());
	return false;
}

void AbstractButton::Update(float dt)
{
	m_PrevPressed = m_Pressed;
}
