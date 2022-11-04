#include "rtspch.h"

#include "Drawable.h"

Drawable::Drawable(Alignment alignH, Alignment alignV)
	: m_AlignH(alignH), m_AlignV(alignV)
{}

void Drawable::SizePosUpdate()
{
	m_TLX = m_X - ((2 - m_AlignH) * GetWidth() / 2);
	m_TLY = m_Y - ((2 - m_AlignV) * GetHeight() / 2);
	m_OTLX = m_TLX + m_PadL;
	m_OTLY = m_TLY + m_PadT;
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

void Drawable::SetPadding(int32_t padLeft, int32_t padRight, int32_t padTop, int32_t padBottom)
{
	m_PadL = padLeft;
	m_PadR = padRight;
	m_PadT = padTop;
	m_PadB = padBottom;
}

void Drawable::SetPadding(int32_t padHorizontal, int32_t padVertical)
{
	m_PadL = padHorizontal;
	m_PadR = padHorizontal;
	m_PadT = padVertical;
	m_PadB = padVertical;

}

void Drawable::SetPadding(int32_t pad)
{
	m_PadL = pad;
	m_PadR = pad;
	m_PadT = pad;
	m_PadB = pad;
}

void Drawable::SetPaddingH(int32_t pad)
{
	m_PadL = pad;
	m_PadR = pad;
}

void Drawable::SetPaddingV(int32_t pad)
{
	m_PadT = pad;
	m_PadB = pad;
}

void Drawable::SetPaddingLeft(int32_t pad)
{
	m_PadL = pad;
}

void Drawable::SetPaddingRight(int32_t pad)
{
	m_PadR = pad;
}

void Drawable::SetPaddingTop(int32_t pad)
{
	m_PadT = pad;
}

void Drawable::SetPaddingBottom(int32_t pad)
{
	m_PadB = pad;
}
