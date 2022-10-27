#include "rtspch.h"
#include "rts.h"

int main(int argc, char** argv)
{
	auto app = Application::Create();
	app->Run();
	Application::Delete();

	return 0;
}