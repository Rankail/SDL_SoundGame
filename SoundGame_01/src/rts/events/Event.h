#pragma once

#include "rts/core/Base.h"

enum class EventType
{
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	KeyPressed, KeyReleased, KeyTyped,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

enum EventCategory
{
	None = 0,
	EventCategoryWindow			= BIT(0),
	EventCategoryInput			= BIT(1),
	EventCategoryKeyboard		= BIT(2),
	EventCategoryMouse			= BIT(3),
	EventCategoryMouseButton	= BIT(4)
};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
	virtual EventType GetEventType() const override { return GetStaticType(); }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

class Event
{
public:
	virtual ~Event() = default;

	virtual EventType GetEventType() const = 0;
	virtual int GetCategoryFlags() const = 0;

	bool IsInCategory(EventCategory category)
	{
		return GetCategoryFlags() & category;
	}

protected:
	bool m_Handled = false;
};