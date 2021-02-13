#include "Halide.h"
#include "wrapper_tutorial_reduction.h"

#include <tiramisu/utils.h>

void test_reduction(const std::string &name)
{
    Halide::Buffer<double> A(100);
    Halide::Buffer<double> B(1);
    for (int i = 0; i < 100; ++i)
        A(i) = rand() % 100; 

    double sum = 0.0;
    for (int i = 0; i < 100; ++i) sum += A(i);
    tutorial_reduction( A.raw_buffer(), B.raw_buffer() );
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Reduction result: " << B(0) << "\n";
}

int main(int, char **)
{
    test_reduction("test_reduction_1");

    return 0;
}
