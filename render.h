#pragma once



#include <SDL.h>

#include <vector>

class sprite;

class renderer {
public:
	void init(SDL_Window* windows);
	void begin_frame();
	void end_frame();
	//void render_push_cinder(cinder cinder);

	void push_rect(sprite&);
	void push_sprite(sprite&);
	void push_sprite_list(std::vector<sprite>&);

	void cleanup();

	SDL_Renderer* get_base_renderer();

private:
	SDL_Renderer* rend;
};