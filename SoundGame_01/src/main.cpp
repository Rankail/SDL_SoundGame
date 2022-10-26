#include <SDL.h>
#include <iostream>

int main(int argc, char** argv)
{
	SDL_Window* window;
	SDL_Surface* surface;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to initialize SDL! Error:\n" << SDL_GetError() << std::endl;
		return -1;
	}

	window = SDL_CreateWindow("SoundGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Failed to create window! Error:\n" << SDL_GetError() << std::endl;
		return -1;
	}

	surface = SDL_GetWindowSurface(window);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x88, 0x44, 0x00));

	SDL_UpdateWindowSurface(window);

	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}