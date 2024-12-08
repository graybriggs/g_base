
#include "sprite.h"

SDL_Rect sprite::get_box() const {
	return box;
}

void sprite::set_box(int x, int y) {
	box.x = x;
	box.y = y;
} 