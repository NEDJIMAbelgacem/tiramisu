#include "Halide.h"
#include <tiramisu/utils.h>
#include "wrapper_test_197.h"
#include "test_197_defs.h"

void test_allocation(const std::string &name)
{
    Halide::Buffer<int32_t> A(  A_size, A_size, T_size, "buf_A" );
    Halide::Buffer<int32_t> A_ref( A_size, A_size, T_size, "buf_A_ref" );
    Halide::Buffer<int32_t> B( B_size, B_size, T_size, "buf_B" );
    Halide::Buffer<int32_t> B_ref( B_size, B_size, T_size, "buf_B_ref" );
    for (int i = 0; i < A_size; ++i)
    {
        for (int j = 0; j < A_size; ++j)
        {
            for (int t = 0; t < T_size; ++t)
            {
                int val = std::rand() % 10 - 20;
                A(i, j, t) = val;
                // only the initialization part of the last iteration will persist
                // and that's what we are looking for
                if ( t == T_size - 1 )
                    A_ref(i, j, t) = 1;
                else
                    A_ref(i, j, t) = val;
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
                // only the initialization part of the last iteration will persist
                // and that's what we are looking for
                if ( t == T_size - 1 )
                    B_ref(i, j, t) = 2;
                else
                    B_ref(i, j, t) = val;
            }
        }
    }



    std::cout << A(0, 0, 0) << " | " << A_ref(0, 0, 0) << "\n";

    test_197( A.raw_buffer(), B.raw_buffer() );

    for (int i = 0; i < B_size; ++i)
    {
        for (int j = 0; j < B_size; ++j)
        {
            for (int t = 0; t < T_size; ++t)
            {
                if ( B( i, j, t ) > 0 )
                {
                    std::cout << i << " " << j << " " << k << "\n";
                }
            }
        }
    }

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
    float sum_A_ref = 0;
    for (int i = 0; i < A_size; ++i)
    {
        for (int j = 0; j < A_size; ++j)
        {
            for (int t = 0; t < T_size; ++t)
            {
                sum_A_ref += A(i, j, t);
            }
        }
    }
    
    std::cout << "sum_A: " << sum_A << "\n";
    std::cout << "sum_A_ref: " << sum_A_ref << "\n";

    compare_buffers(name + "_B_check", B, B_ref);
    compare_buffers(name + "_A_check", A, A_ref);
}

int main(int, char **)
{
    test_allocation("test_197" );
    return 0;
}
