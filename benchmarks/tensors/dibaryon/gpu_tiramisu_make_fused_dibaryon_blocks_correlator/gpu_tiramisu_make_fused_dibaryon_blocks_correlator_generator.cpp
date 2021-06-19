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
    x1("x1", 0, Vsnk),
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
   buffer buf_C_r_cpu("C_r", {Lt, Vsnk/sites_per_rank, sites_per_rank, B2Nrows, NsrcTot, B2Nrows, NsnkTot}, p_float64, a_temporary);
   buffer buf_C_i_cpu("C_i", {Lt, Vsnk/sites_per_rank, sites_per_rank, B2Nrows, NsrcTot, B2Nrows, NsnkTot}, p_float64, a_temporary);

   input B1_prop_r("B1_prop_r",   {tri, t, iCprime, iSprime, jCprime, jSprime, x, y}, p_float64);
   input B1_prop_i("B1_prop_i",   {tri, t, iCprime, iSprime, jCprime, jSprime, x, y}, p_float64);
   input B2_prop_r("B2_prop_r",   {tri, t, iCprime, iSprime, jCprime, jSprime, x, y}, p_float64);
   input B2_prop_i("B2_prop_i",   {tri, t, iCprime, iSprime, jCprime, jSprime, x, y}, p_float64);
   buffer buf_B1_prop_r_gpu("buf_B1_prop_r_gpu",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B1_prop_i_gpu("buf_B1_prop_i_gpu",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B2_prop_r_gpu("buf_B2_prop_r_gpu",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B2_prop_i_gpu("buf_B2_prop_i_gpu",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buf_B1_prop_r_gpu.tag_gpu_global();
   buf_B1_prop_i_gpu.tag_gpu_global();
   buf_B2_prop_r_gpu.tag_gpu_global();
   buf_B2_prop_i_gpu.tag_gpu_global();
   B1_prop_r.store_in( &buf_B1_prop_r_gpu );
   B1_prop_i.store_in( &buf_B1_prop_i_gpu );
   B2_prop_r.store_in( &buf_B2_prop_r_gpu );
   B2_prop_i.store_in( &buf_B2_prop_i_gpu );
   buffer buf_B1_prop_r_cpu("B1_prop_r",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B1_prop_i_cpu("B1_prop_i",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B2_prop_r_cpu("B2_prop_r",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);
   buffer buf_B2_prop_i_cpu("B2_prop_i",   {Nq, Lt, Nc, Ns, Nc, Ns, Vsnk, Vsrc}, p_float64, a_temporary);

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
   buffer buf_src_psi_B1_r_gpu("buf_src_psi_B1_r_gpu",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B1_i_gpu("buf_src_psi_B1_i_gpu",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B2_r_gpu("buf_src_psi_B2_r_gpu",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B2_i_gpu("buf_src_psi_B2_i_gpu",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_snk_psi_B1_r_gpu("buf_snk_psi_B1_r_gpu",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B1_i_gpu("buf_snk_psi_B1_i_gpu",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B2_r_gpu("buf_snk_psi_B2_r_gpu",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B2_i_gpu("buf_snk_psi_B2_i_gpu",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_hex_src_psi_r_gpu("buf_hex_src_psi_r_gpu",   {Vsrc, NsrcHex}, p_float64, a_temporary);
   buffer buf_hex_src_psi_i_gpu("buf_hex_src_psi_i_gpu",   {Vsrc, NsrcHex}, p_float64, a_temporary);
   buffer buf_hex_snk_psi_r_gpu("buf_hex_snk_psi_r_gpu",   {Vsnk, NsnkHex}, p_float64, a_temporary);
   buffer buf_hex_snk_psi_i_gpu("buf_hex_snk_psi_i_gpu",   {Vsnk, NsnkHex}, p_float64, a_temporary);
   buffer buf_snk_psi_r_gpu("buf_snk_psi_r_gpu",   {Vsnk, Vsnk, NEntangled}, p_float64, a_temporary);
   buffer buf_snk_psi_i_gpu("buf_snk_psi_i_gpu",   {Vsnk, Vsnk, NEntangled}, p_float64, a_temporary);

    buf_src_psi_B1_r_gpu.tag_gpu_global();
    buf_src_psi_B1_i_gpu.tag_gpu_global();
    buf_src_psi_B2_r_gpu.tag_gpu_global();
    buf_src_psi_B2_i_gpu.tag_gpu_global();
    buf_snk_psi_B1_r_gpu.tag_gpu_global();
    buf_snk_psi_B1_i_gpu.tag_gpu_global();
    buf_snk_psi_B2_r_gpu.tag_gpu_global();
    buf_snk_psi_B2_i_gpu.tag_gpu_global();
    buf_hex_src_psi_r_gpu.tag_gpu_global();
    buf_hex_src_psi_i_gpu.tag_gpu_global();
    buf_hex_snk_psi_r_gpu.tag_gpu_global();
    buf_hex_snk_psi_i_gpu.tag_gpu_global();
    buf_snk_psi_r_gpu.tag_gpu_global();
    buf_snk_psi_i_gpu.tag_gpu_global();
    src_psi_B1_r.store_in( &buf_src_psi_B1_r_gpu );
    src_psi_B1_i.store_in( &buf_src_psi_B1_i_gpu );
    src_psi_B2_r.store_in( &buf_src_psi_B2_r_gpu );
    src_psi_B2_i.store_in( &buf_src_psi_B2_i_gpu );
    snk_psi_B1_r.store_in( &buf_snk_psi_B1_r_gpu );
    snk_psi_B1_i.store_in( &buf_snk_psi_B1_i_gpu );
    snk_psi_B2_r.store_in( &buf_snk_psi_B2_r_gpu );
    snk_psi_B2_i.store_in( &buf_snk_psi_B2_i_gpu );

    hex_src_psi_r.store_in( &buf_hex_src_psi_r_gpu );
    hex_src_psi_i.store_in( &buf_hex_src_psi_i_gpu );
    hex_snk_psi_r.store_in( &buf_hex_snk_psi_r_gpu );
    hex_snk_psi_i.store_in( &buf_hex_snk_psi_i_gpu );
    snk_psi_r.store_in( &buf_snk_psi_r_gpu );
    snk_psi_i.store_in( &buf_snk_psi_i_gpu );

   buffer buf_src_psi_B1_r_cpu("src_psi_B1_r",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B1_i_cpu("src_psi_B1_i",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B2_r_cpu("src_psi_B2_r",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_src_psi_B2_i_cpu("src_psi_B2_i",   {Vsrc, Nsrc}, p_float64, a_temporary);
   buffer buf_snk_psi_B1_r_cpu("snk_psi_B1_r",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B1_i_cpu("snk_psi_B1_i",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B2_r_cpu("snk_psi_B2_r",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_snk_psi_B2_i_cpu("snk_psi_B2_i",   {Vsnk, Nsnk}, p_float64, a_temporary);
   buffer buf_hex_src_psi_r_cpu("hex_src_psi_r",   {Vsrc, NsrcHex}, p_float64, a_temporary);
   buffer buf_hex_src_psi_i_cpu("hex_src_psi_i",   {Vsrc, NsrcHex}, p_float64, a_temporary);
   buffer buf_hex_snk_psi_r_cpu("hex_snk_psi_r",   {Vsnk, NsnkHex}, p_float64, a_temporary);
   buffer buf_hex_snk_psi_i_cpu("hex_snk_psi_i",   {Vsnk, NsnkHex}, p_float64, a_temporary);
   buffer buf_snk_psi_r_cpu("snk_psi_r",   {Vsnk, Vsnk, NEntangled}, p_float64, a_temporary);
   buffer buf_snk_psi_i_cpu("snk_psi_i",   {Vsnk, Vsnk, NEntangled}, p_float64, a_temporary);

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

   buffer buf_src_spins_gpu("src_spins",   {B2Nrows, 2, 2}, p_int32, a_temporary);
   buffer buf_src_spin_block_weights_gpu("buf_src_spin_block_weights_gpu",   {B2Nrows, 2}, p_float64, a_temporary);
   buffer buf_sigs_gpu("buf_sigs_gpu",   {Nperms}, p_int32, a_temporary);
   buffer buf_snk_b_gpu("snk_b",   {Nperms, Nq, 2}, p_int32, a_temporary);
   buffer buf_src_color_weights_gpu("buf_src_color_weights_gpu",   {B2Nrows, Nw, Nq}, p_int32, a_temporary);
   buffer buf_src_spin_weights_gpu("buf_src_spin_weights_gpu",   {B2Nrows, Nw, Nq}, p_int32, a_temporary);
   buffer buf_src_weights_gpu("buf_src_weights_gpu",   {B2Nrows, Nw}, p_float64, a_temporary);
   buffer buf_snk_color_weights_gpu("buf_snk_color_weights_gpu",   {B2Nrows, Nperms, Nw2, Nq, 2}, p_int32, a_temporary);
   buffer buf_snk_spin_weights_gpu("buf_snk_spin_weights_gpu",   {B2Nrows, Nperms, Nw2, Nq, 2}, p_int32, a_temporary);
   buffer buf_snk_weights_gpu("buf_snk_weights_gpu",   {B2Nrows, Nw2}, p_float64, a_temporary);
   buffer buf_hex_snk_color_weights_gpu("buf_hex_snk_color_weights_gpu", {B2Nrows, Nperms, Nw2Hex, Nq, 2}, p_int32, a_temporary);
   buffer buf_hex_snk_spin_weights_gpu("buf_hex_snk_spin_weights_gpu", {B2Nrows, Nperms, Nw2Hex, Nq, 2}, p_int32, a_temporary);
   buffer buf_hex_snk_weights_gpu("buf_hex_snk_weights_gpu", {B2Nrows, Nw2Hex}, p_float64, a_temporary);

      buf_src_spins_gpu.tag_gpu_global();
      buf_src_spin_block_weights_gpu.tag_gpu_global();
      buf_sigs_gpu.tag_gpu_global();
      buf_snk_b_gpu.tag_gpu_global();
      buf_src_color_weights_gpu.tag_gpu_global();
      buf_src_spin_weights_gpu.tag_gpu_global();
      buf_src_weights_gpu.tag_gpu_global();
      buf_snk_color_weights_gpu.tag_gpu_global();
      buf_snk_spin_weights_gpu.tag_gpu_global();
      buf_snk_weights_gpu.tag_gpu_global();
      buf_hex_snk_color_weights_gpu.tag_gpu_global();
      buf_hex_snk_spin_weights_gpu.tag_gpu_global();
      buf_hex_snk_weights_gpu.tag_gpu_global();
      
      src_spins.store_in( &buf_src_spins_gpu );
      src_spin_block_weights.store_in( &buf_src_spin_block_weights_gpu );
      sigs.store_in( &buf_sigs_gpu );
      snk_b.store_in( &buf_snk_b_gpu );
      src_color_weights.store_in( &buf_src_color_weights_gpu );
      src_spin_weights.store_in( &buf_src_spin_weights_gpu );
      src_weights.store_in( &buf_src_weights_gpu );
      snk_color_weights.store_in( &buf_snk_color_weights_gpu );
      snk_spin_weights.store_in( &buf_snk_spin_weights_gpu );
      snk_weights.store_in( &buf_snk_weights_gpu );
      hex_snk_color_weights.store_in( &buf_hex_snk_color_weights_gpu );
      hex_snk_spin_weights.store_in( &buf_hex_snk_spin_weights_gpu );
      hex_snk_weights.store_in( &buf_hex_snk_weights_gpu );

   buffer buf_src_spins_cpu("buf_src_spins",   {B2Nrows, 2, 2}, p_int32, a_temporary);
   buffer buf_src_spin_block_weights_cpu("src_spin_block_weights",   {B2Nrows, 2}, p_float64, a_temporary);
   buffer buf_sigs_cpu("sigs",   {Nperms}, p_int32, a_temporary);
   buffer buf_snk_b_cpu("buf_snk_b",   {Nperms, Nq, 2}, p_int32, a_temporary);
   buffer buf_src_color_weights_cpu("src_color_weights",   {B2Nrows, Nw, Nq}, p_int32, a_temporary);
   buffer buf_src_spin_weights_cpu("src_spin_weights",   {B2Nrows, Nw, Nq}, p_int32, a_temporary);
   buffer buf_src_weights_cpu("src_weights",   {B2Nrows, Nw}, p_float64, a_temporary);
   buffer buf_snk_color_weights_cpu("snk_color_weights",   {B2Nrows, Nperms, Nw2, Nq, 2}, p_int32, a_temporary);
   buffer buf_snk_spin_weights_cpu("snk_spin_weights",   {B2Nrows, Nperms, Nw2, Nq, 2}, p_int32, a_temporary);
   buffer buf_snk_weights_cpu("snk_weights",   {B2Nrows, Nw2}, p_float64, a_temporary);
   buffer buf_hex_snk_color_weights_cpu("hex_snk_color_weights", {B2Nrows, Nperms, Nw2Hex, Nq, 2}, p_int32, a_temporary);
   buffer buf_hex_snk_spin_weights_cpu("hex_snk_spin_weights", {B2Nrows, Nperms, Nw2Hex, Nq, 2}, p_int32, a_temporary);
   buffer buf_hex_snk_weights_cpu("hex_snk_weights", {B2Nrows, Nw2Hex}, p_float64, a_temporary);

    complex_computation B1_prop(&B1_prop_r, &B1_prop_i);
    complex_computation B2_prop(&B2_prop_r, &B2_prop_i);

    complex_expr src_psi_B1(src_psi_B1_r(y, m), src_psi_B1_i(y, m));
    complex_expr src_psi_B2(src_psi_B2_r(y, m), src_psi_B2_i(y, m));

    complex_expr snk_psi_B1(snk_psi_B1_r(x, n), snk_psi_B1_i(x, n));
    complex_expr snk_psi_B2(snk_psi_B2_r(x, n), snk_psi_B2_i(x, n));
    complex_expr snk_psi_B1_x2(snk_psi_B1_r(x2, n), snk_psi_B1_i(x2, n));
    complex_expr snk_psi_B2_x2(snk_psi_B2_r(x2, n), snk_psi_B2_i(x2, n));

    complex_expr snk_psi_B1_ue(snk_psi_B1_r(x1, NEntangled+nue), snk_psi_B1_i(x1, NEntangled+nue));
    complex_expr snk_psi_B2_ue(snk_psi_B2_r(x1, NEntangled+nue), snk_psi_B2_i(x1, NEntangled+nue));
    complex_expr snk_psi_B1_x2_ue(snk_psi_B1_r(x2, NEntangled+nue), snk_psi_B1_i(x2, NEntangled+nue));
    complex_expr snk_psi_B2_x2_ue(snk_psi_B2_r(x2, NEntangled+nue), snk_psi_B2_i(x2, NEntangled+nue));

    complex_expr hex_src_psi(hex_src_psi_r(y_out*src_sites_per_rank+y_in, mH), hex_src_psi_i(y_out*src_sites_per_rank+y_in, mH));
    complex_expr hex_hex_src_psi(hex_src_psi_r(y, mH), hex_src_psi_i(y, mH));
    complex_expr hex_snk_psi(hex_snk_psi_r(x_out*sites_per_rank+x_in, nH), hex_snk_psi_i(x_out*sites_per_rank+x_in, nH));

    complex_expr snk_psi(snk_psi_r(x1, x2, ne), snk_psi_i(x1, x2, ne));

     /* Baryon blocks */

     // Computing B1_Blocal_r1, B1_Bsecond_r1, B1_Bfirst_r1

    computation B1_Blocal_r1_r_init("B1_Blocal_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Blocal_r1_i_init("B1_Blocal_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bfirst_r1_r_init("B1_Bfirst_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bfirst_r1_i_init("B1_Bfirst_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bsecond_r1_r_init("B1_Bsecond_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bsecond_r1_i_init("B1_Bsecond_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bthird_r1_r_init("B1_Bthird_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bthird_r1_i_init("B1_Bthird_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation B1_Blocal_r1_init(&B1_Blocal_r1_r_init, &B1_Blocal_r1_i_init);
    complex_computation B1_Bfirst_r1_init(&B1_Bfirst_r1_r_init, &B1_Bfirst_r1_i_init);
    complex_computation B1_Bsecond_r1_init(&B1_Bsecond_r1_r_init, &B1_Bsecond_r1_i_init);
    complex_computation B1_Bthird_r1_init(&B1_Bthird_r1_r_init, &B1_Bthird_r1_i_init);

    computation flip_B1_Blocal_r1_r_init("flip_B1_Blocal_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Blocal_r1_i_init("flip_B1_Blocal_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bfirst_r1_r_init("flip_B1_Bfirst_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bfirst_r1_i_init("flip_B1_Bfirst_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bsecond_r1_r_init("flip_B1_Bsecond_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bsecond_r1_i_init("flip_B1_Bsecond_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bthird_r1_r_init("flip_B1_Bthird_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bthird_r1_i_init("flip_B1_Bthird_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation flip_B1_Blocal_r1_init(&flip_B1_Blocal_r1_r_init, &flip_B1_Blocal_r1_i_init);
    complex_computation flip_B1_Bfirst_r1_init(&flip_B1_Bfirst_r1_r_init, &flip_B1_Bfirst_r1_i_init);
    complex_computation flip_B1_Bsecond_r1_init(&flip_B1_Bsecond_r1_r_init, &flip_B1_Bsecond_r1_i_init);
    complex_computation flip_B1_Bthird_r1_init(&flip_B1_Bthird_r1_r_init, &flip_B1_Bthird_r1_i_init);

    complex_expr B1_r1_prop_0 =  B1_prop(0, t, iCprime, iSprime, src_color_weights(0, wnumBlock, 0), src_spin_weights(0, wnumBlock, 0), x1, y);
    complex_expr B1_r1_prop_1 = B1_prop(1, t, jCprime, jSprime, src_color_weights(0, wnumBlock, 1), src_spin_weights(0, wnumBlock, 1), x1, y);
    complex_expr B1_r1_prop_2 =  B1_prop(2, t, kCprime, kSprime, src_color_weights(0, wnumBlock, 2), src_spin_weights(0, wnumBlock, 2), x1, y);
    complex_expr first_B1_r1_prop_0 =  B1_prop(0, t, iCprime, iSprime, src_color_weights(0, wnumBlock, 0), src_spin_weights(0, wnumBlock, 0), x2, y);
    complex_expr second_B1_r1_prop_1 = B1_prop(1, t, jCprime, jSprime, src_color_weights(0, wnumBlock, 1), src_spin_weights(0, wnumBlock, 1), x2, y);
    complex_expr third_B1_r1_prop_2 =  B1_prop(2, t, kCprime, kSprime, src_color_weights(0, wnumBlock, 2), src_spin_weights(0, wnumBlock, 2), x2, y);

    complex_expr B1_r1_diquark = ( B1_r1_prop_0 * B1_r1_prop_2 ) *  src_weights(0, wnumBlock);
    complex_expr first_B1_r1_diquark = ( first_B1_r1_prop_0 * B1_r1_prop_2 ) *  src_weights(0, wnumBlock);
    complex_expr third_B1_r1_diquark = ( B1_r1_prop_0 * third_B1_r1_prop_2 ) *  src_weights(0, wnumBlock);

    computation B1_Blocal_r1_r_props_init("B1_Blocal_r1_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Blocal_r1_i_props_init("B1_Blocal_r1_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bfirst_r1_r_props_init("B1_Bfirst_r1_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bfirst_r1_i_props_init("B1_Bfirst_r1_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bsecond_r1_r_props_init("B1_Bsecond_r1_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bsecond_r1_i_props_init("B1_Bsecond_r1_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bthird_r1_r_props_init("B1_Bthird_r1_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bthird_r1_i_props_init("B1_Bthird_r1_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));

    computation B1_Blocal_r1_r_diquark("B1_Blocal_r1_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, B1_r1_diquark.get_real());
    computation B1_Blocal_r1_i_diquark("B1_Blocal_r1_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, B1_r1_diquark.get_imag());
    computation B1_Bfirst_r1_r_diquark("B1_Bfirst_r1_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, first_B1_r1_diquark.get_real());
    computation B1_Bfirst_r1_i_diquark("B1_Bfirst_r1_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, first_B1_r1_diquark.get_imag());
    computation B1_Bthird_r1_r_diquark("B1_Bthird_r1_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, third_B1_r1_diquark.get_real());
    computation B1_Bthird_r1_i_diquark("B1_Bthird_r1_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, third_B1_r1_diquark.get_imag());

    complex_computation B1_Blocal_r1_diquark(&B1_Blocal_r1_r_diquark, &B1_Blocal_r1_i_diquark);
    complex_computation B1_Bfirst_r1_diquark(&B1_Bfirst_r1_r_diquark, &B1_Bfirst_r1_i_diquark);
    complex_computation B1_Bthird_r1_diquark(&B1_Bthird_r1_r_diquark, &B1_Bthird_r1_i_diquark);

    complex_expr B1_r1_props = B1_r1_prop_1 * B1_Blocal_r1_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr first_B1_r1_props = B1_r1_prop_1 * B1_Bfirst_r1_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr second_B1_r1_props = second_B1_r1_prop_1 * B1_Blocal_r1_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr third_B1_r1_props = B1_r1_prop_1 * B1_Bthird_r1_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);

    computation B1_Blocal_r1_r_props("B1_Blocal_r1_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Blocal_r1_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + B1_r1_props.get_real());
    computation B1_Blocal_r1_i_props("B1_Blocal_r1_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Blocal_r1_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + B1_r1_props.get_imag());
    computation B1_Bfirst_r1_r_props("B1_Bfirst_r1_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bfirst_r1_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + first_B1_r1_props.get_real());
    computation B1_Bfirst_r1_i_props("B1_Bfirst_r1_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bfirst_r1_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + first_B1_r1_props.get_imag());
    computation B1_Bsecond_r1_r_props("B1_Bsecond_r1_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bsecond_r1_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + second_B1_r1_props.get_real());
    computation B1_Bsecond_r1_i_props("B1_Bsecond_r1_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bsecond_r1_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + second_B1_r1_props.get_imag());
    computation B1_Bthird_r1_r_props("B1_Bthird_r1_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bthird_r1_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + third_B1_r1_props.get_real());
    computation B1_Bthird_r1_i_props("B1_Bthird_r1_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bthird_r1_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + third_B1_r1_props.get_imag());

     complex_computation B1_Blocal_r1_props(&B1_Blocal_r1_r_props, &B1_Blocal_r1_i_props);
     complex_computation B1_Bfirst_r1_props(&B1_Bfirst_r1_r_props, &B1_Bfirst_r1_i_props);
     complex_computation B1_Bsecond_r1_props(&B1_Bsecond_r1_r_props, &B1_Bsecond_r1_i_props);
     complex_computation B1_Bthird_r1_props(&B1_Bthird_r1_r_props, &B1_Bthird_r1_i_props);

    complex_expr B1_r1 = src_psi_B1 * B1_Blocal_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr first_B1_r1 = src_psi_B1 * B1_Bfirst_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr second_B1_r1 = src_psi_B1 * B1_Bsecond_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr third_B1_r1 = src_psi_B1 * B1_Bthird_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation B1_Blocal_r1_r_update("B1_Blocal_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Blocal_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + B1_r1.get_real());
    computation B1_Blocal_r1_i_update("B1_Blocal_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Blocal_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + B1_r1.get_imag());
    computation B1_Bfirst_r1_r_update("B1_Bfirst_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bfirst_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + first_B1_r1.get_real());
    computation B1_Bfirst_r1_i_update("B1_Bfirst_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bfirst_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + first_B1_r1.get_imag()); 
    computation B1_Bsecond_r1_r_update("B1_Bsecond_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bsecond_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + second_B1_r1.get_real());
    computation B1_Bsecond_r1_i_update("B1_Bsecond_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bsecond_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + second_B1_r1.get_imag());
    computation B1_Bthird_r1_r_update("B1_Bthird_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bthird_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + third_B1_r1.get_real());
    computation B1_Bthird_r1_i_update("B1_Bthird_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bthird_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + third_B1_r1.get_imag()); 

    complex_expr flip_B1_r1 = src_psi_B2 * B1_Blocal_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_first_B1_r1 = src_psi_B2 * B1_Bfirst_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_second_B1_r1 = src_psi_B2 * B1_Bsecond_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_third_B1_r1 = src_psi_B2 * B1_Bthird_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation flip_B1_Blocal_r1_r_update("flip_B1_Blocal_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Blocal_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_B1_r1.get_real());
    computation flip_B1_Blocal_r1_i_update("flip_B1_Blocal_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Blocal_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_B1_r1.get_imag());
    computation flip_B1_Bfirst_r1_r_update("flip_B1_Bfirst_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bfirst_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_first_B1_r1.get_real());
    computation flip_B1_Bfirst_r1_i_update("flip_B1_Bfirst_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bfirst_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_first_B1_r1.get_imag()); 
    computation flip_B1_Bsecond_r1_r_update("flip_B1_Bsecond_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bsecond_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_second_B1_r1.get_real());
    computation flip_B1_Bsecond_r1_i_update("flip_B1_Bsecond_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bsecond_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_second_B1_r1.get_imag());
    computation flip_B1_Bthird_r1_r_update("flip_B1_Bthird_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bthird_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_third_B1_r1.get_real());
    computation flip_B1_Bthird_r1_i_update("flip_B1_Bthird_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bthird_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_third_B1_r1.get_imag()); 

     // Computing B1_Blocal_r2, B1_Bsecond_r2, B1_Bfirst_r2

    computation B1_Blocal_r2_r_init("B1_Blocal_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Blocal_r2_i_init("B1_Blocal_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bfirst_r2_r_init("B1_Bfirst_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bfirst_r2_i_init("B1_Bfirst_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bsecond_r2_r_init("B1_Bsecond_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bsecond_r2_i_init("B1_Bsecond_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bthird_r2_r_init("B1_Bthird_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B1_Bthird_r2_i_init("B1_Bthird_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation B1_Blocal_r2_init(&B1_Blocal_r2_r_init, &B1_Blocal_r2_i_init);
    complex_computation B1_Bfirst_r2_init(&B1_Bfirst_r2_r_init, &B1_Bfirst_r2_i_init);
    complex_computation B1_Bsecond_r2_init(&B1_Bsecond_r2_r_init, &B1_Bsecond_r2_i_init);
    complex_computation B1_Bthird_r2_init(&B1_Bthird_r2_r_init, &B1_Bthird_r2_i_init);

    computation flip_B1_Blocal_r2_r_init("flip_B1_Blocal_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Blocal_r2_i_init("flip_B1_Blocal_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bfirst_r2_r_init("flip_B1_Bfirst_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bfirst_r2_i_init("flip_B1_Bfirst_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bsecond_r2_r_init("flip_B1_Bsecond_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bsecond_r2_i_init("flip_B1_Bsecond_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bthird_r2_r_init("flip_B1_Bthird_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B1_Bthird_r2_i_init("flip_B1_Bthird_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation flip_B1_Blocal_r2_init(&flip_B1_Blocal_r2_r_init, &flip_B1_Blocal_r2_i_init);
    complex_computation flip_B1_Bfirst_r2_init(&flip_B1_Bfirst_r2_r_init, &flip_B1_Bfirst_r2_i_init);
    complex_computation flip_B1_Bsecond_r2_init(&flip_B1_Bsecond_r2_r_init, &flip_B1_Bsecond_r2_i_init);
    complex_computation flip_B1_Bthird_r2_init(&flip_B1_Bthird_r2_r_init, &flip_B1_Bthird_r2_i_init);

    complex_expr B1_r2_prop_0 =  B1_prop(0, t, iCprime, iSprime, src_color_weights(1, wnumBlock, 0), src_spin_weights(1, wnumBlock, 0), x1, y);
    complex_expr B1_r2_prop_2 =  B1_prop(2, t, kCprime, kSprime, src_color_weights(1, wnumBlock, 2), src_spin_weights(1, wnumBlock, 2), x1, y);
    complex_expr B1_r2_prop_1 = B1_prop(1, t, jCprime, jSprime, src_color_weights(1, wnumBlock, 1), src_spin_weights(1, wnumBlock, 1), x1, y);
    complex_expr first_B1_r2_prop_0 =  B1_prop(0, t, iCprime, iSprime, src_color_weights(1, wnumBlock, 0), src_spin_weights(1, wnumBlock, 0), x2, y);
    complex_expr second_B1_r2_prop_1 = B1_prop(1, t, jCprime, jSprime, src_color_weights(1, wnumBlock, 1), src_spin_weights(1, wnumBlock, 1), x2, y);
    complex_expr third_B1_r2_prop_2 =  B1_prop(2, t, kCprime, kSprime, src_color_weights(1, wnumBlock, 2), src_spin_weights(1, wnumBlock, 2), x2, y);

    complex_expr B1_r2_diquark = ( B1_r2_prop_0 * B1_r2_prop_2 ) *  src_weights(1, wnumBlock);
    complex_expr first_B1_r2_diquark = ( first_B1_r2_prop_0 * B1_r2_prop_2 ) *  src_weights(1, wnumBlock);
    complex_expr third_B1_r2_diquark = ( B1_r2_prop_0 * third_B1_r2_prop_2 ) *  src_weights(1, wnumBlock);

    computation B1_Blocal_r2_r_props_init("B1_Blocal_r2_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Blocal_r2_i_props_init("B1_Blocal_r2_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bfirst_r2_r_props_init("B1_Bfirst_r2_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bfirst_r2_i_props_init("B1_Bfirst_r2_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bsecond_r2_r_props_init("B1_Bsecond_r2_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bsecond_r2_i_props_init("B1_Bsecond_r2_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bthird_r2_r_props_init("B1_Bthird_r2_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B1_Bthird_r2_i_props_init("B1_Bthird_r2_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));

    computation B1_Blocal_r2_r_diquark("B1_Blocal_r2_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, B1_r2_diquark.get_real());
    computation B1_Blocal_r2_i_diquark("B1_Blocal_r2_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, B1_r2_diquark.get_imag());
    computation B1_Bfirst_r2_r_diquark("B1_Bfirst_r2_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, first_B1_r2_diquark.get_real());
    computation B1_Bfirst_r2_i_diquark("B1_Bfirst_r2_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, first_B1_r2_diquark.get_imag());
    computation B1_Bthird_r2_r_diquark("B1_Bthird_r2_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, third_B1_r2_diquark.get_real());
    computation B1_Bthird_r2_i_diquark("B1_Bthird_r2_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, third_B1_r2_diquark.get_imag());

    complex_computation B1_Blocal_r2_diquark(&B1_Blocal_r2_r_diquark, &B1_Blocal_r2_i_diquark);
    complex_computation B1_Bfirst_r2_diquark(&B1_Bfirst_r2_r_diquark, &B1_Bfirst_r2_i_diquark);
    complex_computation B1_Bthird_r2_diquark(&B1_Bthird_r2_r_diquark, &B1_Bthird_r2_i_diquark);

    complex_expr B1_r2_props = B1_r2_prop_1 * B1_Blocal_r2_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr first_B1_r2_props = B1_r2_prop_1 * B1_Bfirst_r2_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr second_B1_r2_props = second_B1_r2_prop_1 * B1_Blocal_r2_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr third_B1_r2_props = B1_r2_prop_1 * B1_Bthird_r2_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);

    computation B1_Blocal_r2_r_props("B1_Blocal_r2_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Blocal_r2_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + B1_r2_props.get_real());
    computation B1_Blocal_r2_i_props("B1_Blocal_r2_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Blocal_r2_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + B1_r2_props.get_imag());
    computation B1_Bfirst_r2_r_props("B1_Bfirst_r2_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bfirst_r2_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + first_B1_r2_props.get_real());
    computation B1_Bfirst_r2_i_props("B1_Bfirst_r2_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bfirst_r2_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + first_B1_r2_props.get_imag());
    computation B1_Bsecond_r2_r_props("B1_Bsecond_r2_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bsecond_r2_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + second_B1_r2_props.get_real());
    computation B1_Bsecond_r2_i_props("B1_Bsecond_r2_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bsecond_r2_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + second_B1_r2_props.get_imag());
    computation B1_Bthird_r2_r_props("B1_Bthird_r2_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bthird_r2_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + third_B1_r2_props.get_real());
    computation B1_Bthird_r2_i_props("B1_Bthird_r2_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B1_Bthird_r2_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + third_B1_r2_props.get_imag());

    complex_computation B1_Blocal_r2_props(&B1_Blocal_r2_r_props, &B1_Blocal_r2_i_props);
    complex_computation B1_Bfirst_r2_props(&B1_Bfirst_r2_r_props, &B1_Bfirst_r2_i_props);
    complex_computation B1_Bsecond_r2_props(&B1_Bsecond_r2_r_props, &B1_Bsecond_r2_i_props);
    complex_computation B1_Bthird_r2_props(&B1_Bthird_r2_r_props, &B1_Bthird_r2_i_props);

    complex_expr B1_r2 = src_psi_B1 * B1_Blocal_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr first_B1_r2 = src_psi_B1 * B1_Bfirst_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr second_B1_r2 = src_psi_B1 * B1_Bsecond_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr third_B1_r2 = src_psi_B1 * B1_Bthird_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation B1_Blocal_r2_r_update("B1_Blocal_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Blocal_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + B1_r2.get_real());
    computation B1_Blocal_r2_i_update("B1_Blocal_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Blocal_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + B1_r2.get_imag());
    computation B1_Bfirst_r2_r_update("B1_Bfirst_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bfirst_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + first_B1_r2.get_real());
    computation B1_Bfirst_r2_i_update("B1_Bfirst_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bfirst_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + first_B1_r2.get_imag());
    computation B1_Bsecond_r2_r_update("B1_Bsecond_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bsecond_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + second_B1_r2.get_real());
    computation B1_Bsecond_r2_i_update("B1_Bsecond_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bsecond_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + second_B1_r2.get_imag());
    computation B1_Bthird_r2_r_update("B1_Bthird_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bthird_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + third_B1_r2.get_real());
    computation B1_Bthird_r2_i_update("B1_Bthird_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B1_Bthird_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + third_B1_r2.get_imag());

    complex_expr flip_B1_r2 = src_psi_B2 * B1_Blocal_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_first_B1_r2 = src_psi_B2 * B1_Bfirst_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_second_B1_r2 = src_psi_B2 * B1_Bsecond_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_third_B1_r2 = src_psi_B2 * B1_Bthird_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation flip_B1_Blocal_r2_r_update("flip_B1_Blocal_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Blocal_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_B1_r2.get_real());
    computation flip_B1_Blocal_r2_i_update("flip_B1_Blocal_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Blocal_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_B1_r2.get_imag());
    computation flip_B1_Bfirst_r2_r_update("flip_B1_Bfirst_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bfirst_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_first_B1_r2.get_real());
    computation flip_B1_Bfirst_r2_i_update("flip_B1_Bfirst_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bfirst_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_first_B1_r2.get_imag()); 
    computation flip_B1_Bsecond_r2_r_update("flip_B1_Bsecond_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bsecond_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_second_B1_r2.get_real());
    computation flip_B1_Bsecond_r2_i_update("flip_B1_Bsecond_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bsecond_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_second_B1_r2.get_imag());
    computation flip_B1_Bthird_r2_r_update("flip_B1_Bthird_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bthird_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_third_B1_r2.get_real());
    computation flip_B1_Bthird_r2_i_update("flip_B1_Bthird_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B1_Bthird_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_third_B1_r2.get_imag()); 

     //Computing B2_Blocal_r1, B2_Bsecond_r1, B2_Bfirst_r1

    computation B2_Blocal_r1_r_init("B2_Blocal_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Blocal_r1_i_init("B2_Blocal_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bfirst_r1_r_init("B2_Bfirst_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bfirst_r1_i_init("B2_Bfirst_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bsecond_r1_r_init("B2_Bsecond_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bsecond_r1_i_init("B2_Bsecond_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bthird_r1_r_init("B2_Bthird_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bthird_r1_i_init("B2_Bthird_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation B2_Blocal_r1_init(&B2_Blocal_r1_r_init, &B2_Blocal_r1_i_init);
    complex_computation B2_Bfirst_r1_init(&B2_Bfirst_r1_r_init, &B2_Bfirst_r1_i_init);
    complex_computation B2_Bsecond_r1_init(&B2_Bsecond_r1_r_init, &B2_Bsecond_r1_i_init);
    complex_computation B2_Bthird_r1_init(&B2_Bthird_r1_r_init, &B2_Bthird_r1_i_init);

    computation flip_B2_Blocal_r1_r_init("flip_B2_Blocal_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Blocal_r1_i_init("flip_B2_Blocal_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bfirst_r1_r_init("flip_B2_Bfirst_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bfirst_r1_i_init("flip_B2_Bfirst_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bsecond_r1_r_init("flip_B2_Bsecond_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bsecond_r1_i_init("flip_B2_Bsecond_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bthird_r1_r_init("flip_B2_Bthird_r1_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bthird_r1_i_init("flip_B2_Bthird_r1_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation flip_B2_Blocal_r1_init(&flip_B2_Blocal_r1_r_init, &flip_B2_Blocal_r1_i_init);
    complex_computation flip_B2_Bfirst_r1_init(&flip_B2_Bfirst_r1_r_init, &flip_B2_Bfirst_r1_i_init);
    complex_computation flip_B2_Bsecond_r1_init(&flip_B2_Bsecond_r1_r_init, &flip_B2_Bsecond_r1_i_init);
    complex_computation flip_B2_Bthird_r1_init(&flip_B2_Bthird_r1_r_init, &flip_B2_Bthird_r1_i_init);

    complex_expr B2_r1_prop_0 =  B2_prop(0, t, iCprime, iSprime, src_color_weights(0, wnumBlock, 0), src_spin_weights(0, wnumBlock, 0), x2, y);
    complex_expr B2_r1_prop_2 =  B2_prop(2, t, kCprime, kSprime, src_color_weights(0, wnumBlock, 2), src_spin_weights(0, wnumBlock, 2), x2, y);
    complex_expr B2_r1_prop_1 = B2_prop(1, t, jCprime, jSprime, src_color_weights(0, wnumBlock, 1), src_spin_weights(0, wnumBlock, 1), x2, y);
    complex_expr first_B2_r1_prop_0 =  B2_prop(0, t, iCprime, iSprime, src_color_weights(0, wnumBlock, 0), src_spin_weights(0, wnumBlock, 0), x1, y);
    complex_expr second_B2_r1_prop_1 = B2_prop(1, t, jCprime, jSprime, src_color_weights(0, wnumBlock, 1), src_spin_weights(0, wnumBlock, 1), x1, y);
    complex_expr third_B2_r1_prop_2 =  B2_prop(2, t, kCprime, kSprime, src_color_weights(0, wnumBlock, 2), src_spin_weights(0, wnumBlock, 2), x1, y);

    complex_expr B2_r1_diquark = ( B2_r1_prop_0 * B2_r1_prop_2 ) *  src_weights(0, wnumBlock);
    complex_expr first_B2_r1_diquark = ( first_B2_r1_prop_0 * B2_r1_prop_2 ) *  src_weights(0, wnumBlock);
    complex_expr third_B2_r1_diquark = ( B2_r1_prop_0 * third_B2_r1_prop_2 ) *  src_weights(0, wnumBlock);

    computation B2_Blocal_r1_r_props_init("B2_Blocal_r1_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Blocal_r1_i_props_init("B2_Blocal_r1_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bfirst_r1_r_props_init("B2_Bfirst_r1_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bfirst_r1_i_props_init("B2_Bfirst_r1_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bsecond_r1_r_props_init("B2_Bsecond_r1_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bsecond_r1_i_props_init("B2_Bsecond_r1_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bthird_r1_r_props_init("B2_Bthird_r1_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bthird_r1_i_props_init("B2_Bthird_r1_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));

    computation B2_Blocal_r1_r_diquark("B2_Blocal_r1_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, B2_r1_diquark.get_real());
    computation B2_Blocal_r1_i_diquark("B2_Blocal_r1_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, B2_r1_diquark.get_imag());
    computation B2_Bfirst_r1_r_diquark("B2_Bfirst_r1_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, first_B2_r1_diquark.get_real());
    computation B2_Bfirst_r1_i_diquark("B2_Bfirst_r1_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, first_B2_r1_diquark.get_imag());
    computation B2_Bthird_r1_r_diquark("B2_Bthird_r1_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, third_B2_r1_diquark.get_real());
    computation B2_Bthird_r1_i_diquark("B2_Bthird_r1_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, third_B2_r1_diquark.get_imag());

    complex_computation B2_Blocal_r1_diquark(&B2_Blocal_r1_r_diquark, &B2_Blocal_r1_i_diquark);
    complex_computation B2_Bfirst_r1_diquark(&B2_Bfirst_r1_r_diquark, &B2_Bfirst_r1_i_diquark);
    complex_computation B2_Bthird_r1_diquark(&B2_Bthird_r1_r_diquark, &B2_Bthird_r1_i_diquark);

    complex_expr B2_r1_props = B2_r1_prop_1 * B2_Blocal_r1_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr first_B2_r1_props = B2_r1_prop_1 * B2_Bfirst_r1_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr second_B2_r1_props = second_B2_r1_prop_1 * B2_Blocal_r1_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr third_B2_r1_props = B2_r1_prop_1 * B2_Bthird_r1_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);

    computation B2_Blocal_r1_r_props("B2_Blocal_r1_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Blocal_r1_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + B2_r1_props.get_real());
    computation B2_Blocal_r1_i_props("B2_Blocal_r1_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Blocal_r1_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + B2_r1_props.get_imag());
    computation B2_Bfirst_r1_r_props("B2_Bfirst_r1_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bfirst_r1_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + first_B2_r1_props.get_real());
    computation B2_Bfirst_r1_i_props("B2_Bfirst_r1_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bfirst_r1_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + first_B2_r1_props.get_imag());
    computation B2_Bsecond_r1_r_props("B2_Bsecond_r1_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bsecond_r1_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + second_B2_r1_props.get_real());
    computation B2_Bsecond_r1_i_props("B2_Bsecond_r1_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bsecond_r1_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + second_B2_r1_props.get_imag());
    computation B2_Bthird_r1_r_props("B2_Bthird_r1_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bthird_r1_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + third_B2_r1_props.get_real());
    computation B2_Bthird_r1_i_props("B2_Bthird_r1_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bthird_r1_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + third_B2_r1_props.get_imag());

    complex_computation B2_Blocal_r1_props(&B2_Blocal_r1_r_props, &B2_Blocal_r1_i_props);
    complex_computation B2_Bfirst_r1_props(&B2_Bfirst_r1_r_props, &B2_Bfirst_r1_i_props);
    complex_computation B2_Bsecond_r1_props(&B2_Bsecond_r1_r_props, &B2_Bsecond_r1_i_props);
    complex_computation B2_Bthird_r1_props(&B2_Bthird_r1_r_props, &B2_Bthird_r1_i_props);

    complex_expr B2_r1 = src_psi_B2 * B2_Blocal_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr first_B2_r1 = src_psi_B2 * B2_Bfirst_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr second_B2_r1 = src_psi_B2 * B2_Bsecond_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr third_B2_r1 = src_psi_B2 * B2_Bthird_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation B2_Blocal_r1_r_update("B2_Blocal_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Blocal_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + B2_r1.get_real());
    computation B2_Blocal_r1_i_update("B2_Blocal_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Blocal_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + B2_r1.get_imag());
    computation B2_Bfirst_r1_r_update("B2_Bfirst_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bfirst_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + first_B2_r1.get_real());
    computation B2_Bfirst_r1_i_update("B2_Bfirst_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bfirst_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + first_B2_r1.get_imag()); 
    computation B2_Bsecond_r1_r_update("B2_Bsecond_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bsecond_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + second_B2_r1.get_real());
    computation B2_Bsecond_r1_i_update("B2_Bsecond_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bsecond_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + second_B2_r1.get_imag());
    computation B2_Bthird_r1_r_update("B2_Bthird_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bthird_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + third_B2_r1.get_real());
    computation B2_Bthird_r1_i_update("B2_Bthird_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bthird_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + third_B2_r1.get_imag()); 

    complex_expr flip_B2_r1 = src_psi_B1 * B2_Blocal_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_first_B2_r1 = src_psi_B1 * B2_Bfirst_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_second_B2_r1 = src_psi_B1 * B2_Bsecond_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_third_B2_r1 = src_psi_B1 * B2_Bthird_r1_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation flip_B2_Blocal_r1_r_update("flip_B2_Blocal_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Blocal_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_B2_r1.get_real());
    computation flip_B2_Blocal_r1_i_update("flip_B2_Blocal_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Blocal_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_B2_r1.get_imag());
    computation flip_B2_Bfirst_r1_r_update("flip_B2_Bfirst_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bfirst_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_first_B2_r1.get_real());
    computation flip_B2_Bfirst_r1_i_update("flip_B2_Bfirst_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bfirst_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_first_B2_r1.get_imag()); 
    computation flip_B2_Bsecond_r1_r_update("flip_B2_Bsecond_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bsecond_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_second_B2_r1.get_real());
    computation flip_B2_Bsecond_r1_i_update("flip_B2_Bsecond_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bsecond_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_second_B2_r1.get_imag());
    computation flip_B2_Bthird_r1_r_update("flip_B2_Bthird_r1_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bthird_r1_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_third_B2_r1.get_real());
    computation flip_B2_Bthird_r1_i_update("flip_B2_Bthird_r1_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bthird_r1_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_third_B2_r1.get_imag()); 

     // Computing B2_Blocal_r2, B2_Bsecond_r2, B2_Bfirst_r2

    computation B2_Blocal_r2_r_init("B2_Blocal_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Blocal_r2_i_init("B2_Blocal_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bfirst_r2_r_init("B2_Bfirst_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bfirst_r2_i_init("B2_Bfirst_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bsecond_r2_r_init("B2_Bsecond_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bsecond_r2_i_init("B2_Bsecond_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bthird_r2_r_init("B2_Bthird_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation B2_Bthird_r2_i_init("B2_Bthird_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation B2_Blocal_r2_init(&B2_Blocal_r2_r_init, &B2_Blocal_r2_i_init);
    complex_computation B2_Bfirst_r2_init(&B2_Bfirst_r2_r_init, &B2_Bfirst_r2_i_init);
    complex_computation B2_Bsecond_r2_init(&B2_Bsecond_r2_r_init, &B2_Bsecond_r2_i_init);
    complex_computation B2_Bthird_r2_init(&B2_Bthird_r2_r_init, &B2_Bthird_r2_i_init);

    computation flip_B2_Blocal_r2_r_init("flip_B2_Blocal_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Blocal_r2_i_init("flip_B2_Blocal_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bfirst_r2_r_init("flip_B2_Bfirst_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bfirst_r2_i_init("flip_B2_Bfirst_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bsecond_r2_r_init("flip_B2_Bsecond_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bsecond_r2_i_init("flip_B2_Bsecond_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bthird_r2_r_init("flip_B2_Bthird_r2_r_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_B2_Bthird_r2_i_init("flip_B2_Bthird_r2_i_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation flip_B2_Blocal_r2_init(&flip_B2_Blocal_r2_r_init, &flip_B2_Blocal_r2_i_init);
    complex_computation flip_B2_Bfirst_r2_init(&flip_B2_Bfirst_r2_r_init, &flip_B2_Bfirst_r2_i_init);
    complex_computation flip_B2_Bsecond_r2_init(&flip_B2_Bsecond_r2_r_init, &flip_B2_Bsecond_r2_i_init);
    complex_computation flip_B2_Bthird_r2_init(&flip_B2_Bthird_r2_r_init, &flip_B2_Bthird_r2_i_init);

    complex_expr B2_r2_prop_0 =  B2_prop(0, t, iCprime, iSprime, src_color_weights(1, wnumBlock, 0), src_spin_weights(1, wnumBlock, 0), x2, y);
    complex_expr B2_r2_prop_2 =  B2_prop(2, t, kCprime, kSprime, src_color_weights(1, wnumBlock, 2), src_spin_weights(1, wnumBlock, 2), x2, y);
    complex_expr B2_r2_prop_1 = B2_prop(1, t, jCprime, jSprime, src_color_weights(1, wnumBlock, 1), src_spin_weights(1, wnumBlock, 1), x2, y);
    complex_expr first_B2_r2_prop_0 =  B2_prop(0, t, iCprime, iSprime, src_color_weights(1, wnumBlock, 0), src_spin_weights(1, wnumBlock, 0), x1, y);
    complex_expr second_B2_r2_prop_1 = B2_prop(1, t, jCprime, jSprime, src_color_weights(1, wnumBlock, 1), src_spin_weights(1, wnumBlock, 1), x1, y);
    complex_expr third_B2_r2_prop_2 =  B2_prop(2, t, kCprime, kSprime, src_color_weights(1, wnumBlock, 2), src_spin_weights(1, wnumBlock, 2), x1, y);

    complex_expr B2_r2_diquark = ( B2_r2_prop_0 * B2_r2_prop_2 ) *  src_weights(1, wnumBlock);
    complex_expr first_B2_r2_diquark = ( first_B2_r2_prop_0 * B2_r2_prop_2 ) *  src_weights(1, wnumBlock);
    complex_expr third_B2_r2_diquark = ( B2_r2_prop_0 * third_B2_r2_prop_2 ) *  src_weights(1, wnumBlock);

    computation B2_Blocal_r2_r_props_init("B2_Blocal_r2_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Blocal_r2_i_props_init("B2_Blocal_r2_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bfirst_r2_r_props_init("B2_Bfirst_r2_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bfirst_r2_i_props_init("B2_Bfirst_r2_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bsecond_r2_r_props_init("B2_Bsecond_r2_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bsecond_r2_i_props_init("B2_Bsecond_r2_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bthird_r2_r_props_init("B2_Bthird_r2_r_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation B2_Bthird_r2_i_props_init("B2_Bthird_r2_i_props_init", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));

    computation B2_Blocal_r2_r_diquark("B2_Blocal_r2_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, B2_r2_diquark.get_real());
    computation B2_Blocal_r2_i_diquark("B2_Blocal_r2_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, B2_r2_diquark.get_imag());
    computation B2_Bfirst_r2_r_diquark("B2_Bfirst_r2_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, first_B2_r2_diquark.get_real());
    computation B2_Bfirst_r2_i_diquark("B2_Bfirst_r2_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, first_B2_r2_diquark.get_imag());
    computation B2_Bthird_r2_r_diquark("B2_Bthird_r2_r_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, third_B2_r2_diquark.get_real());
    computation B2_Bthird_r2_i_diquark("B2_Bthird_r2_i_diquark", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock}, third_B2_r2_diquark.get_imag());

    complex_computation B2_Blocal_r2_diquark(&B2_Blocal_r2_r_diquark, &B2_Blocal_r2_i_diquark);
    complex_computation B2_Bfirst_r2_diquark(&B2_Bfirst_r2_r_diquark, &B2_Bfirst_r2_i_diquark);
    complex_computation B2_Bthird_r2_diquark(&B2_Bthird_r2_r_diquark, &B2_Bthird_r2_i_diquark);

    complex_expr B2_r2_props = B2_r2_prop_1 * B2_Blocal_r2_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr first_B2_r2_props = B2_r2_prop_1 * B2_Bfirst_r2_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr second_B2_r2_props = second_B2_r2_prop_1 * B2_Blocal_r2_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);
    complex_expr third_B2_r2_props = B2_r2_prop_1 * B2_Bthird_r2_diquark(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock);

    computation B2_Blocal_r2_r_props("B2_Blocal_r2_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Blocal_r2_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + B2_r2_props.get_real());
    computation B2_Blocal_r2_i_props("B2_Blocal_r2_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Blocal_r2_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + B2_r2_props.get_imag());
    computation B2_Bfirst_r2_r_props("B2_Bfirst_r2_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bfirst_r2_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + first_B2_r2_props.get_real());
    computation B2_Bfirst_r2_i_props("B2_Bfirst_r2_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bfirst_r2_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + first_B2_r2_props.get_imag());
    computation B2_Bsecond_r2_r_props("B2_Bsecond_r2_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bsecond_r2_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + second_B2_r2_props.get_real());
    computation B2_Bsecond_r2_i_props("B2_Bsecond_r2_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bsecond_r2_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + second_B2_r2_props.get_imag());
    computation B2_Bthird_r2_r_props("B2_Bthird_r2_r_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bthird_r2_r_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + third_B2_r2_props.get_real());
    computation B2_Bthird_r2_i_props("B2_Bthird_r2_i_props", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, B2_Bthird_r2_i_props_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime) + third_B2_r2_props.get_imag());

    complex_computation B2_Blocal_r2_props(&B2_Blocal_r2_r_props, &B2_Blocal_r2_i_props);
    complex_computation B2_Bfirst_r2_props(&B2_Bfirst_r2_r_props, &B2_Bfirst_r2_i_props);
    complex_computation B2_Bsecond_r2_props(&B2_Bsecond_r2_r_props, &B2_Bsecond_r2_i_props);
    complex_computation B2_Bthird_r2_props(&B2_Bthird_r2_r_props, &B2_Bthird_r2_i_props);

    complex_expr B2_r2 = src_psi_B2 * B2_Blocal_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr first_B2_r2 = src_psi_B2 * B2_Bfirst_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr second_B2_r2 = src_psi_B2 * B2_Bsecond_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr third_B2_r2 = src_psi_B2 * B2_Bthird_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation B2_Blocal_r2_r_update("B2_Blocal_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Blocal_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + B2_r2.get_real());
    computation B2_Blocal_r2_i_update("B2_Blocal_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Blocal_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + B2_r2.get_imag());
    computation B2_Bfirst_r2_r_update("B2_Bfirst_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bfirst_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + first_B2_r2.get_real());
    computation B2_Bfirst_r2_i_update("B2_Bfirst_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bfirst_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + first_B2_r2.get_imag());
    computation B2_Bsecond_r2_r_update("B2_Bsecond_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bsecond_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + second_B2_r2.get_real());
    computation B2_Bsecond_r2_i_update("B2_Bsecond_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bsecond_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + second_B2_r2.get_imag());
    computation B2_Bthird_r2_r_update("B2_Bthird_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bthird_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + third_B2_r2.get_real());
    computation B2_Bthird_r2_i_update("B2_Bthird_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, B2_Bthird_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + third_B2_r2.get_imag());

    complex_expr flip_B2_r2 = src_psi_B1 * B2_Blocal_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_first_B2_r2 = src_psi_B1 * B2_Bfirst_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_second_B2_r2 = src_psi_B1 * B2_Bsecond_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);
    complex_expr flip_third_B2_r2 = src_psi_B1 * B2_Bthird_r2_props(t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation flip_B2_Blocal_r2_r_update("flip_B2_Blocal_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Blocal_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_B2_r2.get_real());
    computation flip_B2_Blocal_r2_i_update("flip_B2_Blocal_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Blocal_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_B2_r2.get_imag());
    computation flip_B2_Bfirst_r2_r_update("flip_B2_Bfirst_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bfirst_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_first_B2_r2.get_real());
    computation flip_B2_Bfirst_r2_i_update("flip_B2_Bfirst_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bfirst_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_first_B2_r2.get_imag()); 
    computation flip_B2_Bsecond_r2_r_update("flip_B2_Bsecond_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bsecond_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_second_B2_r2.get_real());
    computation flip_B2_Bsecond_r2_i_update("flip_B2_Bsecond_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bsecond_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_second_B2_r2.get_imag());
    computation flip_B2_Bthird_r2_r_update("flip_B2_Bthird_r2_r_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bthird_r2_r_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_third_B2_r2.get_real());
    computation flip_B2_Bthird_r2_i_update("flip_B2_Bthird_r2_i_update", {t, x1, iCprime, iSprime, x2, kCprime, kSprime, y, jCprime, jSprime, m}, flip_B2_Bthird_r2_i_init(t, x1, iCprime, iSprime, x2, kCprime, kSprime, jCprime, jSprime, m) + flip_third_B2_r2.get_imag()); 
    
// BB_H

     // Computing src_B1_Blocal_r1

    computation src_B1_Blocal_r1_r_init("src_B1_Blocal_r1_r_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation src_B1_Blocal_r1_i_init("src_B1_Blocal_r1_i_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation src_B1_Blocal_r1_init(&src_B1_Blocal_r1_r_init, &src_B1_Blocal_r1_i_init);

    computation flip_src_B1_Blocal_r1_r_init("flip_src_B1_Blocal_r1_r_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_src_B1_Blocal_r1_i_init("flip_src_B1_Blocal_r1_i_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation flip_src_B1_Blocal_r1_init(&flip_src_B1_Blocal_r1_r_init, &flip_src_B1_Blocal_r1_i_init);

    complex_expr src_B1_r1_prop_0 =  B1_prop(0, t, iCprime, iSprime, src_color_weights(0, wnumBlock, 0), src_spin_weights(0, wnumBlock, 0), x_out*sites_per_rank+x_in, y);
    complex_expr src_B1_r1_prop_2 =  B1_prop(2, t, kCprime, kSprime, src_color_weights(0, wnumBlock, 2), src_spin_weights(0, wnumBlock, 2), x_out*sites_per_rank+x_in, y);
    complex_expr src_B1_r1_prop_1 = B1_prop(1, t, jCprime, jSprime, src_color_weights(0, wnumBlock, 1), src_spin_weights(0, wnumBlock, 1), x_out*sites_per_rank+x_in, y);

    complex_expr src_B1_r1_diquark = ( src_B1_r1_prop_0 * src_B1_r1_prop_2 ) *  src_weights(0, wnumBlock);

    computation src_B1_Blocal_r1_r_props_init("src_B1_Blocal_r1_r_props_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation src_B1_Blocal_r1_i_props_init("src_B1_Blocal_r1_i_props_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));

    computation src_B1_Blocal_r1_r_diquark("src_B1_Blocal_r1_r_diquark", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock}, src_B1_r1_diquark.get_real());
    computation src_B1_Blocal_r1_i_diquark("src_B1_Blocal_r1_i_diquark", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock}, src_B1_r1_diquark.get_imag());

    complex_computation src_B1_Blocal_r1_diquark(&src_B1_Blocal_r1_r_diquark, &src_B1_Blocal_r1_i_diquark);

    complex_expr src_B1_r1_props = src_B1_r1_prop_1 * src_B1_Blocal_r1_diquark(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock);

    computation src_B1_Blocal_r1_r_props("src_B1_Blocal_r1_r_props", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, src_B1_Blocal_r1_r_props_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime) + src_B1_r1_props.get_real());
    computation src_B1_Blocal_r1_i_props("src_B1_Blocal_r1_i_props", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, src_B1_Blocal_r1_i_props_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime) + src_B1_r1_props.get_imag());

    complex_computation src_B1_Blocal_r1_props(&src_B1_Blocal_r1_r_props, &src_B1_Blocal_r1_i_props);

    complex_expr src_B1_r1 = src_psi_B1 * src_B1_Blocal_r1_props(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation src_B1_Blocal_r1_r_update("src_B1_Blocal_r1_r_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, src_B1_Blocal_r1_r_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + src_B1_r1.get_real());
    computation src_B1_Blocal_r1_i_update("src_B1_Blocal_r1_i_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, src_B1_Blocal_r1_i_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + src_B1_r1.get_imag()); 

    complex_expr flip_src_B1_r1 = src_psi_B2 * src_B1_Blocal_r1_props(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation flip_src_B1_Blocal_r1_r_update("flip_src_B1_Blocal_r1_r_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, flip_src_B1_Blocal_r1_r_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + flip_src_B1_r1.get_real());
    computation flip_src_B1_Blocal_r1_i_update("flip_src_B1_Blocal_r1_i_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, flip_src_B1_Blocal_r1_i_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + flip_src_B1_r1.get_imag());

     // Computing src_B1_Blocal_r2

    computation src_B1_Blocal_r2_r_init("src_B1_Blocal_r2_r_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation src_B1_Blocal_r2_i_init("src_B1_Blocal_r2_i_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation src_B1_Blocal_r2_init(&src_B1_Blocal_r2_r_init, &src_B1_Blocal_r2_i_init);

    computation flip_src_B1_Blocal_r2_r_init("flip_src_B1_Blocal_r2_r_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_src_B1_Blocal_r2_i_init("flip_src_B1_Blocal_r2_i_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation flip_src_B1_Blocal_r2_init(&flip_src_B1_Blocal_r2_r_init, &flip_src_B1_Blocal_r2_i_init);

    complex_expr src_B1_r2_prop_0 =  B1_prop(0, t, iCprime, iSprime, src_color_weights(1, wnumBlock, 0), src_spin_weights(1, wnumBlock, 0), x_out*sites_per_rank+x_in, y);
    complex_expr src_B1_r2_prop_2 =  B1_prop(2, t, kCprime, kSprime, src_color_weights(1, wnumBlock, 2), src_spin_weights(1, wnumBlock, 2), x_out*sites_per_rank+x_in, y);
    complex_expr src_B1_r2_prop_0p = B1_prop(0, t, kCprime, kSprime, src_color_weights(1, wnumBlock, 0), src_spin_weights(1, wnumBlock, 0), x_out*sites_per_rank+x_in, y);
    complex_expr src_B1_r2_prop_2p = B1_prop(2, t, iCprime, iSprime, src_color_weights(1, wnumBlock, 2), src_spin_weights(1, wnumBlock, 2), x_out*sites_per_rank+x_in, y);
    complex_expr src_B1_r2_prop_1 = B1_prop(1, t, jCprime, jSprime, src_color_weights(1, wnumBlock, 1), src_spin_weights(1, wnumBlock, 1), x_out*sites_per_rank+x_in, y);

    complex_expr src_B1_r2_diquark = ( src_B1_r2_prop_0 * src_B1_r2_prop_2 ) *  src_weights(1, wnumBlock);

    computation src_B1_Blocal_r2_r_props_init("src_B1_Blocal_r2_r_props_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation src_B1_Blocal_r2_i_props_init("src_B1_Blocal_r2_i_props_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));

    computation src_B1_Blocal_r2_r_diquark("src_B1_Blocal_r2_r_diquark", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock}, src_B1_r2_diquark.get_real());
    computation src_B1_Blocal_r2_i_diquark("src_B1_Blocal_r2_i_diquark", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock}, src_B1_r2_diquark.get_imag());

    complex_computation src_B1_Blocal_r2_diquark(&src_B1_Blocal_r2_r_diquark, &src_B1_Blocal_r2_i_diquark);

    complex_expr src_B1_r2_props = src_B1_r2_prop_1 * src_B1_Blocal_r2_diquark(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock);

    computation src_B1_Blocal_r2_r_props("src_B1_Blocal_r2_r_props", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, src_B1_Blocal_r2_r_props_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime) + src_B1_r2_props.get_real());
    computation src_B1_Blocal_r2_i_props("src_B1_Blocal_r2_i_props", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, src_B1_Blocal_r2_i_props_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime) + src_B1_r2_props.get_imag());

    complex_computation src_B1_Blocal_r2_props(&src_B1_Blocal_r2_r_props, &src_B1_Blocal_r2_i_props);

    complex_expr src_B1_r2 = src_psi_B1 * src_B1_Blocal_r2_props(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation src_B1_Blocal_r2_r_update("src_B1_Blocal_r2_r_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, src_B1_Blocal_r2_r_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + src_B1_r2.get_real());
    computation src_B1_Blocal_r2_i_update("src_B1_Blocal_r2_i_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, src_B1_Blocal_r2_i_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + src_B1_r2.get_imag());

    complex_expr flip_src_B1_r2 = src_psi_B2 * src_B1_Blocal_r2_props(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation flip_src_B1_Blocal_r2_r_update("flip_src_B1_Blocal_r2_r_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, flip_src_B1_Blocal_r2_r_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + flip_src_B1_r2.get_real());
    computation flip_src_B1_Blocal_r2_i_update("flip_src_B1_Blocal_r2_i_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, flip_src_B1_Blocal_r2_i_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + flip_src_B1_r2.get_imag());

     // Computing src_B2_Blocal_r1

    computation src_B2_Blocal_r1_r_init("src_B2_Blocal_r1_r_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation src_B2_Blocal_r1_i_init("src_B2_Blocal_r1_i_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation src_B2_Blocal_r1_init(&src_B2_Blocal_r1_r_init, &src_B2_Blocal_r1_i_init);

    computation flip_src_B2_Blocal_r1_r_init("flip_src_B2_Blocal_r1_r_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_src_B2_Blocal_r1_i_init("flip_src_B2_Blocal_r1_i_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation flip_src_B2_Blocal_r1_init(&flip_src_B2_Blocal_r1_r_init, &flip_src_B2_Blocal_r1_i_init);

    complex_expr src_B2_r1_prop_0 =  B2_prop(0, t, iCprime, iSprime, src_color_weights(0, wnumBlock, 0), src_spin_weights(0, wnumBlock, 0), x_out*sites_per_rank+x_in, y);
    complex_expr src_B2_r1_prop_2 =  B2_prop(2, t, kCprime, kSprime, src_color_weights(0, wnumBlock, 2), src_spin_weights(0, wnumBlock, 2), x_out*sites_per_rank+x_in, y);
    complex_expr src_B2_r1_prop_1 = B2_prop(1, t, jCprime, jSprime, src_color_weights(0, wnumBlock, 1), src_spin_weights(0, wnumBlock, 1), x_out*sites_per_rank+x_in, y);

    complex_expr src_B2_r1_diquark = ( src_B2_r1_prop_0 * src_B2_r1_prop_2 ) *  src_weights(0, wnumBlock);

    computation src_B2_Blocal_r1_r_props_init("src_B2_Blocal_r1_r_props_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation src_B2_Blocal_r1_i_props_init("src_B2_Blocal_r1_i_props_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));

    computation src_B2_Blocal_r1_r_diquark("src_B2_Blocal_r1_r_diquark", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock}, src_B2_r1_diquark.get_real());
    computation src_B2_Blocal_r1_i_diquark("src_B2_Blocal_r1_i_diquark", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock}, src_B2_r1_diquark.get_imag());

    complex_computation src_B2_Blocal_r1_diquark(&src_B2_Blocal_r1_r_diquark, &src_B2_Blocal_r1_i_diquark);

    complex_expr src_B2_r1_props = src_B2_r1_prop_1 * src_B2_Blocal_r1_diquark(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock);

    computation src_B2_Blocal_r1_r_props("src_B2_Blocal_r1_r_props", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, src_B2_Blocal_r1_r_props_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime) + src_B2_r1_props.get_real());
    computation src_B2_Blocal_r1_i_props("src_B2_Blocal_r1_i_props", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, src_B2_Blocal_r1_i_props_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime) + src_B2_r1_props.get_imag());

    complex_computation src_B2_Blocal_r1_props(&src_B2_Blocal_r1_r_props, &src_B2_Blocal_r1_i_props);

    complex_expr src_B2_r1 = src_psi_B2 * src_B2_Blocal_r1_props(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation src_B2_Blocal_r1_r_update("src_B2_Blocal_r1_r_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, src_B2_Blocal_r1_r_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + src_B2_r1.get_real());
    computation src_B2_Blocal_r1_i_update("src_B2_Blocal_r1_i_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, src_B2_Blocal_r1_i_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + src_B2_r1.get_imag());

    complex_expr flip_src_B2_r1 = src_psi_B1 * src_B2_Blocal_r1_props(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation flip_src_B2_Blocal_r1_r_update("flip_src_B2_Blocal_r1_r_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, flip_src_B2_Blocal_r1_r_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + flip_src_B2_r1.get_real());
    computation flip_src_B2_Blocal_r1_i_update("flip_src_B2_Blocal_r1_i_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, flip_src_B2_Blocal_r1_i_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + flip_src_B2_r1.get_imag());

     // Computing src_B2_Blocal_r2

    computation src_B2_Blocal_r2_r_init("src_B2_Blocal_r2_r_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation src_B2_Blocal_r2_i_init("src_B2_Blocal_r2_i_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation src_B2_Blocal_r2_init(&src_B2_Blocal_r2_r_init, &src_B2_Blocal_r2_i_init);

    computation flip_src_B2_Blocal_r2_r_init("flip_src_B2_Blocal_r2_r_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));
    computation flip_src_B2_Blocal_r2_i_init("flip_src_B2_Blocal_r2_i_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m}, expr((double) 0));

    complex_computation flip_src_B2_Blocal_r2_init(&flip_src_B2_Blocal_r2_r_init, &flip_src_B2_Blocal_r2_i_init);

    complex_expr src_B2_r2_prop_0 =  B2_prop(0, t, iCprime, iSprime, src_color_weights(1, wnumBlock, 0), src_spin_weights(1, wnumBlock, 0), x_out*sites_per_rank+x_in, y);
    complex_expr src_B2_r2_prop_2 =  B2_prop(2, t, kCprime, kSprime, src_color_weights(1, wnumBlock, 2), src_spin_weights(1, wnumBlock, 2), x_out*sites_per_rank+x_in, y);
    complex_expr src_B2_r2_prop_1 = B2_prop(1, t, jCprime, jSprime, src_color_weights(1, wnumBlock, 1), src_spin_weights(1, wnumBlock, 1), x_out*sites_per_rank+x_in, y);

    complex_expr src_B2_r2_diquark = ( src_B2_r2_prop_0 * src_B2_r2_prop_2 ) *  src_weights(1, wnumBlock);

    computation src_B2_Blocal_r2_r_props_init("src_B2_Blocal_r2_r_props_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));
    computation src_B2_Blocal_r2_i_props_init("src_B2_Blocal_r2_i_props_init", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime}, expr((double) 0));

    computation src_B2_Blocal_r2_r_diquark("src_B2_Blocal_r2_r_diquark", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock}, src_B2_r2_diquark.get_real());
    computation src_B2_Blocal_r2_i_diquark("src_B2_Blocal_r2_i_diquark", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock}, src_B2_r2_diquark.get_imag());

    complex_computation src_B2_Blocal_r2_diquark(&src_B2_Blocal_r2_r_diquark, &src_B2_Blocal_r2_i_diquark);

    complex_expr src_B2_r2_props = src_B2_r2_prop_1 * src_B2_Blocal_r2_diquark(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock);

    computation src_B2_Blocal_r2_r_props("src_B2_Blocal_r2_r_props", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, src_B2_Blocal_r2_r_props_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime) + src_B2_r2_props.get_real());
    computation src_B2_Blocal_r2_i_props("src_B2_Blocal_r2_i_props", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}, src_B2_Blocal_r2_i_props_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime) + src_B2_r2_props.get_imag());

    complex_computation src_B2_Blocal_r2_props(&src_B2_Blocal_r2_r_props, &src_B2_Blocal_r2_i_props);

    complex_expr src_B2_r2 = src_psi_B2 * src_B2_Blocal_r2_props(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation src_B2_Blocal_r2_r_update("src_B2_Blocal_r2_r_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, src_B2_Blocal_r2_r_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + src_B2_r2.get_real());
    computation src_B2_Blocal_r2_i_update("src_B2_Blocal_r2_i_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, src_B2_Blocal_r2_i_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + src_B2_r2.get_imag());

    complex_expr flip_src_B2_r2 = src_psi_B1 * src_B2_Blocal_r2_props(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, Nw-1, jCprime, jSprime);

    computation flip_src_B2_Blocal_r2_r_update("flip_src_B2_Blocal_r2_r_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, flip_src_B2_Blocal_r2_r_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + flip_src_B2_r2.get_real());
    computation flip_src_B2_Blocal_r2_i_update("flip_src_B2_Blocal_r2_i_update", {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m}, flip_src_B2_Blocal_r2_i_init(t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m) + flip_src_B2_r2.get_imag()); 
    
     // Computing snk_B1_Blocal_r1

    computation snk_B1_Blocal_r1_r_init("snk_B1_Blocal_r1_r_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));
    computation snk_B1_Blocal_r1_i_init("snk_B1_Blocal_r1_i_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));

    complex_computation snk_B1_Blocal_r1_init(&snk_B1_Blocal_r1_r_init, &snk_B1_Blocal_r1_i_init);

    computation flip_snk_B1_Blocal_r1_r_init("flip_snk_B1_Blocal_r1_r_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));
    computation flip_snk_B1_Blocal_r1_i_init("flip_snk_B1_Blocal_r1_i_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));

    complex_computation flip_snk_B1_Blocal_r1_init(&flip_snk_B1_Blocal_r1_r_init, &flip_snk_B1_Blocal_r1_i_init);

    complex_expr snk_B1_r1_prop_0 =  B1_prop(0, t, src_color_weights(0, wnumBlock, 0), src_spin_weights(0, wnumBlock, 0), iCprime, iSprime, x, y_out*src_sites_per_rank+y_in);
    complex_expr snk_B1_r1_prop_2 =  B1_prop(2, t, src_color_weights(0, wnumBlock, 2), src_spin_weights(0, wnumBlock, 2), kCprime, kSprime, x, y_out*src_sites_per_rank+y_in);
    complex_expr snk_B1_r1_prop_1 = B1_prop(1, t, src_color_weights(0, wnumBlock, 1), src_spin_weights(0, wnumBlock, 1), jCprime, jSprime, x, y_out*src_sites_per_rank+y_in);

    complex_expr snk_B1_r1_diquark = ( snk_B1_r1_prop_0 * snk_B1_r1_prop_2 ) *  src_weights(0, wnumBlock);

    computation snk_B1_Blocal_r1_r_props_init("snk_B1_Blocal_r1_r_props_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime}, expr((double) 0));
    computation snk_B1_Blocal_r1_i_props_init("snk_B1_Blocal_r1_i_props_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime}, expr((double) 0));

    computation snk_B1_Blocal_r1_r_diquark("snk_B1_Blocal_r1_r_diquark", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock}, snk_B1_r1_diquark.get_real());
    computation snk_B1_Blocal_r1_i_diquark("snk_B1_Blocal_r1_i_diquark", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock}, snk_B1_r1_diquark.get_imag());

    complex_computation snk_B1_Blocal_r1_diquark(&snk_B1_Blocal_r1_r_diquark, &snk_B1_Blocal_r1_i_diquark);

    complex_expr snk_B1_r1_props = snk_B1_r1_prop_1 * snk_B1_Blocal_r1_diquark(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock);

    computation snk_B1_Blocal_r1_r_props("snk_B1_Blocal_r1_r_props", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock, jCprime, jSprime}, snk_B1_Blocal_r1_r_props_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime) + snk_B1_r1_props.get_real());
    computation snk_B1_Blocal_r1_i_props("snk_B1_Blocal_r1_i_props", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock, jCprime, jSprime}, snk_B1_Blocal_r1_i_props_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime) + snk_B1_r1_props.get_imag());

    complex_computation snk_B1_Blocal_r1_props(&snk_B1_Blocal_r1_r_props, &snk_B1_Blocal_r1_i_props);

    complex_expr snk_B1_r1 = snk_psi_B1 * snk_B1_Blocal_r1_props(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, Nw-1, jCprime, jSprime);

    computation snk_B1_Blocal_r1_r_update("snk_B1_Blocal_r1_r_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, snk_B1_Blocal_r1_r_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + snk_B1_r1.get_real());
    computation snk_B1_Blocal_r1_i_update("snk_B1_Blocal_r1_i_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, snk_B1_Blocal_r1_i_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + snk_B1_r1.get_imag());

    complex_expr flip_snk_B1_r1 = snk_psi_B2 * snk_B1_Blocal_r1_props(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, Nw-1, jCprime, jSprime);

    computation flip_snk_B1_Blocal_r1_r_update("flip_snk_B1_Blocal_r1_r_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, flip_snk_B1_Blocal_r1_r_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + flip_snk_B1_r1.get_real());
    computation flip_snk_B1_Blocal_r1_i_update("flip_snk_B1_Blocal_r1_i_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, flip_snk_B1_Blocal_r1_i_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + flip_snk_B1_r1.get_imag());

     // Computing snk_B1_Blocal_r2

    computation snk_B1_Blocal_r2_r_init("snk_B1_Blocal_r2_r_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));
    computation snk_B1_Blocal_r2_i_init("snk_B1_Blocal_r2_i_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));

    complex_computation snk_B1_Blocal_r2_init(&snk_B1_Blocal_r2_r_init, &snk_B1_Blocal_r2_i_init);

    computation flip_snk_B1_Blocal_r2_r_init("flip_snk_B1_Blocal_r2_r_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));
    computation flip_snk_B1_Blocal_r2_i_init("flip_snk_B1_Blocal_r2_i_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));

    complex_computation flip_snk_B1_Blocal_r2_init(&flip_snk_B1_Blocal_r2_r_init, &flip_snk_B1_Blocal_r2_i_init);

    complex_expr snk_B1_r2_prop_0 =  B1_prop(0, t, src_color_weights(1, wnumBlock, 0), src_spin_weights(1, wnumBlock, 0), iCprime, iSprime, x, y_out*src_sites_per_rank+y_in);
    complex_expr snk_B1_r2_prop_2 =  B1_prop(2, t, src_color_weights(1, wnumBlock, 2), src_spin_weights(1, wnumBlock, 2), kCprime, kSprime, x, y_out*src_sites_per_rank+y_in);
    complex_expr snk_B1_r2_prop_1 = B1_prop(1, t, src_color_weights(1, wnumBlock, 1), src_spin_weights(1, wnumBlock, 1), jCprime, jSprime, x, y_out*src_sites_per_rank+y_in);

    complex_expr snk_B1_r2_diquark = ( snk_B1_r2_prop_0 * snk_B1_r2_prop_2 ) *  src_weights(1, wnumBlock);

    computation snk_B1_Blocal_r2_r_props_init("snk_B1_Blocal_r2_r_props_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime}, expr((double) 0));
    computation snk_B1_Blocal_r2_i_props_init("snk_B1_Blocal_r2_i_props_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime}, expr((double) 0));

    computation snk_B1_Blocal_r2_r_diquark("snk_B1_Blocal_r2_r_diquark", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock}, snk_B1_r2_diquark.get_real());
    computation snk_B1_Blocal_r2_i_diquark("snk_B1_Blocal_r2_i_diquark", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock}, snk_B1_r2_diquark.get_imag());

    complex_computation snk_B1_Blocal_r2_diquark(&snk_B1_Blocal_r2_r_diquark, &snk_B1_Blocal_r2_i_diquark);

    complex_expr snk_B1_r2_props = snk_B1_r2_prop_1 * snk_B1_Blocal_r2_diquark(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock);

    computation snk_B1_Blocal_r2_r_props("snk_B1_Blocal_r2_r_props", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock, jCprime, jSprime}, snk_B1_Blocal_r2_r_props_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime) + snk_B1_r2_props.get_real());
    computation snk_B1_Blocal_r2_i_props("snk_B1_Blocal_r2_i_props", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock, jCprime, jSprime}, snk_B1_Blocal_r2_i_props_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime) + snk_B1_r2_props.get_imag());

    complex_computation snk_B1_Blocal_r2_props(&snk_B1_Blocal_r2_r_props, &snk_B1_Blocal_r2_i_props);

    complex_expr snk_B1_r2 = snk_psi_B1 * snk_B1_Blocal_r2_props(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, Nw-1, jCprime, jSprime);

    computation snk_B1_Blocal_r2_r_update("snk_B1_Blocal_r2_r_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, snk_B1_Blocal_r2_r_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + snk_B1_r2.get_real());
    computation snk_B1_Blocal_r2_i_update("snk_B1_Blocal_r2_i_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, snk_B1_Blocal_r2_i_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + snk_B1_r2.get_imag()); 

    complex_expr flip_snk_B1_r2 = snk_psi_B2 * snk_B1_Blocal_r2_props(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, Nw-1, jCprime, jSprime);

    computation flip_snk_B1_Blocal_r2_r_update("flip_snk_B1_Blocal_r2_r_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, flip_snk_B1_Blocal_r2_r_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + flip_snk_B1_r2.get_real());
    computation flip_snk_B1_Blocal_r2_i_update("flip_snk_B1_Blocal_r2_i_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, flip_snk_B1_Blocal_r2_i_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + flip_snk_B1_r2.get_imag());

     // Computing snk_B2_Blocal_r1

    computation snk_B2_Blocal_r1_r_init("snk_B2_Blocal_r1_r_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));
    computation snk_B2_Blocal_r1_i_init("snk_B2_Blocal_r1_i_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));

    complex_computation snk_B2_Blocal_r1_init(&snk_B2_Blocal_r1_r_init, &snk_B2_Blocal_r1_i_init);

    computation flip_snk_B2_Blocal_r1_r_init("flip_snk_B2_Blocal_r1_r_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));
    computation flip_snk_B2_Blocal_r1_i_init("flip_snk_B2_Blocal_r1_i_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));

    complex_computation flip_snk_B2_Blocal_r1_init(&flip_snk_B2_Blocal_r1_r_init, &flip_snk_B2_Blocal_r1_i_init);

    complex_expr snk_B2_r1_prop_0 =  B2_prop(0, t, src_color_weights(0, wnumBlock, 0), src_spin_weights(0, wnumBlock, 0), iCprime, iSprime, x, y_out*src_sites_per_rank+y_in);
    complex_expr snk_B2_r1_prop_2 =  B2_prop(2, t, src_color_weights(0, wnumBlock, 2), src_spin_weights(0, wnumBlock, 2), kCprime, kSprime, x, y_out*src_sites_per_rank+y_in);
    complex_expr snk_B2_r1_prop_1 = B2_prop(1, t, src_color_weights(0, wnumBlock, 1), src_spin_weights(0, wnumBlock, 1), jCprime, jSprime, x, y_out*src_sites_per_rank+y_in);

    complex_expr snk_B2_r1_diquark = ( snk_B2_r1_prop_0 * snk_B2_r1_prop_2 ) *  src_weights(0, wnumBlock);

    computation snk_B2_Blocal_r1_r_props_init("snk_B2_Blocal_r1_r_props_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime}, expr((double) 0));
    computation snk_B2_Blocal_r1_i_props_init("snk_B2_Blocal_r1_i_props_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime}, expr((double) 0));

    computation snk_B2_Blocal_r1_r_diquark("snk_B2_Blocal_r1_r_diquark", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock}, snk_B2_r1_diquark.get_real());
    computation snk_B2_Blocal_r1_i_diquark("snk_B2_Blocal_r1_i_diquark", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock}, snk_B2_r1_diquark.get_imag());

    complex_computation snk_B2_Blocal_r1_diquark(&snk_B2_Blocal_r1_r_diquark, &snk_B2_Blocal_r1_i_diquark);

    complex_expr snk_B2_r1_props = snk_B2_r1_prop_1 * snk_B2_Blocal_r1_diquark(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock);

    computation snk_B2_Blocal_r1_r_props("snk_B2_Blocal_r1_r_props", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock, jCprime, jSprime}, snk_B2_Blocal_r1_r_props_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime) + snk_B2_r1_props.get_real());
    computation snk_B2_Blocal_r1_i_props("snk_B2_Blocal_r1_i_props", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock, jCprime, jSprime}, snk_B2_Blocal_r1_i_props_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime) + snk_B2_r1_props.get_imag());

    complex_computation snk_B2_Blocal_r1_props(&snk_B2_Blocal_r1_r_props, &snk_B2_Blocal_r1_i_props);

    complex_expr snk_B2_r1 = snk_psi_B2 * snk_B2_Blocal_r1_props(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, Nw-1, jCprime, jSprime);

    computation snk_B2_Blocal_r1_r_update("snk_B2_Blocal_r1_r_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, snk_B2_Blocal_r1_r_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + snk_B2_r1.get_real());
    computation snk_B2_Blocal_r1_i_update("snk_B2_Blocal_r1_i_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, snk_B2_Blocal_r1_i_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + snk_B2_r1.get_imag());

    complex_expr flip_snk_B2_r1 = snk_psi_B1 * snk_B2_Blocal_r1_props(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, Nw-1, jCprime, jSprime);

    computation flip_snk_B2_Blocal_r1_r_update("flip_snk_B2_Blocal_r1_r_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, flip_snk_B2_Blocal_r1_r_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + flip_snk_B2_r1.get_real());
    computation flip_snk_B2_Blocal_r1_i_update("flip_snk_B2_Blocal_r1_i_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, flip_snk_B2_Blocal_r1_i_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + flip_snk_B2_r1.get_imag());

     // Computing snk_B2_Blocal_r2

    computation snk_B2_Blocal_r2_r_init("snk_B2_Blocal_r2_r_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));
    computation snk_B2_Blocal_r2_i_init("snk_B2_Blocal_r2_i_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));

    complex_computation snk_B2_Blocal_r2_init(&snk_B2_Blocal_r2_r_init, &snk_B2_Blocal_r2_i_init);

    computation flip_snk_B2_Blocal_r2_r_init("flip_snk_B2_Blocal_r2_r_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));
    computation flip_snk_B2_Blocal_r2_i_init("flip_snk_B2_Blocal_r2_i_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n}, expr((double) 0));

    complex_computation flip_snk_B2_Blocal_r2_init(&flip_snk_B2_Blocal_r2_r_init, &flip_snk_B2_Blocal_r2_i_init);

    complex_expr snk_B2_r2_prop_0 =  B2_prop(0, t, src_color_weights(1, wnumBlock, 0), src_spin_weights(1, wnumBlock, 0), iCprime, iSprime, x, y_out*src_sites_per_rank+y_in);
    complex_expr snk_B2_r2_prop_2 =  B2_prop(2, t, src_color_weights(1, wnumBlock, 2), src_spin_weights(1, wnumBlock, 2), kCprime, kSprime, x, y_out*src_sites_per_rank+y_in);
    complex_expr snk_B2_r2_prop_1 = B2_prop(1, t, src_color_weights(1, wnumBlock, 1), src_spin_weights(1, wnumBlock, 1), jCprime, jSprime, x, y_out*src_sites_per_rank+y_in);

    complex_expr snk_B2_r2_diquark = ( snk_B2_r2_prop_0 * snk_B2_r2_prop_2 ) *  src_weights(1, wnumBlock);

    computation snk_B2_Blocal_r2_r_props_init("snk_B2_Blocal_r2_r_props_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime}, expr((double) 0));
    computation snk_B2_Blocal_r2_i_props_init("snk_B2_Blocal_r2_i_props_init", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime}, expr((double) 0));

    computation snk_B2_Blocal_r2_r_diquark("snk_B2_Blocal_r2_r_diquark", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock}, snk_B2_r2_diquark.get_real());
    computation snk_B2_Blocal_r2_i_diquark("snk_B2_Blocal_r2_i_diquark", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock}, snk_B2_r2_diquark.get_imag());

    complex_computation snk_B2_Blocal_r2_diquark(&snk_B2_Blocal_r2_r_diquark, &snk_B2_Blocal_r2_i_diquark);

    complex_expr snk_B2_r2_props = snk_B2_r2_prop_1 * snk_B2_Blocal_r2_diquark(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock);

    computation snk_B2_Blocal_r2_r_props("snk_B2_Blocal_r2_r_props", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock, jCprime, jSprime}, snk_B2_Blocal_r2_r_props_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime) + snk_B2_r2_props.get_real());
    computation snk_B2_Blocal_r2_i_props("snk_B2_Blocal_r2_i_props", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, wnumBlock, jCprime, jSprime}, snk_B2_Blocal_r2_i_props_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime) + snk_B2_r2_props.get_imag());

    complex_computation snk_B2_Blocal_r2_props(&snk_B2_Blocal_r2_r_props, &snk_B2_Blocal_r2_i_props);

    complex_expr snk_B2_r2 = snk_psi_B2 * snk_B2_Blocal_r2_props(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, Nw-1, jCprime, jSprime);

    computation snk_B2_Blocal_r2_r_update("snk_B2_Blocal_r2_r_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, snk_B2_Blocal_r2_r_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + snk_B2_r2.get_real());
    computation snk_B2_Blocal_r2_i_update("snk_B2_Blocal_r2_i_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, snk_B2_Blocal_r2_i_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + snk_B2_r2.get_imag());

    complex_expr flip_snk_B2_r2 = snk_psi_B1 * snk_B2_Blocal_r2_props(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, Nw-1, jCprime, jSprime);

    computation flip_snk_B2_Blocal_r2_r_update("flip_snk_B2_Blocal_r2_r_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, flip_snk_B2_Blocal_r2_r_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + flip_snk_B2_r2.get_real());
    computation flip_snk_B2_Blocal_r2_i_update("flip_snk_B2_Blocal_r2_i_update", {t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, x, jCprime, jSprime, n}, flip_snk_B2_Blocal_r2_i_init(t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n) + flip_snk_B2_r2.get_imag());

    /* Correlators */

    computation C_init_r("C_init_r", {t, x_out, x_in, rp, mpmH, r, npnH}, expr((double) 0));
    computation C_init_i("C_init_i", {t, x_out, x_in, rp, mpmH, r, npnH}, expr((double) 0));

    // BB_BB
    computation C_BB_BB_prop_init_r("C_BB_BB_prop_init_r", {t, x1, x2, rp, m, r}, expr((double) 0));
    computation C_BB_BB_prop_init_i("C_BB_BB_prop_init_i", {t, x1, x2, rp, m, r}, expr((double) 0));
    
    b=0;
    // r1, b = 0 
    complex_computation BB_BB_new_term_0_r1_b1("BB_BB_new_term_0_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Blocal_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_1_r1_b1("BB_BB_new_term_1_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Blocal_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_2_r1_b1("BB_BB_new_term_2_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bfirst_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_3_r1_b1("BB_BB_new_term_3_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bfirst_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_4_r1_b1("BB_BB_new_term_4_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bsecond_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_5_r1_b1("BB_BB_new_term_5_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bsecond_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_6_r1_b1("BB_BB_new_term_6_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bthird_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_7_r1_b1("BB_BB_new_term_7_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bthird_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    BB_BB_new_term_0_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_1_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_2_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_3_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_4_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_5_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_6_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_7_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));

    // r2, b = 0 
    complex_computation BB_BB_new_term_0_r2_b1("BB_BB_new_term_0_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Blocal_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_1_r2_b1("BB_BB_new_term_1_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Blocal_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_2_r2_b1("BB_BB_new_term_2_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bfirst_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_3_r2_b1("BB_BB_new_term_3_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bfirst_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_4_r2_b1("BB_BB_new_term_4_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bsecond_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_5_r2_b1("BB_BB_new_term_5_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bsecond_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_6_r2_b1("BB_BB_new_term_6_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bthird_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation BB_BB_new_term_7_r2_b1("BB_BB_new_term_7_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bthird_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    BB_BB_new_term_0_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_1_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_2_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_3_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_4_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_5_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_6_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_7_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));

    b=1;
    // r1, b = 1 
    complex_computation BB_BB_new_term_0_r1_b2("BB_BB_new_term_0_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Blocal_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_1_r1_b2("BB_BB_new_term_1_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Blocal_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_2_r1_b2("BB_BB_new_term_2_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bfirst_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_3_r1_b2("BB_BB_new_term_3_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bfirst_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_4_r1_b2("BB_BB_new_term_4_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bsecond_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_5_r1_b2("BB_BB_new_term_5_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bsecond_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_6_r1_b2("BB_BB_new_term_6_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bthird_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_7_r1_b2("BB_BB_new_term_7_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bthird_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    BB_BB_new_term_0_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_1_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_2_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_3_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_4_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_5_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_6_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_7_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));

    // r2, b = 1
    complex_computation BB_BB_new_term_0_r2_b2("BB_BB_new_term_0_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Blocal_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_1_r2_b2("BB_BB_new_term_1_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Blocal_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_2_r2_b2("BB_BB_new_term_2_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bfirst_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_3_r2_b2("BB_BB_new_term_3_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bfirst_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_4_r2_b2("BB_BB_new_term_4_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bsecond_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_5_r2_b2("BB_BB_new_term_5_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bsecond_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_6_r2_b2("BB_BB_new_term_6_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B1_Bthird_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation BB_BB_new_term_7_r2_b2("BB_BB_new_term_7_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, B2_Bthird_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    BB_BB_new_term_0_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_1_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_2_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_3_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_4_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));
    BB_BB_new_term_5_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_6_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    BB_BB_new_term_7_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));

    complex_expr prefactor(cast(p_float64, sigs(nperm)) * snk_weights(r, wnum) * src_spin_block_weights(rp, s), 0.0);

    complex_expr BB_BB_term_res_b1 = BB_BB_new_term_0_r1_b1(t, x1, x2, rp, m, r, s, nperm, wnum);
    complex_expr BB_BB_term_res_b2 = BB_BB_new_term_0_r1_b2(t, x1, x2, rp, m, r, s, nperm, wnum);

    complex_expr BB_BB_term_res = prefactor * BB_BB_term_res_b1 * BB_BB_term_res_b2;

    b=0;
    // r1, b = 0 
    complex_computation flip_BB_BB_new_term_0_r1_b1("flip_BB_BB_new_term_0_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Blocal_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_1_r1_b1("flip_BB_BB_new_term_1_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Blocal_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_2_r1_b1("flip_BB_BB_new_term_2_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bfirst_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_3_r1_b1("flip_BB_BB_new_term_3_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bfirst_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_4_r1_b1("flip_BB_BB_new_term_4_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bsecond_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_5_r1_b1("flip_BB_BB_new_term_5_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bsecond_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_6_r1_b1("flip_BB_BB_new_term_6_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bthird_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_7_r1_b1("flip_BB_BB_new_term_7_r1_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bthird_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    flip_BB_BB_new_term_0_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_1_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_2_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_3_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_4_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_5_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_6_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_7_r1_b1.add_predicate((src_spins(rp, s, 0) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));
    
    // r2, b = 0 
    complex_computation flip_BB_BB_new_term_0_r2_b1("flip_BB_BB_new_term_0_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Blocal_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_1_r2_b1("flip_BB_BB_new_term_1_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Blocal_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_2_r2_b1("flip_BB_BB_new_term_2_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bfirst_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_3_r2_b1("flip_BB_BB_new_term_3_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bfirst_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_4_r2_b1("flip_BB_BB_new_term_4_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bsecond_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_5_r2_b1("flip_BB_BB_new_term_5_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bsecond_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_6_r2_b1("flip_BB_BB_new_term_6_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bthird_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    complex_computation flip_BB_BB_new_term_7_r2_b1("flip_BB_BB_new_term_7_r2_b1", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bthird_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 0), snk_spin_weights(r, nperm, wnum, 0, 0), x2, snk_color_weights(r, nperm, wnum, 2, 0), snk_spin_weights(r, nperm, wnum, 2, 0), snk_color_weights(r, nperm, wnum, 1, 0), snk_spin_weights(r, nperm, wnum, 1, 0), m));
    flip_BB_BB_new_term_0_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_1_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_2_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_3_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_4_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_5_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_6_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_7_r2_b1.add_predicate((src_spins(rp, s, 0) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));

    b=1;
    // r1, b = 1 
    complex_computation flip_BB_BB_new_term_0_r1_b2("flip_BB_BB_new_term_0_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Blocal_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_1_r1_b2("flip_BB_BB_new_term_1_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Blocal_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_2_r1_b2("flip_BB_BB_new_term_2_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bfirst_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_3_r1_b2("flip_BB_BB_new_term_3_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bfirst_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_4_r1_b2("flip_BB_BB_new_term_4_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bsecond_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_5_r1_b2("flip_BB_BB_new_term_5_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bsecond_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_6_r1_b2("flip_BB_BB_new_term_6_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bthird_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_7_r1_b2("flip_BB_BB_new_term_7_r1_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bthird_r1_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    flip_BB_BB_new_term_0_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_1_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_2_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_3_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_4_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_5_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_6_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_7_r1_b2.add_predicate((src_spins(rp, s, 1) == 1) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));

    // r2, b = 1 
    complex_computation flip_BB_BB_new_term_0_r2_b2("flip_BB_BB_new_term_0_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Blocal_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_1_r2_b2("flip_BB_BB_new_term_1_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Blocal_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_2_r2_b2("flip_BB_BB_new_term_2_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bfirst_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_3_r2_b2("flip_BB_BB_new_term_3_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bfirst_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_4_r2_b2("flip_BB_BB_new_term_4_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bsecond_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_5_r2_b2("flip_BB_BB_new_term_5_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bsecond_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_6_r2_b2("flip_BB_BB_new_term_6_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B1_Bthird_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    complex_computation flip_BB_BB_new_term_7_r2_b2("flip_BB_BB_new_term_7_r2_b2", {t, x1, x2, rp, m, r, s, nperm, wnum}, flip_B2_Bthird_r2_init(t, x1, snk_color_weights(r, nperm, wnum, 0, 1), snk_spin_weights(r, nperm, wnum, 0, 1), x2, snk_color_weights(r, nperm, wnum, 2, 1), snk_spin_weights(r, nperm, wnum, 2, 1), snk_color_weights(r, nperm, wnum, 1, 1), snk_spin_weights(r, nperm, wnum, 1, 1), m));
    flip_BB_BB_new_term_0_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_1_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_2_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_3_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_4_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));
    flip_BB_BB_new_term_5_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_6_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 0 && snk_b(nperm, 1, b) == 0 && snk_b(nperm, 2, b) == 1));
    flip_BB_BB_new_term_7_r2_b2.add_predicate((src_spins(rp, s, 1) == 2) && (snk_b(nperm, 0, b) == 1 && snk_b(nperm, 1, b) == 1 && snk_b(nperm, 2, b) == 0));

    complex_expr flip_BB_BB_term_res_b1 = flip_BB_BB_new_term_0_r1_b1(t, x1, x2, rp, m, r, s, nperm, wnum);
    complex_expr flip_BB_BB_term_res_b2 = flip_BB_BB_new_term_0_r1_b2(t, x1, x2, rp, m, r, s, nperm, wnum);

    complex_expr flip_BB_BB_term_res = prefactor * flip_BB_BB_term_res_b1 * flip_BB_BB_term_res_b2;


    computation C_BB_BB_prop_update_r("C_BB_BB_prop_update_r", {t, x1, x2, rp, m, r, s, nperm, wnum}, C_BB_BB_prop_init_r(t, x1, x2, rp, m, r) + tiramisu::expr( 0.5 ) * BB_BB_term_res.get_real() );
    computation C_BB_BB_prop_update_i("C_BB_BB_prop_update_i", {t, x1, x2, rp, m, r, s, nperm, wnum}, C_BB_BB_prop_init_i(t, x1, x2, rp, m, r) + tiramisu::expr( 0.5 ) * BB_BB_term_res.get_imag() );

    computation C_BB_BB_prop_update_r_2("C_BB_BB_prop_update_r_2", {t, x1, x2, rp, m, r, s, nperm, wnum}, C_BB_BB_prop_init_r(t, x1, x2, rp, m, r) + tiramisu::expr( 0.5 ) * flip_BB_BB_term_res.get_real() );
    computation C_BB_BB_prop_update_i_2("C_BB_BB_prop_update_i_2", {t, x1, x2, rp, m, r, s, nperm, wnum}, C_BB_BB_prop_init_i(t, x1, x2, rp, m, r) + tiramisu::expr( 0.5 ) * flip_BB_BB_term_res.get_imag() );


    complex_computation C_BB_BB_prop_update(&C_BB_BB_prop_update_r, &C_BB_BB_prop_update_i);

    complex_expr BB_BB_term_s = (snk_psi_B1_ue * snk_psi_B2_x2_ue + snk_psi_B1_x2_ue * snk_psi_B2_ue) * C_BB_BB_prop_update(t, x1, x2, rp, m, r, 1, Nperms-1, Nw2-1);
    complex_expr BB_BB_term_b = snk_psi * C_BB_BB_prop_update(t, x1, x2, rp, m, r, 1, Nperms-1, Nw2-1);

        // t, x1, x2, rp, m, r, nue}
        // Lt, Vsnk, Vsnk, B2Nrows, Nsrc, B2Nrows, Nsnk

    computation C_BB_init_r("C_BB_init_r", {t, x1, x2, rp, m, r, n}, expr((double) 0));
    computation C_BB_init_i("C_BB_init_i", {t, x1, x2, rp, m, r, n}, expr((double) 0));

    buffer buf_C_BB_r("buf_C_BB_r", {Lt, Vsnk, Vsnk, B2Nrows, Nsrc, B2Nrows, Nsnk}, p_float64, a_temporary);
    buffer buf_C_BB_i("buf_C_BB_i", {Lt, Vsnk, Vsnk, B2Nrows, Nsrc, B2Nrows, Nsnk}, p_float64, a_temporary);
    buffer buf_C_BB_r_cpu("buf_C_BB_r_cpu", {Lt, Vsnk, Vsnk, B2Nrows, Nsrc, B2Nrows, Nsnk}, p_float64, a_temporary);
    buffer buf_C_BB_i_cpu("buf_C_BB_i_cpu", {Lt, Vsnk, Vsnk, B2Nrows, Nsrc, B2Nrows, Nsnk}, p_float64, a_temporary);
    buf_C_BB_r.tag_gpu_global();
    buf_C_BB_i.tag_gpu_global();
    C_BB_init_r.store_in(&buf_C_BB_r, {t, x1, x2, rp, m, r, n});
    C_BB_init_i.store_in(&buf_C_BB_i, {t, x1, x2, rp, m, r, n});

    computation C_BB_BB_update_s_r("C_BB_BB_update_s_r", {t, x1, x2, rp, m, r, nue}, C_BB_init_r(t, x1, x2, rp, m, r, NEntangled+nue) + BB_BB_term_s.get_real());
    computation C_BB_BB_update_s_i("C_BB_BB_update_s_i", {t, x1, x2, rp, m, r, nue}, C_BB_init_i(t, x1, x2, rp, m, r, NEntangled+nue) + BB_BB_term_s.get_imag());

    computation C_BB_BB_update_b_r("C_BB_BB_update_b_r", {t, x1, x2, rp, m, r, ne}, C_BB_init_r(t, x1, x2, rp, m, r, ne) + BB_BB_term_b.get_real());
    computation C_BB_BB_update_b_i("C_BB_BB_update_b_i", {t, x1, x2, rp, m, r, ne}, C_BB_init_i(t, x1, x2, rp, m, r, ne) + BB_BB_term_b.get_imag());

    // BB_H
    computation C_BB_H_prop_init_r("C_BB_H_prop_init_r", {t, x_out, x_in, rp, m, r}, expr((double) 0));
    computation C_BB_H_prop_init_i("C_BB_H_prop_init_i", {t, x_out, x_in, rp, m, r}, expr((double) 0));
    
    complex_computation BB_H_new_term_0_r1_b1("BB_H_new_term_0_r1_b1", {t, x_out, x_in, rp, m, r, s, nperm, wnumHex}, src_B1_Blocal_r1_init(t, x_out, x_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 0), hex_snk_spin_weights(r, nperm, wnumHex, 0, 0), hex_snk_color_weights(r, nperm, wnumHex, 2, 0), hex_snk_spin_weights(r, nperm, wnumHex, 2, 0), hex_snk_color_weights(r, nperm, wnumHex, 1, 0), hex_snk_spin_weights(r, nperm, wnumHex, 1, 0), m));
    BB_H_new_term_0_r1_b1.add_predicate((src_spins(rp, s, 0) == 1));
    complex_computation BB_H_new_term_0_r2_b1("BB_H_new_term_0_r2_b1", {t, x_out, x_in, rp, m, r, s, nperm, wnumHex}, src_B1_Blocal_r2_init(t, x_out, x_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 0), hex_snk_spin_weights(r, nperm, wnumHex, 0, 0), hex_snk_color_weights(r, nperm, wnumHex, 2, 0), hex_snk_spin_weights(r, nperm, wnumHex, 2, 0), hex_snk_color_weights(r, nperm, wnumHex, 1, 0), hex_snk_spin_weights(r, nperm, wnumHex, 1, 0), m));
    BB_H_new_term_0_r2_b1.add_predicate((src_spins(rp, s, 0) == 2));

    complex_computation BB_H_new_term_0_r1_b2("BB_H_new_term_0_r1_b2", {t, x_out, x_in, rp, m, r, s, nperm, wnumHex}, src_B2_Blocal_r1_init(t, x_out, x_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 1), hex_snk_spin_weights(r, nperm, wnumHex, 0, 1), hex_snk_color_weights(r, nperm, wnumHex, 2, 1), hex_snk_spin_weights(r, nperm, wnumHex, 2, 1), hex_snk_color_weights(r, nperm, wnumHex, 1, 1), hex_snk_spin_weights(r, nperm, wnumHex, 1, 1), m));
    BB_H_new_term_0_r1_b2.add_predicate((src_spins(rp, s, 1) == 1));
    complex_computation BB_H_new_term_0_r2_b2("BB_H_new_term_0_r2_b2", {t, x_out, x_in, rp, m, r, s, nperm, wnumHex}, src_B2_Blocal_r2_init(t, x_out, x_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 1), hex_snk_spin_weights(r, nperm, wnumHex, 0, 1), hex_snk_color_weights(r, nperm, wnumHex, 2, 1), hex_snk_spin_weights(r, nperm, wnumHex, 2, 1), hex_snk_color_weights(r, nperm, wnumHex, 1, 1), hex_snk_spin_weights(r, nperm, wnumHex, 1, 1), m));
    BB_H_new_term_0_r2_b2.add_predicate((src_spins(rp, s, 1) == 2));

    complex_expr BB_H_term_res_b1 = BB_H_new_term_0_r1_b1(t, x_out, x_in, rp, m, r, s, nperm, wnumHex);
    complex_expr BB_H_term_res_b2 = BB_H_new_term_0_r1_b2(t, x_out, x_in, rp, m, r, s, nperm, wnumHex);

    complex_expr src_hex_prefactor(cast(p_float64, sigs(nperm)) * hex_snk_weights(r, wnumHex) * src_spin_block_weights(rp, s), 0.0);

    complex_expr BB_H_term_res = src_hex_prefactor * BB_H_term_res_b1 * BB_H_term_res_b2;
    
    complex_computation flip_BB_H_new_term_0_r1_b1("flip_BB_H_new_term_0_r1_b1", {t, x_out, x_in, rp, m, r, s, nperm, wnumHex}, flip_src_B1_Blocal_r1_init(t, x_out, x_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 0), hex_snk_spin_weights(r, nperm, wnumHex, 0, 0), hex_snk_color_weights(r, nperm, wnumHex, 2, 0), hex_snk_spin_weights(r, nperm, wnumHex, 2, 0), hex_snk_color_weights(r, nperm, wnumHex, 1, 0), hex_snk_spin_weights(r, nperm, wnumHex, 1, 0), m));
    flip_BB_H_new_term_0_r1_b1.add_predicate((src_spins(rp, s, 0) == 1));
    complex_computation flip_BB_H_new_term_0_r2_b1("flip_BB_H_new_term_0_r2_b1", {t, x_out, x_in, rp, m, r, s, nperm, wnumHex}, flip_src_B1_Blocal_r2_init(t, x_out, x_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 0), hex_snk_spin_weights(r, nperm, wnumHex, 0, 0), hex_snk_color_weights(r, nperm, wnumHex, 2, 0), hex_snk_spin_weights(r, nperm, wnumHex, 2, 0), hex_snk_color_weights(r, nperm, wnumHex, 1, 0), hex_snk_spin_weights(r, nperm, wnumHex, 1, 0), m));
    flip_BB_H_new_term_0_r2_b1.add_predicate((src_spins(rp, s, 0) == 2));

    complex_computation flip_BB_H_new_term_0_r1_b2("flip_BB_H_new_term_0_r1_b2", {t, x_out, x_in, rp, m, r, s, nperm, wnumHex}, flip_src_B2_Blocal_r1_init(t, x_out, x_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 1), hex_snk_spin_weights(r, nperm, wnumHex, 0, 1), hex_snk_color_weights(r, nperm, wnumHex, 2, 1), hex_snk_spin_weights(r, nperm, wnumHex, 2, 1), hex_snk_color_weights(r, nperm, wnumHex, 1, 1), hex_snk_spin_weights(r, nperm, wnumHex, 1, 1), m));
    flip_BB_H_new_term_0_r1_b2.add_predicate((src_spins(rp, s, 1) == 1));
    complex_computation flip_BB_H_new_term_0_r2_b2("flip_BB_H_new_term_0_r2_b2", {t, x_out, x_in, rp, m, r, s, nperm, wnumHex}, flip_src_B2_Blocal_r2_init(t, x_out, x_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 1), hex_snk_spin_weights(r, nperm, wnumHex, 0, 1), hex_snk_color_weights(r, nperm, wnumHex, 2, 1), hex_snk_spin_weights(r, nperm, wnumHex, 2, 1), hex_snk_color_weights(r, nperm, wnumHex, 1, 1), hex_snk_spin_weights(r, nperm, wnumHex, 1, 1), m));
    flip_BB_H_new_term_0_r2_b2.add_predicate((src_spins(rp, s, 1) == 2));

    complex_expr flip_BB_H_term_res_b1 = flip_BB_H_new_term_0_r1_b1(t, x_out, x_in, rp, m, r, s, nperm, wnumHex);
    complex_expr flip_BB_H_term_res_b2 = flip_BB_H_new_term_0_r1_b2(t, x_out, x_in, rp, m, r, s, nperm, wnumHex);

    complex_expr flip_BB_H_term_res = src_hex_prefactor * flip_BB_H_term_res_b1 * flip_BB_H_term_res_b2;

    computation C_BB_H_prop_update_r("C_BB_H_prop_update_r", {t, x_out, x_in, rp, m, r, s, nperm, wnumHex}, C_BB_H_prop_init_r(t, x_out, x_in, rp, m, r) + (BB_H_term_res.get_real() + flip_BB_H_term_res.get_real())/2.0 );
    computation C_BB_H_prop_update_i("C_BB_H_prop_update_i", {t, x_out, x_in, rp, m, r, s, nperm, wnumHex}, C_BB_H_prop_init_i(t, x_out, x_in, rp, m, r) + (BB_H_term_res.get_imag() + flip_BB_H_term_res.get_imag())/2.0 );

    complex_computation C_BB_H_prop_update(&C_BB_H_prop_update_r, &C_BB_H_prop_update_i);

    complex_expr BB_H_term = hex_snk_psi * C_BB_H_prop_update(t, x_out, x_in, rp, m, r, 1, Nperms-1, Nw2Hex-1);

    computation C_BB_H_update_r("C_BB_H_update_r", {t, x_out, x_in, rp, m, r, nH}, C_init_r(t, x_out, x_in, rp, m, r, Nsnk+nH) + BB_H_term.get_real());
    computation C_BB_H_update_i("C_BB_H_update_i", {t, x_out, x_in, rp, m, r, nH}, C_init_i(t, x_out, x_in, rp, m, r, Nsnk+nH) + BB_H_term.get_imag()); 

    // H_BB
    computation C_H_BB_prop_init_r("C_H_BB_prop_init_r", {t, y_out, y_in, rp, n, r}, expr((double) 0));
    computation C_H_BB_prop_init_i("C_H_BB_prop_init_i", {t, y_out, y_in, rp, n, r}, expr((double) 0));
    
    complex_computation H_BB_new_term_0_r1_b1("H_BB_new_term_0_r1_b1", {t, y_out, y_in, rp, n, r, s, nperm, wnumHex}, snk_B1_Blocal_r1_init(t, y_out, y_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 0), hex_snk_spin_weights(r, nperm, wnumHex, 0, 0), hex_snk_color_weights(r, nperm, wnumHex, 2, 0), hex_snk_spin_weights(r, nperm, wnumHex, 2, 0), hex_snk_color_weights(r, nperm, wnumHex, 1, 0), hex_snk_spin_weights(r, nperm, wnumHex, 1, 0), n));
    H_BB_new_term_0_r1_b1.add_predicate((src_spins(rp, s, 0) == 1));
    complex_computation H_BB_new_term_0_r2_b1("H_BB_new_term_0_r2_b1", {t, y_out, y_in, rp, n, r, s, nperm, wnumHex}, snk_B1_Blocal_r2_init(t, y_out, y_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 0), hex_snk_spin_weights(r, nperm, wnumHex, 0, 0), hex_snk_color_weights(r, nperm, wnumHex, 2, 0), hex_snk_spin_weights(r, nperm, wnumHex, 2, 0), hex_snk_color_weights(r, nperm, wnumHex, 1, 0), hex_snk_spin_weights(r, nperm, wnumHex, 1, 0), n));
    H_BB_new_term_0_r2_b1.add_predicate((src_spins(rp, s, 0) == 2));

    complex_computation H_BB_new_term_0_r1_b2("H_BB_new_term_0_r1_b2", {t, y_out, y_in, rp, n, r, s, nperm, wnumHex}, snk_B2_Blocal_r1_init(t, y_out, y_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 1), hex_snk_spin_weights(r, nperm, wnumHex, 0, 1), hex_snk_color_weights(r, nperm, wnumHex, 2, 1), hex_snk_spin_weights(r, nperm, wnumHex, 2, 1), hex_snk_color_weights(r, nperm, wnumHex, 1, 1), hex_snk_spin_weights(r, nperm, wnumHex, 1, 1), n));
    H_BB_new_term_0_r1_b2.add_predicate((src_spins(rp, s, 1) == 1));
    complex_computation H_BB_new_term_0_r2_b2("H_BB_new_term_0_r2_b2", {t, y_out, y_in, rp, n, r, s, nperm, wnumHex}, snk_B2_Blocal_r2_init(t, y_out, y_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 1), hex_snk_spin_weights(r, nperm, wnumHex, 0, 1), hex_snk_color_weights(r, nperm, wnumHex, 2, 1), hex_snk_spin_weights(r, nperm, wnumHex, 2, 1), hex_snk_color_weights(r, nperm, wnumHex, 1, 1), hex_snk_spin_weights(r, nperm, wnumHex, 1, 1), n));
    H_BB_new_term_0_r2_b2.add_predicate((src_spins(rp, s, 1) == 2));

    complex_expr H_BB_term_res_b1 = H_BB_new_term_0_r1_b1(t, y_out, y_in, rp, n, r, s, nperm, wnumHex);
    complex_expr H_BB_term_res_b2 = H_BB_new_term_0_r1_b2(t, y_out, y_in, rp, n, r, s, nperm, wnumHex);

    complex_expr snk_hex_prefactor(cast(p_float64, sigs(nperm)) * hex_snk_weights(r, wnumHex) * src_spin_block_weights(rp, s), 0.0);

    complex_expr H_BB_term_res = snk_hex_prefactor * H_BB_term_res_b1 * H_BB_term_res_b2;

    complex_computation H_BB_term_res_comp( "H_BB_term_res_comp", { t, y_out, y_in, rp, n, r, s, nperm, wnumHex }, H_BB_term_res );

    complex_computation flip_H_BB_new_term_0_r1_b1("flip_H_BB_new_term_0_r1_b1", {t, y_out, y_in, rp, n, r, s, nperm, wnumHex}, flip_snk_B1_Blocal_r1_init(t, y_out, y_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 0), hex_snk_spin_weights(r, nperm, wnumHex, 0, 0), hex_snk_color_weights(r, nperm, wnumHex, 2, 0), hex_snk_spin_weights(r, nperm, wnumHex, 2, 0), hex_snk_color_weights(r, nperm, wnumHex, 1, 0), hex_snk_spin_weights(r, nperm, wnumHex, 1, 0), n));
    flip_H_BB_new_term_0_r1_b1.add_predicate((src_spins(rp, s, 0) == 1));
    complex_computation flip_H_BB_new_term_0_r2_b1("flip_H_BB_new_term_0_r2_b1", {t, y_out, y_in, rp, n, r, s, nperm, wnumHex}, flip_snk_B1_Blocal_r2_init(t, y_out, y_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 0), hex_snk_spin_weights(r, nperm, wnumHex, 0, 0), hex_snk_color_weights(r, nperm, wnumHex, 2, 0), hex_snk_spin_weights(r, nperm, wnumHex, 2, 0), hex_snk_color_weights(r, nperm, wnumHex, 1, 0), hex_snk_spin_weights(r, nperm, wnumHex, 1, 0), n));
    flip_H_BB_new_term_0_r2_b1.add_predicate((src_spins(rp, s, 0) == 2));

    complex_computation flip_H_BB_new_term_0_r1_b2("flip_H_BB_new_term_0_r1_b2", {t, y_out, y_in, rp, n, r, s, nperm, wnumHex}, flip_snk_B2_Blocal_r1_init(t, y_out, y_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 1), hex_snk_spin_weights(r, nperm, wnumHex, 0, 1), hex_snk_color_weights(r, nperm, wnumHex, 2, 1), hex_snk_spin_weights(r, nperm, wnumHex, 2, 1), hex_snk_color_weights(r, nperm, wnumHex, 1, 1), hex_snk_spin_weights(r, nperm, wnumHex, 1, 1), n));
    flip_H_BB_new_term_0_r1_b2.add_predicate((src_spins(rp, s, 1) == 1));
    complex_computation flip_H_BB_new_term_0_r2_b2("flip_H_BB_new_term_0_r2_b2", {t, y_out, y_in, rp, n, r, s, nperm, wnumHex}, flip_snk_B2_Blocal_r2_init(t, y_out, y_in, hex_snk_color_weights(r, nperm, wnumHex, 0, 1), hex_snk_spin_weights(r, nperm, wnumHex, 0, 1), hex_snk_color_weights(r, nperm, wnumHex, 2, 1), hex_snk_spin_weights(r, nperm, wnumHex, 2, 1), hex_snk_color_weights(r, nperm, wnumHex, 1, 1), hex_snk_spin_weights(r, nperm, wnumHex, 1, 1), n));
    flip_H_BB_new_term_0_r2_b2.add_predicate((src_spins(rp, s, 1) == 2));

    complex_expr flip_H_BB_term_res_b1 = flip_H_BB_new_term_0_r1_b1(t, y_out, y_in, rp, n, r, s, nperm, wnumHex);
    complex_expr flip_H_BB_term_res_b2 = flip_H_BB_new_term_0_r1_b2(t, y_out, y_in, rp, n, r, s, nperm, wnumHex);

    complex_expr flip_H_BB_term_res = snk_hex_prefactor * flip_H_BB_term_res_b1 * flip_H_BB_term_res_b2;

    computation C_H_BB_prop_update_r("C_H_BB_prop_update_r", {t, y_out, y_in, rp, n, r, s, nperm, wnumHex}, C_H_BB_prop_init_r(t, y_out, y_in, rp, n, r) + ((*H_BB_term_res_comp.get_real())(t, y_out, y_in, rp, n, r, s, nperm, wnumHex) + flip_H_BB_term_res.get_real())/2.0 );
    computation C_H_BB_prop_update_i("C_H_BB_prop_update_i", {t, y_out, y_in, rp, n, r, s, nperm, wnumHex}, C_H_BB_prop_init_i(t, y_out, y_in, rp, n, r) + ((*H_BB_term_res_comp.get_imag())(t, y_out, y_in, rp, n, r, s, nperm, wnumHex) + flip_H_BB_term_res.get_imag())/2.0 );

    complex_computation C_H_BB_prop_update(&C_H_BB_prop_update_r, &C_H_BB_prop_update_i);

    complex_expr H_BB_term = hex_src_psi * C_H_BB_prop_update(t, y_out, y_in, rp, n, r, 1, Nperms-1, Nw2Hex-1);


    computation C_H_BB_update_r("C_H_BB_update_r", {t, y_out, y_in, rp, n, r, mH}, C_init_r(t, y_out, y_in, rp, Nsrc+mH, r, n) + H_BB_term.get_real());
    computation C_H_BB_update_i("C_H_BB_update_i", {t, y_out, y_in, rp, n, r, mH}, C_init_i(t, y_out, y_in, rp, Nsrc+mH, r, n) + H_BB_term.get_imag());  


    // H_H
    computation C_H_H_prop_init_r("C_H_H_prop_init_r", {t, x_out, x_in, rp, r, y}, expr((double) 0));
    computation C_H_H_prop_init_i("C_H_H_prop_init_i", {t, x_out, x_in, rp, r, y}, expr((double) 0));


    complex_expr H_H_B1_prop_0 =  B1_prop(0, t, hex_snk_color_weights(r,nperm,wnumHex,0,0), hex_snk_spin_weights(r,nperm,wnumHex,0,0), hex_snk_color_weights(rp,0,wnumHexHex,0,0), hex_snk_spin_weights(rp,0,wnumHexHex,0,0), x_out*sites_per_rank+x_in, y);
    complex_expr H_H_B1_prop_2 =  B1_prop(2, t, hex_snk_color_weights(r,nperm,wnumHex,2,0), hex_snk_spin_weights(r,nperm,wnumHex,2,0), hex_snk_color_weights(rp,0,wnumHexHex,2,0), hex_snk_spin_weights(rp,0,wnumHexHex,2,0), x_out*sites_per_rank+x_in, y);
    complex_expr H_H_B1_prop_1 = B1_prop(1, t, hex_snk_color_weights(r,nperm,wnumHex,1,0), hex_snk_spin_weights(r,nperm,wnumHex,1,0), hex_snk_color_weights(rp,0,wnumHexHex,1,0), hex_snk_spin_weights(rp,0,wnumHexHex,1,0), x_out*sites_per_rank+x_in, y);
    complex_expr B1_H = H_H_B1_prop_0 * H_H_B1_prop_2 * H_H_B1_prop_1;

    complex_expr H_H_B2_prop_0 =  B2_prop(0, t, hex_snk_color_weights(r,nperm,wnumHex,0,1), hex_snk_spin_weights(r,nperm,wnumHex,0,1), hex_snk_color_weights(rp,0,wnumHexHex,0,1), hex_snk_spin_weights(rp,0,wnumHexHex,0,1), x_out*sites_per_rank+x_in, y);
    complex_expr H_H_B2_prop_2 =  B2_prop(2, t, hex_snk_color_weights(r,nperm,wnumHex,2,1), hex_snk_spin_weights(r,nperm,wnumHex,2,1), hex_snk_color_weights(rp,0,wnumHexHex,2,1), hex_snk_spin_weights(rp,0,wnumHexHex,2,1), x_out*sites_per_rank+x_in, y);
    complex_expr H_H_B2_prop_1 = B2_prop(1, t, hex_snk_color_weights(r,nperm,wnumHex,1,1), hex_snk_spin_weights(r,nperm,wnumHex,1,1), hex_snk_color_weights(rp,0,wnumHexHex,1,1), hex_snk_spin_weights(rp,0,wnumHexHex,1,1), x_out*sites_per_rank+x_in, y);
    complex_expr B2_H = H_H_B2_prop_0 * H_H_B2_prop_2 * H_H_B2_prop_1;

    complex_expr hex_hex_prefactor(cast(p_float64, sigs(nperm)) * hex_snk_weights(r, wnumHex) * hex_snk_weights(rp, wnumHexHex), 0.0);

    complex_expr H_H_term_res = hex_hex_prefactor * B1_H * B2_H;

    computation C_H_H_prop_update_r("C_H_H_prop_update_r", {t, x_out, x_in, rp, r, y, nperm, wnumHex, wnumHexHex}, C_H_H_prop_init_r(t, x_out, x_in, rp, r, y) + H_H_term_res.get_real());
    computation C_H_H_prop_update_i("C_H_H_prop_update_i", {t, x_out, x_in, rp, r, y, nperm, wnumHex, wnumHexHex}, C_H_H_prop_init_i(t, x_out, x_in, rp, r, y) + H_H_term_res.get_imag());

    complex_computation C_H_H_prop_update(&C_H_H_prop_update_r, &C_H_H_prop_update_i); 

    complex_expr H_H_term = hex_hex_src_psi * hex_snk_psi * C_H_H_prop_update(t, x_out, x_in, rp, r, y, Nperms-1, Nw2Hex-1, Nw2Hex-1);

    computation C_H_H_update_r("C_H_H_update_r", {t, x_out, x_in, rp, r, y, mH, nH}, C_init_r(t, x_out, x_in, rp, Nsrc+mH, r, Nsnk+nH) + H_H_term.get_real());
    computation C_H_H_update_i("C_H_H_update_i", {t, x_out, x_in, rp, r, y, mH, nH}, C_init_i(t, x_out, x_in, rp, Nsrc+mH, r, Nsnk+nH) + H_H_term.get_imag());

    // -------------------------------------------------------
    // Layer III
    // -------------------------------------------------------

    buffer buf_B1_Blocal_r1_r("buf_B1_Blocal_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Blocal_r1_i("buf_B1_Blocal_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_r1_r("buf_B1_Bfirst_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_r1_i("buf_B1_Bfirst_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bsecond_r1_r("buf_B1_Bsecond_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bsecond_r1_i("buf_B1_Bsecond_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bthird_r1_r("buf_B1_Bthird_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bthird_r1_i("buf_B1_Bthird_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buf_B1_Blocal_r1_r.tag_gpu_global();
    buf_B1_Blocal_r1_i.tag_gpu_global();
    buf_B1_Bfirst_r1_r.tag_gpu_global();
    buf_B1_Bfirst_r1_i.tag_gpu_global();
    buf_B1_Bsecond_r1_r.tag_gpu_global();
    buf_B1_Bsecond_r1_i.tag_gpu_global();
    buf_B1_Bthird_r1_r.tag_gpu_global();
    buf_B1_Bthird_r1_i.tag_gpu_global();
    B1_Blocal_r1_r_init.store_in(&buf_B1_Blocal_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Blocal_r1_i_init.store_in(&buf_B1_Blocal_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bfirst_r1_r_init.store_in(&buf_B1_Bfirst_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bfirst_r1_i_init.store_in(&buf_B1_Bfirst_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bsecond_r1_r_init.store_in(&buf_B1_Bsecond_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bsecond_r1_i_init.store_in(&buf_B1_Bsecond_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bthird_r1_r_init.store_in(&buf_B1_Bthird_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bthird_r1_i_init.store_in(&buf_B1_Bthird_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Blocal_r1_r_update.store_in(&buf_B1_Blocal_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Blocal_r1_i_update.store_in(&buf_B1_Blocal_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bfirst_r1_r_update.store_in(&buf_B1_Bfirst_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bfirst_r1_i_update.store_in(&buf_B1_Bfirst_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bsecond_r1_r_update.store_in(&buf_B1_Bsecond_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bsecond_r1_i_update.store_in(&buf_B1_Bsecond_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bthird_r1_r_update.store_in(&buf_B1_Bthird_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bthird_r1_i_update.store_in(&buf_B1_Bthird_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    // computation *allocate_buf_B1_Blocal_r1_r = buf_B1_Blocal_r1_r.allocate_at( B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_B1_Blocal_r1_i = buf_B1_Blocal_r1_i.allocate_at( B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_B1_Bfirst_r1_r = buf_B1_Bfirst_r1_r.allocate_at( B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_B1_Bfirst_r1_i = buf_B1_Bfirst_r1_i.allocate_at( B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_B1_Bsecond_r1_r = buf_B1_Bsecond_r1_r.allocate_at( B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_B1_Bsecond_r1_i = buf_B1_Bsecond_r1_i.allocate_at( B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_B1_Bthird_r1_r = buf_B1_Bthird_r1_r.allocate_at( B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_B1_Bthird_r1_i = buf_B1_Bthird_r1_i.allocate_at( B1_Blocal_r1_r_init, t );

    // computation *deallocate_buf_B1_Blocal_r1_r = buf_B1_Blocal_r1_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Blocal_r1_i = buf_B1_Blocal_r1_i.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bfirst_r1_r = buf_B1_Bfirst_r1_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bfirst_r1_i = buf_B1_Bfirst_r1_i.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bsecond_r1_r = buf_B1_Bsecond_r1_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bsecond_r1_i = buf_B1_Bsecond_r1_i.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bthird_r1_r = buf_B1_Bthird_r1_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bthird_r1_i = buf_B1_Bthird_r1_i.deallocate_at( C_BB_BB_prop_update_i, t );

    buffer buf_flip_B1_Blocal_r1_r("buf_flip_B1_Blocal_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Blocal_r1_i("buf_flip_B1_Blocal_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bfirst_r1_r("buf_flip_B1_Bfirst_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bfirst_r1_i("buf_flip_B1_Bfirst_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bsecond_r1_r("buf_flip_B1_Bsecond_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bsecond_r1_i("buf_flip_B1_Bsecond_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bthird_r1_r("buf_flip_B1_Bthird_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bthird_r1_i("buf_flip_B1_Bthird_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buf_flip_B1_Blocal_r1_r.tag_gpu_global();
    buf_flip_B1_Blocal_r1_i.tag_gpu_global();
    buf_flip_B1_Bfirst_r1_r.tag_gpu_global();
    buf_flip_B1_Bfirst_r1_i.tag_gpu_global();
    buf_flip_B1_Bsecond_r1_r.tag_gpu_global();
    buf_flip_B1_Bsecond_r1_i.tag_gpu_global();
    buf_flip_B1_Bthird_r1_r.tag_gpu_global();
    buf_flip_B1_Bthird_r1_i.tag_gpu_global();
    flip_B1_Blocal_r1_r_init.store_in(&buf_flip_B1_Blocal_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Blocal_r1_i_init.store_in(&buf_flip_B1_Blocal_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bfirst_r1_r_init.store_in(&buf_flip_B1_Bfirst_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bfirst_r1_i_init.store_in(&buf_flip_B1_Bfirst_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bsecond_r1_r_init.store_in(&buf_flip_B1_Bsecond_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bsecond_r1_i_init.store_in(&buf_flip_B1_Bsecond_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bthird_r1_r_init.store_in(&buf_flip_B1_Bthird_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bthird_r1_i_init.store_in(&buf_flip_B1_Bthird_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Blocal_r1_r_update.store_in(&buf_flip_B1_Blocal_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Blocal_r1_i_update.store_in(&buf_flip_B1_Blocal_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bfirst_r1_r_update.store_in(&buf_flip_B1_Bfirst_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bfirst_r1_i_update.store_in(&buf_flip_B1_Bfirst_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2}); 
    flip_B1_Bsecond_r1_r_update.store_in(&buf_flip_B1_Bsecond_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bsecond_r1_i_update.store_in(&buf_flip_B1_Bsecond_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bthird_r1_r_update.store_in(&buf_flip_B1_Bthird_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bthird_r1_i_update.store_in(&buf_flip_B1_Bthird_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2}); 

    // computation *allocate_buf_flip_B1_Blocal_r1_r = buf_flip_B1_Blocal_r1_r.allocate_at( flip_B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B1_Blocal_r1_i = buf_flip_B1_Blocal_r1_i.allocate_at( flip_B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B1_Bfirst_r1_r = buf_flip_B1_Bfirst_r1_r.allocate_at( flip_B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B1_Bfirst_r1_i = buf_flip_B1_Bfirst_r1_i.allocate_at( flip_B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B1_Bsecond_r1_r = buf_flip_B1_Bsecond_r1_r.allocate_at( flip_B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B1_Bsecond_r1_i = buf_flip_B1_Bsecond_r1_i.allocate_at( flip_B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B1_Bthird_r1_r = buf_flip_B1_Bthird_r1_r.allocate_at( flip_B1_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B1_Bthird_r1_i = buf_flip_B1_Bthird_r1_i.allocate_at( flip_B1_Blocal_r1_r_init, t );

    // computation *deallocate_buf_flip_B1_Blocal_r1_r = buf_flip_B1_Blocal_r1_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Blocal_r1_i = buf_flip_B1_Blocal_r1_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bfirst_r1_r = buf_flip_B1_Bfirst_r1_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bfirst_r1_i = buf_flip_B1_Bfirst_r1_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bsecond_r1_r = buf_flip_B1_Bsecond_r1_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bsecond_r1_i = buf_flip_B1_Bsecond_r1_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bthird_r1_r = buf_flip_B1_Bthird_r1_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bthird_r1_i = buf_flip_B1_Bthird_r1_i.deallocate_at( C_BB_BB_prop_update_i_2, t );

    buffer buf_B1_Blocal_diquark_r1_r("buf_B1_Blocal_diquark_r1_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B1_Blocal_diquark_r1_i("buf_B1_Blocal_diquark_r1_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_diquark_r1_r("buf_B1_Bfirst_diquark_r1_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_diquark_r1_i("buf_B1_Bfirst_diquark_r1_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B1_Bthird_diquark_r1_r("buf_B1_Bthird_diquark_r1_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B1_Bthird_diquark_r1_i("buf_B1_Bthird_diquark_r1_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buf_B1_Blocal_diquark_r1_r.tag_gpu_global();
    buf_B1_Blocal_diquark_r1_i.tag_gpu_global();
    buf_B1_Bfirst_diquark_r1_r.tag_gpu_global();
    buf_B1_Bfirst_diquark_r1_i.tag_gpu_global();
    buf_B1_Bthird_diquark_r1_r.tag_gpu_global();
    buf_B1_Bthird_diquark_r1_i.tag_gpu_global();
    B1_Blocal_r1_r_diquark.store_in(&buf_B1_Blocal_diquark_r1_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B1_Blocal_r1_i_diquark.store_in(&buf_B1_Blocal_diquark_r1_i, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B1_Bfirst_r1_r_diquark.store_in(&buf_B1_Bfirst_diquark_r1_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B1_Bfirst_r1_i_diquark.store_in(&buf_B1_Bfirst_diquark_r1_i, {x1, x2, iCprime, iSprime, kCprime, kSprime}); 
    B1_Bthird_r1_r_diquark.store_in(&buf_B1_Bthird_diquark_r1_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B1_Bthird_r1_i_diquark.store_in(&buf_B1_Bthird_diquark_r1_i, {x1, x2, iCprime, iSprime, kCprime, kSprime}); 
    buffer buf_B1_Blocal_props_r1_r("buf_B1_Blocal_props_r1_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Blocal_props_r1_i("buf_B1_Blocal_props_r1_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_props_r1_r("buf_B1_Bfirst_props_r1_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_props_r1_i("buf_B1_Bfirst_props_r1_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bsecond_props_r1_r("buf_B1_Bsecond_props_r1_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bsecond_props_r1_i("buf_B1_Bsecond_props_r1_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bthird_props_r1_r("buf_B1_Bthird_props_r1_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bthird_props_r1_i("buf_B1_Bthird_props_r1_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buf_B1_Blocal_props_r1_r.tag_gpu_global();
    buf_B1_Blocal_props_r1_i.tag_gpu_global();
    buf_B1_Bfirst_props_r1_r.tag_gpu_global();
    buf_B1_Bfirst_props_r1_i.tag_gpu_global();
    buf_B1_Bsecond_props_r1_r.tag_gpu_global();
    buf_B1_Bsecond_props_r1_i.tag_gpu_global();
    buf_B1_Bthird_props_r1_r.tag_gpu_global();
    buf_B1_Bthird_props_r1_i.tag_gpu_global();
    B1_Blocal_r1_r_props_init.store_in(&buf_B1_Blocal_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Blocal_r1_i_props_init.store_in(&buf_B1_Blocal_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bfirst_r1_r_props_init.store_in(&buf_B1_Bfirst_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bfirst_r1_i_props_init.store_in(&buf_B1_Bfirst_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bsecond_r1_r_props_init.store_in(&buf_B1_Bsecond_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bsecond_r1_i_props_init.store_in(&buf_B1_Bsecond_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bthird_r1_r_props_init.store_in(&buf_B1_Bthird_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bthird_r1_i_props_init.store_in(&buf_B1_Bthird_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Blocal_r1_r_props.store_in(&buf_B1_Blocal_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Blocal_r1_i_props.store_in(&buf_B1_Blocal_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bfirst_r1_r_props.store_in(&buf_B1_Bfirst_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bfirst_r1_i_props.store_in(&buf_B1_Bfirst_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2}); 
    B1_Bsecond_r1_r_props.store_in(&buf_B1_Bsecond_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bsecond_r1_i_props.store_in(&buf_B1_Bsecond_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bthird_r1_r_props.store_in(&buf_B1_Bthird_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bthird_r1_i_props.store_in(&buf_B1_Bthird_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2}); 

    computation *allocate_buf_B1_Blocal_props_r1_r = buf_B1_Blocal_props_r1_r.allocate_at( B1_Blocal_r1_r_props_init, t );
    computation *allocate_buf_B1_Blocal_props_r1_i = buf_B1_Blocal_props_r1_i.allocate_at( B1_Blocal_r1_r_props_init, t );
    computation *allocate_buf_B1_Bfirst_props_r1_r = buf_B1_Bfirst_props_r1_r.allocate_at( B1_Blocal_r1_r_props_init, t );
    computation *allocate_buf_B1_Bfirst_props_r1_i = buf_B1_Bfirst_props_r1_i.allocate_at( B1_Blocal_r1_r_props_init, t );
    computation *allocate_buf_B1_Bsecond_props_r1_r = buf_B1_Bsecond_props_r1_r.allocate_at( B1_Blocal_r1_r_props_init, t );
    computation *allocate_buf_B1_Bsecond_props_r1_i = buf_B1_Bsecond_props_r1_i.allocate_at( B1_Blocal_r1_r_props_init, t );
    computation *allocate_buf_B1_Bthird_props_r1_r = buf_B1_Bthird_props_r1_r.allocate_at( B1_Blocal_r1_r_props_init, t );
    computation *allocate_buf_B1_Bthird_props_r1_i = buf_B1_Bthird_props_r1_i.allocate_at( B1_Blocal_r1_r_props_init, t );

    computation *deallocate_buf_B1_Blocal_props_r1_r = buf_B1_Blocal_props_r1_r.deallocate_at( flip_B1_Bthird_r1_i_update, t );
    computation *deallocate_buf_B1_Blocal_props_r1_i = buf_B1_Blocal_props_r1_i.deallocate_at( flip_B1_Bthird_r1_i_update, t );
    computation *deallocate_buf_B1_Bfirst_props_r1_r = buf_B1_Bfirst_props_r1_r.deallocate_at( flip_B1_Bthird_r1_i_update, t );
    computation *deallocate_buf_B1_Bfirst_props_r1_i = buf_B1_Bfirst_props_r1_i.deallocate_at( flip_B1_Bthird_r1_i_update, t );
    computation *deallocate_buf_B1_Bsecond_props_r1_r = buf_B1_Bsecond_props_r1_r.deallocate_at( flip_B1_Bthird_r1_i_update, t );
    computation *deallocate_buf_B1_Bsecond_props_r1_i = buf_B1_Bsecond_props_r1_i.deallocate_at( flip_B1_Bthird_r1_i_update, t );
    computation *deallocate_buf_B1_Bthird_props_r1_r = buf_B1_Bthird_props_r1_r.deallocate_at( flip_B1_Bthird_r1_i_update, t );
    computation *deallocate_buf_B1_Bthird_props_r1_i = buf_B1_Bthird_props_r1_i.deallocate_at( flip_B1_Bthird_r1_i_update, t );

    buffer buf_B1_Blocal_r2_r("buf_B1_Blocal_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Blocal_r2_i("buf_B1_Blocal_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_r2_r("buf_B1_Bfirst_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_r2_i("buf_B1_Bfirst_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bsecond_r2_r("buf_B1_Bsecond_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bsecond_r2_i("buf_B1_Bsecond_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bthird_r2_r("buf_B1_Bthird_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bthird_r2_i("buf_B1_Bthird_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buf_B1_Blocal_r2_r.tag_gpu_global();
    buf_B1_Blocal_r2_i.tag_gpu_global();
    buf_B1_Bfirst_r2_r.tag_gpu_global();
    buf_B1_Bfirst_r2_i.tag_gpu_global();
    buf_B1_Bsecond_r2_r.tag_gpu_global();
    buf_B1_Bsecond_r2_i.tag_gpu_global();
    buf_B1_Bthird_r2_r.tag_gpu_global();
    buf_B1_Bthird_r2_i.tag_gpu_global();
    B1_Blocal_r2_r_init.store_in(&buf_B1_Blocal_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Blocal_r2_i_init.store_in(&buf_B1_Blocal_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bfirst_r2_r_init.store_in(&buf_B1_Bfirst_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bfirst_r2_i_init.store_in(&buf_B1_Bfirst_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bsecond_r2_r_init.store_in(&buf_B1_Bsecond_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bsecond_r2_i_init.store_in(&buf_B1_Bsecond_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bthird_r2_r_init.store_in(&buf_B1_Bthird_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bthird_r2_i_init.store_in(&buf_B1_Bthird_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Blocal_r2_r_update.store_in(&buf_B1_Blocal_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Blocal_r2_i_update.store_in(&buf_B1_Blocal_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bfirst_r2_r_update.store_in(&buf_B1_Bfirst_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bfirst_r2_i_update.store_in(&buf_B1_Bfirst_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bsecond_r2_r_update.store_in(&buf_B1_Bsecond_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bsecond_r2_i_update.store_in(&buf_B1_Bsecond_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bthird_r2_r_update.store_in(&buf_B1_Bthird_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B1_Bthird_r2_i_update.store_in(&buf_B1_Bthird_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});

    // computation *allocate_buf_B1_Blocal_r2_r = buf_B1_Blocal_r2_r.allocate_at( B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_B1_Blocal_r2_i = buf_B1_Blocal_r2_i.allocate_at( B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_B1_Bfirst_r2_r = buf_B1_Bfirst_r2_r.allocate_at( B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_B1_Bfirst_r2_i = buf_B1_Bfirst_r2_i.allocate_at( B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_B1_Bsecond_r2_r = buf_B1_Bsecond_r2_r.allocate_at( B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_B1_Bsecond_r2_i = buf_B1_Bsecond_r2_i.allocate_at( B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_B1_Bthird_r2_r = buf_B1_Bthird_r2_r.allocate_at( B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_B1_Bthird_r2_i = buf_B1_Bthird_r2_i.allocate_at( B1_Blocal_r2_r_init, t );

    // computation *deallocate_buf_B1_Blocal_r2_r = buf_B1_Blocal_r2_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Blocal_r2_i = buf_B1_Blocal_r2_i.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bfirst_r2_r = buf_B1_Bfirst_r2_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bfirst_r2_i = buf_B1_Bfirst_r2_i.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bsecond_r2_r = buf_B1_Bsecond_r2_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bsecond_r2_i = buf_B1_Bsecond_r2_i.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bthird_r2_r = buf_B1_Bthird_r2_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation *deallocate_buf_B1_Bthird_r2_i = buf_B1_Bthird_r2_i.deallocate_at( C_BB_BB_prop_update_i, t );

    buffer buf_flip_B1_Blocal_r2_r("buf_flip_B1_Blocal_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Blocal_r2_i("buf_flip_B1_Blocal_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bfirst_r2_r("buf_flip_B1_Bfirst_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bfirst_r2_i("buf_flip_B1_Bfirst_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bsecond_r2_r("buf_flip_B1_Bsecond_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bsecond_r2_i("buf_flip_B1_Bsecond_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bthird_r2_r("buf_flip_B1_Bthird_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B1_Bthird_r2_i("buf_flip_B1_Bthird_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buf_flip_B1_Blocal_r2_r.tag_gpu_global();
    buf_flip_B1_Blocal_r2_i.tag_gpu_global();
    buf_flip_B1_Bfirst_r2_r.tag_gpu_global();
    buf_flip_B1_Bfirst_r2_i.tag_gpu_global();
    buf_flip_B1_Bsecond_r2_r.tag_gpu_global();
    buf_flip_B1_Bsecond_r2_i.tag_gpu_global();
    buf_flip_B1_Bthird_r2_r.tag_gpu_global();
    buf_flip_B1_Bthird_r2_i.tag_gpu_global();
    flip_B1_Blocal_r2_r_init.store_in(&buf_flip_B1_Blocal_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Blocal_r2_i_init.store_in(&buf_flip_B1_Blocal_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bfirst_r2_r_init.store_in(&buf_flip_B1_Bfirst_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bfirst_r2_i_init.store_in(&buf_flip_B1_Bfirst_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bsecond_r2_r_init.store_in(&buf_flip_B1_Bsecond_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bsecond_r2_i_init.store_in(&buf_flip_B1_Bsecond_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bthird_r2_r_init.store_in(&buf_flip_B1_Bthird_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bthird_r2_i_init.store_in(&buf_flip_B1_Bthird_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Blocal_r2_r_update.store_in(&buf_flip_B1_Blocal_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Blocal_r2_i_update.store_in(&buf_flip_B1_Blocal_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bfirst_r2_r_update.store_in(&buf_flip_B1_Bfirst_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bfirst_r2_i_update.store_in(&buf_flip_B1_Bfirst_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2}); 
    flip_B1_Bsecond_r2_r_update.store_in(&buf_flip_B1_Bsecond_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bsecond_r2_i_update.store_in(&buf_flip_B1_Bsecond_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bthird_r2_r_update.store_in(&buf_flip_B1_Bthird_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B1_Bthird_r2_i_update.store_in(&buf_flip_B1_Bthird_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2}); 

    // computation *allocate_buf_flip_B1_Blocal_r2_r = buf_flip_B1_Blocal_r2_r.allocate_at( flip_B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B1_Blocal_r2_i = buf_flip_B1_Blocal_r2_i.allocate_at( flip_B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B1_Bfirst_r2_r = buf_flip_B1_Bfirst_r2_r.allocate_at( flip_B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B1_Bfirst_r2_i = buf_flip_B1_Bfirst_r2_i.allocate_at( flip_B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B1_Bsecond_r2_r = buf_flip_B1_Bsecond_r2_r.allocate_at( flip_B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B1_Bsecond_r2_i = buf_flip_B1_Bsecond_r2_i.allocate_at( flip_B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B1_Bthird_r2_r = buf_flip_B1_Bthird_r2_r.allocate_at( flip_B1_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B1_Bthird_r2_i = buf_flip_B1_Bthird_r2_i.allocate_at( flip_B1_Blocal_r2_r_init, t );

    // computation *deallocate_buf_flip_B1_Blocal_r2_r = buf_flip_B1_Blocal_r2_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Blocal_r2_i = buf_flip_B1_Blocal_r2_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bfirst_r2_r = buf_flip_B1_Bfirst_r2_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bfirst_r2_i = buf_flip_B1_Bfirst_r2_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bsecond_r2_r = buf_flip_B1_Bsecond_r2_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bsecond_r2_i = buf_flip_B1_Bsecond_r2_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bthird_r2_r = buf_flip_B1_Bthird_r2_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B1_Bthird_r2_i = buf_flip_B1_Bthird_r2_i.deallocate_at( C_BB_BB_prop_update_i_2, t );

    buffer buf_B1_Blocal_diquark_r2_r("buf_B1_Blocal_diquark_r2_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B1_Blocal_diquark_r2_i("buf_B1_Blocal_diquark_r2_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_diquark_r2_r("buf_B1_Bfirst_diquark_r2_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_diquark_r2_i("buf_B1_Bfirst_diquark_r2_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B1_Bthird_diquark_r2_r("buf_B1_Bthird_diquark_r2_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B1_Bthird_diquark_r2_i("buf_B1_Bthird_diquark_r2_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buf_B1_Blocal_diquark_r2_r.tag_gpu_global();
    buf_B1_Blocal_diquark_r2_i.tag_gpu_global();
    buf_B1_Bfirst_diquark_r2_r.tag_gpu_global();
    buf_B1_Bfirst_diquark_r2_i.tag_gpu_global();
    buf_B1_Bthird_diquark_r2_r.tag_gpu_global();
    buf_B1_Bthird_diquark_r2_i.tag_gpu_global();
    B1_Blocal_r2_r_diquark.store_in(&buf_B1_Blocal_diquark_r2_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B1_Blocal_r2_i_diquark.store_in(&buf_B1_Blocal_diquark_r2_i, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B1_Bfirst_r2_r_diquark.store_in(&buf_B1_Bfirst_diquark_r2_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B1_Bfirst_r2_i_diquark.store_in(&buf_B1_Bfirst_diquark_r2_i, {x1, x2, iCprime, iSprime, kCprime, kSprime}); 
    B1_Bthird_r2_r_diquark.store_in(&buf_B1_Bthird_diquark_r2_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B1_Bthird_r2_i_diquark.store_in(&buf_B1_Bthird_diquark_r2_i, {x1, x2, iCprime, iSprime, kCprime, kSprime}); 
    buffer buf_B1_Blocal_props_r2_r("buf_B1_Blocal_props_r2_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Blocal_props_r2_i("buf_B1_Blocal_props_r2_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_props_r2_r("buf_B1_Bfirst_props_r2_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bfirst_props_r2_i("buf_B1_Bfirst_props_r2_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bsecond_props_r2_r("buf_B1_Bsecond_props_r2_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bsecond_props_r2_i("buf_B1_Bsecond_props_r2_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bthird_props_r2_r("buf_B1_Bthird_props_r2_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B1_Bthird_props_r2_i("buf_B1_Bthird_props_r2_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buf_B1_Blocal_props_r2_r.tag_gpu_global();
    buf_B1_Blocal_props_r2_i.tag_gpu_global();
    buf_B1_Bfirst_props_r2_r.tag_gpu_global();
    buf_B1_Bfirst_props_r2_i.tag_gpu_global();
    buf_B1_Bsecond_props_r2_r.tag_gpu_global();
    buf_B1_Bsecond_props_r2_i.tag_gpu_global();
    buf_B1_Bthird_props_r2_r.tag_gpu_global();
    buf_B1_Bthird_props_r2_i.tag_gpu_global();
    B1_Blocal_r2_r_props_init.store_in(&buf_B1_Blocal_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Blocal_r2_i_props_init.store_in(&buf_B1_Blocal_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bfirst_r2_r_props_init.store_in(&buf_B1_Bfirst_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bfirst_r2_i_props_init.store_in(&buf_B1_Bfirst_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bsecond_r2_r_props_init.store_in(&buf_B1_Bsecond_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bsecond_r2_i_props_init.store_in(&buf_B1_Bsecond_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bthird_r2_r_props_init.store_in(&buf_B1_Bthird_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bthird_r2_i_props_init.store_in(&buf_B1_Bthird_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Blocal_r2_r_props.store_in(&buf_B1_Blocal_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Blocal_r2_i_props.store_in(&buf_B1_Blocal_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bfirst_r2_r_props.store_in(&buf_B1_Bfirst_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bfirst_r2_i_props.store_in(&buf_B1_Bfirst_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2}); 
    B1_Bsecond_r2_r_props.store_in(&buf_B1_Bsecond_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bsecond_r2_i_props.store_in(&buf_B1_Bsecond_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bthird_r2_r_props.store_in(&buf_B1_Bthird_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B1_Bthird_r2_i_props.store_in(&buf_B1_Bthird_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2}); 
    
    computation *allocate_buf_B1_Blocal_props_r2_r = buf_B1_Blocal_props_r2_r.allocate_at( B1_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B1_Blocal_props_r2_i = buf_B1_Blocal_props_r2_i.allocate_at( B1_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B1_Bfirst_props_r2_r = buf_B1_Bfirst_props_r2_r.allocate_at( B1_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B1_Bfirst_props_r2_i = buf_B1_Bfirst_props_r2_i.allocate_at( B1_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B1_Bsecond_props_r2_r = buf_B1_Bsecond_props_r2_r.allocate_at( B1_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B1_Bsecond_props_r2_i = buf_B1_Bsecond_props_r2_i.allocate_at( B1_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B1_Bthird_props_r2_r = buf_B1_Bthird_props_r2_r.allocate_at( B1_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B1_Bthird_props_r2_i = buf_B1_Bthird_props_r2_i.allocate_at( B1_Blocal_r2_r_props_init, t );

    computation *deallocate_buf_B1_Blocal_props_r2_r = buf_B1_Blocal_props_r2_r.deallocate_at( flip_B1_Bthird_r2_i_update, t );
    computation *deallocate_buf_B1_Blocal_props_r2_i = buf_B1_Blocal_props_r2_i.deallocate_at( flip_B1_Bthird_r2_i_update, t );
    computation *deallocate_buf_B1_Bfirst_props_r2_r = buf_B1_Bfirst_props_r2_r.deallocate_at( flip_B1_Bthird_r2_i_update, t );
    computation *deallocate_buf_B1_Bfirst_props_r2_i = buf_B1_Bfirst_props_r2_i.deallocate_at( flip_B1_Bthird_r2_i_update, t );
    computation *deallocate_buf_B1_Bsecond_props_r2_r = buf_B1_Bsecond_props_r2_r.deallocate_at( flip_B1_Bthird_r2_i_update, t );
    computation *deallocate_buf_B1_Bsecond_props_r2_i = buf_B1_Bsecond_props_r2_i.deallocate_at( flip_B1_Bthird_r2_i_update, t );
    computation *deallocate_buf_B1_Bthird_props_r2_r = buf_B1_Bthird_props_r2_r.deallocate_at( flip_B1_Bthird_r2_i_update, t );
    computation *deallocate_buf_B1_Bthird_props_r2_i = buf_B1_Bthird_props_r2_i.deallocate_at( flip_B1_Bthird_r2_i_update, t );

    buffer buf_B2_Blocal_r1_r("buf_B2_Blocal_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Blocal_r1_i("buf_B2_Blocal_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_r1_r("buf_B2_Bfirst_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_r1_i("buf_B2_Bfirst_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bsecond_r1_r("buf_B2_Bsecond_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bsecond_r1_i("buf_B2_Bsecond_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bthird_r1_r("buf_B2_Bthird_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bthird_r1_i("buf_B2_Bthird_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buf_B2_Blocal_r1_r.tag_gpu_global();
    buf_B2_Blocal_r1_i.tag_gpu_global();
    buf_B2_Bfirst_r1_r.tag_gpu_global();
    buf_B2_Bfirst_r1_i.tag_gpu_global();
    buf_B2_Bsecond_r1_r.tag_gpu_global();
    buf_B2_Bsecond_r1_i.tag_gpu_global();
    buf_B2_Bthird_r1_r.tag_gpu_global();
    buf_B2_Bthird_r1_i.tag_gpu_global();
    B2_Blocal_r1_r_init.store_in(&buf_B2_Blocal_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Blocal_r1_i_init.store_in(&buf_B2_Blocal_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bfirst_r1_r_init.store_in(&buf_B2_Bfirst_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bfirst_r1_i_init.store_in(&buf_B2_Bfirst_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bsecond_r1_r_init.store_in(&buf_B2_Bsecond_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bsecond_r1_i_init.store_in(&buf_B2_Bsecond_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bthird_r1_r_init.store_in(&buf_B2_Bthird_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bthird_r1_i_init.store_in(&buf_B2_Bthird_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Blocal_r1_r_update.store_in(&buf_B2_Blocal_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Blocal_r1_i_update.store_in(&buf_B2_Blocal_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bfirst_r1_r_update.store_in(&buf_B2_Bfirst_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bfirst_r1_i_update.store_in(&buf_B2_Bfirst_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bsecond_r1_r_update.store_in(&buf_B2_Bsecond_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bsecond_r1_i_update.store_in(&buf_B2_Bsecond_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bthird_r1_r_update.store_in(&buf_B2_Bthird_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bthird_r1_i_update.store_in(&buf_B2_Bthird_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});

    // computation* allocate_buf_B2_Blocal_r1_r = buf_B2_Blocal_r1_r.allocate_at( B2_Blocal_r1_r_init, t );
    // computation* allocate_buf_B2_Blocal_r1_i = buf_B2_Blocal_r1_i.allocate_at( B2_Blocal_r1_r_init, t );
    // computation* allocate_buf_B2_Bfirst_r1_r = buf_B2_Bfirst_r1_r.allocate_at( B2_Blocal_r1_r_init, t );
    // computation* allocate_buf_B2_Bfirst_r1_i = buf_B2_Bfirst_r1_i.allocate_at( B2_Blocal_r1_r_init, t );
    // computation* allocate_buf_B2_Bsecond_r1_r = buf_B2_Bsecond_r1_r.allocate_at( B2_Blocal_r1_r_init, t );
    // computation* allocate_buf_B2_Bsecond_r1_i = buf_B2_Bsecond_r1_i.allocate_at( B2_Blocal_r1_r_init, t );
    // computation* allocate_buf_B2_Bthird_r1_r = buf_B2_Bthird_r1_r.allocate_at( B2_Blocal_r1_r_init, t );
    // computation* allocate_buf_B2_Bthird_r1_i = buf_B2_Bthird_r1_i.allocate_at( B2_Blocal_r1_r_init, t );

    // computation* deallocate_buf_B2_Blocal_r1_r = buf_B2_Blocal_r1_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation* deallocate_buf_B2_Blocal_r1_i = buf_B2_Blocal_r1_i.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation* deallocate_buf_B2_Bfirst_r1_r = buf_B2_Bfirst_r1_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation* deallocate_buf_B2_Bfirst_r1_i = buf_B2_Bfirst_r1_i.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation* deallocate_buf_B2_Bsecond_r1_r = buf_B2_Bsecond_r1_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation* deallocate_buf_B2_Bsecond_r1_i = buf_B2_Bsecond_r1_i.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation* deallocate_buf_B2_Bthird_r1_r = buf_B2_Bthird_r1_r.deallocate_at( C_BB_BB_prop_update_i, t );
    // computation* deallocate_buf_B2_Bthird_r1_i = buf_B2_Bthird_r1_i.deallocate_at( C_BB_BB_prop_update_i, t );

    buffer buf_flip_B2_Blocal_r1_r("buf_flip_B2_Blocal_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Blocal_r1_i("buf_flip_B2_Blocal_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bfirst_r1_r("buf_flip_B2_Bfirst_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bfirst_r1_i("buf_flip_B2_Bfirst_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bsecond_r1_r("buf_flip_B2_Bsecond_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bsecond_r1_i("buf_flip_B2_Bsecond_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bthird_r1_r("buf_flip_B2_Bthird_r1_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bthird_r1_i("buf_flip_B2_Bthird_r1_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buf_flip_B2_Blocal_r1_r.tag_gpu_global();
    buf_flip_B2_Blocal_r1_i.tag_gpu_global();
    buf_flip_B2_Bfirst_r1_r.tag_gpu_global();
    buf_flip_B2_Bfirst_r1_i.tag_gpu_global();
    buf_flip_B2_Bsecond_r1_r.tag_gpu_global();
    buf_flip_B2_Bsecond_r1_i.tag_gpu_global();
    buf_flip_B2_Bthird_r1_r.tag_gpu_global();
    buf_flip_B2_Bthird_r1_i.tag_gpu_global();
    flip_B2_Blocal_r1_r_init.store_in(&buf_flip_B2_Blocal_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Blocal_r1_i_init.store_in(&buf_flip_B2_Blocal_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bfirst_r1_r_init.store_in(&buf_flip_B2_Bfirst_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bfirst_r1_i_init.store_in(&buf_flip_B2_Bfirst_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bsecond_r1_r_init.store_in(&buf_flip_B2_Bsecond_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bsecond_r1_i_init.store_in(&buf_flip_B2_Bsecond_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bthird_r1_r_init.store_in(&buf_flip_B2_Bthird_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bthird_r1_i_init.store_in(&buf_flip_B2_Bthird_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Blocal_r1_r_update.store_in(&buf_flip_B2_Blocal_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Blocal_r1_i_update.store_in(&buf_flip_B2_Blocal_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bfirst_r1_r_update.store_in(&buf_flip_B2_Bfirst_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bfirst_r1_i_update.store_in(&buf_flip_B2_Bfirst_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2}); 
    flip_B2_Bsecond_r1_r_update.store_in(&buf_flip_B2_Bsecond_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bsecond_r1_i_update.store_in(&buf_flip_B2_Bsecond_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bthird_r1_r_update.store_in(&buf_flip_B2_Bthird_r1_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bthird_r1_i_update.store_in(&buf_flip_B2_Bthird_r1_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2}); 

    // computation *allocate_buf_flip_B2_Blocal_r1_r = buf_flip_B2_Blocal_r1_r.allocate_at( flip_B2_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B2_Blocal_r1_i = buf_flip_B2_Blocal_r1_i.allocate_at( flip_B2_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B2_Bfirst_r1_r = buf_flip_B2_Bfirst_r1_r.allocate_at( flip_B2_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B2_Bfirst_r1_i = buf_flip_B2_Bfirst_r1_i.allocate_at( flip_B2_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B2_Bsecond_r1_r = buf_flip_B2_Bsecond_r1_r.allocate_at( flip_B2_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B2_Bsecond_r1_i = buf_flip_B2_Bsecond_r1_i.allocate_at( flip_B2_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B2_Bthird_r1_r = buf_flip_B2_Bthird_r1_r.allocate_at( flip_B2_Blocal_r1_r_init, t );
    // computation *allocate_buf_flip_B2_Bthird_r1_i = buf_flip_B2_Bthird_r1_i.allocate_at( flip_B2_Blocal_r1_r_init, t );

    // computation *deallocate_buf_flip_B2_Blocal_r1_r = buf_flip_B2_Blocal_r1_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Blocal_r1_i = buf_flip_B2_Blocal_r1_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bfirst_r1_r = buf_flip_B2_Bfirst_r1_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bfirst_r1_i = buf_flip_B2_Bfirst_r1_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bsecond_r1_r = buf_flip_B2_Bsecond_r1_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bsecond_r1_i = buf_flip_B2_Bsecond_r1_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bthird_r1_r = buf_flip_B2_Bthird_r1_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bthird_r1_i = buf_flip_B2_Bthird_r1_i.deallocate_at( C_BB_BB_prop_update_i_2, t );

    buffer buf_B2_Blocal_diquark_r1_r("buf_B2_Blocal_diquark_r1_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B2_Blocal_diquark_r1_i("buf_B2_Blocal_diquark_r1_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_diquark_r1_r("buf_B2_Bfirst_diquark_r1_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_diquark_r1_i("buf_B2_Bfirst_diquark_r1_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B2_Bthird_diquark_r1_r("buf_B2_Bthird_diquark_r1_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B2_Bthird_diquark_r1_i("buf_B2_Bthird_diquark_r1_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buf_B2_Blocal_diquark_r1_r.tag_gpu_global();
    buf_B2_Blocal_diquark_r1_i.tag_gpu_global();
    buf_B2_Bfirst_diquark_r1_r.tag_gpu_global();
    buf_B2_Bfirst_diquark_r1_i.tag_gpu_global();
    buf_B2_Bthird_diquark_r1_r.tag_gpu_global();
    buf_B2_Bthird_diquark_r1_i.tag_gpu_global();
    B2_Blocal_r1_r_diquark.store_in(&buf_B2_Blocal_diquark_r1_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B2_Blocal_r1_i_diquark.store_in(&buf_B2_Blocal_diquark_r1_i, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B2_Bfirst_r1_r_diquark.store_in(&buf_B2_Bfirst_diquark_r1_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B2_Bfirst_r1_i_diquark.store_in(&buf_B2_Bfirst_diquark_r1_i, {x1, x2, iCprime, iSprime, kCprime, kSprime}); 
    B2_Bthird_r1_r_diquark.store_in(&buf_B2_Bthird_diquark_r1_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B2_Bthird_r1_i_diquark.store_in(&buf_B2_Bthird_diquark_r1_i, {x1, x2, iCprime, iSprime, kCprime, kSprime}); 
    buffer buf_B2_Blocal_props_r1_r("buf_B2_Blocal_props_r1_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Blocal_props_r1_i("buf_B2_Blocal_props_r1_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_props_r1_r("buf_B2_Bfirst_props_r1_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_props_r1_i("buf_B2_Bfirst_props_r1_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bsecond_props_r1_r("buf_B2_Bsecond_props_r1_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bsecond_props_r1_i("buf_B2_Bsecond_props_r1_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bthird_props_r1_r("buf_B2_Bthird_props_r1_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bthird_props_r1_i("buf_B2_Bthird_props_r1_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buf_B2_Blocal_props_r1_r.tag_gpu_global();
    buf_B2_Blocal_props_r1_i.tag_gpu_global();
    buf_B2_Bfirst_props_r1_r.tag_gpu_global();
    buf_B2_Bfirst_props_r1_i.tag_gpu_global();
    buf_B2_Bsecond_props_r1_r.tag_gpu_global();
    buf_B2_Bsecond_props_r1_i.tag_gpu_global();
    buf_B2_Bthird_props_r1_r.tag_gpu_global();
    buf_B2_Bthird_props_r1_i.tag_gpu_global();
    B2_Blocal_r1_r_props_init.store_in(&buf_B2_Blocal_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Blocal_r1_i_props_init.store_in(&buf_B2_Blocal_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bfirst_r1_r_props_init.store_in(&buf_B2_Bfirst_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bfirst_r1_i_props_init.store_in(&buf_B2_Bfirst_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bsecond_r1_r_props_init.store_in(&buf_B2_Bsecond_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bsecond_r1_i_props_init.store_in(&buf_B2_Bsecond_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bthird_r1_r_props_init.store_in(&buf_B2_Bthird_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bthird_r1_i_props_init.store_in(&buf_B2_Bthird_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Blocal_r1_r_props.store_in(&buf_B2_Blocal_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Blocal_r1_i_props.store_in(&buf_B2_Blocal_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bfirst_r1_r_props.store_in(&buf_B2_Bfirst_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bfirst_r1_i_props.store_in(&buf_B2_Bfirst_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2}); 
    B2_Bsecond_r1_r_props.store_in(&buf_B2_Bsecond_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bsecond_r1_i_props.store_in(&buf_B2_Bsecond_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bthird_r1_r_props.store_in(&buf_B2_Bthird_props_r1_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bthird_r1_i_props.store_in(&buf_B2_Bthird_props_r1_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2}); 
    
    computation* allocate_buf_B2_Blocal_props_r1_r = buf_B2_Blocal_props_r1_r.allocate_at( B2_Blocal_r1_r_props_init, t );
    computation* allocate_buf_B2_Blocal_props_r1_i = buf_B2_Blocal_props_r1_i.allocate_at( B2_Blocal_r1_r_props_init, t );
    computation* allocate_buf_B2_Bfirst_props_r1_r = buf_B2_Bfirst_props_r1_r.allocate_at( B2_Blocal_r1_r_props_init, t );
    computation* allocate_buf_B2_Bfirst_props_r1_i = buf_B2_Bfirst_props_r1_i.allocate_at( B2_Blocal_r1_r_props_init, t );
    computation* allocate_buf_B2_Bsecond_props_r1_r = buf_B2_Bsecond_props_r1_r.allocate_at( B2_Blocal_r1_r_props_init, t );
    computation* allocate_buf_B2_Bsecond_props_r1_i = buf_B2_Bsecond_props_r1_i.allocate_at( B2_Blocal_r1_r_props_init, t );
    computation* allocate_buf_B2_Bthird_props_r1_r = buf_B2_Bthird_props_r1_r.allocate_at( B2_Blocal_r1_r_props_init, t );
    computation* allocate_buf_B2_Bthird_props_r1_i = buf_B2_Bthird_props_r1_i.allocate_at( B2_Blocal_r1_r_props_init, t );

    computation* deallocate_buf_B2_Blocal_props_r1_r = buf_B2_Blocal_props_r1_r.deallocate_at( flip_B2_Bthird_r1_i_update, t );
    computation* deallocate_buf_B2_Blocal_props_r1_i = buf_B2_Blocal_props_r1_i.deallocate_at( flip_B2_Bthird_r1_i_update, t );
    computation* deallocate_buf_B2_Bfirst_props_r1_r = buf_B2_Bfirst_props_r1_r.deallocate_at( flip_B2_Bthird_r1_i_update, t );
    computation* deallocate_buf_B2_Bfirst_props_r1_i = buf_B2_Bfirst_props_r1_i.deallocate_at( flip_B2_Bthird_r1_i_update, t );
    computation* deallocate_buf_B2_Bsecond_props_r1_r = buf_B2_Bsecond_props_r1_r.deallocate_at( flip_B2_Bthird_r1_i_update, t );
    computation* deallocate_buf_B2_Bsecond_props_r1_i = buf_B2_Bsecond_props_r1_i.deallocate_at( flip_B2_Bthird_r1_i_update, t );
    computation* deallocate_buf_B2_Bthird_props_r1_r = buf_B2_Bthird_props_r1_r.deallocate_at( flip_B2_Bthird_r1_i_update, t );
    computation* deallocate_buf_B2_Bthird_props_r1_i = buf_B2_Bthird_props_r1_i.deallocate_at( flip_B2_Bthird_r1_i_update, t );

    buffer buf_B2_Blocal_r2_r("buf_B2_Blocal_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Blocal_r2_i("buf_B2_Blocal_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_r2_r("buf_B2_Bfirst_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_r2_i("buf_B2_Bfirst_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bsecond_r2_r("buf_B2_Bsecond_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bsecond_r2_i("buf_B2_Bsecond_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bthird_r2_r("buf_B2_Bthird_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bthird_r2_i("buf_B2_Bthird_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buf_B2_Blocal_r2_r.tag_gpu_global();
    buf_B2_Blocal_r2_i.tag_gpu_global();
    buf_B2_Bfirst_r2_r.tag_gpu_global();
    buf_B2_Bfirst_r2_i.tag_gpu_global();
    buf_B2_Bsecond_r2_r.tag_gpu_global();
    buf_B2_Bsecond_r2_i.tag_gpu_global();
    buf_B2_Bthird_r2_r.tag_gpu_global();
    buf_B2_Bthird_r2_i.tag_gpu_global();
    B2_Blocal_r2_r_init.store_in(&buf_B2_Blocal_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Blocal_r2_i_init.store_in(&buf_B2_Blocal_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bfirst_r2_r_init.store_in(&buf_B2_Bfirst_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bfirst_r2_i_init.store_in(&buf_B2_Bfirst_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bsecond_r2_r_init.store_in(&buf_B2_Bsecond_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bsecond_r2_i_init.store_in(&buf_B2_Bsecond_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bthird_r2_r_init.store_in(&buf_B2_Bthird_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bthird_r2_i_init.store_in(&buf_B2_Bthird_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Blocal_r2_r_update.store_in(&buf_B2_Blocal_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Blocal_r2_i_update.store_in(&buf_B2_Blocal_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bfirst_r2_r_update.store_in(&buf_B2_Bfirst_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bfirst_r2_i_update.store_in(&buf_B2_Bfirst_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bsecond_r2_r_update.store_in(&buf_B2_Bsecond_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bsecond_r2_i_update.store_in(&buf_B2_Bsecond_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bthird_r2_r_update.store_in(&buf_B2_Bthird_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    B2_Bthird_r2_i_update.store_in(&buf_B2_Bthird_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});

    // computation *allocate_buf_B2_Blocal_r2_r = buf_B2_Blocal_r2_r.allocate_at( B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_B2_Blocal_r2_i = buf_B2_Blocal_r2_i.allocate_at( B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_B2_Bfirst_r2_r = buf_B2_Bfirst_r2_r.allocate_at( B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_B2_Bfirst_r2_i = buf_B2_Bfirst_r2_i.allocate_at( B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_B2_Bsecond_r2_r = buf_B2_Bsecond_r2_r.allocate_at( B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_B2_Bsecond_r2_i = buf_B2_Bsecond_r2_i.allocate_at( B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_B2_Bthird_r2_r = buf_B2_Bthird_r2_r.allocate_at( B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_B2_Bthird_r2_i = buf_B2_Bthird_r2_i.allocate_at( B2_Blocal_r2_r_init, t );

    // computation *deallocate_buf_B2_Blocal_r2_r = buf_B2_Blocal_r2_r.deallocate_at( B2_Bthird_r2_i_update, t );
    // computation *deallocate_buf_B2_Blocal_r2_i = buf_B2_Blocal_r2_i.deallocate_at( B2_Bthird_r2_i_update, t );
    // computation *deallocate_buf_B2_Bfirst_r2_r = buf_B2_Bfirst_r2_r.deallocate_at( B2_Bthird_r2_i_update, t );
    // computation *deallocate_buf_B2_Bfirst_r2_i = buf_B2_Bfirst_r2_i.deallocate_at( B2_Bthird_r2_i_update, t );
    // computation *deallocate_buf_B2_Bsecond_r2_r = buf_B2_Bsecond_r2_r.deallocate_at( B2_Bthird_r2_i_update, t );
    // computation *deallocate_buf_B2_Bsecond_r2_i = buf_B2_Bsecond_r2_i.deallocate_at( B2_Bthird_r2_i_update, t );
    // computation *deallocate_buf_B2_Bthird_r2_r = buf_B2_Bthird_r2_r.deallocate_at( B2_Bthird_r2_i_update, t );
    // computation *deallocate_buf_B2_Bthird_r2_i = buf_B2_Bthird_r2_i.deallocate_at( B2_Bthird_r2_i_update, t );

    buffer buf_flip_B2_Blocal_r2_r("buf_flip_B2_Blocal_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary); // ~1Gb of data
    buffer buf_flip_B2_Blocal_r2_i("buf_flip_B2_Blocal_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bfirst_r2_r("buf_flip_B2_Bfirst_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bfirst_r2_i("buf_flip_B2_Bfirst_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bsecond_r2_r("buf_flip_B2_Bsecond_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bsecond_r2_i("buf_flip_B2_Bsecond_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bthird_r2_r("buf_flip_B2_Bthird_r2_r",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buffer buf_flip_B2_Bthird_r2_i("buf_flip_B2_Bthird_r2_i",   { Lt, Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, Vsnk}, p_float64, a_temporary);
    buf_flip_B2_Blocal_r2_r.tag_gpu_global();
    buf_flip_B2_Blocal_r2_i.tag_gpu_global();
    buf_flip_B2_Bfirst_r2_r.tag_gpu_global();
    buf_flip_B2_Bfirst_r2_i.tag_gpu_global();
    buf_flip_B2_Bsecond_r2_r.tag_gpu_global();
    buf_flip_B2_Bsecond_r2_i.tag_gpu_global();
    buf_flip_B2_Bthird_r2_r.tag_gpu_global();
    buf_flip_B2_Bthird_r2_i.tag_gpu_global();
    flip_B2_Blocal_r2_i_init.store_in(&buf_flip_B2_Blocal_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Blocal_r2_r_init.store_in(&buf_flip_B2_Blocal_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bfirst_r2_r_init.store_in(&buf_flip_B2_Bfirst_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bfirst_r2_i_init.store_in(&buf_flip_B2_Bfirst_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bsecond_r2_r_init.store_in(&buf_flip_B2_Bsecond_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bsecond_r2_i_init.store_in(&buf_flip_B2_Bsecond_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bthird_r2_r_init.store_in(&buf_flip_B2_Bthird_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bthird_r2_i_init.store_in(&buf_flip_B2_Bthird_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Blocal_r2_r_update.store_in(&buf_flip_B2_Blocal_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Blocal_r2_i_update.store_in(&buf_flip_B2_Blocal_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bfirst_r2_r_update.store_in(&buf_flip_B2_Bfirst_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bfirst_r2_i_update.store_in(&buf_flip_B2_Bfirst_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2}); 
    flip_B2_Bsecond_r2_r_update.store_in(&buf_flip_B2_Bsecond_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bsecond_r2_i_update.store_in(&buf_flip_B2_Bsecond_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bthird_r2_r_update.store_in(&buf_flip_B2_Bthird_r2_r, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2});
    flip_B2_Bthird_r2_i_update.store_in(&buf_flip_B2_Bthird_r2_i, { t, x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x2}); 

    // computation *allocate_buf_flip_B2_Blocal_r2_r = buf_flip_B2_Blocal_r2_r.allocate_at( flip_B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B2_Blocal_r2_i = buf_flip_B2_Blocal_r2_i.allocate_at( flip_B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B2_Bfirst_r2_r = buf_flip_B2_Bfirst_r2_r.allocate_at( flip_B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B2_Bfirst_r2_i = buf_flip_B2_Bfirst_r2_i.allocate_at( flip_B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B2_Bsecond_r2_r = buf_flip_B2_Bsecond_r2_r.allocate_at( flip_B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B2_Bsecond_r2_i = buf_flip_B2_Bsecond_r2_i.allocate_at( flip_B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B2_Bthird_r2_r = buf_flip_B2_Bthird_r2_r.allocate_at( flip_B2_Blocal_r2_r_init, t );
    // computation *allocate_buf_flip_B2_Bthird_r2_i = buf_flip_B2_Bthird_r2_i.allocate_at( flip_B2_Blocal_r2_r_init, t );

    // computation *deallocate_buf_flip_B2_Blocal_r2_r = buf_flip_B2_Blocal_r2_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Blocal_r2_i = buf_flip_B2_Blocal_r2_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bfirst_r2_r = buf_flip_B2_Bfirst_r2_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bfirst_r2_i = buf_flip_B2_Bfirst_r2_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bsecond_r2_r = buf_flip_B2_Bsecond_r2_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bsecond_r2_i = buf_flip_B2_Bsecond_r2_i.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bthird_r2_r = buf_flip_B2_Bthird_r2_r.deallocate_at( C_BB_BB_prop_update_i_2, t );
    // computation *deallocate_buf_flip_B2_Bthird_r2_i = buf_flip_B2_Bthird_r2_i.deallocate_at( C_BB_BB_prop_update_i_2, t );

    buffer buf_B2_Blocal_diquark_r2_r("buf_B2_Blocal_diquark_r2_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B2_Blocal_diquark_r2_i("buf_B2_Blocal_diquark_r2_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_diquark_r2_r("buf_B2_Bfirst_diquark_r2_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_diquark_r2_i("buf_B2_Bfirst_diquark_r2_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B2_Bthird_diquark_r2_r("buf_B2_Bthird_diquark_r2_r",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buffer buf_B2_Bthird_diquark_r2_i("buf_B2_Bthird_diquark_r2_i",   {Vsnk, Vsnk, Nc, Ns, Nc, Ns}, p_float64, a_temporary);
    buf_B2_Blocal_diquark_r2_r.tag_gpu_global();
    buf_B2_Blocal_diquark_r2_i.tag_gpu_global();
    buf_B2_Bfirst_diquark_r2_r.tag_gpu_global();
    buf_B2_Bfirst_diquark_r2_i.tag_gpu_global();
    buf_B2_Bthird_diquark_r2_r.tag_gpu_global();
    buf_B2_Bthird_diquark_r2_i.tag_gpu_global();
    B2_Blocal_r2_r_diquark.store_in(&buf_B2_Blocal_diquark_r2_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B2_Blocal_r2_i_diquark.store_in(&buf_B2_Blocal_diquark_r2_i, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B2_Bfirst_r2_r_diquark.store_in(&buf_B2_Bfirst_diquark_r2_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B2_Bfirst_r2_i_diquark.store_in(&buf_B2_Bfirst_diquark_r2_i, {x1, x2, iCprime, iSprime, kCprime, kSprime}); 
    B2_Bthird_r2_r_diquark.store_in(&buf_B2_Bthird_diquark_r2_r, {x1, x2, iCprime, iSprime, kCprime, kSprime});
    B2_Bthird_r2_i_diquark.store_in(&buf_B2_Bthird_diquark_r2_i, {x1, x2, iCprime, iSprime, kCprime, kSprime}); 
    buffer buf_B2_Blocal_props_r2_r("buf_B2_Blocal_props_r2_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Blocal_props_r2_i("buf_B2_Blocal_props_r2_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_props_r2_r("buf_B2_Bfirst_props_r2_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bfirst_props_r2_i("buf_B2_Bfirst_props_r2_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bsecond_props_r2_r("buf_B2_Bsecond_props_r2_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bsecond_props_r2_i("buf_B2_Bsecond_props_r2_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bthird_props_r2_r("buf_B2_Bthird_props_r2_r",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buffer buf_B2_Bthird_props_r2_i("buf_B2_Bthird_props_r2_i",   {Vsnk, Nc, Ns, Nc, Ns, Nc, Ns, Vsnk, Vsnk}, p_float64, a_temporary);
    buf_B2_Blocal_props_r2_r.tag_gpu_global();
    buf_B2_Blocal_props_r2_i.tag_gpu_global();
    buf_B2_Bfirst_props_r2_r.tag_gpu_global();
    buf_B2_Bfirst_props_r2_i.tag_gpu_global();
    buf_B2_Bsecond_props_r2_r.tag_gpu_global();
    buf_B2_Bsecond_props_r2_i.tag_gpu_global();
    buf_B2_Bthird_props_r2_r.tag_gpu_global();
    buf_B2_Bthird_props_r2_i.tag_gpu_global();
    B2_Blocal_r2_r_props_init.store_in(&buf_B2_Blocal_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Blocal_r2_i_props_init.store_in(&buf_B2_Blocal_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bfirst_r2_r_props_init.store_in(&buf_B2_Bfirst_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bfirst_r2_i_props_init.store_in(&buf_B2_Bfirst_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bsecond_r2_r_props_init.store_in(&buf_B2_Bsecond_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bsecond_r2_i_props_init.store_in(&buf_B2_Bsecond_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bthird_r2_r_props_init.store_in(&buf_B2_Bthird_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bthird_r2_i_props_init.store_in(&buf_B2_Bthird_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Blocal_r2_r_props.store_in(&buf_B2_Blocal_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Blocal_r2_i_props.store_in(&buf_B2_Blocal_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bfirst_r2_r_props.store_in(&buf_B2_Bfirst_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bfirst_r2_i_props.store_in(&buf_B2_Bfirst_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2}); 
    B2_Bsecond_r2_r_props.store_in(&buf_B2_Bsecond_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bsecond_r2_i_props.store_in(&buf_B2_Bsecond_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bthird_r2_r_props.store_in(&buf_B2_Bthird_props_r2_r, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2});
    B2_Bthird_r2_i_props.store_in(&buf_B2_Bthird_props_r2_i, {x1, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, y, x2}); 
    
    computation *allocate_buf_B2_Blocal_props_r2_r = buf_B2_Blocal_props_r2_r.allocate_at( B2_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B2_Blocal_props_r2_i = buf_B2_Blocal_props_r2_i.allocate_at( B2_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B2_Bfirst_props_r2_r = buf_B2_Bfirst_props_r2_r.allocate_at( B2_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B2_Bfirst_props_r2_i = buf_B2_Bfirst_props_r2_i.allocate_at( B2_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B2_Bsecond_props_r2_r = buf_B2_Bsecond_props_r2_r.allocate_at( B2_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B2_Bsecond_props_r2_i = buf_B2_Bsecond_props_r2_i.allocate_at( B2_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B2_Bthird_props_r2_r = buf_B2_Bthird_props_r2_r.allocate_at( B2_Blocal_r2_r_props_init, t );
    computation *allocate_buf_B2_Bthird_props_r2_i = buf_B2_Bthird_props_r2_i.allocate_at( B2_Blocal_r2_r_props_init, t );

    computation *deallocate_buf_B2_Blocal_props_r2_r = buf_B2_Blocal_props_r2_r.deallocate_at( flip_B2_Bthird_r2_i_update, t );
    computation *deallocate_buf_B2_Blocal_props_r2_i = buf_B2_Blocal_props_r2_i.deallocate_at( flip_B2_Bthird_r2_i_update, t );
    computation *deallocate_buf_B2_Bfirst_props_r2_r = buf_B2_Bfirst_props_r2_r.deallocate_at( flip_B2_Bthird_r2_i_update, t );
    computation *deallocate_buf_B2_Bfirst_props_r2_i = buf_B2_Bfirst_props_r2_i.deallocate_at( flip_B2_Bthird_r2_i_update, t );
    computation *deallocate_buf_B2_Bsecond_props_r2_r = buf_B2_Bsecond_props_r2_r.deallocate_at( flip_B2_Bthird_r2_i_update, t );
    computation *deallocate_buf_B2_Bsecond_props_r2_i = buf_B2_Bsecond_props_r2_i.deallocate_at( flip_B2_Bthird_r2_i_update, t );
    computation *deallocate_buf_B2_Bthird_props_r2_r = buf_B2_Bthird_props_r2_r.deallocate_at( flip_B2_Bthird_r2_i_update, t );
    computation *deallocate_buf_B2_Bthird_props_r2_i = buf_B2_Bthird_props_r2_i.deallocate_at( flip_B2_Bthird_r2_i_update, t );

    buffer buf_src_B1_Blocal_r1_r("buf_src_B1_Blocal_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buffer buf_src_B1_Blocal_r1_i("buf_src_B1_Blocal_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buf_src_B1_Blocal_r1_r.tag_gpu_global();
    buf_src_B1_Blocal_r1_i.tag_gpu_global();
    src_B1_Blocal_r1_r_init.store_in(&buf_src_B1_Blocal_r1_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    src_B1_Blocal_r1_i_init.store_in(&buf_src_B1_Blocal_r1_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    src_B1_Blocal_r1_r_update.store_in(&buf_src_B1_Blocal_r1_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    src_B1_Blocal_r1_i_update.store_in(&buf_src_B1_Blocal_r1_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    buffer buf_flip_src_B1_Blocal_r1_r("buf_flip_src_B1_Blocal_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buffer buf_flip_src_B1_Blocal_r1_i("buf_flip_src_B1_Blocal_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buf_flip_src_B1_Blocal_r1_r.tag_gpu_global();
    buf_flip_src_B1_Blocal_r1_i.tag_gpu_global();
    flip_src_B1_Blocal_r1_r_init.store_in(&buf_flip_src_B1_Blocal_r1_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    flip_src_B1_Blocal_r1_i_init.store_in(&buf_flip_src_B1_Blocal_r1_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    flip_src_B1_Blocal_r1_r_update.store_in(&buf_flip_src_B1_Blocal_r1_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    flip_src_B1_Blocal_r1_i_update.store_in(&buf_flip_src_B1_Blocal_r1_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    buffer buf_src_B1_Blocal_diquark_r1_r("buf_src_B1_Blocal_diquark_r1_r",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buffer buf_src_B1_Blocal_diquark_r1_i("buf_src_B1_Blocal_diquark_r1_i",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buf_src_B1_Blocal_diquark_r1_r.tag_gpu_global();
    buf_src_B1_Blocal_diquark_r1_i.tag_gpu_global();
    src_B1_Blocal_r1_r_diquark.store_in(&buf_src_B1_Blocal_diquark_r1_r, {x_out, x_in});
    src_B1_Blocal_r1_i_diquark.store_in(&buf_src_B1_Blocal_diquark_r1_i, {x_out, x_in});
    buffer buf_src_B1_Blocal_props_r1_r("buf_src_B1_Blocal_props_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buffer buf_src_B1_Blocal_props_r1_i("buf_src_B1_Blocal_props_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buf_src_B1_Blocal_props_r1_r.tag_gpu_global();
    buf_src_B1_Blocal_props_r1_i.tag_gpu_global();
    src_B1_Blocal_r1_r_props_init.store_in(&buf_src_B1_Blocal_props_r1_r, {x_out, jCprime, jSprime, x_in});
    src_B1_Blocal_r1_i_props_init.store_in(&buf_src_B1_Blocal_props_r1_i, {x_out, jCprime, jSprime, x_in});
    src_B1_Blocal_r1_r_props.store_in(&buf_src_B1_Blocal_props_r1_r, {x_out, jCprime, jSprime, x_in});
    src_B1_Blocal_r1_i_props.store_in(&buf_src_B1_Blocal_props_r1_i, {x_out, jCprime, jSprime, x_in});

    buffer buf_src_B1_Blocal_r2_r("buf_src_B1_Blocal_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buffer buf_src_B1_Blocal_r2_i("buf_src_B1_Blocal_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buf_src_B1_Blocal_r2_r.tag_gpu_global();
    buf_src_B1_Blocal_r2_i.tag_gpu_global();
    src_B1_Blocal_r2_r_init.store_in(&buf_src_B1_Blocal_r2_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    src_B1_Blocal_r2_i_init.store_in(&buf_src_B1_Blocal_r2_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    src_B1_Blocal_r2_r_update.store_in(&buf_src_B1_Blocal_r2_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    src_B1_Blocal_r2_i_update.store_in(&buf_src_B1_Blocal_r2_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    buffer buf_flip_src_B1_Blocal_r2_r("buf_flip_src_B1_Blocal_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buffer buf_flip_src_B1_Blocal_r2_i("buf_flip_src_B1_Blocal_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buf_flip_src_B1_Blocal_r2_r.tag_gpu_global();
    buf_flip_src_B1_Blocal_r2_i.tag_gpu_global();
    flip_src_B1_Blocal_r2_r_init.store_in(&buf_flip_src_B1_Blocal_r2_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    flip_src_B1_Blocal_r2_i_init.store_in(&buf_flip_src_B1_Blocal_r2_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    flip_src_B1_Blocal_r2_r_update.store_in(&buf_flip_src_B1_Blocal_r2_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    flip_src_B1_Blocal_r2_i_update.store_in(&buf_flip_src_B1_Blocal_r2_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    buffer buf_src_B1_Blocal_diquark_r2_r("buf_src_B1_Blocal_diquark_r2_r",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buffer buf_src_B1_Blocal_diquark_r2_i("buf_src_B1_Blocal_diquark_r2_i",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buf_src_B1_Blocal_diquark_r2_r.tag_gpu_global();
    buf_src_B1_Blocal_diquark_r2_i.tag_gpu_global();
    src_B1_Blocal_r2_r_diquark.store_in(&buf_src_B1_Blocal_diquark_r2_r, {x_out, x_in});
    src_B1_Blocal_r2_i_diquark.store_in(&buf_src_B1_Blocal_diquark_r2_i, {x_out, x_in});
    buffer buf_src_B1_Blocal_props_r2_r("buf_src_B1_Blocal_props_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buffer buf_src_B1_Blocal_props_r2_i("buf_src_B1_Blocal_props_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buf_src_B1_Blocal_props_r2_r.tag_gpu_global();
    buf_src_B1_Blocal_props_r2_i.tag_gpu_global();
    src_B1_Blocal_r2_r_props_init.store_in(&buf_src_B1_Blocal_props_r2_r, {x_out, jCprime, jSprime, x_in});
    src_B1_Blocal_r2_i_props_init.store_in(&buf_src_B1_Blocal_props_r2_i, {x_out, jCprime, jSprime, x_in});
    src_B1_Blocal_r2_r_props.store_in(&buf_src_B1_Blocal_props_r2_r, {x_out, jCprime, jSprime, x_in});
    src_B1_Blocal_r2_i_props.store_in(&buf_src_B1_Blocal_props_r2_i, {x_out, jCprime, jSprime, x_in});
    
    buffer buf_src_B2_Blocal_r1_r("buf_src_B2_Blocal_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buffer buf_src_B2_Blocal_r1_i("buf_src_B2_Blocal_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buf_src_B2_Blocal_r1_r.tag_gpu_global();
    buf_src_B2_Blocal_r1_i.tag_gpu_global();
    src_B2_Blocal_r1_r_init.store_in(&buf_src_B2_Blocal_r1_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    src_B2_Blocal_r1_i_init.store_in(&buf_src_B2_Blocal_r1_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    src_B2_Blocal_r1_r_update.store_in(&buf_src_B2_Blocal_r1_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    src_B2_Blocal_r1_i_update.store_in(&buf_src_B2_Blocal_r1_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    buffer buf_flip_src_B2_Blocal_r1_r("buf_flip_src_B2_Blocal_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buffer buf_flip_src_B2_Blocal_r1_i("buf_flip_src_B2_Blocal_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
    buf_flip_src_B2_Blocal_r1_r.tag_gpu_global();
    buf_flip_src_B2_Blocal_r1_i.tag_gpu_global();
    flip_src_B2_Blocal_r1_r_init.store_in(&buf_flip_src_B2_Blocal_r1_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    flip_src_B2_Blocal_r1_i_init.store_in(&buf_flip_src_B2_Blocal_r1_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    flip_src_B2_Blocal_r1_r_update.store_in(&buf_flip_src_B2_Blocal_r1_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    flip_src_B2_Blocal_r1_i_update.store_in(&buf_flip_src_B2_Blocal_r1_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
    buffer buf_src_B2_Blocal_diquark_r1_r("buf_src_B2_Blocal_diquark_r1_r",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buffer buf_src_B2_Blocal_diquark_r1_i("buf_src_B2_Blocal_diquark_r1_i",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buf_src_B2_Blocal_diquark_r1_r.tag_gpu_global();
    buf_src_B2_Blocal_diquark_r1_i.tag_gpu_global();
    src_B2_Blocal_r1_r_diquark.store_in(&buf_src_B2_Blocal_diquark_r1_r, {x_out, x_in});
    src_B2_Blocal_r1_i_diquark.store_in(&buf_src_B2_Blocal_diquark_r1_i, {x_out, x_in});
    buffer buf_src_B2_Blocal_props_r1_r("buf_src_B2_Blocal_props_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buffer buf_src_B2_Blocal_props_r1_i("buf_src_B2_Blocal_props_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buf_src_B2_Blocal_props_r1_r.tag_gpu_global();
    buf_src_B2_Blocal_props_r1_i.tag_gpu_global();
    src_B2_Blocal_r1_r_props_init.store_in(&buf_src_B2_Blocal_props_r1_r, {x_out, jCprime, jSprime, x_in});
    src_B2_Blocal_r1_i_props_init.store_in(&buf_src_B2_Blocal_props_r1_i, {x_out, jCprime, jSprime, x_in});
    src_B2_Blocal_r1_r_props.store_in(&buf_src_B2_Blocal_props_r1_r, {x_out, jCprime, jSprime, x_in});
    src_B2_Blocal_r1_i_props.store_in(&buf_src_B2_Blocal_props_r1_i, {x_out, jCprime, jSprime, x_in});

        buffer buf_src_B2_Blocal_r2_r("buf_src_B2_Blocal_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
        buffer buf_src_B2_Blocal_r2_i("buf_src_B2_Blocal_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
        buf_src_B2_Blocal_r2_r.tag_gpu_global();
        buf_src_B2_Blocal_r2_i.tag_gpu_global();
        src_B2_Blocal_r2_r_init.store_in(&buf_src_B2_Blocal_r2_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
        src_B2_Blocal_r2_i_init.store_in(&buf_src_B2_Blocal_r2_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
        src_B2_Blocal_r2_r_update.store_in(&buf_src_B2_Blocal_r2_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
        src_B2_Blocal_r2_i_update.store_in(&buf_src_B2_Blocal_r2_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
        buffer buf_flip_src_B2_Blocal_r2_r("buf_flip_src_B2_Blocal_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
        buffer buf_flip_src_B2_Blocal_r2_i("buf_flip_src_B2_Blocal_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsrc, sites_per_rank}, p_float64, a_temporary);
        buf_flip_src_B2_Blocal_r2_r.tag_gpu_global();
        buf_flip_src_B2_Blocal_r2_i.tag_gpu_global();
        flip_src_B2_Blocal_r2_r_init.store_in(&buf_flip_src_B2_Blocal_r2_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
        flip_src_B2_Blocal_r2_i_init.store_in(&buf_flip_src_B2_Blocal_r2_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
        flip_src_B2_Blocal_r2_r_update.store_in(&buf_flip_src_B2_Blocal_r2_r, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
        flip_src_B2_Blocal_r2_i_update.store_in(&buf_flip_src_B2_Blocal_r2_i, {x_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m, x_in});
        buffer buf_src_B2_Blocal_diquark_r2_r("buf_src_B2_Blocal_diquark_r2_r",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
        buffer buf_src_B2_Blocal_diquark_r2_i("buf_src_B2_Blocal_diquark_r2_i",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
        buf_src_B2_Blocal_diquark_r2_r.tag_gpu_global();
        buf_src_B2_Blocal_diquark_r2_i.tag_gpu_global();
        src_B2_Blocal_r2_r_diquark.store_in(&buf_src_B2_Blocal_diquark_r2_r, {x_out, x_in});
        src_B2_Blocal_r2_i_diquark.store_in(&buf_src_B2_Blocal_diquark_r2_i, {x_out, x_in});
        buffer buf_src_B2_Blocal_props_r2_r("buf_src_B2_Blocal_props_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
        buffer buf_src_B2_Blocal_props_r2_i("buf_src_B2_Blocal_props_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
        buf_src_B2_Blocal_props_r2_r.tag_gpu_global();
        buf_src_B2_Blocal_props_r2_i.tag_gpu_global();
        src_B2_Blocal_r2_r_props_init.store_in(&buf_src_B2_Blocal_props_r2_r, {x_out, jCprime, jSprime, x_in}); // {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime}
        src_B2_Blocal_r2_i_props_init.store_in(&buf_src_B2_Blocal_props_r2_i, {x_out, jCprime, jSprime, x_in});
        src_B2_Blocal_r2_r_props.store_in(&buf_src_B2_Blocal_props_r2_r, {x_out, jCprime, jSprime, x_in}); // {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
        src_B2_Blocal_r2_i_props.store_in(&buf_src_B2_Blocal_props_r2_i, {x_out, jCprime, jSprime, x_in}); 

    buffer buf_snk_B1_Blocal_r1_r("buf_snk_B1_Blocal_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B1_Blocal_r1_i("buf_snk_B1_Blocal_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B1_Blocal_r1_r.tag_gpu_global();
    buf_snk_B1_Blocal_r1_i.tag_gpu_global();
    snk_B1_Blocal_r1_r_init.store_in(&buf_snk_B1_Blocal_r1_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B1_Blocal_r1_i_init.store_in(&buf_snk_B1_Blocal_r1_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B1_Blocal_r1_r_update.store_in(&buf_snk_B1_Blocal_r1_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B1_Blocal_r1_i_update.store_in(&buf_snk_B1_Blocal_r1_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    buffer buf_flip_snk_B1_Blocal_r1_r("buf_flip_snk_B1_Blocal_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buffer buf_flip_snk_B1_Blocal_r1_i("buf_flip_snk_B1_Blocal_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buf_flip_snk_B1_Blocal_r1_r.tag_gpu_global();
    buf_flip_snk_B1_Blocal_r1_i.tag_gpu_global();
    flip_snk_B1_Blocal_r1_r_init.store_in(&buf_flip_snk_B1_Blocal_r1_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B1_Blocal_r1_i_init.store_in(&buf_flip_snk_B1_Blocal_r1_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B1_Blocal_r1_r_update.store_in(&buf_flip_snk_B1_Blocal_r1_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B1_Blocal_r1_i_update.store_in(&buf_flip_snk_B1_Blocal_r1_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    buffer buf_snk_B1_Blocal_diquark_r1_r("buf_snk_B1_Blocal_diquark_r1_r",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B1_Blocal_diquark_r1_i("buf_snk_B1_Blocal_diquark_r1_i",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B1_Blocal_diquark_r1_r.tag_gpu_global();
    buf_snk_B1_Blocal_diquark_r1_i.tag_gpu_global();
    snk_B1_Blocal_r1_r_diquark.store_in(&buf_snk_B1_Blocal_diquark_r1_r, {y_out, y_in});
    snk_B1_Blocal_r1_i_diquark.store_in(&buf_snk_B1_Blocal_diquark_r1_i, {y_out, y_in});
    buffer buf_snk_B1_Blocal_props_r1_r("buf_snk_B1_Blocal_props_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B1_Blocal_props_r1_i("buf_snk_B1_Blocal_props_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B1_Blocal_props_r1_r.tag_gpu_global();
    buf_snk_B1_Blocal_props_r1_i.tag_gpu_global();
    snk_B1_Blocal_r1_r_props_init.store_in(&buf_snk_B1_Blocal_props_r1_r, {y_out, jCprime, jSprime, y_in});
    snk_B1_Blocal_r1_i_props_init.store_in(&buf_snk_B1_Blocal_props_r1_i, {y_out, jCprime, jSprime, y_in});
    snk_B1_Blocal_r1_r_props.store_in(&buf_snk_B1_Blocal_props_r1_r, {y_out, jCprime, jSprime, y_in});
    snk_B1_Blocal_r1_i_props.store_in(&buf_snk_B1_Blocal_props_r1_i, {y_out, jCprime, jSprime, y_in});

    buffer buf_snk_B1_Blocal_r2_r("buf_snk_B1_Blocal_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B1_Blocal_r2_i("buf_snk_B1_Blocal_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B1_Blocal_r2_r.tag_gpu_global();
    buf_snk_B1_Blocal_r2_i.tag_gpu_global();
    snk_B1_Blocal_r2_r_init.store_in(&buf_snk_B1_Blocal_r2_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B1_Blocal_r2_i_init.store_in(&buf_snk_B1_Blocal_r2_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B1_Blocal_r2_r_update.store_in(&buf_snk_B1_Blocal_r2_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B1_Blocal_r2_i_update.store_in(&buf_snk_B1_Blocal_r2_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    buffer buf_flip_snk_B1_Blocal_r2_r("buf_flip_snk_B1_Blocal_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buffer buf_flip_snk_B1_Blocal_r2_i("buf_flip_snk_B1_Blocal_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buf_flip_snk_B1_Blocal_r2_r.tag_gpu_global();
    buf_flip_snk_B1_Blocal_r2_i.tag_gpu_global();
    flip_snk_B1_Blocal_r2_r_init.store_in(&buf_flip_snk_B1_Blocal_r2_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B1_Blocal_r2_i_init.store_in(&buf_flip_snk_B1_Blocal_r2_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B1_Blocal_r2_r_update.store_in(&buf_flip_snk_B1_Blocal_r2_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B1_Blocal_r2_i_update.store_in(&buf_flip_snk_B1_Blocal_r2_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    buffer buf_snk_B1_Blocal_diquark_r2_r("buf_snk_B1_Blocal_diquark_r2_r",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B1_Blocal_diquark_r2_i("buf_snk_B1_Blocal_diquark_r2_i",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B1_Blocal_diquark_r2_r.tag_gpu_global();
    buf_snk_B1_Blocal_diquark_r2_i.tag_gpu_global();
    snk_B1_Blocal_r2_r_diquark.store_in(&buf_snk_B1_Blocal_diquark_r2_r, {y_out, y_in});
    snk_B1_Blocal_r2_i_diquark.store_in(&buf_snk_B1_Blocal_diquark_r2_i, {y_out, y_in});
    buffer buf_snk_B1_Blocal_props_r2_r("buf_snk_B1_Blocal_props_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B1_Blocal_props_r2_i("buf_snk_B1_Blocal_props_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B1_Blocal_props_r2_r.tag_gpu_global();
    buf_snk_B1_Blocal_props_r2_i.tag_gpu_global();
    snk_B1_Blocal_r2_r_props_init.store_in(&buf_snk_B1_Blocal_props_r2_r, {y_out, jCprime, jSprime, y_in});
    snk_B1_Blocal_r2_i_props_init.store_in(&buf_snk_B1_Blocal_props_r2_i, {y_out, jCprime, jSprime, y_in});
    snk_B1_Blocal_r2_r_props.store_in(&buf_snk_B1_Blocal_props_r2_r, {y_out, jCprime, jSprime, y_in});
    snk_B1_Blocal_r2_i_props.store_in(&buf_snk_B1_Blocal_props_r2_i, {y_out, jCprime, jSprime, y_in});

    buffer buf_snk_B2_Blocal_r1_r("buf_snk_B2_Blocal_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B2_Blocal_r1_i("buf_snk_B2_Blocal_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B2_Blocal_r1_r.tag_gpu_global();
    buf_snk_B2_Blocal_r1_i.tag_gpu_global();
    snk_B2_Blocal_r1_r_init.store_in(&buf_snk_B2_Blocal_r1_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B2_Blocal_r1_i_init.store_in(&buf_snk_B2_Blocal_r1_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B2_Blocal_r1_r_update.store_in(&buf_snk_B2_Blocal_r1_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B2_Blocal_r1_i_update.store_in(&buf_snk_B2_Blocal_r1_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    buffer buf_flip_snk_B2_Blocal_r1_r("buf_flip_snk_B2_Blocal_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buffer buf_flip_snk_B2_Blocal_r1_i("buf_flip_snk_B2_Blocal_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buf_flip_snk_B2_Blocal_r1_r.tag_gpu_global();
    buf_flip_snk_B2_Blocal_r1_i.tag_gpu_global();
    flip_snk_B2_Blocal_r1_r_init.store_in(&buf_flip_snk_B2_Blocal_r1_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B2_Blocal_r1_i_init.store_in(&buf_flip_snk_B2_Blocal_r1_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B2_Blocal_r1_r_update.store_in(&buf_flip_snk_B2_Blocal_r1_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B2_Blocal_r1_i_update.store_in(&buf_flip_snk_B2_Blocal_r1_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    buffer buf_snk_B2_Blocal_diquark_r1_r("buf_snk_B2_Blocal_diquark_r1_r",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B2_Blocal_diquark_r1_i("buf_snk_B2_Blocal_diquark_r1_i",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B2_Blocal_diquark_r1_r.tag_gpu_global();
    buf_snk_B2_Blocal_diquark_r1_i.tag_gpu_global();
    snk_B2_Blocal_r1_r_diquark.store_in(&buf_snk_B2_Blocal_diquark_r1_r, {y_out, y_in});
    snk_B2_Blocal_r1_i_diquark.store_in(&buf_snk_B2_Blocal_diquark_r1_i, {y_out, y_in});
    buffer buf_snk_B2_Blocal_props_r1_r("buf_snk_B2_Blocal_props_r1_r",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B2_Blocal_props_r1_i("buf_snk_B2_Blocal_props_r1_i",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B2_Blocal_props_r1_r.tag_gpu_global();
    buf_snk_B2_Blocal_props_r1_i.tag_gpu_global();
    snk_B2_Blocal_r1_i_props_init.store_in(&buf_snk_B2_Blocal_props_r1_i, {y_out, jCprime, jSprime, y_in});
    snk_B2_Blocal_r1_r_props_init.store_in(&buf_snk_B2_Blocal_props_r1_r, {y_out, jCprime, jSprime, y_in});
    snk_B2_Blocal_r1_r_props.store_in(&buf_snk_B2_Blocal_props_r1_r, {y_out, jCprime, jSprime, y_in});
    snk_B2_Blocal_r1_i_props.store_in(&buf_snk_B2_Blocal_props_r1_i, {y_out, jCprime, jSprime, y_in});

    buffer buf_snk_B2_Blocal_r2_r("buf_snk_B2_Blocal_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B2_Blocal_r2_i("buf_snk_B2_Blocal_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B2_Blocal_r2_r.tag_gpu_global();
    buf_snk_B2_Blocal_r2_i.tag_gpu_global();
    snk_B2_Blocal_r2_r_init.store_in(&buf_snk_B2_Blocal_r2_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B2_Blocal_r2_i_init.store_in(&buf_snk_B2_Blocal_r2_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B2_Blocal_r2_r_update.store_in(&buf_snk_B2_Blocal_r2_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    snk_B2_Blocal_r2_i_update.store_in(&buf_snk_B2_Blocal_r2_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    buffer buf_flip_snk_B2_Blocal_r2_r("buf_flip_snk_B2_Blocal_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buffer buf_flip_snk_B2_Blocal_r2_i("buf_flip_snk_B2_Blocal_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, Nc, Ns, Nc, Ns, Nsnk, sites_per_rank}, p_float64, a_temporary);
    buf_flip_snk_B2_Blocal_r2_r.tag_gpu_global();
    buf_flip_snk_B2_Blocal_r2_i.tag_gpu_global();
    flip_snk_B2_Blocal_r2_r_init.store_in(&buf_flip_snk_B2_Blocal_r2_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B2_Blocal_r2_i_init.store_in(&buf_flip_snk_B2_Blocal_r2_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B2_Blocal_r2_r_update.store_in(&buf_flip_snk_B2_Blocal_r2_r, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    flip_snk_B2_Blocal_r2_i_update.store_in(&buf_flip_snk_B2_Blocal_r2_i, {y_out, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n, y_in});
    buffer buf_snk_B2_Blocal_diquark_r2_r("buf_snk_B2_Blocal_diquark_r2_r",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B2_Blocal_diquark_r2_i("buf_snk_B2_Blocal_diquark_r2_i",   {Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B2_Blocal_diquark_r2_r.tag_gpu_global();
    buf_snk_B2_Blocal_diquark_r2_i.tag_gpu_global();
    snk_B2_Blocal_r2_r_diquark.store_in(&buf_snk_B2_Blocal_diquark_r2_r, {y_out, y_in});
    snk_B2_Blocal_r2_i_diquark.store_in(&buf_snk_B2_Blocal_diquark_r2_i, {y_out, y_in});
    buffer buf_snk_B2_Blocal_props_r2_r("buf_snk_B2_Blocal_props_r2_r",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buffer buf_snk_B2_Blocal_props_r2_i("buf_snk_B2_Blocal_props_r2_i",   {Vsnk/sites_per_rank, Nc, Ns, sites_per_rank}, p_float64, a_temporary);
    buf_snk_B2_Blocal_props_r2_r.tag_gpu_global();
    buf_snk_B2_Blocal_props_r2_i.tag_gpu_global();
    snk_B2_Blocal_r2_r_props_init.store_in(&buf_snk_B2_Blocal_props_r2_r, {y_out, jCprime, jSprime, y_in});
    snk_B2_Blocal_r2_i_props_init.store_in(&buf_snk_B2_Blocal_props_r2_i, {y_out, jCprime, jSprime, y_in});
    snk_B2_Blocal_r2_r_props.store_in(&buf_snk_B2_Blocal_props_r2_r, {y_out, jCprime, jSprime, y_in});
    snk_B2_Blocal_r2_i_props.store_in(&buf_snk_B2_Blocal_props_r2_i, {y_out, jCprime, jSprime, y_in});
// 1755 - 2278

    /* Correlator */

    buffer buf_C_r("buf_C_r", {Lt, Vsnk/sites_per_rank, sites_per_rank, B2Nrows, NsrcTot, B2Nrows, NsnkTot}, p_float64, a_temporary);
    buffer buf_C_i("buf_C_i", {Lt, Vsnk/sites_per_rank, sites_per_rank, B2Nrows, NsrcTot, B2Nrows, NsnkTot}, p_float64, a_temporary);
    buf_C_r.tag_gpu_global();
    buf_C_i.tag_gpu_global();
    C_r.store_in(&buf_C_r);
    C_i.store_in(&buf_C_i);

    C_init_r.store_in(&buf_C_r, {t, x_out, x_in, rp, mpmH, r, npnH});
    C_init_i.store_in(&buf_C_i, {t, x_out, x_in, rp, mpmH, r, npnH});

    // BB_BB

    buffer* buf_BB_BB_new_term_r_b1;
    buffer* buf_BB_BB_new_term_i_b1;
    allocate_complex_buffers(buf_BB_BB_new_term_r_b1, buf_BB_BB_new_term_i_b1, {Lt, Vsnk, Vsnk}, "buf_BB_BB_new_term_b1", true);
    
    buffer* buf_BB_BB_new_term_r_b2;
    buffer* buf_BB_BB_new_term_i_b2;
    allocate_complex_buffers(buf_BB_BB_new_term_r_b2, buf_BB_BB_new_term_i_b2, {Lt, Vsnk, Vsnk}, "buf_BB_BB_new_term_b2", true); 

    BB_BB_new_term_0_r1_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_0_r1_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2});
    BB_BB_new_term_1_r1_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_1_r1_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2}); 
    BB_BB_new_term_2_r1_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_2_r1_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2});
    BB_BB_new_term_3_r1_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_3_r1_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2});
    BB_BB_new_term_4_r1_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_4_r1_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2});
    BB_BB_new_term_5_r1_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_5_r1_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2}); 
    BB_BB_new_term_6_r1_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_6_r1_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2});
    BB_BB_new_term_7_r1_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_7_r1_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2}); 

    BB_BB_new_term_0_r1_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_0_r1_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2});
    BB_BB_new_term_1_r1_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_1_r1_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2}); 
    BB_BB_new_term_2_r1_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_2_r1_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2});
    BB_BB_new_term_3_r1_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_3_r1_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2}); 
    BB_BB_new_term_4_r1_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_4_r1_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2});
    BB_BB_new_term_5_r1_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_5_r1_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2}); 
    BB_BB_new_term_6_r1_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_6_r1_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2});
    BB_BB_new_term_7_r1_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_7_r1_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2}); 

    BB_BB_new_term_0_r2_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_0_r2_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2});
    BB_BB_new_term_1_r2_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_1_r2_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2}); 
    BB_BB_new_term_2_r2_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_2_r2_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2});
    BB_BB_new_term_3_r2_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_3_r2_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2});
    BB_BB_new_term_4_r2_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_4_r2_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2});
    BB_BB_new_term_5_r2_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_5_r2_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2}); 
    BB_BB_new_term_6_r2_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_6_r2_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2});
    BB_BB_new_term_7_r2_b1.get_real()->store_in(buf_BB_BB_new_term_r_b1, {t, x1, x2});
    BB_BB_new_term_7_r2_b1.get_imag()->store_in(buf_BB_BB_new_term_i_b1, {t, x1, x2}); 

    BB_BB_new_term_0_r2_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_0_r2_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2});
    BB_BB_new_term_1_r2_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_1_r2_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2}); 
    BB_BB_new_term_2_r2_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_2_r2_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2});
    BB_BB_new_term_3_r2_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_3_r2_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2}); 
    BB_BB_new_term_4_r2_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_4_r2_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2});
    BB_BB_new_term_5_r2_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_5_r2_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2}); 
    BB_BB_new_term_6_r2_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_6_r2_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2});
    BB_BB_new_term_7_r2_b2.get_real()->store_in(buf_BB_BB_new_term_r_b2, {t, x1, x2});
    BB_BB_new_term_7_r2_b2.get_imag()->store_in(buf_BB_BB_new_term_i_b2, {t, x1, x2}); 

    buffer* buf_flip_BB_BB_new_term_r_b1;
    buffer* buf_flip_BB_BB_new_term_i_b1;
    allocate_complex_buffers(buf_flip_BB_BB_new_term_r_b1, buf_flip_BB_BB_new_term_i_b1, {Lt, Vsnk, Vsnk}, "buf_flip_BB_BB_new_term_b1", true);
    buffer* buf_flip_BB_BB_new_term_r_b2;
    buffer* buf_flip_BB_BB_new_term_i_b2;
    allocate_complex_buffers(buf_flip_BB_BB_new_term_r_b2, buf_flip_BB_BB_new_term_i_b2, {Lt, Vsnk, Vsnk}, "buf_flip_BB_BB_new_term_b2", true); 

    flip_BB_BB_new_term_0_r1_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_0_r1_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2});
    flip_BB_BB_new_term_1_r1_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_1_r1_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2}); 
    flip_BB_BB_new_term_2_r1_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_2_r1_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2});
    flip_BB_BB_new_term_3_r1_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_3_r1_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2});
    flip_BB_BB_new_term_4_r1_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_4_r1_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2});
    flip_BB_BB_new_term_5_r1_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_5_r1_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2}); 
    flip_BB_BB_new_term_6_r1_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_6_r1_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2});
    flip_BB_BB_new_term_7_r1_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_7_r1_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2}); 

    flip_BB_BB_new_term_0_r1_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_0_r1_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2});
    flip_BB_BB_new_term_1_r1_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_1_r1_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2}); 
    flip_BB_BB_new_term_2_r1_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_2_r1_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2});
    flip_BB_BB_new_term_3_r1_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_3_r1_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2}); 
    flip_BB_BB_new_term_4_r1_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_4_r1_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2});
    flip_BB_BB_new_term_5_r1_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_5_r1_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2}); 
    flip_BB_BB_new_term_6_r1_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_6_r1_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2});
    flip_BB_BB_new_term_7_r1_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_7_r1_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2}); 

    flip_BB_BB_new_term_0_r2_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_0_r2_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2});
    flip_BB_BB_new_term_1_r2_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_1_r2_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2}); 
    flip_BB_BB_new_term_2_r2_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_2_r2_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2});
    flip_BB_BB_new_term_3_r2_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_3_r2_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2});
    flip_BB_BB_new_term_4_r2_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_4_r2_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2});
    flip_BB_BB_new_term_5_r2_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_5_r2_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2}); 
    flip_BB_BB_new_term_6_r2_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_6_r2_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2});
    flip_BB_BB_new_term_7_r2_b1.get_real()->store_in(buf_flip_BB_BB_new_term_r_b1, {t, x1, x2});
    flip_BB_BB_new_term_7_r2_b1.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b1, {t, x1, x2}); 

    flip_BB_BB_new_term_0_r2_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_0_r2_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2});
    flip_BB_BB_new_term_1_r2_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_1_r2_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2}); 
    flip_BB_BB_new_term_2_r2_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_2_r2_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2});
    flip_BB_BB_new_term_3_r2_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_3_r2_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2}); 
    flip_BB_BB_new_term_4_r2_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_4_r2_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2});
    flip_BB_BB_new_term_5_r2_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_5_r2_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2}); 
    flip_BB_BB_new_term_6_r2_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_6_r2_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2});
    flip_BB_BB_new_term_7_r2_b2.get_real()->store_in(buf_flip_BB_BB_new_term_r_b2, {t, x1, x2});
    flip_BB_BB_new_term_7_r2_b2.get_imag()->store_in(buf_flip_BB_BB_new_term_i_b2, {t, x1, x2}); 
//
    buffer buf_C_BB_BB_prop_r("buf_C_BB_BB_prop_r", {Lt, Vsnk, B2Nrows, Nsrc, B2Nrows, Vsnk}, p_float64, a_temporary);
    buffer buf_C_BB_BB_prop_i("buf_C_BB_BB_prop_i", {Lt, Vsnk, B2Nrows, Nsrc, B2Nrows, Vsnk}, p_float64, a_temporary);

    buf_C_BB_BB_prop_r.tag_gpu_global();
    buf_C_BB_BB_prop_i.tag_gpu_global();

    C_BB_BB_prop_init_r.store_in(&buf_C_BB_BB_prop_r, {t, x1, rp, m, r, x2});
    C_BB_BB_prop_init_i.store_in(&buf_C_BB_BB_prop_i, {t, x1, rp, m, r, x2});
    C_BB_BB_prop_update_r.store_in(&buf_C_BB_BB_prop_r, {t, x1, rp, m, r, x2});
    C_BB_BB_prop_update_i.store_in(&buf_C_BB_BB_prop_i, {t, x1, rp, m, r, x2});
    C_BB_BB_prop_update_r_2.store_in(&buf_C_BB_BB_prop_r, {t, x1, rp, m, r, x2});
    C_BB_BB_prop_update_i_2.store_in(&buf_C_BB_BB_prop_i, {t, x1, rp, m, r, x2});



    C_BB_BB_update_b_r.store_in(&buf_C_BB_r, {t, x1, x2, rp, m, r, ne});
    C_BB_BB_update_b_i.store_in(&buf_C_BB_i, {t, x1, x2, rp, m, r, ne});
    C_BB_BB_update_s_r.store_in(&buf_C_BB_r, {t, x1, x2, rp, m, r, NEntangled+nue});
    C_BB_BB_update_s_i.store_in(&buf_C_BB_i, {t, x1, x2, rp, m, r, NEntangled+nue});

    // BB_H

    buffer* buf_BB_H_new_term_r_b1;
    buffer* buf_BB_H_new_term_i_b1;
    allocate_complex_buffers(buf_BB_H_new_term_r_b1, buf_BB_H_new_term_i_b1, {Lt, Vsnk/sites_per_rank, sites_per_rank}, "buf_BB_H_new_term_b1", true);

    BB_H_new_term_0_r1_b1.get_real()->store_in(buf_BB_H_new_term_r_b1, {t, x_out, x_in});
    BB_H_new_term_0_r1_b1.get_imag()->store_in(buf_BB_H_new_term_i_b1, {t, x_out, x_in});

    BB_H_new_term_0_r2_b1.get_real()->store_in(buf_BB_H_new_term_r_b1, {t, x_out, x_in});
    BB_H_new_term_0_r2_b1.get_imag()->store_in(buf_BB_H_new_term_i_b1, {t, x_out, x_in});

    buffer* buf_BB_H_new_term_r_b2;
    buffer* buf_BB_H_new_term_i_b2;
    allocate_complex_buffers(buf_BB_H_new_term_r_b2, buf_BB_H_new_term_i_b2, {Lt, Vsnk/sites_per_rank, sites_per_rank}, "buf_BB_H_new_term_b2", true);

    BB_H_new_term_0_r1_b2.get_real()->store_in(buf_BB_H_new_term_r_b2, {t, x_out, x_in});
    BB_H_new_term_0_r1_b2.get_imag()->store_in(buf_BB_H_new_term_i_b2, {t, x_out, x_in});

    BB_H_new_term_0_r2_b2.get_real()->store_in(buf_BB_H_new_term_r_b2, {t, x_out, x_in});
    BB_H_new_term_0_r2_b2.get_imag()->store_in(buf_BB_H_new_term_i_b2, {t, x_out, x_in});

    buffer* buf_flip_BB_H_new_term_r_b1;
    buffer* buf_flip_BB_H_new_term_i_b1;
    allocate_complex_buffers(buf_flip_BB_H_new_term_r_b1, buf_flip_BB_H_new_term_i_b1, {Lt, Vsnk/sites_per_rank, sites_per_rank}, "buf_flip_BB_H_new_term_b1", true);

    flip_BB_H_new_term_0_r1_b1.get_real()->store_in(buf_flip_BB_H_new_term_r_b1, {t, x_out, x_in});
    flip_BB_H_new_term_0_r1_b1.get_imag()->store_in(buf_flip_BB_H_new_term_i_b1, {t, x_out, x_in});

    flip_BB_H_new_term_0_r2_b1.get_real()->store_in(buf_flip_BB_H_new_term_r_b1, {t, x_out, x_in});
    flip_BB_H_new_term_0_r2_b1.get_imag()->store_in(buf_flip_BB_H_new_term_i_b1, {t, x_out, x_in});

    buffer* buf_flip_BB_H_new_term_r_b2;
    buffer* buf_flip_BB_H_new_term_i_b2;
    allocate_complex_buffers(buf_flip_BB_H_new_term_r_b2, buf_flip_BB_H_new_term_i_b2, {Lt, Vsnk/sites_per_rank, sites_per_rank}, "buf_flip_BB_H_new_term_b2", true);

    flip_BB_H_new_term_0_r1_b2.get_real()->store_in(buf_flip_BB_H_new_term_r_b2, {t, x_out, x_in});
    flip_BB_H_new_term_0_r1_b2.get_imag()->store_in(buf_flip_BB_H_new_term_i_b2, {t, x_out, x_in});

    flip_BB_H_new_term_0_r2_b2.get_real()->store_in(buf_flip_BB_H_new_term_r_b2, {t, x_out, x_in});
    flip_BB_H_new_term_0_r2_b2.get_imag()->store_in(buf_flip_BB_H_new_term_i_b2, {t, x_out, x_in});


    buffer buf_C_BB_H_prop_r("buf_C_BB_H_prop_r", {Lt, Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buffer buf_C_BB_H_prop_i("buf_C_BB_H_prop_i", {Lt, Vsnk/sites_per_rank, sites_per_rank}, p_float64, a_temporary);
    buf_C_BB_H_prop_r.tag_gpu_global();
    buf_C_BB_H_prop_i.tag_gpu_global();

    C_BB_H_prop_init_r.store_in(&buf_C_BB_H_prop_r, {t, x_out, x_in});
    C_BB_H_prop_init_i.store_in(&buf_C_BB_H_prop_i, {t, x_out, x_in});
    C_BB_H_prop_update_r.store_in(&buf_C_BB_H_prop_r, {t, x_out, x_in});
    C_BB_H_prop_update_i.store_in(&buf_C_BB_H_prop_i, {t, x_out, x_in}); 

    C_BB_H_update_r.store_in(&buf_C_r, {t, x_out, x_in, rp, m, r, Nsnk+nH});
    C_BB_H_update_i.store_in(&buf_C_i, {t, x_out, x_in, rp, m, r, Nsnk+nH});

    // H_BB

    buffer* buf_H_BB_new_term_r_b1;
    buffer* buf_H_BB_new_term_i_b1;
    allocate_complex_buffers(buf_H_BB_new_term_r_b1, buf_H_BB_new_term_i_b1, {Lt, Vsnk/sites_per_rank, sites_per_rank, 1}, "buf_H_BB_new_term_b1", true);

    H_BB_new_term_0_r1_b1.get_real()->store_in(buf_H_BB_new_term_r_b1, {t, y_out, y_in, 0});
    H_BB_new_term_0_r1_b1.get_imag()->store_in(buf_H_BB_new_term_i_b1, {t, y_out, y_in, 0});

    H_BB_new_term_0_r2_b1.get_real()->store_in(buf_H_BB_new_term_r_b1, {t, y_out, y_in, 0});
    H_BB_new_term_0_r2_b1.get_imag()->store_in(buf_H_BB_new_term_i_b1, {t, y_out, y_in, 0});

    buffer* buf_H_BB_new_term_r_b2;
    buffer* buf_H_BB_new_term_i_b2;
    allocate_complex_buffers(buf_H_BB_new_term_r_b2, buf_H_BB_new_term_i_b2, {Lt, Vsnk/sites_per_rank, sites_per_rank, 1}, "buf_H_BB_new_term_b2", true);

    H_BB_new_term_0_r1_b2.get_real()->store_in(buf_H_BB_new_term_r_b2, {t, y_out, y_in, 0});
    H_BB_new_term_0_r1_b2.get_imag()->store_in(buf_H_BB_new_term_i_b2, {t, y_out, y_in, 0});

    H_BB_new_term_0_r2_b2.get_real()->store_in(buf_H_BB_new_term_r_b2, {t, y_out, y_in, 0});
    H_BB_new_term_0_r2_b2.get_imag()->store_in(buf_H_BB_new_term_i_b2, {t, y_out, y_in, 0});

    buffer* buf_flip_H_BB_new_term_r_b1;
    buffer* buf_flip_H_BB_new_term_i_b1;
    allocate_complex_buffers(buf_flip_H_BB_new_term_r_b1, buf_flip_H_BB_new_term_i_b1, {Lt, Vsnk/sites_per_rank, sites_per_rank, 1}, "buf_flip_H_BB_new_term_b1", true);

    flip_H_BB_new_term_0_r1_b1.get_real()->store_in(buf_flip_H_BB_new_term_r_b1, {t, y_out, y_in, 0});
    flip_H_BB_new_term_0_r1_b1.get_imag()->store_in(buf_flip_H_BB_new_term_i_b1, {t, y_out, y_in, 0});

    flip_H_BB_new_term_0_r2_b1.get_real()->store_in(buf_flip_H_BB_new_term_r_b1, {t, y_out, y_in, 0});
    flip_H_BB_new_term_0_r2_b1.get_imag()->store_in(buf_flip_H_BB_new_term_i_b1, {t, y_out, y_in, 0});

    buffer* buf_flip_H_BB_new_term_r_b2;
    buffer* buf_flip_H_BB_new_term_i_b2;
    allocate_complex_buffers(buf_flip_H_BB_new_term_r_b2, buf_flip_H_BB_new_term_i_b2, {Lt, Vsnk/sites_per_rank, sites_per_rank, 1}, "buf_flip_H_BB_new_term_b2", true);

    flip_H_BB_new_term_0_r1_b2.get_real()->store_in(buf_flip_H_BB_new_term_r_b2, {t, y_out, y_in, 0});
    flip_H_BB_new_term_0_r1_b2.get_imag()->store_in(buf_flip_H_BB_new_term_i_b2, {t, y_out, y_in, 0});

    flip_H_BB_new_term_0_r2_b2.get_real()->store_in(buf_flip_H_BB_new_term_r_b2, {t, y_out, y_in, 0});
    flip_H_BB_new_term_0_r2_b2.get_imag()->store_in(buf_flip_H_BB_new_term_i_b2, {t, y_out, y_in, 0});

    buffer buf_C_H_BB_prop_r("buf_C_H_BB_prop_r", {Lt, Vsnk/sites_per_rank, sites_per_rank, 1}, p_float64, a_temporary);
    buffer buf_C_H_BB_prop_i("buf_C_H_BB_prop_i", {Lt, Vsnk/sites_per_rank, sites_per_rank, 1}, p_float64, a_temporary);
    buf_C_H_BB_prop_r.tag_gpu_global();
    buf_C_H_BB_prop_i.tag_gpu_global();

    C_H_BB_prop_init_r.store_in(&buf_C_H_BB_prop_r, {t, y_out, y_in, 0});
    C_H_BB_prop_init_i.store_in(&buf_C_H_BB_prop_i, {t, y_out, y_in, 0});
    C_H_BB_prop_update_r.store_in(&buf_C_H_BB_prop_r, {t, y_out, y_in, 0});
    C_H_BB_prop_update_i.store_in(&buf_C_H_BB_prop_i, {t, y_out, y_in, 0});

    buffer buff_H_BB_term_res_comp_r("buff_H_BB_term_res_comp_r", {Lt, Vsnk/sites_per_rank, sites_per_rank, 1}, p_float64, a_temporary);
    buffer buff_H_BB_term_res_comp_i("buff_H_BB_term_res_comp_i", {Lt, Vsnk/sites_per_rank, sites_per_rank, 1}, p_float64, a_temporary);
    buff_H_BB_term_res_comp_r.tag_gpu_global();
    buff_H_BB_term_res_comp_i.tag_gpu_global();

    H_BB_term_res_comp.get_imag()->store_in( &buff_H_BB_term_res_comp_r, {t, y_out, y_in, 0 } );
    H_BB_term_res_comp.get_real()->store_in( &buff_H_BB_term_res_comp_i, {t, y_out, y_in, 0 } );

    C_H_BB_update_r.store_in(&buf_C_r, {t, y_out, y_in, rp, Nsrc+mH, r, n});
    C_H_BB_update_i.store_in(&buf_C_i, {t, y_out, y_in, rp, Nsrc+mH, r, n});

    // H_H

    buffer buf_C_H_H_prop_r("buf_C_H_H_prop_r", {Lt, Vsnk/sites_per_rank, sites_per_rank, 1}, p_float64, a_temporary);
    buffer buf_C_H_H_prop_i("buf_C_H_H_prop_i", {Lt, Vsnk/sites_per_rank, sites_per_rank, 1}, p_float64, a_temporary);
    buf_C_H_H_prop_r.tag_gpu_global();
    buf_C_H_H_prop_i.tag_gpu_global();

    C_H_H_prop_init_r.store_in(&buf_C_H_H_prop_r, {t, x_out, x_in, 0});
    C_H_H_prop_init_i.store_in(&buf_C_H_H_prop_i, {t, x_out, x_in, 0});
    C_H_H_prop_update_r.store_in(&buf_C_H_H_prop_r, {t, x_out, x_in, 0});
    C_H_H_prop_update_i.store_in(&buf_C_H_H_prop_i, {t, x_out, x_in, 0});

    C_H_H_update_r.store_in(&buf_C_r, {t, x_out, x_in, rp, Nsrc+mH, r, Nsnk+nH});
    C_H_H_update_i.store_in(&buf_C_i, {t, x_out, x_in, rp, Nsrc+mH, r, Nsnk+nH});  

// --------------------------------------
    // {x1, x2} -> {x12_out, x12_in} // {block_count, threads_per_block}
    // x1 = (x12_out * thread_per_block + x12_in) / Vsrc
    // x2 = (x12_out * thread_per_block + x12_in) % Vsrc

    C_init_r.tag_gpu_level(x_out, x_in);
    C_init_i.tag_gpu_level(x_out, x_in);

    // BB_BB
    C_BB_init_r.tag_gpu_level(x1, x2);
    C_BB_init_i.tag_gpu_level(x1, x2);
    B1_Blocal_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Blocal_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Blocal_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bfirst_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bfirst_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bsecond_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bsecond_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bthird_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bthird_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);

    B1_Blocal_r1_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r1_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r1_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r1_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r1_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r1_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r1_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r1_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);

    B1_Blocal_r1_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r1_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r1_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r1_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r1_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r1_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);

    B1_Blocal_r1_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r1_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r1_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r1_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r1_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r1_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r1_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r1_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);

    B1_Blocal_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Blocal_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Blocal_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bfirst_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bfirst_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bsecond_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bsecond_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bthird_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bthird_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Blocal_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Blocal_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bfirst_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bfirst_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bsecond_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bsecond_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bthird_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bthird_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r2_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r2_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r2_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r2_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r2_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r2_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r2_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r2_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r2_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r2_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r2_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r2_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r2_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r2_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r2_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r2_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r2_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r2_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r2_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r2_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r2_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r2_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Blocal_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bfirst_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bsecond_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B1_Bthird_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Blocal_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Blocal_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bfirst_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bfirst_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bsecond_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bsecond_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bthird_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B1_Bthird_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Blocal_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Blocal_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bfirst_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bfirst_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bsecond_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bsecond_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bthird_r1_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bthird_r1_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r1_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r1_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r1_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r1_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r1_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r1_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r1_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r1_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r1_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r1_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r1_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r1_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r1_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r1_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r1_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r1_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r1_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r1_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r1_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r1_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r1_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r1_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Blocal_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Blocal_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bfirst_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bfirst_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bsecond_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bsecond_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bthird_r1_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bthird_r1_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Blocal_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Blocal_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bfirst_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bfirst_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bsecond_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bsecond_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bthird_r2_r_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bthird_r2_i_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r2_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r2_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r2_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r2_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r2_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r2_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r2_r_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r2_i_props_init.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r2_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r2_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r2_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r2_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r2_r_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r2_i_diquark.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r2_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r2_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r2_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r2_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r2_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r2_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r2_r_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r2_i_props.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Blocal_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bfirst_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime); 
    B2_Bsecond_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bsecond_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    B2_Bthird_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime); 
    flip_B2_Blocal_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Blocal_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bfirst_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bfirst_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime); 
    flip_B2_Bsecond_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bsecond_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bthird_r2_r_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime);
    flip_B2_Bthird_r2_i_update.tag_gpu_level(x1, iCprime, iSprime, x2, kCprime, kSprime); 
    C_BB_BB_prop_init_r.tag_gpu_level(x1, x2);
    C_BB_BB_prop_init_i.tag_gpu_level(x1, x2);
          BB_BB_new_term_0_r1_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_0_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_1_r1_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_1_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_2_r1_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_2_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_3_r1_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_3_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_4_r1_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_4_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_5_r1_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_5_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_6_r1_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_6_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_7_r1_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_7_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_0_r2_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_0_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_1_r2_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_1_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_2_r2_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_2_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_3_r2_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_3_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_4_r2_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_4_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_5_r2_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_5_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_6_r2_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_6_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_7_r2_b1.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_7_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_0_r1_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_0_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_1_r1_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_1_r1_b2.get_imag()->tag_gpu_level(x1, x2); 
          BB_BB_new_term_2_r1_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_2_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_3_r1_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_3_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_4_r1_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_4_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_5_r1_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_5_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_6_r1_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_6_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_7_r1_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_7_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_0_r2_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_0_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_1_r2_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_1_r2_b2.get_imag()->tag_gpu_level(x1, x2); 
          BB_BB_new_term_2_r2_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_2_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_3_r2_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_3_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_4_r2_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_4_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_5_r2_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_5_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_6_r2_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_6_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          BB_BB_new_term_7_r2_b2.get_real()->tag_gpu_level(x1, x2);
          BB_BB_new_term_7_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_0_r1_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_0_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_1_r1_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_1_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_2_r1_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_2_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_3_r1_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_3_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_4_r1_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_4_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_5_r1_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_5_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_6_r1_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_6_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_7_r1_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_7_r1_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_0_r2_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_0_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_1_r2_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_1_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_2_r2_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_2_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_3_r2_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_3_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_4_r2_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_4_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_5_r2_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_5_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_6_r2_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_6_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_7_r2_b1.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_7_r2_b1.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_0_r1_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_0_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_1_r1_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_1_r1_b2.get_imag()->tag_gpu_level(x1, x2); 
          flip_BB_BB_new_term_2_r1_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_2_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_3_r1_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_3_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_4_r1_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_4_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_5_r1_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_5_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_6_r1_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_6_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_7_r1_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_7_r1_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_0_r2_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_0_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_1_r2_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_1_r2_b2.get_imag()->tag_gpu_level(x1, x2); 
          flip_BB_BB_new_term_2_r2_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_2_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_3_r2_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_3_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_4_r2_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_4_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_5_r2_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_5_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_6_r2_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_6_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_7_r2_b2.get_real()->tag_gpu_level(x1, x2);
          flip_BB_BB_new_term_7_r2_b2.get_imag()->tag_gpu_level(x1, x2);
          C_BB_BB_prop_update_r.tag_gpu_level(x1, x2);
          C_BB_BB_prop_update_i.tag_gpu_level(x1, x2);
          C_BB_BB_prop_update_r_2.tag_gpu_level(x1, x2);
          C_BB_BB_prop_update_i_2.tag_gpu_level(x1, x2);

          C_BB_BB_update_b_r.tag_gpu_level(x1, x2); 
          C_BB_BB_update_b_i.tag_gpu_level(x1, x2);
          C_BB_BB_update_s_r.tag_gpu_level(x1, x2); 
          C_BB_BB_update_s_i.tag_gpu_level(x1, x2);

    // BB_H
          src_B1_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
          flip_src_B1_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
          flip_src_B1_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r1_r_props_init.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r1_i_props_init.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r1_r_diquark.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r1_i_diquark.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r1_r_props.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r1_i_props.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
          flip_src_B1_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
          flip_src_B1_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
          
          src_B1_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
          flip_src_B1_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
          flip_src_B1_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r2_r_props_init.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r2_i_props_init.tag_gpu_level(x_out, x_in);

          src_B1_Blocal_r2_r_diquark.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r2_i_diquark.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r2_r_props.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r2_i_props.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
          src_B1_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);
          flip_src_B1_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
          flip_src_B1_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);

          src_B2_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
          flip_src_B2_Blocal_r1_r_init.tag_gpu_level(x_out, x_in);
          flip_src_B2_Blocal_r1_i_init.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r1_r_props_init.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r1_i_props_init.tag_gpu_level(x_out, x_in);

          src_B2_Blocal_r1_r_diquark.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r1_i_diquark.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r1_r_props.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r1_i_props.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);
          flip_src_B2_Blocal_r1_r_update.tag_gpu_level(x_out, x_in);
          flip_src_B2_Blocal_r1_i_update.tag_gpu_level(x_out, x_in);

          src_B2_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
          flip_src_B2_Blocal_r2_r_init.tag_gpu_level(x_out, x_in);
          flip_src_B2_Blocal_r2_i_init.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r2_r_props_init.tag_gpu_level(x_out, x_in);
        //   {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime}
          src_B2_Blocal_r2_i_props_init.tag_gpu_level(x_out, x_in);
        //   {t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, y, wnumBlock}
          src_B2_Blocal_r2_r_diquark.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r2_i_diquark.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r2_r_props.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r2_i_props.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
          src_B2_Blocal_r2_i_update.tag_gpu_level(x_out, x_in);
          flip_src_B2_Blocal_r2_r_update.tag_gpu_level(x_out, x_in);
          flip_src_B2_Blocal_r2_i_update.tag_gpu_level(x_out, x_in); 
          C_BB_H_prop_init_r.tag_gpu_level(x_out, x_in);
          C_BB_H_prop_init_i.tag_gpu_level(x_out, x_in); 
          BB_H_new_term_0_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
          BB_H_new_term_0_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
          BB_H_new_term_0_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
          BB_H_new_term_0_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
          BB_H_new_term_0_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
          BB_H_new_term_0_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
          BB_H_new_term_0_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
          BB_H_new_term_0_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
          flip_BB_H_new_term_0_r1_b1.get_real()->tag_gpu_level(x_out, x_in);
          flip_BB_H_new_term_0_r1_b1.get_imag()->tag_gpu_level(x_out, x_in);
          flip_BB_H_new_term_0_r2_b1.get_real()->tag_gpu_level(x_out, x_in);
          flip_BB_H_new_term_0_r2_b1.get_imag()->tag_gpu_level(x_out, x_in);
          flip_BB_H_new_term_0_r1_b2.get_real()->tag_gpu_level(x_out, x_in);
          flip_BB_H_new_term_0_r1_b2.get_imag()->tag_gpu_level(x_out, x_in);
          flip_BB_H_new_term_0_r2_b2.get_real()->tag_gpu_level(x_out, x_in);
          flip_BB_H_new_term_0_r2_b2.get_imag()->tag_gpu_level(x_out, x_in);
          C_BB_H_prop_update_r.tag_gpu_level(x_out, x_in); 
          C_BB_H_prop_update_i.tag_gpu_level(x_out, x_in); 
          C_BB_H_update_r.tag_gpu_level(x_out, x_in); 
          C_BB_H_update_i.tag_gpu_level(x_out, x_in);

    // H_BB
          snk_B1_Blocal_r1_r_init.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r1_i_init.tag_gpu_level(y_out, y_in); // 
          flip_snk_B1_Blocal_r1_r_init.tag_gpu_level(y_out, y_in); //
          flip_snk_B1_Blocal_r1_i_init.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r1_r_props_init.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r1_i_props_init.tag_gpu_level(y_out, y_in); //

          snk_B1_Blocal_r1_r_diquark.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r1_i_diquark.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r1_r_props.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r1_i_props.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r1_r_update.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r1_i_update.tag_gpu_level(y_out, y_in); //
          flip_snk_B1_Blocal_r1_r_update.tag_gpu_level(y_out, y_in); //
          flip_snk_B1_Blocal_r1_i_update.tag_gpu_level(y_out, y_in); //

          snk_B1_Blocal_r2_r_init.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r2_i_init.tag_gpu_level(y_out, y_in); //
          flip_snk_B1_Blocal_r2_r_init.tag_gpu_level(y_out, y_in); //
          flip_snk_B1_Blocal_r2_i_init.tag_gpu_level(y_out, y_in); // 
          snk_B1_Blocal_r2_r_props_init.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r2_i_props_init.tag_gpu_level(y_out, y_in); //

          snk_B1_Blocal_r2_r_diquark.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r2_i_diquark.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r2_r_props.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r2_i_props.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r2_r_update.tag_gpu_level(y_out, y_in); //
          snk_B1_Blocal_r2_i_update.tag_gpu_level(y_out, y_in); // 
          flip_snk_B1_Blocal_r2_r_update.tag_gpu_level(y_out, y_in); //
          flip_snk_B1_Blocal_r2_i_update.tag_gpu_level(y_out, y_in); //

          snk_B2_Blocal_r1_r_init.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r1_i_init.tag_gpu_level(y_out, y_in); //
          flip_snk_B2_Blocal_r1_r_init.tag_gpu_level(y_out, y_in); //
          flip_snk_B2_Blocal_r1_i_init.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r1_r_props_init.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r1_i_props_init.tag_gpu_level(y_out, y_in); //
          
          snk_B2_Blocal_r1_r_diquark.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r1_i_diquark.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r1_r_props.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r1_i_props.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r1_r_update.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r1_i_update.tag_gpu_level(y_out, y_in); //
          flip_snk_B2_Blocal_r1_r_update.tag_gpu_level(y_out, y_in); //
          flip_snk_B2_Blocal_r1_i_update.tag_gpu_level(y_out, y_in); //
          
          snk_B2_Blocal_r2_r_init.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r2_i_init.tag_gpu_level(y_out, y_in); //
          flip_snk_B2_Blocal_r2_r_init.tag_gpu_level(y_out, y_in); //
          flip_snk_B2_Blocal_r2_i_init.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r2_r_props_init.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r2_i_props_init.tag_gpu_level(y_out, y_in); //
          
          snk_B2_Blocal_r2_r_diquark.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r2_i_diquark.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r2_r_props.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r2_i_props.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r2_r_update.tag_gpu_level(y_out, y_in); //
          snk_B2_Blocal_r2_i_update.tag_gpu_level(y_out, y_in); //
          flip_snk_B2_Blocal_r2_r_update.tag_gpu_level(y_out, y_in); //
          flip_snk_B2_Blocal_r2_i_update.tag_gpu_level(y_out, y_in); //

          C_H_BB_prop_init_r.tag_gpu_level(y_out, y_in); //
          C_H_BB_prop_init_i.tag_gpu_level(y_out, y_in); //
          H_BB_new_term_0_r1_b1.get_real()->tag_gpu_level(y_out, y_in);
          H_BB_new_term_0_r1_b1.get_imag()->tag_gpu_level(y_out, y_in);
          H_BB_new_term_0_r2_b1.get_real()->tag_gpu_level(y_out, y_in);
          H_BB_new_term_0_r2_b1.get_imag()->tag_gpu_level(y_out, y_in);
          H_BB_new_term_0_r1_b2.get_real()->tag_gpu_level(y_out, y_in);
          H_BB_new_term_0_r1_b2.get_imag()->tag_gpu_level(y_out, y_in);
          H_BB_new_term_0_r2_b2.get_real()->tag_gpu_level(y_out, y_in);
          H_BB_new_term_0_r2_b2.get_imag()->tag_gpu_level(y_out, y_in);
          flip_H_BB_new_term_0_r1_b1.get_real()->tag_gpu_level(y_out, y_in);
          flip_H_BB_new_term_0_r1_b1.get_imag()->tag_gpu_level(y_out, y_in);
          flip_H_BB_new_term_0_r2_b1.get_real()->tag_gpu_level(y_out, y_in);
          flip_H_BB_new_term_0_r2_b1.get_imag()->tag_gpu_level(y_out, y_in);
          flip_H_BB_new_term_0_r1_b2.get_real()->tag_gpu_level(y_out, y_in);
          flip_H_BB_new_term_0_r1_b2.get_imag()->tag_gpu_level(y_out, y_in);
          flip_H_BB_new_term_0_r2_b2.get_real()->tag_gpu_level(y_out, y_in);
          flip_H_BB_new_term_0_r2_b2.get_imag()->tag_gpu_level(y_out, y_in);
          H_BB_term_res_comp.get_real()->tag_gpu_level( y_out, y_in );
          H_BB_term_res_comp.get_imag()->tag_gpu_level( y_out, y_in );
          C_H_BB_prop_update_r.tag_gpu_level(y_out, y_in);
          C_H_BB_prop_update_i.tag_gpu_level(y_out, y_in);
          C_H_BB_update_r.tag_gpu_level(y_out, y_in); 
          C_H_BB_update_i.tag_gpu_level(y_out, y_in); 

    // H_H
          C_H_H_prop_init_r.tag_gpu_level(x_out, x_in);
          C_H_H_prop_init_i.tag_gpu_level(x_out, x_in);
          C_H_H_prop_update_r.tag_gpu_level(x_out, x_in); 
          C_H_H_prop_update_i.tag_gpu_level(x_out, x_in);
          C_H_H_update_r.tag_gpu_level(x_out, x_in); 
          C_H_H_update_i.tag_gpu_level(x_out, x_in); 

    // -------------------------------------------------------
    // Layer II
    // -------------------------------------------------------

    computation copy_buf_C_r_host_to_device({}, memcpy(buf_C_r_cpu, buf_C_r));
    computation copy_buf_C_i_host_to_device({}, memcpy(buf_C_i_cpu, buf_C_i));
    computation copy_B1_prop_r_host_to_device({}, memcpy(buf_B1_prop_r_cpu, buf_B1_prop_r_gpu));
    computation copy_B1_prop_i_host_to_device({}, memcpy(buf_B1_prop_i_cpu, buf_B1_prop_i_gpu));
    computation copy_B2_prop_r_host_to_device({}, memcpy(buf_B2_prop_r_cpu, buf_B2_prop_r_gpu));
    computation copy_B2_prop_i_host_to_device({}, memcpy(buf_B2_prop_i_cpu, buf_B2_prop_i_gpu));
    computation copy_src_psi_B1_r_host_to_device({}, memcpy(buf_src_psi_B1_r_cpu, buf_src_psi_B1_r_gpu));
    computation copy_src_psi_B1_i_host_to_device({}, memcpy(buf_src_psi_B1_i_cpu, buf_src_psi_B1_i_gpu));
    computation copy_src_psi_B2_r_host_to_device({}, memcpy(buf_src_psi_B2_r_cpu, buf_src_psi_B2_r_gpu));
    computation copy_src_psi_B2_i_host_to_device({}, memcpy(buf_src_psi_B2_i_cpu, buf_src_psi_B2_i_gpu));
    computation copy_snk_psi_B1_r_host_to_device({}, memcpy(buf_snk_psi_B1_r_cpu, buf_snk_psi_B1_r_gpu));
    computation copy_snk_psi_B1_i_host_to_device({}, memcpy(buf_snk_psi_B1_i_cpu, buf_snk_psi_B1_i_gpu));
    computation copy_snk_psi_B2_r_host_to_device({}, memcpy(buf_snk_psi_B2_r_cpu, buf_snk_psi_B2_r_gpu));
    computation copy_snk_psi_B2_i_host_to_device({}, memcpy(buf_snk_psi_B2_i_cpu, buf_snk_psi_B2_i_gpu));
    
    computation copy_hex_src_psi_r_host_to_device( {}, memcpy( buf_hex_src_psi_r_cpu,  buf_hex_src_psi_r_gpu ) );
    computation copy_hex_src_psi_i_host_to_device( {}, memcpy( buf_hex_src_psi_i_cpu,  buf_hex_src_psi_i_gpu ) );

    computation copy_src_spins_host_to_device({}, memcpy(buf_src_spins_cpu, buf_src_spins_gpu));
    computation copy_sigs_host_to_device({}, memcpy(buf_sigs_cpu, buf_sigs_gpu));
    computation copy_snk_psi_r_host_to_device({}, memcpy(buf_snk_psi_r_cpu, buf_snk_psi_r_gpu));
    computation copy_snk_psi_i_host_to_device({}, memcpy(buf_snk_psi_i_cpu, buf_snk_psi_i_gpu));
    computation copy_hex_snk_psi_r_host_to_device({}, memcpy(buf_hex_snk_psi_r_cpu, buf_hex_snk_psi_r_gpu));
    computation copy_hex_snk_psi_i_host_to_device({}, memcpy(buf_hex_snk_psi_i_cpu, buf_hex_snk_psi_i_gpu));
    computation copy_src_color_weights_host_to_device({}, memcpy(buf_src_color_weights_cpu, buf_src_color_weights_gpu));
    computation copy_src_spin_weights_host_to_device({}, memcpy(buf_src_spin_weights_cpu, buf_src_spin_weights_gpu));
    computation copy_src_weights_host_to_device({}, memcpy(buf_src_weights_cpu, buf_src_weights_gpu));
    computation copy_snk_color_weights_host_to_device({}, memcpy(buf_snk_color_weights_cpu, buf_snk_color_weights_gpu));
    computation copy_snk_spin_weights_host_to_device({}, memcpy(buf_snk_spin_weights_cpu, buf_snk_spin_weights_gpu));
    computation copy_snk_weights_host_to_device({}, memcpy(buf_snk_weights_cpu, buf_snk_weights_gpu));
    computation copy_hex_snk_color_weights_host_to_device({}, memcpy(buf_hex_snk_color_weights_cpu, buf_hex_snk_color_weights_gpu));
    computation copy_hex_snk_spin_weights_host_to_device({}, memcpy(buf_hex_snk_spin_weights_cpu, buf_hex_snk_spin_weights_gpu));
    computation copy_hex_snk_weights_host_to_device({}, memcpy(buf_hex_snk_weights_cpu, buf_hex_snk_weights_gpu));
    computation copy_src_spin_block_weights_host_to_device({}, memcpy(buf_src_spin_block_weights_cpu, buf_src_spin_block_weights_gpu));
    computation copy_snk_b_host_to_device({}, memcpy(buf_snk_b_cpu, buf_snk_b_gpu));

    computation copy_buf_C_r_device_to_host({}, memcpy(buf_C_r, buf_C_r_cpu));
    computation copy_buf_C_i_device_to_host({}, memcpy(buf_C_i, buf_C_i_cpu));
    // computation copy_B1_prop_r_device_to_host({}, memcpy(*B1_prop_r.get_buffer(), buf_B1_prop_r_cpu));
    // computation copy_B1_prop_i_device_to_host({}, memcpy(*B1_prop_i.get_buffer(), buf_B1_prop_i_cpu));
    // computation copy_B2_prop_r_device_to_host({}, memcpy(*B2_prop_r.get_buffer(), buf_B2_prop_r_cpu));
    // computation copy_B2_prop_i_device_to_host({}, memcpy(*B2_prop_i.get_buffer(), buf_B2_prop_i_cpu));
    // computation copy_src_psi_B1_r_device_to_host({}, memcpy(*src_psi_B1_r.get_buffer(), buf_src_psi_B1_r_cpu));
    // computation copy_src_psi_B1_i_device_to_host({}, memcpy(*src_psi_B1_i.get_buffer(), buf_src_psi_B1_i_cpu));
    // computation copy_src_psi_B2_r_device_to_host({}, memcpy(*src_psi_B2_r.get_buffer(), buf_src_psi_B2_r_cpu));
    // computation copy_src_psi_B2_i_device_to_host({}, memcpy(*src_psi_B2_i.get_buffer(), buf_src_psi_B2_i_cpu));
    // computation copy_snk_psi_B1_r_device_to_host({}, memcpy(*snk_psi_B1_r.get_buffer(), buf_snk_psi_B1_r_cpu));
    // computation copy_snk_psi_B1_i_device_to_host({}, memcpy(*snk_psi_B1_i.get_buffer(), buf_snk_psi_B1_i_cpu));
    // computation copy_snk_psi_B2_r_device_to_host({}, memcpy(*snk_psi_B2_r.get_buffer(), buf_snk_psi_B2_r_cpu));
    // computation copy_snk_psi_B2_i_device_to_host({}, memcpy(*snk_psi_B2_i.get_buffer(), buf_snk_psi_B2_i_cpu));
    // computation copy_hex_src_psi_r_device_to_host( {}, memcpy( buf_hex_src_psi_r_gpu, buf_hex_src_psi_r_cpu ) );
    // computation copy_hex_src_psi_i_device_to_host( {}, memcpy( buf_hex_src_psi_i_gpu, buf_hex_src_psi_i_cpu ) );
    // computation copy_src_spins_device_to_host({}, memcpy(*src_spins.get_buffer(), buf_src_spins_cpu));
    // computation copy_sigs_device_to_host({}, memcpy(*sigs.get_buffer(), buf_sigs_cpu));
    // computation copy_snk_psi_r_device_to_host({}, memcpy(*snk_psi_r.get_buffer(), buf_snk_psi_r_cpu));
    // computation copy_snk_psi_i_device_to_host({}, memcpy(*snk_psi_i.get_buffer(), buf_snk_psi_i_cpu));
    // computation copy_hex_snk_psi_r_device_to_host({}, memcpy(*hex_snk_psi_r.get_buffer(), buf_hex_snk_psi_r_cpu));
    // computation copy_hex_snk_psi_i_device_to_host({}, memcpy(*hex_snk_psi_i.get_buffer(), buf_hex_snk_psi_i_cpu));
    // computation copy_src_color_weights_device_to_host({}, memcpy(*src_color_weights.get_buffer(), buf_src_color_weights_cpu));
    // computation copy_src_spin_weights_device_to_host({}, memcpy(*src_spin_weights.get_buffer(), buf_src_spin_weights_cpu));
    // computation copy_src_weights_device_to_host({}, memcpy(*src_weights.get_buffer(), buf_src_weights_cpu));
    // computation copy_snk_color_weights_device_to_host({}, memcpy(*snk_color_weights.get_buffer(), buf_snk_color_weights_cpu));
    // computation copy_snk_spin_weights_device_to_host({}, memcpy(*snk_spin_weights.get_buffer(), buf_snk_spin_weights_cpu));
    // computation copy_snk_weights_device_to_host({}, memcpy(*snk_weights.get_buffer(), buf_snk_weights_cpu));
    // computation copy_hex_snk_color_weights_device_to_host({}, memcpy(*hex_snk_color_weights.get_buffer(), buf_hex_snk_color_weights_cpu));
    // computation copy_hex_snk_spin_weights_device_to_host({}, memcpy(*hex_snk_spin_weights.get_buffer(), buf_hex_snk_spin_weights_cpu));
    // computation copy_hex_snk_weights_device_to_host({}, memcpy(*hex_snk_weights.get_buffer(), buf_hex_snk_weights_cpu));
    // computation copy_src_spin_block_weights_device_to_host({}, memcpy(*src_spin_block_weights.get_buffer(), buf_src_spin_block_weights_cpu));
    // computation copy_snk_b_device_to_host({}, memcpy(*snk_b.get_buffer(), buf_snk_b_cpu));

    computation copy_buf_C_BB_r_device_to_host({}, memcpy(buf_C_BB_r, buf_C_BB_r_cpu));
    computation copy_buf_C_BB_i_device_to_host({}, memcpy(buf_C_BB_i, buf_C_BB_i_cpu));
    
    computation* handle = &(copy_buf_C_r_host_to_device
        .then(copy_buf_C_i_host_to_device, computation::root)
        .then(copy_B1_prop_r_host_to_device, computation::root)
        .then(copy_B1_prop_i_host_to_device, computation::root)
        .then(copy_B2_prop_r_host_to_device, computation::root)
        .then(copy_B2_prop_i_host_to_device, computation::root)
        .then(copy_src_psi_B1_r_host_to_device, computation::root)
        .then(copy_src_psi_B1_i_host_to_device, computation::root)
        .then(copy_src_psi_B2_r_host_to_device, computation::root)
        .then(copy_src_psi_B2_i_host_to_device, computation::root)
        .then(copy_snk_psi_B1_r_host_to_device, computation::root)
        .then(copy_snk_psi_B1_i_host_to_device, computation::root)
        .then(copy_snk_psi_B2_r_host_to_device, computation::root)
        .then(copy_snk_psi_B2_i_host_to_device, computation::root)
        .then(copy_hex_src_psi_r_host_to_device, computation::root)
        .then(copy_hex_src_psi_i_host_to_device, computation::root)
        .then(copy_src_spins_host_to_device, computation::root)
        .then(copy_sigs_host_to_device, computation::root)
        .then(copy_snk_psi_r_host_to_device, computation::root)
        .then(copy_snk_psi_i_host_to_device, computation::root)
        .then(copy_hex_snk_psi_r_host_to_device, computation::root)
        .then(copy_hex_snk_psi_i_host_to_device, computation::root)
        .then(copy_src_color_weights_host_to_device, computation::root)
        .then(copy_src_spin_weights_host_to_device, computation::root)
        .then(copy_src_weights_host_to_device, computation::root)
        .then(copy_snk_color_weights_host_to_device, computation::root)
        .then(copy_snk_spin_weights_host_to_device, computation::root)
        .then(copy_snk_weights_host_to_device, computation::root)
        .then(copy_hex_snk_color_weights_host_to_device, computation::root)
        .then(copy_hex_snk_spin_weights_host_to_device, computation::root)
        .then(copy_hex_snk_weights_host_to_device, computation::root)
        .then(copy_src_spin_block_weights_host_to_device, computation::root)
        .then(copy_snk_b_host_to_device, computation::root)
        );

    handle = &(handle->then( C_init_r, computation::root ).then( C_init_i, npnH ));

    // BB_BB
// kernel_1
    handle = &(handle
          ->then(C_BB_init_r, computation::root )
          .then(C_BB_init_i, n)
        //   .then( *allocate_buf_B1_Blocal_r1_r, t )
        //   .then( *allocate_buf_B1_Blocal_r1_i, t )
        //   .then( *allocate_buf_B1_Bfirst_r1_r, t )
        //   .then( *allocate_buf_B1_Bfirst_r1_i, t )
        //   .then( *allocate_buf_B1_Bsecond_r1_r, t )
        //   .then( *allocate_buf_B1_Bsecond_r1_i, t )
        //   .then( *allocate_buf_B1_Bthird_r1_r, t )
        //   .then( *allocate_buf_B1_Bthird_r1_i, t )
// kernel_2
          .then(B1_Blocal_r1_r_init, computation::root ) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m
          .then(B1_Blocal_r1_i_init, m) 
          .then(B1_Bfirst_r1_r_init, m)
          .then(B1_Bfirst_r1_i_init, m)
          .then(B1_Bsecond_r1_r_init, m)
          .then(B1_Bsecond_r1_i_init, m)
          .then(B1_Bthird_r1_r_init, m)
          .then(B1_Bthird_r1_i_init, m)
// kernel_3
        //   .then( *allocate_buf_flip_B1_Blocal_r1_r, t)
        //   .then( *allocate_buf_flip_B1_Blocal_r1_i, t)
        //   .then( *allocate_buf_flip_B1_Bfirst_r1_r, t)
        //   .then( *allocate_buf_flip_B1_Bfirst_r1_i, t)
        //   .then( *allocate_buf_flip_B1_Bsecond_r1_r, t)
        //   .then( *allocate_buf_flip_B1_Bsecond_r1_i, t)
        //   .then( *allocate_buf_flip_B1_Bthird_r1_r, t)
        //   .then( *allocate_buf_flip_B1_Bthird_r1_i, t)
          .then(flip_B1_Blocal_r1_r_init, t)
          .then(flip_B1_Blocal_r1_i_init, m)
          .then(flip_B1_Bfirst_r1_r_init, m)
          .then(flip_B1_Bfirst_r1_i_init, m)
          .then(flip_B1_Bsecond_r1_r_init, m)
          .then(flip_B1_Bsecond_r1_i_init, m)
          .then(flip_B1_Bthird_r1_r_init, m)
          .then(flip_B1_Bthird_r1_i_init, m)
// kernel_4
          .then( *allocate_buf_B1_Blocal_props_r1_r, computation::root )
          .then( *allocate_buf_B1_Blocal_props_r1_i, t)
          .then( *allocate_buf_B1_Bfirst_props_r1_r, t)
          .then( *allocate_buf_B1_Bfirst_props_r1_i, t)
          .then( *allocate_buf_B1_Bsecond_props_r1_r, t)
          .then( *allocate_buf_B1_Bsecond_props_r1_i, t)
          .then( *allocate_buf_B1_Bthird_props_r1_r, t)
          .then( *allocate_buf_B1_Bthird_props_r1_i, t)
// 
          .then(B1_Blocal_r1_r_props_init, t ) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime
          .then(B1_Blocal_r1_i_props_init, jSprime)
          .then(B1_Bfirst_r1_r_props_init, jSprime)
          .then(B1_Bfirst_r1_i_props_init, jSprime)
          .then(B1_Bsecond_r1_r_props_init, jSprime)
          .then(B1_Bsecond_r1_i_props_init, jSprime)
          .then(B1_Bthird_r1_r_props_init, jSprime)
          .then(B1_Bthird_r1_i_props_init, jSprime)

          .then(B1_Blocal_r1_r_diquark, y) // {t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock}
          .then(B1_Blocal_r1_i_diquark, wnumBlock)
          .then(B1_Bfirst_r1_r_diquark, wnumBlock)
          .then(B1_Bfirst_r1_i_diquark, wnumBlock)
          .then(B1_Bthird_r1_r_diquark, wnumBlock)
          .then(B1_Bthird_r1_i_diquark, wnumBlock)
          
          .then(B1_Blocal_r1_r_props, wnumBlock) // // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime
          .then(B1_Blocal_r1_i_props, jSprime) 
          .then(B1_Bfirst_r1_r_props, jSprime)
          .then(B1_Bfirst_r1_i_props, jSprime)
          .then(B1_Bsecond_r1_r_props, jSprime)
          .then(B1_Bsecond_r1_i_props, jSprime)
          .then(B1_Bthird_r1_r_props, jSprime)
          .then(B1_Bthird_r1_i_props, jSprime)
// this should be a new kernel
// kernel_5
          .then(B1_Blocal_r1_r_update, t) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m
          .then(B1_Blocal_r1_i_update, m)
          .then(B1_Bfirst_r1_r_update, m)
          .then(B1_Bfirst_r1_i_update, m)
          .then(B1_Bsecond_r1_r_update, m)
          .then(B1_Bsecond_r1_i_update, m)
          .then(B1_Bthird_r1_r_update, m)
          .then(B1_Bthird_r1_i_update, m)
// kernel_6
          .then(flip_B1_Blocal_r1_r_update, t)
          .then(flip_B1_Blocal_r1_i_update, m)
          .then(flip_B1_Bfirst_r1_r_update, m)
          .then(flip_B1_Bfirst_r1_i_update, m)
          .then(flip_B1_Bsecond_r1_r_update, m)
          .then(flip_B1_Bsecond_r1_i_update, m)
          .then(flip_B1_Bthird_r1_r_update, m)
          .then(flip_B1_Bthird_r1_i_update, m)
          .then( *deallocate_buf_B1_Blocal_props_r1_r, t) // 1
          .then( *deallocate_buf_B1_Blocal_props_r1_i, t) // 2
          .then( *deallocate_buf_B1_Bfirst_props_r1_r, t) // 3
          .then( *deallocate_buf_B1_Bfirst_props_r1_i, t) // 4
          .then( *deallocate_buf_B1_Bsecond_props_r1_r, t) // 5
          .then( *deallocate_buf_B1_Bsecond_props_r1_i, t) // 6
          .then( *deallocate_buf_B1_Bthird_props_r1_r, t) // 7
          .then( *deallocate_buf_B1_Bthird_props_r1_i, t) // 8
// ---------------------------- 
// kernel_7:
        //   .then( *allocate_buf_B1_Blocal_r2_r, t)
        //   .then( *allocate_buf_B1_Blocal_r2_i, t)
        //   .then( *allocate_buf_B1_Bfirst_r2_r, t)
        //   .then( *allocate_buf_B1_Bfirst_r2_i, t)
        //   .then( *allocate_buf_B1_Bsecond_r2_r, t)
        //   .then( *allocate_buf_B1_Bsecond_r2_i, t)
        //   .then( *allocate_buf_B1_Bthird_r2_r, t)
        //   .then( *allocate_buf_B1_Bthird_r2_i, t)
          .then(B1_Blocal_r2_r_init, computation::root ) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m
          .then(B1_Blocal_r2_i_init, m)
          .then(B1_Bfirst_r2_r_init, m)
          .then(B1_Bfirst_r2_i_init, m)
          .then(B1_Bsecond_r2_r_init, m)
          .then(B1_Bsecond_r2_i_init, m)
          .then(B1_Bthird_r2_r_init, m)
          .then(B1_Bthird_r2_i_init, m)
// kernel_8
        //   .then( *allocate_buf_flip_B1_Blocal_r2_r, t )
        //   .then( *allocate_buf_flip_B1_Blocal_r2_i, t )
        //   .then( *allocate_buf_flip_B1_Bfirst_r2_r, t )
        //   .then( *allocate_buf_flip_B1_Bfirst_r2_i, t )
        //   .then( *allocate_buf_flip_B1_Bsecond_r2_r, t )
        //   .then( *allocate_buf_flip_B1_Bsecond_r2_i, t )
        //   .then( *allocate_buf_flip_B1_Bthird_r2_r, t )
        //   .then( *allocate_buf_flip_B1_Bthird_r2_i, t )
          .then(flip_B1_Blocal_r2_r_init, t)
          .then(flip_B1_Blocal_r2_i_init, m)
          .then(flip_B1_Bfirst_r2_r_init, m)
          .then(flip_B1_Bfirst_r2_i_init, m)
          .then(flip_B1_Bsecond_r2_r_init, m)
          .then(flip_B1_Bsecond_r2_i_init, m)
          .then(flip_B1_Bthird_r2_r_init, m)
          .then(flip_B1_Bthird_r2_i_init, m)
// kernel_9:
          .then( *allocate_buf_B1_Blocal_props_r2_r, computation::root )
          .then( *allocate_buf_B1_Blocal_props_r2_i, t )
          .then( *allocate_buf_B1_Bfirst_props_r2_r, t )
          .then( *allocate_buf_B1_Bfirst_props_r2_i, t )
          .then( *allocate_buf_B1_Bsecond_props_r2_r, t )
          .then( *allocate_buf_B1_Bsecond_props_r2_i, t )
          .then( *allocate_buf_B1_Bthird_props_r2_r, t )
          .then( *allocate_buf_B1_Bthird_props_r2_i, t )
          .then(B1_Blocal_r2_r_props_init, t) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime
          .then(B1_Blocal_r2_i_props_init, jSprime)
          .then(B1_Bfirst_r2_r_props_init, jSprime)
          .then(B1_Bfirst_r2_i_props_init, jSprime)
          .then(B1_Bsecond_r2_r_props_init, jSprime)
          .then(B1_Bsecond_r2_i_props_init, jSprime)
          .then(B1_Bthird_r2_r_props_init, jSprime)
          .then(B1_Bthird_r2_i_props_init, jSprime)

          .then(B1_Blocal_r2_r_diquark, y) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock
          .then(B1_Blocal_r2_i_diquark, wnumBlock)
          .then(B1_Bfirst_r2_r_diquark, wnumBlock)
          .then(B1_Bfirst_r2_i_diquark, wnumBlock)
          .then(B1_Bthird_r2_r_diquark, wnumBlock)
          .then(B1_Bthird_r2_i_diquark, wnumBlock)
          .then(B1_Blocal_r2_r_props, wnumBlock) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime

          .then(B1_Blocal_r2_i_props, jSprime) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime
          .then(B1_Bfirst_r2_r_props, jSprime)
          .then(B1_Bfirst_r2_i_props, jSprime)
          .then(B1_Bsecond_r2_r_props, jSprime)
          .then(B1_Bsecond_r2_i_props, jSprime)
          .then(B1_Bthird_r2_r_props, jSprime)
          .then(B1_Bthird_r2_i_props, jSprime)
// kernel_10:
          .then(B1_Blocal_r2_r_update, t) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m
          .then(B1_Blocal_r2_i_update, m)
          .then(B1_Bfirst_r2_r_update, m)
          .then(B1_Bfirst_r2_i_update, m)
          .then(B1_Bsecond_r2_r_update, m)
          .then(B1_Bsecond_r2_i_update, m)
          .then(B1_Bthird_r2_r_update, m)
          .then(B1_Bthird_r2_i_update, m)
// kernel_11:
          .then(flip_B1_Blocal_r2_r_update, t)
          .then(flip_B1_Blocal_r2_i_update, m)
          .then(flip_B1_Bfirst_r2_r_update, m)
          .then(flip_B1_Bfirst_r2_i_update, m)
          .then(flip_B1_Bsecond_r2_r_update, m)
          .then(flip_B1_Bsecond_r2_i_update, m)
          .then(flip_B1_Bthird_r2_r_update, m)
          .then(flip_B1_Bthird_r2_i_update, m)
          .then( *deallocate_buf_B1_Blocal_props_r2_r, t ) // 9
          .then( *deallocate_buf_B1_Blocal_props_r2_i, t ) // 10
          .then( *deallocate_buf_B1_Bfirst_props_r2_r, t ) // 11
          .then( *deallocate_buf_B1_Bfirst_props_r2_i, t ) // 12
          .then( *deallocate_buf_B1_Bsecond_props_r2_r, t ) // 13
          .then( *deallocate_buf_B1_Bsecond_props_r2_i, t ) // 14
          .then( *deallocate_buf_B1_Bthird_props_r2_r, t ) // 15
          .then( *deallocate_buf_B1_Bthird_props_r2_i, t ) // 16
// -----------------------
// kernel_12:
        //   .then( *allocate_buf_B2_Blocal_r1_r, t )
        //   .then( *allocate_buf_B2_Blocal_r1_i, t )
        //   .then( *allocate_buf_B2_Bfirst_r1_r, t )
        //   .then( *allocate_buf_B2_Bfirst_r1_i, t )
        //   .then( *allocate_buf_B2_Bsecond_r1_r, t )
        //   .then( *allocate_buf_B2_Bsecond_r1_i, t )
        //   .then( *allocate_buf_B2_Bthird_r1_r, t )
        //   .then( *allocate_buf_B2_Bthird_r1_i, t )
          .then(B2_Blocal_r1_r_init, computation::root) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m
          .then(B2_Blocal_r1_i_init, m)
          .then(B2_Bfirst_r1_r_init, m)
          .then(B2_Bfirst_r1_i_init, m)
          .then(B2_Bsecond_r1_r_init, m)
          .then(B2_Bsecond_r1_i_init, m)
          .then(B2_Bthird_r1_r_init, m)
          .then(B2_Bthird_r1_i_init, m)
// kernel_13:
        //   .then( *allocate_buf_flip_B2_Blocal_r1_r, t )
        //   .then( *allocate_buf_flip_B2_Blocal_r1_i, t )
        //   .then( *allocate_buf_flip_B2_Bfirst_r1_r, t )
        //   .then( *allocate_buf_flip_B2_Bfirst_r1_i, t )
        //   .then( *allocate_buf_flip_B2_Bsecond_r1_r, t )
        //   .then( *allocate_buf_flip_B2_Bsecond_r1_i, t )
        //   .then( *allocate_buf_flip_B2_Bthird_r1_r, t )
        //   .then( *allocate_buf_flip_B2_Bthird_r1_i, t )
          .then(flip_B2_Blocal_r1_r_init, t )
          .then(flip_B2_Blocal_r1_i_init, m)
          .then(flip_B2_Bfirst_r1_r_init, m)
          .then(flip_B2_Bfirst_r1_i_init, m)
          .then(flip_B2_Bsecond_r1_r_init, m)
          .then(flip_B2_Bsecond_r1_i_init, m)
          .then(flip_B2_Bthird_r1_r_init, m)
          .then(flip_B2_Bthird_r1_i_init, m)
// kernel_14
          .then( *allocate_buf_B2_Blocal_props_r1_r, computation::root )
          .then( *allocate_buf_B2_Blocal_props_r1_i, t )
          .then( *allocate_buf_B2_Bfirst_props_r1_r, t )
          .then( *allocate_buf_B2_Bfirst_props_r1_i, t )
          .then( *allocate_buf_B2_Bsecond_props_r1_r, t )
          .then( *allocate_buf_B2_Bsecond_props_r1_i, t )
          .then( *allocate_buf_B2_Bthird_props_r1_r, t )
          .then( *allocate_buf_B2_Bthird_props_r1_i, t )
          .then(B2_Blocal_r1_r_props_init, t ) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime
          .then(B2_Blocal_r1_i_props_init, jSprime)
          .then(B2_Bfirst_r1_r_props_init, jSprime)
          .then(B2_Bfirst_r1_i_props_init, jSprime)
          .then(B2_Bsecond_r1_r_props_init, jSprime)
          .then(B2_Bsecond_r1_i_props_init, jSprime)
          .then(B2_Bthird_r1_r_props_init, jSprime)
          .then(B2_Bthird_r1_i_props_init, jSprime)

          .then(B2_Blocal_r1_r_diquark, y)  // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock
          .then(B2_Blocal_r1_i_diquark, wnumBlock)
          .then(B2_Bfirst_r1_r_diquark, wnumBlock)
          .then(B2_Bfirst_r1_i_diquark, wnumBlock)
          .then(B2_Bthird_r1_r_diquark, wnumBlock)
          .then(B2_Bthird_r1_i_diquark, wnumBlock)
          .then(B2_Blocal_r1_r_props, wnumBlock)

          .then(B2_Blocal_r1_i_props, jSprime) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime
          .then(B2_Bfirst_r1_r_props, jSprime)
          .then(B2_Bfirst_r1_i_props, jSprime)
          .then(B2_Bsecond_r1_r_props, jSprime)
          .then(B2_Bsecond_r1_i_props, jSprime)
          .then(B2_Bthird_r1_r_props, jSprime)
          .then(B2_Bthird_r1_i_props, jSprime)
// kernel_15:
          .then(B2_Blocal_r1_r_update, t) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m
          .then(B2_Blocal_r1_i_update, m)
          .then(B2_Bfirst_r1_r_update, m)
          .then(B2_Bfirst_r1_i_update, m)
          .then(B2_Bsecond_r1_r_update, m)
          .then(B2_Bsecond_r1_i_update, m)
          .then(B2_Bthird_r1_r_update, m)
          .then(B2_Bthird_r1_i_update, m)
// kernel_16:
          .then(flip_B2_Blocal_r1_r_update, t)
          .then(flip_B2_Blocal_r1_i_update, m)
          .then(flip_B2_Bfirst_r1_r_update, m)
          .then(flip_B2_Bfirst_r1_i_update, m)
          .then(flip_B2_Bsecond_r1_r_update, m)
          .then(flip_B2_Bsecond_r1_i_update, m)
          .then(flip_B2_Bthird_r1_r_update, m)
          .then(flip_B2_Bthird_r1_i_update, m)
          .then( *deallocate_buf_B2_Blocal_props_r1_r, t ) // 17
          .then( *deallocate_buf_B2_Blocal_props_r1_i, t ) // 18
          .then( *deallocate_buf_B2_Bfirst_props_r1_r, t ) // 19
          .then( *deallocate_buf_B2_Bfirst_props_r1_i, t ) // 20
          .then( *deallocate_buf_B2_Bsecond_props_r1_r, t ) // 21
          .then( *deallocate_buf_B2_Bsecond_props_r1_i, t ) // 22
          .then( *deallocate_buf_B2_Bthird_props_r1_r, t ) // 23
          .then( *deallocate_buf_B2_Bthird_props_r1_i, t ) // 24
// -------------
// kernel_17:
        //   .then( *allocate_buf_B2_Blocal_r2_r, t )
        //   .then( *allocate_buf_B2_Blocal_r2_i, t )
        //   .then( *allocate_buf_B2_Bfirst_r2_r, t )
        //   .then( *allocate_buf_B2_Bfirst_r2_i, t )
        //   .then( *allocate_buf_B2_Bsecond_r2_r, t )
        //   .then( *allocate_buf_B2_Bsecond_r2_i, t )
        //   .then( *allocate_buf_B2_Bthird_r2_r, t )
        //   .then( *allocate_buf_B2_Bthird_r2_i, t )
          .then(B2_Blocal_r2_r_init, computation::root) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m
          .then(B2_Blocal_r2_i_init, m)
          .then(B2_Bfirst_r2_r_init, m)
          .then(B2_Bfirst_r2_i_init, m)
          .then(B2_Bsecond_r2_r_init, m)
          .then(B2_Bsecond_r2_i_init, m)
          .then(B2_Bthird_r2_r_init, m)
          .then(B2_Bthird_r2_i_init, m)
// kernel_18
        //   .then( *allocate_buf_flip_B2_Blocal_r2_r, t )
        //   .then( *allocate_buf_flip_B2_Blocal_r2_i, t )
        //   .then( *allocate_buf_flip_B2_Bfirst_r2_r, t )
        //   .then( *allocate_buf_flip_B2_Bfirst_r2_i, t )
        //   .then( *allocate_buf_flip_B2_Bsecond_r2_r, t )
        //   .then( *allocate_buf_flip_B2_Bsecond_r2_i, t )
        //   .then( *allocate_buf_flip_B2_Bthird_r2_r, t )
        //   .then( *allocate_buf_flip_B2_Bthird_r2_i, t )
          .then(flip_B2_Blocal_r2_r_init, t)
          .then(flip_B2_Blocal_r2_i_init, m)
          .then(flip_B2_Bfirst_r2_r_init, m)
          .then(flip_B2_Bfirst_r2_i_init, m)
          .then(flip_B2_Bsecond_r2_r_init, m)
          .then(flip_B2_Bsecond_r2_i_init, m)
          .then(flip_B2_Bthird_r2_r_init, m)
          .then(flip_B2_Bthird_r2_i_init, m)
// kernel_19
          .then( *allocate_buf_B2_Blocal_props_r2_r, computation::root )
          .then( *allocate_buf_B2_Blocal_props_r2_i, t )
          .then( *allocate_buf_B2_Bfirst_props_r2_r, t )
          .then( *allocate_buf_B2_Bfirst_props_r2_i, t )
          .then( *allocate_buf_B2_Bsecond_props_r2_r, t )
          .then( *allocate_buf_B2_Bsecond_props_r2_i, t )
          .then( *allocate_buf_B2_Bthird_props_r2_r, t )
          .then( *allocate_buf_B2_Bthird_props_r2_i, t )
          .then(B2_Blocal_r2_r_props_init, t ) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime
          .then(B2_Blocal_r2_i_props_init, jSprime)
          .then(B2_Bfirst_r2_r_props_init, jSprime)
          .then(B2_Bfirst_r2_i_props_init, jSprime)
          .then(B2_Bsecond_r2_r_props_init, jSprime)
          .then(B2_Bsecond_r2_i_props_init, jSprime)
          .then(B2_Bthird_r2_r_props_init, jSprime)
          .then(B2_Bthird_r2_i_props_init, jSprime)

          .then(B2_Blocal_r2_r_diquark, y) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock
          .then(B2_Blocal_r2_i_diquark, wnumBlock)
          .then(B2_Bfirst_r2_r_diquark, wnumBlock)
          .then(B2_Bfirst_r2_i_diquark, wnumBlock)
          .then(B2_Bthird_r2_r_diquark, wnumBlock)
          .then(B2_Bthird_r2_i_diquark, wnumBlock)
          .then(B2_Blocal_r2_r_props, wnumBlock)

          .then(B2_Blocal_r2_i_props, jSprime) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, wnumBlock, jCprime, jSprime
          .then(B2_Bfirst_r2_r_props, jSprime)
          .then(B2_Bfirst_r2_i_props, jSprime)
          .then(B2_Bsecond_r2_r_props, jSprime)
          .then(B2_Bsecond_r2_i_props, jSprime)
          .then(B2_Bthird_r2_r_props, jSprime)
          .then(B2_Bthird_r2_i_props, jSprime)
// kernel_20
          .then(B2_Blocal_r2_r_update, t) // t, x1, x2, iCprime, iSprime, kCprime, kSprime, y, jCprime, jSprime, m
          .then(B2_Blocal_r2_i_update, m)
          .then(B2_Bfirst_r2_r_update, m)
          .then(B2_Bfirst_r2_i_update, m) 
          .then(B2_Bsecond_r2_r_update, m)
          .then(B2_Bsecond_r2_i_update, m)
          .then(B2_Bthird_r2_r_update, m)
          .then(B2_Bthird_r2_i_update, m) 
        //   .then( *deallocate_buf_B2_Blocal_r2_r, t ) // 25
        //   .then( *deallocate_buf_B2_Blocal_r2_i, t ) // 26
        //   .then( *deallocate_buf_B2_Bfirst_r2_r, t ) // 27
        //   .then( *deallocate_buf_B2_Bfirst_r2_i, t ) // 28
        //   .then( *deallocate_buf_B2_Bsecond_r2_r, t ) // 29
        //   .then( *deallocate_buf_B2_Bsecond_r2_i, t ) // 30
        //   .then( *deallocate_buf_B2_Bthird_r2_r, t ) // 31
        //   .then( *deallocate_buf_B2_Bthird_r2_i, t ) // 32
// kernel_21
          .then(flip_B2_Blocal_r2_r_update, t)
          .then(flip_B2_Blocal_r2_i_update, m)
          .then(flip_B2_Bfirst_r2_r_update, m)
          .then(flip_B2_Bfirst_r2_i_update, m) 
          .then(flip_B2_Bsecond_r2_r_update, m)
          .then(flip_B2_Bsecond_r2_i_update, m)
          .then(flip_B2_Bthird_r2_r_update, m)
          .then(flip_B2_Bthird_r2_i_update, m) 
          .then( *deallocate_buf_B2_Blocal_props_r2_r, t ) // 33
          .then( *deallocate_buf_B2_Blocal_props_r2_i, t ) // 34
          .then( *deallocate_buf_B2_Bfirst_props_r2_r, t ) // 35
          .then( *deallocate_buf_B2_Bfirst_props_r2_i, t ) // 36
          .then( *deallocate_buf_B2_Bsecond_props_r2_r, t ) // 37
          .then( *deallocate_buf_B2_Bsecond_props_r2_i, t ) // 38
          .then( *deallocate_buf_B2_Bthird_props_r2_r, t ) // 39
          .then( *deallocate_buf_B2_Bthird_props_r2_i, t ) // 40
// ------------------------------- 
// kernel_22:
          .then(C_BB_BB_prop_init_r, computation::root) // t, x1, x2, rp, m, r
          .then(C_BB_BB_prop_init_i, r)
// kernel_23:
          .then( *(BB_BB_new_term_0_r1_b1.get_real()), t) // t, x1, x2, rp, m, r, s, nperm, wnum
          .then( *(BB_BB_new_term_0_r1_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_1_r1_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_1_r1_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_2_r1_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_2_r1_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_3_r1_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_3_r1_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_4_r1_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_4_r1_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_5_r1_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_5_r1_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_6_r1_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_6_r1_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_7_r1_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_7_r1_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_0_r2_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_0_r2_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_1_r2_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_1_r2_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_2_r2_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_2_r2_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_3_r2_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_3_r2_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_4_r2_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_4_r2_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_5_r2_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_5_r2_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_6_r2_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_6_r2_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_7_r2_b1.get_real()), wnum)
          .then( *(BB_BB_new_term_7_r2_b1.get_imag()), wnum)
          .then( *(BB_BB_new_term_0_r1_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_0_r1_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_1_r1_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_1_r1_b2.get_imag()), wnum) 
          .then( *(BB_BB_new_term_2_r1_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_2_r1_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_3_r1_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_3_r1_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_4_r1_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_4_r1_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_5_r1_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_5_r1_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_6_r1_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_6_r1_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_7_r1_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_7_r1_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_0_r2_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_0_r2_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_1_r2_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_1_r2_b2.get_imag()), wnum) 
          .then( *(BB_BB_new_term_2_r2_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_2_r2_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_3_r2_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_3_r2_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_4_r2_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_4_r2_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_5_r2_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_5_r2_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_6_r2_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_6_r2_b2.get_imag()), wnum)
          .then( *(BB_BB_new_term_7_r2_b2.get_real()), wnum)
          .then( *(BB_BB_new_term_7_r2_b2.get_imag()), wnum)
          .then(C_BB_BB_prop_update_r, wnum) 
          .then(C_BB_BB_prop_update_i, wnum)
        //   .then( *deallocate_buf_B1_Blocal_r1_r, t ) // 41
        //   .then( *deallocate_buf_B1_Blocal_r1_i, t ) // 42
        //   .then( *deallocate_buf_B1_Bfirst_r1_r, t ) // 43
        //   .then( *deallocate_buf_B1_Bfirst_r1_i, t ) // 44
        //   .then( *deallocate_buf_B1_Bsecond_r1_r, t ) // 45
        //   .then( *deallocate_buf_B1_Bsecond_r1_i, t ) // 46
        //   .then( *deallocate_buf_B1_Bthird_r1_r, t ) // 47
        //   .then( *deallocate_buf_B1_Bthird_r1_i, t ) // 48
        //   .then( *deallocate_buf_B1_Blocal_r2_r, t ) // 49
        //   .then( *deallocate_buf_B1_Blocal_r2_i, t ) // 50 
        //   .then( *deallocate_buf_B1_Bfirst_r2_r, t ) // 51
        //   .then( *deallocate_buf_B1_Bfirst_r2_i, t ) // 52
        //   .then( *deallocate_buf_B1_Bsecond_r2_r, t ) // 53
        //   .then( *deallocate_buf_B1_Bsecond_r2_i, t ) // 54
        //   .then( *deallocate_buf_B1_Bthird_r2_r, t ) // 55
        //   .then( *deallocate_buf_B1_Bthird_r2_i, t ) // 56
        //   .then( *deallocate_buf_B2_Blocal_r1_r, t ) // 57
        //   .then( *deallocate_buf_B2_Blocal_r1_i, t ) // 58
        //   .then( *deallocate_buf_B2_Bfirst_r1_r, t ) // 59
        //   .then( *deallocate_buf_B2_Bfirst_r1_i, t ) // 60
        //   .then( *deallocate_buf_B2_Bsecond_r1_r, t ) // 61
        //   .then( *deallocate_buf_B2_Bsecond_r1_i, t ) // 62
        //   .then( *deallocate_buf_B2_Bthird_r1_r, t ) // 63
        //   .then( *deallocate_buf_B2_Bthird_r1_i, t ) // 64
// kernel_24
          .then( *(flip_BB_BB_new_term_0_r1_b1.get_real()), t)
          .then( *(flip_BB_BB_new_term_0_r1_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_1_r1_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_1_r1_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_2_r1_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_2_r1_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_3_r1_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_3_r1_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_4_r1_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_4_r1_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_5_r1_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_5_r1_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_6_r1_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_6_r1_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_7_r1_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_7_r1_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_0_r2_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_0_r2_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_1_r2_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_1_r2_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_2_r2_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_2_r2_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_3_r2_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_3_r2_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_4_r2_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_4_r2_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_5_r2_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_5_r2_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_6_r2_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_6_r2_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_7_r2_b1.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_7_r2_b1.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_0_r1_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_0_r1_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_1_r1_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_1_r1_b2.get_imag()), wnum) 
          .then( *(flip_BB_BB_new_term_2_r1_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_2_r1_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_3_r1_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_3_r1_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_4_r1_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_4_r1_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_5_r1_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_5_r1_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_6_r1_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_6_r1_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_7_r1_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_7_r1_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_0_r2_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_0_r2_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_1_r2_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_1_r2_b2.get_imag()), wnum) 
          .then( *(flip_BB_BB_new_term_2_r2_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_2_r2_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_3_r2_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_3_r2_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_4_r2_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_4_r2_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_5_r2_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_5_r2_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_6_r2_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_6_r2_b2.get_imag()), wnum)
          .then( *(flip_BB_BB_new_term_7_r2_b2.get_real()), wnum)
          .then( *(flip_BB_BB_new_term_7_r2_b2.get_imag()), wnum)
          .then(C_BB_BB_prop_update_r_2, wnum) 
          .then(C_BB_BB_prop_update_i_2, wnum)
        //   .then( *deallocate_buf_flip_B1_Blocal_r1_r, t) // 65
        //   .then( *deallocate_buf_flip_B1_Blocal_r1_i, t) // 66
        //   .then( *deallocate_buf_flip_B1_Bfirst_r1_r, t) // 67
        //   .then( *deallocate_buf_flip_B1_Bfirst_r1_i, t) // 68
        //   .then( *deallocate_buf_flip_B1_Bsecond_r1_r, t) // 69
        //   .then( *deallocate_buf_flip_B1_Bsecond_r1_i, t) // 70
        //   .then( *deallocate_buf_flip_B1_Bthird_r1_r, t) // 71
        //   .then( *deallocate_buf_flip_B1_Bthird_r1_i, t) // 72
        //   .then( *deallocate_buf_flip_B1_Blocal_r2_r, t) // 73
        //   .then( *deallocate_buf_flip_B1_Blocal_r2_i, t) // 74
        //   .then( *deallocate_buf_flip_B1_Bfirst_r2_r, t) // 75
        //   .then( *deallocate_buf_flip_B1_Bfirst_r2_i, t) // 76
        //   .then( *deallocate_buf_flip_B1_Bsecond_r2_r, t) // 77
        //   .then( *deallocate_buf_flip_B1_Bsecond_r2_i, t) // 78
        //   .then( *deallocate_buf_flip_B1_Bthird_r2_r, t) // 79
        //   .then( *deallocate_buf_flip_B1_Bthird_r2_i, t) // 80
        //   .then( *deallocate_buf_flip_B2_Blocal_r1_r, t) // 81
        //   .then( *deallocate_buf_flip_B2_Blocal_r1_i, t) // 82
        //   .then( *deallocate_buf_flip_B2_Bfirst_r1_r, t) // 83
        //   .then( *deallocate_buf_flip_B2_Bfirst_r1_i, t) // 84
        //   .then( *deallocate_buf_flip_B2_Bsecond_r1_r, t) // 85
        //   .then( *deallocate_buf_flip_B2_Bsecond_r1_i, t) // 86
        //   .then( *deallocate_buf_flip_B2_Bthird_r1_r, t) // 87
        //   .then( *deallocate_buf_flip_B2_Bthird_r1_i, t) // 88
        //   .then( *deallocate_buf_flip_B2_Blocal_r2_r, t ) // 89
        //   .then( *deallocate_buf_flip_B2_Blocal_r2_i, t ) // 90
        //   .then( *deallocate_buf_flip_B2_Bfirst_r2_r, t ) // 91
        //   .then( *deallocate_buf_flip_B2_Bfirst_r2_i, t ) // 92
        //   .then( *deallocate_buf_flip_B2_Bsecond_r2_r, t ) // 93
        //   .then( *deallocate_buf_flip_B2_Bsecond_r2_i, t ) // 94
        //   .then( *deallocate_buf_flip_B2_Bthird_r2_r, t ) // 95
        //   .then( *deallocate_buf_flip_B2_Bthird_r2_i, t ) // 96

// kernel_25
          .then(C_BB_BB_update_b_r, t)  // t, x1, x2, rp, m, r, ne
          .then(C_BB_BB_update_b_i, ne)
          .then(C_BB_BB_update_s_r, r)  // t, x1, x2, rp, m, r, nue
          .then(C_BB_BB_update_s_i, nue)
          );

    // BB_H
    handle = &(handle
          ->then(src_B1_Blocal_r1_r_init, t) // t, x_out, x_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, m
          .then(src_B1_Blocal_r1_i_init, jSprime)
          .then(flip_src_B1_Blocal_r1_r_init, jSprime)
          .then(flip_src_B1_Blocal_r1_i_init, jSprime)
          .then(src_B1_Blocal_r1_r_props_init, x_in)
          .then(src_B1_Blocal_r1_i_props_init, jSprime)

          .then(src_B1_Blocal_r1_r_diquark, y)
          .then(src_B1_Blocal_r1_i_diquark, wnumBlock)
          .then(src_B1_Blocal_r1_r_props, wnumBlock)
          .then(src_B1_Blocal_r1_i_props, jSprime)
          .then(src_B1_Blocal_r1_r_update, y)
          .then(src_B1_Blocal_r1_i_update, m)
          .then(flip_src_B1_Blocal_r1_r_update, m)
          .then(flip_src_B1_Blocal_r1_i_update, m)

          .then(src_B1_Blocal_r2_r_init, x_in)
          .then(src_B1_Blocal_r2_i_init, jSprime)
          .then(flip_src_B1_Blocal_r2_r_init, jSprime)
          .then(flip_src_B1_Blocal_r2_i_init, jSprime)
          .then(src_B1_Blocal_r2_r_props_init, x_in)
          .then(src_B1_Blocal_r2_i_props_init, jSprime)

          .then(src_B1_Blocal_r2_r_diquark, y)
          .then(src_B1_Blocal_r2_i_diquark, wnumBlock)
          .then(src_B1_Blocal_r2_r_props, wnumBlock)
          .then(src_B1_Blocal_r2_i_props, jSprime)
          .then(src_B1_Blocal_r2_r_update, y)
          .then(src_B1_Blocal_r2_i_update, m)
          .then(flip_src_B1_Blocal_r2_r_update, m)
          .then(flip_src_B1_Blocal_r2_i_update, m)

          .then(src_B2_Blocal_r1_r_init, x_in)
          .then(src_B2_Blocal_r1_i_init, jSprime)
          .then(flip_src_B2_Blocal_r1_r_init, jSprime)
          .then(flip_src_B2_Blocal_r1_i_init, jSprime)
          .then(src_B2_Blocal_r1_r_props_init, x_in)
          .then(src_B2_Blocal_r1_i_props_init, jSprime)

          .then(src_B2_Blocal_r1_r_diquark, y)
          .then(src_B2_Blocal_r1_i_diquark, wnumBlock)
          .then(src_B2_Blocal_r1_r_props, wnumBlock)
          .then(src_B2_Blocal_r1_i_props, jSprime)
          .then(src_B2_Blocal_r1_r_update, y)
          .then(src_B2_Blocal_r1_i_update, m)
          .then(flip_src_B2_Blocal_r1_r_update, m)
          .then(flip_src_B2_Blocal_r1_i_update, m)

          .then(src_B2_Blocal_r2_r_init, x_in)
          .then(src_B2_Blocal_r2_i_init, jSprime)
          .then(flip_src_B2_Blocal_r2_r_init, jSprime)
          .then(flip_src_B2_Blocal_r2_i_init, jSprime)
          .then(src_B2_Blocal_r2_r_props_init, x_in)
          .then(src_B2_Blocal_r2_i_props_init, jSprime)

          .then(src_B2_Blocal_r2_r_diquark, y)
          .then(src_B2_Blocal_r2_i_diquark, wnumBlock)
          .then(src_B2_Blocal_r2_r_props, wnumBlock)
          .then(src_B2_Blocal_r2_i_props, jSprime)
          .then(src_B2_Blocal_r2_r_update, y)
          .then(src_B2_Blocal_r2_i_update, m)
          .then(flip_src_B2_Blocal_r2_r_update, m)
          .then(flip_src_B2_Blocal_r2_i_update, m) 
          
         .then(C_BB_H_prop_init_r, x_in)
          .then(C_BB_H_prop_init_i, r) 
          .then( *(BB_H_new_term_0_r1_b1.get_real()), r)
          .then( *(BB_H_new_term_0_r1_b1.get_imag()), wnumHex)
          .then( *(BB_H_new_term_0_r2_b1.get_real()), wnumHex)
          .then( *(BB_H_new_term_0_r2_b1.get_imag()), wnumHex)
          .then( *(BB_H_new_term_0_r1_b2.get_real()), wnumHex)
          .then( *(BB_H_new_term_0_r1_b2.get_imag()), wnumHex)
          .then( *(BB_H_new_term_0_r2_b2.get_real()), wnumHex)
          .then( *(BB_H_new_term_0_r2_b2.get_imag()), wnumHex)
          .then( *(flip_BB_H_new_term_0_r1_b1.get_real()), wnumHex)
          .then( *(flip_BB_H_new_term_0_r1_b1.get_imag()), wnumHex)
          .then( *(flip_BB_H_new_term_0_r2_b1.get_real()), wnumHex)
          .then( *(flip_BB_H_new_term_0_r2_b1.get_imag()), wnumHex)
          .then( *(flip_BB_H_new_term_0_r1_b2.get_real()), wnumHex)
          .then( *(flip_BB_H_new_term_0_r1_b2.get_imag()), wnumHex)
          .then( *(flip_BB_H_new_term_0_r2_b2.get_real()), wnumHex)
          .then( *(flip_BB_H_new_term_0_r2_b2.get_imag()), wnumHex)
          .then(C_BB_H_prop_update_r, wnumHex) 
          .then(C_BB_H_prop_update_i, wnumHex) 
          .then(C_BB_H_update_r, r)  // t, x_out, x_in, rp, m, r, nH
          .then(C_BB_H_update_i, nH)
          );

// kernel_10:
    // H_BB
    handle = &(handle
          ->then( snk_B1_Blocal_r1_r_init, computation::root) // t, y_out, y_in, iCprime, iSprime, kCprime, kSprime, jCprime, jSprime, n
          .then(snk_B1_Blocal_r1_i_init, jSprime)
          .then(flip_snk_B1_Blocal_r1_r_init, jSprime)
          .then(flip_snk_B1_Blocal_r1_i_init, jSprime)
          .then(snk_B1_Blocal_r1_r_props_init, y_in)
          .then(snk_B1_Blocal_r1_i_props_init, jSprime)

          .then(snk_B1_Blocal_r1_r_diquark, x)
          .then(snk_B1_Blocal_r1_i_diquark, wnumBlock)
          .then(snk_B1_Blocal_r1_r_props, wnumBlock)
          .then(snk_B1_Blocal_r1_i_props, jSprime)
          .then(snk_B1_Blocal_r1_r_update, x)
          .then(snk_B1_Blocal_r1_i_update, n)
          .then(flip_snk_B1_Blocal_r1_r_update, n)
          .then(flip_snk_B1_Blocal_r1_i_update, n)

          .then(snk_B1_Blocal_r2_r_init, y_in)
          .then(snk_B1_Blocal_r2_i_init, jSprime)
          .then(flip_snk_B1_Blocal_r2_r_init, jSprime)
          .then(flip_snk_B1_Blocal_r2_i_init, jSprime)
          .then(snk_B1_Blocal_r2_r_props_init, y_in)
          .then(snk_B1_Blocal_r2_i_props_init, jSprime)

          .then(snk_B1_Blocal_r2_r_diquark, x)
          .then(snk_B1_Blocal_r2_i_diquark, wnumBlock)
          .then(snk_B1_Blocal_r2_r_props, wnumBlock)
          .then(snk_B1_Blocal_r2_i_props, jSprime)
          .then(snk_B1_Blocal_r2_r_update, x)
          .then(snk_B1_Blocal_r2_i_update, n)
          .then(flip_snk_B1_Blocal_r2_r_update, n)
          .then(flip_snk_B1_Blocal_r2_i_update, n)

          .then(snk_B2_Blocal_r1_r_init, y_in)
          .then(snk_B2_Blocal_r1_i_init, jSprime)
          .then(flip_snk_B2_Blocal_r1_r_init, jSprime)
          .then(flip_snk_B2_Blocal_r1_i_init, jSprime)
          .then(snk_B2_Blocal_r1_r_props_init, y_in)
          .then(snk_B2_Blocal_r1_i_props_init, jSprime)

          .then(snk_B2_Blocal_r1_r_diquark, x)
          .then(snk_B2_Blocal_r1_i_diquark, wnumBlock)
          .then(snk_B2_Blocal_r1_r_props, wnumBlock)
          .then(snk_B2_Blocal_r1_i_props, jSprime)
          .then(snk_B2_Blocal_r1_r_update, x)
          .then(snk_B2_Blocal_r1_i_update, n)
          .then(flip_snk_B2_Blocal_r1_r_update, n)
          .then(flip_snk_B2_Blocal_r1_i_update, n)

          .then(snk_B2_Blocal_r2_r_init, y_in)
          .then(snk_B2_Blocal_r2_i_init, jSprime)
          .then(flip_snk_B2_Blocal_r2_r_init, jSprime)
          .then(flip_snk_B2_Blocal_r2_i_init, jSprime)
          .then(snk_B2_Blocal_r2_r_props_init, y_in)
          .then(snk_B2_Blocal_r2_i_props_init, jSprime)

          .then(snk_B2_Blocal_r2_r_diquark, x)
          .then(snk_B2_Blocal_r2_i_diquark, wnumBlock)
          .then(snk_B2_Blocal_r2_r_props, wnumBlock)
          .then(snk_B2_Blocal_r2_i_props, jSprime)
          .then(snk_B2_Blocal_r2_r_update, x)
          .then(flip_snk_B2_Blocal_r2_r_update, n)
          .then(flip_snk_B2_Blocal_r2_i_update, n)
          .then(snk_B2_Blocal_r2_i_update, n)
          .then(C_H_BB_prop_init_r, y_in)
          .then(C_H_BB_prop_init_i, r)
          .then( *(H_BB_new_term_0_r1_b1.get_real()), r)
          .then( *(H_BB_new_term_0_r1_b1.get_imag()), wnumHex)
          .then( *(H_BB_new_term_0_r2_b1.get_real()), wnumHex)
          .then( *(H_BB_new_term_0_r2_b1.get_imag()), wnumHex)
          .then( *(H_BB_new_term_0_r1_b2.get_real()), wnumHex)
          .then( *(H_BB_new_term_0_r1_b2.get_imag()), wnumHex)
          .then( *(H_BB_new_term_0_r2_b2.get_real()), wnumHex)
          .then( *(H_BB_new_term_0_r2_b2.get_imag()), wnumHex)
          .then( *(flip_H_BB_new_term_0_r1_b1.get_real()), wnumHex)
          .then( *(flip_H_BB_new_term_0_r1_b1.get_imag()), wnumHex)
          .then( *(flip_H_BB_new_term_0_r2_b1.get_real()), wnumHex)
          .then( *(flip_H_BB_new_term_0_r2_b1.get_imag()), wnumHex)
          .then( *(flip_H_BB_new_term_0_r1_b2.get_real()), wnumHex)
          .then( *(flip_H_BB_new_term_0_r1_b2.get_imag()), wnumHex)
          .then( *(flip_H_BB_new_term_0_r2_b2.get_real()), wnumHex)
          .then( *(flip_H_BB_new_term_0_r2_b2.get_imag()), wnumHex)
          .then( *(H_BB_term_res_comp.get_real()), wnumHex)
          .then( *(H_BB_term_res_comp.get_imag()), wnumHex)
          .then(C_H_BB_prop_update_r, wnumHex) 
          .then(C_H_BB_prop_update_i, wnumHex)
          .then(C_H_BB_update_r, r) // t, y_out, y_in, rp, n, r, mH
          .then(C_H_BB_update_i, mH) 
          ); 

// kernel_11:
    // // H_H
    handle = &(handle
          ->then(C_H_H_prop_init_r, t) // t, x_out, x_in, rp, r, y
          .then(C_H_H_prop_init_i, y)
          .then(C_H_H_prop_update_r, y) 
          .then(C_H_H_prop_update_i, wnumHexHex)
          .then(C_H_H_update_r, y) 
          .then(C_H_H_update_i, nH) 
          ); 

    handle = &(handle->then(copy_buf_C_r_device_to_host, computation::root)
    .then(copy_buf_C_i_device_to_host, computation::root)
    // .then(copy_B1_prop_r_device_to_host, computation::root)
    // .then(copy_B1_prop_i_device_to_host, computation::root)
    // .then(copy_B2_prop_r_device_to_host, computation::root)
    // .then(copy_B2_prop_i_device_to_host, computation::root)
    // .then(copy_src_psi_B1_r_device_to_host, computation::root)
    // .then(copy_src_psi_B1_i_device_to_host, computation::root)
    // .then(copy_src_psi_B2_r_device_to_host, computation::root)
    // .then(copy_src_psi_B2_i_device_to_host, computation::root)
    // .then(copy_snk_psi_B1_r_device_to_host, computation::root)
    // .then(copy_snk_psi_B1_i_device_to_host, computation::root)
    // .then(copy_snk_psi_B2_r_device_to_host, computation::root)
    // .then(copy_snk_psi_B2_i_device_to_host, computation::root)
    // .then(copy_hex_src_psi_r_device_to_host, computation::root)
    // .then(copy_hex_src_psi_i_device_to_host, computation::root)
    // .then(copy_src_spins_device_to_host, computation::root)
    // .then(copy_sigs_device_to_host, computation::root)
    // .then(copy_snk_psi_r_device_to_host, computation::root)
    // .then(copy_snk_psi_i_device_to_host, computation::root)
    // .then(copy_hex_snk_psi_r_device_to_host, computation::root)
    // .then(copy_hex_snk_psi_i_device_to_host, computation::root)
    // .then(copy_src_color_weights_device_to_host, computation::root)
    // .then(copy_src_spin_weights_device_to_host, computation::root)
    // .then(copy_src_weights_device_to_host, computation::root)
    // .then(copy_snk_color_weights_device_to_host, computation::root)
    // .then(copy_snk_spin_weights_device_to_host, computation::root)
    // .then(copy_snk_weights_device_to_host, computation::root)
    // .then(copy_hex_snk_color_weights_device_to_host, computation::root)
    // .then(copy_hex_snk_spin_weights_device_to_host, computation::root)
    // .then(copy_hex_snk_weights_device_to_host, computation::root)
    // .then(copy_src_spin_block_weights_device_to_host, computation::root)
    // .then(copy_snk_b_device_to_host, computation::root)
    .then(copy_buf_C_BB_r_device_to_host, computation::root)
    .then(copy_buf_C_BB_i_device_to_host, computation::root)
    );

#if VECTORIZED

    // (BB_BB_new_term_0_r1_b1.get_real())->tag_vector_level(wnum, Nw2);
    // (BB_H_new_term_0_r1_b1.get_real())->tag_vector_level(wnumHex, Nw2Hex);
    // (H_BB_new_term_0_r1_b1.get_real())->tag_vector_level(wnumHex, Nw2Hex);
    // C_H_H_prop_update_r.tag_vector_level(wnumHexHex, Nw2Hex);

#endif

#if PARALLEL

    // B1_Blocal_r1_r_init.tag_distribute_level(t);
    // src_B1_Blocal_r1_r_init.tag_distribute_level(t);
    // snk_B1_Blocal_r1_r_init.tag_distribute_level(t);
    // C_H_H_prop_init_r.tag_distribute_level(t);


#endif

    // -------------------------------------------------------
    // Code Generation
    // -------------------------------------------------------
    tiramisu::codegen({
            &buf_C_r_cpu, &buf_C_i_cpu,
            &buf_C_BB_r_cpu, &buf_C_BB_i_cpu,
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
        "generated_gpu_tiramisu_make_fused_dibaryon_blocks_correlator.o", true);
}

int main(int argc, char **argv)
{
	generate_function("gpu_tiramisu_make_fused_dibaryon_blocks_correlator");

    return 0;
}
