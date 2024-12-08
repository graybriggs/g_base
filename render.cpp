

#include <iostream>

#include "render.h"

void renderer::init(SDL_Window* window) {
	Uint32 renderer_flags = SDL_RENDERER_ACCELERATED;
	rend = SDL_CreateRenderer(window, -1, renderer_flags);
	if (rend == nullptr) {
		std::cout << "Failed to create renderer...\n";
		exit(1);
	}
}

void renderer::begin_frame() {

	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255); // Black
	SDL_RenderClear(rend);
}

void renderer::end_frame() {

	SDL_RenderPresent(rend);
}

void renderer::push_rect(sprite& sprite) {

	SDL_SetRenderDrawColor(rend, 255, 0, 0, 255); // red
	//SDL_Rect sr = sprite.get_box();
	//SDL_RenderFillRect(renderer, &sr);
}

void renderer::push_sprite(sprite& sprite) {

}

void renderer::push_sprite_list(std::vector<sprite>& sprite_list) {

}

void renderer::cleanup() {
	SDL_DestroyRenderer(rend);
}

SDL_Renderer* renderer::get_base_renderer() {
	return rend;
}