#include "rtspch.h"

#include "Button.h"
#include "rts/events/EventManager.h"
#include "rts/renderer/Renderer.h"

Button::Button()
	: AbstractButton()
{}

Button::~Button()
{
}

void Button::SetProperties(const ButtonProperties& properties)
{
	m_BgColor = properties.backgroundColor;
	m_BgActive = properties.backgroundColorActive;
	m_Text->SetFont(properties.font);
	m_Text->SetColor(properties.textColor);
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
