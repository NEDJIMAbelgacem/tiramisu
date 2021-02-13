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
    buffer buf_A("buf_A",   { a_i }, p_float64, a_temporary);
    buffer buf_B("buf_B",   { b_i }, p_float64, a_temporary);
    A.store_in( &buf_A );
    B.store_in( &buf_B );

    computation reduce({var("dummy", 0, 1)}, cub_sum_reduce(*A.get_buffer(), *B.get_buffer(), expr( 100 ) ));

    tiramisu::codegen({A.get_buffer(), B.get_buffer()},
                      "build/generated_fct_developers_tutorial_reduction.o", true);

    return 0;
}
