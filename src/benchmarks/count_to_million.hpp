#pragma once
#include "utils/timer.hpp"

namespace benchmarks::basic {
    inline void run_counting_benchmark() {
        std::cout << "\nRunning Counting Benchmark:\n";
        for (int i = 0; i < 5; ++i) {
            Timer timer("Count to million");
            volatile int sum = 0;
            for (int j = 0; j < 1000000; ++j) {
                sum += 1;
            }
            timer.stop();
        }
    }
}
