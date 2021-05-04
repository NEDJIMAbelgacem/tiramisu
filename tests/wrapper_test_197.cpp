#include "Halide.h"
#include "wrapper_test_197.h"

#include <tiramisu/utils.h>

#define T 2
#define A_size 256

void test_allocation(const std::string &name)
{
    Halide::Buffer<float> A(A_size, A_size, T);
    Halide::Buffer<float> A_ref(A_size, A_size, T);
    for (int i = 0; i < A_size; ++i)
    {
        for (int j = 0; j < A_size; ++j)
        {
            for (int k = 0; k < T; ++k)
            {
                A(i, j, k) = std::rand() % 10 - 5;
                A_ref(i, j, k) = std::rand() % 10 - 5;
            }
        }
    }


    test_197( A.raw_buffer() );
    compare_buffers(name, A, A_ref);
}

int main(int, char **)
{
    test_allocation("test_197_1" );
    test_allocation("test_197_2" );

    return 0;
}
