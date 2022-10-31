#pragma once

#include "Event.h"
#include <queue>

class EventManager
{
public:


private:
	std::queue<std::shared_ptr<Event>> m_EventQueue;
};