#pragma once

#include "Event.h"
#include <queue>

class EventManager
{
public:
	using EventCallbackFn = std::function<void(Event&)>;

	static void PollEvents();
	static void SetEventCallback(EventCallbackFn func);

private:
	static EventCallbackFn m_Callback;
};