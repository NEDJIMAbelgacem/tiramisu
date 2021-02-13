#include "Halide.h"
#include "wrapper_tutorial_reduction.h"

#include <tiramisu/utils.h>
#include <chrono>

void test_reduction(const std::string &name, int array_size)
{
    Halide::Buffer<double> A(array_size);
    Halide::Buffer<double> B(1);
    for (int i = 0; i < array_size; ++i)
        A(i) = rand() % array_size; 

    double sum = 0.0;
    double seq_time = 0.0;
    double reduce_time = 0.0;
    {
        auto start = std::chrono::steady_clock::now();
        for (int i = 0; i < array_size; ++i) sum += A(i);
        auto end = std::chrono::steady_clock::now();
        seq_time = (end - start).count();
    }
    {
        auto start = std::chrono::steady_clock::now();
        tutorial_reduction( A.raw_buffer(), B.raw_buffer() );
        auto end = std::chrono::steady_clock::now();
        reduce_time = (end - start).count();
    }
    
    std::cout << "Sequential sum: " << sum << ", done in " << seq_time << "\n";
    std::cout << "Reduction result: " << B(0) << ", done in " << reduce_time << "\n";
}

int main(int, char **)
{
    test_reduction("test_reduction_1", 100000000);

    return 0;
}
