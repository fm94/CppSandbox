# C++ Performance Testing Sandbox

A simple, modular C++ project for testing and benchmarking code snippets. Measure execution time and memory usage of various C++ operations.

## Features
- Modular structure for easy addition of new tests
- Built-in timing utilities
- Memory usage measurements
- Eigen library integration for testing fast matrix operations
- CMake-based build system

## Prerequisites
- CMake (3.10 or higher)
- C++17 compatible compiler (tested with MSVC 2022)
- Git

## Getting Started

### Clone and Build
```bash
# Clone the repository with submodules
git clone --recursive https://github.com/fm94/CppSandbox.git
cd CppSandbox

# Create build directory and build
cmake -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release

# Or load the project in VSCode and hit F5
```

### Project Structure
```
benchmark-project/
├── extern/          # External dependencies (submodules)
│   └── eigen/       # Eigen library
├── src/
│   ├── utils/       # Utility classes (Timer, etc.)
│   └── benchmarks/  # Benchmark implementations
│       ├── test.hpp # Sample test
```

## Adding New Tests

1. Create a new header file for your tests:
```cpp
// src/benchmarks/my_test.hpp
#pragma once
#include "utils/timer.hpp"

namespace benchmarks::my_category {
    inline void run_my_benchmark() {
        std::cout << "\nRunning My Benchmark:\n";
        
        Timer timer("My Operation");
        // Your code here
        timer.stop();
        
        // Optional: Add memory measurements
        // Your memory measurements here
    }
}
```

3. Add your benchmark to `main.cpp`:
```cpp
#include "benchmarks/my_category/my_test.hpp"

int main() {
    // Other benchmarks...
    benchmarks::my_category::run_my_benchmark();
    return 0;
}
```

## Example Benchmark Output
```
Running Eigen Matrix Benchmark:
Theoretical matrix size: 7.63 MB
Empty matrix size: 24 B
Allocated matrix size: 7.63 MB
Matrix properties:
  Rows: 1000
  Cols: 1000
  Size: 7.63 MB
  Storage order: Column-major
  First element: 0
  Last element: 999999
```

## Tips for Writing Benchmarks
1. Use the `Timer` class for consistent timing measurements
2. Consider adding memory measurements for operations that allocate memory
3. Run operations multiple times to get reliable measurements
4. Add descriptive output to help understand the results
5. Comment out unused benchmarks in `main.cpp` when focusing on specific tests

## Contributing
If you create a coll surprising test then please submit it
1. Create a new branch for your benchmark
2. Add your benchmark following the structure above
3. Test your benchmark
4. Submit a pull request
