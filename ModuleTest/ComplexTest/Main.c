#include <complex.h>
#include <stdio.h>
int main() {
	_Dcomplex  a = _Cbuild(3, 4);
	_Dcomplex b = _Cbuild(4, 5);
	_Dcomplex c = _Cbuild(5, 6);;

	_Dcomplex d = a + b;
	_Dcomplex f = a * b;
	_Dcomplex g = a / b;

	printf("d=a+b=%f+%fi\n", creal(d), cimag(d));
	printf("f=a*b=%f+%fi\n", creal(f), cimag(f));
	printf("g=a/b=%f+%fi\n", creal(g), cimag(g));
	getchar();
	return 0;
}