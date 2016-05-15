#ifndef INCLUDE_LCOK
#define INCLUDE_LOCK
#include "main.h"
#endif


queue *newQueue(int firstNodeValue)
{
	queue *temp = malloc(sizeof(queue));
	
	temp->front = malloc(sizeof(node));//adds the initial node
	temp->front->value = firstNodeValue;
	temp->back = temp->front;
	
	return temp;
}

void addNode(int nodeValue, queue *toAdd)
{
	node *temp = malloc(sizeof(node));

	temp->value = nodeValue;
	temp->behind = NULL;
	
	if(toAdd->back)//if there is already a rear
	{
		toAdd->back->behind = temp;//adds to the rear of the old rear
	}
	toAdd->back = temp;//new rear

}

node *removeNode(queue *toRemove)
{
	node *holder;
	if(toRemove->front)//takes the first node off
	{
		node *holder = toRemove->front;
		if(toRemove->front->behind)
		{
			toRemove->front = toRemove->front->behind;
		}
	}
	else
	{
		printf("Queue is empty!\n");
	
	}

	return holder;
}

void printQueue(queue *toPrint)
{
	printNode(toPrint->front);
}

void printNode(node *toPrint)
{
	if(toPrint != NULL)//prints as long as there are nodes
	{
		printf("Value : %d\n", toPrint->value);
		printNode(toPrint->behind);
	}
	

}