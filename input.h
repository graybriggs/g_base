#pragma once

#include <unordered_map>
#include <vector>

enum class button_t {
	INPUT_KEY_LEFT,
	INPUT_KEY_RIGHT,
	INPUT_KEY_UP,
	INPUT_KEY_DOWN,
	INPUT_KEY_A,
	INPUT_KEY_D,
	INPUT_KEY_G,
	INPUT_KEY_S,
	INPUT_KEY_W,
	INPUT_KEY_X,
	INPUT_KEY_Z,

	INPUT_BUTTON_MAX
};

class input {
public:
	input();
	void init();
	void set_button_state(button_t button, float state);
	void set_button_pressed(button_t button);
	void set_button_released(button_t button);
	bool state_button(button_t button);
	void clear_all_inputs();
	const char* button_name(button_t button);

	std::unordered_map<button_t, bool> key_bindings;
	std::unordered_map<button_t, const char*> button_names;
	//bool key_bindings[button_t::INPUT_BUTTON_MAX];
};