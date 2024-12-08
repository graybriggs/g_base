#pragma once

#include <SDL.h>

#include <ctime>
#include <string>
#include <memory>

#include "game.h"
#include "input.h"
#include "render.h"

class platform {
public:
	void window_setup(uint32_t w, uint32_t h, std::string win_name);
	void init();
	// void platform_video_init();
	void pump_events();
	// void platform_prepare_frame();
	// void platform_end_frame();
	void run();

	void update();
	void render();

	void cleanup();

	Uint32 get_ticks();
	SDL_Window* get_window();
	input* get_input();
	renderer* get_renderer();

private:
	SDL_Window* window;
	std::string window_name;
	uint32_t window_width;
	uint32_t window_height;
	SDL_Event event;
	bool app_done;


	// timing specific
	float accumulator;
	float frame_start;

	//static const float frames_per_second = 60.0f;
	int FRAMES_PER_SECOND;
	float delta; // fixed timestep of 1/60th of a second
	uint32_t updates_per_second;


	// input, render

	std::unique_ptr<input> p_in;
	std::unique_ptr<renderer> p_renderer;

	std::unique_ptr<game> p_game;
};