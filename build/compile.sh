cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/tensors/baryon/gpu_tiramisu_make_fused_baryon_blocks_correlator
# compile generator
g++   -DNVCC_PATH=\"/usr/local/cuda/bin/nvcc\" \
-I/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/include \
-I/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/3rdParty/isl/build/include \
-I/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/3rdParty/Halide/include \
-I/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/3rdParty/Halide/tools \
-I/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build \
-I/usr/local/cuda/include \
-std=c++11 -Wall -Wno-sign-compare -fno-rtti -DHALIDE_NO_JPEG -g \
-O0   -o CMakeFiles/gpu_tiramisu_make_fused_baryon_blocks_correlator_generator.dir/gpu_tiramisu_make_fused_baryon_blocks_correlator_generator.cpp.o \
-c /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/tensors/baryon/gpu_tiramisu_make_fused_baryon_blocks_correlator/gpu_tiramisu_make_fused_baryon_blocks_correlator_generator.cpp

# link generator
/usr/bin/cmake -E cmake_link_script CMakeFiles/gpu_tiramisu_make_fused_baryon_blocks_correlator_generator.dir/link.txt --verbose=1
g++   -std=c++11 -Wall -Wno-sign-compare -fno-rtti -DHALIDE_NO_JPEG -g -O0  \
CMakeFiles/gpu_tiramisu_make_fused_baryon_blocks_correlator_generator.dir/gpu_tiramisu_make_fused_baryon_blocks_correlator_generator.cpp.o  \
-o ../../../../gpu_tiramisu_make_fused_baryon_blocks_correlator_generator ../../../../libtiramisu.so \
../../../../../3rdParty/Halide/lib/libHalide.a ../../../../../3rdParty/isl/build/lib/libisl.so -ldl -lpthread -lrt -ldl -lpthread -lz -lm \
../../../../libcuda_wrapper.a /usr/local/cuda/lib64/libcudart_static.a -lpthread -ldl /usr/lib/x86_64-linux-gnu/librt.so \
/usr/local/cuda/lib64/libcublas.so -Wl,-rpath,/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build:/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/3rdParty/isl/build/lib:/usr/local/cuda/lib64 

# run generator
../../../../gpu_tiramisu_make_fused_baryon_blocks_correlator_generator
# compile wrapper
/usr/bin/cmake -E cmake_link_script CMakeFiles/gpu_tiramisu_make_fused_baryon_blocks_correlator_wrapper.dir/link.txt --verbose=1
g++   -std=c++11 -Wall -Wno-sign-compare -fno-rtti -DHALIDE_NO_JPEG -g -O0  \
CMakeFiles/gpu_tiramisu_make_fused_baryon_blocks_correlator_wrapper.dir/gpu_tiramisu_make_fused_baryon_blocks_correlator_wrapper.cpp.o \
generated_gpu_tiramisu_make_fused_baryon_blocks_correlator.o generated_gpu_tiramisu_make_fused_baryon_blocks_correlator.o_cpu.o \
generated_gpu_tiramisu_make_fused_baryon_blocks_correlator.o_gpu.o  -o ../../../../gpu_tiramisu_make_fused_baryon_blocks_correlator_wrapper \
../../../../libtiramisu.so ../../../../../3rdParty/Halide/lib/libHalide.a ../../../../../3rdParty/isl/build/lib/libisl.so -ldl -lpthread -lrt -ldl \
-lpthread -lz -lm ../../../../libcuda_wrapper.a /usr/local/cuda/lib64/libcudart_static.a -lpthread -ldl /usr/lib/x86_64-linux-gnu/librt.so \
/usr/local/cuda/lib64/libcublas.so -Wl,-rpath,/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build:/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/3rdParty/isl/build/lib:/usr/local/cuda/lib64
# run wrapper
../../../../gpu_tiramisu_make_fused_baryon_blocks_correlator_wrapper