#include "benchmarks/count_to_million.hpp"
#include "benchmarks/eigen_ops.hpp"

int main() {
    // Run basic counting benchmark
    // benchmarks::basic::run_counting_benchmark();

    // Run Eigen matrix benchmark
    benchmarks::matrix::run_eigen_benchmark();

    return 0;
}