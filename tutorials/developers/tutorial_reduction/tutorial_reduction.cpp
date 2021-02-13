#include <tiramisu/tiramisu.h>
#include <tiramisu/block.h>

using namespace tiramisu;

int main(int argc, char **argv)
{
    tiramisu::init("tutorial_reduction");
    input A("A", {"a_i"}, {100}, p_float64);
    input B("B", {"b_i"}, {1}, p_float64);

    computation reduce({}, cub_sum_reduce(*A.get_buffer(), *B.get_buffer(), 100));

    tiramisu::codegen({A.get_buffer(), B.get_buffer()},
                      "build/generated_fct_developers_tutorial_reduction.o", true);

    return 0;
}
