#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif

integerStack *createStack()
{
	integerStack *temp = malloc(sizeof(integerStack));
	temp->topPointer = -1;
	temp->bottomPointer = -1;
	temp->size = 0;
	
	return temp;
}

int pop(integerStack *stack)
{
	int stackValue;
	if(stack->size != 0)
	{
		stackValue = stack->stackContents[stack->topPointer];
		stack->topPointer -= 1;
		stack->size -= 1;
		return stackValue;
	
	}
	else
	{
		printf("Nothing left on the stack!\n");
	}
}

void push(integerStack *toPushOnto, int toPush)
{
	if(toPushOnto->topPointer + 1 < STACK_SIZE)
	{
		toPushOnto->topPointer += 1;
		toPushOnto->size += 1;
		toPushOnto->stackContents[toPushOnto->topPointer] = toPush;
		
	}
	else
	{
		printf("Stack Full!\n");
	
	}

}

void printStack(integerStack *toPrint)
{
	int i;
	for(i = 0; i < toPrint->size; i++)
	{
		printf("%d : %d\n", i, toPrint->stackContents[i]);
	
	}

}