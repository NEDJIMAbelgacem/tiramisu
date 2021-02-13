#include <tiramisu/tiramisu.h>
#include <tiramisu/block.h>

using namespace tiramisu;

int main(int argc, char **argv)
{
    tiramisu::init("tutorial_reduction");
    var a_i("a_i", 0, 100);
    var b_i("b_i", 0, 1);
    input A("A", { a_i }, p_float64);
    input B("B", { b_i }, p_float64);

    computation reduce({var("dummy", 0, 1)}, cub_sum_reduce(*A.get_buffer(), *B.get_buffer() ));

    tiramisu::codegen({A.get_buffer(), B.get_buffer()},
                      "build/generated_fct_developers_tutorial_reduction.o");

    return 0;
}
