#include <stdio.h>


int
main(void)
{
	double time,
		t;

	printf("Enter the time since spoilt>");
	scanf("%lf", &time);
	t = 4 * (time * time) / (time + 2) - 20;

	printf("That equals %f degrees.\n", t);
	return(0);
}
