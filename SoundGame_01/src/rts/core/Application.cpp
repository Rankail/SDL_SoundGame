#include "rtspch.h"
#include "Application.h"

#include "rts/renderer/Renderer.h"
#include "rts/core/Exceptions.h"
#include "rts/core/Log.h"

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

	Log::Init();

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG_CRITICAL("Failed to initialize SDL.\n{}", SDL_GetError());
		throw InitException("Failed to initialize SDL");
	}

	int imgFlags = IMG_INIT_PNG;
	if ((~IMG_Init(imgFlags)) & imgFlags)
	{
		LOG_CRITICAL("Failed to initialize SD_imageL.\n{}", SDL_GetError());
		throw InitException("Failed to initialize SDL_image", SDL_GetError());
	}

	if (TTF_Init() == -1)
	{
		LOG_CRITICAL("Failed to initialize SDL_ttf.\n{}", SDL_GetError());
		throw InitException("Failed to initialize SDL_ttf", SDL_GetError());
	}

	m_Window = Window::Create("Sound Game 01", 800, 600);
	Renderer::Init();
	Renderer::SetClearColor(Colors::DARK_RED);

	LOG_TRACE("Finished initialization of App");
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
