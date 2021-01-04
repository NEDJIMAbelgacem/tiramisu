git pull belgacem_tiramisu dibaryon-gpu
cd ./build
make run_gpu_tiramisu_make_fused_dibaryon_blocks_correlator &> out.txt
mv ./out.txt ../out.txt
git add ../out.txt
git commit -m "change"
