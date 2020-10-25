#include "Halide.h"
#include <tiramisu/utils.h>
#include <cstdlib>
#include <iostream>
#include "benchmarks.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "wrapper.h"
#ifdef __cplusplus
}  // extern "C"
#endif

#include "baryon_ref.cpp"

int main(int, char **)
{
    std::vector<std::chrono::duration<double,std::milli>> duration_vector_1;
    std::vector<std::chrono::duration<double,std::milli>> duration_vector_2;

    // Halide::Buffer<float> buf_res2(BT, "buf_res2");
    // Halide::Buffer<float> buf_res2_ref(BT, "buf_res2_ref");
    // Halide::Buffer<float> buf_S(BK, BZ, BY, BX, BT, BARYON_P, BARYON_P, "buf_S");
    // Halide::Buffer<float> buf_wp(BARYON_P, BARYON_P, BARYON_P, BK, "buf_wp");
    // Halide::Buffer<int> fc1(BARYON_N, "buf_fc1");
    // Halide::Buffer<int> fc2(BARYON_N, "buf_fc2");
    // Halide::Buffer<int> fc3(BARYON_N, "buf_fc2");
	Halide::Buffer<float> buf_res2(std::vector<int>{ BT }, "buf_res2");
    Halide::Buffer<float> buf_res2_ref(std::vector<int>{ BT }, "buf_res2_ref");
    Halide::Buffer<float> buf_S(std::vector<int>{BARYON_P, BARYON_P, BT, BX, BY, BZ, BZ}, "buf_S");
    Halide::Buffer<float> buf_wp(std::vector<int>{BK, BARYON_P, BARYON_P, BARYON_P}, "buf_wp");
    Halide::Buffer<int> fc1(std::vector<int>{ BARYON_N }, "buf_fc1");
    Halide::Buffer<int> fc2(BARYON_N, "buf_fc2");
    Halide::Buffer<int> fc3(BARYON_N, "buf_fc3");


    init_buffers((float (*)[BARYON_P][BT][BX][BY][BZ][BK]) buf_S.raw_buffer()->host,
		 (float (*)[BARYON_P][BARYON_P][BARYON_P]) buf_wp.raw_buffer()->host,
		 (float) 5,
		 (int *) fc1.raw_buffer()->host,
		 (int *) fc2.raw_buffer()->host,
		 (int *) fc3.raw_buffer()->host);
	// init_buffers((reinterpret_cast<float S[BARYON_P][BARYON_P][BT][BX][BY][BZ][BK]>(buf_S).raw_buffer()->host,
	// 	 (float (*)[BARYON_P][BARYON_P][BARYON_P]) buf_wp.raw_buffer()->host,
	// 	 (float) 5,
	// 	 (int *) fc1.raw_buffer()->host,
	// 	 (int *) fc2.raw_buffer()->host,
	// 	 (int *) fc3.raw_buffer()->host);
	std::cerr << "init_buffers executed properly" << std::endl;

    for (int i = 0; i < NB_TESTS; i++)
    {
    	    init_buffer(buf_res2_ref, (float)0);
	    auto start2 = std::chrono::high_resolution_clock::now();

	    ref((float *) buf_res2_ref.raw_buffer()->host,
		(float (*)[BARYON_P][BT][BX][BY][BZ][BK]) buf_S.raw_buffer()->host,
		(float (*)[BARYON_P][BARYON_P][BARYON_P		]) buf_wp.raw_buffer()->host,
		(int *) fc1.raw_buffer()->host,
		(int *) fc2.raw_buffer()->host,
		(int *) fc3.raw_buffer()->host);

	    auto end2 = std::chrono::high_resolution_clock::now();
	    std::chrono::duration<double,std::milli> duration2 = end2 - start2;
	    duration_vector_2.push_back(duration2);
    }

    for (int i = 0; i < NB_TESTS; i++)
    {
	    init_buffer(buf_res2, (float)0);
	    auto start1 = std::chrono::high_resolution_clock::now();
	    tiramisu_generated_code(buf_res2.raw_buffer(),
				    buf_S.raw_buffer(),
				    buf_wp.raw_buffer(),
				    fc1.raw_buffer(),
				    fc2.raw_buffer(),
				    fc3.raw_buffer());
	    auto end1 = std::chrono::high_resolution_clock::now();
	    std::chrono::duration<double,std::milli> duration1 = end1 - start1;
	    duration_vector_1.push_back(duration1);
    }

    std::cout << std::endl << "Reference buffer : ";
    print_buffer(buf_res2_ref);

    std::cout << "Tiramisu buffer : ";
    print_buffer(buf_res2);

    compare_buffers("benchmark_" + std::string(TEST_NAME_STR), buf_res2, buf_res2_ref);

    print_time("performance_CPU.csv", "baryon",
               {"Ref", "Tiramisu"},
               {median(duration_vector_2), median(duration_vector_1)});

    return 0;
}