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
        std::chrono::duration<double> elapsed_seconds = end - start;
        seq_time = elapsed_seconds.count();
    }
    {
        auto start = std::chrono::steady_clock::now();
        tutorial_reduction( A.raw_buffer(), B.raw_buffer() );
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        reduce_time = elapsed_seconds.count();
    }
    
    std::cout << "Sequential sum: " << sum << ", done in " << seq_time << "s\n";
    std::cout << "Reduction result: " << B(0) << ", done in " << reduce_time << "s\n";
}

int main(int, char **)
{
    test_reduction("test_reduction_1", 1000000000);

    return 0;
}
