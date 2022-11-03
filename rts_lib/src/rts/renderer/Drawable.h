#pragma once

#include <cstdint>

enum Alignment
{
	LEFT = 0, CENTER = 1, RIGHT = 2
};

class Drawable
{
public:
	Drawable(Alignment alignH = Alignment::LEFT, Alignment alignV = Alignment::LEFT);
	virtual ~Drawable() = default;

	virtual void SizePosUpdate();

	virtual int32_t GetX() const { return m_X; }
	virtual int32_t GetY() const { return m_Y; }

	virtual void SetPos(int32_t x, int32_t y);
	virtual void SetX(int32_t x);
	virtual void SetY(int32_t y);

	virtual void SetAlignment(Alignment alignH, Alignment alignV);
	virtual void SetAlignmentH(Alignment align);
	virtual void SetAlignmentV(Alignment align);

	virtual int32_t GetTopLeftX() const { return m_TLX; }
	virtual int32_t GetTopLeftY() const { return m_TLY; }

	virtual int32_t GetWidth() const { return m_Width; }
	virtual int32_t GetHeight() const { return m_Height; }

	virtual Alignment GetAlignmentH() const { return m_AlignH; }
	virtual Alignment GetAlignmentV() const { return m_AlignV; }

protected:
	int32_t m_X;
	int32_t m_Y;

	int32_t m_TLX;
	int32_t m_TLY;

	Alignment m_AlignH;
	Alignment m_AlignV;

	int32_t m_Width = 0;
	int32_t m_Height = 0;
};