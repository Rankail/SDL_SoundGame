#include "rts.h"

#include "StarteMenu.h"

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

	FontLib::AddFont("rsc/fonts/arial.ttf", 18, "arial");
	FontLib::AddFont("rsc/fonts/arial.ttf", 20, "arial");

	std::shared_ptr<StartMenu> startmenu = std::make_shared<StartMenu>();
	LayerManager::AddLayer("start", startmenu);
	LayerManager::PushLayer("start");

	app->Run();
	Application::Delete();

	return 0;
}