#pragma once

#include <SDL.h>

#include "sprite.h"
#include "input.h"
#include "render.h"


class game {
public:

	void rcv_input(input*);
	void update(float dt);
	void render(renderer*);

private:

	SDL_Rect sr = { 100, 100, 32, 32 };
	sprite player;

};