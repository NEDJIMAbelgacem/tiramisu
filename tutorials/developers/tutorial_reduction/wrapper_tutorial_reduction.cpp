#include "Halide.h"
#include "wrapper_tutorial_reduction.h"

#include <tiramisu/utils.h>
#include <chrono>

void test_reduction(const std::string &name)
{
    Halide::Buffer<double> A(100);
    Halide::Buffer<double> B(1);
    for (int i = 0; i < 10000; ++i)
        A(i) = rand() % 10000; 

    double sum = 0.0;
    double seq_time = 0.0;
    double reduce_time = 0.0;
    {
        auto start = std::chrono::steady_clock::now();
        for (int i = 0; i < 100; ++i) sum += A(i);
        auto end = std::chrono::steady_clock::now();
        seq_time = (end - start).count()
    }
    {
        auto start = std::chrono::steady_clock::now();
        tutorial_reduction( A.raw_buffer(), B.raw_buffer() );
        auto end = std::chrono::steady_clock::now();
        reduce_time = (end - start).count()
    }
    
    std::cout << "Sequential sum: " << sum << ", done in " << seq_time << "\n";
    std::cout << "Reduction result: " << B(0) << ", done in " << reduce_time << "\n";
}

int main(int, char **)
{
    test_reduction("test_reduction_1");

    return 0;
}
