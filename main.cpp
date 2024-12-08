
#include <SDL.h>

/*

struct player {
	float x = 600;
	float y = 350;
	float w = 16;
	float h = 16;

	SDL_Rect get_pos() {
		SDL_Rect r{ x, y, w, h };
		return r;
	}
};

int main(int argc, char* args[]) {

	SDL_Window* window = SDL_CreateWindow(
		"xmas",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1200, 800,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL) {
		exit(1);
	}
	Uint32 renderer_flags = SDL_RENDERER_ACCELERATED;
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, renderer_flags);
	if (renderer == NULL) {
		exit(1);
	}

	bool done = false;
	SDL_Event event;

	player santa;

	while (!done) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = true;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
		SDL_Rect sr = santa.get_pos();
		SDL_RenderFillRect(renderer, &sr);

		SDL_RenderPresent(renderer);
	}

	SDL_Quit();
}

*/

#include "platform_sdl.h"

#include <memory>

int main(int argc, char* args[]) {

	auto pf = std::make_unique<platform>();
	pf->run();

	return 0;
}