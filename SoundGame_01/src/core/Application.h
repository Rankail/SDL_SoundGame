#pragma once

#include "Window.h"

class Application
{
public:
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


};