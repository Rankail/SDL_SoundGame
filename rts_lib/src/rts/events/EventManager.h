#pragma once

#include "Event.h"
#include <queue>

class EventManager
{
public:
	EventManager() = delete;
	virtual ~EventManager() = delete;
	EventManager(const EventManager& other) = delete;


	using EventCallbackFn = std::function<void(Event&)>;

	static void PollEvents();
	static void SetEventCallback(EventCallbackFn func);

private:
	static EventCallbackFn m_Callback;
};

class EventSplitter
{
public:
	EventSplitter(Event& e)
		: m_Event(e)
	{}

	template<typename T, typename F>
	bool Dispatch(const F& func)
	{
		if (m_Event.GetEventType() == T::GetStaticType())
		{
			m_Event.Handled |= func(static_cast<T&>(m_Event));
			return true;
		}
		return false;
	}

private:
	Event& m_Event;
};