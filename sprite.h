#pragma once



#include <SDL.h>

class sprite {
public:	
	SDL_Rect get_box() const;
	void set_box(int x, int y);

private:
	SDL_Texture* texture;
	SDL_Rect box{ 0, 0, 32, 32 };

};