#pragma once

#include <SDL.h>
#include <memory>

class Window
{
public:
	static std::shared_ptr<Window> Create(const char* title, uint32_t width, uint32_t height);

public:
	Window(const char* title, uint32_t width, uint32_t height);
	virtual ~Window();

	SDL_Window* GetSDLWindow() { return m_Window; }

	SDL_Point GetWindowSize();
	uint32_t GetWindowFlags() { return SDL_GetWindowFlags(m_Window); }

private:
	SDL_Window* m_Window;
};