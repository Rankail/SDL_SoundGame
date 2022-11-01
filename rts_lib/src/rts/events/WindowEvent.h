#pragma once

#include "Event.h"

#include <cstdint>

// Window was resized
class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(uint32_t width, uint32_t height)
		: m_Width(width), m_Height(height)
	{}

	uint32_t GetWidth() const { return m_Width; }
	uint32_t GetHeight() const { return m_Height; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << GetName() << ": " << m_Width << ", " << m_Height;
		return ss.str();
	}

	EVENT_CLASS_TYPE(WindowResize)
	EVENT_CLASS_CATEGORY(EventCategoryWindow)

private:
	uint32_t m_Width, m_Height;
};

// IWndow was closed
class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;

	EVENT_CLASS_TYPE(WindowClose)
	EVENT_CLASS_CATEGORY(EventCategoryWindow)
};

// Window gained focus
class WindowFocusEvent : public Event
{
public:
	WindowFocusEvent() = default;

	EVENT_CLASS_TYPE(WindowFocus)
	EVENT_CLASS_CATEGORY(EventCategoryWindow)
};

// WIndow lost focus
class WindowLostFocusEvent : public Event
{
public:
	WindowLostFocusEvent() = default;

	EVENT_CLASS_TYPE(WindowLostFocus)
	EVENT_CLASS_CATEGORY(EventCategoryWindow)
};

// Window was minimized
class WindowMinimizedEvent : public Event
{
public:
	WindowMinimizedEvent() = default;

	EVENT_CLASS_TYPE(WindowMinimized)
	EVENT_CLASS_CATEGORY(EventCategoryWindow)
};

// Window was restored from minimize (or maximize?)
class WindowRestoredEvent : public Event
{
public:
	WindowRestoredEvent() = default;

	EVENT_CLASS_TYPE(WindowRestored)
	EVENT_CLASS_CATEGORY(EventCategoryWindow)
};

// Window was moved
class WindowMovedEvent : public Event
{
public:
	WindowMovedEvent(int32_t newX, int32_t newY)
		: m_NewX(newX), m_NewY(newY)
	{}

	int32_t GetWindowNewX() const { return m_NewX; }
	int32_t GetWindowNewY() const { return m_NewY; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << GetName() << ": " << m_NewX << ", " << m_NewY;
		return ss.str();
	}

	EVENT_CLASS_TYPE(WindowMoved)
	EVENT_CLASS_CATEGORY(EventCategoryWindow)

private:
	int32_t m_NewX, m_NewY;
};