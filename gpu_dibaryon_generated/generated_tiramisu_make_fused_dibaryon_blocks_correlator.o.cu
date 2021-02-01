#include <stdint.h>
static __global__ void _kernel_0(int32_t c1, double *buf_C_r)
{
	const int32_t __bx__ = (blockIdx.x + 0);
	const int32_t __tx__ = (threadIdx.x + 0);
	for (int32_t c7 = 0; (c7 <= 3); (c7 += 1))
	{
		for (int32_t c9 = 0; (c9 <= 45); (c9 += 1))
		{
			for (int32_t c11 = 0; (c11 <= 3); (c11 += 1))
			{
				for (int32_t c13 = 0; (c13 <= 45); (c13 += 1))
				{
					buf_C_r[(((((((0 + (c13 * 1)) + (c11 * (1 * 46))) + (c9 * ((1 * 46) * 4))) + (c7 * (((1 * 46) * 4) * 46))) + (__tx__ * ((((1 * 46) * 4) * 46) * 4))) + (__bx__ * (((((1 * 46) * 4) * 46) * 4) * 2))) + (c1 * ((((((1 * 46) * 4) * 46) * 4) * 2) * 64)))] = 0;
				};
			};
		};
	};
};
extern "C" int32_t _kernel_0_wrapper(int32_t c1, double *buf_C_r)
{
	{
		dim3 blocks((63 + 1), 1, 1);
		dim3 threads((1 + 1), 1, 1);
		_kernel_0<<<blocks, threads>>>(c1, buf_C_r);
	};
	return 0;
};
static __global__ void _kernel_1(int32_t c1, double *buf_C_i)
{
	const int32_t __bx__ = (blockIdx.x + 0);
	const int32_t __tx__ = (threadIdx.x + 0);
	for (int32_t c7 = 0; (c7 <= 3); (c7 += 1))
	{
		for (int32_t c9 = 0; (c9 <= 45); (c9 += 1))
		{
			for (int32_t c11 = 0; (c11 <= 3); (c11 += 1))
			{
				for (int32_t c13 = 0; (c13 <= 45); (c13 += 1))
				{
					buf_C_i[(((((((0 + (c13 * 1)) + (c11 * (1 * 46))) + (c9 * ((1 * 46) * 4))) + (c7 * (((1 * 46) * 4) * 46))) + (__tx__ * ((((1 * 46) * 4) * 46) * 4))) + (__bx__ * (((((1 * 46) * 4) * 46) * 4) * 2))) + (c1 * ((((((1 * 46) * 4) * 46) * 4) * 2) * 64)))] = 0;
				};
			};
		};
	};
};
extern "C" int32_t* _kernel_1_wrapper(int32_t c1, double *buf_C_i)
{
	{
		dim3 blocks((63 + 1), 1, 1);
		dim3 threads((1 + 1), 1, 1);
		_kernel_1<<<blocks, threads>>>(c1, buf_C_i);
	};
	return 0;
}