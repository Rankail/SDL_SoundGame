#pragma once

#include "rts/events/Event.h"
#include <cstdint>

class Layer
{
public:
	Layer() = default;
	virtual ~Layer() = default;

	virtual void OnCreate() {}
	virtual void OnResize(int32_t width, int32_t height) {}
	virtual void OnDelete() {}

	virtual void OnPush() {}
	virtual void OnPop() {}

	virtual bool OnUpdate(float dt) { return true; }
	virtual void OnEvent(Event& e) {}
	virtual void OnRender() {}
};