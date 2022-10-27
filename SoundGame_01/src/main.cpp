#include "rtspch.h"

int main(int argc, char** argv)
{
	SDL_Window* window;
	SDL_Renderer* renderer;

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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {

	}

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
			else if (e.type == SDL_KEYUP) {
				if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					quit = true;
				}
			}
		}

		//update

		//render
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x33, 0xFF);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderFillRect(renderer, new SDL_Rect{ 20, 30, 50, 40 });

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}