
Lowering after final simplification:
assert((reinterpret(uint64, buf_C_r.buffer) != (uint64)0), halide_error_buffer_argument_is_null("buf_C_r"))
assert((reinterpret(uint64, buf_C_i.buffer) != (uint64)0), halide_error_buffer_argument_is_null("buf_C_i"))
assert((reinterpret(uint64, _src_weights_b26.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_src_weights_b26"))
assert((reinterpret(uint64, _src_spins_b20.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_src_spins_b20"))
assert((reinterpret(uint64, _src_spin_weights_b25.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_src_spin_weights_b25"))
assert((reinterpret(uint64, _src_spin_block_weights_b21.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_src_spin_block_weights_b21"))
assert((reinterpret(uint64, _src_psi_B2_r_b8.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_src_psi_B2_r_b8"))
assert((reinterpret(uint64, _src_psi_B2_i_b9.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_src_psi_B2_i_b9"))
assert((reinterpret(uint64, _src_psi_B1_r_b6.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_src_psi_B1_r_b6"))
assert((reinterpret(uint64, _src_psi_B1_i_b7.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_src_psi_B1_i_b7"))
assert((reinterpret(uint64, _src_color_weights_b24.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_src_color_weights_b24"))
assert((reinterpret(uint64, _snk_weights_b29.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_snk_weights_b29"))
assert((reinterpret(uint64, _snk_spin_weights_b28.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_snk_spin_weights_b28"))
assert((reinterpret(uint64, _snk_psi_r_b18.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_snk_psi_r_b18"))
assert((reinterpret(uint64, _snk_psi_i_b19.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_snk_psi_i_b19"))
assert((reinterpret(uint64, _snk_psi_B2_r_b12.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_snk_psi_B2_r_b12"))
assert((reinterpret(uint64, _snk_psi_B2_i_b13.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_snk_psi_B2_i_b13"))
assert((reinterpret(uint64, _snk_psi_B1_r_b10.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_snk_psi_B1_r_b10"))
assert((reinterpret(uint64, _snk_psi_B1_i_b11.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_snk_psi_B1_i_b11"))
assert((reinterpret(uint64, _snk_color_weights_b27.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_snk_color_weights_b27"))
assert((reinterpret(uint64, _snk_b_b23.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_snk_b_b23"))
assert((reinterpret(uint64, _sigs_b22.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_sigs_b22"))
assert((reinterpret(uint64, _hex_src_psi_r_b14.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_hex_src_psi_r_b14"))
assert((reinterpret(uint64, _hex_src_psi_i_b15.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_hex_src_psi_i_b15"))
assert((reinterpret(uint64, _hex_snk_weights_b32.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_hex_snk_weights_b32"))
assert((reinterpret(uint64, _hex_snk_spin_weights_b31.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_hex_snk_spin_weights_b31"))
assert((reinterpret(uint64, _hex_snk_psi_r_b16.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_hex_snk_psi_r_b16"))
assert((reinterpret(uint64, _hex_snk_psi_i_b17.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_hex_snk_psi_i_b17"))
assert((reinterpret(uint64, _hex_snk_color_weights_b30.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_hex_snk_color_weights_b30"))
assert((reinterpret(uint64, _B2_prop_r_b4.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_B2_prop_r_b4"))
assert((reinterpret(uint64, _B2_prop_i_b5.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_B2_prop_i_b5"))
assert((reinterpret(uint64, _B1_prop_r_b2.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_B1_prop_r_b2"))
assert((reinterpret(uint64, _B1_prop_i_b3.buffer) != (uint64)0), halide_error_buffer_argument_is_null("_B1_prop_i_b3"))
let _B1_prop_i_b3 = _halide_buffer_get_host(_B1_prop_i_b3.buffer)
let _B1_prop_r_b2 = _halide_buffer_get_host(_B1_prop_r_b2.buffer)
let _B2_prop_i_b5 = _halide_buffer_get_host(_B2_prop_i_b5.buffer)
let _B2_prop_r_b4 = _halide_buffer_get_host(_B2_prop_r_b4.buffer)
let _hex_snk_color_weights_b30 = _halide_buffer_get_host(_hex_snk_color_weights_b30.buffer)
let _hex_snk_psi_i_b17 = _halide_buffer_get_host(_hex_snk_psi_i_b17.buffer)
let _hex_snk_psi_r_b16 = _halide_buffer_get_host(_hex_snk_psi_r_b16.buffer)
let _hex_snk_spin_weights_b31 = _halide_buffer_get_host(_hex_snk_spin_weights_b31.buffer)
let _hex_snk_weights_b32 = _halide_buffer_get_host(_hex_snk_weights_b32.buffer)
let _hex_src_psi_i_b15 = _halide_buffer_get_host(_hex_src_psi_i_b15.buffer)
let _hex_src_psi_r_b14 = _halide_buffer_get_host(_hex_src_psi_r_b14.buffer)
let _sigs_b22 = _halide_buffer_get_host(_sigs_b22.buffer)
let _snk_b_b23 = _halide_buffer_get_host(_snk_b_b23.buffer)
let _snk_color_weights_b27 = _halide_buffer_get_host(_snk_color_weights_b27.buffer)
let _snk_psi_B1_i_b11 = _halide_buffer_get_host(_snk_psi_B1_i_b11.buffer)
let _snk_psi_B1_r_b10 = _halide_buffer_get_host(_snk_psi_B1_r_b10.buffer)
let _snk_psi_B2_i_b13 = _halide_buffer_get_host(_snk_psi_B2_i_b13.buffer)
let _snk_psi_B2_r_b12 = _halide_buffer_get_host(_snk_psi_B2_r_b12.buffer)
let _snk_psi_i_b19 = _halide_buffer_get_host(_snk_psi_i_b19.buffer)
let _snk_psi_r_b18 = _halide_buffer_get_host(_snk_psi_r_b18.buffer)
let _snk_spin_weights_b28 = _halide_buffer_get_host(_snk_spin_weights_b28.buffer)
let _snk_weights_b29 = _halide_buffer_get_host(_snk_weights_b29.buffer)
let _src_color_weights_b24 = _halide_buffer_get_host(_src_color_weights_b24.buffer)
let _src_psi_B1_i_b7 = _halide_buffer_get_host(_src_psi_B1_i_b7.buffer)
let _src_psi_B1_r_b6 = _halide_buffer_get_host(_src_psi_B1_r_b6.buffer)
let _src_psi_B2_i_b9 = _halide_buffer_get_host(_src_psi_B2_i_b9.buffer)
let _src_psi_B2_r_b8 = _halide_buffer_get_host(_src_psi_B2_r_b8.buffer)
let _src_spin_block_weights_b21 = _halide_buffer_get_host(_src_spin_block_weights_b21.buffer)
let _src_spin_weights_b25 = _halide_buffer_get_host(_src_spin_weights_b25.buffer)
let _src_spins_b20 = _halide_buffer_get_host(_src_spins_b20.buffer)
let _src_weights_b26 = _halide_buffer_get_host(_src_weights_b26.buffer)
let buf_C_i = _halide_buffer_get_host(buf_C_i.buffer)
let buf_C_r = _halide_buffer_get_host(buf_C_r.buffer)
produce  {
  allocate buf_src_B2_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_src_B2_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_src_B2_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_src_B2_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_src_B2_Blocal_props_r2_r[float64 * 2 * 3]
  allocate buf_src_B2_Blocal_props_r2_i[float64 * 2 * 3]
  allocate buf_src_B2_Blocal_props_r1_r[float64 * 2 * 3]
  allocate buf_src_B2_Blocal_props_r1_i[float64 * 2 * 3]
  allocate buf_src_B2_Blocal_diquark_r2_r[float64 * 1]
  allocate buf_src_B2_Blocal_diquark_r2_i[float64 * 1]
  allocate buf_src_B2_Blocal_diquark_r1_r[float64 * 1]
  allocate buf_src_B2_Blocal_diquark_r1_i[float64 * 1]
  allocate buf_src_B1_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_src_B1_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_src_B1_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_src_B1_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_src_B1_Blocal_props_r2_r[float64 * 2 * 3]
  allocate buf_src_B1_Blocal_props_r2_i[float64 * 2 * 3]
  allocate buf_src_B1_Blocal_props_r1_r[float64 * 2 * 3]
  allocate buf_src_B1_Blocal_props_r1_i[float64 * 2 * 3]
  allocate buf_src_B1_Blocal_diquark_r2_r[float64 * 1]
  allocate buf_src_B1_Blocal_diquark_r2_i[float64 * 1]
  allocate buf_src_B1_Blocal_diquark_r1_r[float64 * 1]
  allocate buf_src_B1_Blocal_diquark_r1_i[float64 * 1]
  allocate buf_snk_B2_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_snk_B2_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_snk_B2_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_snk_B2_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_snk_B2_Blocal_props_r2_r[float64 * 2 * 3]
  allocate buf_snk_B2_Blocal_props_r2_i[float64 * 2 * 3]
  allocate buf_snk_B2_Blocal_props_r1_r[float64 * 2 * 3]
  allocate buf_snk_B2_Blocal_props_r1_i[float64 * 2 * 3]
  allocate buf_snk_B2_Blocal_diquark_r2_r[float64 * 1]
  allocate buf_snk_B2_Blocal_diquark_r2_i[float64 * 1]
  allocate buf_snk_B2_Blocal_diquark_r1_r[float64 * 1]
  allocate buf_snk_B2_Blocal_diquark_r1_i[float64 * 1]
  allocate buf_snk_B1_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_snk_B1_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_snk_B1_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_snk_B1_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_snk_B1_Blocal_props_r2_r[float64 * 2 * 3]
  allocate buf_snk_B1_Blocal_props_r2_i[float64 * 2 * 3]
  allocate buf_snk_B1_Blocal_props_r1_r[float64 * 2 * 3]
  allocate buf_snk_B1_Blocal_props_r1_i[float64 * 2 * 3]
  allocate buf_snk_B1_Blocal_diquark_r2_r[float64 * 1]
  allocate buf_snk_B1_Blocal_diquark_r2_i[float64 * 1]
  allocate buf_snk_B1_Blocal_diquark_r1_r[float64 * 1]
  allocate buf_snk_B1_Blocal_diquark_r1_i[float64 * 1]
  allocate buf_flip_src_B2_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_src_B2_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_src_B2_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_src_B2_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_src_B1_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_src_B1_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_src_B1_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_src_B1_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_snk_B2_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_snk_B2_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_snk_B2_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_snk_B2_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_snk_B1_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_snk_B1_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_snk_B1_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_snk_B1_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_H_BB_new_term_b2_r[float64 * 1]
  allocate buf_flip_H_BB_new_term_b2_i[float64 * 1]
  allocate buf_flip_H_BB_new_term_b1_r[float64 * 1]
  allocate buf_flip_H_BB_new_term_b1_i[float64 * 1]
  allocate buf_flip_BB_H_new_term_b2_r[float64 * 1]
  allocate buf_flip_BB_H_new_term_b2_i[float64 * 1]
  allocate buf_flip_BB_H_new_term_b1_r[float64 * 1]
  allocate buf_flip_BB_H_new_term_b1_i[float64 * 1]
  allocate buf_flip_BB_BB_new_term_b2_r[float64 * 1]
  allocate buf_flip_BB_BB_new_term_b2_i[float64 * 1]
  allocate buf_flip_BB_BB_new_term_b1_r[float64 * 1]
  allocate buf_flip_BB_BB_new_term_b1_i[float64 * 1]
  allocate buf_flip_B2_Bthird_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bthird_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bthird_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bthird_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bsecond_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bsecond_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bsecond_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bsecond_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bfirst_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bfirst_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bfirst_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B2_Bfirst_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bthird_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bthird_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bthird_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bthird_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bsecond_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bsecond_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bsecond_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bsecond_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bfirst_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bfirst_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bfirst_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_flip_B1_Bfirst_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_H_BB_new_term_b2_r[float64 * 1]
  allocate buf_H_BB_new_term_b2_i[float64 * 1]
  allocate buf_H_BB_new_term_b1_r[float64 * 1]
  allocate buf_H_BB_new_term_b1_i[float64 * 1]
  allocate buf_C_H_H_prop_r[float64 * 1]
  allocate buf_C_H_H_prop_i[float64 * 1]
  allocate buf_C_H_BB_prop_r[float64 * 1]
  allocate buf_C_H_BB_prop_i[float64 * 1]
  allocate buf_C_BB_H_prop_r[float64 * 1]
  allocate buf_C_BB_H_prop_i[float64 * 1]
  allocate buf_C_BB_BB_prop_r[float64 * 1]
  allocate buf_C_BB_BB_prop_i[float64 * 1]
  allocate buf_BB_H_new_term_b2_r[float64 * 1]
  allocate buf_BB_H_new_term_b2_i[float64 * 1]
  allocate buf_BB_H_new_term_b1_r[float64 * 1]
  allocate buf_BB_H_new_term_b1_i[float64 * 1]
  allocate buf_BB_BB_new_term_b2_r[float64 * 1]
  allocate buf_BB_BB_new_term_b2_i[float64 * 1]
  allocate buf_BB_BB_new_term_b1_r[float64 * 1]
  allocate buf_BB_BB_new_term_b1_i[float64 * 1]
  allocate buf_B2_Bthird_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bthird_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bthird_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bthird_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bthird_props_r2_r[float64 * 2 * 3]
  allocate buf_B2_Bthird_props_r2_i[float64 * 2 * 3]
  allocate buf_B2_Bthird_props_r1_r[float64 * 2 * 3]
  allocate buf_B2_Bthird_props_r1_i[float64 * 2 * 3]
  allocate buf_B2_Bthird_diquark_r2_r[float64 * 1]
  allocate buf_B2_Bthird_diquark_r2_i[float64 * 1]
  allocate buf_B2_Bthird_diquark_r1_r[float64 * 1]
  allocate buf_B2_Bthird_diquark_r1_i[float64 * 1]
  allocate buf_B2_Bsecond_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bsecond_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bsecond_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bsecond_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bsecond_props_r2_r[float64 * 2 * 3]
  allocate buf_B2_Bsecond_props_r2_i[float64 * 2 * 3]
  allocate buf_B2_Bsecond_props_r1_r[float64 * 2 * 3]
  allocate buf_B2_Bsecond_props_r1_i[float64 * 2 * 3]
  allocate buf_B2_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Blocal_props_r2_r[float64 * 2 * 3]
  allocate buf_B2_Blocal_props_r2_i[float64 * 2 * 3]
  allocate buf_B2_Blocal_props_r1_r[float64 * 2 * 3]
  allocate buf_B2_Blocal_props_r1_i[float64 * 2 * 3]
  allocate buf_B2_Blocal_diquark_r2_r[float64 * 1]
  allocate buf_B2_Blocal_diquark_r2_i[float64 * 1]
  allocate buf_B2_Blocal_diquark_r1_r[float64 * 1]
  allocate buf_B2_Blocal_diquark_r1_i[float64 * 1]
  allocate buf_B2_Bfirst_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bfirst_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bfirst_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bfirst_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B2_Bfirst_props_r2_r[float64 * 2 * 3]
  allocate buf_B2_Bfirst_props_r2_i[float64 * 2 * 3]
  allocate buf_B2_Bfirst_props_r1_r[float64 * 2 * 3]
  allocate buf_B2_Bfirst_props_r1_i[float64 * 2 * 3]
  allocate buf_B2_Bfirst_diquark_r2_r[float64 * 1]
  allocate buf_B2_Bfirst_diquark_r2_i[float64 * 1]
  allocate buf_B2_Bfirst_diquark_r1_r[float64 * 1]
  allocate buf_B2_Bfirst_diquark_r1_i[float64 * 1]
  allocate buf_B1_Bthird_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bthird_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bthird_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bthird_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bthird_props_r2_r[float64 * 2 * 3]
  allocate buf_B1_Bthird_props_r2_i[float64 * 2 * 3]
  allocate buf_B1_Bthird_props_r1_r[float64 * 2 * 3]
  allocate buf_B1_Bthird_props_r1_i[float64 * 2 * 3]
  allocate buf_B1_Bthird_diquark_r2_r[float64 * 1]
  allocate buf_B1_Bthird_diquark_r2_i[float64 * 1]
  allocate buf_B1_Bthird_diquark_r1_r[float64 * 1]
  allocate buf_B1_Bthird_diquark_r1_i[float64 * 1]
  allocate buf_B1_Bsecond_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bsecond_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bsecond_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bsecond_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bsecond_props_r2_r[float64 * 2 * 3]
  allocate buf_B1_Bsecond_props_r2_i[float64 * 2 * 3]
  allocate buf_B1_Bsecond_props_r1_r[float64 * 2 * 3]
  allocate buf_B1_Bsecond_props_r1_i[float64 * 2 * 3]
  allocate buf_B1_Blocal_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Blocal_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Blocal_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Blocal_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Blocal_props_r2_r[float64 * 2 * 3]
  allocate buf_B1_Blocal_props_r2_i[float64 * 2 * 3]
  allocate buf_B1_Blocal_props_r1_r[float64 * 2 * 3]
  allocate buf_B1_Blocal_props_r1_i[float64 * 2 * 3]
  allocate buf_B1_Blocal_diquark_r2_r[float64 * 1]
  allocate buf_B1_Blocal_diquark_r2_i[float64 * 1]
  allocate buf_B1_Blocal_diquark_r1_r[float64 * 1]
  allocate buf_B1_Blocal_diquark_r1_i[float64 * 1]
  allocate buf_B1_Bfirst_r2_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bfirst_r2_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bfirst_r1_r[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bfirst_r1_i[float64 * 44 * 2 * 3 * 2 * 3 * 2 * 3]
  allocate buf_B1_Bfirst_props_r2_r[float64 * 2 * 3]
  allocate buf_B1_Bfirst_props_r2_i[float64 * 2 * 3]
  allocate buf_B1_Bfirst_props_r1_r[float64 * 2 * 3]
  allocate buf_B1_Bfirst_props_r1_i[float64 * 2 * 3]
  allocate buf_B1_Bfirst_diquark_r2_r[float64 * 1]
  allocate buf_B1_Bfirst_diquark_r2_i[float64 * 1]
  allocate buf_B1_Bfirst_diquark_r1_r[float64 * 1]
  allocate buf_B1_Bfirst_diquark_r1_i[float64 * 1]
  for (c1, 0, 2) {
    for (c3, 0, 2) {
      for (c5, 0, 2) {
        for (c7, 0, 4) {
          for (c9, 0, 46) {
            for (c11, 0, 4) {
              for (c13, 0, 46) {
                buf_C_r[((((((c13 + int32((int64(c11)*(int64)46))) + int32((int64(c9)*(int64)184))) + int32((int64(c7)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = 0.000000
                buf_C_i[((((((c13 + int32((int64(c11)*(int64)46))) + int32((int64(c9)*(int64)184))) + int32((int64(c7)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = 0.000000
              }
            }
          }
        }
      }
    }
    for (c3, 0, 2) {
      for (c5, 0, 2) {
        for (c7, 0, 4) {
          for (c9, 0, 3) {
            for (c11, 0, 2) {
              for (c13, 0, 3) {
                for (c15, 0, 2) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_B1_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bfirst_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bfirst_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bsecond_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bsecond_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bthird_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bthird_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bfirst_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bfirst_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bsecond_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bsecond_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bthird_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bthird_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                      }
                    }
                  }
                }
              }
            }
          }
          for (c9, 0, 3) {
            for (c11, 0, 2) {
              for (c13, 0, 3) {
                for (c15, 0, 2) {
                  for (c17, 0, 4) {
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        buf_B1_Blocal_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Blocal_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bfirst_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bfirst_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bsecond_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bsecond_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bthird_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bthird_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                      }
                    }
// ------
                    for (c19, 0, 12) {
                      let t446 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t445 = _src_color_weights_b24[((c19*3) + 2)]
                      let t444 = _src_spin_weights_b25[(c19*3)]
                      let t443 = _src_color_weights_b24[(c19*3)]
                      let t442 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t441 = _src_color_weights_b24[((c19*3) + 2)]
                      let t440 = _src_spin_weights_b25[(c19*3)]
                      let t439 = _src_color_weights_b24[(c19*3)]
                      buf_B1_Blocal_diquark_r1_r[0] = (let t96 = (c17 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t96 + (t440*16)) + (t439*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t96 + (t442*16)) + (t441*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t96 + (t444*16)) + (t443*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t96 + (t446*16)) + (t445*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19]))
                      let t465 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t464 = _src_color_weights_b24[((c19*3) + 2)]
                      let t463 = _src_spin_weights_b25[(c19*3)]
                      let t462 = _src_color_weights_b24[(c19*3)]
                      let t461 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t460 = _src_color_weights_b24[((c19*3) + 2)]
                      let t459 = _src_spin_weights_b25[(c19*3)]
                      let t458 = _src_color_weights_b24[(c19*3)]
                      buf_B1_Blocal_diquark_r1_i[0] = (let t97 = (c17 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t97 + (t459*16)) + (t458*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t97 + (t461*16)) + (t460*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t97 + (t463*16)) + (t462*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t97 + (t465*16)) + (t464*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19]))
                      let t484 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t483 = _src_color_weights_b24[((c19*3) + 2)]
                      let t482 = _src_spin_weights_b25[(c19*3)]
                      let t481 = _src_color_weights_b24[(c19*3)]
                      let t480 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t479 = _src_color_weights_b24[((c19*3) + 2)]
                      let t478 = _src_spin_weights_b25[(c19*3)]
                      let t477 = _src_color_weights_b24[(c19*3)]
                      buf_B1_Bfirst_diquark_r1_r[0] = (let t98 = (c17 + (c7*4)) in (let t99 = (c17 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t98 + (t478*16)) + (t477*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t99 + (t480*16)) + (t479*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t98 + (t482*16)) + (t481*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t99 + (t484*16)) + (t483*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19])))
                      let t503 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t502 = _src_color_weights_b24[((c19*3) + 2)]
                      let t501 = _src_spin_weights_b25[(c19*3)]
                      let t500 = _src_color_weights_b24[(c19*3)]
                      let t499 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t498 = _src_color_weights_b24[((c19*3) + 2)]
                      let t497 = _src_spin_weights_b25[(c19*3)]
                      let t496 = _src_color_weights_b24[(c19*3)]
                      buf_B1_Bfirst_diquark_r1_i[0] = (let t100 = (c17 + (c7*4)) in (let t101 = (c17 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t100 + (t497*16)) + (t496*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t101 + (t499*16)) + (t498*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t100 + (t501*16)) + (t500*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t101 + (t503*16)) + (t502*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19])))
                      let t522 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t521 = _src_color_weights_b24[((c19*3) + 2)]
                      let t520 = _src_spin_weights_b25[(c19*3)]
                      let t519 = _src_color_weights_b24[(c19*3)]
                      let t518 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t517 = _src_color_weights_b24[((c19*3) + 2)]
                      let t516 = _src_spin_weights_b25[(c19*3)]
                      let t515 = _src_color_weights_b24[(c19*3)]
                      buf_B1_Bthird_diquark_r1_r[0] = (let t102 = (c17 + (((c3*2) + c5)*4)) in (let t103 = (c17 + (c7*4)) in (((_B1_prop_r_b2[(((((t102 + (t516*16)) + (t515*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t103 + (t518*16)) + (t517*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t102 + (t520*16)) + (t519*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t103 + (t522*16)) + (t521*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19])))
                      let t541 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t540 = _src_color_weights_b24[((c19*3) + 2)]
                      let t539 = _src_spin_weights_b25[(c19*3)]
                      let t538 = _src_color_weights_b24[(c19*3)]
                      let t537 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t536 = _src_color_weights_b24[((c19*3) + 2)]
                      let t535 = _src_spin_weights_b25[(c19*3)]
                      let t534 = _src_color_weights_b24[(c19*3)]
                      buf_B1_Bthird_diquark_r1_i[0] = (let t104 = (c17 + (((c3*2) + c5)*4)) in (let t105 = (c17 + (c7*4)) in (((_B1_prop_r_b2[(((((t104 + (t535*16)) + (t534*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t105 + (t537*16)) + (t536*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t104 + (t539*16)) + (t538*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t105 + (t541*16)) + (t540*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19])))
                      for (c21, 0, 3) {
                        for (c23, 0, 2) {
                          let t556 = _src_spin_weights_b25[((c19*3) + 1)]
                          let t555 = _src_color_weights_b24[((c19*3) + 1)]
                          let t554 = _src_spin_weights_b25[((c19*3) + 1)]
                          let t553 = _src_color_weights_b24[((c19*3) + 1)]
                          buf_B1_Blocal_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t106 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Blocal_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t106 + (t554*16)) + (t553*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r1_r[0]) - (_B1_prop_i_b3[((((((t106 + (t556*16)) + (t555*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r1_i[0]))))
                          let t23 = _src_spin_weights_b25[((c19*3) + 1)]
                          let t22 = _src_color_weights_b24[((c19*3) + 1)]
                          let t21 = _src_spin_weights_b25[((c19*3) + 1)]
                          let t20 = _src_color_weights_b24[((c19*3) + 1)]
                          buf_B1_Blocal_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t107 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Blocal_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t107 + (t21*16)) + (t20*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r1_i[0]) + (_B1_prop_i_b3[((((((t107 + (t23*16)) + (t22*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r1_r[0]))))
                          buf_B1_Bfirst_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t108 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Bfirst_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t108 + (t21*16)) + (t20*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bfirst_diquark_r1_r[0]) - (_B1_prop_i_b3[((((((t108 + (t23*16)) + (t22*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bfirst_diquark_r1_i[0]))))
                          buf_B1_Bfirst_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t109 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Bfirst_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t109 + (t21*16)) + (t20*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bfirst_diquark_r1_i[0]) + (_B1_prop_i_b3[((((((t109 + (t23*16)) + (t22*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bfirst_diquark_r1_r[0]))))
                          buf_B1_Bsecond_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t110 = (c17 + (c7*4)) in (buf_B1_Bsecond_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t110 + (t21*16)) + (t20*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r1_r[0]) - (_B1_prop_i_b3[((((((t110 + (t23*16)) + (t22*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r1_i[0]))))
                          buf_B1_Bsecond_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t111 = (c17 + (c7*4)) in (buf_B1_Bsecond_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t111 + (t21*16)) + (t20*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r1_i[0]) + (_B1_prop_i_b3[((((((t111 + (t23*16)) + (t22*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r1_r[0]))))
                          buf_B1_Bthird_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t112 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Bthird_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t112 + (t21*16)) + (t20*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bthird_diquark_r1_r[0]) - (_B1_prop_i_b3[((((((t112 + (t23*16)) + (t22*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bthird_diquark_r1_i[0]))))
                          buf_B1_Bthird_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t113 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Bthird_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t113 + (t21*16)) + (t20*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bthird_diquark_r1_i[0]) + (_B1_prop_i_b3[((((((t113 + (t23*16)) + (t22*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bthird_diquark_r1_r[0]))))
                        }
                      }
                    }
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        for (c23, 0, 44) {
                          buf_B1_Blocal_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t114 = (c23 + (c17*44)) in (let t115 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Blocal_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t114]*buf_B1_Blocal_props_r1_r[t115]) - (_src_psi_B1_i_b7[t114]*buf_B1_Blocal_props_r1_i[t115])))))
                          buf_B1_Blocal_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t116 = (c23 + (c17*44)) in (let t117 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Blocal_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t116]*buf_B1_Blocal_props_r1_i[t117]) + (_src_psi_B1_i_b7[t116]*buf_B1_Blocal_props_r1_r[t117])))))
                          buf_B1_Bfirst_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t118 = (c23 + (c17*44)) in (let t119 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bfirst_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t118]*buf_B1_Bfirst_props_r1_r[t119]) - (_src_psi_B1_i_b7[t118]*buf_B1_Bfirst_props_r1_i[t119])))))
                          buf_B1_Bfirst_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t120 = (c23 + (c17*44)) in (let t121 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bfirst_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t120]*buf_B1_Bfirst_props_r1_i[t121]) + (_src_psi_B1_i_b7[t120]*buf_B1_Bfirst_props_r1_r[t121])))))
                          buf_B1_Bsecond_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t122 = (c23 + (c17*44)) in (let t123 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bsecond_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t122]*buf_B1_Bsecond_props_r1_r[t123]) - (_src_psi_B1_i_b7[t122]*buf_B1_Bsecond_props_r1_i[t123])))))
                          buf_B1_Bsecond_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t124 = (c23 + (c17*44)) in (let t125 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bsecond_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t124]*buf_B1_Bsecond_props_r1_i[t125]) + (_src_psi_B1_i_b7[t124]*buf_B1_Bsecond_props_r1_r[t125])))))
                          buf_B1_Bthird_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t126 = (c23 + (c17*44)) in (let t127 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bthird_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t126]*buf_B1_Bthird_props_r1_r[t127]) - (_src_psi_B1_i_b7[t126]*buf_B1_Bthird_props_r1_i[t127])))))
                          buf_B1_Bthird_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t128 = (c23 + (c17*44)) in (let t129 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bthird_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t128]*buf_B1_Bthird_props_r1_i[t129]) + (_src_psi_B1_i_b7[t128]*buf_B1_Bthird_props_r1_r[t129])))))
                          buf_flip_B1_Blocal_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t130 = (c23 + (c17*44)) in (let t131 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Blocal_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t130]*buf_B1_Blocal_props_r1_r[t131]) - (_src_psi_B2_i_b9[t130]*buf_B1_Blocal_props_r1_i[t131])))))
                          buf_flip_B1_Blocal_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t132 = (c23 + (c17*44)) in (let t133 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Blocal_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t132]*buf_B1_Blocal_props_r1_i[t133]) + (_src_psi_B2_i_b9[t132]*buf_B1_Blocal_props_r1_r[t133])))))
                          buf_flip_B1_Bfirst_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t134 = (c23 + (c17*44)) in (let t135 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bfirst_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t134]*buf_B1_Bfirst_props_r1_r[t135]) - (_src_psi_B2_i_b9[t134]*buf_B1_Bfirst_props_r1_i[t135])))))
                          buf_flip_B1_Bfirst_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t136 = (c23 + (c17*44)) in (let t137 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bfirst_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t136]*buf_B1_Bfirst_props_r1_i[t137]) + (_src_psi_B2_i_b9[t136]*buf_B1_Bfirst_props_r1_r[t137])))))
                          buf_flip_B1_Bsecond_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t138 = (c23 + (c17*44)) in (let t139 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bsecond_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t138]*buf_B1_Bsecond_props_r1_r[t139]) - (_src_psi_B2_i_b9[t138]*buf_B1_Bsecond_props_r1_i[t139])))))
                          buf_flip_B1_Bsecond_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t140 = (c23 + (c17*44)) in (let t141 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bsecond_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t140]*buf_B1_Bsecond_props_r1_i[t141]) + (_src_psi_B2_i_b9[t140]*buf_B1_Bsecond_props_r1_r[t141])))))
                          buf_flip_B1_Bthird_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t142 = (c23 + (c17*44)) in (let t143 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bthird_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t142]*buf_B1_Bthird_props_r1_r[t143]) - (_src_psi_B2_i_b9[t142]*buf_B1_Bthird_props_r1_i[t143])))))
                          buf_flip_B1_Bthird_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t144 = (c23 + (c17*44)) in (let t145 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bthird_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t144]*buf_B1_Bthird_props_r1_i[t145]) + (_src_psi_B2_i_b9[t144]*buf_B1_Bthird_props_r1_r[t145])))))
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          for (c9, 0, 3) {
            for (c11, 0, 2) {
              for (c13, 0, 3) {
                for (c15, 0, 2) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_B1_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bfirst_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bfirst_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bsecond_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bsecond_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bthird_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B1_Bthird_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bfirst_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bfirst_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bsecond_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bsecond_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bthird_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B1_Bthird_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                      }
                    }
                  }
                }
              }
            }
          }
          for (c9, 0, 3) {
            for (c11, 0, 2) {
              for (c13, 0, 3) {
                for (c15, 0, 2) {
                  for (c17, 0, 4) {
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        buf_B1_Blocal_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Blocal_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bfirst_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bfirst_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bsecond_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bsecond_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bthird_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B1_Bthird_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                      }
                    }
                    for (c19, 0, 12) {
                      let t1192 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1191 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1190 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1189 = _src_color_weights_b24[((c19*3) + 36)]
                      let t1188 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1187 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1186 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1185 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B1_Blocal_diquark_r2_r[0] = (let t146 = (c17 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t146 + (t1186*16)) + (t1185*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t146 + (t1188*16)) + (t1187*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t146 + (t1190*16)) + (t1189*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t146 + (t1192*16)) + (t1191*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)]))
                      let t1211 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1210 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1209 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1208 = _src_color_weights_b24[((c19*3) + 36)]
                      let t1207 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1206 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1205 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1204 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B1_Blocal_diquark_r2_i[0] = (let t147 = (c17 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t147 + (t1205*16)) + (t1204*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t147 + (t1207*16)) + (t1206*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t147 + (t1209*16)) + (t1208*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t147 + (t1211*16)) + (t1210*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)]))
                      let t1230 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1229 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1228 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1227 = _src_color_weights_b24[((c19*3) + 36)]
                      let t1226 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1225 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1224 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1223 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B1_Bfirst_diquark_r2_r[0] = (let t148 = (c17 + (c7*4)) in (let t149 = (c17 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t148 + (t1224*16)) + (t1223*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t149 + (t1226*16)) + (t1225*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t148 + (t1228*16)) + (t1227*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t149 + (t1230*16)) + (t1229*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)])))
                      let t1249 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1248 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1247 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1246 = _src_color_weights_b24[((c19*3) + 36)]
                      let t1245 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1244 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1243 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1242 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B1_Bfirst_diquark_r2_i[0] = (let t150 = (c17 + (c7*4)) in (let t151 = (c17 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t150 + (t1243*16)) + (t1242*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t151 + (t1245*16)) + (t1244*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t150 + (t1247*16)) + (t1246*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t151 + (t1249*16)) + (t1248*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)])))
                      let t1268 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1267 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1266 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1265 = _src_color_weights_b24[((c19*3) + 36)]
                      let t1264 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1263 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1262 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1261 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B1_Bthird_diquark_r2_r[0] = (let t152 = (c17 + (((c3*2) + c5)*4)) in (let t153 = (c17 + (c7*4)) in (((_B1_prop_r_b2[(((((t152 + (t1262*16)) + (t1261*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t153 + (t1264*16)) + (t1263*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t152 + (t1266*16)) + (t1265*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t153 + (t1268*16)) + (t1267*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)])))
                      let t1287 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1286 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1285 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1284 = _src_color_weights_b24[((c19*3) + 36)]
                      let t1283 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t1282 = _src_color_weights_b24[((c19*3) + 38)]
                      let t1281 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t1280 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B1_Bthird_diquark_r2_i[0] = (let t154 = (c17 + (((c3*2) + c5)*4)) in (let t155 = (c17 + (c7*4)) in (((_B1_prop_r_b2[(((((t154 + (t1281*16)) + (t1280*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_i_b3[((((((t155 + (t1283*16)) + (t1282*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t154 + (t1285*16)) + (t1284*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B1_prop_r_b2[((((((t155 + (t1287*16)) + (t1286*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)])))
                      for (c21, 0, 3) {
                        for (c23, 0, 2) {
                          let t1302 = _src_spin_weights_b25[((c19*3) + 37)]
                          let t1301 = _src_color_weights_b24[((c19*3) + 37)]
                          let t1300 = _src_spin_weights_b25[((c19*3) + 37)]
                          let t1299 = _src_color_weights_b24[((c19*3) + 37)]
                          buf_B1_Blocal_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t156 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Blocal_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t156 + (t1300*16)) + (t1299*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r2_r[0]) - (_B1_prop_i_b3[((((((t156 + (t1302*16)) + (t1301*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r2_i[0]))))
                          let t47 = _src_spin_weights_b25[((c19*3) + 37)]
                          let t46 = _src_color_weights_b24[((c19*3) + 37)]
                          let t45 = _src_spin_weights_b25[((c19*3) + 37)]
                          let t44 = _src_color_weights_b24[((c19*3) + 37)]
                          buf_B1_Blocal_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t157 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Blocal_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t157 + (t45*16)) + (t44*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r2_i[0]) + (_B1_prop_i_b3[((((((t157 + (t47*16)) + (t46*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r2_r[0]))))
                          buf_B1_Bfirst_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t158 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Bfirst_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t158 + (t45*16)) + (t44*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bfirst_diquark_r2_r[0]) - (_B1_prop_i_b3[((((((t158 + (t47*16)) + (t46*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bfirst_diquark_r2_i[0]))))
                          buf_B1_Bfirst_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t159 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Bfirst_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t159 + (t45*16)) + (t44*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bfirst_diquark_r2_i[0]) + (_B1_prop_i_b3[((((((t159 + (t47*16)) + (t46*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bfirst_diquark_r2_r[0]))))
                          buf_B1_Bsecond_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t160 = (c17 + (c7*4)) in (buf_B1_Bsecond_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t160 + (t45*16)) + (t44*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r2_r[0]) - (_B1_prop_i_b3[((((((t160 + (t47*16)) + (t46*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r2_i[0]))))
                          buf_B1_Bsecond_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t161 = (c17 + (c7*4)) in (buf_B1_Bsecond_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t161 + (t45*16)) + (t44*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r2_i[0]) + (_B1_prop_i_b3[((((((t161 + (t47*16)) + (t46*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Blocal_diquark_r2_r[0]))))
                          buf_B1_Bthird_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t162 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Bthird_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t162 + (t45*16)) + (t44*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bthird_diquark_r2_r[0]) - (_B1_prop_i_b3[((((((t162 + (t47*16)) + (t46*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bthird_diquark_r2_i[0]))))
                          buf_B1_Bthird_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t163 = (c17 + (((c3*2) + c5)*4)) in (buf_B1_Bthird_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B1_prop_r_b2[((((((t163 + (t45*16)) + (t44*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bthird_diquark_r2_i[0]) + (_B1_prop_i_b3[((((((t163 + (t47*16)) + (t46*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B1_Bthird_diquark_r2_r[0]))))
                        }
                      }
                    }
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        for (c23, 0, 44) {
                          buf_B1_Blocal_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t164 = (c23 + (c17*44)) in (let t165 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Blocal_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t164]*buf_B1_Blocal_props_r2_r[t165]) - (_src_psi_B1_i_b7[t164]*buf_B1_Blocal_props_r2_i[t165])))))
                          buf_B1_Blocal_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t166 = (c23 + (c17*44)) in (let t167 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Blocal_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t166]*buf_B1_Blocal_props_r2_i[t167]) + (_src_psi_B1_i_b7[t166]*buf_B1_Blocal_props_r2_r[t167])))))
                          buf_B1_Bfirst_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t168 = (c23 + (c17*44)) in (let t169 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bfirst_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t168]*buf_B1_Bfirst_props_r2_r[t169]) - (_src_psi_B1_i_b7[t168]*buf_B1_Bfirst_props_r2_i[t169])))))
                          buf_B1_Bfirst_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t170 = (c23 + (c17*44)) in (let t171 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bfirst_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t170]*buf_B1_Bfirst_props_r2_i[t171]) + (_src_psi_B1_i_b7[t170]*buf_B1_Bfirst_props_r2_r[t171])))))
                          buf_B1_Bsecond_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t172 = (c23 + (c17*44)) in (let t173 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bsecond_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t172]*buf_B1_Bsecond_props_r2_r[t173]) - (_src_psi_B1_i_b7[t172]*buf_B1_Bsecond_props_r2_i[t173])))))
                          buf_B1_Bsecond_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t174 = (c23 + (c17*44)) in (let t175 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bsecond_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t174]*buf_B1_Bsecond_props_r2_i[t175]) + (_src_psi_B1_i_b7[t174]*buf_B1_Bsecond_props_r2_r[t175])))))
                          buf_B1_Bthird_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t176 = (c23 + (c17*44)) in (let t177 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bthird_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t176]*buf_B1_Bthird_props_r2_r[t177]) - (_src_psi_B1_i_b7[t176]*buf_B1_Bthird_props_r2_i[t177])))))
                          buf_B1_Bthird_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t178 = (c23 + (c17*44)) in (let t179 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B1_Bthird_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t178]*buf_B1_Bthird_props_r2_i[t179]) + (_src_psi_B1_i_b7[t178]*buf_B1_Bthird_props_r2_r[t179])))))
                          buf_flip_B1_Blocal_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t180 = (c23 + (c17*44)) in (let t181 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Blocal_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t180]*buf_B1_Blocal_props_r2_r[t181]) - (_src_psi_B2_i_b9[t180]*buf_B1_Blocal_props_r2_i[t181])))))
                          buf_flip_B1_Blocal_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t182 = (c23 + (c17*44)) in (let t183 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Blocal_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t182]*buf_B1_Blocal_props_r2_i[t183]) + (_src_psi_B2_i_b9[t182]*buf_B1_Blocal_props_r2_r[t183])))))
                          buf_flip_B1_Bfirst_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t184 = (c23 + (c17*44)) in (let t185 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bfirst_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t184]*buf_B1_Bfirst_props_r2_r[t185]) - (_src_psi_B2_i_b9[t184]*buf_B1_Bfirst_props_r2_i[t185])))))
                          buf_flip_B1_Bfirst_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t186 = (c23 + (c17*44)) in (let t187 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bfirst_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t186]*buf_B1_Bfirst_props_r2_i[t187]) + (_src_psi_B2_i_b9[t186]*buf_B1_Bfirst_props_r2_r[t187])))))
                          buf_flip_B1_Bsecond_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t188 = (c23 + (c17*44)) in (let t189 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bsecond_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t188]*buf_B1_Bsecond_props_r2_r[t189]) - (_src_psi_B2_i_b9[t188]*buf_B1_Bsecond_props_r2_i[t189])))))
                          buf_flip_B1_Bsecond_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t190 = (c23 + (c17*44)) in (let t191 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bsecond_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t190]*buf_B1_Bsecond_props_r2_i[t191]) + (_src_psi_B2_i_b9[t190]*buf_B1_Bsecond_props_r2_r[t191])))))
                          buf_flip_B1_Bthird_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t192 = (c23 + (c17*44)) in (let t193 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bthird_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t192]*buf_B1_Bthird_props_r2_r[t193]) - (_src_psi_B2_i_b9[t192]*buf_B1_Bthird_props_r2_i[t193])))))
                          buf_flip_B1_Bthird_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t194 = (c23 + (c17*44)) in (let t195 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B1_Bthird_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t194]*buf_B1_Bthird_props_r2_i[t195]) + (_src_psi_B2_i_b9[t194]*buf_B1_Bthird_props_r2_r[t195])))))
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          for (c9, 0, 3) {
            for (c11, 0, 2) {
              for (c13, 0, 3) {
                for (c15, 0, 2) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_B2_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bfirst_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bfirst_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bsecond_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bsecond_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bthird_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bthird_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bfirst_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bfirst_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bsecond_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bsecond_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bthird_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bthird_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                      }
                    }
                  }
                }
              }
            }
          }
          for (c9, 0, 3) {
            for (c11, 0, 2) {
              for (c13, 0, 3) {
                for (c15, 0, 2) {
                  for (c17, 0, 4) {
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        buf_B2_Blocal_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Blocal_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bfirst_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bfirst_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bsecond_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bsecond_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bthird_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bthird_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                      }
                    }
                    for (c19, 0, 12) {
                      let t1938 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t1937 = _src_color_weights_b24[((c19*3) + 2)]
                      let t1936 = _src_spin_weights_b25[(c19*3)]
                      let t1935 = _src_color_weights_b24[(c19*3)]
                      let t1934 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t1933 = _src_color_weights_b24[((c19*3) + 2)]
                      let t1932 = _src_spin_weights_b25[(c19*3)]
                      let t1931 = _src_color_weights_b24[(c19*3)]
                      buf_B2_Blocal_diquark_r1_r[0] = (let t196 = (c17 + (c7*4)) in (((_B2_prop_r_b4[(((((t196 + (t1932*16)) + (t1931*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t196 + (t1934*16)) + (t1933*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t196 + (t1936*16)) + (t1935*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t196 + (t1938*16)) + (t1937*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19]))
                      let t1957 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t1956 = _src_color_weights_b24[((c19*3) + 2)]
                      let t1955 = _src_spin_weights_b25[(c19*3)]
                      let t1954 = _src_color_weights_b24[(c19*3)]
                      let t1953 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t1952 = _src_color_weights_b24[((c19*3) + 2)]
                      let t1951 = _src_spin_weights_b25[(c19*3)]
                      let t1950 = _src_color_weights_b24[(c19*3)]
                      buf_B2_Blocal_diquark_r1_i[0] = (let t197 = (c17 + (c7*4)) in (((_B2_prop_r_b4[(((((t197 + (t1951*16)) + (t1950*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t197 + (t1953*16)) + (t1952*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t197 + (t1955*16)) + (t1954*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t197 + (t1957*16)) + (t1956*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19]))
                      let t1976 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t1975 = _src_color_weights_b24[((c19*3) + 2)]
                      let t1974 = _src_spin_weights_b25[(c19*3)]
                      let t1973 = _src_color_weights_b24[(c19*3)]
                      let t1972 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t1971 = _src_color_weights_b24[((c19*3) + 2)]
                      let t1970 = _src_spin_weights_b25[(c19*3)]
                      let t1969 = _src_color_weights_b24[(c19*3)]
                      buf_B2_Bfirst_diquark_r1_r[0] = (let t198 = (c17 + (((c3*2) + c5)*4)) in (let t199 = (c17 + (c7*4)) in (((_B2_prop_r_b4[(((((t198 + (t1970*16)) + (t1969*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t199 + (t1972*16)) + (t1971*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t198 + (t1974*16)) + (t1973*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t199 + (t1976*16)) + (t1975*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19])))
                      let t1995 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t1994 = _src_color_weights_b24[((c19*3) + 2)]
                      let t1993 = _src_spin_weights_b25[(c19*3)]
                      let t1992 = _src_color_weights_b24[(c19*3)]
                      let t1991 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t1990 = _src_color_weights_b24[((c19*3) + 2)]
                      let t1989 = _src_spin_weights_b25[(c19*3)]
                      let t1988 = _src_color_weights_b24[(c19*3)]
                      buf_B2_Bfirst_diquark_r1_i[0] = (let t200 = (c17 + (((c3*2) + c5)*4)) in (let t201 = (c17 + (c7*4)) in (((_B2_prop_r_b4[(((((t200 + (t1989*16)) + (t1988*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t201 + (t1991*16)) + (t1990*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t200 + (t1993*16)) + (t1992*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t201 + (t1995*16)) + (t1994*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19])))
                      let t2014 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t2013 = _src_color_weights_b24[((c19*3) + 2)]
                      let t2012 = _src_spin_weights_b25[(c19*3)]
                      let t2011 = _src_color_weights_b24[(c19*3)]
                      let t2010 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t2009 = _src_color_weights_b24[((c19*3) + 2)]
                      let t2008 = _src_spin_weights_b25[(c19*3)]
                      let t2007 = _src_color_weights_b24[(c19*3)]
                      buf_B2_Bthird_diquark_r1_r[0] = (let t202 = (c17 + (c7*4)) in (let t203 = (c17 + (((c3*2) + c5)*4)) in (((_B2_prop_r_b4[(((((t202 + (t2008*16)) + (t2007*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t203 + (t2010*16)) + (t2009*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t202 + (t2012*16)) + (t2011*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t203 + (t2014*16)) + (t2013*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19])))
                      let t2033 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t2032 = _src_color_weights_b24[((c19*3) + 2)]
                      let t2031 = _src_spin_weights_b25[(c19*3)]
                      let t2030 = _src_color_weights_b24[(c19*3)]
                      let t2029 = _src_spin_weights_b25[((c19*3) + 2)]
                      let t2028 = _src_color_weights_b24[((c19*3) + 2)]
                      let t2027 = _src_spin_weights_b25[(c19*3)]
                      let t2026 = _src_color_weights_b24[(c19*3)]
                      buf_B2_Bthird_diquark_r1_i[0] = (let t204 = (c17 + (c7*4)) in (let t205 = (c17 + (((c3*2) + c5)*4)) in (((_B2_prop_r_b4[(((((t204 + (t2027*16)) + (t2026*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t205 + (t2029*16)) + (t2028*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t204 + (t2031*16)) + (t2030*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t205 + (t2033*16)) + (t2032*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c19])))
                      for (c21, 0, 3) {
                        for (c23, 0, 2) {
                          let t2048 = _src_spin_weights_b25[((c19*3) + 1)]
                          let t2047 = _src_color_weights_b24[((c19*3) + 1)]
                          let t2046 = _src_spin_weights_b25[((c19*3) + 1)]
                          let t2045 = _src_color_weights_b24[((c19*3) + 1)]
                          buf_B2_Blocal_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t206 = (c17 + (c7*4)) in (buf_B2_Blocal_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t206 + (t2046*16)) + (t2045*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r1_r[0]) - (_B2_prop_i_b5[((((((t206 + (t2048*16)) + (t2047*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r1_i[0]))))
                          let t71 = _src_spin_weights_b25[((c19*3) + 1)]
                          let t70 = _src_color_weights_b24[((c19*3) + 1)]
                          let t69 = _src_spin_weights_b25[((c19*3) + 1)]
                          let t68 = _src_color_weights_b24[((c19*3) + 1)]
                          buf_B2_Blocal_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t207 = (c17 + (c7*4)) in (buf_B2_Blocal_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t207 + (t69*16)) + (t68*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r1_i[0]) + (_B2_prop_i_b5[((((((t207 + (t71*16)) + (t70*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r1_r[0]))))
                          buf_B2_Bfirst_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t208 = (c17 + (c7*4)) in (buf_B2_Bfirst_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t208 + (t69*16)) + (t68*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bfirst_diquark_r1_r[0]) - (_B2_prop_i_b5[((((((t208 + (t71*16)) + (t70*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bfirst_diquark_r1_i[0]))))
                          buf_B2_Bfirst_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t209 = (c17 + (c7*4)) in (buf_B2_Bfirst_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t209 + (t69*16)) + (t68*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bfirst_diquark_r1_i[0]) + (_B2_prop_i_b5[((((((t209 + (t71*16)) + (t70*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bfirst_diquark_r1_r[0]))))
                          buf_B2_Bsecond_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t210 = (c17 + (((c3*2) + c5)*4)) in (buf_B2_Bsecond_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t210 + (t69*16)) + (t68*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r1_r[0]) - (_B2_prop_i_b5[((((((t210 + (t71*16)) + (t70*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r1_i[0]))))
                          buf_B2_Bsecond_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t211 = (c17 + (((c3*2) + c5)*4)) in (buf_B2_Bsecond_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t211 + (t69*16)) + (t68*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r1_i[0]) + (_B2_prop_i_b5[((((((t211 + (t71*16)) + (t70*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r1_r[0]))))
                          buf_B2_Bthird_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t212 = (c17 + (c7*4)) in (buf_B2_Bthird_props_r1_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t212 + (t69*16)) + (t68*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bthird_diquark_r1_r[0]) - (_B2_prop_i_b5[((((((t212 + (t71*16)) + (t70*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bthird_diquark_r1_i[0]))))
                          buf_B2_Bthird_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t213 = (c17 + (c7*4)) in (buf_B2_Bthird_props_r1_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t213 + (t69*16)) + (t68*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bthird_diquark_r1_i[0]) + (_B2_prop_i_b5[((((((t213 + (t71*16)) + (t70*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bthird_diquark_r1_r[0]))))
                        }
                      }
                    }
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        for (c23, 0, 44) {
                          buf_B2_Blocal_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t214 = (c23 + (c17*44)) in (let t215 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Blocal_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t214]*buf_B2_Blocal_props_r1_r[t215]) - (_src_psi_B2_i_b9[t214]*buf_B2_Blocal_props_r1_i[t215])))))
                          buf_B2_Blocal_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t216 = (c23 + (c17*44)) in (let t217 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Blocal_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t216]*buf_B2_Blocal_props_r1_i[t217]) + (_src_psi_B2_i_b9[t216]*buf_B2_Blocal_props_r1_r[t217])))))
                          buf_B2_Bfirst_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t218 = (c23 + (c17*44)) in (let t219 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bfirst_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t218]*buf_B2_Bfirst_props_r1_r[t219]) - (_src_psi_B2_i_b9[t218]*buf_B2_Bfirst_props_r1_i[t219])))))
                          buf_B2_Bfirst_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t220 = (c23 + (c17*44)) in (let t221 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bfirst_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t220]*buf_B2_Bfirst_props_r1_i[t221]) + (_src_psi_B2_i_b9[t220]*buf_B2_Bfirst_props_r1_r[t221])))))
                          buf_B2_Bsecond_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t222 = (c23 + (c17*44)) in (let t223 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bsecond_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t222]*buf_B2_Bsecond_props_r1_r[t223]) - (_src_psi_B2_i_b9[t222]*buf_B2_Bsecond_props_r1_i[t223])))))
                          buf_B2_Bsecond_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t224 = (c23 + (c17*44)) in (let t225 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bsecond_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t224]*buf_B2_Bsecond_props_r1_i[t225]) + (_src_psi_B2_i_b9[t224]*buf_B2_Bsecond_props_r1_r[t225])))))
                          buf_B2_Bthird_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t226 = (c23 + (c17*44)) in (let t227 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bthird_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t226]*buf_B2_Bthird_props_r1_r[t227]) - (_src_psi_B2_i_b9[t226]*buf_B2_Bthird_props_r1_i[t227])))))
                          buf_B2_Bthird_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t228 = (c23 + (c17*44)) in (let t229 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bthird_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t228]*buf_B2_Bthird_props_r1_i[t229]) + (_src_psi_B2_i_b9[t228]*buf_B2_Bthird_props_r1_r[t229])))))
                          buf_flip_B2_Blocal_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t230 = (c23 + (c17*44)) in (let t231 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Blocal_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t230]*buf_B2_Blocal_props_r1_r[t231]) - (_src_psi_B1_i_b7[t230]*buf_B2_Blocal_props_r1_i[t231])))))
                          buf_flip_B2_Blocal_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t232 = (c23 + (c17*44)) in (let t233 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Blocal_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t232]*buf_B2_Blocal_props_r1_i[t233]) + (_src_psi_B1_i_b7[t232]*buf_B2_Blocal_props_r1_r[t233])))))
                          buf_flip_B2_Bfirst_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t234 = (c23 + (c17*44)) in (let t235 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bfirst_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t234]*buf_B2_Bfirst_props_r1_r[t235]) - (_src_psi_B1_i_b7[t234]*buf_B2_Bfirst_props_r1_i[t235])))))
                          buf_flip_B2_Bfirst_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t236 = (c23 + (c17*44)) in (let t237 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bfirst_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t236]*buf_B2_Bfirst_props_r1_i[t237]) + (_src_psi_B1_i_b7[t236]*buf_B2_Bfirst_props_r1_r[t237])))))
                          buf_flip_B2_Bsecond_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t238 = (c23 + (c17*44)) in (let t239 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bsecond_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t238]*buf_B2_Bsecond_props_r1_r[t239]) - (_src_psi_B1_i_b7[t238]*buf_B2_Bsecond_props_r1_i[t239])))))
                          buf_flip_B2_Bsecond_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t240 = (c23 + (c17*44)) in (let t241 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bsecond_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t240]*buf_B2_Bsecond_props_r1_i[t241]) + (_src_psi_B1_i_b7[t240]*buf_B2_Bsecond_props_r1_r[t241])))))
                          buf_flip_B2_Bthird_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t242 = (c23 + (c17*44)) in (let t243 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bthird_r1_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t242]*buf_B2_Bthird_props_r1_r[t243]) - (_src_psi_B1_i_b7[t242]*buf_B2_Bthird_props_r1_i[t243])))))
                          buf_flip_B2_Bthird_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t244 = (c23 + (c17*44)) in (let t245 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bthird_r1_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t244]*buf_B2_Bthird_props_r1_i[t245]) + (_src_psi_B1_i_b7[t244]*buf_B2_Bthird_props_r1_r[t245])))))
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          for (c9, 0, 3) {
            for (c11, 0, 2) {
              for (c13, 0, 3) {
                for (c15, 0, 2) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_B2_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bfirst_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bfirst_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bsecond_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bsecond_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bthird_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_B2_Bthird_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bfirst_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bfirst_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bsecond_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bsecond_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bthird_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                        buf_flip_B2_Bthird_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = 0.000000
                      }
                    }
                  }
                }
              }
            }
          }
          for (c9, 0, 3) {
            for (c11, 0, 2) {
              for (c13, 0, 3) {
                for (c15, 0, 2) {
                  for (c17, 0, 4) {
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        buf_B2_Blocal_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Blocal_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bfirst_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bfirst_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bsecond_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bsecond_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bthird_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                        buf_B2_Bthird_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = 0.000000
                      }
                    }
                    for (c19, 0, 12) {
                      let t2684 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2683 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2682 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2681 = _src_color_weights_b24[((c19*3) + 36)]
                      let t2680 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2679 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2678 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2677 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B2_Blocal_diquark_r2_r[0] = (let t246 = (c17 + (c7*4)) in (((_B2_prop_r_b4[(((((t246 + (t2678*16)) + (t2677*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t246 + (t2680*16)) + (t2679*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t246 + (t2682*16)) + (t2681*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t246 + (t2684*16)) + (t2683*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)]))
                      let t2703 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2702 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2701 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2700 = _src_color_weights_b24[((c19*3) + 36)]
                      let t2699 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2698 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2697 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2696 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B2_Blocal_diquark_r2_i[0] = (let t247 = (c17 + (c7*4)) in (((_B2_prop_r_b4[(((((t247 + (t2697*16)) + (t2696*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t247 + (t2699*16)) + (t2698*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t247 + (t2701*16)) + (t2700*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t247 + (t2703*16)) + (t2702*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)]))
                      let t2722 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2721 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2720 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2719 = _src_color_weights_b24[((c19*3) + 36)]
                      let t2718 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2717 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2716 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2715 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B2_Bfirst_diquark_r2_r[0] = (let t248 = (c17 + (((c3*2) + c5)*4)) in (let t249 = (c17 + (c7*4)) in (((_B2_prop_r_b4[(((((t248 + (t2716*16)) + (t2715*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t249 + (t2718*16)) + (t2717*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t248 + (t2720*16)) + (t2719*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t249 + (t2722*16)) + (t2721*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)])))
                      let t2741 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2740 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2739 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2738 = _src_color_weights_b24[((c19*3) + 36)]
                      let t2737 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2736 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2735 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2734 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B2_Bfirst_diquark_r2_i[0] = (let t250 = (c17 + (((c3*2) + c5)*4)) in (let t251 = (c17 + (c7*4)) in (((_B2_prop_r_b4[(((((t250 + (t2735*16)) + (t2734*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t251 + (t2737*16)) + (t2736*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t250 + (t2739*16)) + (t2738*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t251 + (t2741*16)) + (t2740*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)])))
                      let t2760 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2759 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2758 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2757 = _src_color_weights_b24[((c19*3) + 36)]
                      let t2756 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2755 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2754 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2753 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B2_Bthird_diquark_r2_r[0] = (let t252 = (c17 + (c7*4)) in (let t253 = (c17 + (((c3*2) + c5)*4)) in (((_B2_prop_r_b4[(((((t252 + (t2754*16)) + (t2753*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t253 + (t2756*16)) + (t2755*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t252 + (t2758*16)) + (t2757*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t253 + (t2760*16)) + (t2759*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)])))
                      let t2779 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2778 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2777 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2776 = _src_color_weights_b24[((c19*3) + 36)]
                      let t2775 = _src_spin_weights_b25[((c19*3) + 38)]
                      let t2774 = _src_color_weights_b24[((c19*3) + 38)]
                      let t2773 = _src_spin_weights_b25[((c19*3) + 36)]
                      let t2772 = _src_color_weights_b24[((c19*3) + 36)]
                      buf_B2_Bthird_diquark_r2_i[0] = (let t254 = (c17 + (c7*4)) in (let t255 = (c17 + (((c3*2) + c5)*4)) in (((_B2_prop_r_b4[(((((t254 + (t2773*16)) + (t2772*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_i_b5[((((((t255 + (t2775*16)) + (t2774*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t254 + (t2777*16)) + (t2776*32)) + (c11*96)) + (c9*192)) + (c1*576))]*_B2_prop_r_b4[((((((t255 + (t2779*16)) + (t2778*32)) + (c15*96)) + (c13*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c19 + 12)])))
                      for (c21, 0, 3) {
                        for (c23, 0, 2) {
                          let t2794 = _src_spin_weights_b25[((c19*3) + 37)]
                          let t2793 = _src_color_weights_b24[((c19*3) + 37)]
                          let t2792 = _src_spin_weights_b25[((c19*3) + 37)]
                          let t2791 = _src_color_weights_b24[((c19*3) + 37)]
                          buf_B2_Blocal_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t256 = (c17 + (c7*4)) in (buf_B2_Blocal_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t256 + (t2792*16)) + (t2791*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r2_r[0]) - (_B2_prop_i_b5[((((((t256 + (t2794*16)) + (t2793*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r2_i[0]))))
                          let t95 = _src_spin_weights_b25[((c19*3) + 37)]
                          let t94 = _src_color_weights_b24[((c19*3) + 37)]
                          let t93 = _src_spin_weights_b25[((c19*3) + 37)]
                          let t92 = _src_color_weights_b24[((c19*3) + 37)]
                          buf_B2_Blocal_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t257 = (c17 + (c7*4)) in (buf_B2_Blocal_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t257 + (t93*16)) + (t92*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r2_i[0]) + (_B2_prop_i_b5[((((((t257 + (t95*16)) + (t94*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r2_r[0]))))
                          buf_B2_Bfirst_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t258 = (c17 + (c7*4)) in (buf_B2_Bfirst_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t258 + (t93*16)) + (t92*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bfirst_diquark_r2_r[0]) - (_B2_prop_i_b5[((((((t258 + (t95*16)) + (t94*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bfirst_diquark_r2_i[0]))))
                          buf_B2_Bfirst_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t259 = (c17 + (c7*4)) in (buf_B2_Bfirst_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t259 + (t93*16)) + (t92*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bfirst_diquark_r2_i[0]) + (_B2_prop_i_b5[((((((t259 + (t95*16)) + (t94*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bfirst_diquark_r2_r[0]))))
                          buf_B2_Bsecond_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t260 = (c17 + (((c3*2) + c5)*4)) in (buf_B2_Bsecond_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t260 + (t93*16)) + (t92*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r2_r[0]) - (_B2_prop_i_b5[((((((t260 + (t95*16)) + (t94*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r2_i[0]))))
                          buf_B2_Bsecond_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t261 = (c17 + (((c3*2) + c5)*4)) in (buf_B2_Bsecond_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t261 + (t93*16)) + (t92*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r2_i[0]) + (_B2_prop_i_b5[((((((t261 + (t95*16)) + (t94*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Blocal_diquark_r2_r[0]))))
                          buf_B2_Bthird_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] = (let t262 = (c17 + (c7*4)) in (buf_B2_Bthird_props_r2_r[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t262 + (t93*16)) + (t92*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bthird_diquark_r2_r[0]) - (_B2_prop_i_b5[((((((t262 + (t95*16)) + (t94*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bthird_diquark_r2_i[0]))))
                          buf_B2_Bthird_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] = (let t263 = (c17 + (c7*4)) in (buf_B2_Bthird_props_r2_i[(c23 + int32((int64(c21)*(int64)2)))] + ((_B2_prop_r_b4[((((((t263 + (t93*16)) + (t92*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bthird_diquark_r2_i[0]) + (_B2_prop_i_b5[((((((t263 + (t95*16)) + (t94*32)) + (c23*96)) + (c21*192)) + (c1*576)) + 1152)]*buf_B2_Bthird_diquark_r2_r[0]))))
                        }
                      }
                    }
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        for (c23, 0, 44) {
                          buf_B2_Blocal_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t264 = (c23 + (c17*44)) in (let t265 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Blocal_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t264]*buf_B2_Blocal_props_r2_r[t265]) - (_src_psi_B2_i_b9[t264]*buf_B2_Blocal_props_r2_i[t265])))))
                          buf_B2_Blocal_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t266 = (c23 + (c17*44)) in (let t267 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Blocal_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t266]*buf_B2_Blocal_props_r2_i[t267]) + (_src_psi_B2_i_b9[t266]*buf_B2_Blocal_props_r2_r[t267])))))
                          buf_B2_Bfirst_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t268 = (c23 + (c17*44)) in (let t269 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bfirst_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t268]*buf_B2_Bfirst_props_r2_r[t269]) - (_src_psi_B2_i_b9[t268]*buf_B2_Bfirst_props_r2_i[t269])))))
                          buf_B2_Bfirst_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t270 = (c23 + (c17*44)) in (let t271 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bfirst_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t270]*buf_B2_Bfirst_props_r2_i[t271]) + (_src_psi_B2_i_b9[t270]*buf_B2_Bfirst_props_r2_r[t271])))))
                          buf_B2_Bsecond_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t272 = (c23 + (c17*44)) in (let t273 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bsecond_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t272]*buf_B2_Bsecond_props_r2_r[t273]) - (_src_psi_B2_i_b9[t272]*buf_B2_Bsecond_props_r2_i[t273])))))
                          buf_B2_Bsecond_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t274 = (c23 + (c17*44)) in (let t275 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bsecond_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t274]*buf_B2_Bsecond_props_r2_i[t275]) + (_src_psi_B2_i_b9[t274]*buf_B2_Bsecond_props_r2_r[t275])))))
                          buf_B2_Bthird_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t276 = (c23 + (c17*44)) in (let t277 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bthird_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t276]*buf_B2_Bthird_props_r2_r[t277]) - (_src_psi_B2_i_b9[t276]*buf_B2_Bthird_props_r2_i[t277])))))
                          buf_B2_Bthird_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t278 = (c23 + (c17*44)) in (let t279 = (c21 + int32((int64(c19)*(int64)2))) in (buf_B2_Bthird_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B2_r_b8[t278]*buf_B2_Bthird_props_r2_i[t279]) + (_src_psi_B2_i_b9[t278]*buf_B2_Bthird_props_r2_r[t279])))))
                          buf_flip_B2_Blocal_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t280 = (c23 + (c17*44)) in (let t281 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Blocal_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t280]*buf_B2_Blocal_props_r2_r[t281]) - (_src_psi_B1_i_b7[t280]*buf_B2_Blocal_props_r2_i[t281])))))
                          buf_flip_B2_Blocal_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t282 = (c23 + (c17*44)) in (let t283 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Blocal_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t282]*buf_B2_Blocal_props_r2_i[t283]) + (_src_psi_B1_i_b7[t282]*buf_B2_Blocal_props_r2_r[t283])))))
                          buf_flip_B2_Bfirst_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t284 = (c23 + (c17*44)) in (let t285 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bfirst_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t284]*buf_B2_Bfirst_props_r2_r[t285]) - (_src_psi_B1_i_b7[t284]*buf_B2_Bfirst_props_r2_i[t285])))))
                          buf_flip_B2_Bfirst_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t286 = (c23 + (c17*44)) in (let t287 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bfirst_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t286]*buf_B2_Bfirst_props_r2_i[t287]) + (_src_psi_B1_i_b7[t286]*buf_B2_Bfirst_props_r2_r[t287])))))
                          buf_flip_B2_Bsecond_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t288 = (c23 + (c17*44)) in (let t289 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bsecond_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t288]*buf_B2_Bsecond_props_r2_r[t289]) - (_src_psi_B1_i_b7[t288]*buf_B2_Bsecond_props_r2_i[t289])))))
                          buf_flip_B2_Bsecond_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t290 = (c23 + (c17*44)) in (let t291 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bsecond_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t290]*buf_B2_Bsecond_props_r2_i[t291]) + (_src_psi_B1_i_b7[t290]*buf_B2_Bsecond_props_r2_r[t291])))))
                          buf_flip_B2_Bthird_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t292 = (c23 + (c17*44)) in (let t293 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bthird_r2_r[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t292]*buf_B2_Bthird_props_r2_r[t293]) - (_src_psi_B1_i_b7[t292]*buf_B2_Bthird_props_r2_i[t293])))))
                          buf_flip_B2_Bthird_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] = (let t294 = (c23 + (c17*44)) in (let t295 = (c21 + int32((int64(c19)*(int64)2))) in (buf_flip_B2_Bthird_r2_i[((((((c23 + int32((int64(c21)*(int64)44))) + int32((int64(c19)*(int64)88))) + int32((int64(c15)*(int64)264))) + int32((int64(c13)*(int64)528))) + int32((int64(c11)*(int64)1584))) + int32((int64(c9)*(int64)3168)))] + ((_src_psi_B1_r_b6[t294]*buf_B2_Bthird_props_r2_i[t295]) + (_src_psi_B1_i_b7[t294]*buf_B2_Bthird_props_r2_r[t295])))))
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          for (c9, 0, 4) {
            for (c11, 0, 44) {
              for (c13, 0, 4) {
                buf_C_BB_BB_prop_r[0] = 0.000000
                buf_C_BB_BB_prop_i[0] = 0.000000
                for (c15, 0, 2) {
                  for (c17, 0, 36) {
                    for (c19, 0, 288) {
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4628 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4627 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4626 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4625 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4624 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4623 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B1_Blocal_r1_r[((((((c11 + int32((int64(t4628)*(int64)44))) + int32((int64(t4627)*(int64)88))) + int32((int64(t4626)*(int64)264))) + int32((int64(t4625)*(int64)528))) + int32((int64(t4624)*(int64)1584))) + int32((int64(t4623)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4645 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4644 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4643 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4642 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4641 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4640 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B1_Blocal_r1_i[((((((c11 + int32((int64(t4645)*(int64)44))) + int32((int64(t4644)*(int64)88))) + int32((int64(t4643)*(int64)264))) + int32((int64(t4642)*(int64)528))) + int32((int64(t4641)*(int64)1584))) + int32((int64(t4640)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t4662 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4661 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4660 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4659 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4658 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4657 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B2_Blocal_r1_r[((((((c11 + int32((int64(t4662)*(int64)44))) + int32((int64(t4661)*(int64)88))) + int32((int64(t4660)*(int64)264))) + int32((int64(t4659)*(int64)528))) + int32((int64(t4658)*(int64)1584))) + int32((int64(t4657)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t4679 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4678 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4677 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4676 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4675 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4674 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B2_Blocal_r1_i[((((((c11 + int32((int64(t4679)*(int64)44))) + int32((int64(t4678)*(int64)88))) + int32((int64(t4677)*(int64)264))) + int32((int64(t4676)*(int64)528))) + int32((int64(t4675)*(int64)1584))) + int32((int64(t4674)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4696 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4695 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4694 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4693 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4692 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4691 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B1_Bfirst_r1_r[((((((c11 + int32((int64(t4696)*(int64)44))) + int32((int64(t4695)*(int64)88))) + int32((int64(t4694)*(int64)264))) + int32((int64(t4693)*(int64)528))) + int32((int64(t4692)*(int64)1584))) + int32((int64(t4691)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4713 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4712 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4711 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4710 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4709 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4708 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B1_Bfirst_r1_i[((((((c11 + int32((int64(t4713)*(int64)44))) + int32((int64(t4712)*(int64)88))) + int32((int64(t4711)*(int64)264))) + int32((int64(t4710)*(int64)528))) + int32((int64(t4709)*(int64)1584))) + int32((int64(t4708)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t4730 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4729 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4728 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4727 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4726 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4725 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B2_Bfirst_r1_r[((((((c11 + int32((int64(t4730)*(int64)44))) + int32((int64(t4729)*(int64)88))) + int32((int64(t4728)*(int64)264))) + int32((int64(t4727)*(int64)528))) + int32((int64(t4726)*(int64)1584))) + int32((int64(t4725)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t4747 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4746 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4745 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4744 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4743 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4742 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B2_Bfirst_r1_i[((((((c11 + int32((int64(t4747)*(int64)44))) + int32((int64(t4746)*(int64)88))) + int32((int64(t4745)*(int64)264))) + int32((int64(t4744)*(int64)528))) + int32((int64(t4743)*(int64)1584))) + int32((int64(t4742)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4764 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4763 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4762 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4761 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4760 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4759 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B1_Bsecond_r1_r[((((((c11 + int32((int64(t4764)*(int64)44))) + int32((int64(t4763)*(int64)88))) + int32((int64(t4762)*(int64)264))) + int32((int64(t4761)*(int64)528))) + int32((int64(t4760)*(int64)1584))) + int32((int64(t4759)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4781 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4780 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4779 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4778 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4777 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4776 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B1_Bsecond_r1_i[((((((c11 + int32((int64(t4781)*(int64)44))) + int32((int64(t4780)*(int64)88))) + int32((int64(t4779)*(int64)264))) + int32((int64(t4778)*(int64)528))) + int32((int64(t4777)*(int64)1584))) + int32((int64(t4776)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t4798 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4797 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4796 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4795 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4794 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4793 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B2_Bsecond_r1_r[((((((c11 + int32((int64(t4798)*(int64)44))) + int32((int64(t4797)*(int64)88))) + int32((int64(t4796)*(int64)264))) + int32((int64(t4795)*(int64)528))) + int32((int64(t4794)*(int64)1584))) + int32((int64(t4793)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t4815 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4814 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4813 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4812 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4811 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4810 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B2_Bsecond_r1_i[((((((c11 + int32((int64(t4815)*(int64)44))) + int32((int64(t4814)*(int64)88))) + int32((int64(t4813)*(int64)264))) + int32((int64(t4812)*(int64)528))) + int32((int64(t4811)*(int64)1584))) + int32((int64(t4810)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t4832 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4831 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4830 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4829 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4828 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4827 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B1_Bthird_r1_r[((((((c11 + int32((int64(t4832)*(int64)44))) + int32((int64(t4831)*(int64)88))) + int32((int64(t4830)*(int64)264))) + int32((int64(t4829)*(int64)528))) + int32((int64(t4828)*(int64)1584))) + int32((int64(t4827)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t4849 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4848 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4847 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4846 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4845 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4844 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B1_Bthird_r1_i[((((((c11 + int32((int64(t4849)*(int64)44))) + int32((int64(t4848)*(int64)88))) + int32((int64(t4847)*(int64)264))) + int32((int64(t4846)*(int64)528))) + int32((int64(t4845)*(int64)1584))) + int32((int64(t4844)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4866 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4865 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4864 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4863 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4862 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4861 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B2_Bthird_r1_r[((((((c11 + int32((int64(t4866)*(int64)44))) + int32((int64(t4865)*(int64)88))) + int32((int64(t4864)*(int64)264))) + int32((int64(t4863)*(int64)528))) + int32((int64(t4862)*(int64)1584))) + int32((int64(t4861)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4883 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4882 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4881 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4880 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4879 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4878 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B2_Bthird_r1_i[((((((c11 + int32((int64(t4883)*(int64)44))) + int32((int64(t4882)*(int64)88))) + int32((int64(t4881)*(int64)264))) + int32((int64(t4880)*(int64)528))) + int32((int64(t4879)*(int64)1584))) + int32((int64(t4878)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4900 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4899 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4898 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4897 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4896 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4895 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B1_Blocal_r2_r[((((((c11 + int32((int64(t4900)*(int64)44))) + int32((int64(t4899)*(int64)88))) + int32((int64(t4898)*(int64)264))) + int32((int64(t4897)*(int64)528))) + int32((int64(t4896)*(int64)1584))) + int32((int64(t4895)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4917 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4916 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4915 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4914 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4913 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4912 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B1_Blocal_r2_i[((((((c11 + int32((int64(t4917)*(int64)44))) + int32((int64(t4916)*(int64)88))) + int32((int64(t4915)*(int64)264))) + int32((int64(t4914)*(int64)528))) + int32((int64(t4913)*(int64)1584))) + int32((int64(t4912)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t4934 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4933 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4932 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4931 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4930 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4929 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B2_Blocal_r2_r[((((((c11 + int32((int64(t4934)*(int64)44))) + int32((int64(t4933)*(int64)88))) + int32((int64(t4932)*(int64)264))) + int32((int64(t4931)*(int64)528))) + int32((int64(t4930)*(int64)1584))) + int32((int64(t4929)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t4951 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4950 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4949 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4948 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4947 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4946 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B2_Blocal_r2_i[((((((c11 + int32((int64(t4951)*(int64)44))) + int32((int64(t4950)*(int64)88))) + int32((int64(t4949)*(int64)264))) + int32((int64(t4948)*(int64)528))) + int32((int64(t4947)*(int64)1584))) + int32((int64(t4946)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4968 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4967 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4966 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4965 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4964 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4963 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B1_Bfirst_r2_r[((((((c11 + int32((int64(t4968)*(int64)44))) + int32((int64(t4967)*(int64)88))) + int32((int64(t4966)*(int64)264))) + int32((int64(t4965)*(int64)528))) + int32((int64(t4964)*(int64)1584))) + int32((int64(t4963)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t4985 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4984 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t4983 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4982 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4981 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4980 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B1_Bfirst_r2_i[((((((c11 + int32((int64(t4985)*(int64)44))) + int32((int64(t4984)*(int64)88))) + int32((int64(t4983)*(int64)264))) + int32((int64(t4982)*(int64)528))) + int32((int64(t4981)*(int64)1584))) + int32((int64(t4980)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5002 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5001 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5000 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4999 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t4998 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t4997 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B2_Bfirst_r2_r[((((((c11 + int32((int64(t5002)*(int64)44))) + int32((int64(t5001)*(int64)88))) + int32((int64(t5000)*(int64)264))) + int32((int64(t4999)*(int64)528))) + int32((int64(t4998)*(int64)1584))) + int32((int64(t4997)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5019 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5018 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5017 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5016 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5015 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5014 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B2_Bfirst_r2_i[((((((c11 + int32((int64(t5019)*(int64)44))) + int32((int64(t5018)*(int64)88))) + int32((int64(t5017)*(int64)264))) + int32((int64(t5016)*(int64)528))) + int32((int64(t5015)*(int64)1584))) + int32((int64(t5014)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5036 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5035 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5034 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5033 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5032 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5031 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B1_Bsecond_r2_r[((((((c11 + int32((int64(t5036)*(int64)44))) + int32((int64(t5035)*(int64)88))) + int32((int64(t5034)*(int64)264))) + int32((int64(t5033)*(int64)528))) + int32((int64(t5032)*(int64)1584))) + int32((int64(t5031)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5053 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5052 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5051 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5050 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5049 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5048 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B1_Bsecond_r2_i[((((((c11 + int32((int64(t5053)*(int64)44))) + int32((int64(t5052)*(int64)88))) + int32((int64(t5051)*(int64)264))) + int32((int64(t5050)*(int64)528))) + int32((int64(t5049)*(int64)1584))) + int32((int64(t5048)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5070 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5069 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5068 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5067 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5066 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5065 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B2_Bsecond_r2_r[((((((c11 + int32((int64(t5070)*(int64)44))) + int32((int64(t5069)*(int64)88))) + int32((int64(t5068)*(int64)264))) + int32((int64(t5067)*(int64)528))) + int32((int64(t5066)*(int64)1584))) + int32((int64(t5065)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5087 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5086 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5085 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5084 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5083 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5082 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B2_Bsecond_r2_i[((((((c11 + int32((int64(t5087)*(int64)44))) + int32((int64(t5086)*(int64)88))) + int32((int64(t5085)*(int64)264))) + int32((int64(t5084)*(int64)528))) + int32((int64(t5083)*(int64)1584))) + int32((int64(t5082)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5104 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5103 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5102 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5101 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5100 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5099 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B1_Bthird_r2_r[((((((c11 + int32((int64(t5104)*(int64)44))) + int32((int64(t5103)*(int64)88))) + int32((int64(t5102)*(int64)264))) + int32((int64(t5101)*(int64)528))) + int32((int64(t5100)*(int64)1584))) + int32((int64(t5099)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5121 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5120 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5119 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5118 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5117 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5116 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B1_Bthird_r2_i[((((((c11 + int32((int64(t5121)*(int64)44))) + int32((int64(t5120)*(int64)88))) + int32((int64(t5119)*(int64)264))) + int32((int64(t5118)*(int64)528))) + int32((int64(t5117)*(int64)1584))) + int32((int64(t5116)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5138 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5137 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5136 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5135 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5134 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5133 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_r[0] = buf_B2_Bthird_r2_r[((((((c11 + int32((int64(t5138)*(int64)44))) + int32((int64(t5137)*(int64)88))) + int32((int64(t5136)*(int64)264))) + int32((int64(t5135)*(int64)528))) + int32((int64(t5134)*(int64)1584))) + int32((int64(t5133)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5155 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5154 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5153 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5152 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5151 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5150 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_BB_BB_new_term_b1_i[0] = buf_B2_Bthird_r2_i[((((((c11 + int32((int64(t5155)*(int64)44))) + int32((int64(t5154)*(int64)88))) + int32((int64(t5153)*(int64)264))) + int32((int64(t5152)*(int64)528))) + int32((int64(t5151)*(int64)1584))) + int32((int64(t5150)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5172 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5171 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5170 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5169 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5168 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5167 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B1_Blocal_r1_r[((((((c11 + int32((int64(t5172)*(int64)44))) + int32((int64(t5171)*(int64)88))) + int32((int64(t5170)*(int64)264))) + int32((int64(t5169)*(int64)528))) + int32((int64(t5168)*(int64)1584))) + int32((int64(t5167)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5189 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5188 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5187 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5186 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5185 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5184 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B1_Blocal_r1_i[((((((c11 + int32((int64(t5189)*(int64)44))) + int32((int64(t5188)*(int64)88))) + int32((int64(t5187)*(int64)264))) + int32((int64(t5186)*(int64)528))) + int32((int64(t5185)*(int64)1584))) + int32((int64(t5184)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5206 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5205 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5204 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5203 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5202 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5201 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B2_Blocal_r1_r[((((((c11 + int32((int64(t5206)*(int64)44))) + int32((int64(t5205)*(int64)88))) + int32((int64(t5204)*(int64)264))) + int32((int64(t5203)*(int64)528))) + int32((int64(t5202)*(int64)1584))) + int32((int64(t5201)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5223 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5222 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5221 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5220 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5219 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5218 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B2_Blocal_r1_i[((((((c11 + int32((int64(t5223)*(int64)44))) + int32((int64(t5222)*(int64)88))) + int32((int64(t5221)*(int64)264))) + int32((int64(t5220)*(int64)528))) + int32((int64(t5219)*(int64)1584))) + int32((int64(t5218)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5240 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5239 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5238 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5237 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5236 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5235 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B1_Bfirst_r1_r[((((((c11 + int32((int64(t5240)*(int64)44))) + int32((int64(t5239)*(int64)88))) + int32((int64(t5238)*(int64)264))) + int32((int64(t5237)*(int64)528))) + int32((int64(t5236)*(int64)1584))) + int32((int64(t5235)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5257 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5256 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5255 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5254 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5253 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5252 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B1_Bfirst_r1_i[((((((c11 + int32((int64(t5257)*(int64)44))) + int32((int64(t5256)*(int64)88))) + int32((int64(t5255)*(int64)264))) + int32((int64(t5254)*(int64)528))) + int32((int64(t5253)*(int64)1584))) + int32((int64(t5252)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5274 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5273 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5272 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5271 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5270 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5269 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B2_Bfirst_r1_r[((((((c11 + int32((int64(t5274)*(int64)44))) + int32((int64(t5273)*(int64)88))) + int32((int64(t5272)*(int64)264))) + int32((int64(t5271)*(int64)528))) + int32((int64(t5270)*(int64)1584))) + int32((int64(t5269)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5291 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5290 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5289 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5288 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5287 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5286 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B2_Bfirst_r1_i[((((((c11 + int32((int64(t5291)*(int64)44))) + int32((int64(t5290)*(int64)88))) + int32((int64(t5289)*(int64)264))) + int32((int64(t5288)*(int64)528))) + int32((int64(t5287)*(int64)1584))) + int32((int64(t5286)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5308 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5307 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5306 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5305 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5304 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5303 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B1_Bsecond_r1_r[((((((c11 + int32((int64(t5308)*(int64)44))) + int32((int64(t5307)*(int64)88))) + int32((int64(t5306)*(int64)264))) + int32((int64(t5305)*(int64)528))) + int32((int64(t5304)*(int64)1584))) + int32((int64(t5303)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5325 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5324 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5323 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5322 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5321 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5320 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B1_Bsecond_r1_i[((((((c11 + int32((int64(t5325)*(int64)44))) + int32((int64(t5324)*(int64)88))) + int32((int64(t5323)*(int64)264))) + int32((int64(t5322)*(int64)528))) + int32((int64(t5321)*(int64)1584))) + int32((int64(t5320)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5342 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5341 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5340 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5339 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5338 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5337 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B2_Bsecond_r1_r[((((((c11 + int32((int64(t5342)*(int64)44))) + int32((int64(t5341)*(int64)88))) + int32((int64(t5340)*(int64)264))) + int32((int64(t5339)*(int64)528))) + int32((int64(t5338)*(int64)1584))) + int32((int64(t5337)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5359 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5358 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5357 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5356 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5355 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5354 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B2_Bsecond_r1_i[((((((c11 + int32((int64(t5359)*(int64)44))) + int32((int64(t5358)*(int64)88))) + int32((int64(t5357)*(int64)264))) + int32((int64(t5356)*(int64)528))) + int32((int64(t5355)*(int64)1584))) + int32((int64(t5354)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5376 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5375 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5374 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5373 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5372 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5371 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B1_Bthird_r1_r[((((((c11 + int32((int64(t5376)*(int64)44))) + int32((int64(t5375)*(int64)88))) + int32((int64(t5374)*(int64)264))) + int32((int64(t5373)*(int64)528))) + int32((int64(t5372)*(int64)1584))) + int32((int64(t5371)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5393 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5392 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5391 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5390 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5389 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5388 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B1_Bthird_r1_i[((((((c11 + int32((int64(t5393)*(int64)44))) + int32((int64(t5392)*(int64)88))) + int32((int64(t5391)*(int64)264))) + int32((int64(t5390)*(int64)528))) + int32((int64(t5389)*(int64)1584))) + int32((int64(t5388)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5410 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5409 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5408 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5407 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5406 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5405 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B2_Bthird_r1_r[((((((c11 + int32((int64(t5410)*(int64)44))) + int32((int64(t5409)*(int64)88))) + int32((int64(t5408)*(int64)264))) + int32((int64(t5407)*(int64)528))) + int32((int64(t5406)*(int64)1584))) + int32((int64(t5405)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5427 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5426 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5425 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5424 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5423 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5422 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B2_Bthird_r1_i[((((((c11 + int32((int64(t5427)*(int64)44))) + int32((int64(t5426)*(int64)88))) + int32((int64(t5425)*(int64)264))) + int32((int64(t5424)*(int64)528))) + int32((int64(t5423)*(int64)1584))) + int32((int64(t5422)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5444 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5443 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5442 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5441 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5440 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5439 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B1_Blocal_r2_r[((((((c11 + int32((int64(t5444)*(int64)44))) + int32((int64(t5443)*(int64)88))) + int32((int64(t5442)*(int64)264))) + int32((int64(t5441)*(int64)528))) + int32((int64(t5440)*(int64)1584))) + int32((int64(t5439)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5461 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5460 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5459 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5458 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5457 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5456 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B1_Blocal_r2_i[((((((c11 + int32((int64(t5461)*(int64)44))) + int32((int64(t5460)*(int64)88))) + int32((int64(t5459)*(int64)264))) + int32((int64(t5458)*(int64)528))) + int32((int64(t5457)*(int64)1584))) + int32((int64(t5456)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5478 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5477 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5476 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5475 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5474 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5473 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B2_Blocal_r2_r[((((((c11 + int32((int64(t5478)*(int64)44))) + int32((int64(t5477)*(int64)88))) + int32((int64(t5476)*(int64)264))) + int32((int64(t5475)*(int64)528))) + int32((int64(t5474)*(int64)1584))) + int32((int64(t5473)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5495 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5494 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5493 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5492 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5491 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5490 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B2_Blocal_r2_i[((((((c11 + int32((int64(t5495)*(int64)44))) + int32((int64(t5494)*(int64)88))) + int32((int64(t5493)*(int64)264))) + int32((int64(t5492)*(int64)528))) + int32((int64(t5491)*(int64)1584))) + int32((int64(t5490)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5512 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5511 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5510 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5509 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5508 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5507 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B1_Bfirst_r2_r[((((((c11 + int32((int64(t5512)*(int64)44))) + int32((int64(t5511)*(int64)88))) + int32((int64(t5510)*(int64)264))) + int32((int64(t5509)*(int64)528))) + int32((int64(t5508)*(int64)1584))) + int32((int64(t5507)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5529 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5528 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5527 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5526 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5525 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5524 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B1_Bfirst_r2_i[((((((c11 + int32((int64(t5529)*(int64)44))) + int32((int64(t5528)*(int64)88))) + int32((int64(t5527)*(int64)264))) + int32((int64(t5526)*(int64)528))) + int32((int64(t5525)*(int64)1584))) + int32((int64(t5524)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5546 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5545 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5544 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5543 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5542 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5541 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B2_Bfirst_r2_r[((((((c11 + int32((int64(t5546)*(int64)44))) + int32((int64(t5545)*(int64)88))) + int32((int64(t5544)*(int64)264))) + int32((int64(t5543)*(int64)528))) + int32((int64(t5542)*(int64)1584))) + int32((int64(t5541)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5563 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5562 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5561 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5560 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5559 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5558 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B2_Bfirst_r2_i[((((((c11 + int32((int64(t5563)*(int64)44))) + int32((int64(t5562)*(int64)88))) + int32((int64(t5561)*(int64)264))) + int32((int64(t5560)*(int64)528))) + int32((int64(t5559)*(int64)1584))) + int32((int64(t5558)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5580 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5579 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5578 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5577 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5576 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5575 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B1_Bsecond_r2_r[((((((c11 + int32((int64(t5580)*(int64)44))) + int32((int64(t5579)*(int64)88))) + int32((int64(t5578)*(int64)264))) + int32((int64(t5577)*(int64)528))) + int32((int64(t5576)*(int64)1584))) + int32((int64(t5575)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5597 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5596 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5595 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5594 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5593 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5592 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B1_Bsecond_r2_i[((((((c11 + int32((int64(t5597)*(int64)44))) + int32((int64(t5596)*(int64)88))) + int32((int64(t5595)*(int64)264))) + int32((int64(t5594)*(int64)528))) + int32((int64(t5593)*(int64)1584))) + int32((int64(t5592)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5614 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5613 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5612 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5611 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5610 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5609 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B2_Bsecond_r2_r[((((((c11 + int32((int64(t5614)*(int64)44))) + int32((int64(t5613)*(int64)88))) + int32((int64(t5612)*(int64)264))) + int32((int64(t5611)*(int64)528))) + int32((int64(t5610)*(int64)1584))) + int32((int64(t5609)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5631 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5630 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5629 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5628 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5627 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5626 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B2_Bsecond_r2_i[((((((c11 + int32((int64(t5631)*(int64)44))) + int32((int64(t5630)*(int64)88))) + int32((int64(t5629)*(int64)264))) + int32((int64(t5628)*(int64)528))) + int32((int64(t5627)*(int64)1584))) + int32((int64(t5626)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5648 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5647 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5646 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5645 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5644 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5643 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B1_Bthird_r2_r[((((((c11 + int32((int64(t5648)*(int64)44))) + int32((int64(t5647)*(int64)88))) + int32((int64(t5646)*(int64)264))) + int32((int64(t5645)*(int64)528))) + int32((int64(t5644)*(int64)1584))) + int32((int64(t5643)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t5665 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5664 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5663 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5662 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5661 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5660 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B1_Bthird_r2_i[((((((c11 + int32((int64(t5665)*(int64)44))) + int32((int64(t5664)*(int64)88))) + int32((int64(t5663)*(int64)264))) + int32((int64(t5662)*(int64)528))) + int32((int64(t5661)*(int64)1584))) + int32((int64(t5660)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5682 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5681 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5680 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5679 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5678 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5677 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_r[0] = buf_B2_Bthird_r2_r[((((((c11 + int32((int64(t5682)*(int64)44))) + int32((int64(t5681)*(int64)88))) + int32((int64(t5680)*(int64)264))) + int32((int64(t5679)*(int64)528))) + int32((int64(t5678)*(int64)1584))) + int32((int64(t5677)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t5699 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5698 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t5697 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5696 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t5695 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t5694 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_BB_BB_new_term_b2_i[0] = buf_B2_Bthird_r2_i[((((((c11 + int32((int64(t5699)*(int64)44))) + int32((int64(t5698)*(int64)88))) + int32((int64(t5697)*(int64)264))) + int32((int64(t5696)*(int64)528))) + int32((int64(t5695)*(int64)1584))) + int32((int64(t5694)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5716 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5715 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5714 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5713 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5712 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5711 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B1_Blocal_r1_r[((((((c11 + int32((int64(t5716)*(int64)44))) + int32((int64(t5715)*(int64)88))) + int32((int64(t5714)*(int64)264))) + int32((int64(t5713)*(int64)528))) + int32((int64(t5712)*(int64)1584))) + int32((int64(t5711)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5733 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5732 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5731 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5730 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5729 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5728 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B1_Blocal_r1_i[((((((c11 + int32((int64(t5733)*(int64)44))) + int32((int64(t5732)*(int64)88))) + int32((int64(t5731)*(int64)264))) + int32((int64(t5730)*(int64)528))) + int32((int64(t5729)*(int64)1584))) + int32((int64(t5728)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5750 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5749 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5748 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5747 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5746 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5745 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B2_Blocal_r1_r[((((((c11 + int32((int64(t5750)*(int64)44))) + int32((int64(t5749)*(int64)88))) + int32((int64(t5748)*(int64)264))) + int32((int64(t5747)*(int64)528))) + int32((int64(t5746)*(int64)1584))) + int32((int64(t5745)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5767 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5766 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5765 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5764 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5763 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5762 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B2_Blocal_r1_i[((((((c11 + int32((int64(t5767)*(int64)44))) + int32((int64(t5766)*(int64)88))) + int32((int64(t5765)*(int64)264))) + int32((int64(t5764)*(int64)528))) + int32((int64(t5763)*(int64)1584))) + int32((int64(t5762)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5784 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5783 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5782 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5781 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5780 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5779 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B1_Bfirst_r1_r[((((((c11 + int32((int64(t5784)*(int64)44))) + int32((int64(t5783)*(int64)88))) + int32((int64(t5782)*(int64)264))) + int32((int64(t5781)*(int64)528))) + int32((int64(t5780)*(int64)1584))) + int32((int64(t5779)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5801 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5800 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5799 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5798 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5797 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5796 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B1_Bfirst_r1_i[((((((c11 + int32((int64(t5801)*(int64)44))) + int32((int64(t5800)*(int64)88))) + int32((int64(t5799)*(int64)264))) + int32((int64(t5798)*(int64)528))) + int32((int64(t5797)*(int64)1584))) + int32((int64(t5796)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5818 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5817 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5816 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5815 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5814 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5813 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B2_Bfirst_r1_r[((((((c11 + int32((int64(t5818)*(int64)44))) + int32((int64(t5817)*(int64)88))) + int32((int64(t5816)*(int64)264))) + int32((int64(t5815)*(int64)528))) + int32((int64(t5814)*(int64)1584))) + int32((int64(t5813)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5835 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5834 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5833 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5832 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5831 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5830 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B2_Bfirst_r1_i[((((((c11 + int32((int64(t5835)*(int64)44))) + int32((int64(t5834)*(int64)88))) + int32((int64(t5833)*(int64)264))) + int32((int64(t5832)*(int64)528))) + int32((int64(t5831)*(int64)1584))) + int32((int64(t5830)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5852 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5851 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5850 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5849 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5848 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5847 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B1_Bsecond_r1_r[((((((c11 + int32((int64(t5852)*(int64)44))) + int32((int64(t5851)*(int64)88))) + int32((int64(t5850)*(int64)264))) + int32((int64(t5849)*(int64)528))) + int32((int64(t5848)*(int64)1584))) + int32((int64(t5847)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5869 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5868 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5867 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5866 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5865 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5864 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B1_Bsecond_r1_i[((((((c11 + int32((int64(t5869)*(int64)44))) + int32((int64(t5868)*(int64)88))) + int32((int64(t5867)*(int64)264))) + int32((int64(t5866)*(int64)528))) + int32((int64(t5865)*(int64)1584))) + int32((int64(t5864)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5886 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5885 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5884 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5883 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5882 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5881 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B2_Bsecond_r1_r[((((((c11 + int32((int64(t5886)*(int64)44))) + int32((int64(t5885)*(int64)88))) + int32((int64(t5884)*(int64)264))) + int32((int64(t5883)*(int64)528))) + int32((int64(t5882)*(int64)1584))) + int32((int64(t5881)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5903 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5902 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5901 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5900 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5899 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5898 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B2_Bsecond_r1_i[((((((c11 + int32((int64(t5903)*(int64)44))) + int32((int64(t5902)*(int64)88))) + int32((int64(t5901)*(int64)264))) + int32((int64(t5900)*(int64)528))) + int32((int64(t5899)*(int64)1584))) + int32((int64(t5898)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5920 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5919 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5918 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5917 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5916 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5915 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B1_Bthird_r1_r[((((((c11 + int32((int64(t5920)*(int64)44))) + int32((int64(t5919)*(int64)88))) + int32((int64(t5918)*(int64)264))) + int32((int64(t5917)*(int64)528))) + int32((int64(t5916)*(int64)1584))) + int32((int64(t5915)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t5937 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5936 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5935 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5934 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5933 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5932 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B1_Bthird_r1_i[((((((c11 + int32((int64(t5937)*(int64)44))) + int32((int64(t5936)*(int64)88))) + int32((int64(t5935)*(int64)264))) + int32((int64(t5934)*(int64)528))) + int32((int64(t5933)*(int64)1584))) + int32((int64(t5932)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5954 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5953 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5952 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5951 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5950 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5949 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B2_Bthird_r1_r[((((((c11 + int32((int64(t5954)*(int64)44))) + int32((int64(t5953)*(int64)88))) + int32((int64(t5952)*(int64)264))) + int32((int64(t5951)*(int64)528))) + int32((int64(t5950)*(int64)1584))) + int32((int64(t5949)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 1) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5971 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5970 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5969 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5968 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5967 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5966 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B2_Bthird_r1_i[((((((c11 + int32((int64(t5971)*(int64)44))) + int32((int64(t5970)*(int64)88))) + int32((int64(t5969)*(int64)264))) + int32((int64(t5968)*(int64)528))) + int32((int64(t5967)*(int64)1584))) + int32((int64(t5966)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t5988 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5987 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t5986 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5985 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t5984 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t5983 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B1_Blocal_r2_r[((((((c11 + int32((int64(t5988)*(int64)44))) + int32((int64(t5987)*(int64)88))) + int32((int64(t5986)*(int64)264))) + int32((int64(t5985)*(int64)528))) + int32((int64(t5984)*(int64)1584))) + int32((int64(t5983)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t6005 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6004 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6003 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6002 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6001 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6000 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B1_Blocal_r2_i[((((((c11 + int32((int64(t6005)*(int64)44))) + int32((int64(t6004)*(int64)88))) + int32((int64(t6003)*(int64)264))) + int32((int64(t6002)*(int64)528))) + int32((int64(t6001)*(int64)1584))) + int32((int64(t6000)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t6022 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6021 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6020 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6019 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6018 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6017 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B2_Blocal_r2_r[((((((c11 + int32((int64(t6022)*(int64)44))) + int32((int64(t6021)*(int64)88))) + int32((int64(t6020)*(int64)264))) + int32((int64(t6019)*(int64)528))) + int32((int64(t6018)*(int64)1584))) + int32((int64(t6017)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t6039 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6038 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6037 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6036 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6035 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6034 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B2_Blocal_r2_i[((((((c11 + int32((int64(t6039)*(int64)44))) + int32((int64(t6038)*(int64)88))) + int32((int64(t6037)*(int64)264))) + int32((int64(t6036)*(int64)528))) + int32((int64(t6035)*(int64)1584))) + int32((int64(t6034)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t6056 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6055 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6054 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6053 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6052 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6051 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B1_Bfirst_r2_r[((((((c11 + int32((int64(t6056)*(int64)44))) + int32((int64(t6055)*(int64)88))) + int32((int64(t6054)*(int64)264))) + int32((int64(t6053)*(int64)528))) + int32((int64(t6052)*(int64)1584))) + int32((int64(t6051)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t6073 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6072 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6071 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6070 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6069 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6068 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B1_Bfirst_r2_i[((((((c11 + int32((int64(t6073)*(int64)44))) + int32((int64(t6072)*(int64)88))) + int32((int64(t6071)*(int64)264))) + int32((int64(t6070)*(int64)528))) + int32((int64(t6069)*(int64)1584))) + int32((int64(t6068)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t6090 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6089 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6088 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6087 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6086 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6085 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B2_Bfirst_r2_r[((((((c11 + int32((int64(t6090)*(int64)44))) + int32((int64(t6089)*(int64)88))) + int32((int64(t6088)*(int64)264))) + int32((int64(t6087)*(int64)528))) + int32((int64(t6086)*(int64)1584))) + int32((int64(t6085)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t6107 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6106 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6105 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6104 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6103 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6102 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B2_Bfirst_r2_i[((((((c11 + int32((int64(t6107)*(int64)44))) + int32((int64(t6106)*(int64)88))) + int32((int64(t6105)*(int64)264))) + int32((int64(t6104)*(int64)528))) + int32((int64(t6103)*(int64)1584))) + int32((int64(t6102)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t6124 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6123 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6122 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6121 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6120 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6119 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B1_Bsecond_r2_r[((((((c11 + int32((int64(t6124)*(int64)44))) + int32((int64(t6123)*(int64)88))) + int32((int64(t6122)*(int64)264))) + int32((int64(t6121)*(int64)528))) + int32((int64(t6120)*(int64)1584))) + int32((int64(t6119)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t6141 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6140 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6139 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6138 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6137 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6136 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B1_Bsecond_r2_i[((((((c11 + int32((int64(t6141)*(int64)44))) + int32((int64(t6140)*(int64)88))) + int32((int64(t6139)*(int64)264))) + int32((int64(t6138)*(int64)528))) + int32((int64(t6137)*(int64)1584))) + int32((int64(t6136)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t6158 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6157 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6156 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6155 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6154 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6153 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B2_Bsecond_r2_r[((((((c11 + int32((int64(t6158)*(int64)44))) + int32((int64(t6157)*(int64)88))) + int32((int64(t6156)*(int64)264))) + int32((int64(t6155)*(int64)528))) + int32((int64(t6154)*(int64)1584))) + int32((int64(t6153)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t6175 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6174 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6173 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6172 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6171 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6170 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B2_Bsecond_r2_i[((((((c11 + int32((int64(t6175)*(int64)44))) + int32((int64(t6174)*(int64)88))) + int32((int64(t6173)*(int64)264))) + int32((int64(t6172)*(int64)528))) + int32((int64(t6171)*(int64)1584))) + int32((int64(t6170)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t6192 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6191 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6190 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6189 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6188 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6187 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B1_Bthird_r2_r[((((((c11 + int32((int64(t6192)*(int64)44))) + int32((int64(t6191)*(int64)88))) + int32((int64(t6190)*(int64)264))) + int32((int64(t6189)*(int64)528))) + int32((int64(t6188)*(int64)1584))) + int32((int64(t6187)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 0) && (_snk_b_b23[((c17*6) + 2)] == 0)) && (_snk_b_b23[((c17*6) + 4)] == 1)))) {
                        let t6209 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6208 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6207 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6206 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6205 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6204 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B1_Bthird_r2_i[((((((c11 + int32((int64(t6209)*(int64)44))) + int32((int64(t6208)*(int64)88))) + int32((int64(t6207)*(int64)264))) + int32((int64(t6206)*(int64)528))) + int32((int64(t6205)*(int64)1584))) + int32((int64(t6204)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t6226 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6225 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6224 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6223 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6222 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6221 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_r[0] = buf_flip_B2_Bthird_r2_r[((((((c11 + int32((int64(t6226)*(int64)44))) + int32((int64(t6225)*(int64)88))) + int32((int64(t6224)*(int64)264))) + int32((int64(t6223)*(int64)528))) + int32((int64(t6222)*(int64)1584))) + int32((int64(t6221)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[((c15*2) + (c9*4))] == 2) && (((_snk_b_b23[(c17*6)] == 1) && (_snk_b_b23[((c17*6) + 2)] == 1)) && (_snk_b_b23[((c17*6) + 4)] == 0)))) {
                        let t6243 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6242 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 2)]
                        let t6241 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6240 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 4)]
                        let t6239 = _snk_spin_weights_b28[(((c19*6) + (c17*1728)) + (c13*62208))]
                        let t6238 = _snk_color_weights_b27[(((c19*6) + (c17*1728)) + (c13*62208))]
                        buf_flip_BB_BB_new_term_b1_i[0] = buf_flip_B2_Bthird_r2_i[((((((c11 + int32((int64(t6243)*(int64)44))) + int32((int64(t6242)*(int64)88))) + int32((int64(t6241)*(int64)264))) + int32((int64(t6240)*(int64)528))) + int32((int64(t6239)*(int64)1584))) + int32((int64(t6238)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6260 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6259 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6258 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6257 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6256 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6255 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B1_Blocal_r1_r[((((((c11 + int32((int64(t6260)*(int64)44))) + int32((int64(t6259)*(int64)88))) + int32((int64(t6258)*(int64)264))) + int32((int64(t6257)*(int64)528))) + int32((int64(t6256)*(int64)1584))) + int32((int64(t6255)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6277 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6276 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6275 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6274 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6273 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6272 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B1_Blocal_r1_i[((((((c11 + int32((int64(t6277)*(int64)44))) + int32((int64(t6276)*(int64)88))) + int32((int64(t6275)*(int64)264))) + int32((int64(t6274)*(int64)528))) + int32((int64(t6273)*(int64)1584))) + int32((int64(t6272)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6294 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6293 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6292 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6291 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6290 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6289 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B2_Blocal_r1_r[((((((c11 + int32((int64(t6294)*(int64)44))) + int32((int64(t6293)*(int64)88))) + int32((int64(t6292)*(int64)264))) + int32((int64(t6291)*(int64)528))) + int32((int64(t6290)*(int64)1584))) + int32((int64(t6289)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6311 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6310 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6309 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6308 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6307 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6306 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B2_Blocal_r1_i[((((((c11 + int32((int64(t6311)*(int64)44))) + int32((int64(t6310)*(int64)88))) + int32((int64(t6309)*(int64)264))) + int32((int64(t6308)*(int64)528))) + int32((int64(t6307)*(int64)1584))) + int32((int64(t6306)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6328 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6327 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6326 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6325 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6324 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6323 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B1_Bfirst_r1_r[((((((c11 + int32((int64(t6328)*(int64)44))) + int32((int64(t6327)*(int64)88))) + int32((int64(t6326)*(int64)264))) + int32((int64(t6325)*(int64)528))) + int32((int64(t6324)*(int64)1584))) + int32((int64(t6323)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6345 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6344 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6343 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6342 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6341 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6340 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B1_Bfirst_r1_i[((((((c11 + int32((int64(t6345)*(int64)44))) + int32((int64(t6344)*(int64)88))) + int32((int64(t6343)*(int64)264))) + int32((int64(t6342)*(int64)528))) + int32((int64(t6341)*(int64)1584))) + int32((int64(t6340)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6362 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6361 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6360 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6359 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6358 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6357 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B2_Bfirst_r1_r[((((((c11 + int32((int64(t6362)*(int64)44))) + int32((int64(t6361)*(int64)88))) + int32((int64(t6360)*(int64)264))) + int32((int64(t6359)*(int64)528))) + int32((int64(t6358)*(int64)1584))) + int32((int64(t6357)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6379 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6378 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6377 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6376 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6375 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6374 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B2_Bfirst_r1_i[((((((c11 + int32((int64(t6379)*(int64)44))) + int32((int64(t6378)*(int64)88))) + int32((int64(t6377)*(int64)264))) + int32((int64(t6376)*(int64)528))) + int32((int64(t6375)*(int64)1584))) + int32((int64(t6374)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6396 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6395 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6394 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6393 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6392 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6391 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B1_Bsecond_r1_r[((((((c11 + int32((int64(t6396)*(int64)44))) + int32((int64(t6395)*(int64)88))) + int32((int64(t6394)*(int64)264))) + int32((int64(t6393)*(int64)528))) + int32((int64(t6392)*(int64)1584))) + int32((int64(t6391)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6413 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6412 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6411 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6410 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6409 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6408 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B1_Bsecond_r1_i[((((((c11 + int32((int64(t6413)*(int64)44))) + int32((int64(t6412)*(int64)88))) + int32((int64(t6411)*(int64)264))) + int32((int64(t6410)*(int64)528))) + int32((int64(t6409)*(int64)1584))) + int32((int64(t6408)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6430 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6429 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6428 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6427 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6426 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6425 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B2_Bsecond_r1_r[((((((c11 + int32((int64(t6430)*(int64)44))) + int32((int64(t6429)*(int64)88))) + int32((int64(t6428)*(int64)264))) + int32((int64(t6427)*(int64)528))) + int32((int64(t6426)*(int64)1584))) + int32((int64(t6425)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6447 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6446 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6445 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6444 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6443 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6442 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B2_Bsecond_r1_i[((((((c11 + int32((int64(t6447)*(int64)44))) + int32((int64(t6446)*(int64)88))) + int32((int64(t6445)*(int64)264))) + int32((int64(t6444)*(int64)528))) + int32((int64(t6443)*(int64)1584))) + int32((int64(t6442)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6464 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6463 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6462 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6461 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6460 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6459 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B1_Bthird_r1_r[((((((c11 + int32((int64(t6464)*(int64)44))) + int32((int64(t6463)*(int64)88))) + int32((int64(t6462)*(int64)264))) + int32((int64(t6461)*(int64)528))) + int32((int64(t6460)*(int64)1584))) + int32((int64(t6459)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6481 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6480 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6479 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6478 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6477 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6476 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B1_Bthird_r1_i[((((((c11 + int32((int64(t6481)*(int64)44))) + int32((int64(t6480)*(int64)88))) + int32((int64(t6479)*(int64)264))) + int32((int64(t6478)*(int64)528))) + int32((int64(t6477)*(int64)1584))) + int32((int64(t6476)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6498 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6497 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6496 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6495 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6494 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6493 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B2_Bthird_r1_r[((((((c11 + int32((int64(t6498)*(int64)44))) + int32((int64(t6497)*(int64)88))) + int32((int64(t6496)*(int64)264))) + int32((int64(t6495)*(int64)528))) + int32((int64(t6494)*(int64)1584))) + int32((int64(t6493)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 1) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6515 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6514 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6513 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6512 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6511 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6510 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B2_Bthird_r1_i[((((((c11 + int32((int64(t6515)*(int64)44))) + int32((int64(t6514)*(int64)88))) + int32((int64(t6513)*(int64)264))) + int32((int64(t6512)*(int64)528))) + int32((int64(t6511)*(int64)1584))) + int32((int64(t6510)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6532 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6531 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6530 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6529 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6528 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6527 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B1_Blocal_r2_r[((((((c11 + int32((int64(t6532)*(int64)44))) + int32((int64(t6531)*(int64)88))) + int32((int64(t6530)*(int64)264))) + int32((int64(t6529)*(int64)528))) + int32((int64(t6528)*(int64)1584))) + int32((int64(t6527)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6549 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6548 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6547 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6546 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6545 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6544 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B1_Blocal_r2_i[((((((c11 + int32((int64(t6549)*(int64)44))) + int32((int64(t6548)*(int64)88))) + int32((int64(t6547)*(int64)264))) + int32((int64(t6546)*(int64)528))) + int32((int64(t6545)*(int64)1584))) + int32((int64(t6544)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6566 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6565 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6564 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6563 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6562 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6561 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B2_Blocal_r2_r[((((((c11 + int32((int64(t6566)*(int64)44))) + int32((int64(t6565)*(int64)88))) + int32((int64(t6564)*(int64)264))) + int32((int64(t6563)*(int64)528))) + int32((int64(t6562)*(int64)1584))) + int32((int64(t6561)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6583 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6582 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6581 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6580 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6579 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6578 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B2_Blocal_r2_i[((((((c11 + int32((int64(t6583)*(int64)44))) + int32((int64(t6582)*(int64)88))) + int32((int64(t6581)*(int64)264))) + int32((int64(t6580)*(int64)528))) + int32((int64(t6579)*(int64)1584))) + int32((int64(t6578)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6600 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6599 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6598 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6597 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6596 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6595 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B1_Bfirst_r2_r[((((((c11 + int32((int64(t6600)*(int64)44))) + int32((int64(t6599)*(int64)88))) + int32((int64(t6598)*(int64)264))) + int32((int64(t6597)*(int64)528))) + int32((int64(t6596)*(int64)1584))) + int32((int64(t6595)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6617 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6616 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6615 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6614 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6613 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6612 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B1_Bfirst_r2_i[((((((c11 + int32((int64(t6617)*(int64)44))) + int32((int64(t6616)*(int64)88))) + int32((int64(t6615)*(int64)264))) + int32((int64(t6614)*(int64)528))) + int32((int64(t6613)*(int64)1584))) + int32((int64(t6612)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6634 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6633 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6632 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6631 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6630 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6629 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B2_Bfirst_r2_r[((((((c11 + int32((int64(t6634)*(int64)44))) + int32((int64(t6633)*(int64)88))) + int32((int64(t6632)*(int64)264))) + int32((int64(t6631)*(int64)528))) + int32((int64(t6630)*(int64)1584))) + int32((int64(t6629)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6651 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6650 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6649 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6648 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6647 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6646 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B2_Bfirst_r2_i[((((((c11 + int32((int64(t6651)*(int64)44))) + int32((int64(t6650)*(int64)88))) + int32((int64(t6649)*(int64)264))) + int32((int64(t6648)*(int64)528))) + int32((int64(t6647)*(int64)1584))) + int32((int64(t6646)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6668 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6667 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6666 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6665 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6664 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6663 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B1_Bsecond_r2_r[((((((c11 + int32((int64(t6668)*(int64)44))) + int32((int64(t6667)*(int64)88))) + int32((int64(t6666)*(int64)264))) + int32((int64(t6665)*(int64)528))) + int32((int64(t6664)*(int64)1584))) + int32((int64(t6663)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6685 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6684 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6683 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6682 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6681 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6680 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B1_Bsecond_r2_i[((((((c11 + int32((int64(t6685)*(int64)44))) + int32((int64(t6684)*(int64)88))) + int32((int64(t6683)*(int64)264))) + int32((int64(t6682)*(int64)528))) + int32((int64(t6681)*(int64)1584))) + int32((int64(t6680)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6702 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6701 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6700 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6699 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6698 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6697 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B2_Bsecond_r2_r[((((((c11 + int32((int64(t6702)*(int64)44))) + int32((int64(t6701)*(int64)88))) + int32((int64(t6700)*(int64)264))) + int32((int64(t6699)*(int64)528))) + int32((int64(t6698)*(int64)1584))) + int32((int64(t6697)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6719 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6718 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6717 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6716 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6715 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6714 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B2_Bsecond_r2_i[((((((c11 + int32((int64(t6719)*(int64)44))) + int32((int64(t6718)*(int64)88))) + int32((int64(t6717)*(int64)264))) + int32((int64(t6716)*(int64)528))) + int32((int64(t6715)*(int64)1584))) + int32((int64(t6714)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6736 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6735 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6734 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6733 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6732 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6731 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B1_Bthird_r2_r[((((((c11 + int32((int64(t6736)*(int64)44))) + int32((int64(t6735)*(int64)88))) + int32((int64(t6734)*(int64)264))) + int32((int64(t6733)*(int64)528))) + int32((int64(t6732)*(int64)1584))) + int32((int64(t6731)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 0) && (_snk_b_b23[((c17*6) + 3)] == 0)) && (_snk_b_b23[((c17*6) + 5)] == 1)))) {
                        let t6753 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6752 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6751 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6750 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6749 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6748 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B1_Bthird_r2_i[((((((c11 + int32((int64(t6753)*(int64)44))) + int32((int64(t6752)*(int64)88))) + int32((int64(t6751)*(int64)264))) + int32((int64(t6750)*(int64)528))) + int32((int64(t6749)*(int64)1584))) + int32((int64(t6748)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6770 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6769 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6768 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6767 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6766 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6765 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_r[0] = buf_flip_B2_Bthird_r2_r[((((((c11 + int32((int64(t6770)*(int64)44))) + int32((int64(t6769)*(int64)88))) + int32((int64(t6768)*(int64)264))) + int32((int64(t6767)*(int64)528))) + int32((int64(t6766)*(int64)1584))) + int32((int64(t6765)*(int64)3168)))]
                      }
                      if (((_src_spins_b20[(((c15*2) + (c9*4)) + 1)] == 2) && (((_snk_b_b23[((c17*6) + 1)] == 1) && (_snk_b_b23[((c17*6) + 3)] == 1)) && (_snk_b_b23[((c17*6) + 5)] == 0)))) {
                        let t6787 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6786 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 3)]
                        let t6785 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6784 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 5)]
                        let t6783 = _snk_spin_weights_b28[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        let t6782 = _snk_color_weights_b27[((((c19*6) + (c17*1728)) + (c13*62208)) + 1)]
                        buf_flip_BB_BB_new_term_b2_i[0] = buf_flip_B2_Bthird_r2_i[((((((c11 + int32((int64(t6787)*(int64)44))) + int32((int64(t6786)*(int64)88))) + int32((int64(t6785)*(int64)264))) + int32((int64(t6784)*(int64)528))) + int32((int64(t6783)*(int64)1584))) + int32((int64(t6782)*(int64)3168)))]
                      }
                      buf_C_BB_BB_prop_r[0] = (let t296 = ((float64(_sigs_b22[c17])*_snk_weights_b29[(c19 + (c13*288))])*_src_spin_block_weights_b21[(c15 + (c9*2))]) in (buf_C_BB_BB_prop_r[0] + (((((t296*buf_BB_BB_new_term_b1_r[0])*buf_BB_BB_new_term_b2_r[0]) - ((t296*buf_BB_BB_new_term_b1_i[0])*buf_BB_BB_new_term_b2_i[0])) + (((t296*buf_flip_BB_BB_new_term_b1_r[0])*buf_flip_BB_BB_new_term_b2_r[0]) - ((t296*buf_flip_BB_BB_new_term_b1_i[0])*buf_flip_BB_BB_new_term_b2_i[0])))*0.500000)))
                      buf_C_BB_BB_prop_i[0] = (let t297 = ((float64(_sigs_b22[c17])*_snk_weights_b29[(c19 + (c13*288))])*_src_spin_block_weights_b21[(c15 + (c9*2))]) in (buf_C_BB_BB_prop_i[0] + (((((t297*buf_BB_BB_new_term_b1_r[0])*buf_BB_BB_new_term_b2_i[0]) + ((t297*buf_BB_BB_new_term_b1_i[0])*buf_BB_BB_new_term_b2_r[0])) + (((t297*buf_flip_BB_BB_new_term_b1_r[0])*buf_flip_BB_BB_new_term_b2_i[0]) + ((t297*buf_flip_BB_BB_new_term_b1_i[0])*buf_flip_BB_BB_new_term_b2_r[0])))*0.500000)))
                    }
                  }
                }
                for (c15, 0, 3) {
                  buf_C_r[((((((c15 + int32((int64(c13)*(int64)46))) + int32((int64(c11)*(int64)184))) + int32((int64(c9)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = (let t298 = ((c15 + (c7*3)) + (((c3*2) + c5)*12)) in (buf_C_r[((((((c15 + int32((int64(c13)*(int64)46))) + int32((int64(c11)*(int64)184))) + int32((int64(c9)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] + ((_snk_psi_r_b18[t298]*buf_C_BB_BB_prop_r[0]) - (_snk_psi_i_b19[t298]*buf_C_BB_BB_prop_i[0]))))
                  buf_C_i[((((((c15 + int32((int64(c13)*(int64)46))) + int32((int64(c11)*(int64)184))) + int32((int64(c9)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = (let t299 = ((c15 + (c7*3)) + (((c3*2) + c5)*12)) in (buf_C_i[((((((c15 + int32((int64(c13)*(int64)46))) + int32((int64(c11)*(int64)184))) + int32((int64(c9)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] + ((_snk_psi_r_b18[t299]*buf_C_BB_BB_prop_i[0]) + (_snk_psi_i_b19[t299]*buf_C_BB_BB_prop_r[0]))))
                }
                for (c15, 0, 41) {
                  buf_C_r[((((((int32((int64(c15) + (int64)3)) + int32((int64(c13)*(int64)46))) + int32((int64(c11)*(int64)184))) + int32((int64(c9)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = (let t300 = (c15 + (((c3*2) + c5)*44)) in (let t301 = _snk_psi_B1_r_b10[(t300 + 3)] in (let t302 = (c15 + (c7*44)) in (let t303 = _snk_psi_B2_r_b12[(t302 + 3)] in (let t304 = _snk_psi_B1_i_b11[(t300 + 3)] in (let t305 = _snk_psi_B2_i_b13[(t302 + 3)] in (let t306 = _snk_psi_B1_r_b10[(t302 + 3)] in (let t307 = _snk_psi_B2_r_b12[(t300 + 3)] in (let t308 = _snk_psi_B1_i_b11[(t302 + 3)] in (let t309 = _snk_psi_B2_i_b13[(t300 + 3)] in (buf_C_r[((((((int32((int64(c15) + (int64)3)) + int32((int64(c13)*(int64)46))) + int32((int64(c11)*(int64)184))) + int32((int64(c9)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] + (((((t301*t303) - (t304*t305)) + ((t306*t307) - (t308*t309)))*buf_C_BB_BB_prop_r[0]) - ((((t301*t305) + (t304*t303)) + ((t306*t309) + (t308*t307)))*buf_C_BB_BB_prop_i[0])))))))))))))
                  buf_C_i[((((((int32((int64(c15) + (int64)3)) + int32((int64(c13)*(int64)46))) + int32((int64(c11)*(int64)184))) + int32((int64(c9)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = (let t310 = (c15 + (((c3*2) + c5)*44)) in (let t311 = _snk_psi_B1_r_b10[(t310 + 3)] in (let t312 = (c15 + (c7*44)) in (let t313 = _snk_psi_B2_r_b12[(t312 + 3)] in (let t314 = _snk_psi_B1_i_b11[(t310 + 3)] in (let t315 = _snk_psi_B2_i_b13[(t312 + 3)] in (let t316 = _snk_psi_B1_r_b10[(t312 + 3)] in (let t317 = _snk_psi_B2_r_b12[(t310 + 3)] in (let t318 = _snk_psi_B1_i_b11[(t312 + 3)] in (let t319 = _snk_psi_B2_i_b13[(t310 + 3)] in (buf_C_i[((((((int32((int64(c15) + (int64)3)) + int32((int64(c13)*(int64)46))) + int32((int64(c11)*(int64)184))) + int32((int64(c9)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] + (((((t311*t313) - (t314*t315)) + ((t316*t317) - (t318*t319)))*buf_C_BB_BB_prop_i[0]) + ((((t311*t315) + (t314*t313)) + ((t316*t319) + (t318*t317)))*buf_C_BB_BB_prop_r[0])))))))))))))
                }
              }
            }
          }
        }
      }
    }
    for (c3, 0, 2) {
      for (c5, 0, 2) {
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 3) {
                  for (c17, 0, 2) {
                    for (c19, 0, 44) {
                      buf_src_B1_Blocal_r1_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_src_B1_Blocal_r1_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_src_B1_Blocal_r1_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_src_B1_Blocal_r1_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 4) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      buf_src_B1_Blocal_props_r1_r[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                      buf_src_B1_Blocal_props_r1_i[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                    }
                  }
                  for (c17, 0, 12) {
                    let t3208 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3207 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3206 = _src_spin_weights_b25[(c17*3)]
                    let t3205 = _src_color_weights_b24[(c17*3)]
                    let t3204 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3203 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3202 = _src_spin_weights_b25[(c17*3)]
                    let t3201 = _src_color_weights_b24[(c17*3)]
                    buf_src_B1_Blocal_diquark_r1_r[0] = (let t320 = (c15 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t320 + (t3202*16)) + (t3201*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B1_prop_r_b2[((((((t320 + (t3204*16)) + (t3203*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t320 + (t3206*16)) + (t3205*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B1_prop_i_b3[((((((t320 + (t3208*16)) + (t3207*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c17]))
                    let t3226 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3225 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3224 = _src_spin_weights_b25[(c17*3)]
                    let t3223 = _src_color_weights_b24[(c17*3)]
                    let t3222 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3221 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3220 = _src_spin_weights_b25[(c17*3)]
                    let t3219 = _src_color_weights_b24[(c17*3)]
                    buf_src_B1_Blocal_diquark_r1_i[0] = (let t321 = (c15 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t321 + (t3220*16)) + (t3219*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B1_prop_i_b3[((((((t321 + (t3222*16)) + (t3221*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t321 + (t3224*16)) + (t3223*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B1_prop_r_b2[((((((t321 + (t3226*16)) + (t3225*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c17]))
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        let t3240 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3239 = _src_color_weights_b24[((c17*3) + 1)]
                        let t3238 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3237 = _src_color_weights_b24[((c17*3) + 1)]
                        buf_src_B1_Blocal_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = (let t322 = (c15 + (((c3*2) + c5)*4)) in (buf_src_B1_Blocal_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] + ((_B1_prop_r_b2[((((((t322 + (t3238*16)) + (t3237*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B1_Blocal_diquark_r1_r[0]) - (_B1_prop_i_b3[((((((t322 + (t3240*16)) + (t3239*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B1_Blocal_diquark_r1_i[0]))))
                        let t3256 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3255 = _src_color_weights_b24[((c17*3) + 1)]
                        let t3254 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3253 = _src_color_weights_b24[((c17*3) + 1)]
                        buf_src_B1_Blocal_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = (let t323 = (c15 + (((c3*2) + c5)*4)) in (buf_src_B1_Blocal_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] + ((_B1_prop_r_b2[((((((t323 + (t3254*16)) + (t3253*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B1_Blocal_diquark_r1_i[0]) + (_B1_prop_i_b3[((((((t323 + (t3256*16)) + (t3255*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B1_Blocal_diquark_r1_r[0]))))
                      }
                    }
                  }
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_src_B1_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t324 = (c21 + (c15*44)) in (let t325 = (c19 + int32((int64(c17)*(int64)2))) in (buf_src_B1_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B1_r_b6[t324]*buf_src_B1_Blocal_props_r1_r[t325]) - (_src_psi_B1_i_b7[t324]*buf_src_B1_Blocal_props_r1_i[t325])))))
                        buf_src_B1_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t326 = (c21 + (c15*44)) in (let t327 = (c19 + int32((int64(c17)*(int64)2))) in (buf_src_B1_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B1_r_b6[t326]*buf_src_B1_Blocal_props_r1_i[t327]) + (_src_psi_B1_i_b7[t326]*buf_src_B1_Blocal_props_r1_r[t327])))))
                        buf_flip_src_B1_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t328 = (c21 + (c15*44)) in (let t329 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_src_B1_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B2_r_b8[t328]*buf_src_B1_Blocal_props_r1_r[t329]) - (_src_psi_B2_i_b9[t328]*buf_src_B1_Blocal_props_r1_i[t329])))))
                        buf_flip_src_B1_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t330 = (c21 + (c15*44)) in (let t331 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_src_B1_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B2_r_b8[t330]*buf_src_B1_Blocal_props_r1_i[t331]) + (_src_psi_B2_i_b9[t330]*buf_src_B1_Blocal_props_r1_r[t331])))))
                      }
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 3) {
                  for (c17, 0, 2) {
                    for (c19, 0, 44) {
                      buf_src_B1_Blocal_r2_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_src_B1_Blocal_r2_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_src_B1_Blocal_r2_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_src_B1_Blocal_r2_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 4) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      buf_src_B1_Blocal_props_r2_r[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                      buf_src_B1_Blocal_props_r2_i[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                    }
                  }
                  for (c17, 0, 12) {
                    let t3390 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t3389 = _src_color_weights_b24[((c17*3) + 38)]
                    let t3388 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t3387 = _src_color_weights_b24[((c17*3) + 36)]
                    let t3386 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t3385 = _src_color_weights_b24[((c17*3) + 38)]
                    let t3384 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t3383 = _src_color_weights_b24[((c17*3) + 36)]
                    buf_src_B1_Blocal_diquark_r2_r[0] = (let t332 = (c15 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t332 + (t3384*16)) + (t3383*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B1_prop_r_b2[((((((t332 + (t3386*16)) + (t3385*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t332 + (t3388*16)) + (t3387*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B1_prop_i_b3[((((((t332 + (t3390*16)) + (t3389*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c17 + 12)]))
                    let t3408 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t3407 = _src_color_weights_b24[((c17*3) + 38)]
                    let t3406 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t3405 = _src_color_weights_b24[((c17*3) + 36)]
                    let t3404 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t3403 = _src_color_weights_b24[((c17*3) + 38)]
                    let t3402 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t3401 = _src_color_weights_b24[((c17*3) + 36)]
                    buf_src_B1_Blocal_diquark_r2_i[0] = (let t333 = (c15 + (((c3*2) + c5)*4)) in (((_B1_prop_r_b2[(((((t333 + (t3402*16)) + (t3401*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B1_prop_i_b3[((((((t333 + (t3404*16)) + (t3403*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t333 + (t3406*16)) + (t3405*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B1_prop_r_b2[((((((t333 + (t3408*16)) + (t3407*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c17 + 12)]))
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        let t3422 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t3421 = _src_color_weights_b24[((c17*3) + 37)]
                        let t3420 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t3419 = _src_color_weights_b24[((c17*3) + 37)]
                        buf_src_B1_Blocal_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = (let t334 = (c15 + (((c3*2) + c5)*4)) in (buf_src_B1_Blocal_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] + ((_B1_prop_r_b2[((((((t334 + (t3420*16)) + (t3419*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B1_Blocal_diquark_r2_r[0]) - (_B1_prop_i_b3[((((((t334 + (t3422*16)) + (t3421*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B1_Blocal_diquark_r2_i[0]))))
                        let t3438 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t3437 = _src_color_weights_b24[((c17*3) + 37)]
                        let t3436 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t3435 = _src_color_weights_b24[((c17*3) + 37)]
                        buf_src_B1_Blocal_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = (let t335 = (c15 + (((c3*2) + c5)*4)) in (buf_src_B1_Blocal_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] + ((_B1_prop_r_b2[((((((t335 + (t3436*16)) + (t3435*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B1_Blocal_diquark_r2_i[0]) + (_B1_prop_i_b3[((((((t335 + (t3438*16)) + (t3437*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B1_Blocal_diquark_r2_r[0]))))
                      }
                    }
                  }
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_src_B1_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t336 = (c21 + (c15*44)) in (let t337 = (c19 + int32((int64(c17)*(int64)2))) in (buf_src_B1_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B1_r_b6[t336]*buf_src_B1_Blocal_props_r2_r[t337]) - (_src_psi_B1_i_b7[t336]*buf_src_B1_Blocal_props_r2_i[t337])))))
                        buf_src_B1_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t338 = (c21 + (c15*44)) in (let t339 = (c19 + int32((int64(c17)*(int64)2))) in (buf_src_B1_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B1_r_b6[t338]*buf_src_B1_Blocal_props_r2_i[t339]) + (_src_psi_B1_i_b7[t338]*buf_src_B1_Blocal_props_r2_r[t339])))))
                        buf_flip_src_B1_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t340 = (c21 + (c15*44)) in (let t341 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_src_B1_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B2_r_b8[t340]*buf_src_B1_Blocal_props_r2_r[t341]) - (_src_psi_B2_i_b9[t340]*buf_src_B1_Blocal_props_r2_i[t341])))))
                        buf_flip_src_B1_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t342 = (c21 + (c15*44)) in (let t343 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_src_B1_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B2_r_b8[t342]*buf_src_B1_Blocal_props_r2_i[t343]) + (_src_psi_B2_i_b9[t342]*buf_src_B1_Blocal_props_r2_r[t343])))))
                      }
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 3) {
                  for (c17, 0, 2) {
                    for (c19, 0, 44) {
                      buf_src_B2_Blocal_r1_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_src_B2_Blocal_r1_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_src_B2_Blocal_r1_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_src_B2_Blocal_r1_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 4) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      buf_src_B2_Blocal_props_r1_r[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                      buf_src_B2_Blocal_props_r1_i[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                    }
                  }
                  for (c17, 0, 12) {
                    let t3572 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3571 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3570 = _src_spin_weights_b25[(c17*3)]
                    let t3569 = _src_color_weights_b24[(c17*3)]
                    let t3568 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3567 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3566 = _src_spin_weights_b25[(c17*3)]
                    let t3565 = _src_color_weights_b24[(c17*3)]
                    buf_src_B2_Blocal_diquark_r1_r[0] = (let t344 = (c15 + (((c3*2) + c5)*4)) in (((_B2_prop_r_b4[(((((t344 + (t3566*16)) + (t3565*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B2_prop_r_b4[((((((t344 + (t3568*16)) + (t3567*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t344 + (t3570*16)) + (t3569*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B2_prop_i_b5[((((((t344 + (t3572*16)) + (t3571*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c17]))
                    let t3590 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3589 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3588 = _src_spin_weights_b25[(c17*3)]
                    let t3587 = _src_color_weights_b24[(c17*3)]
                    let t3586 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3585 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3584 = _src_spin_weights_b25[(c17*3)]
                    let t3583 = _src_color_weights_b24[(c17*3)]
                    buf_src_B2_Blocal_diquark_r1_i[0] = (let t345 = (c15 + (((c3*2) + c5)*4)) in (((_B2_prop_r_b4[(((((t345 + (t3584*16)) + (t3583*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B2_prop_i_b5[((((((t345 + (t3586*16)) + (t3585*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t345 + (t3588*16)) + (t3587*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B2_prop_r_b4[((((((t345 + (t3590*16)) + (t3589*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c17]))
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        let t3604 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3603 = _src_color_weights_b24[((c17*3) + 1)]
                        let t3602 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3601 = _src_color_weights_b24[((c17*3) + 1)]
                        buf_src_B2_Blocal_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = (let t346 = (c15 + (((c3*2) + c5)*4)) in (buf_src_B2_Blocal_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] + ((_B2_prop_r_b4[((((((t346 + (t3602*16)) + (t3601*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B2_Blocal_diquark_r1_r[0]) - (_B2_prop_i_b5[((((((t346 + (t3604*16)) + (t3603*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B2_Blocal_diquark_r1_i[0]))))
                        let t3620 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3619 = _src_color_weights_b24[((c17*3) + 1)]
                        let t3618 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3617 = _src_color_weights_b24[((c17*3) + 1)]
                        buf_src_B2_Blocal_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = (let t347 = (c15 + (((c3*2) + c5)*4)) in (buf_src_B2_Blocal_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] + ((_B2_prop_r_b4[((((((t347 + (t3618*16)) + (t3617*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B2_Blocal_diquark_r1_i[0]) + (_B2_prop_i_b5[((((((t347 + (t3620*16)) + (t3619*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B2_Blocal_diquark_r1_r[0]))))
                      }
                    }
                  }
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_src_B2_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t348 = (c21 + (c15*44)) in (let t349 = (c19 + int32((int64(c17)*(int64)2))) in (buf_src_B2_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B2_r_b8[t348]*buf_src_B2_Blocal_props_r1_r[t349]) - (_src_psi_B2_i_b9[t348]*buf_src_B2_Blocal_props_r1_i[t349])))))
                        buf_src_B2_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t350 = (c21 + (c15*44)) in (let t351 = (c19 + int32((int64(c17)*(int64)2))) in (buf_src_B2_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B2_r_b8[t350]*buf_src_B2_Blocal_props_r1_i[t351]) + (_src_psi_B2_i_b9[t350]*buf_src_B2_Blocal_props_r1_r[t351])))))
                        buf_flip_src_B2_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t352 = (c21 + (c15*44)) in (let t353 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_src_B2_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B1_r_b6[t352]*buf_src_B2_Blocal_props_r1_r[t353]) - (_src_psi_B1_i_b7[t352]*buf_src_B2_Blocal_props_r1_i[t353])))))
                        buf_flip_src_B2_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t354 = (c21 + (c15*44)) in (let t355 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_src_B2_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B1_r_b6[t354]*buf_src_B2_Blocal_props_r1_i[t355]) + (_src_psi_B1_i_b7[t354]*buf_src_B2_Blocal_props_r1_r[t355])))))
                      }
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 3) {
                  for (c17, 0, 2) {
                    for (c19, 0, 44) {
                      buf_src_B2_Blocal_r2_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_src_B2_Blocal_r2_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_src_B2_Blocal_r2_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_src_B2_Blocal_r2_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 4) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      buf_src_B2_Blocal_props_r2_r[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                      buf_src_B2_Blocal_props_r2_i[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                    }
                  }
                  for (c17, 0, 12) {
                    let t3754 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t3753 = _src_color_weights_b24[((c17*3) + 38)]
                    let t3752 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t3751 = _src_color_weights_b24[((c17*3) + 36)]
                    let t3750 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t3749 = _src_color_weights_b24[((c17*3) + 38)]
                    let t3748 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t3747 = _src_color_weights_b24[((c17*3) + 36)]
                    buf_src_B2_Blocal_diquark_r2_r[0] = (let t356 = (c15 + (((c3*2) + c5)*4)) in (((_B2_prop_r_b4[(((((t356 + (t3748*16)) + (t3747*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B2_prop_r_b4[((((((t356 + (t3750*16)) + (t3749*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t356 + (t3752*16)) + (t3751*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B2_prop_i_b5[((((((t356 + (t3754*16)) + (t3753*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c17 + 12)]))
                    let t3772 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t3771 = _src_color_weights_b24[((c17*3) + 38)]
                    let t3770 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t3769 = _src_color_weights_b24[((c17*3) + 36)]
                    let t3768 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t3767 = _src_color_weights_b24[((c17*3) + 38)]
                    let t3766 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t3765 = _src_color_weights_b24[((c17*3) + 36)]
                    buf_src_B2_Blocal_diquark_r2_i[0] = (let t357 = (c15 + (((c3*2) + c5)*4)) in (((_B2_prop_r_b4[(((((t357 + (t3766*16)) + (t3765*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B2_prop_i_b5[((((((t357 + (t3768*16)) + (t3767*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t357 + (t3770*16)) + (t3769*32)) + (c9*96)) + (c7*192)) + (c1*576))]*_B2_prop_r_b4[((((((t357 + (t3772*16)) + (t3771*32)) + (c13*96)) + (c11*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c17 + 12)]))
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        let t3786 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t3785 = _src_color_weights_b24[((c17*3) + 37)]
                        let t3784 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t3783 = _src_color_weights_b24[((c17*3) + 37)]
                        buf_src_B2_Blocal_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = (let t358 = (c15 + (((c3*2) + c5)*4)) in (buf_src_B2_Blocal_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] + ((_B2_prop_r_b4[((((((t358 + (t3784*16)) + (t3783*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B2_Blocal_diquark_r2_r[0]) - (_B2_prop_i_b5[((((((t358 + (t3786*16)) + (t3785*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B2_Blocal_diquark_r2_i[0]))))
                        let t3802 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t3801 = _src_color_weights_b24[((c17*3) + 37)]
                        let t3800 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t3799 = _src_color_weights_b24[((c17*3) + 37)]
                        buf_src_B2_Blocal_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = (let t359 = (c15 + (((c3*2) + c5)*4)) in (buf_src_B2_Blocal_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] + ((_B2_prop_r_b4[((((((t359 + (t3800*16)) + (t3799*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B2_Blocal_diquark_r2_i[0]) + (_B2_prop_i_b5[((((((t359 + (t3802*16)) + (t3801*32)) + (c21*96)) + (c19*192)) + (c1*576)) + 1152)]*buf_src_B2_Blocal_diquark_r2_r[0]))))
                      }
                    }
                  }
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_src_B2_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t360 = (c21 + (c15*44)) in (let t361 = (c19 + int32((int64(c17)*(int64)2))) in (buf_src_B2_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B2_r_b8[t360]*buf_src_B2_Blocal_props_r2_r[t361]) - (_src_psi_B2_i_b9[t360]*buf_src_B2_Blocal_props_r2_i[t361])))))
                        buf_src_B2_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t362 = (c21 + (c15*44)) in (let t363 = (c19 + int32((int64(c17)*(int64)2))) in (buf_src_B2_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B2_r_b8[t362]*buf_src_B2_Blocal_props_r2_i[t363]) + (_src_psi_B2_i_b9[t362]*buf_src_B2_Blocal_props_r2_r[t363])))))
                        buf_flip_src_B2_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t364 = (c21 + (c15*44)) in (let t365 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_src_B2_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B1_r_b6[t364]*buf_src_B2_Blocal_props_r2_r[t365]) - (_src_psi_B1_i_b7[t364]*buf_src_B2_Blocal_props_r2_i[t365])))))
                        buf_flip_src_B2_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t366 = (c21 + (c15*44)) in (let t367 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_src_B2_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_src_psi_B1_r_b6[t366]*buf_src_B2_Blocal_props_r2_i[t367]) + (_src_psi_B1_i_b7[t366]*buf_src_B2_Blocal_props_r2_r[t367])))))
                      }
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 4) {
          for (c9, 0, 44) {
            for (c11, 0, 4) {
              buf_C_BB_H_prop_r[0] = 0.000000
              buf_C_BB_H_prop_i[0] = 0.000000
              for (c13, 0, 2) {
                for (c15, 0, 36) {
                  for (c17, 0, 32) {
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 1)) {
                      let t6876 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t6875 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t6874 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t6873 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t6872 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t6871 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_BB_H_new_term_b1_r[0] = buf_src_B1_Blocal_r1_r[((((((c9 + int32((int64(t6876)*(int64)44))) + int32((int64(t6875)*(int64)88))) + int32((int64(t6874)*(int64)264))) + int32((int64(t6873)*(int64)528))) + int32((int64(t6872)*(int64)1584))) + int32((int64(t6871)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 1)) {
                      let t6892 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t6891 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t6890 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t6889 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t6888 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t6887 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_BB_H_new_term_b1_i[0] = buf_src_B1_Blocal_r1_i[((((((c9 + int32((int64(t6892)*(int64)44))) + int32((int64(t6891)*(int64)88))) + int32((int64(t6890)*(int64)264))) + int32((int64(t6889)*(int64)528))) + int32((int64(t6888)*(int64)1584))) + int32((int64(t6887)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 2)) {
                      let t6908 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t6907 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t6906 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t6905 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t6904 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t6903 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_BB_H_new_term_b1_r[0] = buf_src_B1_Blocal_r2_r[((((((c9 + int32((int64(t6908)*(int64)44))) + int32((int64(t6907)*(int64)88))) + int32((int64(t6906)*(int64)264))) + int32((int64(t6905)*(int64)528))) + int32((int64(t6904)*(int64)1584))) + int32((int64(t6903)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 2)) {
                      let t6924 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t6923 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t6922 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t6921 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t6920 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t6919 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_BB_H_new_term_b1_i[0] = buf_src_B1_Blocal_r2_i[((((((c9 + int32((int64(t6924)*(int64)44))) + int32((int64(t6923)*(int64)88))) + int32((int64(t6922)*(int64)264))) + int32((int64(t6921)*(int64)528))) + int32((int64(t6920)*(int64)1584))) + int32((int64(t6919)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 1)) {
                      let t6940 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t6939 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t6938 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t6937 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t6936 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t6935 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_BB_H_new_term_b2_r[0] = buf_src_B2_Blocal_r1_r[((((((c9 + int32((int64(t6940)*(int64)44))) + int32((int64(t6939)*(int64)88))) + int32((int64(t6938)*(int64)264))) + int32((int64(t6937)*(int64)528))) + int32((int64(t6936)*(int64)1584))) + int32((int64(t6935)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 1)) {
                      let t6956 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t6955 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t6954 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t6953 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t6952 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t6951 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_BB_H_new_term_b2_i[0] = buf_src_B2_Blocal_r1_i[((((((c9 + int32((int64(t6956)*(int64)44))) + int32((int64(t6955)*(int64)88))) + int32((int64(t6954)*(int64)264))) + int32((int64(t6953)*(int64)528))) + int32((int64(t6952)*(int64)1584))) + int32((int64(t6951)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 2)) {
                      let t6972 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t6971 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t6970 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t6969 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t6968 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t6967 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_BB_H_new_term_b2_r[0] = buf_src_B2_Blocal_r2_r[((((((c9 + int32((int64(t6972)*(int64)44))) + int32((int64(t6971)*(int64)88))) + int32((int64(t6970)*(int64)264))) + int32((int64(t6969)*(int64)528))) + int32((int64(t6968)*(int64)1584))) + int32((int64(t6967)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 2)) {
                      let t6988 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t6987 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t6986 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t6985 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t6984 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t6983 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_BB_H_new_term_b2_i[0] = buf_src_B2_Blocal_r2_i[((((((c9 + int32((int64(t6988)*(int64)44))) + int32((int64(t6987)*(int64)88))) + int32((int64(t6986)*(int64)264))) + int32((int64(t6985)*(int64)528))) + int32((int64(t6984)*(int64)1584))) + int32((int64(t6983)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 1)) {
                      let t7004 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7003 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7002 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7001 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7000 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t6999 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_flip_BB_H_new_term_b1_r[0] = buf_flip_src_B1_Blocal_r1_r[((((((c9 + int32((int64(t7004)*(int64)44))) + int32((int64(t7003)*(int64)88))) + int32((int64(t7002)*(int64)264))) + int32((int64(t7001)*(int64)528))) + int32((int64(t7000)*(int64)1584))) + int32((int64(t6999)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 1)) {
                      let t7020 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7019 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7018 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7017 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7016 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7015 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_flip_BB_H_new_term_b1_i[0] = buf_flip_src_B1_Blocal_r1_i[((((((c9 + int32((int64(t7020)*(int64)44))) + int32((int64(t7019)*(int64)88))) + int32((int64(t7018)*(int64)264))) + int32((int64(t7017)*(int64)528))) + int32((int64(t7016)*(int64)1584))) + int32((int64(t7015)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 2)) {
                      let t7036 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7035 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7034 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7033 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7032 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7031 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_flip_BB_H_new_term_b1_r[0] = buf_flip_src_B1_Blocal_r2_r[((((((c9 + int32((int64(t7036)*(int64)44))) + int32((int64(t7035)*(int64)88))) + int32((int64(t7034)*(int64)264))) + int32((int64(t7033)*(int64)528))) + int32((int64(t7032)*(int64)1584))) + int32((int64(t7031)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 2)) {
                      let t7052 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7051 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7050 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7049 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7048 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7047 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_flip_BB_H_new_term_b1_i[0] = buf_flip_src_B1_Blocal_r2_i[((((((c9 + int32((int64(t7052)*(int64)44))) + int32((int64(t7051)*(int64)88))) + int32((int64(t7050)*(int64)264))) + int32((int64(t7049)*(int64)528))) + int32((int64(t7048)*(int64)1584))) + int32((int64(t7047)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 1)) {
                      let t7068 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7067 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7066 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7065 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7064 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7063 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_flip_BB_H_new_term_b2_r[0] = buf_flip_src_B2_Blocal_r1_r[((((((c9 + int32((int64(t7068)*(int64)44))) + int32((int64(t7067)*(int64)88))) + int32((int64(t7066)*(int64)264))) + int32((int64(t7065)*(int64)528))) + int32((int64(t7064)*(int64)1584))) + int32((int64(t7063)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 1)) {
                      let t7084 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7083 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7082 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7081 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7080 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7079 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_flip_BB_H_new_term_b2_i[0] = buf_flip_src_B2_Blocal_r1_i[((((((c9 + int32((int64(t7084)*(int64)44))) + int32((int64(t7083)*(int64)88))) + int32((int64(t7082)*(int64)264))) + int32((int64(t7081)*(int64)528))) + int32((int64(t7080)*(int64)1584))) + int32((int64(t7079)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 2)) {
                      let t7100 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7099 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7098 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7097 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7096 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7095 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_flip_BB_H_new_term_b2_r[0] = buf_flip_src_B2_Blocal_r2_r[((((((c9 + int32((int64(t7100)*(int64)44))) + int32((int64(t7099)*(int64)88))) + int32((int64(t7098)*(int64)264))) + int32((int64(t7097)*(int64)528))) + int32((int64(t7096)*(int64)1584))) + int32((int64(t7095)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 2)) {
                      let t7116 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7115 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7114 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7113 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7112 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7111 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_flip_BB_H_new_term_b2_i[0] = buf_flip_src_B2_Blocal_r2_i[((((((c9 + int32((int64(t7116)*(int64)44))) + int32((int64(t7115)*(int64)88))) + int32((int64(t7114)*(int64)264))) + int32((int64(t7113)*(int64)528))) + int32((int64(t7112)*(int64)1584))) + int32((int64(t7111)*(int64)3168)))]
                    }
                    buf_C_BB_H_prop_r[0] = (let t368 = ((float64(_sigs_b22[c15])*_hex_snk_weights_b32[(c17 + (c11*32))])*_src_spin_block_weights_b21[(c13 + (c7*2))]) in (buf_C_BB_H_prop_r[0] + (((((t368*buf_BB_H_new_term_b1_r[0])*buf_BB_H_new_term_b2_r[0]) - ((t368*buf_BB_H_new_term_b1_i[0])*buf_BB_H_new_term_b2_i[0])) + (((t368*buf_flip_BB_H_new_term_b1_r[0])*buf_flip_BB_H_new_term_b2_r[0]) - ((t368*buf_flip_BB_H_new_term_b1_i[0])*buf_flip_BB_H_new_term_b2_i[0])))*0.500000)))
                    buf_C_BB_H_prop_i[0] = (let t369 = ((float64(_sigs_b22[c15])*_hex_snk_weights_b32[(c17 + (c11*32))])*_src_spin_block_weights_b21[(c13 + (c7*2))]) in (buf_C_BB_H_prop_i[0] + (((((t369*buf_BB_H_new_term_b1_r[0])*buf_BB_H_new_term_b2_i[0]) + ((t369*buf_BB_H_new_term_b1_i[0])*buf_BB_H_new_term_b2_r[0])) + (((t369*buf_flip_BB_H_new_term_b1_r[0])*buf_flip_BB_H_new_term_b2_i[0]) + ((t369*buf_flip_BB_H_new_term_b1_i[0])*buf_flip_BB_H_new_term_b2_r[0])))*0.500000)))
                  }
                }
              }
              for (c13, 0, 2) {
                buf_C_r[((((((int32((int64(c13) + (int64)44)) + int32((int64(c11)*(int64)46))) + int32((int64(c9)*(int64)184))) + int32((int64(c7)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = (let t370 = (c13 + (((c3*2) + c5)*2)) in (buf_C_r[((((((int32((int64(c13) + (int64)44)) + int32((int64(c11)*(int64)46))) + int32((int64(c9)*(int64)184))) + int32((int64(c7)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] + ((_hex_snk_psi_r_b16[t370]*buf_C_BB_H_prop_r[0]) - (_hex_snk_psi_i_b17[t370]*buf_C_BB_H_prop_i[0]))))
                buf_C_i[((((((int32((int64(c13) + (int64)44)) + int32((int64(c11)*(int64)46))) + int32((int64(c9)*(int64)184))) + int32((int64(c7)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = (let t371 = (c13 + (((c3*2) + c5)*2)) in (buf_C_i[((((((int32((int64(c13) + (int64)44)) + int32((int64(c11)*(int64)46))) + int32((int64(c9)*(int64)184))) + int32((int64(c7)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] + ((_hex_snk_psi_r_b16[t371]*buf_C_BB_H_prop_i[0]) + (_hex_snk_psi_i_b17[t371]*buf_C_BB_H_prop_r[0]))))
              }
            }
          }
        }
      }
    }
    for (c3, 0, 2) {
      for (c5, 0, 2) {
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 3) {
                  for (c17, 0, 2) {
                    for (c19, 0, 44) {
                      buf_snk_B1_Blocal_r1_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_snk_B1_Blocal_r1_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_snk_B1_Blocal_r1_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_snk_B1_Blocal_r1_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 4) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      buf_snk_B1_Blocal_props_r1_r[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                      buf_snk_B1_Blocal_props_r1_i[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                    }
                  }
                  for (c17, 0, 12) {
                    let t3936 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3935 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3934 = _src_spin_weights_b25[(c17*3)]
                    let t3933 = _src_color_weights_b24[(c17*3)]
                    let t3932 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3931 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3930 = _src_spin_weights_b25[(c17*3)]
                    let t3929 = _src_color_weights_b24[(c17*3)]
                    buf_snk_B1_Blocal_diquark_r1_r[0] = (let t372 = (((c3*2) + c5) + (c15*4)) in (let t373 = ((t372 + (c9*16)) + (c7*32)) in (let t374 = ((t372 + (c13*16)) + (c11*32)) in (((_B1_prop_r_b2[(((t373 + (t3930*96)) + (t3929*192)) + (c1*576))]*_B1_prop_r_b2[((((t374 + (t3932*96)) + (t3931*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((t373 + (t3934*96)) + (t3933*192)) + (c1*576))]*_B1_prop_i_b3[((((t374 + (t3936*96)) + (t3935*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c17]))))
                    let t3954 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3953 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3952 = _src_spin_weights_b25[(c17*3)]
                    let t3951 = _src_color_weights_b24[(c17*3)]
                    let t3950 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t3949 = _src_color_weights_b24[((c17*3) + 2)]
                    let t3948 = _src_spin_weights_b25[(c17*3)]
                    let t3947 = _src_color_weights_b24[(c17*3)]
                    buf_snk_B1_Blocal_diquark_r1_i[0] = (let t375 = (((c3*2) + c5) + (c15*4)) in (let t376 = ((t375 + (c9*16)) + (c7*32)) in (let t377 = ((t375 + (c13*16)) + (c11*32)) in (((_B1_prop_r_b2[(((t376 + (t3948*96)) + (t3947*192)) + (c1*576))]*_B1_prop_i_b3[((((t377 + (t3950*96)) + (t3949*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((t376 + (t3952*96)) + (t3951*192)) + (c1*576))]*_B1_prop_r_b2[((((t377 + (t3954*96)) + (t3953*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c17]))))
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        let t3968 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3967 = _src_color_weights_b24[((c17*3) + 1)]
                        let t3966 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3965 = _src_color_weights_b24[((c17*3) + 1)]
                        buf_snk_B1_Blocal_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = (let t378 = (((((c3*2) + c5) + (c15*4)) + (c21*16)) + (c19*32)) in (buf_snk_B1_Blocal_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] + ((_B1_prop_r_b2[((((t378 + (t3966*96)) + (t3965*192)) + (c1*576)) + 1152)]*buf_snk_B1_Blocal_diquark_r1_r[0]) - (_B1_prop_i_b3[((((t378 + (t3968*96)) + (t3967*192)) + (c1*576)) + 1152)]*buf_snk_B1_Blocal_diquark_r1_i[0]))))
                        let t3984 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3983 = _src_color_weights_b24[((c17*3) + 1)]
                        let t3982 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t3981 = _src_color_weights_b24[((c17*3) + 1)]
                        buf_snk_B1_Blocal_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = (let t379 = (((((c3*2) + c5) + (c15*4)) + (c21*16)) + (c19*32)) in (buf_snk_B1_Blocal_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] + ((_B1_prop_r_b2[((((t379 + (t3982*96)) + (t3981*192)) + (c1*576)) + 1152)]*buf_snk_B1_Blocal_diquark_r1_i[0]) + (_B1_prop_i_b3[((((t379 + (t3984*96)) + (t3983*192)) + (c1*576)) + 1152)]*buf_snk_B1_Blocal_diquark_r1_r[0]))))
                      }
                    }
                  }
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_snk_B1_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t380 = (c21 + (c15*44)) in (let t381 = (c19 + int32((int64(c17)*(int64)2))) in (buf_snk_B1_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B1_r_b10[t380]*buf_snk_B1_Blocal_props_r1_r[t381]) - (_snk_psi_B1_i_b11[t380]*buf_snk_B1_Blocal_props_r1_i[t381])))))
                        buf_snk_B1_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t382 = (c21 + (c15*44)) in (let t383 = (c19 + int32((int64(c17)*(int64)2))) in (buf_snk_B1_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B1_r_b10[t382]*buf_snk_B1_Blocal_props_r1_i[t383]) + (_snk_psi_B1_i_b11[t382]*buf_snk_B1_Blocal_props_r1_r[t383])))))
                        buf_flip_snk_B1_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t384 = (c21 + (c15*44)) in (let t385 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_snk_B1_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B2_r_b12[t384]*buf_snk_B1_Blocal_props_r1_r[t385]) - (_snk_psi_B2_i_b13[t384]*buf_snk_B1_Blocal_props_r1_i[t385])))))
                        buf_flip_snk_B1_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t386 = (c21 + (c15*44)) in (let t387 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_snk_B1_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B2_r_b12[t386]*buf_snk_B1_Blocal_props_r1_i[t387]) + (_snk_psi_B2_i_b13[t386]*buf_snk_B1_Blocal_props_r1_r[t387])))))
                      }
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 3) {
                  for (c17, 0, 2) {
                    for (c19, 0, 44) {
                      buf_snk_B1_Blocal_r2_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_snk_B1_Blocal_r2_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_snk_B1_Blocal_r2_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_snk_B1_Blocal_r2_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 4) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      buf_snk_B1_Blocal_props_r2_r[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                      buf_snk_B1_Blocal_props_r2_i[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                    }
                  }
                  for (c17, 0, 12) {
                    let t4118 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t4117 = _src_color_weights_b24[((c17*3) + 38)]
                    let t4116 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t4115 = _src_color_weights_b24[((c17*3) + 36)]
                    let t4114 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t4113 = _src_color_weights_b24[((c17*3) + 38)]
                    let t4112 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t4111 = _src_color_weights_b24[((c17*3) + 36)]
                    buf_snk_B1_Blocal_diquark_r2_r[0] = (let t388 = (((c3*2) + c5) + (c15*4)) in (let t389 = ((t388 + (c9*16)) + (c7*32)) in (let t390 = ((t388 + (c13*16)) + (c11*32)) in (((_B1_prop_r_b2[(((t389 + (t4112*96)) + (t4111*192)) + (c1*576))]*_B1_prop_r_b2[((((t390 + (t4114*96)) + (t4113*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((t389 + (t4116*96)) + (t4115*192)) + (c1*576))]*_B1_prop_i_b3[((((t390 + (t4118*96)) + (t4117*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c17 + 12)]))))
                    let t4136 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t4135 = _src_color_weights_b24[((c17*3) + 38)]
                    let t4134 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t4133 = _src_color_weights_b24[((c17*3) + 36)]
                    let t4132 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t4131 = _src_color_weights_b24[((c17*3) + 38)]
                    let t4130 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t4129 = _src_color_weights_b24[((c17*3) + 36)]
                    buf_snk_B1_Blocal_diquark_r2_i[0] = (let t391 = (((c3*2) + c5) + (c15*4)) in (let t392 = ((t391 + (c9*16)) + (c7*32)) in (let t393 = ((t391 + (c13*16)) + (c11*32)) in (((_B1_prop_r_b2[(((t392 + (t4130*96)) + (t4129*192)) + (c1*576))]*_B1_prop_i_b3[((((t393 + (t4132*96)) + (t4131*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((t392 + (t4134*96)) + (t4133*192)) + (c1*576))]*_B1_prop_r_b2[((((t393 + (t4136*96)) + (t4135*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c17 + 12)]))))
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        let t4150 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t4149 = _src_color_weights_b24[((c17*3) + 37)]
                        let t4148 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t4147 = _src_color_weights_b24[((c17*3) + 37)]
                        buf_snk_B1_Blocal_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = (let t394 = (((((c3*2) + c5) + (c15*4)) + (c21*16)) + (c19*32)) in (buf_snk_B1_Blocal_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] + ((_B1_prop_r_b2[((((t394 + (t4148*96)) + (t4147*192)) + (c1*576)) + 1152)]*buf_snk_B1_Blocal_diquark_r2_r[0]) - (_B1_prop_i_b3[((((t394 + (t4150*96)) + (t4149*192)) + (c1*576)) + 1152)]*buf_snk_B1_Blocal_diquark_r2_i[0]))))
                        let t4166 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t4165 = _src_color_weights_b24[((c17*3) + 37)]
                        let t4164 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t4163 = _src_color_weights_b24[((c17*3) + 37)]
                        buf_snk_B1_Blocal_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = (let t395 = (((((c3*2) + c5) + (c15*4)) + (c21*16)) + (c19*32)) in (buf_snk_B1_Blocal_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] + ((_B1_prop_r_b2[((((t395 + (t4164*96)) + (t4163*192)) + (c1*576)) + 1152)]*buf_snk_B1_Blocal_diquark_r2_i[0]) + (_B1_prop_i_b3[((((t395 + (t4166*96)) + (t4165*192)) + (c1*576)) + 1152)]*buf_snk_B1_Blocal_diquark_r2_r[0]))))
                      }
                    }
                  }
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_snk_B1_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t396 = (c21 + (c15*44)) in (let t397 = (c19 + int32((int64(c17)*(int64)2))) in (buf_snk_B1_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B1_r_b10[t396]*buf_snk_B1_Blocal_props_r2_r[t397]) - (_snk_psi_B1_i_b11[t396]*buf_snk_B1_Blocal_props_r2_i[t397])))))
                        buf_snk_B1_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t398 = (c21 + (c15*44)) in (let t399 = (c19 + int32((int64(c17)*(int64)2))) in (buf_snk_B1_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B1_r_b10[t398]*buf_snk_B1_Blocal_props_r2_i[t399]) + (_snk_psi_B1_i_b11[t398]*buf_snk_B1_Blocal_props_r2_r[t399])))))
                        buf_flip_snk_B1_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t400 = (c21 + (c15*44)) in (let t401 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_snk_B1_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B2_r_b12[t400]*buf_snk_B1_Blocal_props_r2_r[t401]) - (_snk_psi_B2_i_b13[t400]*buf_snk_B1_Blocal_props_r2_i[t401])))))
                        buf_flip_snk_B1_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t402 = (c21 + (c15*44)) in (let t403 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_snk_B1_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B2_r_b12[t402]*buf_snk_B1_Blocal_props_r2_i[t403]) + (_snk_psi_B2_i_b13[t402]*buf_snk_B1_Blocal_props_r2_r[t403])))))
                      }
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 3) {
                  for (c17, 0, 2) {
                    for (c19, 0, 44) {
                      buf_snk_B2_Blocal_r1_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_snk_B2_Blocal_r1_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_snk_B2_Blocal_r1_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_snk_B2_Blocal_r1_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 4) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      buf_snk_B2_Blocal_props_r1_r[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                      buf_snk_B2_Blocal_props_r1_i[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                    }
                  }
                  for (c17, 0, 12) {
                    let t4300 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t4299 = _src_color_weights_b24[((c17*3) + 2)]
                    let t4298 = _src_spin_weights_b25[(c17*3)]
                    let t4297 = _src_color_weights_b24[(c17*3)]
                    let t4296 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t4295 = _src_color_weights_b24[((c17*3) + 2)]
                    let t4294 = _src_spin_weights_b25[(c17*3)]
                    let t4293 = _src_color_weights_b24[(c17*3)]
                    buf_snk_B2_Blocal_diquark_r1_r[0] = (let t404 = (((c3*2) + c5) + (c15*4)) in (let t405 = ((t404 + (c9*16)) + (c7*32)) in (let t406 = ((t404 + (c13*16)) + (c11*32)) in (((_B2_prop_r_b4[(((t405 + (t4294*96)) + (t4293*192)) + (c1*576))]*_B2_prop_r_b4[((((t406 + (t4296*96)) + (t4295*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((t405 + (t4298*96)) + (t4297*192)) + (c1*576))]*_B2_prop_i_b5[((((t406 + (t4300*96)) + (t4299*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c17]))))
                    let t4318 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t4317 = _src_color_weights_b24[((c17*3) + 2)]
                    let t4316 = _src_spin_weights_b25[(c17*3)]
                    let t4315 = _src_color_weights_b24[(c17*3)]
                    let t4314 = _src_spin_weights_b25[((c17*3) + 2)]
                    let t4313 = _src_color_weights_b24[((c17*3) + 2)]
                    let t4312 = _src_spin_weights_b25[(c17*3)]
                    let t4311 = _src_color_weights_b24[(c17*3)]
                    buf_snk_B2_Blocal_diquark_r1_i[0] = (let t407 = (((c3*2) + c5) + (c15*4)) in (let t408 = ((t407 + (c9*16)) + (c7*32)) in (let t409 = ((t407 + (c13*16)) + (c11*32)) in (((_B2_prop_r_b4[(((t408 + (t4312*96)) + (t4311*192)) + (c1*576))]*_B2_prop_i_b5[((((t409 + (t4314*96)) + (t4313*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((t408 + (t4316*96)) + (t4315*192)) + (c1*576))]*_B2_prop_r_b4[((((t409 + (t4318*96)) + (t4317*192)) + (c1*576)) + 2304)]))*_src_weights_b26[c17]))))
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        let t4332 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t4331 = _src_color_weights_b24[((c17*3) + 1)]
                        let t4330 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t4329 = _src_color_weights_b24[((c17*3) + 1)]
                        buf_snk_B2_Blocal_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] = (let t410 = (((((c3*2) + c5) + (c15*4)) + (c21*16)) + (c19*32)) in (buf_snk_B2_Blocal_props_r1_r[(c21 + int32((int64(c19)*(int64)2)))] + ((_B2_prop_r_b4[((((t410 + (t4330*96)) + (t4329*192)) + (c1*576)) + 1152)]*buf_snk_B2_Blocal_diquark_r1_r[0]) - (_B2_prop_i_b5[((((t410 + (t4332*96)) + (t4331*192)) + (c1*576)) + 1152)]*buf_snk_B2_Blocal_diquark_r1_i[0]))))
                        let t4348 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t4347 = _src_color_weights_b24[((c17*3) + 1)]
                        let t4346 = _src_spin_weights_b25[((c17*3) + 1)]
                        let t4345 = _src_color_weights_b24[((c17*3) + 1)]
                        buf_snk_B2_Blocal_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] = (let t411 = (((((c3*2) + c5) + (c15*4)) + (c21*16)) + (c19*32)) in (buf_snk_B2_Blocal_props_r1_i[(c21 + int32((int64(c19)*(int64)2)))] + ((_B2_prop_r_b4[((((t411 + (t4346*96)) + (t4345*192)) + (c1*576)) + 1152)]*buf_snk_B2_Blocal_diquark_r1_i[0]) + (_B2_prop_i_b5[((((t411 + (t4348*96)) + (t4347*192)) + (c1*576)) + 1152)]*buf_snk_B2_Blocal_diquark_r1_r[0]))))
                      }
                    }
                  }
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_snk_B2_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t412 = (c21 + (c15*44)) in (let t413 = (c19 + int32((int64(c17)*(int64)2))) in (buf_snk_B2_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B2_r_b12[t412]*buf_snk_B2_Blocal_props_r1_r[t413]) - (_snk_psi_B2_i_b13[t412]*buf_snk_B2_Blocal_props_r1_i[t413])))))
                        buf_snk_B2_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t414 = (c21 + (c15*44)) in (let t415 = (c19 + int32((int64(c17)*(int64)2))) in (buf_snk_B2_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B2_r_b12[t414]*buf_snk_B2_Blocal_props_r1_i[t415]) + (_snk_psi_B2_i_b13[t414]*buf_snk_B2_Blocal_props_r1_r[t415])))))
                        buf_flip_snk_B2_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t416 = (c21 + (c15*44)) in (let t417 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_snk_B2_Blocal_r1_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B1_r_b10[t416]*buf_snk_B2_Blocal_props_r1_r[t417]) - (_snk_psi_B1_i_b11[t416]*buf_snk_B2_Blocal_props_r1_i[t417])))))
                        buf_flip_snk_B2_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t418 = (c21 + (c15*44)) in (let t419 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_snk_B2_Blocal_r1_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B1_r_b10[t418]*buf_snk_B2_Blocal_props_r1_i[t419]) + (_snk_psi_B1_i_b11[t418]*buf_snk_B2_Blocal_props_r1_r[t419])))))
                      }
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 3) {
                  for (c17, 0, 2) {
                    for (c19, 0, 44) {
                      buf_snk_B2_Blocal_r2_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_snk_B2_Blocal_r2_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_snk_B2_Blocal_r2_r[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                    for (c19, 0, 44) {
                      buf_flip_snk_B2_Blocal_r2_i[((((((c19 + int32((int64(c17)*(int64)44))) + int32((int64(c15)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = 0.000000
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 3) {
          for (c9, 0, 2) {
            for (c11, 0, 3) {
              for (c13, 0, 2) {
                for (c15, 0, 4) {
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      buf_snk_B2_Blocal_props_r2_r[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                      buf_snk_B2_Blocal_props_r2_i[(c19 + int32((int64(c17)*(int64)2)))] = 0.000000
                    }
                  }
                  for (c17, 0, 12) {
                    let t4482 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t4481 = _src_color_weights_b24[((c17*3) + 38)]
                    let t4480 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t4479 = _src_color_weights_b24[((c17*3) + 36)]
                    let t4478 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t4477 = _src_color_weights_b24[((c17*3) + 38)]
                    let t4476 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t4475 = _src_color_weights_b24[((c17*3) + 36)]
                    buf_snk_B2_Blocal_diquark_r2_r[0] = (let t420 = (((c3*2) + c5) + (c15*4)) in (let t421 = ((t420 + (c9*16)) + (c7*32)) in (let t422 = ((t420 + (c13*16)) + (c11*32)) in (((_B2_prop_r_b4[(((t421 + (t4476*96)) + (t4475*192)) + (c1*576))]*_B2_prop_r_b4[((((t422 + (t4478*96)) + (t4477*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((t421 + (t4480*96)) + (t4479*192)) + (c1*576))]*_B2_prop_i_b5[((((t422 + (t4482*96)) + (t4481*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c17 + 12)]))))
                    let t4500 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t4499 = _src_color_weights_b24[((c17*3) + 38)]
                    let t4498 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t4497 = _src_color_weights_b24[((c17*3) + 36)]
                    let t4496 = _src_spin_weights_b25[((c17*3) + 38)]
                    let t4495 = _src_color_weights_b24[((c17*3) + 38)]
                    let t4494 = _src_spin_weights_b25[((c17*3) + 36)]
                    let t4493 = _src_color_weights_b24[((c17*3) + 36)]
                    buf_snk_B2_Blocal_diquark_r2_i[0] = (let t423 = (((c3*2) + c5) + (c15*4)) in (let t424 = ((t423 + (c9*16)) + (c7*32)) in (let t425 = ((t423 + (c13*16)) + (c11*32)) in (((_B2_prop_r_b4[(((t424 + (t4494*96)) + (t4493*192)) + (c1*576))]*_B2_prop_i_b5[((((t425 + (t4496*96)) + (t4495*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((t424 + (t4498*96)) + (t4497*192)) + (c1*576))]*_B2_prop_r_b4[((((t425 + (t4500*96)) + (t4499*192)) + (c1*576)) + 2304)]))*_src_weights_b26[(c17 + 12)]))))
                    for (c19, 0, 3) {
                      for (c21, 0, 2) {
                        let t4514 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t4513 = _src_color_weights_b24[((c17*3) + 37)]
                        let t4512 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t4511 = _src_color_weights_b24[((c17*3) + 37)]
                        buf_snk_B2_Blocal_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] = (let t426 = (((((c3*2) + c5) + (c15*4)) + (c21*16)) + (c19*32)) in (buf_snk_B2_Blocal_props_r2_r[(c21 + int32((int64(c19)*(int64)2)))] + ((_B2_prop_r_b4[((((t426 + (t4512*96)) + (t4511*192)) + (c1*576)) + 1152)]*buf_snk_B2_Blocal_diquark_r2_r[0]) - (_B2_prop_i_b5[((((t426 + (t4514*96)) + (t4513*192)) + (c1*576)) + 1152)]*buf_snk_B2_Blocal_diquark_r2_i[0]))))
                        let t4530 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t4529 = _src_color_weights_b24[((c17*3) + 37)]
                        let t4528 = _src_spin_weights_b25[((c17*3) + 37)]
                        let t4527 = _src_color_weights_b24[((c17*3) + 37)]
                        buf_snk_B2_Blocal_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] = (let t427 = (((((c3*2) + c5) + (c15*4)) + (c21*16)) + (c19*32)) in (buf_snk_B2_Blocal_props_r2_i[(c21 + int32((int64(c19)*(int64)2)))] + ((_B2_prop_r_b4[((((t427 + (t4528*96)) + (t4527*192)) + (c1*576)) + 1152)]*buf_snk_B2_Blocal_diquark_r2_i[0]) + (_B2_prop_i_b5[((((t427 + (t4530*96)) + (t4529*192)) + (c1*576)) + 1152)]*buf_snk_B2_Blocal_diquark_r2_r[0]))))
                      }
                    }
                  }
                  for (c17, 0, 3) {
                    for (c19, 0, 2) {
                      for (c21, 0, 44) {
                        buf_snk_B2_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t428 = (c21 + (c15*44)) in (let t429 = (c19 + int32((int64(c17)*(int64)2))) in (buf_snk_B2_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B2_r_b12[t428]*buf_snk_B2_Blocal_props_r2_r[t429]) - (_snk_psi_B2_i_b13[t428]*buf_snk_B2_Blocal_props_r2_i[t429])))))
                        buf_flip_snk_B2_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t430 = (c21 + (c15*44)) in (let t431 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_snk_B2_Blocal_r2_r[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B1_r_b10[t430]*buf_snk_B2_Blocal_props_r2_r[t431]) - (_snk_psi_B1_i_b11[t430]*buf_snk_B2_Blocal_props_r2_i[t431])))))
                        buf_flip_snk_B2_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t432 = (c21 + (c15*44)) in (let t433 = (c19 + int32((int64(c17)*(int64)2))) in (buf_flip_snk_B2_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B1_r_b10[t432]*buf_snk_B2_Blocal_props_r2_i[t433]) + (_snk_psi_B1_i_b11[t432]*buf_snk_B2_Blocal_props_r2_r[t433])))))
                        buf_snk_B2_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] = (let t434 = (c21 + (c15*44)) in (let t435 = (c19 + int32((int64(c17)*(int64)2))) in (buf_snk_B2_Blocal_r2_i[((((((c21 + int32((int64(c19)*(int64)44))) + int32((int64(c17)*(int64)88))) + int32((int64(c13)*(int64)264))) + int32((int64(c11)*(int64)528))) + int32((int64(c9)*(int64)1584))) + int32((int64(c7)*(int64)3168)))] + ((_snk_psi_B2_r_b12[t434]*buf_snk_B2_Blocal_props_r2_i[t435]) + (_snk_psi_B2_i_b13[t434]*buf_snk_B2_Blocal_props_r2_r[t435])))))
                      }
                    }
                  }
                }
              }
            }
          }
        }
        for (c7, 0, 4) {
          for (c9, 0, 44) {
            for (c11, 0, 4) {
              buf_C_H_BB_prop_r[0] = 0.000000
              buf_C_H_BB_prop_i[0] = 0.000000
              for (c13, 0, 2) {
                for (c15, 0, 36) {
                  for (c17, 0, 32) {
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 1)) {
                      let t7182 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7181 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7180 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7179 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7178 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7177 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_H_BB_new_term_b1_r[0] = buf_snk_B1_Blocal_r1_r[((((((c9 + int32((int64(t7182)*(int64)44))) + int32((int64(t7181)*(int64)88))) + int32((int64(t7180)*(int64)264))) + int32((int64(t7179)*(int64)528))) + int32((int64(t7178)*(int64)1584))) + int32((int64(t7177)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 1)) {
                      let t7198 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7197 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7196 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7195 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7194 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7193 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_H_BB_new_term_b1_i[0] = buf_snk_B1_Blocal_r1_i[((((((c9 + int32((int64(t7198)*(int64)44))) + int32((int64(t7197)*(int64)88))) + int32((int64(t7196)*(int64)264))) + int32((int64(t7195)*(int64)528))) + int32((int64(t7194)*(int64)1584))) + int32((int64(t7193)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 2)) {
                      let t7214 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7213 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7212 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7211 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7210 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7209 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_H_BB_new_term_b1_r[0] = buf_snk_B1_Blocal_r2_r[((((((c9 + int32((int64(t7214)*(int64)44))) + int32((int64(t7213)*(int64)88))) + int32((int64(t7212)*(int64)264))) + int32((int64(t7211)*(int64)528))) + int32((int64(t7210)*(int64)1584))) + int32((int64(t7209)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 2)) {
                      let t7230 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7229 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7228 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7227 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7226 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7225 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_H_BB_new_term_b1_i[0] = buf_snk_B1_Blocal_r2_i[((((((c9 + int32((int64(t7230)*(int64)44))) + int32((int64(t7229)*(int64)88))) + int32((int64(t7228)*(int64)264))) + int32((int64(t7227)*(int64)528))) + int32((int64(t7226)*(int64)1584))) + int32((int64(t7225)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 1)) {
                      let t7246 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7245 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7244 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7243 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7242 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7241 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_H_BB_new_term_b2_r[0] = buf_snk_B2_Blocal_r1_r[((((((c9 + int32((int64(t7246)*(int64)44))) + int32((int64(t7245)*(int64)88))) + int32((int64(t7244)*(int64)264))) + int32((int64(t7243)*(int64)528))) + int32((int64(t7242)*(int64)1584))) + int32((int64(t7241)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 1)) {
                      let t7262 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7261 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7260 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7259 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7258 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7257 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_H_BB_new_term_b2_i[0] = buf_snk_B2_Blocal_r1_i[((((((c9 + int32((int64(t7262)*(int64)44))) + int32((int64(t7261)*(int64)88))) + int32((int64(t7260)*(int64)264))) + int32((int64(t7259)*(int64)528))) + int32((int64(t7258)*(int64)1584))) + int32((int64(t7257)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 2)) {
                      let t7278 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7277 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7276 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7275 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7274 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7273 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_H_BB_new_term_b2_r[0] = buf_snk_B2_Blocal_r2_r[((((((c9 + int32((int64(t7278)*(int64)44))) + int32((int64(t7277)*(int64)88))) + int32((int64(t7276)*(int64)264))) + int32((int64(t7275)*(int64)528))) + int32((int64(t7274)*(int64)1584))) + int32((int64(t7273)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 2)) {
                      let t7294 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7293 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7292 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7291 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7290 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7289 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_H_BB_new_term_b2_i[0] = buf_snk_B2_Blocal_r2_i[((((((c9 + int32((int64(t7294)*(int64)44))) + int32((int64(t7293)*(int64)88))) + int32((int64(t7292)*(int64)264))) + int32((int64(t7291)*(int64)528))) + int32((int64(t7290)*(int64)1584))) + int32((int64(t7289)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 1)) {
                      let t7310 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7309 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7308 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7307 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7306 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7305 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_flip_H_BB_new_term_b1_r[0] = buf_flip_snk_B1_Blocal_r1_r[((((((c9 + int32((int64(t7310)*(int64)44))) + int32((int64(t7309)*(int64)88))) + int32((int64(t7308)*(int64)264))) + int32((int64(t7307)*(int64)528))) + int32((int64(t7306)*(int64)1584))) + int32((int64(t7305)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 1)) {
                      let t7326 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7325 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7324 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7323 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7322 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7321 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_flip_H_BB_new_term_b1_i[0] = buf_flip_snk_B1_Blocal_r1_i[((((((c9 + int32((int64(t7326)*(int64)44))) + int32((int64(t7325)*(int64)88))) + int32((int64(t7324)*(int64)264))) + int32((int64(t7323)*(int64)528))) + int32((int64(t7322)*(int64)1584))) + int32((int64(t7321)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 2)) {
                      let t7342 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7341 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7340 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7339 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7338 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7337 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_flip_H_BB_new_term_b1_r[0] = buf_flip_snk_B1_Blocal_r2_r[((((((c9 + int32((int64(t7342)*(int64)44))) + int32((int64(t7341)*(int64)88))) + int32((int64(t7340)*(int64)264))) + int32((int64(t7339)*(int64)528))) + int32((int64(t7338)*(int64)1584))) + int32((int64(t7337)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[((c13*2) + (c7*4))] == 2)) {
                      let t7358 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7357 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 2)]
                      let t7356 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7355 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 4)]
                      let t7354 = _hex_snk_spin_weights_b31[(((c17*6) + (c15*192)) + (c11*6912))]
                      let t7353 = _hex_snk_color_weights_b30[(((c17*6) + (c15*192)) + (c11*6912))]
                      buf_flip_H_BB_new_term_b1_i[0] = buf_flip_snk_B1_Blocal_r2_i[((((((c9 + int32((int64(t7358)*(int64)44))) + int32((int64(t7357)*(int64)88))) + int32((int64(t7356)*(int64)264))) + int32((int64(t7355)*(int64)528))) + int32((int64(t7354)*(int64)1584))) + int32((int64(t7353)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 1)) {
                      let t7374 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7373 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7372 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7371 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7370 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7369 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_flip_H_BB_new_term_b2_r[0] = buf_flip_snk_B2_Blocal_r1_r[((((((c9 + int32((int64(t7374)*(int64)44))) + int32((int64(t7373)*(int64)88))) + int32((int64(t7372)*(int64)264))) + int32((int64(t7371)*(int64)528))) + int32((int64(t7370)*(int64)1584))) + int32((int64(t7369)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 1)) {
                      let t7390 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7389 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7388 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7387 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7386 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7385 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_flip_H_BB_new_term_b2_i[0] = buf_flip_snk_B2_Blocal_r1_i[((((((c9 + int32((int64(t7390)*(int64)44))) + int32((int64(t7389)*(int64)88))) + int32((int64(t7388)*(int64)264))) + int32((int64(t7387)*(int64)528))) + int32((int64(t7386)*(int64)1584))) + int32((int64(t7385)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 2)) {
                      let t7406 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7405 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7404 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7403 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7402 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7401 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_flip_H_BB_new_term_b2_r[0] = buf_flip_snk_B2_Blocal_r2_r[((((((c9 + int32((int64(t7406)*(int64)44))) + int32((int64(t7405)*(int64)88))) + int32((int64(t7404)*(int64)264))) + int32((int64(t7403)*(int64)528))) + int32((int64(t7402)*(int64)1584))) + int32((int64(t7401)*(int64)3168)))]
                    }
                    if ((_src_spins_b20[(((c13*2) + (c7*4)) + 1)] == 2)) {
                      let t7422 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7421 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 3)]
                      let t7420 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7419 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 5)]
                      let t7418 = _hex_snk_spin_weights_b31[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      let t7417 = _hex_snk_color_weights_b30[((((c17*6) + (c15*192)) + (c11*6912)) + 1)]
                      buf_flip_H_BB_new_term_b2_i[0] = buf_flip_snk_B2_Blocal_r2_i[((((((c9 + int32((int64(t7422)*(int64)44))) + int32((int64(t7421)*(int64)88))) + int32((int64(t7420)*(int64)264))) + int32((int64(t7419)*(int64)528))) + int32((int64(t7418)*(int64)1584))) + int32((int64(t7417)*(int64)3168)))]
                    }
                    buf_C_H_BB_prop_r[0] = (let t436 = ((float64(_sigs_b22[c15])*_hex_snk_weights_b32[(c17 + (c11*32))])*_src_spin_block_weights_b21[(c13 + (c7*2))]) in (buf_C_H_BB_prop_r[0] + (((((t436*buf_H_BB_new_term_b1_r[0])*buf_H_BB_new_term_b2_r[0]) - ((t436*buf_H_BB_new_term_b1_i[0])*buf_H_BB_new_term_b2_i[0])) + (((t436*buf_flip_H_BB_new_term_b1_r[0])*buf_flip_H_BB_new_term_b2_r[0]) - ((t436*buf_flip_H_BB_new_term_b1_i[0])*buf_flip_H_BB_new_term_b2_i[0])))*0.500000)))
                    buf_C_H_BB_prop_i[0] = (let t437 = ((float64(_sigs_b22[c15])*_hex_snk_weights_b32[(c17 + (c11*32))])*_src_spin_block_weights_b21[(c13 + (c7*2))]) in (buf_C_H_BB_prop_i[0] + (((((t437*buf_H_BB_new_term_b1_r[0])*buf_H_BB_new_term_b2_i[0]) + ((t437*buf_H_BB_new_term_b1_i[0])*buf_H_BB_new_term_b2_r[0])) + (((t437*buf_flip_H_BB_new_term_b1_r[0])*buf_flip_H_BB_new_term_b2_i[0]) + ((t437*buf_flip_H_BB_new_term_b1_i[0])*buf_flip_H_BB_new_term_b2_r[0])))*0.500000)))
                  }
                }
              }
              for (c13, 0, 2) {
                buf_C_r[((((((c9 + int32((int64(c7)*(int64)46))) + int32(((int64(c13)*(int64)184) + (int64)8096))) + int32((int64(c11)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = (buf_C_r[((((((c9 + int32((int64(c7)*(int64)46))) + int32(((int64(c13)*(int64)184) + (int64)8096))) + int32((int64(c11)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] + 1.000000)
                buf_C_i[((((((c9 + int32((int64(c7)*(int64)46))) + int32(((int64(c13)*(int64)184) + (int64)8096))) + int32((int64(c11)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = (buf_C_i[((((((c9 + int32((int64(c7)*(int64)46))) + int32(((int64(c13)*(int64)184) + (int64)8096))) + int32((int64(c11)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] + 1.000000)
              }
            }
          }
        }
      }
    }
    for (c3, 0, 2) {
      for (c5, 0, 2) {
        for (c7, 0, 4) {
          for (c9, 0, 4) {
            for (c11, 0, 4) {
              buf_C_H_H_prop_r[0] = 0.000000
              buf_C_H_H_prop_i[0] = 0.000000
              for (c13, 0, 36) {
                for (c15, 0, 32) {
                  for (c17, 0, 32) {
                    let t7722 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 3)]
                    let t7721 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 3)]
                    let t7720 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7719 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7718 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7717 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7716 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7715 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7714 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7713 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7712 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7711 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7710 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7709 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7708 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7707 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7706 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7705 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7704 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7703 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7702 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 3)]
                    let t7701 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 3)]
                    let t7700 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7699 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7698 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7697 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7696 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7695 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7694 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7693 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7692 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7691 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7690 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7689 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7688 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7687 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7686 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7685 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7684 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7683 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7642 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 2)]
                    let t7641 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 2)]
                    let t7640 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7639 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7638 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7637 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7636 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7635 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7634 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7633 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7632 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7631 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7630 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7629 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7628 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7627 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7626 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7625 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7624 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7623 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7622 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 2)]
                    let t7621 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 2)]
                    let t7620 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7619 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7618 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7617 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7616 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7615 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7614 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7613 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7612 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7611 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7610 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7609 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7608 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7607 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7606 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7605 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7604 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7603 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7602 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 3)]
                    let t7601 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 3)]
                    let t7600 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7599 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7598 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7597 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7596 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7595 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7594 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7593 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7592 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7591 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7590 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7589 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7588 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7587 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7586 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7585 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7584 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7583 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7582 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 3)]
                    let t7581 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 3)]
                    let t7580 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7579 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7578 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7577 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7576 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7575 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7574 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7573 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7572 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7571 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7570 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7569 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7568 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7567 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7566 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7565 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7564 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7563 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7522 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 2)]
                    let t7521 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 2)]
                    let t7520 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7519 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7518 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7517 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7516 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7515 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7514 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7513 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7512 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7511 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7510 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7509 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7508 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7507 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7506 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7505 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7504 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7503 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7502 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 2)]
                    let t7501 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 2)]
                    let t7500 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7499 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7498 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7497 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7496 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7495 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7494 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7493 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7492 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7491 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7490 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7489 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7488 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7487 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7486 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7485 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7484 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7483 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    buf_C_H_H_prop_r[0] = (let t438 = ((float64(_sigs_b22[c13])*_hex_snk_weights_b32[(c15 + (c9*32))])*_hex_snk_weights_b32[(c17 + (c7*32))]) in (let t439 = (c11 + (((c3*2) + c5)*4)) in (buf_C_H_H_prop_r[0] + (((t438*((((_B1_prop_r_b2[(((((t439 + (t7486*16)) + (t7485*32)) + (t7484*96)) + (t7483*192)) + (c1*576))]*_B1_prop_r_b2[((((((t439 + (t7490*16)) + (t7489*32)) + (t7488*96)) + (t7487*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t439 + (t7494*16)) + (t7493*32)) + (t7492*96)) + (t7491*192)) + (c1*576))]*_B1_prop_i_b3[((((((t439 + (t7498*16)) + (t7497*32)) + (t7496*96)) + (t7495*192)) + (c1*576)) + 2304)]))*_B1_prop_r_b2[((((((t439 + (t7502*16)) + (t7501*32)) + (t7500*96)) + (t7499*192)) + (c1*576)) + 1152)]) - (((_B1_prop_r_b2[(((((t439 + (t7506*16)) + (t7505*32)) + (t7504*96)) + (t7503*192)) + (c1*576))]*_B1_prop_i_b3[((((((t439 + (t7510*16)) + (t7509*32)) + (t7508*96)) + (t7507*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t439 + (t7514*16)) + (t7513*32)) + (t7512*96)) + (t7511*192)) + (c1*576))]*_B1_prop_r_b2[((((((t439 + (t7518*16)) + (t7517*32)) + (t7516*96)) + (t7515*192)) + (c1*576)) + 2304)]))*_B1_prop_i_b3[((((((t439 + (t7522*16)) + (t7521*32)) + (t7520*96)) + (t7519*192)) + (c1*576)) + 1152)])))*((((_B2_prop_r_b4[(((((t439 + (t7566*16)) + (t7565*32)) + (t7564*96)) + (t7563*192)) + (c1*576))]*_B2_prop_r_b4[((((((t439 + (t7570*16)) + (t7569*32)) + (t7568*96)) + (t7567*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t439 + (t7574*16)) + (t7573*32)) + (t7572*96)) + (t7571*192)) + (c1*576))]*_B2_prop_i_b5[((((((t439 + (t7578*16)) + (t7577*32)) + (t7576*96)) + (t7575*192)) + (c1*576)) + 2304)]))*_B2_prop_r_b4[((((((t439 + (t7582*16)) + (t7581*32)) + (t7580*96)) + (t7579*192)) + (c1*576)) + 1152)]) - (((_B2_prop_r_b4[(((((t439 + (t7586*16)) + (t7585*32)) + (t7584*96)) + (t7583*192)) + (c1*576))]*_B2_prop_i_b5[((((((t439 + (t7590*16)) + (t7589*32)) + (t7588*96)) + (t7587*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t439 + (t7594*16)) + (t7593*32)) + (t7592*96)) + (t7591*192)) + (c1*576))]*_B2_prop_r_b4[((((((t439 + (t7598*16)) + (t7597*32)) + (t7596*96)) + (t7595*192)) + (c1*576)) + 2304)]))*_B2_prop_i_b5[((((((t439 + (t7602*16)) + (t7601*32)) + (t7600*96)) + (t7599*192)) + (c1*576)) + 1152)]))) - ((t438*((((_B1_prop_r_b2[(((((t439 + (t7606*16)) + (t7605*32)) + (t7604*96)) + (t7603*192)) + (c1*576))]*_B1_prop_r_b2[((((((t439 + (t7610*16)) + (t7609*32)) + (t7608*96)) + (t7607*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t439 + (t7614*16)) + (t7613*32)) + (t7612*96)) + (t7611*192)) + (c1*576))]*_B1_prop_i_b3[((((((t439 + (t7618*16)) + (t7617*32)) + (t7616*96)) + (t7615*192)) + (c1*576)) + 2304)]))*_B1_prop_i_b3[((((((t439 + (t7622*16)) + (t7621*32)) + (t7620*96)) + (t7619*192)) + (c1*576)) + 1152)]) + (((_B1_prop_r_b2[(((((t439 + (t7626*16)) + (t7625*32)) + (t7624*96)) + (t7623*192)) + (c1*576))]*_B1_prop_i_b3[((((((t439 + (t7630*16)) + (t7629*32)) + (t7628*96)) + (t7627*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t439 + (t7634*16)) + (t7633*32)) + (t7632*96)) + (t7631*192)) + (c1*576))]*_B1_prop_r_b2[((((((t439 + (t7638*16)) + (t7637*32)) + (t7636*96)) + (t7635*192)) + (c1*576)) + 2304)]))*_B1_prop_r_b2[((((((t439 + (t7642*16)) + (t7641*32)) + (t7640*96)) + (t7639*192)) + (c1*576)) + 1152)])))*((((_B2_prop_r_b4[(((((t439 + (t7686*16)) + (t7685*32)) + (t7684*96)) + (t7683*192)) + (c1*576))]*_B2_prop_r_b4[((((((t439 + (t7690*16)) + (t7689*32)) + (t7688*96)) + (t7687*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t439 + (t7694*16)) + (t7693*32)) + (t7692*96)) + (t7691*192)) + (c1*576))]*_B2_prop_i_b5[((((((t439 + (t7698*16)) + (t7697*32)) + (t7696*96)) + (t7695*192)) + (c1*576)) + 2304)]))*_B2_prop_i_b5[((((((t439 + (t7702*16)) + (t7701*32)) + (t7700*96)) + (t7699*192)) + (c1*576)) + 1152)]) + (((_B2_prop_r_b4[(((((t439 + (t7706*16)) + (t7705*32)) + (t7704*96)) + (t7703*192)) + (c1*576))]*_B2_prop_i_b5[((((((t439 + (t7710*16)) + (t7709*32)) + (t7708*96)) + (t7707*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t439 + (t7714*16)) + (t7713*32)) + (t7712*96)) + (t7711*192)) + (c1*576))]*_B2_prop_r_b4[((((((t439 + (t7718*16)) + (t7717*32)) + (t7716*96)) + (t7715*192)) + (c1*576)) + 2304)]))*_B2_prop_r_b4[((((((t439 + (t7722*16)) + (t7721*32)) + (t7720*96)) + (t7719*192)) + (c1*576)) + 1152)])))))))
                    let t7972 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 3)]
                    let t7971 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 3)]
                    let t7970 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7969 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7968 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7967 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7966 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7965 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7964 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7963 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7962 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7961 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7960 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7959 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7958 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7957 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7956 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7955 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7954 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7953 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7952 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 3)]
                    let t7951 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 3)]
                    let t7950 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7949 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7948 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7947 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7946 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7945 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7944 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7943 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7942 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7941 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7940 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7939 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7938 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7937 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7936 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7935 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7934 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7933 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7892 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 2)]
                    let t7891 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 2)]
                    let t7890 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7889 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7888 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7887 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7886 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7885 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7884 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7883 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7882 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7881 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7880 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7879 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7878 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7877 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7876 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7875 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7874 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7873 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7872 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 2)]
                    let t7871 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 2)]
                    let t7870 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7869 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7868 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7867 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7866 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7865 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7864 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7863 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7862 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7861 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7860 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7859 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7858 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7857 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7856 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7855 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7854 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7853 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7852 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 3)]
                    let t7851 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 3)]
                    let t7850 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7849 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7848 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7847 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7846 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7845 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7844 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7843 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7842 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7841 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7840 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7839 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7838 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7837 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7836 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7835 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7834 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7833 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7832 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 3)]
                    let t7831 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 3)]
                    let t7830 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7829 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 3)]
                    let t7828 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7827 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7826 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7825 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7824 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7823 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7822 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7821 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7820 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 5)]
                    let t7819 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 5)]
                    let t7818 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7817 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 5)]
                    let t7816 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 1)]
                    let t7815 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 1)]
                    let t7814 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7813 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 1)]
                    let t7772 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 2)]
                    let t7771 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 2)]
                    let t7770 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7769 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7768 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7767 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7766 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7765 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7764 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7763 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7762 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7761 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7760 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7759 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7758 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7757 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7756 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7755 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7754 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7753 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7752 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 2)]
                    let t7751 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 2)]
                    let t7750 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7749 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 2)]
                    let t7748 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7747 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7746 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7745 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7744 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7743 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7742 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7741 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7740 = _hex_snk_spin_weights_b31[(((c17*6) + (c7*6912)) + 4)]
                    let t7739 = _hex_snk_color_weights_b30[(((c17*6) + (c7*6912)) + 4)]
                    let t7738 = _hex_snk_spin_weights_b31[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7737 = _hex_snk_color_weights_b30[((((c15*6) + (c13*192)) + (c9*6912)) + 4)]
                    let t7736 = _hex_snk_spin_weights_b31[((c17*6) + (c7*6912))]
                    let t7735 = _hex_snk_color_weights_b30[((c17*6) + (c7*6912))]
                    let t7734 = _hex_snk_spin_weights_b31[(((c15*6) + (c13*192)) + (c9*6912))]
                    let t7733 = _hex_snk_color_weights_b30[(((c15*6) + (c13*192)) + (c9*6912))]
                    buf_C_H_H_prop_i[0] = (let t440 = ((float64(_sigs_b22[c13])*_hex_snk_weights_b32[(c15 + (c9*32))])*_hex_snk_weights_b32[(c17 + (c7*32))]) in (let t441 = (c11 + (((c3*2) + c5)*4)) in (buf_C_H_H_prop_i[0] + (((t440*((((_B1_prop_r_b2[(((((t441 + (t7736*16)) + (t7735*32)) + (t7734*96)) + (t7733*192)) + (c1*576))]*_B1_prop_r_b2[((((((t441 + (t7740*16)) + (t7739*32)) + (t7738*96)) + (t7737*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t441 + (t7744*16)) + (t7743*32)) + (t7742*96)) + (t7741*192)) + (c1*576))]*_B1_prop_i_b3[((((((t441 + (t7748*16)) + (t7747*32)) + (t7746*96)) + (t7745*192)) + (c1*576)) + 2304)]))*_B1_prop_r_b2[((((((t441 + (t7752*16)) + (t7751*32)) + (t7750*96)) + (t7749*192)) + (c1*576)) + 1152)]) - (((_B1_prop_r_b2[(((((t441 + (t7756*16)) + (t7755*32)) + (t7754*96)) + (t7753*192)) + (c1*576))]*_B1_prop_i_b3[((((((t441 + (t7760*16)) + (t7759*32)) + (t7758*96)) + (t7757*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t441 + (t7764*16)) + (t7763*32)) + (t7762*96)) + (t7761*192)) + (c1*576))]*_B1_prop_r_b2[((((((t441 + (t7768*16)) + (t7767*32)) + (t7766*96)) + (t7765*192)) + (c1*576)) + 2304)]))*_B1_prop_i_b3[((((((t441 + (t7772*16)) + (t7771*32)) + (t7770*96)) + (t7769*192)) + (c1*576)) + 1152)])))*((((_B2_prop_r_b4[(((((t441 + (t7816*16)) + (t7815*32)) + (t7814*96)) + (t7813*192)) + (c1*576))]*_B2_prop_r_b4[((((((t441 + (t7820*16)) + (t7819*32)) + (t7818*96)) + (t7817*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t441 + (t7824*16)) + (t7823*32)) + (t7822*96)) + (t7821*192)) + (c1*576))]*_B2_prop_i_b5[((((((t441 + (t7828*16)) + (t7827*32)) + (t7826*96)) + (t7825*192)) + (c1*576)) + 2304)]))*_B2_prop_i_b5[((((((t441 + (t7832*16)) + (t7831*32)) + (t7830*96)) + (t7829*192)) + (c1*576)) + 1152)]) + (((_B2_prop_r_b4[(((((t441 + (t7836*16)) + (t7835*32)) + (t7834*96)) + (t7833*192)) + (c1*576))]*_B2_prop_i_b5[((((((t441 + (t7840*16)) + (t7839*32)) + (t7838*96)) + (t7837*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t441 + (t7844*16)) + (t7843*32)) + (t7842*96)) + (t7841*192)) + (c1*576))]*_B2_prop_r_b4[((((((t441 + (t7848*16)) + (t7847*32)) + (t7846*96)) + (t7845*192)) + (c1*576)) + 2304)]))*_B2_prop_r_b4[((((((t441 + (t7852*16)) + (t7851*32)) + (t7850*96)) + (t7849*192)) + (c1*576)) + 1152)]))) + ((t440*((((_B1_prop_r_b2[(((((t441 + (t7856*16)) + (t7855*32)) + (t7854*96)) + (t7853*192)) + (c1*576))]*_B1_prop_r_b2[((((((t441 + (t7860*16)) + (t7859*32)) + (t7858*96)) + (t7857*192)) + (c1*576)) + 2304)]) - (_B1_prop_i_b3[(((((t441 + (t7864*16)) + (t7863*32)) + (t7862*96)) + (t7861*192)) + (c1*576))]*_B1_prop_i_b3[((((((t441 + (t7868*16)) + (t7867*32)) + (t7866*96)) + (t7865*192)) + (c1*576)) + 2304)]))*_B1_prop_i_b3[((((((t441 + (t7872*16)) + (t7871*32)) + (t7870*96)) + (t7869*192)) + (c1*576)) + 1152)]) + (((_B1_prop_r_b2[(((((t441 + (t7876*16)) + (t7875*32)) + (t7874*96)) + (t7873*192)) + (c1*576))]*_B1_prop_i_b3[((((((t441 + (t7880*16)) + (t7879*32)) + (t7878*96)) + (t7877*192)) + (c1*576)) + 2304)]) + (_B1_prop_i_b3[(((((t441 + (t7884*16)) + (t7883*32)) + (t7882*96)) + (t7881*192)) + (c1*576))]*_B1_prop_r_b2[((((((t441 + (t7888*16)) + (t7887*32)) + (t7886*96)) + (t7885*192)) + (c1*576)) + 2304)]))*_B1_prop_r_b2[((((((t441 + (t7892*16)) + (t7891*32)) + (t7890*96)) + (t7889*192)) + (c1*576)) + 1152)])))*((((_B2_prop_r_b4[(((((t441 + (t7936*16)) + (t7935*32)) + (t7934*96)) + (t7933*192)) + (c1*576))]*_B2_prop_r_b4[((((((t441 + (t7940*16)) + (t7939*32)) + (t7938*96)) + (t7937*192)) + (c1*576)) + 2304)]) - (_B2_prop_i_b5[(((((t441 + (t7944*16)) + (t7943*32)) + (t7942*96)) + (t7941*192)) + (c1*576))]*_B2_prop_i_b5[((((((t441 + (t7948*16)) + (t7947*32)) + (t7946*96)) + (t7945*192)) + (c1*576)) + 2304)]))*_B2_prop_r_b4[((((((t441 + (t7952*16)) + (t7951*32)) + (t7950*96)) + (t7949*192)) + (c1*576)) + 1152)]) - (((_B2_prop_r_b4[(((((t441 + (t7956*16)) + (t7955*32)) + (t7954*96)) + (t7953*192)) + (c1*576))]*_B2_prop_i_b5[((((((t441 + (t7960*16)) + (t7959*32)) + (t7958*96)) + (t7957*192)) + (c1*576)) + 2304)]) + (_B2_prop_i_b5[(((((t441 + (t7964*16)) + (t7963*32)) + (t7962*96)) + (t7961*192)) + (c1*576))]*_B2_prop_r_b4[((((((t441 + (t7968*16)) + (t7967*32)) + (t7966*96)) + (t7965*192)) + (c1*576)) + 2304)]))*_B2_prop_i_b5[((((((t441 + (t7972*16)) + (t7971*32)) + (t7970*96)) + (t7969*192)) + (c1*576)) + 1152)])))))))
                  }
                }
              }
              for (c13, 0, 2) {
                for (c15, 0, 2) {
                  buf_C_r[((((((int32((int64(c15) + (int64)44)) + int32((int64(c9)*(int64)46))) + int32(((int64(c13)*(int64)184) + (int64)8096))) + int32((int64(c7)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = (let t442 = (c13 + (c11*2)) in (let t443 = _hex_src_psi_r_b14[t442] in (let t444 = (c15 + (((c3*2) + c5)*2)) in (let t445 = _hex_snk_psi_r_b16[t444] in (let t446 = _hex_src_psi_i_b15[t442] in (let t447 = _hex_snk_psi_i_b17[t444] in (buf_C_r[((((((int32((int64(c15) + (int64)44)) + int32((int64(c9)*(int64)46))) + int32(((int64(c13)*(int64)184) + (int64)8096))) + int32((int64(c7)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] + ((((t443*t445) - (t446*t447))*buf_C_H_H_prop_r[0]) - (((t443*t447) + (t446*t445))*buf_C_H_H_prop_i[0])))))))))
                  buf_C_i[((((((int32((int64(c15) + (int64)44)) + int32((int64(c9)*(int64)46))) + int32(((int64(c13)*(int64)184) + (int64)8096))) + int32((int64(c7)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] = (let t448 = (c13 + (c11*2)) in (let t449 = _hex_src_psi_r_b14[t448] in (let t450 = (c15 + (((c3*2) + c5)*2)) in (let t451 = _hex_snk_psi_r_b16[t450] in (let t452 = _hex_src_psi_i_b15[t448] in (let t453 = _hex_snk_psi_i_b17[t450] in (buf_C_i[((((((int32((int64(c15) + (int64)44)) + int32((int64(c9)*(int64)46))) + int32(((int64(c13)*(int64)184) + (int64)8096))) + int32((int64(c7)*(int64)8464))) + int32((int64(c5)*(int64)33856))) + int32((int64(c3)*(int64)67712))) + int32((int64(c1)*(int64)135424)))] + ((((t449*t451) - (t452*t453))*buf_C_H_H_prop_i[0]) + (((t449*t453) + (t452*t451))*buf_C_H_H_prop_r[0])))))))))
                }
              }
            }
          }
        }
      }
    }
  }
  free buf_src_B2_Blocal_r2_r
  free buf_src_B2_Blocal_r2_i
  free buf_src_B2_Blocal_r1_r
  free buf_src_B2_Blocal_r1_i
  free buf_src_B2_Blocal_props_r2_r
  free buf_src_B2_Blocal_props_r2_i
  free buf_src_B2_Blocal_props_r1_r
  free buf_src_B2_Blocal_props_r1_i
  free buf_src_B2_Blocal_diquark_r2_r
  free buf_src_B2_Blocal_diquark_r2_i
  free buf_src_B2_Blocal_diquark_r1_r
  free buf_src_B2_Blocal_diquark_r1_i
  free buf_src_B1_Blocal_r2_r
  free buf_src_B1_Blocal_r2_i
  free buf_src_B1_Blocal_r1_r
  free buf_src_B1_Blocal_r1_i
  free buf_src_B1_Blocal_props_r2_r
  free buf_src_B1_Blocal_props_r2_i
  free buf_src_B1_Blocal_props_r1_r
  free buf_src_B1_Blocal_props_r1_i
  free buf_src_B1_Blocal_diquark_r2_r
  free buf_src_B1_Blocal_diquark_r2_i
  free buf_src_B1_Blocal_diquark_r1_r
  free buf_src_B1_Blocal_diquark_r1_i
  free buf_snk_B2_Blocal_r2_r
  free buf_snk_B2_Blocal_r2_i
  free buf_snk_B2_Blocal_r1_r
  free buf_snk_B2_Blocal_r1_i
  free buf_snk_B2_Blocal_props_r2_r
  free buf_snk_B2_Blocal_props_r2_i
  free buf_snk_B2_Blocal_props_r1_r
  free buf_snk_B2_Blocal_props_r1_i
  free buf_snk_B2_Blocal_diquark_r2_r
  free buf_snk_B2_Blocal_diquark_r2_i
  free buf_snk_B2_Blocal_diquark_r1_r
  free buf_snk_B2_Blocal_diquark_r1_i
  free buf_snk_B1_Blocal_r2_r
  free buf_snk_B1_Blocal_r2_i
  free buf_snk_B1_Blocal_r1_r
  free buf_snk_B1_Blocal_r1_i
  free buf_snk_B1_Blocal_props_r2_r
  free buf_snk_B1_Blocal_props_r2_i
  free buf_snk_B1_Blocal_props_r1_r
  free buf_snk_B1_Blocal_props_r1_i
  free buf_snk_B1_Blocal_diquark_r2_r
  free buf_snk_B1_Blocal_diquark_r2_i
  free buf_snk_B1_Blocal_diquark_r1_r
  free buf_snk_B1_Blocal_diquark_r1_i
  free buf_flip_src_B2_Blocal_r2_r
  free buf_flip_src_B2_Blocal_r2_i
  free buf_flip_src_B2_Blocal_r1_r
  free buf_flip_src_B2_Blocal_r1_i
  free buf_flip_src_B1_Blocal_r2_r
  free buf_flip_src_B1_Blocal_r2_i
  free buf_flip_src_B1_Blocal_r1_r
  free buf_flip_src_B1_Blocal_r1_i
  free buf_flip_snk_B2_Blocal_r2_r
  free buf_flip_snk_B2_Blocal_r2_i
  free buf_flip_snk_B2_Blocal_r1_r
  free buf_flip_snk_B2_Blocal_r1_i
  free buf_flip_snk_B1_Blocal_r2_r
  free buf_flip_snk_B1_Blocal_r2_i
  free buf_flip_snk_B1_Blocal_r1_r
  free buf_flip_snk_B1_Blocal_r1_i
  free buf_flip_H_BB_new_term_b2_r
  free buf_flip_H_BB_new_term_b2_i
  free buf_flip_H_BB_new_term_b1_r
  free buf_flip_H_BB_new_term_b1_i
  free buf_flip_BB_H_new_term_b2_r
  free buf_flip_BB_H_new_term_b2_i
  free buf_flip_BB_H_new_term_b1_r
  free buf_flip_BB_H_new_term_b1_i
  free buf_flip_BB_BB_new_term_b2_r
  free buf_flip_BB_BB_new_term_b2_i
  free buf_flip_BB_BB_new_term_b1_r
  free buf_flip_BB_BB_new_term_b1_i
  free buf_flip_B2_Bthird_r2_r
  free buf_flip_B2_Bthird_r2_i
  free buf_flip_B2_Bthird_r1_r
  free buf_flip_B2_Bthird_r1_i
  free buf_flip_B2_Bsecond_r2_r
  free buf_flip_B2_Bsecond_r2_i
  free buf_flip_B2_Bsecond_r1_r
  free buf_flip_B2_Bsecond_r1_i
  free buf_flip_B2_Blocal_r2_r
  free buf_flip_B2_Blocal_r2_i
  free buf_flip_B2_Blocal_r1_r
  free buf_flip_B2_Blocal_r1_i
  free buf_flip_B2_Bfirst_r2_r
  free buf_flip_B2_Bfirst_r2_i
  free buf_flip_B2_Bfirst_r1_r
  free buf_flip_B2_Bfirst_r1_i
  free buf_flip_B1_Bthird_r2_r
  free buf_flip_B1_Bthird_r2_i
  free buf_flip_B1_Bthird_r1_r
  free buf_flip_B1_Bthird_r1_i
  free buf_flip_B1_Bsecond_r2_r
  free buf_flip_B1_Bsecond_r2_i
  free buf_flip_B1_Bsecond_r1_r
  free buf_flip_B1_Bsecond_r1_i
  free buf_flip_B1_Blocal_r2_r
  free buf_flip_B1_Blocal_r2_i
  free buf_flip_B1_Blocal_r1_r
  free buf_flip_B1_Blocal_r1_i
  free buf_flip_B1_Bfirst_r2_r
  free buf_flip_B1_Bfirst_r2_i
  free buf_flip_B1_Bfirst_r1_r
  free buf_flip_B1_Bfirst_r1_i
  free buf_H_BB_new_term_b2_r
  free buf_H_BB_new_term_b2_i
  free buf_H_BB_new_term_b1_r
  free buf_H_BB_new_term_b1_i
  free buf_C_H_H_prop_r
  free buf_C_H_H_prop_i
  free buf_C_H_BB_prop_r
  free buf_C_H_BB_prop_i
  free buf_C_BB_H_prop_r
  free buf_C_BB_H_prop_i
  free buf_C_BB_BB_prop_r
  free buf_C_BB_BB_prop_i
  free buf_BB_H_new_term_b2_r
  free buf_BB_H_new_term_b2_i
  free buf_BB_H_new_term_b1_r
  free buf_BB_H_new_term_b1_i
  free buf_BB_BB_new_term_b2_r
  free buf_BB_BB_new_term_b2_i
  free buf_BB_BB_new_term_b1_r
  free buf_BB_BB_new_term_b1_i
  free buf_B2_Bthird_r2_r
  free buf_B2_Bthird_r2_i
  free buf_B2_Bthird_r1_r
  free buf_B2_Bthird_r1_i
  free buf_B2_Bthird_props_r2_r
  free buf_B2_Bthird_props_r2_i
  free buf_B2_Bthird_props_r1_r
  free buf_B2_Bthird_props_r1_i
  free buf_B2_Bthird_diquark_r2_r
  free buf_B2_Bthird_diquark_r2_i
  free buf_B2_Bthird_diquark_r1_r
  free buf_B2_Bthird_diquark_r1_i
  free buf_B2_Bsecond_r2_r
  free buf_B2_Bsecond_r2_i
  free buf_B2_Bsecond_r1_r
  free buf_B2_Bsecond_r1_i
  free buf_B2_Bsecond_props_r2_r
  free buf_B2_Bsecond_props_r2_i
  free buf_B2_Bsecond_props_r1_r
  free buf_B2_Bsecond_props_r1_i
  free buf_B2_Blocal_r2_r
  free buf_B2_Blocal_r2_i
  free buf_B2_Blocal_r1_r
  free buf_B2_Blocal_r1_i
  free buf_B2_Blocal_props_r2_r
  free buf_B2_Blocal_props_r2_i
  free buf_B2_Blocal_props_r1_r
  free buf_B2_Blocal_props_r1_i
  free buf_B2_Blocal_diquark_r2_r
  free buf_B2_Blocal_diquark_r2_i
  free buf_B2_Blocal_diquark_r1_r
  free buf_B2_Blocal_diquark_r1_i
  free buf_B2_Bfirst_r2_r
  free buf_B2_Bfirst_r2_i
  free buf_B2_Bfirst_r1_r
  free buf_B2_Bfirst_r1_i
  free buf_B2_Bfirst_props_r2_r
  free buf_B2_Bfirst_props_r2_i
  free buf_B2_Bfirst_props_r1_r
  free buf_B2_Bfirst_props_r1_i
  free buf_B2_Bfirst_diquark_r2_r
  free buf_B2_Bfirst_diquark_r2_i
  free buf_B2_Bfirst_diquark_r1_r
  free buf_B2_Bfirst_diquark_r1_i
  free buf_B1_Bthird_r2_r
  free buf_B1_Bthird_r2_i
  free buf_B1_Bthird_r1_r
  free buf_B1_Bthird_r1_i
  free buf_B1_Bthird_props_r2_r
  free buf_B1_Bthird_props_r2_i
  free buf_B1_Bthird_props_r1_r
  free buf_B1_Bthird_props_r1_i
  free buf_B1_Bthird_diquark_r2_r
  free buf_B1_Bthird_diquark_r2_i
  free buf_B1_Bthird_diquark_r1_r
  free buf_B1_Bthird_diquark_r1_i
  free buf_B1_Bsecond_r2_r
  free buf_B1_Bsecond_r2_i
  free buf_B1_Bsecond_r1_r
  free buf_B1_Bsecond_r1_i
  free buf_B1_Bsecond_props_r2_r
  free buf_B1_Bsecond_props_r2_i
  free buf_B1_Bsecond_props_r1_r
  free buf_B1_Bsecond_props_r1_i
  free buf_B1_Blocal_r2_r
  free buf_B1_Blocal_r2_i
  free buf_B1_Blocal_r1_r
  free buf_B1_Blocal_r1_i
  free buf_B1_Blocal_props_r2_r
  free buf_B1_Blocal_props_r2_i
  free buf_B1_Blocal_props_r1_r
  free buf_B1_Blocal_props_r1_i
  free buf_B1_Blocal_diquark_r2_r
  free buf_B1_Blocal_diquark_r2_i
  free buf_B1_Blocal_diquark_r1_r
  free buf_B1_Blocal_diquark_r1_i
  free buf_B1_Bfirst_r2_r
  free buf_B1_Bfirst_r2_i
  free buf_B1_Bfirst_r1_r
  free buf_B1_Bfirst_r1_i
  free buf_B1_Bfirst_props_r2_r
  free buf_B1_Bfirst_props_r2_i
  free buf_B1_Bfirst_props_r1_r
  free buf_B1_Bfirst_props_r1_i
  free buf_B1_Bfirst_diquark_r2_r
  free buf_B1_Bfirst_diquark_r2_i
  free buf_B1_Bfirst_diquark_r1_r
  free buf_B1_Bfirst_diquark_r1_i
}
