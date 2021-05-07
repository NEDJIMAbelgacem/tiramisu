#include <tiramisu/tiramisu.h>
#include <tiramisu/block.h>
#include "test_197_defs.h"

using namespace tiramisu;

int main(int argc, char **argv)
{
    tiramisu::init("test_197");

    // generated code:
    // {
    //     for (int t1 = 0; t1 < T; ++t1)
    //     {
    //         for (int t2 = 0; t2 < T; ++t2)
    //         {
    //             allocate A_gpu
    //             initialize A_gpu to 1
    //             copy from A_gpu (device) to A (host)
    //             deallocate A_gpu
    //         }
    //     }
    //     for (int t1 = 0; t1 < T; ++t1)
    //     {
    //         for (int t2 = 0; t2 < T; ++t2)
    //         {
    //             allocate B_gpu
    //             initialize B_gpu to 2
    //             copy from B_gpu (device) to B (host)
    //             deallocate B_gpu
    //         }
    //     }
    // }
    var t1( "t1", 0, T );
    var t2( "t2", 0, T );
    var A_iter1( "A_iter1", 0, A_size );
    var A_iter2( "A_iter2", 0, A_size );

    var B_iter1( "B_iter1", 0, B_size );
    var B_iter2( "B_iter2", 0, B_size );

    input A( "A", { t1, t2, A_iter1, A_iter2 }, p_float32 );
    input B( "B", { t1, t2, B_iter1, B_iter2 }, p_float32 );

    buffer b_A_gpu( "b_A_gpu", { T, T, A_size, A_size }, p_float32, a_temporary );
    b_A_gpu.tag_gpu_global();

    buffer b_B_gpu( "b_B_gpu", { T, T, B_size, B_size }, p_float32, a_temporary );
    b_B_gpu.tag_gpu_global();

    computation init_A( "init_A", { t1, t2, A_iter1, A_iter2 }, expr( (double) 1 ) );
    init_A.store_in( &b_A_gpu, { t1, t2, A_iter1, A_iter2 } );
    init_A.tag_gpu_level( A_iter1, A_iter2 );

    computation init_B( "init_B", { t1, t2, B_iter1, B_iter2 }, expr( (double) 2 ) );
    init_B.store_in( &b_B_gpu, { t1, t2, B_iter1, B_iter2 } );
    init_B.tag_gpu_level( B_iter1, B_iter2 );

    computation copy_A_device_to_host( {t1, t2}, memcpy( b_A_gpu, *A.get_buffer() ) );

    computation copy_B_device_to_host( {t1, t2}, memcpy( b_B_gpu, *B.get_buffer() ) );

    tiramisu::computation *allocate_A = b_A_gpu.allocate_at( init_A, t2 );
    tiramisu::computation *deallocate_A = b_A_gpu.deallocate_at( copy_A_device_to_host, t2 );

    tiramisu::computation *allocate_B = b_B_gpu.allocate_at( init_B, t2 );
    tiramisu::computation *deallocate_B = b_B_gpu.deallocate_at( copy_B_device_to_host, t2 );

    allocate_A->then( init_A, t2 ).then( copy_A_device_to_host, t2 )
                                  .then( *deallocate_A, t2 )
                                  .then( *allocate_B, computation::root )
                                  .then( init_B, t2 )
                                  .then( copy_B_device_to_host, t2 )
                                  .then( *deallocate_B, t2 );

    tiramisu::codegen({ A.get_buffer(), B.get_buffer() }, "build/generated_fct_test_197.o", true);
    return 0;
}
