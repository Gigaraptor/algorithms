#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif


int main(int argc, char *argv[])
{
	integerStack *stack = createStack();
	
	push(stack, 3);
	push(stack, 6);
	push(stack, 12);
	push(stack, 12);
	push(stack, 12);
	push(stack, 12);
	push(stack, 12);
	push(stack, 12);
	push(stack, 12);
	push(stack, 12);
	push(stack, 8);
	push(stack, 102);
	push(stack, 102);
	push(stack, 12);
	
	printStack(stack);
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 
	printf("Pop Value : %d\n", pop(stack)); 


	return 0;
}