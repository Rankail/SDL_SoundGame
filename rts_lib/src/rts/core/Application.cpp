#include "rtspch.h"
#include "Application.h"

#include "rts/renderer/Renderer.h"
#include "rts/core/Exceptions.h"
#include "rts/events/EventManager.h"
#include "rts/core/LayerManager.h"

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
		throw InitException("Failed to initialize SDL");
	}

	int imgFlags = IMG_INIT_PNG;
	if ((IMG_Init(imgFlags) & imgFlags) != imgFlags)
	{
		throw InitException("Failed to initialize SDL_image", SDL_GetError());
	}

	if (TTF_Init() == -1)
	{
		throw InitException("Failed to initialize SDL_ttf", SDL_GetError());
	}

	EventManager::SetEventCallback(BIND_FN(Application::OnEvent));

	m_Window = Window::Create("Sound Game 01", 800, 600);

	Renderer::Init();

	LOG_TRACE("Finished initialization of App");
}

Application::~Application()
{
	Renderer::Shutdown();
}

void Application::Run()
{
	uint32_t curTime, prevTime;
	curTime = SDL_GetTicks();
	prevTime = curTime;
	float dt = 0.f;

	while (!m_Quit)
	{
		uint32_t cTime = SDL_GetTicks();
		dt = (float)(curTime - prevTime) / 1000.f;

		// update
		for (auto it = LayerManager::rbegin(); it != LayerManager::rend(); ++it)
		{
			if (!(*it)->OnUpdate(dt)) break;
		}

		//render
		Renderer::Clear();

		for (auto it = LayerManager::begin(); it != LayerManager::end(); ++it)
		{
			(*it)->OnRender();
		}

		Renderer::Present();

		// events
		EventManager::PollEvents();

		if (LayerManager::Empty()) Close();
	}
}

void Application::Close()
{
	LayerManager::Clear();
	m_Quit = true;
}

void Application::OnEvent(Event& event)
{
	if (event.GetEventType() != EventType::MouseMoved)
		LOG_INFO(event.ToString());

	EventSplitter splitter(event);
	splitter.Dispatch<WindowCloseEvent>(BIND_FN(Application::OnWindowClose));
	splitter.Dispatch<WindowResizeEvent>(BIND_FN(Application::OnWindowResize));

	for (auto it = LayerManager::rbegin(); it != LayerManager::rend(); ++it)
	{
		if (event.Handled) break;

		(*it)->OnEvent(event);
	}
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	Close();
	return false;
}

bool Application::OnWindowResize(WindowResizeEvent& e)
{
	m_Window->OnResize(e.GetWidth(), e.GetHeight());
	for (auto it = LayerManager::begin(); it != LayerManager::end(); ++it)
	{
		(*it)->OnResize(e.GetWidth(), e.GetHeight());
	}
	return true;
}
