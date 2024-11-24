#pragma once
#include <chrono>
#include <iostream>
#include <string_view>

class Timer {
    using clock_type = std::chrono::high_resolution_clock;
    using second_type = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_type> m_beg;
    std::string_view m_name;

public:
    Timer(std::string_view name) : m_beg(clock_type::now()), m_name(name) {}
    
    void stop() {
        auto end = clock_type::now();
        auto duration = std::chrono::duration_cast<second_type>(end - m_beg);
        std::cout << m_name << ": " << duration.count() << " seconds\n";
    }
};