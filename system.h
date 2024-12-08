#pragma once

//#include <memory>
//
//
//#include "render.h"
//
//struct platform_info;
//
//class app_system {
//public:
//
//	app_system();
//
//	void init();
//	void update();
//	void cleanup();
//
//	input* get_input();
//
//private:
//	float accumulator;
//	float frame_start;
//
//	//static const float frames_per_second = 60.0f;
//	//int FRAMES_PER_SECOND;
//	float dt; // fixed timestep of 1/60th of a second
//	uint32_t updates_per_second;
//
//	std::unique_ptr<renderer> rend;
//	std::unique_ptr<input> input;
//
//	renderer renderer;
//
//};