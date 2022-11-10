#include "StartMenu.h"

#include "Menu.h"

void StartMenu::OnCreate()
{

	FontLib::AddFont("rsc/fonts/arialbd.ttf", 72, "arialb");
	FontLib::AddFont("rsc/fonts/arialbd.ttf", 20, "arialb");

	m_Title = std::make_shared<Text>("TETRIS", "arialb", 72);
	m_PressToStart = std::make_shared<Text>("< Press Enter >", "arialb", 20);

	LayerManager::AddLayer("menu", std::make_shared<Menu>());
}

void StartMenu::OnResize(int32_t width, int32_t height)
{
	m_Title->SetAlignment(Alignment::CENTER, Alignment::CENTER);
	m_Title->SetPos(width / 2, height / 3);

	m_PressToStart->SetAlignment(Alignment::CENTER, Alignment::CENTER);
	m_PressToStart->SetPos(width / 2, height * 2 / 3);
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
		LayerManager::Clear();
		return true;
	}
	else if (e.GetKeyCode() == SDL_SCANCODE_RETURN)
	{
		LayerManager::SwitchTo("menu");
		return true;
	}

	return false;
}

void StartMenu::OnRender()
{
	Renderer::SetColor(Colors::TURQOISE);
	Renderer::FillRect(m_Title->GetTopLeftX()-15, m_Title->GetTopLeftY()-15, m_Title->GetWidth()+30, m_Title->GetHeight()+30);
	Renderer::SetColor(Colors::BLACK);
	Renderer::FillRect(m_Title->GetTopLeftX()-10, m_Title->GetTopLeftY()-10, m_Title->GetWidth()+20, m_Title->GetHeight()+20);
	m_Title->Render();
	m_PressToStart->Render();
}
