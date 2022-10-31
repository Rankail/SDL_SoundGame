#pragma once

#include <SDL.h>
#include "Event.h"

class KeyEvent : public Event
{
public:
	SDL_Scancode GetKeyCode() const { return m_KeyCode; }

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
	KeyEvent(SDL_Scancode keyCode)
		: m_KeyCode(keyCode)
	{}

	SDL_Scancode m_KeyCode;
};

class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(SDL_Scancode keyCode, bool isRepeat = false)
		: KeyEvent(keyCode), m_IsRepeat(isRepeat)
	{}

	bool IsRepeat() const { return m_IsRepeat; }

	EVENT_CLASS_TYPE(KeyPressed)

private:
	bool m_IsRepeat;
};

class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(SDL_Scancode keyCode)
		: KeyEvent(keyCode)
	{}

	EVENT_CLASS_TYPE(KeyReleased)
};

class KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent(SDL_Scancode keyCode)
		: KeyEvent(keyCode)
	{}

	EVENT_CLASS_TYPE(KeyTyped)
};