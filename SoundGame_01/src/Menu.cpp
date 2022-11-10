#include "Menu.h"

void Menu::OnCreate()
{
	m_Button = std::make_shared<Button>();
	m_Button->SetText("Test Button");
	m_Button->SetFont("arialb", 20);
	m_Button->SetTextColor(Colors::YELLOW);
	m_Button->SetBackgroundColor(Colors::DARK_BLUE);
	m_Button->SetActiveBackgroundColor(Color(0, 0, 0x44));
}

void Menu::OnResize(int32_t width, int32_t height)
{
	m_Button->SetAlignment(Alignment::CENTER, Alignment::CENTER);
	m_Button->SetPos(width / 2, height / 2);
	m_Button->SetPadding(10);
}

void Menu::OnEvent(Event& e)
{
	EventSplitter splitter(e);
	splitter.Dispatch<KeyReleasedEvent>(BIND_FN(Menu::OnKeyRelease));
	m_Button->OnEvent(e);
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

bool Menu::OnUpdate(float dt)
{
	if (m_Button->IsClicked())
	{
		LOG_INFO("Click");
	}
	if (m_Button->IsHeld())
	{
		LOG_INFO("Held");
	}
	if (m_Button->IsReleased())
	{
		LOG_INFO("Release");
	}


	m_Button->Update();
	return false;
}

void Menu::OnRender()
{
	Renderer::SetColor(Colors::RED);
	Renderer::FillRect(10, 10, 100, 200);
	m_Button->Render();
}
