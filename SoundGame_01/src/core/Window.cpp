#include "rtspch.h"

#include "Window.h"
#include "Exceptions.h"

Window::Window(const char* title, uint32_t width, uint32_t height)
{
    m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (m_Window == NULL) {
        throw InitException("Failed to create Window");
    }
}

Window::~Window()
{
}

SDL_Point Window::GetWindowSize()
{
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    return SDL_Point(w, h);
}
