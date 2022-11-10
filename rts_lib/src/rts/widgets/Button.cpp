#include "rtspch.h"

#include "Button.h"
#include "rts/events/EventManager.h"
#include "rts/renderer/Renderer.h"

Button::Button()
{
	m_Text = std::make_shared<Text>();
}

Button::~Button()
{
}

void Button::SetText(const std::string& text)
{
	m_Text->SetText(text);
	SizePosUpdate();
}

void Button::SetFont(const std::string& font, int32_t pointSize)
{
	m_Text->SetFont(font, pointSize);
	SizePosUpdate();
}

void Button::SetFont(std::shared_ptr<Font> font)
{
	m_Text->SetFont(font);
	SizePosUpdate();
}

void Button::SetTextColor(Color color)
{
	m_Text->SetColor(color);
	SizePosUpdate();
}

void Button::SetBackgroundColor(Color color)
{
	m_BgColor = color;
}

void Button::SetActiveBackgroundColor(Color color)
{
	m_BgActive = color;
}

void Button::SizePosUpdateBefore()
{
	m_ObjWidth = m_Text->GetWidth();
	m_ObjHeight = m_Text->GetHeight();
}

void Button::SizePosUpdateAfter()
{
	m_Text->SetPos(m_OTLX, m_OTLY);
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
	splitter.Dispatch<MouseMovedEvent>(BIND_FN(Button::OnMouseMoved));
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

bool Button::OnMouseMoved(MouseMovedEvent& e)
{
	m_Hover = (e.GetX() >= m_TLX && e.GetY() >= m_TLY && e.GetX() < m_TLX + GetWidth() && e.GetY() < m_TLY + GetHeight());
	return false;
}

void Button::Update()
{
	m_PrevPressed = m_Pressed;
}

void Button::Render()
{
	if (!m_Text->IsCreated()) return;

	if (m_Hover && m_Pressed && m_BgActive)
		Renderer::SetColor(m_BgActive);
	else
		Renderer::SetColor(m_BgColor);
	Renderer::FillRect(m_TLX, m_TLY, GetWidth(), GetHeight());
	m_Text->Render();
}
