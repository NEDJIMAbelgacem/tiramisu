#include "Halide.h"
#include "test_197_defs.h"

#include <tiramisu/utils.h>
#include "wrapper_test_197.h"

void test_allocation(const std::string &name)
{
    int A_buf_sizes[] = { A_size, A_size, T_size, T_size };
    int B_buf_sizes[] = { B_size, B_size, T_size, T_size };
    Halide::Buffer<float, 4> A( A_buf_sizes );
    Halide::Buffer<float, 4> A_ref( A_buf_sizes );
    Halide::Buffer<float, 4> B( B_buf_sizes );
    Halide::Buffer<float, 4> B_ref( B_buf_sizes );
    for (int i = 0; i < A_size; ++i)
    {
        for (int j = 0; j < A_size; ++j)
        {
            for (int t2 = 0; t2 < T_size; ++t2)
            {
                for (int t1 = 0; t1 < T_size; ++t1)
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
            for (int t2 = 0; t2 < T_size; ++t2)
            {
                for (int t1 = 0; t1 < T_size; ++t1)
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
