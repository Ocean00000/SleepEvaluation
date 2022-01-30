#pragma once

#include <thread>
#include <windows.h>

namespace sleep_evaluation {
	struct function_thread_sleep {
		using duration = std::chrono::milliseconds;
		static inline void sleep() {
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	};

	struct function_sleep {
		using duration = std::chrono::milliseconds;
		static inline void sleep() {
			Sleep(1);
		}		
	};
}