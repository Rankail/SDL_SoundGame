#include "Menu.h"

void Menu::OnCreate()
{
	m_Button = std::make_shared<Button>();
	m_Button->SetText()
}

void Menu::OnResize(int32_t width, int32_t height)
{
}

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
