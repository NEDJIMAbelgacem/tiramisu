static __global__ void _kernel_0(double *buf_B1_Blocal_diquark_r1_i, double *buf_B1_Blocal_diquark_r1_r, double *buf_B1_Blocal_props_r1_i, double *buf_B1_Blocal_props_r1_r, double *buf_B1_Blocal_r1_i, double *buf_B1_Blocal_r1_r, double *buf_B1_prop_i, double *buf_B1_prop_r, int32_t *buf_src_color_weights, double *buf_src_psi_B1_i, double *buf_src_psi_B1_r, int32_t *buf_src_spin_weights, double *buf_src_weights)
{
        const int32_t __bx__ = (blockIdx.x + 0);
        const int32_t __tx__ = (threadIdx.x + 0);
        for (int32_t c7 = 0; (c7 <= 2); (c7 += 1))
        {
                for (int32_t c9 = 0; (c9 <= 1); (c9 += 1))
                {
                        for (int32_t c11 = 0; (c11 <= 2); (c11 += 1))
                        {
                                for (int32_t c13 = 0; (c13 <= 1); (c13 += 1))
                                {
                                        for (int32_t c15 = 0; (c15 <= 2); (c15 += 1))
                                        {
                                                for (int32_t c17 = 0; (c17 <= 1); (c17 += 1))
                                                {
                                                        buf_B1_Blocal_r1_r[(((((((0 + (0 * 1)) + (c17 * (1 * 1))) + (c15 * ((1 * 1) * 2))) + (c13 * (((1 * 1) * 2) * 3))) + (c11 * ((((1 * 1) * 2) * 3) * 2))) + (c9 * (((((1 * 1) * 2) * 3) * 2) * 3))) + (c7 * ((((((1 * 1) * 2) * 3) * 2) * 3) * 2)))] = 0;
                                                        buf_B1_Blocal_r1_i[(((((((0 + (0 * 1)) + (c17 * (1 * 1))) + (c15 * ((1 * 1) * 2))) + (c13 * (((1 * 1) * 2) * 3))) + (c11 * ((((1 * 1) * 2) * 3) * 2))) + (c9 * (((((1 * 1) * 2) * 3) * 2) * 3))) + (c7 * ((((((1 * 1) * 2) * 3) * 2) * 3) * 2)))] = 0;
                                                };
                                        };
                                };
                        };
                };
        };
        for (int32_t c7 = 0; (c7 <= 2); (c7 += 1))
        {
                for (int32_t c9 = 0; (c9 <= 1); (c9 += 1))
                {
                        for (int32_t c11 = 0; (c11 <= 2); (c11 += 1))
                        {
                                for (int32_t c13 = 0; (c13 <= 1); (c13 += 1))
                                {
                                        for (int32_t c15 = 0; (c15 <= 7); (c15 += 1))
                                        {
                                                for (int32_t c17 = 0; (c17 <= 2); (c17 += 1))
                                                {
                                                        for (int32_t c19 = 0; (c19 <= 1); (c19 += 1))
                                                        {
                                                                buf_B1_Blocal_props_r1_r[((0 + (c19 * 1)) + (c17 * (1 * 2)))] = 0;
                                                                buf_B1_Blocal_props_r1_i[((0 + (c19 * 1)) + (c17 * (1 * 2)))] = 0;
                                                        };
                                                };
                                                for (int32_t c17 = 0; (c17 <= 11); (c17 += 1))
                                                {
                                                        const int32_t t119 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t120 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t121 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t122 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t123 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t124 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t125 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t126 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        buf_B1_Blocal_diquark_r1_r[(0 + (0 * 1))] = (((buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t120 * ((1 * 8) * 8))) + (t119 * (((1 * 8) * 8) * 2))) + (c9 * ((((1 * 8) * 8) * 2) * 3))) + (c7 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (0 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t122 * ((1 * 8) * 8))) + (t121 * (((1 * 8) * 8) * 2))) + (c13 * ((((1 * 8) * 8) * 2) * 3))) + (c11 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (2 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))]) - (buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t124 * ((1 * 8) * 8))) + (t123 * (((1 * 8) * 8) * 2))) + (c9 * ((((1 * 8) * 8) * 2) * 3))) + (c7 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (0 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t126 * ((1 * 8) * 8))) + (t125 * (((1 * 8) * 8) * 2))) + (c13 * ((((1 * 8) * 8) * 2) * 3))) + (c11 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (2 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))])) * buf_src_weights[((0 + (c17 * 1)) + (0 * (1 * 12)))]);
                                                        const int32_t t137 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t138 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t139 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t140 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t141 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t142 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t143 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t144 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        buf_B1_Blocal_diquark_r1_i[(0 + (0 * 1))] = (((buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t138 * ((1 * 8) * 8))) + (t137 * (((1 * 8) * 8) * 2))) + (c9 * ((((1 * 8) * 8) * 2) * 3))) + (c7 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (0 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t140 * ((1 * 8) * 8))) + (t139 * (((1 * 8) * 8) * 2))) + (c13 * ((((1 * 8) * 8) * 2) * 3))) + (c11 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (2 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))]) + (buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t142 * ((1 * 8) * 8))) + (t141 * (((1 * 8) * 8) * 2))) + (c9 * ((((1 * 8) * 8) * 2) * 3))) + (c7 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (0 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t144 * ((1 * 8) * 8))) + (t143 * (((1 * 8) * 8) * 2))) + (c13 * ((((1 * 8) * 8) * 2) * 3))) + (c11 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (2 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))])) * buf_src_weights[((0 + (c17 * 1)) + (0 * (1 * 12)))]);
                                                        for (int32_t c19 = 0; (c19 <= 2); (c19 += 1))
                                                        {
                                                                for (int32_t c21 = 0; (c21 <= 1); (c21 += 1))
                                                                {
                                                                        const int32_t t155 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t156 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t157 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t158 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        buf_B1_Blocal_props_r1_r[((0 + (c21 * 1)) + (c19 * (1 * 2)))] = (buf_B1_Blocal_props_r1_r[((0 + (c21 * 1)) + (c19 * (1 * 2)))] + ((buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t156 * ((1 * 8) * 8))) + (t155 * (((1 * 8) * 8) * 2))) + (c21 * ((((1 * 8) * 8) * 2) * 3))) + (c19 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (1 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_Blocal_diquark_r1_r[(0 + (0 * 1))]) - (buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t158 * ((1 * 8) * 8))) + (t157 * (((1 * 8) * 8) * 2))) + (c21 * ((((1 * 8) * 8) * 2) * 3))) + (c19 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (1 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_Blocal_diquark_r1_i[(0 + (0 * 1))])));
                                                                        const int32_t t171 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t172 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t173 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t174 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        buf_B1_Blocal_props_r1_i[((0 + (c21 * 1)) + (c19 * (1 * 2)))] = (buf_B1_Blocal_props_r1_i[((0 + (c21 * 1)) + (c19 * (1 * 2)))] + ((buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t172 * ((1 * 8) * 8))) + (t171 * (((1 * 8) * 8) * 2))) + (c21 * ((((1 * 8) * 8) * 2) * 3))) + (c19 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (1 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_Blocal_diquark_r1_i[(0 + (0 * 1))]) + (buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t174 * ((1 * 8) * 8))) + (t173 * (((1 * 8) * 8) * 2))) + (c21 * ((((1 * 8) * 8) * 2) * 3))) + (c19 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (1 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_Blocal_diquark_r1_r[(0 + (0 * 1))])));
                                                                };
                                                        };
                                                };
                                                for (int32_t c17 = 0; (c17 <= 2); (c17 += 1))
                                                {
                                                        for (int32_t c19 = 0; (c19 <= 1); (c19 += 1))
                                                        {
                                                                buf_B1_Blocal_r1_r[(((((((0 + (0 * 1)) + (c19 * (1 * 1))) + (c17 * ((1 * 1) * 2))) + (c13 * (((1 * 1) * 2) * 3))) + (c11 * ((((1 * 1) * 2) * 3) * 2))) + (c9 * (((((1 * 1) * 2) * 3) * 2) * 3))) + (c7 * ((((((1 * 1) * 2) * 3) * 2) * 3) * 2)))] = (buf_B1_Blocal_r1_r[(((((((0 + (0 * 1)) + (c19 * (1 * 1))) + (c17 * ((1 * 1) * 2))) + (c13 * (((1 * 1) * 2) * 3))) + (c11 * ((((1 * 1) * 2) * 3) * 2))) + (c9 * (((((1 * 1) * 2) * 3) * 2) * 3))) + (c7 * ((((((1 * 1) * 2) * 3) * 2) * 3) * 2)))] + ((buf_src_psi_B1_r[((0 + (0 * 1)) + (c15 * (1 * 1)))] * buf_B1_Blocal_props_r1_r[((0 + (c19 * 1)) + (c17 * (1 * 2)))]) - (buf_src_psi_B1_i[((0 + (0 * 1)) + (c15 * (1 * 1)))] * buf_B1_Blocal_props_r1_i[((0 + (c19 * 1)) + (c17 * (1 * 2)))])));
                                                                buf_B1_Blocal_r1_i[(((((((0 + (0 * 1)) + (c19 * (1 * 1))) + (c17 * ((1 * 1) * 2))) + (c13 * (((1 * 1) * 2) * 3))) + (c11 * ((((1 * 1) * 2) * 3) * 2))) + (c9 * (((((1 * 1) * 2) * 3) * 2) * 3))) + (c7 * ((((((1 * 1) * 2) * 3) * 2) * 3) * 2)))] = (buf_B1_Blocal_r1_i[(((((((0 + (0 * 1)) + (c19 * (1 * 1))) + (c17 * ((1 * 1) * 2))) + (c13 * (((1 * 1) * 2) * 3))) + (c11 * ((((1 * 1) * 2) * 3) * 2))) + (c9 * (((((1 * 1) * 2) * 3) * 2) * 3))) + (c7 * ((((((1 * 1) * 2) * 3) * 2) * 3) * 2)))] + ((buf_src_psi_B1_r[((0 + (0 * 1)) + (c15 * (1 * 1)))] * buf_B1_Blocal_props_r1_i[((0 + (c19 * 1)) + (c17 * (1 * 2)))]) + (buf_src_psi_B1_i[((0 + (0 * 1)) + (c15 * (1 * 1)))] * buf_B1_Blocal_props_r1_r[((0 + (c19 * 1)) + (c17 * (1 * 2)))])));
                                                        };
                                                };
                                        };
                                };
                        };
                };
        };
};
double *_B1_Blocal_r1_i_diquark_b21;
double *_B1_Blocal_r1_i_init_b17;
double *_B1_Blocal_r1_i_props_b23;
double *_B1_Blocal_r1_i_props_init_b19;
double *_B1_Blocal_r1_i_update_b25;
double *_B1_Blocal_r1_r_diquark_b20;
double *_B1_Blocal_r1_r_init_b16;
double *_B1_Blocal_r1_r_props_b22;
double *_B1_Blocal_r1_r_props_init_b18;
double *_B1_Blocal_r1_r_update_b24;
double *_B1_prop_i_b3;
double *_B1_prop_r_b2;
double *_C_i_b1;
double *_C_r_b0;
int32_t *_sigs_b15;
int32_t *_snk_color_weights_b11;
double *_snk_psi_i_b7;
double *_snk_psi_r_b6;
int32_t *_snk_spin_weights_b12;
double *_snk_weights_b13;
int32_t *_src_color_weights_b8;
double *_src_psi_B1_i_b5;
double *_src_psi_B1_r_b4;
int32_t *_src_spin_weights_b9;
int32_t *_src_spins_b14;
double *_src_weights_b10;
double *buf_B1_Blocal_diquark_r1_i;
double *buf_B1_Blocal_diquark_r1_r;
double *buf_B1_Blocal_diquark_r2_i;
double *buf_B1_Blocal_diquark_r2_r;
double *buf_B1_Blocal_props_r1_i;
double *buf_B1_Blocal_props_r1_r;
double *buf_B1_Blocal_props_r2_i;
double *buf_B1_Blocal_props_r2_r;
double *buf_B1_Blocal_r1_i;
double *buf_B1_Blocal_r1_r;
double *buf_B1_Blocal_r2_i;
double *buf_B1_Blocal_r2_r;
double *buf_B1_prop_i;
double *buf_B1_prop_r;
double *buf_C_i;
double *buf_C_prop_i;
double *buf_C_prop_r;
double *buf_C_r;
double *buf_new_term_i_b1;
double *buf_new_term_r_b1;
int32_t *buf_sigs;
int32_t *buf_snk_color_weights;
double *buf_snk_psi_i;
double *buf_snk_psi_r;
int32_t *buf_snk_spin_weights;
double *buf_snk_weights;
int32_t *buf_src_color_weights;
double *buf_src_psi_B1_i;
double *buf_src_psi_B1_r;
int32_t *buf_src_spin_weights;
double *buf_src_weights;
int32_t *src_spins;
extern "C" void* tiramisu_make_fused_baryon_blocks_correlator(double *buf_C_r_cpu, double *buf_C_i_cpu, double *B1_prop_r_cpu, double *B1_prop_i_cpu, double *src_psi_B1_r_cpu, double *src_psi_B1_i_cpu, double *snk_psi_r_cpu, double *snk_psi_i_cpu, int32_t *src_color_weights_cpu, int32_t *src_spin_weights_cpu, double *src_weights_cpu, int32_t *src_spins_cpu, int32_t *snk_color_weights_cpu, int32_t *snk_spin_weights_cpu, double *snk_weights_cpu, int32_t *sigs_cpu, double *buf_B1_Blocal_r1_r_cpu, double *buf_B1_Blocal_r1_i_cpu)
{
        _B1_Blocal_r1_i_diquark_b21 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (8 - 0) * (12 - 0) * sizeof(double));
        _B1_Blocal_r1_i_init_b17 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (1 - 0) * sizeof(double));
        _B1_Blocal_r1_i_props_b23 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (8 - 0) * (12 - 0) * (3 - 0) * (2 - 0) * sizeof(double));
        _B1_Blocal_r1_i_props_init_b19 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (8 - 0) * (3 - 0) * (2 - 0) * sizeof(double));
        _B1_Blocal_r1_i_update_b25 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (8 - 0) * (3 - 0) * (2 - 0) * (1 - 0) * sizeof(double));
        _B1_Blocal_r1_r_diquark_b20 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (8 - 0) * (12 - 0) * sizeof(double));
        _B1_Blocal_r1_r_init_b16 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (1 - 0) * sizeof(double));
        _B1_Blocal_r1_r_props_b22 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (8 - 0) * (12 - 0) * (3 - 0) * (2 - 0) * sizeof(double));
        _B1_Blocal_r1_r_props_init_b18 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (8 - 0) * (3 - 0) * (2 - 0) * sizeof(double));
        _B1_Blocal_r1_r_update_b24 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (8 - 0) * (3 - 0) * (2 - 0) * (1 - 0) * sizeof(double));
        _B1_prop_i_b3 = (double*)malloc((3 - 0) * (1 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (8 - 0) * (8 - 0) * sizeof(double));
        _B1_prop_r_b2 = (double*)malloc((3 - 0) * (1 - 0) * (3 - 0) * (2 - 0) * (3 - 0) * (2 - 0) * (8 - 0) * (8 - 0) * sizeof(double));
        _C_i_b1 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (2 - 0) * (1 - 0) * (2 - 0) * (1 - 0) * sizeof(double));
        _C_r_b0 = (double*)malloc((1 - 0) * (4 - 0) * (2 - 0) * (2 - 0) * (1 - 0) * (2 - 0) * (1 - 0) * sizeof(double));
        _sigs_b15 = (int32_t*)malloc((2 - 0) * sizeof(int32_t));
        _snk_color_weights_b11 = (int32_t*)malloc((2 - 0) * (2 - 0) * (12 - 0) * (3 - 0) * sizeof(int32_t));
        _snk_psi_i_b7 = (double*)malloc((8 - 0) * (1 - 0) * sizeof(double));
        _snk_psi_r_b6 = (double*)malloc((8 - 0) * (1 - 0) * sizeof(double));
        _snk_spin_weights_b12 = (int32_t*)malloc((2 - 0) * (2 - 0) * (12 - 0) * (3 - 0) * sizeof(int32_t));
        _snk_weights_b13 = (double*)malloc((2 - 0) * (12 - 0) * sizeof(double));
        _src_color_weights_b8 = (int32_t*)malloc((2 - 0) * (12 - 0) * (3 - 0) * sizeof(int32_t));
        _src_psi_B1_i_b5 = (double*)malloc((8 - 0) * (1 - 0) * sizeof(double));
        _src_psi_B1_r_b4 = (double*)malloc((8 - 0) * (1 - 0) * sizeof(double));
        _src_spin_weights_b9 = (int32_t*)malloc((2 - 0) * (12 - 0) * (3 - 0) * sizeof(int32_t));
        _src_spins_b14 = (int32_t*)malloc((2 - 0) * sizeof(int32_t));
        _src_weights_b10 = (double*)malloc((2 - 0) * (12 - 0) * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_diquark_r1_i, 1 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_diquark_r1_r, 1 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_diquark_r2_i, 1 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_diquark_r2_r, 1 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_props_r1_i, 3 * 2 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_props_r1_r, 3 * 2 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_props_r2_i, 3 * 2 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_props_r2_r, 3 * 2 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_r1_i, 3 * 2 * 3 * 2 * 3 * 2 * 1 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_r1_r, 3 * 2 * 3 * 2 * 3 * 2 * 1 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_r2_i, 3 * 2 * 3 * 2 * 3 * 2 * 1 * sizeof(double));
        cudaMalloc(&buf_B1_Blocal_r2_r, 3 * 2 * 3 * 2 * 3 * 2 * 1 * sizeof(double));
        cudaMalloc(&buf_B1_prop_i, 3 * 1 * 3 * 2 * 3 * 2 * 8 * 8 * sizeof(double));
        cudaMalloc(&buf_B1_prop_r, 3 * 1 * 3 * 2 * 3 * 2 * 8 * 8 * sizeof(double));
        cudaMalloc(&buf_C_i, 1 * 4 * 2 * 1 * 2 * 1 * sizeof(double));
        cudaMalloc(&buf_C_prop_i, 1 * 4 * 2 * 2 * 1 * 2 * sizeof(double));
        cudaMalloc(&buf_C_prop_r, 1 * 4 * 2 * 2 * 1 * 2 * sizeof(double));
        cudaMalloc(&buf_C_r, 1 * 4 * 2 * 1 * 2 * 1 * sizeof(double));
        cudaMalloc(&buf_new_term_i_b1, 1 * 4 * 2 * 2 * 1 * 2 * 2 * 12 * sizeof(double));
        cudaMalloc(&buf_new_term_r_b1, 1 * 4 * 2 * 2 * 1 * 2 * 2 * 12 * sizeof(double));
        cudaMalloc(&buf_sigs, 2 * sizeof(int32_t));
        cudaMalloc(&buf_snk_color_weights, 2 * 2 * 12 * 3 * sizeof(int32_t));
        cudaMalloc(&buf_snk_psi_i, 8 * 1 * sizeof(double));
        cudaMalloc(&buf_snk_psi_r, 8 * 1 * sizeof(double));
        cudaMalloc(&buf_snk_spin_weights, 2 * 2 * 12 * 3 * sizeof(int32_t));
        cudaMalloc(&buf_snk_weights, 2 * 12 * sizeof(double));
        cudaMalloc(&buf_src_color_weights, 2 * 12 * 3 * sizeof(int32_t));
        cudaMalloc(&buf_src_psi_B1_i, 8 * 1 * sizeof(double));
        cudaMalloc(&buf_src_psi_B1_r, 8 * 1 * sizeof(double));
        cudaMalloc(&buf_src_spin_weights, 2 * 12 * 3 * sizeof(int32_t));
        cudaMalloc(&buf_src_weights, 2 * 12 * sizeof(double));
        cudaMalloc(&src_spins, 2 * sizeof(int32_t));
        cudaMemcpy(buf_C_r, buf_C_r_cpu, 1 * 4 * 2 * 1 * 2 * 1 * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_C_i, buf_C_i_cpu, 1 * 4 * 2 * 1 * 2 * 1 * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_B1_prop_r, B1_prop_r_cpu, 3 * 1 * 3 * 2 * 3 * 2 * 8 * 8 * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_B1_prop_i, B1_prop_i_cpu, 3 * 1 * 3 * 2 * 3 * 2 * 8 * 8 * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_src_psi_B1_r, src_psi_B1_r_cpu, 8 * 1 * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_src_psi_B1_i, src_psi_B1_i_cpu, 8 * 1 * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_snk_psi_r, snk_psi_r_cpu, 8 * 1 * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_snk_psi_i, snk_psi_i_cpu, 8 * 1 * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_src_color_weights, src_color_weights_cpu, 2 * 12 * 3 * sizeof(int32_t), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_src_spin_weights, src_spin_weights_cpu, 2 * 12 * 3 * sizeof(int32_t), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_src_weights, src_weights_cpu, 2 * 12 * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(src_spins, src_spins_cpu, 2 * sizeof(int32_t), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_snk_color_weights, snk_color_weights_cpu, 2 * 2 * 12 * 3 * sizeof(int32_t), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_snk_spin_weights, snk_spin_weights_cpu, 2 * 2 * 12 * 3 * sizeof(int32_t), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_snk_weights, snk_weights_cpu, 2 * 12 * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(buf_sigs, sigs_cpu, 2 * sizeof(int32_t), cudaMemcpyHostToDevice);
        {
                dim3 blocks((3 + 1), 1, 1);
                dim3 threads((1 + 1), 1, 1);
                _kernel_0<<<blocks, threads>>>(buf_B1_Blocal_diquark_r1_i, buf_B1_Blocal_diquark_r1_r, buf_B1_Blocal_props_r1_i, buf_B1_Blocal_props_r1_r, buf_B1_Blocal_r1_i, buf_B1_Blocal_r1_r, buf_B1_prop_i, buf_B1_prop_r, buf_src_color_weights, buf_src_psi_B1_i, buf_src_psi_B1_r, buf_src_spin_weights, buf_src_weights);
        };
        cudaMemcpy(B1_prop_r_cpu, buf_B1_prop_r, 3 * 1 * 3 * 2 * 3 * 2 * 8 * 8 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(B1_prop_i_cpu, buf_B1_prop_i, 3 * 1 * 3 * 2 * 3 * 2 * 8 * 8 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(src_psi_B1_r_cpu, buf_src_psi_B1_r, 8 * 1 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(src_psi_B1_i_cpu, buf_src_psi_B1_i, 8 * 1 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(snk_psi_r_cpu, buf_snk_psi_r, 8 * 1 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(snk_psi_i_cpu, buf_snk_psi_i, 8 * 1 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(src_color_weights_cpu, buf_src_color_weights, 2 * 12 * 3 * sizeof(int32_t), cudaMemcpyDeviceToHost);
        cudaMemcpy(src_spin_weights_cpu, buf_src_spin_weights, 2 * 12 * 3 * sizeof(int32_t), cudaMemcpyDeviceToHost);
        cudaMemcpy(src_weights_cpu, buf_src_weights, 2 * 12 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(src_spins_cpu, src_spins, 2 * sizeof(int32_t), cudaMemcpyDeviceToHost);
        cudaMemcpy(snk_color_weights_cpu, buf_snk_color_weights, 2 * 2 * 12 * 3 * sizeof(int32_t), cudaMemcpyDeviceToHost);
        cudaMemcpy(snk_spin_weights_cpu, buf_snk_spin_weights, 2 * 2 * 12 * 3 * sizeof(int32_t), cudaMemcpyDeviceToHost);
        cudaMemcpy(snk_weights_cpu, buf_snk_weights, 2 * 12 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(sigs_cpu, buf_sigs, 2 * sizeof(int32_t), cudaMemcpyDeviceToHost);
        cudaMemcpy(buf_C_r_cpu, buf_C_r, 1 * 4 * 2 * 1 * 2 * 1 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(buf_C_i_cpu, buf_C_i, 1 * 4 * 2 * 1 * 2 * 1 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(buf_B1_Blocal_r1_i_cpu, buf_B1_Blocal_r1_i, 3 * 2 * 3 * 2 * 3 * 2 * 1 * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(buf_B1_Blocal_r1_r_cpu, buf_B1_Blocal_r1_r, 3 * 2 * 3 * 2 * 3 * 2 * 1 * sizeof(double), cudaMemcpyDeviceToHost);
        free(_B1_Blocal_r1_i_diquark_b21);
        free(_B1_Blocal_r1_i_init_b17);
        free(_B1_Blocal_r1_i_props_b23);
        free(_B1_Blocal_r1_i_props_init_b19);
        free(_B1_Blocal_r1_i_update_b25);
        free(_B1_Blocal_r1_r_diquark_b20);
        free(_B1_Blocal_r1_r_init_b16);
        free(_B1_Blocal_r1_r_props_b22);
        free(_B1_Blocal_r1_r_props_init_b18);
        free(_B1_Blocal_r1_r_update_b24);
        free(_B1_prop_i_b3);
        free(_B1_prop_r_b2);
        free(_C_i_b1);
        free(_C_r_b0);
        free(_sigs_b15);
        free(_snk_color_weights_b11);
        free(_snk_psi_i_b7);
        free(_snk_psi_r_b6);
        free(_snk_spin_weights_b12);
        free(_snk_weights_b13);
        free(_src_color_weights_b8);
        free(_src_psi_B1_i_b5);
        free(_src_psi_B1_r_b4);
        free(_src_spin_weights_b9);
        free(_src_spins_b14);
        free(_src_weights_b10);
        cudaFree(buf_B1_Blocal_diquark_r1_i);
        cudaFree(buf_B1_Blocal_diquark_r1_r);
        cudaFree(buf_B1_Blocal_diquark_r2_i);
        cudaFree(buf_B1_Blocal_diquark_r2_r);
        cudaFree(buf_B1_Blocal_props_r1_i);
        cudaFree(buf_B1_Blocal_props_r1_r);
        cudaFree(buf_B1_Blocal_props_r2_i);
        cudaFree(buf_B1_Blocal_props_r2_r);
        cudaFree(buf_B1_Blocal_r1_i);
        cudaFree(buf_B1_Blocal_r1_r);
        cudaFree(buf_B1_Blocal_r2_i);
        cudaFree(buf_B1_Blocal_r2_r);
        cudaFree(buf_B1_prop_i);
        cudaFree(buf_B1_prop_r);
        cudaFree(buf_C_i);
        cudaFree(buf_C_prop_i);
        cudaFree(buf_C_prop_r);
        cudaFree(buf_C_r);
        cudaFree(buf_new_term_i_b1);
        cudaFree(buf_new_term_r_b1);
        cudaFree(buf_sigs);
        cudaFree(buf_snk_color_weights);
        cudaFree(buf_snk_psi_i);
        cudaFree(buf_snk_psi_r);
        cudaFree(buf_snk_spin_weights);
        cudaFree(buf_snk_weights);
        cudaFree(buf_src_color_weights);
        cudaFree(buf_src_psi_B1_i);
        cudaFree(buf_src_psi_B1_r);
        cudaFree(buf_src_spin_weights);
        cudaFree(buf_src_weights);
        cudaFree(src_spins);
}
static __global__ void _kernel_0(double *buf_B1_Blocal_diquark_r1_i, double *buf_B1_Blocal_diquark_r1_r, double *buf_B1_Blocal_props_r1_i, double *buf_B1_Blocal_props_r1_r, double *buf_B1_Blocal_r1_i, double *buf_B1_Blocal_r1_r, double *buf_B1_prop_i, double *buf_B1_prop_r, int32_t *buf_src_color_weights, double *buf_src_psi_B1_i, double *buf_src_psi_B1_r, int32_t *buf_src_spin_weights, double *buf_src_weights)
{
        const int32_t __bx__ = (blockIdx.x + 0);
        const int32_t __tx__ = (threadIdx.x + 0);
        for (int32_t c7 = 0; (c7 <= 2); (c7 += 1))
        {
                for (int32_t c9 = 0; (c9 <= 1); (c9 += 1))
                {
                        for (int32_t c11 = 0; (c11 <= 2); (c11 += 1))
                        {
                                for (int32_t c13 = 0; (c13 <= 1); (c13 += 1))
                                {
                                        for (int32_t c15 = 0; (c15 <= 2); (c15 += 1))
                                        {
                                                for (int32_t c17 = 0; (c17 <= 1); (c17 += 1))
                                                {
                                                        buf_B1_Blocal_r1_r[(((((((0 + (0 * 1)) + (c17 * (1 * 1))) + (c15 * ((1 * 1) * 2))) + (c13 * (((1 * 1) * 2) * 3))) + (c11 * ((((1 * 1) * 2) * 3) * 2))) + (c9 * (((((1 * 1) * 2) * 3) * 2) * 3))) + (c7 * ((((((1 * 1) * 2) * 3) * 2) * 3) * 2)))] = 0;
                                                        buf_B1_Blocal_r1_i[(((((((0 + (0 * 1)) + (c17 * (1 * 1))) + (c15 * ((1 * 1) * 2))) + (c13 * (((1 * 1) * 2) * 3))) + (c11 * ((((1 * 1) * 2) * 3) * 2))) + (c9 * (((((1 * 1) * 2) * 3) * 2) * 3))) + (c7 * ((((((1 * 1) * 2) * 3) * 2) * 3) * 2)))] = 0;
                                                };
                                        };
                                };
                        };
                };
        };
        for (int32_t c7 = 0; (c7 <= 2); (c7 += 1))
        {
                for (int32_t c9 = 0; (c9 <= 1); (c9 += 1))
                {
                        for (int32_t c11 = 0; (c11 <= 2); (c11 += 1))
                        {
                                for (int32_t c13 = 0; (c13 <= 1); (c13 += 1))
                                {
                                        for (int32_t c15 = 0; (c15 <= 7); (c15 += 1))
                                        {
                                                for (int32_t c17 = 0; (c17 <= 2); (c17 += 1))
                                                {
                                                        for (int32_t c19 = 0; (c19 <= 1); (c19 += 1))
                                                        {
                                                                buf_B1_Blocal_props_r1_r[((0 + (c19 * 1)) + (c17 * (1 * 2)))] = 0;
                                                                buf_B1_Blocal_props_r1_i[((0 + (c19 * 1)) + (c17 * (1 * 2)))] = 0;
                                                        };
                                                };
                                                for (int32_t c17 = 0; (c17 <= 11); (c17 += 1))
                                                {
                                                        const int32_t t119 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t120 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t121 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t122 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t123 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t124 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t125 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t126 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        buf_B1_Blocal_diquark_r1_r[(0 + (0 * 1))] = (((buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t120 * ((1 * 8) * 8))) + (t119 * (((1 * 8) * 8) * 2))) + (c9 * ((((1 * 8) * 8) * 2) * 3))) + (c7 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (0 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t122 * ((1 * 8) * 8))) + (t121 * (((1 * 8) * 8) * 2))) + (c13 * ((((1 * 8) * 8) * 2) * 3))) + (c11 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (2 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))]) - (buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t124 * ((1 * 8) * 8))) + (t123 * (((1 * 8) * 8) * 2))) + (c9 * ((((1 * 8) * 8) * 2) * 3))) + (c7 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (0 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t126 * ((1 * 8) * 8))) + (t125 * (((1 * 8) * 8) * 2))) + (c13 * ((((1 * 8) * 8) * 2) * 3))) + (c11 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (2 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))])) * buf_src_weights[((0 + (c17 * 1)) + (0 * (1 * 12)))]);
                                                        const int32_t t137 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t138 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t139 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t140 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t141 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t142 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 0))];
                                                        const int32_t t143 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        const int32_t t144 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 2))];
                                                        buf_B1_Blocal_diquark_r1_i[(0 + (0 * 1))] = (((buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t138 * ((1 * 8) * 8))) + (t137 * (((1 * 8) * 8) * 2))) + (c9 * ((((1 * 8) * 8) * 2) * 3))) + (c7 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (0 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t140 * ((1 * 8) * 8))) + (t139 * (((1 * 8) * 8) * 2))) + (c13 * ((((1 * 8) * 8) * 2) * 3))) + (c11 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (2 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))]) + (buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t142 * ((1 * 8) * 8))) + (t141 * (((1 * 8) * 8) * 2))) + (c9 * ((((1 * 8) * 8) * 2) * 3))) + (c7 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (0 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t144 * ((1 * 8) * 8))) + (t143 * (((1 * 8) * 8) * 2))) + (c13 * ((((1 * 8) * 8) * 2) * 3))) + (c11 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (2 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))])) * buf_src_weights[((0 + (c17 * 1)) + (0 * (1 * 12)))]);
                                                        for (int32_t c19 = 0; (c19 <= 2); (c19 += 1))
                                                        {
                                                                for (int32_t c21 = 0; (c21 <= 1); (c21 += 1))
                                                                {
                                                                        const int32_t t155 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t156 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t157 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t158 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        buf_B1_Blocal_props_r1_r[((0 + (c21 * 1)) + (c19 * (1 * 2)))] = (buf_B1_Blocal_props_r1_r[((0 + (c21 * 1)) + (c19 * (1 * 2)))] + ((buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t156 * ((1 * 8) * 8))) + (t155 * (((1 * 8) * 8) * 2))) + (c21 * ((((1 * 8) * 8) * 2) * 3))) + (c19 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (1 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_Blocal_diquark_r1_r[(0 + (0 * 1))]) - (buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t158 * ((1 * 8) * 8))) + (t157 * (((1 * 8) * 8) * 2))) + (c21 * ((((1 * 8) * 8) * 2) * 3))) + (c19 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (1 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_Blocal_diquark_r1_i[(0 + (0 * 1))])));
                                                                        const int32_t t171 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t172 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t173 = buf_src_color_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        const int32_t t174 = buf_src_spin_weights[(((0 + (((1 * 3) * 12) * 0)) + ((1 * 3) * c17)) + (1 * 1))];
                                                                        buf_B1_Blocal_props_r1_i[((0 + (c21 * 1)) + (c19 * (1 * 2)))] = (buf_B1_Blocal_props_r1_i[((0 + (c21 * 1)) + (c19 * (1 * 2)))] + ((buf_B1_prop_r[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t172 * ((1 * 8) * 8))) + (t171 * (((1 * 8) * 8) * 2))) + (c21 * ((((1 * 8) * 8) * 2) * 3))) + (c19 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (1 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_Blocal_diquark_r1_i[(0 + (0 * 1))]) + (buf_B1_prop_i[((((((((0 + (c15 * 1)) + (((2 * __bx__) + __tx__) * (1 * 8))) + (t174 * ((1 * 8) * 8))) + (t173 * (((1 * 8) * 8) * 2))) + (c21 * ((((1 * 8) * 8) * 2) * 3))) + (c19 * (((((1 * 8) * 8) * 2) * 3) * 2))) + (0 * ((((((1 * 8) * 8) * 2) * 3) * 2) * 3))) + (1 * (((((((1 * 8) * 8) * 2) * 3) * 2) * 3) * 1)))] * buf_B1_Blocal_diquark_r1_r[(0 + (0 * 1))])));
                                                                };
                                                        };
                                                };
                                                for (int32_t c17 = 0; (c17 <= 2); (c17 += 1))
                                                {
                                                        for (int32_t c19 = 0; (c19 <= 1); (c19 += 1))
                                                        {
                                                                int index = (((((((0 + (0 * 1)) + (c19 * (1 * 1))) + (c17 * ((1 * 1) * 2))) + (c13 * (((1 * 1) * 2) * 3))) + (c11 * ((((1 * 1) * 2) * 3) * 2))) + (c9 * (((((1 * 1) * 2) * 3) * 2) * 3))) + (c7 * ((((((1 * 1) * 2) * 3) * 2) * 3) * 2)));
                                                                buf_B1_Blocal_r1_r[index] = (buf_B1_Blocal_r1_r[index] + ((buf_src_psi_B1_r[((0 + (0 * 1)) + (c15 * (1 * 1)))] * buf_B1_Blocal_props_r1_r[((0 + (c19 * 1)) + (c17 * (1 * 2)))]) - (buf_src_psi_B1_i[((0 + (0 * 1)) + (c15 * (1 * 1)))] * buf_B1_Blocal_props_r1_i[((0 + (c19 * 1)) + (c17 * (1 * 2)))])));
                                                                buf_B1_Blocal_r1_i[index] = (buf_B1_Blocal_r1_i[index] + ((buf_src_psi_B1_r[((0 + (0 * 1)) + (c15 * (1 * 1)))] * buf_B1_Blocal_props_r1_i[((0 + (c19 * 1)) + (c17 * (1 * 2)))]) + (buf_src_psi_B1_i[((0 + (0 * 1)) + (c15 * (1 * 1)))] * buf_B1_Blocal_props_r1_r[((0 + (c19 * 1)) + (c17 * (1 * 2)))])));
                                                                // buf_B1_Blocal_r1_r[*] = buf_B1_Blocal_r1_r[*] + buf_src_psi_B1_r[*] * buf_B1_Blocal_props_r1_r[*] - buf_src_psi_B1_i[*] * buf_B1_Blocal_props_r1_i[*];
                                                                // buf_B1_Blocal_r1_r[*] = buf_B1_Blocal_r1_r[*] + buf_src_psi_B1_r[*] * buf_B1_Blocal_props_r1_r[*] - buf_src_psi_B1_i[*] * buf_B1_Blocal_props_r1_i[*];
                                                        };
                                                };
                                        };
                                };
                        };
                };
        };
};
extern "C" int32_t _kernel_0_wrapper(double *buf_B1_Blocal_diquark_r1_i, double *buf_B1_Blocal_diquark_r1_r, double *buf_B1_Blocal_props_r1_i, double *buf_B1_Blocal_props_r1_r, double *buf_B1_Blocal_r1_i, double *buf_B1_Blocal_r1_r, double *buf_B1_prop_i, double *buf_B1_prop_r, int32_t *buf_src_color_weights, double *buf_src_psi_B1_i, double *buf_src_psi_B1_r, int32_t *buf_src_spin_weights, double *buf_src_weights)
{
        {
                dim3 blocks((3 + 1), 1, 1);
                dim3 threads((1 + 1), 1, 1);
                _kernel_0<<<blocks, threads>>>(buf_B1_Blocal_diquark_r1_i, buf_B1_Blocal_diquark_r1_r, buf_B1_Blocal_props_r1_i, buf_B1_Blocal_props_r1_r, buf_B1_Blocal_r1_i, buf_B1_Blocal_r1_r, buf_B1_prop_i, buf_B1_prop_r, buf_src_color_weights, buf_src_psi_B1_i, buf_src_psi_B1_r, buf_src_spin_weights, buf_src_weights);
        };
        return 0;
}
[gen_halide_stmt function]
|   


C like code:
{
  C210(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C214(10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C218(20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C222(30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C226(40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C230(50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C234(60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C238(70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C242(80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C246(90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C250(100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C254(110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C258(120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C262(130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C266(140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C270(150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  for (int c3 = 0; c3 <= 3; c3 += 1)
    for (int c5 = 0; c5 <= 1; c5 += 1) {
      for (int c7 = 0; c7 <= 2; c7 += 1)
        for (int c9 = 0; c9 <= 1; c9 += 1)
          for (int c11 = 0; c11 <= 2; c11 += 1)
            for (int c13 = 0; c13 <= 1; c13 += 1)
              for (int c15 = 0; c15 <= 2; c15 += 1)
                for (int c17 = 0; c17 <= 1; c17 += 1) {
                  B1_Blocal_r1_r_init(150, 0, 10, c3, 0, c5, 0, c7, 0, c9, 0, c11, 0, c13, 0, c15, 0, c17, 0, 0, 0, 0, 0);
                  B1_Blocal_r1_i_init(150, 0, 10, c3, 0, c5, 0, c7, 0, c9, 0, c11, 0, c13, 0, c15, 0, c17, 10, 0, 0, 0, 0);
                }
      for (int c7 = 0; c7 <= 2; c7 += 1)
        for (int c9 = 0; c9 <= 1; c9 += 1)
          for (int c11 = 0; c11 <= 2; c11 += 1)
            for (int c13 = 0; c13 <= 1; c13 += 1)
              for (int c15 = 0; c15 <= 7; c15 += 1) {
                for (int c17 = 0; c17 <= 2; c17 += 1)
                  for (int c19 = 0; c19 <= 1; c19 += 1) {
                    B1_Blocal_r1_r_props_init(150, 0, 10, c3, 0, c5, 10, c7, 0, c9, 0, c11, 0, c13, 0, c15, 0, c17, 0, c19, 0, 0, 0);
                    B1_Blocal_r1_i_props_init(150, 0, 10, c3, 0, c5, 10, c7, 0, c9, 0, c11, 0, c13, 0, c15, 0, c17, 0, c19, 10, 0, 0);
                  }
                for (int c17 = 0; c17 <= 11; c17 += 1) {
                  B1_Blocal_r1_r_diquark(150, 0, 10, c3, 0, c5, 10, c7, 0, c9, 0, c11, 0, c13, 0, c15, 10, c17, 0, 0, 0, 0, 0);
                  B1_Blocal_r1_i_diquark(150, 0, 10, c3, 0, c5, 10, c7, 0, c9, 0, c11, 0, c13, 0, c15, 10, c17, 10, 0, 0, 0, 0);
                  for (int c19 = 0; c19 <= 2; c19 += 1)
                    for (int c21 = 0; c21 <= 1; c21 += 1) {
                      B1_Blocal_r1_r_props(150, 0, 10, c3, 0, c5, 10, c7, 0, c9, 0, c11, 0, c13, 0, c15, 10, c17, 20, c19, 0, c21, 0);
                      B1_Blocal_r1_i_props(150, 0, 10, c3, 0, c5, 10, c7, 0, c9, 0, c11, 0, c13, 0, c15, 10, c17, 20, c19, 0, c21, 10);
                    }
                }
                for (int c17 = 0; c17 <= 2; c17 += 1)
                  for (int c19 = 0; c19 <= 1; c19 += 1) {
                    B1_Blocal_r1_r_update(150, 0, 10, c3, 0, c5, 10, c7, 0, c9, 0, c11, 0, c13, 0, c15, 20, c17, 0, c19, 0, 0, 0);
                    B1_Blocal_r1_i_update(150, 0, 10, c3, 0, c5, 10, c7, 0, c9, 0, c11, 0, c13, 0, c15, 20, c17, 0, c19, 0, 0, 10);
                  }
              }
    }
  C282(160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C286(170, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C290(180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C294(190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C298(200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C302(210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C306(220, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C310(230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C314(240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C318(250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C322(260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C326(270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C330(280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C334(290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C274(300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C278(310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C338(320, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  C342(330, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}



