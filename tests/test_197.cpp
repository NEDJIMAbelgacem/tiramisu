#include <tiramisu/tiramisu.h>
#include <tiramisu/block.h>

using namespace tiramisu;

#define T 2
#define A_size 256
#define B_Size 1

int main(int argc, char **argv)
{
    // {
    //     for (int t = 0; t < N; ++t)
    //     {
    //         // allocate A
    //          initialize A
    //         // deallocate A
    //     }
    // }
    var t( "t", 0, T );
    var A_iter1( "A_iter1", 0, A_size );
    var A_iter2( "A_iter2", 0, A_size );

    tiramisu::init("test_197");
    input A( "A", { t, A_iter1, A_iter2 }, p_float32 );

    buffer b_A_gpu( "b_A_gpu", { T, A_size, A_size }, p_float32, a_temporary );
    b_A_gpu.tag_gpu_global();

    computation init_A( "init_A", { t, A_iter1, A_iter2 }, expr( (double) 0 ) );
    init_A.store_in( &b_A_gpu, { t, A_iter1, A_iter2 } );

    b_A_gpu.allocate_at( init_A, t );

    tiramisu::codegen({ A.get_buffer() },
                      "build/generated_fct_test_197.o", true);
    return 0;
}
