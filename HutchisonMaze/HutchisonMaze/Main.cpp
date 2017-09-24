#include "SDL.h"
#include "SDLApp.h"

int main(int argc, char* argv[])
{
	const char* WINDOW_TITLE = "Hutchison Technologies Maze Game";
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	const bool FULLSCREEN = false;

	SDLApp* appInstance = SDLApp::GetInstance();

	appInstance->Init(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, FULLSCREEN);

	while (appInstance->IsRunning())
	{
		appInstance->HandleEvents();
		appInstance->Update();
		appInstance->Render();
	}

	appInstance->Destroy();

	return 0;
}