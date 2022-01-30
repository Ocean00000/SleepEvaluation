#pragma once

namespace sleep_evaluation {
	template<class SleepType>
	const char* const get_sleep_name();

	struct function_thread_sleep;
	template<>
	const char* const get_sleep_name<function_thread_sleep>() {
		return "std::this_thread::sleep_for";
	}

	struct function_sleep;
	template<>
	const char* const get_sleep_name<function_sleep>() {
		return "Sleep";
	}
}