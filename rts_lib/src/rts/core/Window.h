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

	void OnResize(int32_t width, int32_t height);

	int32_t GetWindowWidth() const { return m_Width; }
	int32_t GetWindowHeight() const { return m_Height; }
	uint32_t GetWindowFlags() { return SDL_GetWindowFlags(m_Window); }

private:
	int32_t m_Width, m_Height;
	SDL_Window* m_Window;
};