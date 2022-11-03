#include "rts.h"

#include "StartMenu.h"

int main(int argc, char** argv)
{
	Application* app;
	try
	{
		app = Application::Create();
	}
	catch (InitException& e)
	{
		LOG_CRITICAL(e.what());
		return -1;
	}

	Renderer::SetClearColor(Colors::BLACK);

	auto startmenu = std::make_shared<StartMenu>();
	LayerManager::AddLayer("start", startmenu);
	LayerManager::PushLayer("start");

	app->Run();
	Application::Delete();

	return 0;
}