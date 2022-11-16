#include <stdio.h>
#include "exHeader.h"

void swap(int *a, int *b)
{
	int c;
	
	c = *a;
	*a = *b;
	*b = c;
	
	printf("O seu A é %i \n",*a);
	printf("O seu B é %i \n",*b);
}
