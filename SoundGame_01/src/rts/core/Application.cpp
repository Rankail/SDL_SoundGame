#include "rtspch.h"
#include "Application.h"

#include "rts/renderer/Renderer.h"
#include "rts/core/Exceptions.h"

Application* Application::instance = nullptr;

Application* Application::Create()
{
	new Application();
	return instance;
}

void Application::Delete()
{
	delete instance;
	instance = nullptr;
}

Application* Application::GetInstance()
{
	return instance;
}

Application::Application()
{
	instance = this;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw InitException("Failed to initialize SDL", SDL_GetError());
	}

	int imgFlags = IMG_INIT_PNG;
	if ((~IMG_Init(imgFlags)) & imgFlags)
	{
		throw InitException("Failed to initialize SDL_image", SDL_GetError());
	}

	if (TTF_Init() == -1)
	{
		throw InitException("Failed to initialize SDL_ttf", SDL_GetError());
	}

	m_Window = Window::Create("Sound Game 01", 800, 600);
	Renderer::Init();
	Renderer::SetClearColor(Colors::DARK_RED);
}

Application::~Application()
{
	Renderer::Shutdown();
}

void Application::Run()
{
	while (!m_Quit)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				Close();
			}
			if (e.type == SDL_KEYUP)
			{
				if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					Close();
				}
			}
		}

		//update

		//render
		Renderer::Clear();

		Renderer::SetColor(Colors::DARK_GREEN);
		Renderer::FillRect(20, 30, 50, 40);

		Renderer::Present();
	}
}

void Application::Close()
{
	m_Quit = true;
}
