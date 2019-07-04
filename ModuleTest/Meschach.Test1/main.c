 #include <stdio.h>
#include "mesch12b/matrix.h"
int main() {
	int ns = 1846, ntr = 500;
	MAT *A;
	A = m_get(ns,ntr);
	//m_free(A);
	getchar();
	return 0;
}