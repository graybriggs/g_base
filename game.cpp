

#include "game.h"

#include <iostream>

void game::rcv_input(input* in) {

	if (in->key_bindings[button_t::INPUT_KEY_W]) {
		std::cout << "w pressed\n";
		sr.y--;
	}
	if (in->key_bindings[button_t::INPUT_KEY_A]) {
		std::cout << "a pressed\n";
		sr.x--;
	}
	if (in->key_bindings[button_t::INPUT_KEY_S]) {
		std::cout << "s pressed\n";
		sr.y++;
	}
	if (in->key_bindings[button_t::INPUT_KEY_D]) {
		std::cout << "d pressed\n";
		sr.x++;
	}
}

void game::update(float dt) {

}


void game::render(renderer* rend) {
	SDL_SetRenderDrawColor(rend->get_base_renderer(), 255, 0, 0, 255); // red
	if (rend == nullptr) std::cout << "there is a problem passing the render object\n";
	if (rend->get_base_renderer() == nullptr) std::cout << "There is a problem with BASE RENDERER\n";

	SDL_RenderFillRect(rend->get_base_renderer(), &sr);
}

