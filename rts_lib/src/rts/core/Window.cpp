#include "rtspch.h"
#include "Window.h"

#include "rts/core/Exceptions.h"

std::shared_ptr<Window> Window::Create(const char* title, uint32_t width, uint32_t height)
{
    return std::make_shared<Window>(title, width, height);
}

Window::Window(const char* title, uint32_t width, uint32_t height)
    : m_Width(width), m_Height(height)
{
    m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (m_Window == NULL) {
        LOG_CRITICAL("Failed to create window.\n{}", SDL_GetError());
        throw InitException("Failed to create window");
    }
}

Window::~Window()
{
    SDL_DestroyWindow(m_Window);
}

void Window::OnResize(int32_t width, int32_t height)
{
    m_Width = width;
    m_Height = height;
}
