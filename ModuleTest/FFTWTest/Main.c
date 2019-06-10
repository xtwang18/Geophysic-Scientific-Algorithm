 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fftw3.h"

#pragma comment(lib, "libfftw3-3.lib") // double版本
 //#pragma comment(lib, "libfftw3f-3.lib")// float版本
// #pragma comment(lib, "libfftw3l-3.lib")// long double版本

#define PI 3.1415926


int main()
{
	int len = 4;
	fftw_complex  *in = NULL;
	// 如果要使用float版本,需先引用float版本的lib库,然后在fftw后面加上f后缀即可.
	fftw_complex *out = NULL;// fftwf_complex --> 即为float版本
	fftw_plan p;
	in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * len);
	out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * len);
	double dx = 1.0 / len;
	//printf("size of fftw_complex:%d,%d\n",sizeof(fftw_complex),sizeof(double));
	// 输入纯实数
	in[0][0] = 1;
	in[0][1] = 0;
	in[1][0] = 2;
	in[1][1] = 0;
	in[2][0] = -1;
	in[2][1] = 0;
	in[3][0] = 3;
	in[3][1] = 0;
 
	for (int i = 0; i < len; i++)
	{
		//in[i] = i + 1;//sin(2 * PI * dx*i) + sin(4 * PI * dx*i);

		printf("%d: %.2f + %.2fi\n ", i, in[i][0], in[i][1]);
	}

	printf("\n\n");

	// 傅里叶变换
	p = fftw_plan_dft_1d(len, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(p);
	
	// 输出幅度谱
	for (int i = 0; i < len; i++)
	{
		//float len = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
		printf("%d: %.2f + %.2fi\n ",i, out[i][0],out[i][1]);
	}
	printf("\n");

	// 释放资源
	fftw_destroy_plan(p);
	fftw_free(in);
	fftw_free(out);

	system("pause");
	return 0;
}
 