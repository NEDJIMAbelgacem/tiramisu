#include <tiramisu/tiramisu.h>
#include <tiramisu/block.h>

using namespace tiramisu;

int main(int argc, char **argv)
{
    tiramisu::init("tutorial_reduction");

    constant N("M", 1000000000);
    // constant M("M", 1);

    input A("A", { "a_i" }, { N }, p_float64);
    input B("B", { "b_i" }, { 1 }, p_float64);

    buffer A_gpu( "A_gpu", { N }, p_float64, a_temporary );
    buffer B_gpu( "B_gpu", { 1 }, p_float64, a_temporary );
    A_gpu.tag_gpu_global();
    B_gpu.tag_gpu_global();

    computation copy_A_to_device({}, memcpy(*A.get_buffer(), A_gpu));
    computation copy_B_to_device({}, memcpy(*B.get_buffer(), B_gpu));

    computation copy_A_to_host({}, memcpy(A_gpu, *A.get_buffer()));
    computation copy_B_to_host({}, memcpy(B_gpu, *B.get_buffer()));

    computation reduce({ var("dummy", 0, 1) }, cub_sum_reduce( A_gpu, B_gpu, N ));

    copy_A_to_device
        .then( copy_B_to_device, computation::root )
        .then( reduce, computation::root )
        .then( copy_B_to_host, computation::root )
        .then( copy_A_to_host, computation::root );


    tiramisu::codegen({A.get_buffer(), B.get_buffer()},
                      "build/generated_fct_developers_tutorial_reduction.o", true);

    return 0;
}
