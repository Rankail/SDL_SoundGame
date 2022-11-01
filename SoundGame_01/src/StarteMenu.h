#pragma once

#include "rts.h"

class StartMenu : public Layer
{
public:
	virtual void OnEvent(Event& e) override;
	bool OnMousePress(MouseButtonPressedEvent& e);
	bool OnMouseRelease(MouseButtonReleasedEvent& e);
	bool OnKeyRelease(KeyReleasedEvent& e);

	virtual void OnRender() override;

private:
	bool m_Pressed = false;
};