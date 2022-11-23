#include "StartMenu.h"

#include "Menu.h"

void StartMenu::OnCreate()
{
	FontLib::AddFont("rsc/fonts/arialbd.ttf", 72, "arialb");
	FontLib::AddFont("rsc/fonts/arialbd.ttf", 20, "arialb");

	m_Title = std::make_shared<Text>("TETRIS", "arialb", 72);
	m_BtnPressToStart = std::make_shared<TextureButton>();
	m_BtnPressToStart->SetText("Press Enter");
	m_BtnPressToStart->SetTextColor(Color(0xcc, 0xcc, 0xcc));
	m_BtnPressToStart->SetFont("arialb", 20);
	m_BtnPressToStart->SetTexture("rsc/textures/buttons/Template.png");
	m_BtnPressToStart->SetTextureActive("rsc/textures/buttons/TemplateActive.png");

	LayerManager::AddLayer("menu", std::make_shared<Menu>());
}

void StartMenu::OnResize(int32_t width, int32_t height)
{
	m_Title->SetAlignment(Alignment::CENTER, Alignment::CENTER);
	m_Title->SetPos(width / 2, height / 3);

	m_BtnPressToStart->SetAlignment(Alignment::CENTER, Alignment::CENTER);
	m_BtnPressToStart->SetPos(width / 2, height * 2 / 3);
}

void StartMenu::OnEvent(Event& e)
{
	m_BtnPressToStart->OnEvent(e);
	EventSplitter splitter(e);
	splitter.Dispatch<KeyReleasedEvent>(BIND_FN(StartMenu::OnKeyRelease));
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

bool StartMenu::OnUpdate(float dt)
{
	if (m_BtnPressToStart->GetStatus() == ButtonState::RELEASED)
	{
		LayerManager::SwitchTo("menu");
	}

	m_BtnPressToStart->Update(dt);
	return false;
}

void StartMenu::OnRender()
{
	Renderer::SetColor(Colors::TURQOISE);
	Renderer::FillRect(m_Title->GetTopLeftX()-15, m_Title->GetTopLeftY()-15, m_Title->GetWidth()+30, m_Title->GetHeight()+30);
	Renderer::SetColor(Colors::BLACK);
	Renderer::FillRect(m_Title->GetTopLeftX()-10, m_Title->GetTopLeftY()-10, m_Title->GetWidth()+20, m_Title->GetHeight()+20);
	m_Title->Render();
	m_BtnPressToStart->Render();
}
