#pragma once
#include <Eigen/Dense>
#include "utils/timer.hpp"
#include <iostream>
#include <iomanip>

namespace benchmarks::matrix {
    // Helper function to format bytes to KB/MB
    inline std::string format_memory(size_t bytes) {
        if (bytes < 1024) return std::to_string(bytes) + " B";
        if (bytes < 1024 * 1024) return std::to_string(bytes / 1024) + " KB";
        return std::to_string(bytes / (1024 * 1024)) + " MB";
    }

    inline void run_eigen_benchmark() {
        std::cout << "\nRunning Eigen Matrix Benchmark:\n";
        
        constexpr int rows = 100;
        constexpr int cols = 100000;

        // Calculate theoretical size
        size_t theoretical_size = rows * cols * sizeof(double);
        std::cout << "Theoretical matrix size: " << format_memory(theoretical_size) << "\n";
        
        // Test column-major matrix initialization
        {
            // Measure empty matrix size
            Eigen::MatrixXd matrix;
            std::cout << "Empty matrix size: " << format_memory(sizeof(matrix)) << "\n";
            
            // Measure allocated but uninitialized matrix size
            matrix.resize(rows, cols);
            std::cout << "Allocated matrix size: " << format_memory(matrix.size() * sizeof(double)) << "\n";
            
            Timer timer("Eigen ColMajor Matrix Init");
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    matrix(i, j) = static_cast<double>(i * cols + j);
                }
            }
            timer.stop();

            // Print matrix properties
            std::cout << "Matrix properties:\n"
                     << "  Rows: " << matrix.rows() << "\n"
                     << "  Cols: " << matrix.cols() << "\n"
                     << "  Size: " << format_memory(matrix.size() * sizeof(double)) << "\n"
                     << "  Storage order: " << (matrix.IsRowMajor ? "Row-major" : "Column-major") << "\n"
                     << "  First element: " << matrix(0,0) << "\n"
                     << "  Last element: " << matrix(rows-1,cols-1) << "\n\n";
        }

        // Test column-major matrix initialization (column-wise loop)
        {
            Timer timer("Eigen ColMajor Matrix Init (column-wise)");
            Eigen::MatrixXd matrix(rows, cols);
            
            for (int j = 0; j < cols; ++j) {
                for (int i = 0; i < rows; ++i) {
                    matrix(i, j) = static_cast<double>(i * cols + j);
                }
            }
            timer.stop();

            // Print matrix properties
            std::cout << "Matrix properties (column-wise init):\n"
                     << "  Size: " << format_memory(matrix.size() * sizeof(double)) << "\n"
                     << "  First element: " << matrix(0,0) << "\n"
                     << "  Last element: " << matrix(rows-1,cols-1) << "\n";
        }
    }
}