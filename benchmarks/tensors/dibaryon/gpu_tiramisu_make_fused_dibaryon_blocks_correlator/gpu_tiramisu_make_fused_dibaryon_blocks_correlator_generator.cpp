#include <tiramisu/tiramisu.h>
#include <string.h>
#include "gpu_tiramisu_make_fused_dibaryon_blocks_correlator_wrapper.h"
#include "../../utils/complex_util.h"
#include "../../utils/util.h"

using namespace tiramisu;

#define VECTORIZED 0
#define PARALLEL 0

void generate_function(std::string name)
{
    tiramisu::init(name);
    tiramisu::init(name);

   int b;
   int NsrcTot = Nsrc+NsrcHex;
   int NsnkTot = Nsnk+NsnkHex;
   var nperm("nperm", 0, Nperms),
	r("r", 0, B2Nrows),
	rp("rp", 0, B2Nrows),
	q("q", 0, Nq),
	s("s", 0, 2),
	to("to", 0, 2),
	wnum("wnum", 0, Nw2),
	wnumHex("wnumHex", 0, Nw2Hex),
	wnumHexHex("wnumHexHex", 0, Nw2Hex),
	wnumBlock("wnumBlock", 0, Nw),
        t("t", 0, Lt),
	x("x", 0, Vsnk),
	x_out("x_out", 0, Vsnk/sites_per_rank),
	x_in("x_in", 0, sites_per_rank),
	x2("x2", 0, Vsnk),
        y("y", 0, Vsrc),
	y_out("y_out", 0, Vsrc/src_sites_per_rank),
	y_in("y_in", 0, src_sites_per_rank),
	m("m", 0, Nsrc),
	n("n", 0, Nsnk),
	ne("ne", 0, NEntangled),
	nue("nue", 0, Nsnk-NEntangled),
	mH("mH", 0, NsrcHex),
	nH("nH", 0, NsnkHex),
	mpmH("mpmH", 0, NsrcTot),
	npnH("npnH", 0, NsnkTot),
        tri("tri", 0, Nq),
        iCprime("iCprime", 0, Nc),
        iSprime("iSprime", 0, Ns),
        jCprime("jCprime", 0, Nc),
        jSprime("jSprime", 0, Ns),
        kCprime("kCprime", 0, Nc),
        kSprime("kSprime", 0, Ns);

   input C_r("C_r",      {t, x_out, x_in, rp, mpmH, r, npnH}, p_float64);
   input C_i("C_i",      {t, x_out, x_in, rp, mpmH, r, npnH}, p_float64);
   buffer buf_C_r_cpu("buf_C_r_cpu", {Lt, Vsnk/sites_per_rank, sites_per_rank, B2Nrows, NsrcTot, B2Nrows, NsnkTot}, p_float64, a_input);
   buffer buf_C_i_cpu("buf_C_i_cpu", {Lt, Vsnk/sites_per_rank, sites_per_rank, B2Nrows, NsrcTot, B2Nrows, NsnkTot}, p_float64, a_input);

   input B1_prop_r("B1_prop_r",   {tri, t, iCprime, iSprime, jCprime, jSprime, x, y}, p_float64);
   input B1_prop_i("B1_prop_i",   {tri, t, iCprime, iSprime, jCprime, jSprime, x, y}, p_float64);
   input B2_prop_r("B2_prop_r",   {tri, t, iCprime, iSprime, jCprime, jSprime, x, y}, p_float64);
   input B2_prop_i("B2_prop_i",   {tri, t, iCprime, iSprime, jCprime, jSprime, x, y}, p_float64);
   buffer buf_B1_prop_r_cpu("buf_B1_prop_r_cpu",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B1_prop_i_cpu("buf_B1_prop_i_cpu",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B2_prop_r_cpu("buf_B2_prop_r_cpu",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B2_prop_i_cpu("buf_B2_prop_i_cpu",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);

   buffer buf_B1_prop_r("B1_prop_r",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B1_prop_i("B1_prop_i",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B2_prop_r("B2_prop_r",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B2_prop_i("B2_prop_i",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buf_B1_prop_r.tag_gpu_global();
   buf_B1_prop_i.tag_gpu_global();
   buf_B2_prop_r.tag_gpu_global();
   buf_B2_prop_i.tag_gpu_global();

   B1_prop_r.store_in(&buf_B1_prop_r, {tri, t, iCprime, iSprime, jCprime, jSprime, x, y});
   B1_prop_i.store_in(&buf_B1_prop_i, {tri, t, iCprime, iSprime, jCprime, jSprime, x, y});
   B2_prop_r.store_in(&buf_B2_prop_r, {tri, t, iCprime, iSprime, jCprime, jSprime, x, y});
   B2_prop_i.store_in(&buf_B2_prop_i, {tri, t, iCprime, iSprime, jCprime, jSprime, x, y});

   input src_psi_B1_r("src_psi_B1_r",    {y, m}, p_float64);
   input src_psi_B1_i("src_psi_B1_i",    {y, m}, p_float64);
   input src_psi_B2_r("src_psi_B2_r",    {y, m}, p_float64);
   input src_psi_B2_i("src_psi_B2_i",    {y, m}, p_float64);
   input snk_psi_B1_r("snk_psi_B1_r",    {x, n}, p_float64);
   input snk_psi_B1_i("snk_psi_B1_i",    {x, n}, p_float64);
   input snk_psi_B2_r("snk_psi_B2_r",    {x, n}, p_float64);
   input snk_psi_B2_i("snk_psi_B2_i",    {x, n}, p_float64);
   input hex_src_psi_r("hex_src_psi_r",    {y, mH}, p_float64);
   input hex_src_psi_i("hex_src_psi_i",    {y, mH}, p_float64);
   input hex_snk_psi_r("hex_snk_psi_r",    {x, nH}, p_float64);
   input hex_snk_psi_i("hex_snk_psi_i",    {x, nH}, p_float64);
   input snk_psi_r("snk_psi_r", {x, x2, ne}, p_float64);
   input snk_psi_i("snk_psi_i", {x, x2, ne}, p_float64);

   buffer buf_src_psi_B1_r("src_psi_B1_r",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B1_i("src_psi_B1_i",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B2_r("src_psi_B2_r",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B2_i("src_psi_B2_i",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_snk_psi_B1_r("snk_psi_B1_r",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B1_i("snk_psi_B1_i",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B2_r("snk_psi_B2_r",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B2_i("snk_psi_B2_i",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_hex_src_psi_r("hex_src_psi_r",   {Vsrc, NsrcHex}, p_float64, a_temporary);
   buffer buf_hex_src_psi_i("hex_src_psi_i",   {Vsrc, NsrcHex}, p_float64, a_temporary);
   buffer buf_hex_snk_psi_r("hex_snk_psi_r",   {Vsnk, NsnkHex}, p_float64, a_temporary);
   buffer buf_hex_snk_psi_i("hex_snk_psi_i",   {Vsnk, NsnkHex}, p_float64, a_temporary);
   buffer buf_snk_psi_r("snk_psi_r",   {Vsnk, Vsnk, NEntangled}, p_float64, a_temporary);
   buffer buf_snk_psi_i("snk_psi_i",   {Vsnk, Vsnk, NEntangled}, p_float64, a_temporary);

   buf_src_psi_B1_r.tag_gpu_global();
   buf_src_psi_B1_i.tag_gpu_global();
   buf_src_psi_B2_r.tag_gpu_global();
   buf_src_psi_B2_i.tag_gpu_global();
   buf_snk_psi_B1_r.tag_gpu_global();
   buf_snk_psi_B1_i.tag_gpu_global();
   buf_snk_psi_B2_r.tag_gpu_global();
   buf_snk_psi_B2_i.tag_gpu_global();
   buf_hex_src_psi_r.tag_gpu_global();
   buf_hex_src_psi_i.tag_gpu_global();
   buf_hex_snk_psi_r.tag_gpu_global();
   buf_hex_snk_psi_i.tag_gpu_global();
   buf_snk_psi_r.tag_gpu_global();
   buf_snk_psi_i.tag_gpu_global();

      src_psi_B1_r.store_in(&buf_src_psi_B1_r, {y, m});
      src_psi_B1_i.store_in(&buf_src_psi_B1_i, {y, m});
      src_psi_B2_r.store_in(&buf_src_psi_B2_r, {y, m});
      src_psi_B2_i.store_in(&buf_src_psi_B2_i, {y, m});
      snk_psi_B1_r.store_in(&buf_snk_psi_B1_r, {x, n});
      snk_psi_B1_i.store_in(&buf_snk_psi_B1_i, {x, n});
      snk_psi_B2_r.store_in(&buf_snk_psi_B2_r, {x, n});
      snk_psi_B2_i.store_in(&buf_snk_psi_B2_i, {x, n});
      hex_src_psi_r.store_in(&buf_hex_src_psi_r, {y, mH});
      hex_src_psi_i.store_in(&buf_hex_src_psi_i, {y, mH});
      hex_snk_psi_r.store_in(&buf_hex_snk_psi_r, {x, nH});
      hex_snk_psi_i.store_in(&buf_hex_snk_psi_i, {x, nH});
      snk_psi_r.store_in(&buf_snk_psi_r, {x, x2, ne});
      snk_psi_i.store_in(&buf_snk_psi_i, {x, x2, ne});


   buffer buf_src_psi_B1_r_cpu("buf_src_psi_B1_r_cpu",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B1_i_cpu("buf_src_psi_B1_i_cpu",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B2_r_cpu("buf_src_psi_B2_r_cpu",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B2_i_cpu("buf_src_psi_B2_i_cpu",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_snk_psi_B1_r_cpu("buf_snk_psi_B1_r_cpu",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B1_i_cpu("buf_snk_psi_B1_i_cpu",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B2_r_cpu("buf_snk_psi_B2_r_cpu",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B2_i_cpu("buf_snk_psi_B2_i_cpu",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_hex_src_psi_r_cpu("buf_hex_src_psi_r_cpu",   {Vsrc, NsrcHex}, p_float64, a_temporary);
   buffer buf_hex_src_psi_i_cpu("buf_hex_src_psi_i_cpu",   {Vsrc, NsrcHex}, p_float64, a_temporary);
   buffer buf_hex_snk_psi_r_cpu("buf_hex_snk_psi_r_cpu",   {Vsnk, NsnkHex}, p_float64, a_temporary);
   buffer buf_hex_snk_psi_i_cpu("buf_hex_snk_psi_i_cpu",   {Vsnk, NsnkHex}, p_float64, a_temporary);
   buffer buf_snk_psi_r_cpu("buf_snk_psi_r_cpu",   {Vsnk, Vsnk, NEntangled}, p_float64, a_temporary);
   buffer buf_snk_psi_i_cpu("buf_snk_psi_i_cpu",   {Vsnk, Vsnk, NEntangled}, p_float64, a_temporary);

   input src_spins("src_spins", {rp, s, to}, p_int32);
   input src_spin_block_weights("src_spin_block_weights", {rp, s}, p_float64);
   input sigs("sigs", {nperm}, p_int32);
   input snk_b("snk_b", {nperm, q, to}, p_int32);
   input src_color_weights("src_color_weights", {r, wnumBlock, q}, p_int32);
   input src_spin_weights("src_spin_weights", {r, wnumBlock, q}, p_int32);
   input src_weights("src_weights", {r, wnumBlock}, p_float64);
   input snk_color_weights("snk_color_weights", {r, nperm, wnum, q, to}, p_int32);
   input snk_spin_weights("snk_spin_weights", {r, nperm, wnum, q, to}, p_int32);
   input snk_weights("snk_weights", {r, wnum}, p_float64);
   input hex_snk_color_weights("hex_snk_color_weights", {r, nperm, wnumHex, q, to}, p_int32);
   input hex_snk_spin_weights("hex_snk_spin_weights", {r, nperm, wnumHex, q, to}, p_int32);
   input hex_snk_weights("hex_snk_weights", {r, wnumHex}, p_float64);

   buffer buf_src_spins("src_spins",   {B2Nrows, 2, 2}, p_int32, a_temporary);
   buffer buf_src_spin_block_weights("src_spin_block_weights",   {B2Nrows, 2}, p_float64, a_temporary);
   buffer buf_sigs("sigs",   {Nperms}, p_int32, a_temporary);
   buffer buf_snk_b("snk_b",   {Nperms, Nq, 2}, p_int32, a_temporary);
   buffer buf_src_color_weights("src_color_weights",   {B2Nrows, Nw, Nq}, p_int32, a_temporary);
   buffer buf_src_spin_weights("src_spin_weights",   {B2Nrows, Nw, Nq}, p_int32, a_temporary);
   buffer buf_src_weights("src_weights",   {B2Nrows, Nw}, p_float64, a_temporary);
   buffer buf_snk_color_weights("snk_color_weights",   {B2Nrows, Nperms, Nw2, Nq, 2}, p_int32, a_temporary);
   buffer buf_snk_spin_weights("snk_spin_weights",   {B2Nrows, Nperms, Nw2, Nq, 2}, p_int32, a_temporary);
   buffer buf_snk_weights("snk_weights",   {B2Nrows, Nw2}, p_float64, a_temporary);
   buffer buf_hex_snk_color_weights("hex_snk_color_weights", {B2Nrows, Nperms, Nw2Hex, Nq, 2}, p_int32, a_temporary);
   buffer buf_hex_snk_spin_weights("hex_snk_spin_weights", {B2Nrows, Nperms, Nw2Hex, Nq, 2}, p_int32, a_temporary);
   buffer buf_hex_snk_weights("hex_snk_weights", {B2Nrows, Nw2Hex}, p_float64, a_temporary);

      buf_src_spins.tag_gpu_global();
      buf_src_spin_block_weights.tag_gpu_global();
      buf_sigs.tag_gpu_global();
      buf_snk_b.tag_gpu_global();
      buf_src_color_weights.tag_gpu_global();
      buf_src_spin_weights.tag_gpu_global();
      buf_src_weights.tag_gpu_global();
      buf_snk_color_weights.tag_gpu_global();
      buf_snk_spin_weights.tag_gpu_global();
      buf_snk_weights.tag_gpu_global();
      buf_hex_snk_color_weights.tag_gpu_global();
      buf_hex_snk_spin_weights.tag_gpu_global();
      buf_hex_snk_weights.tag_gpu_global();

      src_spins.store_in(&buf_src_spins, {rp, s, to});
      src_spin_block_weights.store_in(&buf_src_spin_block_weights, {rp, s});
      sigs.store_in(&buf_sigs, {nperm});
      snk_b.store_in(&buf_snk_b, {nperm, q, to});
      src_color_weights.store_in(&buf_src_color_weights, {r, wnumBlock, q});
      src_spin_weights.store_in(&buf_src_spin_weights, {r, wnumBlock, q});
      src_weights.store_in(&buf_src_weights, {r, wnumBlock});
      snk_color_weights.store_in(&buf_snk_color_weights, {r, nperm, wnum, q, to});
      snk_spin_weights.store_in(&buf_snk_spin_weights, {r, nperm, wnum, q, to});
      snk_weights.store_in(&buf_snk_weights, {r, wnum});
      hex_snk_color_weights.store_in(&buf_hex_snk_color_weights, {r, nperm, wnumHex, q, to});
      hex_snk_spin_weights.store_in(&buf_hex_snk_spin_weights, {r, nperm, wnumHex, q, to});
      hex_snk_weights.store_in(&buf_hex_snk_weights, {r, wnumHex});

   buffer buf_src_spins_cpu("buf_src_spins_cpu",   {B2Nrows, 2, 2}, p_int32, a_temporary);
   buffer buf_src_spin_block_weights_cpu("buf_src_spin_block_weights_cpu",   {B2Nrows, 2}, p_float64, a_temporary);
   buffer buf_sigs_cpu("buf_sigs_cpu",   {Nperms}, p_int32, a_temporary);
   buffer buf_snk_b_cpu("buf_snk_b_cpu",   {Nperms, Nq, 2}, p_int32, a_temporary);
   buffer buf_src_color_weights_cpu("buf_src_color_weights_cpu",   {B2Nrows, Nw, Nq}, p_int32, a_temporary);
   buffer buf_src_spin_weights_cpu("buf_src_spin_weights_cpu",   {B2Nrows, Nw, Nq}, p_int32, a_temporary);
   buffer buf_src_weights_cpu("buf_src_weights_cpu",   {B2Nrows, Nw}, p_float64, a_temporary);
   buffer buf_snk_color_weights_cpu("buf_snk_color_weights_cpu",   {B2Nrows, Nperms, Nw2, Nq, 2}, p_int32, a_temporary);
   buffer buf_snk_spin_weights_cpu("buf_snk_spin_weights_cpu",   {B2Nrows, Nperms, Nw2, Nq, 2}, p_int32, a_temporary);
   buffer buf_snk_weights_cpu("buf_snk_weights_cpu",   {B2Nrows, Nw2}, p_float64, a_temporary);
   buffer buf_hex_snk_color_weights_cpu("buf_hex_snk_color_weights_cpu", {B2Nrows, Nperms, Nw2Hex, Nq, 2}, p_int32, a_temporary);
   buffer buf_hex_snk_spin_weights_cpu("buf_hex_snk_spin_weights_cpu", {B2Nrows, Nperms, Nw2Hex, Nq, 2}, p_int32, a_temporary);
   buffer buf_hex_snk_weights_cpu("buf_hex_snk_weights_cpu", {B2Nrows, Nw2Hex}, p_float64, a_temporary);

    buffer buf_C_r("buf_C_r", {Lt, Vsnk/sites_per_rank, sites_per_rank, B2Nrows, NsrcTot, B2Nrows, NsnkTot}, p_float64, a_input);
    buf_C_r.tag_gpu_global();
    buffer buf_C_i("buf_C_i", {Lt, Vsnk/sites_per_rank, sites_per_rank, B2Nrows, NsrcTot, B2Nrows, NsnkTot}, p_float64, a_input);
    buf_C_i.tag_gpu_global();

    C_r.store_in(&buf_C_r, {t, x_out, x_in, rp, mpmH, r, npnH});
    C_i.store_in(&buf_C_i, {t, x_out, x_in, rp, mpmH, r, npnH});


    computation C_init_r("C_init_r", {t, x_out, x_in, rp, m, r, n}, expr((double) 0));
    computation C_init_i("C_init_i", {t, x_out, x_in, rp, m, r, n}, expr((double) 0));

    C_init_r.store_in(&buf_C_r, {t, x_out, x_in, rp, mpmH, r, npnH});
    C_init_i.store_in(&buf_C_i, {t, x_out, x_in, rp, mpmH, r, npnH});

    // computation flip_B1_Bfirst_r2_r_init("flip_B1_Bfirst_r2_r_init", {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime, m}, expr((double) 0));
    // computation flip_B1_Bfirst_r2_i_init("flip_B1_Bfirst_r2_i_init", {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime, m}, expr((double) 0));

    // complex_computation flip_B1_Bfirst_r2_init(&flip_B1_Bfirst_r2_r_init, &flip_B1_Bfirst_r2_i_init);

    // complex_computation flip_BB_BB_new_term_2_r2_b1("flip_BB_BB_new_term_2_r2_b1", {t, x_out, x_in, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bfirst_r2_init(t, x_out, x_in, x2, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), 0, 0, snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    // flip_BB_BB_new_term_2_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));


    computation copy_buf_C_r_device_to_host({}, memcpy(buf_C_r, buf_C_r_cpu));
    computation copy_buf_C_i_device_to_host({}, memcpy(buf_C_i, buf_C_i_cpu));
    computation copy_B1_prop_r_device_to_host({}, memcpy(*B1_prop_r.get_buffer(), buf_B1_prop_r_cpu));
    computation copy_B1_prop_i_device_to_host({}, memcpy(*B1_prop_i.get_buffer(), buf_B1_prop_i_cpu));
    computation copy_B2_prop_r_device_to_host({}, memcpy(*B2_prop_r.get_buffer(), buf_B2_prop_r_cpu));
    computation copy_B2_prop_i_device_to_host({}, memcpy(*B2_prop_i.get_buffer(), buf_B2_prop_i_cpu));
    computation copy_src_psi_B1_r_device_to_host({}, memcpy(*src_psi_B1_r.get_buffer(), buf_src_psi_B1_r_cpu));
    computation copy_src_psi_B1_i_device_to_host({}, memcpy(*src_psi_B1_i.get_buffer(), buf_src_psi_B1_i_cpu));
    computation copy_src_psi_B2_r_device_to_host({}, memcpy(*src_psi_B2_r.get_buffer(), buf_src_psi_B2_r_cpu));
    computation copy_src_psi_B2_i_device_to_host({}, memcpy(*src_psi_B2_i.get_buffer(), buf_src_psi_B2_i_cpu));
    computation copy_snk_psi_B1_r_device_to_host({}, memcpy(*snk_psi_B1_r.get_buffer(), buf_snk_psi_B1_r_cpu));
    computation copy_snk_psi_B1_i_device_to_host({}, memcpy(*snk_psi_B1_i.get_buffer(), buf_snk_psi_B1_i_cpu));
    computation copy_snk_psi_B2_r_device_to_host({}, memcpy(*snk_psi_B2_r.get_buffer(), buf_snk_psi_B2_r_cpu));
    computation copy_snk_psi_B2_i_device_to_host({}, memcpy(*snk_psi_B2_i.get_buffer(), buf_snk_psi_B2_i_cpu));
    computation copy_src_spins_device_to_host({}, memcpy(*src_spins.get_buffer(), buf_src_spins_cpu));
    computation copy_sigs_device_to_host({}, memcpy(*sigs.get_buffer(), buf_sigs_cpu));
    computation copy_snk_psi_r_device_to_host({}, memcpy(*snk_psi_r.get_buffer(), buf_snk_psi_r_cpu));
    computation copy_snk_psi_i_device_to_host({}, memcpy(*snk_psi_i.get_buffer(), buf_snk_psi_i_cpu));
    computation copy_hex_snk_psi_r_device_to_host({}, memcpy(*hex_snk_psi_r.get_buffer(), buf_hex_snk_psi_r_cpu));
    computation copy_hex_snk_psi_i_device_to_host({}, memcpy(*hex_snk_psi_i.get_buffer(), buf_hex_snk_psi_i_cpu));
    computation copy_src_color_weights_device_to_host({}, memcpy(*src_color_weights.get_buffer(), buf_src_color_weights_cpu));
    computation copy_src_spin_weights_device_to_host({}, memcpy(*src_spin_weights.get_buffer(), buf_src_spin_weights_cpu));
    computation copy_src_weights_device_to_host({}, memcpy(*src_weights.get_buffer(), buf_src_weights_cpu));
    computation copy_snk_color_weights_device_to_host({}, memcpy(*snk_color_weights.get_buffer(), buf_snk_color_weights_cpu));
    computation copy_snk_spin_weights_device_to_host({}, memcpy(*snk_spin_weights.get_buffer(), buf_snk_spin_weights_cpu));
    computation copy_snk_weights_device_to_host({}, memcpy(*snk_weights.get_buffer(), buf_snk_weights_cpu));
    computation copy_hex_snk_color_weights_device_to_host({}, memcpy(*hex_snk_color_weights.get_buffer(), buf_hex_snk_color_weights_cpu));
    computation copy_hex_snk_spin_weights_device_to_host({}, memcpy(*hex_snk_spin_weights.get_buffer(), buf_hex_snk_spin_weights_cpu));
    computation copy_hex_snk_weights_device_to_host({}, memcpy(*hex_snk_weights.get_buffer(), buf_hex_snk_weights_cpu));
    computation copy_src_spin_block_weights_device_to_host({}, memcpy(*src_spin_block_weights.get_buffer(), buf_src_spin_block_weights_cpu));
    computation copy_snk_b_device_to_host({}, memcpy(*snk_b.get_buffer(), buf_snk_b_cpu));
    
    computation copy_buf_C_r_host_to_device({}, memcpy(buf_C_r_cpu, buf_C_r));
    computation copy_buf_C_i_host_to_device({}, memcpy(buf_C_i_cpu, buf_C_i));
    computation copy_B1_prop_r_host_to_device({}, memcpy(buf_B1_prop_r_cpu, *B1_prop_r.get_buffer()));
    computation copy_B1_prop_i_host_to_device({}, memcpy(buf_B1_prop_i_cpu, *B1_prop_i.get_buffer()));
    computation copy_B2_prop_r_host_to_device({}, memcpy(buf_B2_prop_r_cpu, *B2_prop_r.get_buffer()));
    computation copy_B2_prop_i_host_to_device({}, memcpy(buf_B2_prop_i_cpu, *B2_prop_i.get_buffer()));
    computation copy_src_psi_B1_r_host_to_device({}, memcpy(buf_src_psi_B1_r_cpu, *src_psi_B1_r.get_buffer()));
    computation copy_src_psi_B1_i_host_to_device({}, memcpy(buf_src_psi_B1_i_cpu, *src_psi_B1_i.get_buffer()));
    computation copy_src_psi_B2_r_host_to_device({}, memcpy(buf_src_psi_B2_r_cpu, *src_psi_B2_r.get_buffer()));
    computation copy_src_psi_B2_i_host_to_device({}, memcpy(buf_src_psi_B2_i_cpu, *src_psi_B2_i.get_buffer()));
    computation copy_snk_psi_B1_r_host_to_device({}, memcpy(buf_snk_psi_B1_r_cpu, *snk_psi_B1_r.get_buffer()));
    computation copy_snk_psi_B1_i_host_to_device({}, memcpy(buf_snk_psi_B1_i_cpu, *snk_psi_B1_i.get_buffer()));
    computation copy_snk_psi_B2_r_host_to_device({}, memcpy(buf_snk_psi_B2_r_cpu, *snk_psi_B2_r.get_buffer()));
    computation copy_snk_psi_B2_i_host_to_device({}, memcpy(buf_snk_psi_B2_i_cpu, *snk_psi_B2_i.get_buffer()));
    computation copy_src_spins_host_to_device({}, memcpy(buf_src_spins_cpu, *src_spins.get_buffer()));
    computation copy_sigs_host_to_device({}, memcpy(buf_sigs_cpu, *sigs.get_buffer()));
    computation copy_snk_psi_r_host_to_device({}, memcpy(buf_snk_psi_r_cpu, *snk_psi_r.get_buffer()));
    computation copy_snk_psi_i_host_to_device({}, memcpy(buf_snk_psi_i_cpu, *snk_psi_i.get_buffer()));
    computation copy_hex_snk_psi_r_host_to_device({}, memcpy(buf_hex_snk_psi_r_cpu, *hex_snk_psi_r.get_buffer()));
    computation copy_hex_snk_psi_i_host_to_device({}, memcpy(buf_hex_snk_psi_i_cpu, *hex_snk_psi_i.get_buffer()));
    computation copy_src_color_weights_host_to_device({}, memcpy(buf_src_color_weights_cpu, *src_color_weights.get_buffer()));
    computation copy_src_spin_weights_host_to_device({}, memcpy(buf_src_spin_weights_cpu, *src_spin_weights.get_buffer()));
    computation copy_src_weights_host_to_device({}, memcpy(buf_src_weights_cpu, *src_weights.get_buffer()));
    computation copy_snk_color_weights_host_to_device({}, memcpy(buf_snk_color_weights_cpu, *snk_color_weights.get_buffer()));
    computation copy_snk_spin_weights_host_to_device({}, memcpy(buf_snk_spin_weights_cpu, *snk_spin_weights.get_buffer()));
    computation copy_snk_weights_host_to_device({}, memcpy(buf_snk_weights_cpu, *snk_weights.get_buffer()));
    computation copy_hex_snk_color_weights_host_to_device({}, memcpy(buf_hex_snk_color_weights_cpu, *hex_snk_color_weights.get_buffer()));
    computation copy_hex_snk_spin_weights_host_to_device({}, memcpy(buf_hex_snk_spin_weights_cpu, *hex_snk_spin_weights.get_buffer()));
    computation copy_hex_snk_weights_host_to_device({}, memcpy(buf_hex_snk_weights_cpu, *hex_snk_weights.get_buffer()));
    computation copy_src_spin_block_weights_host_to_device({}, memcpy(buf_src_spin_block_weights_cpu, *src_spin_block_weights.get_buffer()));
    computation copy_snk_b_host_to_device({}, memcpy(buf_snk_b_cpu, *snk_b.get_buffer()));



      C_init_r.tag_gpu_level(x_out, x_in);
      C_init_i.tag_gpu_level(x_out, x_in);
// // BB_BB

//       B1_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
//       B1_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);

//           B1_Bfirst_r1_r_init.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r1_i_init.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r1_r_init.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r1_i_init.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r1_r_init.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r1_i_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bfirst_r1_r_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bfirst_r1_i_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bsecond_r1_r_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bsecond_r1_i_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bthird_r1_r_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bthird_r1_i_init.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r1_r_props_init.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r1_i_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r1_r_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r1_i_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r1_r_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r1_i_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r1_r_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r1_i_props_init.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r1_r_diquark.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r1_i_diquark.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r1_r_diquark.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r1_i_diquark.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r1_r_diquark.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r1_i_diquark.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r1_r_props.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r1_i_props.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r1_r_props.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r1_i_props.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r1_r_props.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r1_i_props.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r1_r_props.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r1_i_props.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r1_r_update.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r1_i_update.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r1_r_update.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r1_i_update.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r1_r_update.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r1_i_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bfirst_r1_r_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bfirst_r1_i_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bsecond_r1_r_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bsecond_r1_i_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bthird_r1_r_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bthird_r1_i_update.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r2_r_init.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r2_i_init.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r2_r_init.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r2_i_init.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r2_r_init.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r2_i_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bfirst_r2_r_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bfirst_r2_i_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bsecond_r2_r_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bsecond_r2_i_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bthird_r2_r_init.tag_gpu_level(x_out, x_in);
//           flip_B1_Bthird_r2_i_init.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r2_r_props_init.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r2_i_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r2_r_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r2_i_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r2_r_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r2_i_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r2_r_props_init.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r2_i_props_init.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r2_r_diquark.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r2_i_diquark.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r2_r_diquark.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r2_i_diquark.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r2_r_diquark.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r2_i_diquark.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r2_r_props.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r2_i_props.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r2_r_props.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r2_i_props.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r2_r_props.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r2_i_props.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r2_r_props.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r2_i_props.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
//           B1_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r2_r_update.tag_gpu_level(x_out, x_in);
//           B1_Bfirst_r2_i_update.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r2_r_update.tag_gpu_level(x_out, x_in);
//           B1_Bsecond_r2_i_update.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r2_r_update.tag_gpu_level(x_out, x_in);
//           B1_Bthird_r2_i_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bfirst_r2_r_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bfirst_r2_i_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bsecond_r2_r_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bsecond_r2_i_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bthird_r2_r_update.tag_gpu_level(x_out, x_in);
//           flip_B1_Bthird_r2_i_update.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r1_r_init.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r1_i_init.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r1_r_init.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r1_i_init.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r1_r_init.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r1_i_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bfirst_r1_r_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bfirst_r1_i_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bsecond_r1_r_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bsecond_r1_i_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bthird_r1_r_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bthird_r1_i_init.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r1_r_props_init.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r1_i_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r1_r_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r1_i_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r1_r_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r1_i_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r1_r_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r1_i_props_init.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r1_r_diquark.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r1_i_diquark.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r1_r_diquark.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r1_i_diquark.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r1_r_diquark.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r1_i_diquark.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r1_r_props.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r1_i_props.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r1_r_props.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r1_i_props.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r1_r_props.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r1_i_props.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r1_r_props.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r1_i_props.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r1_r_update.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r1_i_update.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r1_r_update.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r1_i_update.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r1_r_update.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r1_i_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bfirst_r1_r_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bfirst_r1_i_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bsecond_r1_r_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bsecond_r1_i_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bthird_r1_r_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bthird_r1_i_update.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r2_r_init.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r2_i_init.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r2_r_init.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r2_i_init.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r2_r_init.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r2_i_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bfirst_r2_r_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bfirst_r2_i_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bsecond_r2_r_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bsecond_r2_i_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bthird_r2_r_init.tag_gpu_level(x_out, x_in);
//           flip_B2_Bthird_r2_i_init.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r2_r_props_init.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r2_i_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r2_r_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r2_i_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r2_r_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r2_i_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r2_r_props_init.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r2_i_props_init.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r2_r_diquark.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r2_i_diquark.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r2_r_diquark.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r2_i_diquark.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r2_r_diquark.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r2_i_diquark.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r2_r_props.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r2_i_props.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r2_r_props.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r2_i_props.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r2_r_props.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r2_i_props.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r2_r_props.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r2_i_props.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
//           B2_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r2_r_update.tag_gpu_level(x_out, x_in);
//           B2_Bfirst_r2_i_update.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r2_r_update.tag_gpu_level(x_out, x_in);
//           B2_Bsecond_r2_i_update.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r2_r_update.tag_gpu_level(x_out, x_in);
//           B2_Bthird_r2_i_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bfirst_r2_r_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bfirst_r2_i_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bsecond_r2_r_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bsecond_r2_i_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bthird_r2_r_update.tag_gpu_level(x_out, x_in);
//           flip_B2_Bthird_r2_i_update.tag_gpu_level(x_out, x_in);
//           C_BB_BB_prop_init_r.tag_gpu_level(x_out, x_in);
//           C_BB_BB_prop_init_i.tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_0_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_0_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_1_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_1_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_2_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_2_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_3_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_3_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_4_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_4_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_5_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_5_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_6_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_6_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_7_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_7_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_0_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_0_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_1_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_1_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_2_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_2_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_3_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_3_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_4_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_4_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_5_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_5_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_6_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_6_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_7_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_7_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_0_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_0_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_1_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_1_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_2_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_2_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_3_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_3_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_4_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_4_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_5_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_5_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_6_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_6_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_7_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_7_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_0_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_0_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_1_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_1_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_2_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_2_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_3_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_3_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_4_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_4_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_5_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_5_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_6_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_6_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_7_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_BB_new_term_7_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_0_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_0_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_1_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_1_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_2_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_2_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_3_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_3_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_4_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_4_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_5_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_5_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_6_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_6_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_7_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_7_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_0_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_0_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_1_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_1_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_2_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_2_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_3_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_3_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_4_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_4_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_5_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_5_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_6_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_6_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_7_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_7_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_0_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_0_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_1_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_1_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_2_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_2_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_3_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_3_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_4_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_4_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_5_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_5_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_6_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_6_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_7_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_7_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_0_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_0_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_1_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_1_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_2_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_2_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_3_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_3_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_4_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_4_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_5_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_5_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_6_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_6_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_7_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_BB_new_term_7_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           C_BB_BB_prop_update_r.tag_gpu_level(x_out, x_in);
//           C_BB_BB_prop_update_i.tag_gpu_level(x_out, x_in);
//           C_BB_BB_update_b_r.tag_gpu_level(x_out, x_in);
//           C_BB_BB_update_b_i.tag_gpu_level(x_out, x_in);
//           C_BB_BB_update_s_r.tag_gpu_level(x_out, x_in);
//           C_BB_BB_update_s_i.tag_gpu_level(x_out, x_in);

// // BB_H

//           src_B1_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
//           flip_src_B1_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
//           flip_src_B1_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r1_r_props_init.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r1_i_props_init.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r1_r_diquark.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r1_i_diquark.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r1_r_props.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r1_i_props.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
//           flip_src_B1_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
//           flip_src_B1_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
//           flip_src_B1_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
//           flip_src_B1_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r2_r_props_init.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r2_i_props_init.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r2_r_diquark.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r2_i_diquark.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r2_r_props.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r2_i_props.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
//           src_B1_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);
//           flip_src_B1_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
//           flip_src_B1_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
//           flip_src_B2_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
//           flip_src_B2_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r1_r_props_init.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r1_i_props_init.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r1_r_diquark.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r1_i_diquark.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r1_r_props.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r1_i_props.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
//           flip_src_B2_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
//           flip_src_B2_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
//           flip_src_B2_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
//           flip_src_B2_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r2_r_props_init.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r2_i_props_init.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r2_r_diquark.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r2_i_diquark.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r2_r_props.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r2_i_props.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
//           src_B2_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);
//           flip_src_B2_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
//           flip_src_B2_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);
//           C_BB_H_prop_init_r.tag_gpu_level(x_out, x_in);
//           C_BB_H_prop_init_i.tag_gpu_level(x_out, x_in);
//           BB_H_new_term_0_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_H_new_term_0_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_H_new_term_0_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           BB_H_new_term_0_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_H_new_term_0_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_H_new_term_0_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           BB_H_new_term_0_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           BB_H_new_term_0_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_H_new_term_0_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_H_new_term_0_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_H_new_term_0_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_H_new_term_0_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_H_new_term_0_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_H_new_term_0_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           flip_BB_H_new_term_0_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
//           flip_BB_H_new_term_0_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
//           C_BB_H_prop_update_r.tag_gpu_level(x_out, x_in);
//           C_BB_H_prop_update_i.tag_gpu_level(x_out, x_in);
//           C_BB_H_update_r.tag_gpu_level(x_out, x_in);
//           C_BB_H_update_i.tag_gpu_level(x_out, x_in);

//     // H_BB
//           snk_B1_Blocal_r1_r_init.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r1_i_init.tag_gpu_level(y_out, y_in);
//           flip_snk_B1_Blocal_r1_r_init.tag_gpu_level(y_out, y_in);
//           flip_snk_B1_Blocal_r1_i_init.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r1_r_props_init.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r1_i_props_init.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r1_r_diquark.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r1_i_diquark.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r1_r_props.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r1_i_props.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r1_r_update.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r1_i_update.tag_gpu_level(y_out, y_in);
//           flip_snk_B1_Blocal_r1_r_update.tag_gpu_level(y_out, y_in);
//           flip_snk_B1_Blocal_r1_i_update.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r2_r_init.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r2_i_init.tag_gpu_level(y_out, y_in);
//           flip_snk_B1_Blocal_r2_r_init.tag_gpu_level(y_out, y_in);
//           flip_snk_B1_Blocal_r2_i_init.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r2_r_props_init.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r2_i_props_init.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r2_r_diquark.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r2_i_diquark.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r2_r_props.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r2_i_props.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r2_r_update.tag_gpu_level(y_out, y_in);
//           snk_B1_Blocal_r2_i_update.tag_gpu_level(y_out, y_in);
//           flip_snk_B1_Blocal_r2_r_update.tag_gpu_level(y_out, y_in);
//           flip_snk_B1_Blocal_r2_i_update.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r1_r_init.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r1_i_init.tag_gpu_level(y_out, y_in);
//           flip_snk_B2_Blocal_r1_r_init.tag_gpu_level(y_out, y_in);
//           flip_snk_B2_Blocal_r1_i_init.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r1_r_props_init.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r1_i_props_init.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r1_r_diquark.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r1_i_diquark.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r1_r_props.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r1_i_props.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r1_r_update.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r1_i_update.tag_gpu_level(y_out, y_in);
//           flip_snk_B2_Blocal_r1_r_update.tag_gpu_level(y_out, y_in);
//           flip_snk_B2_Blocal_r1_i_update.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r2_r_init.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r2_i_init.tag_gpu_level(y_out, y_in);
//           flip_snk_B2_Blocal_r2_r_init.tag_gpu_level(y_out, y_in);
//           flip_snk_B2_Blocal_r2_i_init.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r2_r_props_init.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r2_i_props_init.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r2_r_diquark.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r2_i_diquark.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r2_r_props.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r2_i_props.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r2_r_update.tag_gpu_level(y_out, y_in);
//           flip_snk_B2_Blocal_r2_r_update.tag_gpu_level(y_out, y_in);
//           flip_snk_B2_Blocal_r2_i_update.tag_gpu_level(y_out, y_in);
//           snk_B2_Blocal_r2_i_update.tag_gpu_level(y_out, y_in);
//           C_H_BB_prop_init_r.tag_gpu_level(y_out, y_in);
//           C_H_BB_prop_init_i.tag_gpu_level(y_out, y_in);
//           H_BB_new_term_0_r1_b1.get_real()->tag_gpu_level(y_out, y_in);
//           H_BB_new_term_0_r1_b1.get_imag()->tag_gpu_level(y_out, y_in);
//           H_BB_new_term_0_r2_b1.get_real()->tag_gpu_level(y_out, y_in);
//           H_BB_new_term_0_r2_b1.get_imag()->tag_gpu_level(y_out, y_in);
//           H_BB_new_term_0_r1_b2.get_real()->tag_gpu_level(y_out, y_in);
//           H_BB_new_term_0_r1_b2.get_imag()->tag_gpu_level(y_out, y_in);
//           H_BB_new_term_0_r2_b2.get_real()->tag_gpu_level(y_out, y_in);
//           H_BB_new_term_0_r2_b2.get_imag()->tag_gpu_level(y_out, y_in);
//           flip_H_BB_new_term_0_r1_b1.get_real()->tag_gpu_level(y_out, y_in);
//           flip_H_BB_new_term_0_r1_b1.get_imag()->tag_gpu_level(y_out, y_in);
//           flip_H_BB_new_term_0_r2_b1.get_real()->tag_gpu_level(y_out, y_in);
//           flip_H_BB_new_term_0_r2_b1.get_imag()->tag_gpu_level(y_out, y_in);
//           flip_H_BB_new_term_0_r1_b2.get_real()->tag_gpu_level(y_out, y_in);
//           flip_H_BB_new_term_0_r1_b2.get_imag()->tag_gpu_level(y_out, y_in);
//           flip_H_BB_new_term_0_r2_b2.get_real()->tag_gpu_level(y_out, y_in);
//           flip_H_BB_new_term_0_r2_b2.get_imag()->tag_gpu_level(y_out, y_in);
//           C_H_BB_prop_update_r.tag_gpu_level(y_out, y_in);
//           C_H_BB_prop_update_i.tag_gpu_level(y_out, y_in);
//           C_H_BB_update_r.tag_gpu_level(y_out, y_in);
//           C_H_BB_update_i.tag_gpu_level(y_out, y_in);

//     // H_H
//           C_H_H_prop_init_r.tag_gpu_level(x_out, x_in);
//           C_H_H_prop_init_i.tag_gpu_level(x_out, x_in);
//           C_H_H_prop_update_r.tag_gpu_level(x_out, x_in);
//           C_H_H_prop_update_i.tag_gpu_level(x_out, x_in);
//           C_H_H_update_r.tag_gpu_level(x_out, x_in);
//           C_H_H_update_i.tag_gpu_level(x_out, x_in);

    // -------------------------------------------------------
    // Layer II
    // -------------------------------------------------------

      computation* handle = &copy_buf_C_r_host_to_device.then(copy_buf_C_i_host_to_device, computation::root);
      handle = &handle->then(copy_B1_prop_r_host_to_device, computation::root);
      handle = &handle->then(copy_B1_prop_i_host_to_device, computation::root);
      handle = &handle->then(copy_B2_prop_r_host_to_device, computation::root);
      handle = &handle->then(copy_B2_prop_i_host_to_device, computation::root);
      handle = &handle->then(copy_src_psi_B1_r_host_to_device, computation::root);
      handle = &handle->then(copy_src_psi_B1_i_host_to_device, computation::root);
      handle = &handle->then(copy_src_psi_B2_r_host_to_device, computation::root);
      handle = &handle->then(copy_src_psi_B2_i_host_to_device, computation::root);
      handle = &handle->then(copy_snk_psi_B1_r_host_to_device, computation::root);
      handle = &handle->then(copy_snk_psi_B1_i_host_to_device, computation::root);
      handle = &handle->then(copy_snk_psi_B2_r_host_to_device, computation::root);
      handle = &handle->then(copy_snk_psi_B2_i_host_to_device, computation::root);
      handle = &handle->then(copy_src_spins_host_to_device, computation::root);
      handle = &handle->then(copy_sigs_host_to_device, computation::root);
      handle = &handle->then(copy_snk_psi_r_host_to_device, computation::root);
      handle = &handle->then(copy_snk_psi_i_host_to_device, computation::root);
      handle = &handle->then(copy_hex_snk_psi_r_host_to_device, computation::root);
      handle = &handle->then(copy_hex_snk_psi_i_host_to_device, computation::root);
      handle = &handle->then(copy_src_color_weights_host_to_device, computation::root);
      handle = &handle->then(copy_src_spin_weights_host_to_device, computation::root);
      handle = &handle->then(copy_src_weights_host_to_device, computation::root);
      handle = &handle->then(copy_snk_color_weights_host_to_device, computation::root);
      handle = &handle->then(copy_snk_spin_weights_host_to_device, computation::root);
      handle = &handle->then(copy_snk_weights_host_to_device, computation::root);
      handle = &handle->then(copy_hex_snk_color_weights_host_to_device, computation::root);
      handle = &handle->then(copy_hex_snk_spin_weights_host_to_device, computation::root);
      handle = &handle->then(copy_hex_snk_weights_host_to_device, computation::root);
      handle = &handle->then(copy_src_spin_block_weights_host_to_device, computation::root);
      handle = &handle->then(copy_snk_b_host_to_device, computation::root);

    handle = &(handle->then(C_init_r, computation::root).then(C_init_i, npnH));

    // BB_BB
    // {
    // handle = &(handle
    //       ->then(B1_Blocal_r1_r_init, computation::root)
    //       .then(B1_Blocal_r1_i_init, m)
    //       .then(B1_Bfirst_r1_r_init, m)
    //       .then(B1_Bfirst_r1_i_init, m)
    //       .then(B1_Bsecond_r1_r_init, m)
    //       .then(B1_Bsecond_r1_i_init, m)
    //       .then(B1_Bthird_r1_r_init, m)
    //       .then(B1_Bthird_r1_i_init, m)
    //       .then(flip_B1_Blocal_r1_r_init, m)
    //       .then(flip_B1_Blocal_r1_i_init, m)
    //       .then(flip_B1_Bfirst_r1_r_init, m)
    //       .then(flip_B1_Bfirst_r1_i_init, m)
    //       .then(flip_B1_Bsecond_r1_r_init, m)
    //       .then(flip_B1_Bsecond_r1_i_init, m)
    //       .then(flip_B1_Bthird_r1_r_init, m)
    //       .then(flip_B1_Bthird_r1_i_init, m)

    //       .then(B1_Blocal_r1_r_props_init, x2)
    //       .then(B1_Blocal_r1_i_props_init, jSprime)
    //       .then(B1_Bfirst_r1_r_props_init, jSprime)
    //       .then(B1_Bfirst_r1_i_props_init, jSprime)
    //       .then(B1_Bsecond_r1_r_props_init, jSprime)
    //       .then(B1_Bsecond_r1_i_props_init, jSprime)
    //       .then(B1_Bthird_r1_r_props_init, jSprime)
    //       .then(B1_Bthird_r1_i_props_init, jSprime)

    //       .then(B1_Blocal_r1_r_diquark, y)
    //       .then(B1_Blocal_r1_i_diquark, wnumBlock)
    //       .then(B1_Bfirst_r1_r_diquark, wnumBlock)
    //       .then(B1_Bfirst_r1_i_diquark, wnumBlock)
    //       .then(B1_Bthird_r1_r_diquark, wnumBlock)
    //       .then(B1_Bthird_r1_i_diquark, wnumBlock)
    //       .then(B1_Blocal_r1_r_props, wnumBlock)
    //       .then(B1_Blocal_r1_i_props, jSprime)
    //       .then(B1_Bfirst_r1_r_props, jSprime)
    //       .then(B1_Bfirst_r1_i_props, jSprime)
    //       .then(B1_Bsecond_r1_r_props, jSprime)
    //       .then(B1_Bsecond_r1_i_props, jSprime)
    //       .then(B1_Bthird_r1_r_props, jSprime)
    //       .then(B1_Bthird_r1_i_props, jSprime)
    //       .then(B1_Blocal_r1_r_update, y)
    //       .then(B1_Blocal_r1_i_update, m)
    //       .then(B1_Bfirst_r1_r_update, m)
    //       .then(B1_Bfirst_r1_i_update, m)
    //       .then(B1_Bsecond_r1_r_update, m)
    //       .then(B1_Bsecond_r1_i_update, m)
    //       .then(B1_Bthird_r1_r_update, m)
    //       .then(B1_Bthird_r1_i_update, m)
    //       .then(flip_B1_Blocal_r1_r_update, m)
    //       .then(flip_B1_Blocal_r1_i_update, m)
    //       .then(flip_B1_Bfirst_r1_r_update, m)
    //       .then(flip_B1_Bfirst_r1_i_update, m)
    //       .then(flip_B1_Bsecond_r1_r_update, m)
    //       .then(flip_B1_Bsecond_r1_i_update, m)
    //       .then(flip_B1_Bthird_r1_r_update, m)
    //       .then(flip_B1_Bthird_r1_i_update, m)
    //       .then(B1_Blocal_r2_r_init, x2)
    //       .then(B1_Blocal_r2_i_init, m)
    //       .then(B1_Bfirst_r2_r_init, m)
    //       .then(B1_Bfirst_r2_i_init, m)
    //       .then(B1_Bsecond_r2_r_init, m)
    //       .then(B1_Bsecond_r2_i_init, m)
    //       .then(B1_Bthird_r2_r_init, m)
    //       .then(B1_Bthird_r2_i_init, m)
    //       .then(flip_B1_Blocal_r2_r_init, m)
    //       .then(flip_B1_Blocal_r2_i_init, m)
    //       .then(flip_B1_Bfirst_r2_r_init, m)
    //       .then(flip_B1_Bfirst_r2_i_init, m)
    //       .then(flip_B1_Bsecond_r2_r_init, m)
    //       .then(flip_B1_Bsecond_r2_i_init, m)
    //       .then(flip_B1_Bthird_r2_r_init, m)
    //       .then(flip_B1_Bthird_r2_i_init, m)
    //       .then(B1_Blocal_r2_r_props_init, x2) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Blocal_r2_i_props_init, jSprime) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Bfirst_r2_r_props_init, jSprime) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Bfirst_r2_i_props_init, jSprime) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Bsecond_r2_r_props_init, jSprime) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Bsecond_r2_i_props_init, jSprime) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Bthird_r2_r_props_init, jSprime) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Bthird_r2_i_props_init, jSprime) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Blocal_r2_r_diquark, y) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Blocal_r2_i_diquark, wnumBlock) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Bfirst_r2_r_diquark, wnumBlock) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Bfirst_r2_i_diquark, wnumBlock) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Bthird_r2_r_diquark, wnumBlock) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Bthird_r2_i_diquark, wnumBlock) // {t, x_out, x_in, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
    //       .then(B1_Blocal_r2_r_props, wnumBlock)
    //       .then(B1_Blocal_r2_i_props, jSprime)
    //       .then(B1_Bfirst_r2_r_props, jSprime)
    //       .then(B1_Bfirst_r2_i_props, jSprime)
    //       .then(B1_Bsecond_r2_r_props, jSprime)
    //       .then(B1_Bsecond_r2_i_props, jSprime)
    //       .then(B1_Bthird_r2_r_props, jSprime)
    //       .then(B1_Bthird_r2_i_props, jSprime)
    //       .then(B1_Blocal_r2_r_update, y)
    //       .then(B1_Blocal_r2_i_update, m)
    //       .then(B1_Bfirst_r2_r_update, m)
    //       .then(B1_Bfirst_r2_i_update, m)
    //       .then(B1_Bsecond_r2_r_update, m)
    //       .then(B1_Bsecond_r2_i_update, m)
    //       .then(B1_Bthird_r2_r_update, m)
    //       .then(B1_Bthird_r2_i_update, m)
    //       .then(flip_B1_Blocal_r2_r_update, m)
    //       .then(flip_B1_Blocal_r2_i_update, m)
    //       .then(flip_B1_Bfirst_r2_r_update, m)
    //       .then(flip_B1_Bfirst_r2_i_update, m)
    //       .then(flip_B1_Bsecond_r2_r_update, m)
    //       .then(flip_B1_Bsecond_r2_i_update, m)
    //       .then(flip_B1_Bthird_r2_r_update, m)
    //       .then(flip_B1_Bthird_r2_i_update, m)
    //       .then(B2_Blocal_r1_r_init, x2)
    //       .then(B2_Blocal_r1_i_init, m)
    //       .then(B2_Bfirst_r1_r_init, m)
    //       .then(B2_Bfirst_r1_i_init, m)
    //       .then(B2_Bsecond_r1_r_init, m)
    //       .then(B2_Bsecond_r1_i_init, m)
    //       .then(B2_Bthird_r1_r_init, m)
    //       .then(B2_Bthird_r1_i_init, m)
    //       .then(flip_B2_Blocal_r1_r_init, m)
    //       .then(flip_B2_Blocal_r1_i_init, m)
    //       .then(flip_B2_Bfirst_r1_r_init, m)
    //       .then(flip_B2_Bfirst_r1_i_init, m)
    //       .then(flip_B2_Bsecond_r1_r_init, m)
    //       .then(flip_B2_Bsecond_r1_i_init, m)
    //       .then(flip_B2_Bthird_r1_r_init, m)
    //       .then(flip_B2_Bthird_r1_i_init, m)
    //       .then(B2_Blocal_r1_r_props_init, x2)
    //       .then(B2_Blocal_r1_i_props_init, jSprime)
    //       .then(B2_Bfirst_r1_r_props_init, jSprime)
    //       .then(B2_Bfirst_r1_i_props_init, jSprime)
    //       .then(B2_Bsecond_r1_r_props_init, jSprime)
    //       .then(B2_Bsecond_r1_i_props_init, jSprime)
    //       .then(B2_Bthird_r1_r_props_init, jSprime)
    //       .then(B2_Bthird_r1_i_props_init, jSprime)
    //       .then(B2_Blocal_r1_r_diquark, y)
    //       .then(B2_Blocal_r1_i_diquark, wnumBlock)
    //       .then(B2_Bfirst_r1_r_diquark, wnumBlock)
    //       .then(B2_Bfirst_r1_i_diquark, wnumBlock)
    //       .then(B2_Bthird_r1_r_diquark, wnumBlock)
    //       .then(B2_Bthird_r1_i_diquark, wnumBlock)
    //       .then(B2_Blocal_r1_r_props, wnumBlock)
    //       .then(B2_Blocal_r1_i_props, jSprime)
    //       .then(B2_Bfirst_r1_r_props, jSprime)
    //       .then(B2_Bfirst_r1_i_props, jSprime)
    //       .then(B2_Bsecond_r1_r_props, jSprime)
    //       .then(B2_Bsecond_r1_i_props, jSprime)
    //       .then(B2_Bthird_r1_r_props, jSprime)
    //       .then(B2_Bthird_r1_i_props, jSprime)
    //       .then(B2_Blocal_r1_r_update, y)
    //       .then(B2_Blocal_r1_i_update, m)
    //       .then(B2_Bfirst_r1_r_update, m)
    //       .then(B2_Bfirst_r1_i_update, m)
    //       .then(B2_Bsecond_r1_r_update, m)
    //       .then(B2_Bsecond_r1_i_update, m)
    //       .then(B2_Bthird_r1_r_update, m)
    //       .then(B2_Bthird_r1_i_update, m)
    //       .then(flip_B2_Blocal_r1_r_update, m)
    //       .then(flip_B2_Blocal_r1_i_update, m)
    //       .then(flip_B2_Bfirst_r1_r_update, m)
    //       .then(flip_B2_Bfirst_r1_i_update, m)
    //       .then(flip_B2_Bsecond_r1_r_update, m)
    //       .then(flip_B2_Bsecond_r1_i_update, m)
    //       .then(flip_B2_Bthird_r1_r_update, m)
    //       .then(flip_B2_Bthird_r1_i_update, m)
    //       .then(B2_Blocal_r2_r_init, x2)
    //       .then(B2_Blocal_r2_i_init, m)
    //       .then(B2_Bfirst_r2_r_init, m)
    //       .then(B2_Bfirst_r2_i_init, m)
    //       .then(B2_Bsecond_r2_r_init, m)
    //       .then(B2_Bsecond_r2_i_init, m)
    //       .then(B2_Bthird_r2_r_init, m)
    //       .then(B2_Bthird_r2_i_init, m)
    //       .then(flip_B2_Blocal_r2_r_init, m)
    //       .then(flip_B2_Blocal_r2_i_init, m)
    //       .then(flip_B2_Bfirst_r2_r_init, m)
    //       .then(flip_B2_Bfirst_r2_i_init, m)
    //       .then(flip_B2_Bsecond_r2_r_init, m)
    //       .then(flip_B2_Bsecond_r2_i_init, m)
    //       .then(flip_B2_Bthird_r2_r_init, m)
    //       .then(flip_B2_Bthird_r2_i_init, m)
    //       .then(B2_Blocal_r2_r_props_init, x2)
    //       .then(B2_Blocal_r2_i_props_init, jSprime)
    //       .then(B2_Bfirst_r2_r_props_init, jSprime)
    //       .then(B2_Bfirst_r2_i_props_init, jSprime)
    //       .then(B2_Bsecond_r2_r_props_init, jSprime)
    //       .then(B2_Bsecond_r2_i_props_init, jSprime)
    //       .then(B2_Bthird_r2_r_props_init, jSprime)
    //       .then(B2_Bthird_r2_i_props_init, jSprime)
    //       .then(B2_Blocal_r2_r_diquark, y)
    //       .then(B2_Blocal_r2_i_diquark, wnumBlock)
    //       .then(B2_Bfirst_r2_r_diquark, wnumBlock)
    //       .then(B2_Bfirst_r2_i_diquark, wnumBlock)
    //       .then(B2_Bthird_r2_r_diquark, wnumBlock)
    //       .then(B2_Bthird_r2_i_diquark, wnumBlock)
    //       .then(B2_Blocal_r2_r_props, wnumBlock)
    //       .then(B2_Blocal_r2_i_props, jSprime)
    //       .then(B2_Bfirst_r2_r_props, jSprime)
    //       .then(B2_Bfirst_r2_i_props, jSprime)
    //       .then(B2_Bsecond_r2_r_props, jSprime)
    //       .then(B2_Bsecond_r2_i_props, jSprime)
    //       .then(B2_Bthird_r2_r_props, jSprime)
    //       .then(B2_Bthird_r2_i_props, jSprime)
    //       .then(B2_Blocal_r2_r_update, y)
    //       .then(B2_Blocal_r2_i_update, m)
    //       .then(B2_Bfirst_r2_r_update, m)
    //       .then(B2_Bfirst_r2_i_update, m)
    //       .then(B2_Bsecond_r2_r_update, m)
    //       .then(B2_Bsecond_r2_i_update, m)
    //       .then(B2_Bthird_r2_r_update, m)
    //       .then(B2_Bthird_r2_i_update, m)
    //       .then(flip_B2_Blocal_r2_r_update, m)
    //       .then(flip_B2_Blocal_r2_i_update, m)
    //       .then(flip_B2_Bfirst_r2_r_update, m)
    //       .then(flip_B2_Bfirst_r2_i_update, m)
    //       .then(flip_B2_Bsecond_r2_r_update, m)
    //       .then(flip_B2_Bsecond_r2_i_update, m)
    //       .then(flip_B2_Bthird_r2_r_update, m)
    //       .then(flip_B2_Bthird_r2_i_update, m)
    //       .then(C_BB_BB_prop_init_r, x2)
    //       .then(C_BB_BB_prop_init_i, r)
    //       .then( *(BB_BB_new_term_0_r1_b1.get_real()), r)
    //       .then( *(BB_BB_new_term_0_r1_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_1_r1_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_1_r1_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_2_r1_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_2_r1_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_3_r1_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_3_r1_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_4_r1_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_4_r1_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_5_r1_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_5_r1_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_6_r1_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_6_r1_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_7_r1_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_7_r1_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_0_r2_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_0_r2_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_1_r2_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_1_r2_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_2_r2_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_2_r2_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_3_r2_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_3_r2_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_4_r2_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_4_r2_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_5_r2_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_5_r2_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_6_r2_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_6_r2_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_7_r2_b1.get_real()), wnum)
    //       .then( *(BB_BB_new_term_7_r2_b1.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_0_r1_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_0_r1_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_1_r1_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_1_r1_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_2_r1_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_2_r1_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_3_r1_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_3_r1_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_4_r1_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_4_r1_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_5_r1_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_5_r1_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_6_r1_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_6_r1_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_7_r1_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_7_r1_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_0_r2_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_0_r2_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_1_r2_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_1_r2_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_2_r2_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_2_r2_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_3_r2_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_3_r2_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_4_r2_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_4_r2_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_5_r2_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_5_r2_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_6_r2_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_6_r2_b2.get_imag()), wnum)
    //       .then( *(BB_BB_new_term_7_r2_b2.get_real()), wnum)
    //       .then( *(BB_BB_new_term_7_r2_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_0_r1_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_0_r1_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_1_r1_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_1_r1_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_2_r1_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_2_r1_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_3_r1_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_3_r1_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_4_r1_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_4_r1_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_5_r1_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_5_r1_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_6_r1_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_6_r1_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_7_r1_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_7_r1_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_0_r2_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_0_r2_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_1_r2_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_1_r2_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_2_r2_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_2_r2_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_3_r2_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_3_r2_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_4_r2_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_4_r2_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_5_r2_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_5_r2_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_6_r2_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_6_r2_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_7_r2_b1.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_7_r2_b1.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_0_r1_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_0_r1_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_1_r1_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_1_r1_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_2_r1_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_2_r1_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_3_r1_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_3_r1_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_4_r1_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_4_r1_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_5_r1_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_5_r1_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_6_r1_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_6_r1_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_7_r1_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_7_r1_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_0_r2_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_0_r2_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_1_r2_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_1_r2_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_2_r2_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_2_r2_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_3_r2_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_3_r2_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_4_r2_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_4_r2_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_5_r2_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_5_r2_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_6_r2_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_6_r2_b2.get_imag()), wnum)
    //       .then( *(flip_BB_BB_new_term_7_r2_b2.get_real()), wnum)
    //       .then( *(flip_BB_BB_new_term_7_r2_b2.get_imag()), wnum)
    //       .then(C_BB_BB_prop_update_r, wnum)
    //       .then(C_BB_BB_prop_update_i, wnum)
    //       .then(C_BB_BB_update_b_r, r)
    //       .then(C_BB_BB_update_b_i, ne)
    //       .then(C_BB_BB_update_s_r, r)
    //       .then(C_BB_BB_update_s_i, nue)
    //       );
    // }

    // // BB_H
    // {
    // handle = &(handle
    //       ->then(src_B1_Blocal_r1_r_init, t)
    //       .then(src_B1_Blocal_r1_i_init, jSprime)
    //       .then(flip_src_B1_Blocal_r1_r_init, jSprime)
    //       .then(flip_src_B1_Blocal_r1_i_init, jSprime)
    //       .then(src_B1_Blocal_r1_r_props_init, x_in)
    //       .then(src_B1_Blocal_r1_i_props_init, jSprime)
    //       .then(src_B1_Blocal_r1_r_diquark, y)
    //       .then(src_B1_Blocal_r1_i_diquark, wnumBlock)
    //       .then(src_B1_Blocal_r1_r_props, wnumBlock)
    //       .then(src_B1_Blocal_r1_i_props, jSprime)
    //       .then(src_B1_Blocal_r1_r_update, y)
    //       .then(src_B1_Blocal_r1_i_update, m)
    //       .then(flip_src_B1_Blocal_r1_r_update, m)
    //       .then(flip_src_B1_Blocal_r1_i_update, m)
    //       .then(src_B1_Blocal_r2_r_init, x_in)
    //       .then(src_B1_Blocal_r2_i_init, jSprime)
    //       .then(flip_src_B1_Blocal_r2_r_init, jSprime)
    //       .then(flip_src_B1_Blocal_r2_i_init, jSprime)
    //       .then(src_B1_Blocal_r2_r_props_init, x_in)
    //       .then(src_B1_Blocal_r2_i_props_init, jSprime)
    //       .then(src_B1_Blocal_r2_r_diquark, y)
    //       .then(src_B1_Blocal_r2_i_diquark, wnumBlock)
    //       .then(src_B1_Blocal_r2_r_props, wnumBlock)
    //       .then(src_B1_Blocal_r2_i_props, jSprime)
    //       .then(src_B1_Blocal_r2_r_update, y)
    //       .then(src_B1_Blocal_r2_i_update, m)
    //       .then(flip_src_B1_Blocal_r2_r_update, m)
    //       .then(flip_src_B1_Blocal_r2_i_update, m)
    //       .then(src_B2_Blocal_r1_r_init, x_in)
    //       .then(src_B2_Blocal_r1_i_init, jSprime)
    //       .then(flip_src_B2_Blocal_r1_r_init, jSprime)
    //       .then(flip_src_B2_Blocal_r1_i_init, jSprime)
    //       .then(src_B2_Blocal_r1_r_props_init, x_in)
    //       .then(src_B2_Blocal_r1_i_props_init, jSprime)
    //       .then(src_B2_Blocal_r1_r_diquark, y)
    //       .then(src_B2_Blocal_r1_i_diquark, wnumBlock)
    //       .then(src_B2_Blocal_r1_r_props, wnumBlock)
    //       .then(src_B2_Blocal_r1_i_props, jSprime)
    //       .then(src_B2_Blocal_r1_r_update, y)
    //       .then(src_B2_Blocal_r1_i_update, m)
    //       .then(flip_src_B2_Blocal_r1_r_update, m)
    //       .then(flip_src_B2_Blocal_r1_i_update, m)
    //       .then(src_B2_Blocal_r2_r_init, x_in)
    //       .then(src_B2_Blocal_r2_i_init, jSprime)
    //       .then(flip_src_B2_Blocal_r2_r_init, jSprime)
    //       .then(flip_src_B2_Blocal_r2_i_init, jSprime)
    //       .then(src_B2_Blocal_r2_r_props_init, x_in)
    //       .then(src_B2_Blocal_r2_i_props_init, jSprime)
    //       .then(src_B2_Blocal_r2_r_diquark, y)
    //       .then(src_B2_Blocal_r2_i_diquark, wnumBlock)
    //       .then(src_B2_Blocal_r2_r_props, wnumBlock)
    //       .then(src_B2_Blocal_r2_i_props, jSprime)
    //       .then(src_B2_Blocal_r2_r_update, y)
    //       .then(src_B2_Blocal_r2_i_update, m)
    //       .then(flip_src_B2_Blocal_r2_r_update, m)
    //       .then(flip_src_B2_Blocal_r2_i_update, m)
    //      .then(C_BB_H_prop_init_r, x_in)
    //       .then(C_BB_H_prop_init_i, r)
    //       .then( *(BB_H_new_term_0_r1_b1.get_real()), r)
    //       .then( *(BB_H_new_term_0_r1_b1.get_imag()), wnumHex)
    //       .then( *(BB_H_new_term_0_r2_b1.get_real()), wnumHex)
    //       .then( *(BB_H_new_term_0_r2_b1.get_imag()), wnumHex)
    //       .then( *(BB_H_new_term_0_r1_b2.get_real()), wnumHex)
    //       .then( *(BB_H_new_term_0_r1_b2.get_imag()), wnumHex)
    //       .then( *(BB_H_new_term_0_r2_b2.get_real()), wnumHex)
    //       .then( *(BB_H_new_term_0_r2_b2.get_imag()), wnumHex)
    //       .then( *(flip_BB_H_new_term_0_r1_b1.get_real()), wnumHex)
    //       .then( *(flip_BB_H_new_term_0_r1_b1.get_imag()), wnumHex)
    //       .then( *(flip_BB_H_new_term_0_r2_b1.get_real()), wnumHex)
    //       .then( *(flip_BB_H_new_term_0_r2_b1.get_imag()), wnumHex)
    //       .then( *(flip_BB_H_new_term_0_r1_b2.get_real()), wnumHex)
    //       .then( *(flip_BB_H_new_term_0_r1_b2.get_imag()), wnumHex)
    //       .then( *(flip_BB_H_new_term_0_r2_b2.get_real()), wnumHex)
    //       .then( *(flip_BB_H_new_term_0_r2_b2.get_imag()), wnumHex)
    //       .then(C_BB_H_prop_update_r, wnumHex)
    //       .then(C_BB_H_prop_update_i, wnumHex)
    //       .then(C_BB_H_update_r, r)
    //       .then(C_BB_H_update_i, nH)
    //       );
    // }

    // // H_BB
    // {
    // handle = &(handle
    //       ->then(snk_B1_Blocal_r1_r_init, t)
    //       .then(snk_B1_Blocal_r1_i_init, jSprime)
    //       .then(flip_snk_B1_Blocal_r1_r_init, jSprime)
    //       .then(flip_snk_B1_Blocal_r1_i_init, jSprime)
    //       .then(snk_B1_Blocal_r1_r_props_init, y_in)
    //       .then(snk_B1_Blocal_r1_i_props_init, jSprime)
    //       .then(snk_B1_Blocal_r1_r_diquark, x)
    //       .then(snk_B1_Blocal_r1_i_diquark, wnumBlock)
    //       .then(snk_B1_Blocal_r1_r_props, wnumBlock)
    //       .then(snk_B1_Blocal_r1_i_props, jSprime)
    //       .then(snk_B1_Blocal_r1_r_update, x)
    //       .then(snk_B1_Blocal_r1_i_update, n)
    //       .then(flip_snk_B1_Blocal_r1_r_update, n)
    //       .then(flip_snk_B1_Blocal_r1_i_update, n)
    //       .then(snk_B1_Blocal_r2_r_init, y_in)
    //       .then(snk_B1_Blocal_r2_i_init, jSprime)
    //       .then(flip_snk_B1_Blocal_r2_r_init, jSprime)
    //       .then(flip_snk_B1_Blocal_r2_i_init, jSprime)
    //       .then(snk_B1_Blocal_r2_r_props_init, y_in)
    //       .then(snk_B1_Blocal_r2_i_props_init, jSprime)
    //       .then(snk_B1_Blocal_r2_r_diquark, x)
    //       .then(snk_B1_Blocal_r2_i_diquark, wnumBlock)
    //       .then(snk_B1_Blocal_r2_r_props, wnumBlock)
    //       .then(snk_B1_Blocal_r2_i_props, jSprime)
    //       .then(snk_B1_Blocal_r2_r_update, x)
    //       .then(snk_B1_Blocal_r2_i_update, n)
    //       .then(flip_snk_B1_Blocal_r2_r_update, n)
    //       .then(flip_snk_B1_Blocal_r2_i_update, n)
    //       .then(snk_B2_Blocal_r1_r_init, y_in)
    //       .then(snk_B2_Blocal_r1_i_init, jSprime)
    //       .then(flip_snk_B2_Blocal_r1_r_init, jSprime)
    //       .then(flip_snk_B2_Blocal_r1_i_init, jSprime)
    //       .then(snk_B2_Blocal_r1_r_props_init, y_in)
    //       .then(snk_B2_Blocal_r1_i_props_init, jSprime)
    //       .then(snk_B2_Blocal_r1_r_diquark, x)
    //       .then(snk_B2_Blocal_r1_i_diquark, wnumBlock)
    //       .then(snk_B2_Blocal_r1_r_props, wnumBlock)
    //       .then(snk_B2_Blocal_r1_i_props, jSprime)
    //       .then(snk_B2_Blocal_r1_r_update, x)
    //       .then(snk_B2_Blocal_r1_i_update, n)
    //       .then(flip_snk_B2_Blocal_r1_r_update, n)
    //       .then(flip_snk_B2_Blocal_r1_i_update, n)
    //       .then(snk_B2_Blocal_r2_r_init, y_in)
    //       .then(snk_B2_Blocal_r2_i_init, jSprime)
    //       .then(flip_snk_B2_Blocal_r2_r_init, jSprime)
    //       .then(flip_snk_B2_Blocal_r2_i_init, jSprime)
    //       .then(snk_B2_Blocal_r2_r_props_init, y_in)
    //       .then(snk_B2_Blocal_r2_i_props_init, jSprime)
    //       .then(snk_B2_Blocal_r2_r_diquark, x)
    //       .then(snk_B2_Blocal_r2_i_diquark, wnumBlock)
    //       .then(snk_B2_Blocal_r2_r_props, wnumBlock)
    //       .then(snk_B2_Blocal_r2_i_props, jSprime)
    //       .then(snk_B2_Blocal_r2_r_update, x)
    //       .then(flip_snk_B2_Blocal_r2_r_update, n)
    //       .then(flip_snk_B2_Blocal_r2_i_update, n)
    //       .then(snk_B2_Blocal_r2_i_update, n)
    //       .then(C_H_BB_prop_init_r, y_in)
    //       .then(C_H_BB_prop_init_i, r)
    //       .then( *(H_BB_new_term_0_r1_b1.get_real()), r)
    //       .then( *(H_BB_new_term_0_r1_b1.get_imag()), wnumHex)
    //       .then( *(H_BB_new_term_0_r2_b1.get_real()), wnumHex)
    //       .then( *(H_BB_new_term_0_r2_b1.get_imag()), wnumHex)
    //       .then( *(H_BB_new_term_0_r1_b2.get_real()), wnumHex)
    //       .then( *(H_BB_new_term_0_r1_b2.get_imag()), wnumHex)
    //       .then( *(H_BB_new_term_0_r2_b2.get_real()), wnumHex)
    //       .then( *(H_BB_new_term_0_r2_b2.get_imag()), wnumHex)
    //       .then( *(flip_H_BB_new_term_0_r1_b1.get_real()), wnumHex)
    //       .then( *(flip_H_BB_new_term_0_r1_b1.get_imag()), wnumHex)
    //       .then( *(flip_H_BB_new_term_0_r2_b1.get_real()), wnumHex)
    //       .then( *(flip_H_BB_new_term_0_r2_b1.get_imag()), wnumHex)
    //       .then( *(flip_H_BB_new_term_0_r1_b2.get_real()), wnumHex)
    //       .then( *(flip_H_BB_new_term_0_r1_b2.get_imag()), wnumHex)
    //       .then( *(flip_H_BB_new_term_0_r2_b2.get_real()), wnumHex)
    //       .then( *(flip_H_BB_new_term_0_r2_b2.get_imag()), wnumHex)
    //       .then(C_H_BB_prop_update_r, wnumHex)
    //       .then(C_H_BB_prop_update_i, wnumHex)
    //       .then(C_H_BB_update_r, r)
    //       .then(C_H_BB_update_i, mH)
    //       );
    // }

    // // H_H
    // {
    // handle = &(handle
    //       ->then(C_H_H_prop_init_r, t)
    //       .then(C_H_H_prop_init_i, y)
    //       .then(C_H_H_prop_update_r, y)
    //       .then(C_H_H_prop_update_i, wnumHexHex)
    //       .then(C_H_H_update_r, y)
    //       .then(C_H_H_update_i, nH)
    //       );
    // }

    handle = &handle->then(copy_B1_prop_r_device_to_host, computation::root);
    handle = &handle->then(copy_B1_prop_i_device_to_host, computation::root);
    handle = &handle->then(copy_B2_prop_r_device_to_host, computation::root);
    handle = &handle->then(copy_B2_prop_i_device_to_host, computation::root);
    handle = &handle->then(copy_src_psi_B1_r_device_to_host, computation::root);
    handle = &handle->then(copy_src_psi_B1_i_device_to_host, computation::root);
    handle = &handle->then(copy_src_psi_B2_r_device_to_host, computation::root);
    handle = &handle->then(copy_src_psi_B2_i_device_to_host, computation::root);
    handle = &handle->then(copy_snk_psi_B1_r_device_to_host, computation::root);
    handle = &handle->then(copy_snk_psi_B1_i_device_to_host, computation::root);
    handle = &handle->then(copy_snk_psi_B2_r_device_to_host, computation::root);
    handle = &handle->then(copy_snk_psi_B2_i_device_to_host, computation::root);
    handle = &handle->then(copy_src_spins_device_to_host, computation::root);
    handle = &handle->then(copy_sigs_device_to_host, computation::root);
    handle = &handle->then(copy_snk_psi_r_device_to_host, computation::root);
    handle = &handle->then(copy_snk_psi_i_device_to_host, computation::root);
    handle = &handle->then(copy_hex_snk_psi_r_device_to_host, computation::root);
    handle = &handle->then(copy_hex_snk_psi_i_device_to_host, computation::root);
    handle = &handle->then(copy_src_color_weights_device_to_host, computation::root);
    handle = &handle->then(copy_src_spin_weights_device_to_host, computation::root);
    handle = &handle->then(copy_src_weights_device_to_host, computation::root);
    handle = &handle->then(copy_snk_color_weights_device_to_host, computation::root);
    handle = &handle->then(copy_snk_spin_weights_device_to_host, computation::root);
    handle = &handle->then(copy_snk_weights_device_to_host, computation::root);
    handle = &handle->then(copy_hex_snk_color_weights_device_to_host, computation::root);
    handle = &handle->then(copy_hex_snk_spin_weights_device_to_host, computation::root);
    handle = &handle->then(copy_hex_snk_weights_device_to_host, computation::root);
    handle = &handle->then(copy_src_spin_block_weights_device_to_host, computation::root);
    handle = &handle->then(copy_snk_b_device_to_host, computation::root);

    // -------------------------------------------------------
    // Code Generation
    // -------------------------------------------------------
    tiramisu::codegen({
	     &buf_C_r_cpu, &buf_C_i_cpu,
        &buf_B1_prop_r_cpu, &buf_B1_prop_i_cpu,
        &buf_B2_prop_r_cpu, &buf_B2_prop_i_cpu,
        &buf_src_psi_B1_r_cpu, &buf_src_psi_B1_i_cpu,
        &buf_src_psi_B2_r_cpu, &buf_src_psi_B2_i_cpu,
        &buf_snk_psi_B1_r_cpu, &buf_snk_psi_B1_i_cpu,
        &buf_snk_psi_B2_r_cpu, &buf_snk_psi_B2_i_cpu,
        &buf_hex_src_psi_r_cpu, &buf_hex_src_psi_i_cpu,
        &buf_hex_snk_psi_r_cpu, &buf_hex_snk_psi_i_cpu,
        &buf_snk_psi_r_cpu, &buf_snk_psi_i_cpu,
	     &buf_src_spins_cpu,
	     &buf_src_spin_block_weights_cpu,
           &buf_sigs_cpu,
	     &buf_src_color_weights_cpu,
	     &buf_src_spin_weights_cpu,
	     &buf_src_weights_cpu,
	     &buf_snk_b_cpu,    
	     &buf_snk_color_weights_cpu,
	     &buf_snk_spin_weights_cpu,
	     &buf_snk_weights_cpu,
	     &buf_hex_snk_color_weights_cpu,
	     &buf_hex_snk_spin_weights_cpu,
	     &buf_hex_snk_weights_cpu
        },
        "generated_tiramisu_make_fused_dibaryon_blocks_correlator.o", true);


}


int main(int argc, char **argv)
{
	generate_function("tiramisu_make_fused_dibaryon_blocks_correlator2");

    return 0;
}
