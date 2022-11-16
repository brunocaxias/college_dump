#include <stdio.h>
#include "hfile.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int printText;
	unsigned num_of_disks;
	num_of_disks = strToInt(argv[1]);

	struct Stack *src, *dest, *aux;

	if (argc > 2)
	{
		printText = compare(argv[2], "-v");
	}
	else
	{
		printText = 1;
	}

	if (printText == 0)
	{
		printf("=> Solving the Tower of Hanoi with %i disks.\n", num_of_disks);
		printf("=> Initial configuration:\n");
		printf("=> Moves:\n");
	}

	src = createStack(num_of_disks);
	aux = createStack(num_of_disks);
	dest = createStack(num_of_disks);

	for (int i = num_of_disks; i >= 1; i--)
	{
		push(src, i);
	}

	tohIterative(size(src), src, aux, dest, printText);

	if (printText == 0)
	{
		printf("=> Final configuration:\n");
		printAllStacks(src, dest, aux, num_of_disks);
	}

	destroy(src);
	destroy(aux);
	destroy(dest);

	return 0;
}
