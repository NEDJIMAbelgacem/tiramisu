#include "Halide.h"
#include "wrapper_test_197.h"
#include "test_197_defs.h"

#include <tiramisu/utils.h>

void test_allocation(const std::string &name)
{
    Halide::Buffer<float> A(A_size, A_size, T, T);
    Halide::Buffer<float> A_ref(A_size, A_size, T, T);
    Halide::Buffer<float> B(B_size, B_size, T, T);
    Halide::Buffer<float> B_ref(B_size, B_size, T, T);
    for (int i = 0; i < A_size; ++i)
    {
        for (int j = 0; j < A_size; ++j)
        {
            for (int t2 = 0; t2 < T; ++t2)
            {
                for (int t1 = 0; t1 < T; ++t1)
                {
                    int val = std::rand() % 10 - 5;
                    A(i, j, t2, t1) = val;
                    A_ref(i, j, t2, t1) = 1;
                }
            }
        }
    }

    for (int i = 0; i < B_size; ++i)
    {
        for (int j = 0; j < B_size; ++j)
        {
            for (int t2 = 0; t2 < T; ++t2)
            {
                for (int t1 = 0; t1 < T; ++t1)
                {
                    int val = std::rand() % 10 - 5;
                    B(i, j, t2, t1) = val;
                    B_ref(i, j, t2, t1) = 2;
                }
            }
        }
    }

    test_197( A.raw_buffer(), B.raw_buffer() );
    compare_buffers(name, A, A_ref);
    compare_buffers(name, B, B_ref);
}

int main(int, char **)
{
    test_allocation("test_197" );
    return 0;
}
