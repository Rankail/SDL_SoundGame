#include "rtspch.h"

#include "Application.h"
#include "Exceptions.h"

Application* Application::instance = nullptr;

Application* Application::GetInstance()
{
	if (instance == nullptr) {
		instance = new Application();
	}
	return instance;
}

Application::Application()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw InitException(std::string("Failed to initialize SDL\n") + SDL_GetError());
	}

	m_Window = std::make_shared<Window>();
	Renderer::Init();
}

Application::~Application()
{
}

void Application::Run()
{

}

void Application::Close()
{
}
