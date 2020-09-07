#include <tiramisu/tiramisu.h>

#include <string.h>

#include "old_baryon_wrapper.h"

using namespace tiramisu;

/*
 * The goal is to generate code that implements the reference.
 * baryon_ref.cpp
 */
void generate_function(std::string name, int size)
{
    tiramisu::init(name);

    constant N("N", size);
    constant T("T", BT);
    constant a1("a1", 0);
    constant a2("a2", 0);
    constant a3("a3", 0);
    constant xp0("xp0", 0);
    constant K("K", BK);
    constant b0("b0", 0);
    constant b1("b1", 0);
    constant b2("b2", 0);

    input fc1("fc1", {"k"}, {K}, p_int32);
    input fc2("fc2", {"k"}, {K}, p_int32);
    input fc3("fc3", {"k"}, {K}, p_int32);
    input S("S", {"xp0", "a1", "t", "i1", "i2", "i3", "d1"}, {1, 1, T, N, N, N, 1}, p_float32);
    input wp("wp", {"k", "b0", "b1", "b2"}, {K, 1, 1, 1}, p_float32);

    var i1("i1", 0, N), i2("i2", 0, N), i3("i3", 0, N), k("k", 1, K), t("t", 0, T), k0("k", 0, 1);

    computation Res2("Res2", {t}, expr((float) 0));
    computation Res1("Res1", {t, i1, i2, i3}, expr((float) 0));

    computation Res0("Res0", {t, i1, i2, i3, k}, p_float32);
    // Res0.set_expression(S(xp0, a1, t, i1, i2, i3, fc1(k)) * S(xp0, a2, t, i1, i2, i3, fc2(k)) * S(xp0, a3, t, i1, i2, i3, fc3(k))
	// 	      + S(xp0, a1, t, i1, i2, i3, fc2(k)) * S(xp0, a2, t, i1, i2, i3, fc3(k)) * S(xp0, a3, t, i1, i2, i3, fc1(k))
	// 	      + S(xp0, a1, t, i1, i2, i3, fc3(k)) * S(xp0, a2, t, i1, i2, i3, fc1(k)) * S(xp0, a3, t, i1, i2, i3, fc2(k))
	// 	      - S(xp0, a1, t, i1, i2, i3, fc2(k)) * S(xp0, a2, t, i1, i2, i3, fc1(k)) * S(xp0, a3, t, i1, i2, i3, fc3(k))
	// 	      - S(xp0, a1, t, i1, i2, i3, fc3(k)) * S(xp0, a2, t, i1, i2, i3, fc2(k)) * S(xp0, a3, t, i1, i2, i3, fc1(k))
	// 	      - S(xp0, a1, t, i1, i2, i3, fc1(k)) * S(xp0, a2, t, i1, i2, i3, fc3(k)) * S(xp0, a3, t, i1, i2, i3, fc2(k)));

        Res0.set_expression(S(xp0, a1, t, i1, i2, i3, 0) * S(xp0, a2, t, i1, i2, i3, fc2(k)) * S(xp0, a3, t, i1, i2, i3, fc3(k))
		      + S(xp0, a1, t, i1, i2, i3, fc2(k)) * S(xp0, a2, t, i1, i2, i3, fc3(k)) * S(xp0, a3, t, i1, i2, i3, 0)
		      + S(xp0, a1, t, i1, i2, i3, fc3(k)) * S(xp0, a2, t, i1, i2, i3, 0) * S(xp0, a3, t, i1, i2, i3, fc2(k))
		      - S(xp0, a1, t, i1, i2, i3, fc2(k)) * S(xp0, a2, t, i1, i2, i3, 0) * S(xp0, a3, t, i1, i2, i3, fc3(k))
		      - S(xp0, a1, t, i1, i2, i3, fc3(k)) * S(xp0, a2, t, i1, i2, i3, fc2(k)) * S(xp0, a3, t, i1, i2, i3, 0)
		      - S(xp0, a1, t, i1, i2, i3, 0) * S(xp0, a2, t, i1, i2, i3, fc3(k)) * S(xp0, a3, t, i1, i2, i3, fc2(k)));

    computation Res1_update_0("Res1_update_0", {t, i1, i2, i3, k}, p_float32);
    Res1_update_0.set_expression(Res1_update_0(t, i1, i2, i3, k-1) + wp(k, b2, b1, b0) * Res0(t, i1, i2, i3, k));

    computation Res2_update_0("Res2_update_0", {t, i1, i2, i3}, p_float32);
    Res2_update_0.set_expression(Res2_update_0(t, i1, i2, i3) + cast(p_float32, expr(o_expo, cast(p_float32, i3+i2+i1), p_float32)) * Res1(t, i1, i2, i3)); //exp(i(i3*px+i2*py+i1*pz))

    // -------------------------------------------------------
    // Layer III
    // -------------------------------------------------------
    buffer buf_fc1("buf_fc1", {K}, p_int32, a_input);
    buffer buf_fc2("buf_fc2", {K}, p_int32, a_input);
    buffer buf_fc3("buf_fc3", {K}, p_int32, a_input);

    buffer buf_res0("buf_res0", {BZ}, p_float32, a_temporary);
    buf_res0.set_auto_allocate(false);
    computation *alloc_res0 = buf_res0.allocate_at(Res2, t);
    buffer buf_res1("buf_res1", {N}, p_float32, a_temporary);
    buf_res1.set_auto_allocate(false);
    computation *alloc_res1 = buf_res1.allocate_at(Res2, t);
    buffer buf_res2("buf_res2", {T}, p_float32, a_output);
    buffer buf_d1("buf_d1", {1}, p_int32, a_temporary);
    buf_d1.set_auto_allocate(false);
    computation *alloc_d1 = buf_d1.allocate_at(Res2, t);
    buffer buf_d2("buf_d2", {1}, p_int32, a_temporary);
    buf_d2.set_auto_allocate(false);
    computation *alloc_d2 = buf_d2.allocate_at(Res2, t);
    buffer buf_d3("buf_d3", {1}, p_int32, a_temporary);
    buf_d3.set_auto_allocate(false);
    computation *alloc_d3 = buf_d3.allocate_at(Res2, t);

    buffer buf_S("buf_S", {BARYON_P, BARYON_P, BARYON_P, N, N, N, BARYON_P1}, p_float32, a_input);
    buffer buf_wp("buf_wp", {BARYON_N, BARYON_P, BARYON_P, BARYON_P}, p_float32, a_input);

    buffer buf_res2_cpu("buf_res2_cpu", {T}, p_float32, a_output);

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

    // -------------------------------------------------------
    // Layer II
    // -------------------------------------------------------

    Res2.then(*alloc_res1, t)
	.then(*alloc_res0, t)
	.then(*alloc_d1, t)
	.then(*alloc_d2, t)
	.then(*alloc_d3, t)
	.then(Res1, i3)
	.then(Res0, i3)
	.then(Res1_update_0, k)
	.then(Res2_update_0, i2);

    // Res0.tag_gpu_level(t, i1);

    // Res0.tag_vector_level(i3, BARYON_N);
    // Res2.tag_parallel_level(t);

    // -------------------------------------------------------
    // Code Generation
    // -------------------------------------------------------

    tiramisu::codegen({&buf_res2, &buf_S, &buf_wp, &buf_fc1, &buf_fc2, &buf_fc3},
		      "generated_old_baryon.o", true);
}

#define SIZE0 16

void generate_function2(std::string name, int size) {
    tiramisu::init(name);

    // constant p0("N", expr((int32_t) SIZE0));

    // var i("i", 0, p0), j("j", 0, p0), k("k", 0, p0);

    var i("i", 0, 16), j("j", 0, 16);
    input A("A", {"i", "j"}, {SIZE0, SIZE0}, p_float32);
    input B("B", {"i", "j"}, {SIZE0, SIZE0}, p_float32);


    buffer b_A("b_A", {expr(SIZE0), expr(SIZE0)}, p_float32, a_input);
    buffer b_B("b_B", {expr(SIZE0), expr(SIZE0)}, p_float32, a_input);
    buffer b_C("b_C", {expr(SIZE0), expr(SIZE0)}, p_float32, a_output);
    buffer b_A_gpu("b_A_gpu", {expr(SIZE0), expr(SIZE0)}, p_float32, a_temporary);
    buffer b_B_gpu("b_B_gpu", {expr(SIZE0), expr(SIZE0)}, p_float32, a_temporary);
    buffer b_C_gpu("b_C_gpu", {expr(SIZE0), expr(SIZE0)}, p_float32, a_temporary);
    b_A_gpu.tag_gpu_global();
    b_B_gpu.tag_gpu_global();
    b_C_gpu.tag_gpu_global();

    // for (int i = 0; i < 8; ++i) {
    //     for (int j = 0; j < 8; ++j) {
    //         C[i][j] = A[i][j] + B[j][i]; 
    //     }
    // }

    computation C("C", {i,j}, p_float32);
    computation copy_A_to_device({}, memcpy(b_A, b_A_gpu));
    computation copy_B_to_device({}, memcpy(b_B, b_B_gpu));
    computation copy_C_to_host({}, memcpy(b_C_gpu, b_C));


    C.set_expression(A(i, j) + B(j, i));

    copy_A_to_device.then(copy_B_to_device, computation::root)
                    .then(C, computation::root)
                    .then(copy_C_to_host, computation::root);

    C.tag_gpu_level(i, j);


    A.store_in(&b_A_gpu);
    B.store_in(&b_B_gpu);
    C.store_in(&b_C_gpu);

    tiramisu::codegen({&b_A, &b_B, &b_C}, "generated_old_baryon.o", true);
}

void generate_tutorial_04gpu1(std::string name, int size) {
    tiramisu::init(name);

    // -------------------------------------------------------
    // Layer I
    // -------------------------------------------------------

    constant N("N", SIZE0);

    // Declare loop iterators
    var i("i", 0, N), j("j", 0, N), k("k", 0, N);

    // Declare cpu buffers.
    buffer b_A("b_A", {expr(SIZE0), expr(SIZE0)}, p_uint8, a_input);
    buffer b_B("b_B", {expr(SIZE0), expr(SIZE0)}, p_uint8, a_input);
    buffer b_C("b_C", {expr(SIZE0), expr(SIZE0)}, p_uint8, a_output);
    // Declare gpu buffers.
    buffer b_A_gpu("b_A_gpu", {expr(SIZE0), expr(SIZE0)}, p_uint8, a_temporary);
    buffer b_B_gpu("b_B_gpu", {expr(SIZE0), expr(SIZE0)}, p_uint8, a_temporary);
    buffer b_C_gpu("b_C_gpu", {expr(SIZE0), expr(SIZE0)}, p_uint8, a_temporary);
    // Tag the GPU buffers to be stored in global memory.
    b_A_gpu.tag_gpu_global();
    b_B_gpu.tag_gpu_global();
    b_C_gpu.tag_gpu_global();

    // Declare inputs.
    input A("A", {"i", "j"}, {N, N}, p_uint8);
    input B("B", {"i", "j"}, {N, N}, p_uint8);

    // Declare a computation to initialize the reduction.
    computation C_init("C_init", {i, j}, expr((uint8_t) 0));

    // Declare the reduction operation.
    computation C("C", {i,j,k}, p_uint8);
    // Note that the previous computation has an empty expression,
    // because we can only use C in an expression after its declaration.
    C.set_expression(C(i, j, k - 1) + A(i, k) * B(k, j));

    // Declare host-gpu transfer computations.
    computation copy_A_to_device({}, memcpy(b_A, b_A_gpu));
    computation copy_B_to_device({}, memcpy(b_B, b_B_gpu));
    computation copy_C_to_host({}, memcpy(b_C_gpu, b_C));

    // -------------------------------------------------------
    // Layer II
    // -------------------------------------------------------

    // A simple tiling.
    C_init.gpu_tile(i, j, 16, 16);
    C.gpu_tile(i, j, 16, 16);

    // Scheduling commands
    copy_A_to_device.then(copy_B_to_device, computation::root)
                    .then(C_init, computation::root)
                    .then(C, computation::root)
                    .then(copy_C_to_host, computation::root);

    // -------------------------------------------------------
    // Layer III
    // -------------------------------------------------------

    // Map the computations to a buffer.
    A.store_in(&b_A_gpu);
    B.store_in(&b_B_gpu);

    // Store C_init[i,j] in b_C[i,j]
    C_init.store_in(&b_C_gpu);
    // Store C[i,j,k] in b_C[i,j]
    C.store_in(&b_C_gpu, {i,j});
    // Note that both of the computations C_init and C store their
    // results in the buffer b_C.

    // -------------------------------------------------------
    // Code Generation
    // -------------------------------------------------------

    // Generate object files. The last argument triggers cuda compilation.
    tiramisu::codegen({&b_A, &b_B, &b_C}, "generated_old_baryon.o", true);
}

void generate_tutorial_04gpu2(std::string name, int size) {
    tiramisu::init(name);

    // -------------------------------------------------------
    // Layer I
    // -------------------------------------------------------

    constant N("N", SIZE0);

    // Declare loop iterators
    var i("i", 0, N), j("j", 0, N), k("k", 0, N);
    var i0("i0"), i1("i1");
    var j0("j0"), j1("j1");
    var k0("k0"), k1("k1");

    // Declare inputs.
    input A("A", {i, k}, p_uint8);
    input B("B", {k, j}, p_uint8);
    A.get_buffer()->tag_gpu_global();
    B.get_buffer()->tag_gpu_global();

    // Declare a computation to initialize the reduction.
    computation C_init("C_init", {i, j}, expr((uint8_t) 0));
    C_init.get_buffer()->tag_gpu_global();

    // Declare the reduction operation.
    computation C("C", {i, j, k}, p_uint8);
    // Note that the previous computation has an empty expression,
    // because we can only use C in an expression after its declaration.
    C.set_expression(C(i, j, k - 1) + A(i, k) * B(k, j));

    // Declare cpu buffers.
    buffer b_A("b_A", {expr(SIZE0), expr(SIZE0)}, p_uint8, a_input);
    buffer b_B("b_B", {expr(SIZE0), expr(SIZE0)}, p_uint8, a_input);
    buffer b_C("b_C", {expr(SIZE0), expr(SIZE0)}, p_uint8, a_output);
    // Declare host-gpu transfer computations.
    computation copy_A_to_device({}, memcpy(b_A, *A.get_buffer()));
    computation copy_B_to_device({}, memcpy(b_B, *B.get_buffer()));
    computation copy_C_to_host({}, memcpy(*C_init.get_buffer(), b_C));

    // -------------------------------------------------------
    // Layer II
    // -------------------------------------------------------

    // A simple tiling.
    C.split(k, 16, k0, k1);
    C_init.gpu_tile(i, j, 16, 16, i0, j0, i1, j1);
    C.gpu_tile(i, j, 16, 16, i0, j0, i1, j1);

    // Scheduling commands
    copy_A_to_device.then(copy_B_to_device, computation::root)
                    .then(C_init, computation::root)
                    .then(C, j1)  // Fuse
                    .then(copy_C_to_host, computation::root);

    // -------------------------------------------------------
    // Layer III
    // -------------------------------------------------------

    // Tiramisu automatically allocates buffers for A, B, and C_init

    // Store C in the same buffer as C_init[i,j]
    C.store_in(C_init.get_buffer(), {i, j});

    // Use shared memory as an intermediate layer for global access
    C.cache_shared(A, k0, {16, 16}, {i0 * 16, k0 * 16});
    C.cache_shared(B, k0, {16, 16}, {k0 * 16, j0 * 16});

    // -------------------------------------------------------
    // Code Generation
    // -------------------------------------------------------

    // Generate object files. The last argument triggers cuda compilation.
    tiramisu::codegen({&b_A, &b_B, &b_C}, "generated_old_baryon.o", true);
}

void generate_indirect_array_access_cpu(std::string name, int size) {
    tiramisu::init(name);

    // constant p0("N", expr((int32_t) SIZE0));

    // var i("i", 0, p0), j("j", 0, p0), k("k", 0, p0);

    var i("i", 0, 16), j("j", 0, 16);
    input A("A", {"i", "j"}, {SIZE0, SIZE0}, p_uint16);
    input B("B", {"i", "j"}, {SIZE0, SIZE0}, p_uint16);


    buffer b_A("b_A", {expr(SIZE0), expr(SIZE0)}, p_uint16, a_input);
    buffer b_B("b_B", {expr(SIZE0), expr(SIZE0)}, p_uint16, a_input);
    buffer b_C("b_C", {expr(SIZE0), expr(SIZE0)}, p_uint16, a_output);

    // for (int i = 0; i < 8; ++i) {
    //     for (int j = 0; j < 8; ++j) {
    //         C[i][j] = A[ B[j][i] ] [ B[i][j] ]; 
    //     }
    // }

    computation C("C", {i,j}, p_uint16);

    C.set_expression(A(B(j, i), B(i, j)));

    A.store_in(&b_A);
    B.store_in(&b_B);
    C.store_in(&b_C);

    tiramisu::codegen({&b_A, &b_B, &b_C}, "generated_old_baryon.o");
}

void generate_indirect_array_access(std::string name, int size) {
    tiramisu::init(name);

    // constant p0("N", expr((int32_t) SIZE0));

    // var i("i", 0, p0), j("j", 0, p0), k("k", 0, p0);

    var i("i", 0, 16), j("j", 0, 16);
    input A("A", {"i", "j"}, {SIZE0, SIZE0}, p_int32);
    input B("B", {"i", "j"}, {SIZE0, SIZE0}, p_int32);


    buffer b_A("b_A", {expr(SIZE0), expr(SIZE0)}, p_int32, a_input);
    buffer b_B("b_B", {expr(SIZE0), expr(SIZE0)}, p_int32, a_input);
    buffer b_C("b_C", {expr(SIZE0), expr(SIZE0)}, p_int32, a_output);
    buffer b_A_gpu("b_A_gpu", {expr(SIZE0), expr(SIZE0)}, p_int32, a_temporary);
    buffer b_B_gpu("b_B_gpu", {expr(SIZE0), expr(SIZE0)}, p_int32, a_temporary);
    buffer b_C_gpu("b_C_gpu", {expr(SIZE0), expr(SIZE0)}, p_int32, a_temporary);
    b_A_gpu.tag_gpu_global();
    b_B_gpu.tag_gpu_global();
    b_C_gpu.tag_gpu_global();

    // for (int i = 0; i < 8; ++i) {
    //     for (int j = 0; j < 8; ++j) {
    //         C[i][j] = A[ B[j][i] ] [ B[i][j] ]; 
    //     }
    // }

    computation C("C", {i,j}, p_int32);
    computation copy_A_to_device({}, memcpy(b_A, b_A_gpu));
    computation copy_B_to_device({}, memcpy(b_B, b_B_gpu));
    computation copy_C_to_host({}, memcpy(b_C_gpu, b_C));


    C.set_expression(A(B(j, i), B(i, j)));

    copy_A_to_device.then(copy_B_to_device, computation::root)
                    .then(C, computation::root)
                    .then(copy_C_to_host, computation::root);

    C.tag_gpu_level(i, j);

    A.store_in(&b_A_gpu);
    B.store_in(&b_B_gpu);
    C.store_in(&b_C_gpu);

    tiramisu::codegen({&b_A, &b_B, &b_C}, "generated_old_baryon.o", true);
    // tiramisu::codegen({&b_A, &b_B, &b_C, &b_A_gpu, &b_B_gpu, &b_C_gpu}, "generated_old_baryon.o", true);
    // Old backend works for implicit integer casting, CUDA backend doesn't
}

void generate_predicate_test(std::string name, int size) {
    tiramisu::init(name);

    // constant p0("N", expr((int32_t) SIZE0));

    // var i("i", 0, p0), j("j", 0, p0), k("k", 0, p0);

    var i("i", 0, 16), j("j", 0, 16);
    input A("A", {"i", "j"}, {SIZE0, SIZE0}, p_float32);
    input B("B", {"i", "j"}, {SIZE0, SIZE0}, p_float32);


    buffer b_A("b_A", {expr(SIZE0), expr(SIZE0)}, p_float32, a_input);
    buffer b_B("b_B", {expr(SIZE0), expr(SIZE0)}, p_float32, a_input);
    buffer b_C("b_C", {expr(SIZE0), expr(SIZE0)}, p_float32, a_output);
    buffer b_A_gpu("b_A_gpu", {expr(SIZE0), expr(SIZE0)}, p_float32, a_temporary);
    buffer b_B_gpu("b_B_gpu", {expr(SIZE0), expr(SIZE0)}, p_float32, a_temporary);
    buffer b_C_gpu("b_C_gpu", {expr(SIZE0), expr(SIZE0)}, p_float32, a_temporary);
    b_A_gpu.tag_gpu_global();
    b_B_gpu.tag_gpu_global();
    b_C_gpu.tag_gpu_global();


    // for (int i = 0; i < 8; ++i) {
    //     for (int j = 0; j < 8; ++j) {
    //         if (i < 5.0f)
    //             C[i][j] = A[i][j] + B[j][i]; 
    //     }
    // }

    computation C("C", {i,j}, p_float32);
    computation copy_A_to_device({}, memcpy(b_A, b_A_gpu));
    computation copy_B_to_device({}, memcpy(b_B, b_B_gpu));
    computation copy_C_to_host({}, memcpy(b_C_gpu, b_C));


    C.set_expression(A(i, j) + B(j, i));
    C.add_predicate(i < 5);

    copy_A_to_device.then(copy_B_to_device, computation::root)
                    .then(C, computation::root)
                    .then(copy_C_to_host, computation::root);

    C.tag_gpu_level(i, j);

    A.store_in(&b_A_gpu);
    B.store_in(&b_B_gpu);
    C.store_in(&b_C_gpu);

    tiramisu::codegen({&b_A, &b_B, &b_C}, "generated_old_baryon.o", true);

    // This doesn't provide good CUDA code
    // tiramisu::codegen({&b_A, &b_B, &b_C, &b_A_gpu, &b_B_gpu, &b_C_gpu}, "generated_old_baryon.o", true);
    // Lowering after final simplification:
    // produce  {
    //   tiramisu_cuda_memcpy_to_device(b_A_gpu, tiramisu_address_of_float32(b_A.buffer, 0), (uint64)1024)
    //   tiramisu_cuda_memcpy_to_device(b_B_gpu, tiramisu_address_of_float32(b_B.buffer, 0), (uint64)1024)
    //   _kernel_0_wrapper(b_A_gpu, b_B_gpu, b_C_gpu)
    //   tiramisu_cuda_memcpy_to_host(tiramisu_address_of_float32(b_C.buffer, 0), b_C_gpu, (uint64)1024)
    // }

    // Internal error at /home/nedjima/mit-nyuad/tiramisu/3rdParty/Halide/src/CodeGen_LLVM.cpp:1093
    // Symbol not found: b_A_gpu
}

int main(int argc, char **argv)
{
    // generate_function2("tiramisu_generated_code", BARYON_N);
    // generate_tutorial_04gpu1("tiramisu_generated_code", BARYON_N);
    // generate_tutorial_04gpu2("tiramisu_generated_code", BARYON_N);
    // generate_indirect_array_access_cpu("tiramisu_generated_code", BARYON_N);
    generate_indirect_array_access("tiramisu_generated_code", BARYON_N);
    // generate_predicate_test("tiramisu_generated_code", BARYON_N);

    return 0;
}