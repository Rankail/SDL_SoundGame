#pragma once

#include "rts.h"

class Menu : public Layer
{
public:

	virtual void OnEvent(Event& e);
	bool OnKeyRelease(KeyReleasedEvent& e);

	virtual void OnRender() override;
};