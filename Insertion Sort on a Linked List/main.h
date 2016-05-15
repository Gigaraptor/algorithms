#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	struct node *ahead, *behind;
	int valueOfNode;

}node;


node *createNode(int valueOfNode);
void addNode(node *nodeList, int valueOfNode);
node *removeNode(int position, node *nodeList);
void printNodeList(node *nodeList);
void insertionSort(node *nodeList);