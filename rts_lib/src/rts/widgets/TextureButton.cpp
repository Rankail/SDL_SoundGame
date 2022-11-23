#include "rtspch.h"
#include "TextureButton.h"

void TextureButton::SizePosUpdateBefore()
{
	m_ObjWidth = m_Text->GetWidth();
	m_ObjHeight = m_Text->GetHeight();
	int padX = (GetWidth() - GetObjectWidth()) / 2;
	int padY = (GetHeight() - GetObjectHeight()) / 2;
	m_PadL = padX;
	m_PadR = padX;
	m_PadT = padY;
	m_PadB = padY;
}

void TextureButton::SizePosUpdateAfter()
{
	m_Text->SetPos(m_OTLX, m_OTLY);
}

TextureButton::TextureButton()
	: AbstractButton()
{
	m_Texture = std::make_shared<Texture>();
	m_TextureActive = std::make_shared<Texture>();
}

TextureButton::~TextureButton()
{
}

void TextureButton::SetProperties(const ButtonProperties& properties)
{
	m_Text->SetFont(properties.font);
	m_Text->SetColor(properties.textColor);
	SizePosUpdate();
}

void TextureButton::SetTexture(std::shared_ptr<Texture> texture)
{
	m_Texture = texture;
	SizePosUpdate();
}

void TextureButton::SetTexture(const std::string& file)
{
	m_Texture = TextureLib::LoadTexture(file);
	SizePosUpdate();
}

void TextureButton::SetTextureActive(std::shared_ptr<Texture> texture)
{
	m_TextureActive = texture;
}

void TextureButton::SetTextureActive(const std::string& file)
{
	m_TextureActive = TextureLib::LoadTexture(file);
}

void TextureButton::Render()
{
	if (m_Hover && m_Pressed && m_TextureActive->GetWidth() != 0)
		m_TextureActive->Render(m_TLX, m_TLY);
	else
		m_Texture->Render(m_TLX, m_TLY);
	m_Text->Render();
}
