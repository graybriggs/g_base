


#define _CRT_SECURE_NO_WARNINGS // for strcpy

#include <SDL.h>

#include <cstdio>
#include <iostream>
#include <string>
#include <ctime>

#include "platform_sdl.h"
#include "system.h"


void platform::init() {
	std::cout << "Initializing system...\n";
	srand((unsigned int)time(nullptr));
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);


	//input_init();
	p_in = std::make_unique<input>();
	if (p_in == nullptr) {
		std::cout << "Input init failed\n";
		exit(1);
	}

	p_renderer = std::make_unique<renderer>();
	if (p_renderer == nullptr) {
		std::cout << "Renderer init failed\n";
		exit(1);
	}
	p_renderer->init(window);

	p_game = std::make_unique<game>();
	if (p_game == nullptr) {
		std::cout << "Core game init failed\n";
		exit(1);
	}

}

void platform::window_setup(uint32_t w, uint32_t h, std::string win_name) {
	std::cout << "Setting up window...\n";
	window_name = win_name;
	window_width = w;
	window_height = h;
	window = SDL_CreateWindow(
		window_name.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		window_width, window_height,
		SDL_WINDOW_SHOWN
	);
	if (window == nullptr) {
		std::cout << "Window creation failed\n";
		exit(1);
	}
}

void platform::pump_events() {

	//SDL_Event event = platform.event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			app_done = true;
			return;
		}
		else if (event.type == SDL_KEYDOWN) {
			// special condition
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				app_done = true;
				return;
			}

			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				p_in->set_button_pressed(button_t::INPUT_KEY_LEFT);
				break;
			case SDLK_RIGHT:
				p_in->set_button_pressed(button_t::INPUT_KEY_RIGHT);
				break;
			case SDLK_UP:
				p_in->set_button_pressed(button_t::INPUT_KEY_UP);
				break;
			case SDLK_DOWN:
				p_in->set_button_pressed(button_t::INPUT_KEY_DOWN);
				break;
			case SDLK_w:
				p_in->set_button_pressed(button_t::INPUT_KEY_W);
				break;
			case SDLK_a:
				p_in->set_button_pressed(button_t::INPUT_KEY_A);
				break;
			case SDLK_s:
				p_in->set_button_pressed(button_t::INPUT_KEY_S);
				break;
			case SDLK_d:
				p_in->set_button_pressed(button_t::INPUT_KEY_D);
				break;
			}
		}
		else if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				p_in->set_button_released(button_t::INPUT_KEY_LEFT);
				break;
			case SDLK_RIGHT:
				p_in->set_button_released(button_t::INPUT_KEY_RIGHT);
				break;
			case SDLK_UP:
				p_in->set_button_released(button_t::INPUT_KEY_UP);
				break;
			case SDLK_DOWN:
				p_in->set_button_released(button_t::INPUT_KEY_DOWN);
				break;
			case SDLK_w:
				p_in->set_button_released(button_t::INPUT_KEY_W);
				break;
			case SDLK_a:
				p_in->set_button_released(button_t::INPUT_KEY_A);
				break;
			case SDLK_s:
				p_in->set_button_released(button_t::INPUT_KEY_S);
				break;
			case SDLK_d:
				p_in->set_button_released(button_t::INPUT_KEY_D);
				break;
			}
		}
	}
}

void platform::run() {

	window_setup(1200, 800, "xmas game");
	init();


	accumulator = 0.0f;
	frame_start = static_cast<float>(get_ticks());
	FRAMES_PER_SECOND = 60;
	delta = 1.0f / FRAMES_PER_SECOND;

	app_done = false;

	while (!app_done) {
		pump_events();
		// platform_prepare_frame(); // nothing
		//sys.update();
		p_game->rcv_input(get_input());
		// this.update()
		update();
		 
		// platform_end_frame(); // nothing
	}

	//sys.cleanup();
	cleanup();
}


void platform::update() {
	float currentTime = static_cast<float>(get_ticks());
	accumulator += currentTime - frame_start;
	frame_start = currentTime;
	updates_per_second = 0;


	if (accumulator > 0.2f)
		accumulator = 0.2f;
	
	while (accumulator > delta) {

		//cinder_update(dt);
		p_game->update(delta);

		accumulator -= delta;
		++updates_per_second;
	}

	render();


	//input.clear();
}

void platform::render() {

	p_renderer->begin_frame();

	p_game->render(get_renderer());

	p_renderer->end_frame();
}

void platform::cleanup() {
	p_renderer->cleanup();
	SDL_DestroyWindow(window);
	SDL_Quit();
}

Uint32 platform::get_ticks() {
	return SDL_GetTicks();
}

SDL_Window* platform::get_window() {
	return window;
}

input* platform::get_input() {
	return p_in.get();
}

renderer* platform::get_renderer() {
	return p_renderer.get();
}