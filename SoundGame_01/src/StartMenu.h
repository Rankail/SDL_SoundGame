#pragma once

#include "rts.h"

class StartMenu : public Layer
{
public:
	virtual void OnCreate() override;

	virtual void OnResize(int32_t width, int32_t height);
	virtual void OnEvent(Event& e) override;
	bool OnKeyRelease(KeyReleasedEvent& e);

	virtual bool OnUpdate(float dt) override;
	virtual void OnRender() override;

private:
	bool m_Pressed = false;
	std::shared_ptr<Text> m_Title;
	std::shared_ptr<TextureButton> m_BtnPressToStart;
};