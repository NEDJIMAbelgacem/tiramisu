cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/tensors/dibaryon/gpu_tiramisu_make_fused_dibaryon_blocks_correlator
g++   -std=c++11 -Wall -Wno-sign-compare -fno-rtti -DHALIDE_NO_JPEG -g -O0   CMakeFiles/gpu_tiramisu_make_fused_dibaryon_blocks_correlator_wrapper.dir/gpu_tiramisu_make_fused_dibaryon_blocks_correlator_wrapper.cpp.o generated_gpu_tiramisu_make_fused_dibaryon_blocks_correlator.o generated_gpu_tiramisu_make_fused_dibaryon_blocks_correlator.o_cpu.o generated_gpu_tiramisu_make_fused_dibaryon_blocks_correlator.o_gpu.o  -o ../../../../gpu_tiramisu_make_fused_dibaryon_blocks_correlator_wrapper ../../../../libtiramisu.so ../../../../../3rdParty/Halide/lib/libHalide.a ../../../../../3rdParty/isl/build/lib/libisl.so -ldl -lpthread -lrt -ldl -lpthread -lz -lm ../../../../libcuda_wrapper.a /usr/local/cuda/lib64/libcudart_static.a -lpthread -ldl /usr/lib/x86_64-linux-gnu/librt.so /usr/local/cuda/lib64/libcublas.so -Wl,-rpath,/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build:/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/3rdParty/isl/build/lib:/usr/local/cuda/lib64 
cd -