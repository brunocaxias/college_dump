#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "hfile.h"


struct Stack* createStack(unsigned capacity)
{
    Stack* stack =(Stack*) malloc(sizeof(Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array =(info_t*) malloc(stack -> capacity * sizeof(info_t));
    return stack;
}
 
int isFull(Stack* stack)
{
return (stack->top == stack->capacity - 1);
}
 

int isEmpty(Stack* stack)
{
return (stack->top == -1);
}
 
int size(Stack *s) {
    return s->top + 1;
}

void push(Stack *stack, info_t item)
{
    if (isFull(stack))
        return;
    stack -> array[++stack -> top] = item;
}


info_t pop(Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack -> array[stack -> top--];
}

info_t peek(Stack *s)
{
    if (!isEmpty(s)) {
        return s->array[s->top];
    }
    else {
       exit(EXIT_FAILURE);
    }
}

void destroy(Stack* s)
{
	s->top = -1;
	free(s->array);
	free(s);
}

void printStack(Stack* s)
{
    if (isEmpty(s))
        return;
     
    info_t x = peek(s);
	
    pop(s);
 
    printStack(s);
	
	printf("%i ", x);

    push(s,x);
}

void printAllStacks(Stack* src, Stack* dest, Stack* aux, int num_of_disks)
{
	if(num_of_disks % 2 == 0)
	{
		printf("   A: ");
		printStack(src);
		printf("\n");
	
		printf("   B: ");
		printStack(dest);
		printf("\n");
	
		printf("   C: ");
		printStack(aux);
		printf("\n");
	}
	else{
		printf("   A: ");
		printStack(src);
		printf("\n");
		
		printf("   B: ");
		printStack(aux);
		printf("\n");
		
		printf("   C: ");
		printStack(dest);
		printf("\n");
	}

}
 

void moveDisk(char fromPeg, char toPeg, int disk, int printText)
{
	if(printText == 0)
	{
		printf("   Move the disk %d from \'%c\' to \'%c\'\n", disk, fromPeg, toPeg);	
	}  
}
 



 

