import re
out = open("out.cpp", "w")
patt = re.compile("[ \(,]\d+[ \),}]")
def replace_func(s):
    return s.group()[:-1] + "l" + s.group()[-1]
for l in open("/home/belgacem/PFE/tiramisu/benchmarks/tensors/dibaryon/gpu_tiramisu_make_fused_dibaryon_blocks_correlator/gpu_tiramisu_make_fused_dibaryon_blocks_correlator_generator.cpp").readlines():
    result = re.sub(patt, replace_func, l)
    out.write( result )
    print(result)
