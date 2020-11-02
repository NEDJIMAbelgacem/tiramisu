#include <tiramisu/tiramisu.h>
#include <string.h>
#include "tiramisu_make_fused_baryon_blocks_correlator_wrapper.h"
#include "../../utils/complex_util.h"
#include "../../utils/util.h"

using namespace tiramisu;

#define VECTORIZED 0
#define PARALLEL 0
#define GPU_PARALLEL 1

void generate_function(std::string name)
{
    tiramisu::init(name);

    var r("r", 0, 4 * B1Nrows),
        rp("rp", 0, 4 * B1Nrows),
        nperm("nperm", 0, 4 * B1Nperms),
        q("q", 0, 4 * Nq),
        wnum("wnum", 0, 4 * Nw),
        wnumBlock("wnumBlock", 0, 4 * Nw),
        t("t", 0, 16),//Lt),
        x("x", 0, 4 * Vsnk),
        x_out("x_out", 0, 4 * Vsnk/sites_per_rank),
        x_in("x_in", 0, 4 * sites_per_rank),
        y("y", 0, 4 * Vsrc),
        m("m", 0, 4 * NsrcHex),
        n("n", 0, 4 * NsnkHex),
        tri("tri", 0, 4 * Nq),
        iCprime("iCprime", 0, Nc),
        iSprime("iSprime", 0, Ns),
        jCprime("jCprime", 0, Nc),
        jSprime("jSprime", 0, Ns),
        kCprime("kCprime", 0, Nc),
        kSprime("kSprime", 0, Ns);


//    input B1_prop_r("B1_prop_r",   {tri, t, iCprime, iSprime, jCprime, jSprime, x, y}, p_float64);
//    input B1_prop_i("B1_prop_i",   {tri, t, iCprime, iSprime, jCprime, jSprime, x, y}, p_float64);
//    input src_psi_B1_r("src_psi_B1_r",    {y, m}, p_float64);
//    input src_psi_B1_i("src_psi_B1_i",    {y, m}, p_float64);
//    input snk_psi_r("snk_psi_r", {x, n}, p_float64); 
//    input snk_psi_i("snk_psi_i", {x, n}, p_float64);
//    input src_color_weights("src_color_weights", {rp, wnum, q}, p_int32);
//    input src_spin_weights("src_spin_weights", {rp, wnum, q}, p_int32);
//    input src_weights("src_weights", {rp, wnum}, p_float64);
//    input snk_color_weights("snk_color_weights", {r, nperm, wnum, q}, p_int32);
//    input snk_spin_weights("snk_spin_weights", {r, nperm, wnum, q}, p_int32);
//    input snk_weights("snk_weights", {r, wnum}, p_float64);
//    input src_spins("src_spins", {rp}, p_int32);
//    input sigs("sigs", {nperm}, p_int32);

    // -------------------------------------------------------
    // Layer II
    // -------------------------------------------------------

    /* Correlator */

    buffer buf_C_r("buf_C_r", {t, x_out, rp, m, r, n}, p_float64, a_temporary);
    buffer buf_C_i("buf_C_i", {t, x_out, rp, m, r, n}, p_float64, a_temporary);

    buf_C_r.tag_gpu_global();
    buf_C_i.tag_gpu_global();
    buffer buf_C_r_cpu("buf_C_r_cpu", {t, x_out, rp, m, r, n}, p_float64, a_temporary);
    buffer buf_C_i_cpu("buf_C_i_cpu", {t, x_out, rp, m, r, n}, p_float64, a_temporary);

    computation C_init_r("C_init_r", {t, x_out, rp, m, r, n}, expr((double) 0));
    computation C_init_i("C_init_i", {t, x_out, rp, m, r, n}, expr((double) 0));

    C_init_r.store_in(buf_C_r);
    C_init_i.store_in(buf_C_i);

    // buffer B1_prop_r_cpu("B1_prop_r_cpu",   {t, iCprime, iSprime, jCprime, jSprime, x, y, tri}, p_float64, a_temporary);
    // buffer B1_prop_i_cpu("B1_prop_i_cpu",   {t, iCprime, iSprime, jCprime, jSprime, x, y, tri}, p_float64, a_temporary);
    // buffer src_psi_B1_r_cpu("src_psi_B1_r_cpu",    {y, m}, p_float64, a_temporary);
    // buffer src_psi_B1_i_cpu("src_psi_B1_i_cpu",    {y, m}, p_float64, a_temporary);
    // buffer snk_psi_r_cpu("snk_psi_r_cpu", {x, n}, p_float64, a_temporary);
    // buffer snk_psi_i_cpu("snk_psi_i_cpu", {x, n}, p_float64, a_temporary);
    // buffer src_color_weights_cpu("src_color_weights_cpu", {rp, wnum, q}, p_int32, a_temporary);
    // buffer src_spin_weights_cpu("src_spin_weights_cpu", {rp, wnum, q}, p_int32, a_temporary);
    // buffer src_weights_cpu("src_weights_cpu", {rp, wnum}, p_float64, a_temporary);
    // buffer snk_color_weights_cpu("snk_color_weights_cpu", {r, nperm, wnum, q}, p_int32, a_temporary);
    // buffer snk_spin_weights_cpu("snk_spin_weights_cpu", {r, nperm, wnum, q}, p_int32, a_temporary);
    // buffer snk_weights_cpu("snk_weights_cpu", {r, wnum}, p_float64, a_temporary);
    // buffer src_spins_cpu("src_spins_cpu", {rp}, p_int32, a_temporary);
    // buffer sigs_cpu("sigs_cpu", {nperm}, p_int32, a_temporary);

    // computation copy_buf_C_r_host_to_device({t, x_out, rp, m, r, n}, memcpy(buf_C_r_cpu, buf_C_r));
    // computation copy_buf_C_i_host_to_device({t, x_out, rp, m, r, n}, memcpy(buf_C_i_cpu, buf_C_i));
    // computation copy_buf_C_r_device_to_host({t, x_out, rp, m, r, n}, memcpy(buf_C_r, buf_C_r_cpu));
    // computation copy_buf_C_i_device_to_host({t, x_out, rp, m, r, n}, memcpy(buf_C_i, buf_C_i_cpu));

    computation copy_buf_C_r_host_to_device("copy_buf_C_r_host_to_device", {}, memcpy(buf_C_r_cpu, buf_C_r));
    computation copy_buf_C_i_host_to_device("copy_buf_C_i_host_to_device", {}, memcpy(buf_C_i_cpu, buf_C_i));
    computation copy_buf_C_r_device_to_host("copy_buf_C_r_device_to_host", {}, memcpy(buf_C_r, buf_C_r_cpu));
    computation copy_buf_C_i_device_to_host("copy_buf_C_i_device_to_host", {}, memcpy(buf_C_i, buf_C_i_cpu));

    // -------------------------------------------------------
    // Layer III
    // -------------------------------------------------------

    computation* handle = &copy_buf_C_r_host_to_device.then(copy_buf_C_i_host_to_device, computation::root);
    handle = &handle->then(C_init_r, computation::root).then(C_init_i, computation::root);
    handle = &handle->then(copy_buf_C_r_device_to_host, computation::root)
            .then(copy_buf_C_i_device_to_host, computation::root)
            ;
    C_init_r.tag_gpu_level(t);
   input C_r("C_r",      {t, x_out, rp, m, r, n}, p_float64);
   input C_i("C_i",      {t, x_out, rp, m, r, n}, p_float64);
    C_r.store_in(&buf_C_r);
    C_i.store_in(&buf_C_i);

    // C_r.tag_gpu_level(t);
    // C_i.tag_gpu_level(t);

    // -------------------------------------------------------
    // Code Generation
    // -------------------------------------------------------
    tiramisu::codegen({
        &buf_C_r_cpu, &buf_C_i_cpu,
        // &B1_prop_r_cpu, &B1_prop_i_cpu,
        // &src_psi_B1_r_cpu, &src_psi_B1_i_cpu,
        // &snk_psi_r_cpu, &snk_psi_i_cpu,
        // &src_color_weights_cpu,
        // &src_spin_weights_cpu,
        // &src_weights_cpu,
        // &src_spins_cpu, 
        // &snk_color_weights_cpu,
        // &snk_spin_weights_cpu,
        // &snk_weights_cpu,
        // &sigs_cpu
        }, 
        "generated_tiramisu_make_fused_baryon_blocks_correlator.o", true);
}

int main(int argc, char **argv)
{

    generate_function("tiramisu_make_fused_baryon_blocks_correlator");

    return 0;
}
