#pragma once

#include "rts.h"

class Menu : public Layer
{
public:

	virtual void OnCreate() override;
	virtual void OnResize(int32_t width, int32_t height) override;

	virtual void OnEvent(Event& e) override;
	bool OnKeyRelease(KeyReleasedEvent& e);

	virtual void OnRender() override;

private:
	std::shared_ptr<Button> m_Button;
};