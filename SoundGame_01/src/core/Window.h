#pragma once

#include <SDL.h>

class Window
{
public:
	Window(const char* title, uint32_t width, uint32_t height);
	virtual ~Window();

	SDL_Window* GetSDLWindow() { return m_Window; }

	SDL_Point GetWindowSize();
	uint32_t GetWindowFlags() { return SDL_GetWindowFlags(m_Window); }

private:
	SDL_Window* m_Window;
};