#include <tiramisu/tiramisu.h>
#include <tiramisu/block.h>

using namespace tiramisu;

int main(int argc, char **argv)
{
    tiramisu::init("tutorial_reduction");

    input A("sizes", {"s_i"}, {100}, p_float64);
    input B("params", {"p_i"}, {1}, p_float64);

    computation reduce({var("dummy", 0, 1)}, cub_sum_reduce(A.get_buffer(), b.get_buffer(), 100));

    tiramisu::codegen({A.get_buffer(), B.get_buffer(),
                      "build/generated_fct_developers_tutorial_reduction.o", true);

    return 0;
}
