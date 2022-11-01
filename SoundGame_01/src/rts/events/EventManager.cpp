#include "rtspch.h"

#include "EventManager.h"
#include "WindowEvent.h"
#include "KeyEvent.h"
#include "MouseEvent.h"

EventManager::EventCallbackFn EventManager::m_Callback;

void EventManager::PollEvents()
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_WINDOWEVENT)
		{
			if (ev.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				WindowCloseEvent e;
				m_Callback(e);
			}
			else if (ev.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				WindowResizeEvent e(ev.window.data1, ev.window.data2);
				m_Callback(e);
			}
			else if (ev.window.event == SDL_WINDOWEVENT_MOVED)
			{
				WindowMovedEvent e(ev.window.data1, ev.window.data2);
				m_Callback(e);
			}
			else if (ev.window.event == SDL_WINDOWEVENT_MINIMIZED)
			{
				WindowMinimizedEvent e;
				m_Callback(e);
			}
			else if (ev.window.event == SDL_WINDOWEVENT_RESTORED)
			{
				WindowRestoredEvent e;
				m_Callback(e);
			}
			else if (ev.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
			{
				WindowFocusEvent e;
				m_Callback(e);
			}
			else if (ev.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
			{
				WindowLostFocusEvent e;
				m_Callback(e);
			}
		}
		else if (ev.type == SDL_KEYDOWN)
		{
			KeyPressedEvent e(ev.key.keysym.scancode, ev.key.repeat);
			m_Callback(e);
		}
		else if (ev.type == SDL_KEYUP)
		{
			KeyReleasedEvent e(ev.key.keysym.scancode);
			m_Callback(e);
		}
		else if (ev.type == SDL_MOUSEBUTTONDOWN)
		{
			MouseButtonPressedEvent e(ev.button.button);
			m_Callback(e);
		}
		else if (ev.type == SDL_MOUSEBUTTONUP)
		{
			MouseButtonReleasedEvent e(ev.button.button);
			m_Callback(e);
		}
		else if (ev.type == SDL_MOUSEMOTION)
		{
			MouseMovedEvent e((float)ev.motion.x, (float)ev.motion.y);
			m_Callback(e);
		}
		else if (ev.type == SDL_MOUSEWHEEL)
		{
			MouseScrolledEvent e((float)ev.wheel.x, (float)ev.wheel.y);
			m_Callback(e);
		}
	}
}

void EventManager::SetEventCallback(EventCallbackFn func)
{
	m_Callback = func;
}
