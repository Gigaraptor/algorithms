#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 30
const static int SUCCESS = 1;
const static int FAIL = 0;

typedef struct
{
	int stackContents[STACK_SIZE];
	int topPointer,bottomPointer,size;


}integerStack;


integerStack *createStack();
int pop(integerStack *stack);
void push(integerStack *toPushOnto, int toPush);
void printStack(integerStack *toPrint);