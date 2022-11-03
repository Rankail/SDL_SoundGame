#include "rtspch.h"

#include "Drawable.h"

Drawable::Drawable(Alignment alignH, Alignment alignV)
	: m_AlignH(alignH), m_AlignV(alignV)
{}

void Drawable::SizePosUpdate()
{
	m_TLX = m_X - ((2 - m_AlignH) * GetWidth() / 2);
	m_TLY = m_Y - ((2 - m_AlignV) * GetHeight() / 2);
}

void Drawable::SetPos(int32_t x, int32_t y)
{
	m_X = x;
	m_Y = y;
	SizePosUpdate();
}

void Drawable::SetX(int32_t x)
{
	m_X = x;
	SizePosUpdate();
}

void Drawable::SetY(int32_t y)
{
	m_Y = y;
	SizePosUpdate();
}

void Drawable::SetAlignment(Alignment alignH, Alignment alignV)
{
	m_AlignH = alignH;
	m_AlignV = alignV;
	SizePosUpdate();
}

void Drawable::SetAlignmentH(Alignment align)
{
	m_AlignH = align;
	SizePosUpdate();
}

void Drawable::SetAlignmentV(Alignment align)
{
	m_AlignV = align;
	SizePosUpdate();
}
