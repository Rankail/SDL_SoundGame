#include "StartMenu.h"

#include "rts/events/MouseEvent.h"

void StartMenu::OnCreate()
{
	TextureLib::AddTexture("rsc/textures/Bounce.png", "bounce");
	m_Title = std::make_shared<Text>("Hello World!", "arial", 18);
}

void StartMenu::OnEvent(Event& e)
{
	EventSplitter splitter(e);
	splitter.Dispatch<MouseButtonPressedEvent>(BIND_FN(StartMenu::OnMousePress));
	splitter.Dispatch<MouseButtonReleasedEvent>(BIND_FN(StartMenu::OnMouseRelease));
	splitter.Dispatch<KeyReleasedEvent>(BIND_FN(StartMenu::OnKeyRelease));
}

bool StartMenu::OnMousePress(MouseButtonPressedEvent& e)
{
	if (e.GetMouseButton() == SDL_BUTTON_LEFT)
	{
		m_Pressed = true;
		return true;
	}

	return false;
}

bool StartMenu::OnMouseRelease(MouseButtonReleasedEvent& e)
{
	if (e.GetMouseButton() == SDL_BUTTON_LEFT)
	{
		m_Pressed = false;
		return true;
	}

	return false;
}

bool StartMenu::OnKeyRelease(KeyReleasedEvent& e)
{
	if (e.GetKeyCode() == SDL_SCANCODE_ESCAPE)
	{
		LayerManager::PopLayer();
		return true;
	}

	return false;
}

void StartMenu::OnRender()
{
	if (m_Pressed)	Renderer::SetColor(Colors::LIGHT_BLUE);
	else			Renderer::SetColor(Colors::OLIVE);
	
	Renderer::FillRect(20, 30, 50, 40);
	Renderer::RenderTexture(TextureLib::GetTexture("bounce"), 50, 50, 200, 200);
	Renderer::RenderText(m_Title, 400, 400);
}
