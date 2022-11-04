#include "rtspch.h"

#include "Button.h"
#include "rts/events/EventManager.h"
#include "rts/renderer/Renderer.h"

Button::Button()
{}

Button::~Button()
{
}

void Button::SetText(const std::string& text)
{
	m_Text->SetText(text);
}

void Button::SetFont(const std::string& font, int32_t pointSize)
{
	m_Text->SetFont(font, pointSize);
}

void Button::SetFont(std::shared_ptr<Font> font)
{
	m_Text->SetFont(font);
}

void Button::SetTextColor(Color color)
{
	m_Text->SetColor(color);
}

void Button::SetBackgroundColor(Color color)
{
	m_BgColor = color;
}

void Button::SetPos(int32_t x, int32_t y)
{
	m_Text->SetPos(x + m_PadL, y + m_PadT);
	Drawable::SetPos(x, y);
}

void Button::SetX(int32_t x)
{
	m_Text->SetX(x + m_PadL);
	Drawable::SetX(x);
}

void Button::SetY(int32_t y)
{
	m_Text->SetY(y + m_PadL);
	Drawable::SetY(y);
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
	if (!m_Text->IsCreated()) return;

	Renderer::SetColor(m_BgColor);
	Renderer::FillRect(m_TLX, m_TLY, m_ObjWidth, m_ObjHeight);
	m_Text->Render();
}
