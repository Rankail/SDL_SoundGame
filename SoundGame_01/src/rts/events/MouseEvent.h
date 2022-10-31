#pragma once

#include "Event.h"
#include <cstdint>

class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(const float x, const float y)
		: m_MouseX(x), m_MouseY(y)
	{}

	float GetX() const { return m_MouseX; }
	float GetY() const { return m_MouseY; }

	EVENT_CLASS_TYPE(MouseMoved)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

private:
	float m_MouseX, m_MouseY;
};

class MouseScrolledEevnt : public Event
{
public:
	MouseScrolledEevnt(const float xOffset, const float yOffset)
		: m_XOffset(xOffset), m_YOffset(yOffset)
	{}

	float GetXOffset() const { return m_XOffset; }
	float GetYOffset() const { return m_YOffset; }

	EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

private:
	float m_XOffset, m_YOffset;
};

class MouseButtonEvent : public Event
{
public:
	uint8_t GetMouseButton() const { return m_MouseButton; }

	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

protected:
	MouseButtonEvent(const uint8_t button)
		: m_MouseButton(button)
	{}

	uint8_t m_MouseButton;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(const uint8_t button, bool isRepeat = false)
		: MouseButtonEvent(button), m_IsRepeat(isRepeat)
	{}

	bool isRepeat() const { return m_IsRepeat; }

	EVENT_CLASS_TYPE(MouseButtonPressed)

private:
	bool m_IsRepeat;
};


class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(const uint8_t button)
		: MouseButtonEvent(button)
	{}

	EVENT_CLASS_TYPE(MouseButtonReleased)
};