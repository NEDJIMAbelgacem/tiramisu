#ifndef QBLOCKS_2PT_PARAMETERS_H
#define QBLOCKS_2PT_PARAMETERS_H

#define DATA_SET_1 1
#define DATA_SET_2 0

#if DATA_SET_1

#define P_Vsrc 128
#define P_Vsnk 128
#define P_Nsrc 44l
#define P_Nsnk 44l
#define P_NEntangled 3l
#define P_NsrcHex 1l
#define P_NsnkHex 1l
#define P_Nperms 36l
#define P_B1Nperms 2l
#define P_Nw 12l
#define P_Nw2 288l
#define P_Nw2Hex 32l
#define P_Nt 2l
#define P_Nc 3l
#define P_Ns 2l
#define P_Nq 3l
#define P_B2Nrows 4l
#define P_B1Nrows 2l
#define P_Nb 2l
#define P_mq 1.0
#define P_Mq 2l
#define P_B0Nrows 1l
#define P_Mw 12l
#define P_NsFull 4l
#define P_sites_per_rank 2l
#define P_src_sites_per_rank 2l
#define P_tiling_factor 2

#elif DATA_SET_2

#define P_Vsrc 16
#define P_Vsnk 16
#define P_Nsrc 44
#define P_Nsnk 44
#define P_NEntangled 3
#define P_NsrcHex 1
#define P_NsnkHex 1
#define P_Nperms 36
#define P_B1Nperms 2
#define P_Nw 12
#define P_Nw2 288
#define P_Nw2Hex 32
#define P_Nt 2
#define P_Nc 3
#define P_Ns 2
#define P_Nq 3
#define P_B2Nrows 4
#define P_B1Nrows 2
#define P_Nb 2
#define P_mq 1.0
#define P_Mq 2
#define P_B0Nrows 1
#define P_Mw 12
#define P_NsFull 4
#define P_sites_per_rank 4
#define P_src_sites_per_rank 4

#endif

#endif
