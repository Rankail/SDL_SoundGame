#pragma once

#include "rts/core/Window.h"

#include <memory>

class Application
{
public:
	static Application* Create();
	static void Delete();
	static Application* GetInstance();
private:
	static Application* instance;
private:
	Application();
	~Application();

public:
	std::shared_ptr<Window> GetWindow() { return m_Window; }

	void Run();
	void Close();

private:
	std::shared_ptr<Window> m_Window;

	bool m_Quit = false;

};