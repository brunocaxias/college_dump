#include <stdio.h>
#include "exHeader.h"

void calcula(float l, float *area, float *perimetro)
{
	*area = l*l;
	*perimetro = 4*l;
	
	printf("A area é %f \n", *area);
	printf("O perimetro é %f \n", *perimetro);
}