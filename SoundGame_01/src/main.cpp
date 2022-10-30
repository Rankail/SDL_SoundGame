#include "rtspch.h"
#include "rts.h"

int main(int argc, char** argv)
{
	auto app = Application::Create();

	FontLib::AddFont("rsc/fonts/arial.ttf", 18, "arial");

	app->Run();
	Application::Delete();

	return 0;
}