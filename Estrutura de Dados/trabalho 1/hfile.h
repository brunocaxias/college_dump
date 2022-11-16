#ifndef __hfile_h_
#define __hfile_h_

typedef int info_t;

typedef struct Stack
{
	unsigned capacity;
	int top;
	info_t *array;
}Stack;

/*Creates and returns a stack*/
struct Stack* createStack(unsigned capacity);

/*Checks if a stack is full*/
int isFull(Stack* stack);

/*Checks if a stack is empty*/
int isEmpty(Stack* stack);

/*Returns the size of a stack*/
int size(Stack *s);

/*Pushes an object(info_t) into a stack*/
void push(Stack *stack, info_t item);

/*Pops an object(info_t) out of a stack*/
info_t pop(Stack* stack);

/*Peeks an object(info_t) inside a stack*/
info_t peek(Stack *s);

/*Destroys a stack*/
void destroy(Stack* s);

/*Prints objects(info_t) of a stack*/
void printStack(Stack* s);

/*Prints multiple stack (used to shorten the code)*/
void printAllStacks(Stack* src, Stack* dest, Stack* aux, int num_of_disks);

/*Prints the moves of a stack*/
void moveDisk(char fromPeg, char toPeg, int disk, int printText);

/*Moves obejects(info_t) between stacks*/
void moveDisksBetweenTwoPoles(Stack *src,Stack *dest, char s, char d, int printText);

/*Solves Tower of Hanoi*/
void tohIterative(int num_of_disks,Stack*src, Stack *aux, Stack *dest, int printText);

/* Functions file methods*/

/*Compares 2 strings*/
int compare(char a[],char b[]);

/*Transform string into int*/
int strToInt(char *str);

/*-----------------------*/





#endif