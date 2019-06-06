#include <stdio.h>
#include <string.h>
#include "segy.h"
int main() {
	bhed re = {0}; //二进制
	segy tr = {0};

	int dt = 0;//采样间隔
	int ns = 0;//每道采样点数
	int ntr = 0;//总道数

	const char * p = "shots.segy";
	const char *p1 = "out.segy";
	getSgyInfo(p, &re, &ntr, &ns, &dt);

	//打印地震道相关信息
	printf("ns : %d, dt : %d, traces: %d\n",re.hns,re.hdt,re.ntrpr);
	printf("%d,%d,%d\n",ntr,ns,dt);
	float* trace =(float *)malloc(ns*sizeof(float));
	
	for (int itr = 0; itr < ntr; itr++)
	{
	 	segyread(p, &tr, trace, itr);

		//if (itr % 2 == 0)
		//	memset(trace,0,sizeof(float)*ns); 

	 	segywriteIBM(p1, re, tr, trace, itr);
	}

	free(trace);
	trace = NULL;
	getchar();
	return 0;
}