#include <tiramisu/tiramisu.h>

#include <string.h>

#include "wrapper.h"

using namespace tiramisu;

/*
 * The goal is to generate code that implements the reference.
 * baryon_ref.cpp
 */
void generate_function(std::string name, int size)
{
    tiramisu::init(name);

    // constant N("N", size);
    // constant T("T", BT);
    // constant a1("a1", 0);
    // constant a2("a2", 0);
    // constant a3("a3", 0);
    // constant xp0("xp0", 0);
    // constant K("K", BK);
    // constant b0("b0", 0);
    // constant b1("b1", 0);
    // constant b2("b2", 0);
    const int N = size;
    const int T = BT;
    const int a1 = 0;
    const int a2 = 0;
    const int a3 = 0;
    const int xp0 = 0;
    const int K = BK;
    const int b0 = 0;
    const int b1 = 0;
    const int b2 = 0; 

    input fc1("fc1", {"k"}, {K}, p_int32);
    input fc2("fc2", {"k"}, {K}, p_int32);
    input fc3("fc3", {"k"}, {K}, p_int32);
    input S("S", {"xp0", "a1", "t", "i1", "i2", "i3", "d1"}, {1, 1, T, N, N, N, BK}, p_float32);
    input wp("wp", {"k", "b0", "b1", "b2"}, {K, 1, 1, 1}, p_float32);

    var i1("i1", 0, N), i2("i2", 0, N), i3("i3", 0, N), k("k", 0, K), t("t", 0, T), k0("k", 0, 1);

    computation Res2("Res2", {t}, expr((float) 0));
    computation Res1("Res1", {t, i1, i2, i3}, expr((float) 0));

    computation Res0("Res0", {t, i1, i2, i3, k}, p_float32);
    Res0.set_expression(S(xp0, a1, t, i1, i2, i3, fc1(k)) * S(xp0, a2, t, i1, i2, i3, fc2(k)) * S(xp0, a3, t, i1, i2, i3, fc3(k))
		      + S(xp0, a1, t, i1, i2, i3, fc2(k)) * S(xp0, a2, t, i1, i2, i3, fc3(k)) * S(xp0, a3, t, i1, i2, i3, fc1(k))
		      + S(xp0, a1, t, i1, i2, i3, fc3(k)) * S(xp0, a2, t, i1, i2, i3, fc1(k)) * S(xp0, a3, t, i1, i2, i3, fc2(k))
		      - S(xp0, a1, t, i1, i2, i3, fc2(k)) * S(xp0, a2, t, i1, i2, i3, fc1(k)) * S(xp0, a3, t, i1, i2, i3, fc3(k))
		      - S(xp0, a1, t, i1, i2, i3, fc3(k)) * S(xp0, a2, t, i1, i2, i3, fc2(k)) * S(xp0, a3, t, i1, i2, i3, fc1(k))
		      - S(xp0, a1, t, i1, i2, i3, fc1(k)) * S(xp0, a2, t, i1, i2, i3, fc3(k)) * S(xp0, a3, t, i1, i2, i3, fc2(k)));

    computation Res1_update_0("Res1_update_0", {t, i1, i2, i3, k}, p_float32);
    Res1_update_0.set_expression(Res1_update_0(t, i1, i2, i3, k-1) + wp(k, b2, b1, b0) * Res0(t, i1, i2, i3, k));

    computation Res2_update_0("Res2_update_0", {t, i1, i2, i3}, p_float32);
    Res2_update_0.set_expression(Res2_update_0(t, i1, i2, i3) + cast(p_float32, expr(o_expo, cast(p_float32, i3 + i2) + cast(p_float32, i1), p_float32)) * Res1(t, i1, i2, i3)); //exp(i(i3*px+i2*py+i1*pz))

    // -------------------------------------------------------
    // Layer III
    // -------------------------------------------------------
    buffer buf_fc1("buf_fc1", {BARYON_N}, p_int32, a_temporary);
    buffer buf_fc2("buf_fc2", {BARYON_N}, p_int32, a_temporary);
    buffer buf_fc3("buf_fc3", {BARYON_N}, p_int32, a_temporary);

    buffer buf_res0("buf_res0", {BZ}, p_float32, a_temporary);
    // buf_res0.set_auto_allocate(false);
    // computation *alloc_res0 = buf_res0.allocate_at(Res2, t);
    buffer buf_res1("buf_res1", {N}, p_float32, a_temporary);
    // buf_res1.set_auto_allocate(false);
    // computation *alloc_res1 = buf_res1.allocate_at(Res2, t);
    buffer buf_res2("buf_res2", {T}, p_float32, a_temporary);
    buffer buf_d1("buf_d1", {1}, p_int32, a_temporary);
    // buf_d1.set_auto_allocate(false);
    // computation *alloc_d1 = buf_d1.allocate_at(Res2, t);
    buffer buf_d2("buf_d2", {1}, p_int32, a_temporary);
    // buf_d2.set_auto_allocate(false);
    // computation *alloc_d2 = buf_d2.allocate_at(Res2, t);
    buffer buf_d3("buf_d3", {1}, p_int32, a_temporary);
    // buf_d3.set_auto_allocate(false);
    // computation *alloc_d3 = buf_d3.allocate_at(Res2, t);

    buffer buf_S("buf_S", {BARYON_P, BARYON_P, BT, BX, BY, BZ, BK}, p_float32, a_temporary);
    buffer buf_wp("buf_wp", {BK, BARYON_P, BARYON_P, BARYON_P}, p_float32, a_temporary);

    fc1.store_in(&buf_fc1);
    fc2.store_in(&buf_fc2);
    fc3.store_in(&buf_fc3);
    Res0.store_in(&buf_res0, {i3});
    Res1.store_in(&buf_res1, {i3});
    Res1_update_0.store_in(&buf_res1, {i3});
    Res2.store_in(&buf_res2, {t});
    Res2_update_0.store_in(&buf_res2, {t});
    S.store_in(&buf_S);
    wp.store_in(&buf_wp);

    buf_res2.tag_gpu_global();
    buf_res1.tag_gpu_global();
    buf_res0.tag_gpu_global();
    buf_S.tag_gpu_global();
    buf_wp.tag_gpu_global();
    buf_fc1.tag_gpu_global();
    buf_fc2.tag_gpu_global();
    buf_fc3.tag_gpu_global();
    buf_d3.tag_gpu_global();
    buf_d2.tag_gpu_global();
    buf_d1.tag_gpu_global();

    buffer buf_res2_cpu("buf_res2_cpu", {T}, p_float32, a_output);
    buffer buf_S_cpu("buf_S_cpu", {BARYON_P, BARYON_P, BT, BX, BY, BZ, BK}, p_float32, a_input);
    buffer buf_wp_cpu("buf_wp_cpu", {BK, BARYON_P, BARYON_P, BARYON_P}, p_float32, a_input);
    buffer buf_fc1_cpu("buf_fc1_cpu", {K}, p_int32, a_input);
    buffer buf_fc2_cpu("buf_fc2_cpu", {K}, p_int32, a_input);
    buffer buf_fc3_cpu("buf_fc3_cpu", {K}, p_int32, a_input);

    computation copy_buf_S_cpu_host_to_device({}, memcpy(buf_S_cpu, buf_S));
    computation copy_buf_wp_cpu_host_to_device({}, memcpy(buf_wp_cpu, buf_wp));
    computation copy_buf_fc1_cpu_host_to_device({}, memcpy(buf_fc1_cpu, buf_fc1));
    computation copy_buf_fc2_cpu_host_to_device({}, memcpy(buf_fc2_cpu, buf_fc2));
    computation copy_buf_fc3_cpu_host_to_device({}, memcpy(buf_fc3_cpu, buf_fc3));

    computation copy_buf_res2_device_to_host({}, memcpy(buf_res2, buf_res2_cpu));

    // -------------------------------------------------------
    // Layer II
    // -------------------------------------------------------

    copy_buf_S_cpu_host_to_device
        .then(copy_buf_wp_cpu_host_to_device, computation::root)
        .then(copy_buf_fc1_cpu_host_to_device, computation::root)
        .then(copy_buf_fc2_cpu_host_to_device, computation::root)
        .then(copy_buf_fc3_cpu_host_to_device, computation::root)
        .then(Res2, computation::root);

    Res2
    // .then(*alloc_res1, t)
	// .then(*alloc_res0, t)
	// .then(*alloc_d1, t)
	// .then(*alloc_d2, t)
	// .then(*alloc_d3, t)
	.then(Res1, i3)
	.then(Res0, i3)
	.then(Res1_update_0, k)
	.then(Res2_update_0, i3);

    Res2.then(copy_buf_res2_device_to_host, computation::root);

    Res1.tag_gpu_level(i2, i3);

    // Res0.tag_vector_level(i3, BARYON_N);
    // Res2.tag_parallel_level(t);

    // -------------------------------------------------------
    // Code Generation
    // -------------------------------------------------------

    tiramisu::codegen({&buf_res2_cpu, &buf_S_cpu, &buf_wp_cpu, &buf_fc1_cpu, &buf_fc2_cpu, &buf_fc3_cpu},
		      "generated_baryon.o", true);
}

int main(int argc, char **argv)
{
    generate_function("tiramisu_generated_code", BARYON_N);

    return 0;
}
