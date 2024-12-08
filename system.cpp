
//#include <cstdio>
//#include <memory>
//
//#include "system.h"
//
//#include "platform_sdl.h"
//#include "render.h"
//
////#include "cinders.h"
//
//app_system::app_system():
//	rend(std::make_unique<renderer>()) {
//	int FRAMES_PER_SECOND = 60;
//	dt = 1.0f / FRAMES_PER_SECOND; // fixed timestep of 1/60th of a secon
//	accumulator = 0.0f;
//}
//
//void app_system::init(platform_info& platform) {
//
//	rend->init(platform.window);
//	
//
//	accumulator = 0.0f;
//	frame_start = static_cast<float>(platform_get_ticks());
//}
//
//void app_system::update() {
//
//	float currentTime = static_cast<float>(platform_get_ticks());
//	accumulator += currentTime - frame_start;
//	frame_start = currentTime;
//	updates_per_second = 0;
//	//
//
//	
//	if (accumulator > 0.2f)
//		accumulator = 0.2f;
//	
//	while (accumulator > dt) {
//
//		//cinder_update(dt);
//
//		accumulator -= dt;
//		++updates_per_second;
//	}
//	
//
//
//	rend->begin_frame();
//
//
//
//	rend->end_frame();
//
//	//input.clear();
//
//}
//
//
//void app_system::cleanup() {
//	rend->cleanup();
//}
//
//input* app_system::get_input() {
//	input.get();
//}