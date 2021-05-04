#include <tiramisu/tiramisu.h>
#include <tiramisu/block.h>

using namespace tiramisu;

#define T 2
#define A_size 256

int main(int argc, char **argv)
{
    tiramisu::init("test_197");
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

    input A( "A", { t, A_iter1, A_iter2 }, p_float32 );

    buffer b_A_gpu( "b_A_gpu", { T, A_size, A_size }, p_float32, a_temporary );
    b_A_gpu.tag_gpu_global();

    computation init_A( "init_A", { t, A_iter1, A_iter2 }, expr( (double) 0 ) );
    init_A.store_in( &b_A_gpu, { t, A_iter1, A_iter2 } );

    computation init_A2( "init_A2", { t, A_iter1, A_iter2 }, expr( (double) 1 ) );
    init_A2.store_in( &b_A_gpu, { t, A_iter1, A_iter2 } );

    tiramisu::computation * allocate_A = b_A_gpu.allocate_at( init_A, t );

    init_A.tag_gpu_level( A_iter1, A_iter2 );
    init_A2.tag_gpu_level( A_iter1, A_iter2 );

    allocate_A->then( init_A, t ).then( init_A2, A_iter2 );

    tiramisu::codegen({ A.get_buffer() },
                      "build/generated_fct_test_197.o", true);
    return 0;
}
