cmake_minimum_required(VERSION 3.10)
project(benchmark_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4 /O2)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -O3)
endif()

# Add Eigen using add_subdirectory
add_subdirectory(extern/eigen)

# Create executable
add_executable(benchmark_app src/main.cpp)

# Add include directories
target_include_directories(benchmark_app PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link with Eigen
target_link_libraries(benchmark_app PRIVATE Eigen3::Eigen)