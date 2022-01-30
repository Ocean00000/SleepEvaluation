// SleepEvaluation.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "FunctionSleep.hpp"
#include "SleepName.hpp"
#include "Unit.hpp"
#include <iostream>
#include <chrono>

using namespace sleep_evaluation;
using namespace std::chrono;
using namespace std;

namespace {

	template<class SleepType>
	double get_resolution_sleep(const size_t count) {
		const auto start = steady_clock::now();
		for (int index = 0; index < count; ++index) {
			SleepType::sleep();
		}
		const auto stop = steady_clock::now();

		return static_cast<double>(duration_cast<typename SleepType::duration>(stop - start).count()) / count;
	}

    template<class SleepType>
    void output_time(const size_t count) {
        cout << get_sleep_name<SleepType>() << "," << std::fixed << get_resolution_sleep<SleepType>(count) << "," << get_unit<typename SleepType::duration>() << endl;
    }
}

int main()
{
    const size_t count = 2000;
	SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);
    cout << "Sleep,Resolution,Unit" << endl;
	output_time<function_thread_sleep>(count);
	output_time<function_sleep>(count);
	SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);

	return 0;
}

