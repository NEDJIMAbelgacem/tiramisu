lines = """computation copy_buf_C_r_device_to_host({}, memcpy(buf_C_r, buf_C_r_cpu));
computation copy_buf_C_i_device_to_host({}, memcpy(buf_C_i, buf_C_i_cpu));
computation copy_B1_prop_r_device_to_host({}, memcpy(*B1_prop_r.get_buffer(), B1_prop_r_cpu));
computation copy_B1_prop_i_device_to_host({}, memcpy(*B1_prop_i.get_buffer(), B1_prop_i_cpu));
computation copy_B2_prop_r_device_to_host({}, memcpy(*B2_prop_r.get_buffer(), B2_prop_r_cpu));
computation copy_B2_prop_i_device_to_host({}, memcpy(*B2_prop_i.get_buffer(), B2_prop_i_cpu));
computation copy_src_psi_B1_r_device_to_host({}, memcpy(*src_psi_B1_r.get_buffer(), src_psi_B1_r_cpu));
computation copy_src_psi_B1_i_device_to_host({}, memcpy(*src_psi_B1_i.get_buffer(), src_psi_B1_i_cpu));
computation copy_src_psi_B2_r_device_to_host({}, memcpy(*src_psi_B2_r.get_buffer(), src_psi_B2_r_cpu));
computation copy_src_psi_B2_i_device_to_host({}, memcpy(*src_psi_B2_i.get_buffer(), src_psi_B2_i_cpu));
computation copy_snk_psi_B1_r_device_to_host({}, memcpy(*snk_psi_B1_r.get_buffer(), snk_psi_B1_r_cpu));
computation copy_snk_psi_B1_i_device_to_host({}, memcpy(*snk_psi_B1_i.get_buffer(), snk_psi_B1_i_cpu));
computation copy_snk_psi_B2_r_device_to_host({}, memcpy(*snk_psi_B2_r.get_buffer(), snk_psi_B2_r_cpu));
computation copy_snk_psi_B2_i_device_to_host({}, memcpy(*snk_psi_B2_i.get_buffer(), snk_psi_B2_i_cpu));
computation copy_src_spins_device_to_host({}, memcpy(*src_spins.get_buffer(), src_spins_cpu));
computation copy_sigs_device_to_host({}, memcpy(*sigs.get_buffer(), sigs_cpu));
computation copy_snk_psi_r_device_to_host({}, memcpy(*snk_psi_r.get_buffer(), snk_psi_r_cpu));
computation copy_snk_psi_i_device_to_host({}, memcpy(*snk_psi_i.get_buffer(), snk_psi_i_cpu));
computation copy_hex_snk_psi_r_device_to_host({}, memcpy(*hex_snk_psi_r.get_buffer(), hex_snk_psi_r_cpu));
computation copy_hex_snk_psi_i_device_to_host({}, memcpy(*hex_snk_psi_i.get_buffer(), hex_snk_psi_i_cpu));
computation copy_src_color_weights_device_to_host({}, memcpy(*src_color_weights.get_buffer(), src_color_weights_cpu));
computation copy_src_spin_weights_device_to_host({}, memcpy(*src_spin_weights.get_buffer(), src_spin_weights_cpu));
computation copy_src_weights_device_to_host({}, memcpy(*src_weights.get_buffer(), src_weights_cpu));
computation copy_snk_color_weights_device_to_host({}, memcpy(*snk_color_weights.get_buffer(), snk_color_weights_cpu));
computation copy_snk_spin_weights_device_to_host({}, memcpy(*snk_spin_weights.get_buffer(), snk_spin_weights_cpu));
computation copy_snk_weights_device_to_host({}, memcpy(*snk_weights.get_buffer(), snk_weights_cpu));
computation copy_hex_snk_color_weights_device_to_host({}, memcpy(*hex_snk_color_weights.get_buffer(), hex_snk_color_weights_cpu));
computation copy_hex_snk_spin_weights_device_to_host({}, memcpy(*hex_snk_spin_weights.get_buffer(), hex_snk_spin_weights_cpu));
computation copy_hex_snk_weights_device_to_host({}, memcpy(*hex_snk_weights.get_buffer(), hex_snk_weights_cpu));
computation copy_src_spin_block_weights_device_to_host({}, memcpy(*src_spin_block_weights.get_buffer(), src_spin_block_weights_cpu));
computation copy_snk_b_device_to_host({}, memcpy(*snk_b.get_buffer(), snk_b_cpu));"""
lines = lines.split('\n')
for l in lines:
    l = l.replace('device', '1').replace('host', 'device').replace('1', 'host')
    firstOpenParenIndex = l.index('(')
    secondOpenParenIndex = firstOpenParenIndex + l[firstOpenParenIndex + 1:].index('(') + 1
    inv_l = l[::-1]
    firstCloseParenIndex = inv_l.index(')')
    secondCloseParenIndex = firstCloseParenIndex + inv_l[firstCloseParenIndex + 1:].index(')') + 1
    firstCloseParenIndex = len(l) - firstCloseParenIndex - 1
    secondCloseParenIndex = len(l) - secondCloseParenIndex - 1
    left, right = [i.strip() for i in l[secondOpenParenIndex + 1: secondCloseParenIndex].split(',')]
    print(l[:secondOpenParenIndex+1] + left + ", " + right + l[secondCloseParenIndex:])