#include "Menu.h"

void Menu::OnCreate()
{
	m_Buttons = std::make_shared<ButtonGroupV>();
	auto btnMarathon = std::make_shared<Button>();
	auto btn40Lines = std::make_shared<Button>();
	m_Buttons->AddButton("marathon", btnMarathon);
	m_Buttons->AddButton("40lines", btn40Lines);

	ButtonProperties props(Color(0, 0, 0x44), Color(0, 0, 0x25), Colors::YELLOW, "arialb", 20);
	
	btnMarathon->SetProperties(props);
	btnMarathon->SetText("Marathon");

	btn40Lines->SetProperties(props);
	btn40Lines->SetText("40 Lines");
}

void Menu::OnResize(int32_t width, int32_t height)
{
	m_Buttons->SetAlignment(Alignment::CENTER, Alignment::CENTER);
	m_Buttons->SetPos(width / 2, height / 2);
	m_Buttons->SetGap(15);

	auto btn = m_Buttons->GetButton("marathon");
	btn->SetPadding(10);
	btn = m_Buttons->GetButton("40lines");
	btn->SetPadding(10);

	m_Buttons->UpdateLayout();
}

void Menu::OnEvent(Event& e)
{
	EventSplitter splitter(e);
	splitter.Dispatch<KeyReleasedEvent>(BIND_FN(Menu::OnKeyRelease));
	m_Buttons->OnEvent(e);
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
	m_Buttons->Update(dt);
	return false;
}

void Menu::OnRender()
{
	m_Buttons->Render();
}
