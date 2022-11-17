#pragma once

#include <cstdint>

enum Alignment
{
	LEFT = 0, CENTER = 1, RIGHT = 2
};

class Drawable
{
protected:
	virtual void SizePosUpdate();
	virtual void SizePosUpdateBefore() {}
	virtual void SizePosUpdateAfter() {}

public:
	Drawable(Alignment alignH = Alignment::LEFT, Alignment alignV = Alignment::LEFT);
	virtual ~Drawable() = default;

	virtual int32_t GetX() const { return m_X; }
	virtual int32_t GetY() const { return m_Y; }

	virtual void SetPos(int32_t x, int32_t y);
	virtual void SetX(int32_t x);
	virtual void SetY(int32_t y);

	virtual void SetSize(int32_t w, int32_t h);
	virtual void SetWidth(int32_t w);
	virtual void SetHeight(int32_t h);

	virtual void SetAlignment(Alignment alignH, Alignment alignV);
	virtual void SetAlignmentH(Alignment align);
	virtual void SetAlignmentV(Alignment align);

	virtual void SetPadding(int32_t padLeft, int32_t padRight, int32_t padTop, int32_t padBottom);
	virtual void SetPadding(int32_t padHorizontal, int32_t padVertical);
	virtual void SetPadding(int32_t pad);
	virtual void SetPaddingH(int32_t pad);
	virtual void SetPaddingV(int32_t pad);
	virtual void SetPaddingLeft(int32_t pad);
	virtual void SetPaddingRight(int32_t pad);
	virtual void SetPaddingTop(int32_t pad);
	virtual void SetPaddingBottom(int32_t pad);

	virtual int32_t GetTopLeftX() const { return m_TLX; }
	virtual int32_t GetTopLeftY() const { return m_TLY; }
	
	virtual int32_t GetObjTopLeftX() const { return m_OTLX; }
	virtual int32_t GetObjTopLeftY() const { return m_OTLY; }

	virtual int32_t GetWidth() const { return m_PadL + GetObjectWidth() + m_PadR; }
	virtual int32_t GetHeight() const { return m_PadT + GetObjectHeight() + m_PadB; }

	virtual int32_t GetObjectWidth() const { return m_ObjWidth; }
	virtual int32_t GetObjectHeight() const { return m_ObjHeight; }

	virtual int32_t GetPaddingTop() const { return m_PadT; }
	virtual int32_t GetPaddingBottom() const { return m_PadB; }
	virtual int32_t GetPaddingLeft() const { return m_PadL; }
	virtual int32_t GetPaddingRight() const { return m_PadR; }

	virtual Alignment GetAlignmentH() const { return m_AlignH; }
	virtual Alignment GetAlignmentV() const { return m_AlignV; }

	virtual void Update(float dt) {}
	virtual void Render() {}

protected:
	int32_t m_X = 0;
	int32_t m_Y = 0;

	int32_t m_TLX = 0;
	int32_t m_TLY = 0;

	int32_t m_OTLX = 0;
	int32_t m_OTLY = 0;

	Alignment m_AlignH;
	Alignment m_AlignV;

	int32_t m_ObjWidth = 0;
	int32_t m_ObjHeight = 0;

	int32_t m_PadL = 0, m_PadR = 0, m_PadT = 0, m_PadB = 0;
};