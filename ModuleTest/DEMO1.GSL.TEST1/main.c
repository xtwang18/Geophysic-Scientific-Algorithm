#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "./include/gsl/gsl_sf_bessel.h"
#include "./include/gsl/gsl_matrix.h"

int main(void)
{
	int ns = 1846, ntr = 500;
	gsl_matrix * m = gsl_matrix_float_alloc(ns,ntr);

	//Fill Matrix from binary file
	FILE * fp = fopen("seis.bin","rb");
	if (fp == NULL)
	{
		printf("open error\n");
		getchar();
		exit(1);
	}
	gsl_matrix_float_fread(fp,m);

	//Examine value of matrix 
	for (size_t i = ns - 1; i > ns - 10; i--)
	{
		printf("%e\n", gsl_matrix_float_get(m,i,ntr - 1));
	}


	//Dispose Resources
	gsl_matrix_float_free(m);
	fclose(fp);
	fp = NULL;

	getchar();
	return 0;
}