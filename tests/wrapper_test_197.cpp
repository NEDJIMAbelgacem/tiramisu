#include "Halide.h"
#include <tiramisu/utils.h>
#include "wrapper_test_197.h"
#include "test_197_defs.h"

void test_allocation(const std::string &name)
{
    Halide::Buffer<float> A(  A_size, A_size, T_size, "buf_A" );
    Halide::Buffer<float> A_ref( A_size, A_size, T_size, "buf_A_ref" );
    Halide::Buffer<float> B( B_size, B_size, T_size, "buf_B" );
    Halide::Buffer<float> B_ref( B_size, B_size, T_size, "buf_B_ref" );
    for (int i = 0; i < A_size; ++i)
    {
        for (int j = 0; j < A_size; ++j)
        {
            for (int t = 0; t < T_size; ++t)
            {
                int val = std::rand() % 10 - 5;
                A(i, j, t) = val;
                A_ref(i, j, t) = 1;
            }
        }
    }

    for (int i = 0; i < B_size; ++i)
    {
        for (int j = 0; j < B_size; ++j)
        {
            for (int t = 0; t < T_size; ++t)
            {
                int val = std::rand() % 10 - 5;
                B(i, j, t) = val;
                B_ref(i, j, t) = 2;
            }
        }
    }

    std::cout << A(0, 0, 0) << " | " << A_ref(0, 0, 0) << "\n";

{
    float sum_A = 0;
    for (int i = 0; i < A_size; ++i)
    {
        for (int j = 0; j < A_size; ++j)
        {
            for (int t = 0; t < T_size; ++t)
            {
                sum_A += A(i, j, t);
            }
        }
    }
    float sum_B = 0;
    for (int i = 0; i < A_size; ++i)
    {
        for (int j = 0; j < A_size; ++j)
        {
            for (int t = 0; t < T_size; ++t)
            {
                sum_B += B(i, j, t);
            }
        }
    }
    
    std::cout << "sum_A: " << sum_A << "\n";
    std::cout << "sum_B: " << sum_B << "\n";
}

    test_197( A.raw_buffer(), B.raw_buffer() );
    float sum_A = 0;
    for (int i = 0; i < A_size; ++i)
    {
        for (int j = 0; j < A_size; ++j)
        {
            for (int t = 0; t < T_size; ++t)
            {
                sum_A += A(i, j, t);
            }
        }
    }
    float sum_B = 0;
    for (int i = 0; i < A_size; ++i)
    {
        for (int j = 0; j < A_size; ++j)
        {
            for (int t = 0; t < T_size; ++t)
            {
                sum_B += B(i, j, t);
            }
        }
    }
    
    std::cout << "sum_A: " << sum_A << "\n";
    std::cout << "sum_B: " << sum_B << "\n";

    compare_buffers(name, B, B_ref);
    compare_buffers(name, A, A_ref);
}

int main(int, char **)
{
    test_allocation("test_197" );
    return 0;
}
