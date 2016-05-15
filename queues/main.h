#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *behind;
	int value;

}node; 

typedef struct queue
{
	node *front, *back;

}queue;


queue *newQueue(int firstNodeValue);
void addNode(int nodeValue, queue *toAdd);
node *removeNode(queue *toRemove);
void printQueue(queue *toPrint);
void printNode(node *toPrint);