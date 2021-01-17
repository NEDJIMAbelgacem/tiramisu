import re
FILENAME = "./gpu_tiramisu_make_fused_dibaryon_blocks_correlator_generator.cpp"
lines = [i.rstrip() for i in open(FILENAME).readlines()]
out = []
for line in lines:
    stripped_line = line.strip();
    out.append(line)
    if re.match(r"buffer [A-Za-z_][A-Za-z_0-9]*\(.*\);", stripped_line):
        start_spaces = line[:line.index('b')]
        tag_gpu_level_statement = stripped_line[7:stripped_line.index('(')] + '.tag_gpu_global();'
        out.append(start_spaces + tag_gpu_level_statement)

for i in out:
    print(i)