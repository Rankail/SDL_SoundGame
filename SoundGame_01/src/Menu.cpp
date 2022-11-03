#include "Menu.h"

void Menu::OnEvent(Event& e)
{
	EventSplitter splitter(e);
	splitter.Dispatch<KeyReleasedEvent>(BIND_FN(Menu::OnKeyRelease));
}

bool Menu::OnKeyRelease(KeyReleasedEvent& e)
{
	if (e.GetKeyCode() == SDL_SCANCODE_ESCAPE)
	{
		LayerManager::SwitchTo("start");
		return true;
	}

	return false;
}

void Menu::OnRender()
{
	Renderer::SetColor(Colors::RED);
	Renderer::FillRect(10, 10, 100, 200);
}
