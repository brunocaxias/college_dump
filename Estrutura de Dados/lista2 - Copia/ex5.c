#include <stdio.h>
#include "exHeader.h"


/* Incompleto*/
void charcpy(char* dest, const char* src, int count) 
{
	while (count--) *dest++ = *src++;
	
}
