git pull belgacem_tiramisu dibaryon-gpu
cd ./build
make run_gpu_tiramisu_make_fused_baryon_blocks_correlator &> out.txt
mv ./out.txt ../out.txt
git add *
git commit -m "change"
