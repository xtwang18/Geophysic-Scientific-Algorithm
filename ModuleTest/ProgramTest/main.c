#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ReadBinFile(float **seis);
void CreateBinFile(float **seis);
int ns = 1846, ntr = 500;
int main() {
	//�����ά�������ڴ������

	float ** seisiy = NULL;
	//int a[5] = { 1,3,5,7,9 };
	seisiy = (float **)malloc(sizeof(float*)*ns);
	for (size_t i = 0; i < ns; i++)
	{
		seisiy[i] = (float*)malloc(sizeof(float)*ntr);
	}
	//��seisiy���г�ʼ��
	for (size_t i = 0; i < ns; i++)
	{
		for (size_t j = 0; j < ntr; j++)
		{
			seisiy[i][j] = 0.;
		}
	}

	
	//��ȡ�������ļ��������ݴ�ŵ�������
	ReadBinFile(seisiy);


	//CreateBinFile(seisiy);

	 
#pragma region �ͷſռ�for
	for (size_t i = 0; i < ns; i++)
	{
		free(seisiy[i]);
		seisiy[i] = NULL;
	}
	seisiy = NULL;
	getchar();
	return 0;
#pragma endregion


}

void  ReadBinFile(float **seis) {	
	FILE *fp = fopen("seis.bin", "rb");
	if ((fp == NULL) ){
		printf("Error on open  file!");
			getch();
			exit(1);
	}
	else
	{
		for (size_t j = 0; j < ntr; j++)
		{		
			for (size_t i = 0; i < ns; i++)
			{
				fread(&seis[i][j],sizeof(float),1,fp);	
			}					 		
		}
		fclose(fp);
	}
	for (size_t i = 1845; i > 1832; i--)
	{
		printf("%e\n",seis[i][499]);
	}
}

void CreateBinFile(float **seisiy)
{
  
	FILE * fp = fopen("test.bin","wb");
	if (fp == NULL)
	{
		printf("create failed");
		getchar();
		exit(1);
	}
	else
	{
		printf("create ok");
		for (size_t i = 0; i < ns; i++)
		{
			for (size_t j = 0; j < ntr; j++)
			{
				fwrite(&seisiy[i][j], 4, 1, fp);
			}
		}
		fclose(fp);
	}
	 
}
