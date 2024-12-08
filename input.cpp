
#include <string>

#include "input.h"

//static bool key_bindings[INPUT_BUTTON_MAX];


input::input() {
	key_bindings[button_t::INPUT_KEY_UP] = false;
	key_bindings[button_t::INPUT_KEY_DOWN] = false;
	key_bindings[button_t::INPUT_KEY_LEFT] = false;
	key_bindings[button_t::INPUT_KEY_RIGHT] = false;
	key_bindings[button_t::INPUT_KEY_A] = false;
	key_bindings[button_t::INPUT_KEY_D] = false;
	key_bindings[button_t::INPUT_KEY_G] = false;
	key_bindings[button_t::INPUT_KEY_S] = false;
	key_bindings[button_t::INPUT_KEY_W] = false;
	key_bindings[button_t::INPUT_KEY_X] = false;
	key_bindings[button_t::INPUT_KEY_Z] = false;

	button_names[button_t::INPUT_KEY_UP] = "UP";
	button_names[button_t::INPUT_KEY_DOWN] = "DOWN";
	button_names[button_t::INPUT_KEY_LEFT] = "LEFT";
	button_names[button_t::INPUT_KEY_RIGHT] = "RIGHT";
	button_names[button_t::INPUT_KEY_A] = "A";
	button_names[button_t::INPUT_KEY_D] = "D";
	button_names[button_t::INPUT_KEY_G] = "G";
	button_names[button_t::INPUT_KEY_S] = "S";
	button_names[button_t::INPUT_KEY_W] = "W";
	button_names[button_t::INPUT_KEY_X] = "X";
	button_names[button_t::INPUT_KEY_Z] = "Y";
}

void input::init() {
	clear_all_inputs();
}

void input::set_button_state(button_t button, float state) {
	key_bindings[button];
}

void input::set_button_pressed(button_t button) {

	/*
	if (button < 0 || button > INPUT_BUTTON_MAX) {
		printf("Invaid button press\n");
		return;
	}
	*/

	key_bindings[button] = true;
}

void input::set_button_released(button_t button) {

	//if (button < 0 || button > INPUT_BUTTON_MAX) {
	//	return;
	//}

	key_bindings[button] = false;
}

bool input::state_button(button_t state) {
	return key_bindings[state];
}

void input::clear_all_inputs() {
	//memset(key_bindings, 0, sizeof(key_bindings));
	for (auto kb : key_bindings) {
		kb.second = false;
	}
}

const char* input::button_name(button_t button) {
	return button_names[button];
}