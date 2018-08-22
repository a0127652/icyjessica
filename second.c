#include <stdio.h>

int main(void){
	double a;
	double b=6, c=18.6;

	a = b/c;
	printf("b is %3f, c is %3.1f.", b, c);
	printf("a is %.7f.\n", a);

	return 0;
}

