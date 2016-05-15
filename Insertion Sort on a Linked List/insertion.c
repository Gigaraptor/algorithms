#ifndef INCLUDE_LOCK
#define INCLUDE_LCOK
#include "main.h"
#endif


node *createNode(int valueOfNode)
{
	node *temp = malloc(sizeof(node));
	
	temp->valueOfNode = valueOfNode;
	temp->ahead = NULL;
	temp->behind = NULL;
	
	return temp;
}
void addNode(node *nodeList, int valueOfNode)
{
	node *position = nodeList;
	node *positionBefore;
	while(position)//finds the end of the list
	{
		positionBefore = position;
		position = position->behind;
	
	}
	position = createNode(valueOfNode);//allocates to the list
	position->ahead = positionBefore;//sets the one ahead to the one before
	positionBefore->behind = position;

}

node *removeNode(int position, node *nodeList)
{
	int i = 0;
	node *tempPos = nodeList;
	while(tempPos && i != position)//searches for the node based on position
	{
		tempPos = tempPos->behind;
		i++;
	}
	if(!tempPos)
	{
		printf("Node not Found!\n");
		return NULL;
	}
	tempPos->ahead->behind = tempPos->behind;//removes reference to the node
	if(tempPos->behind)
	{
		tempPos->behind->ahead = tempPos->ahead;
	}
	
	return tempPos;//not freed since the value is returned
}

void printNodeList(node *nodeList)
{
	if(nodeList)
	{
		printf("%d\n", nodeList->valueOfNode);
		printNodeList(nodeList->behind);
	
	}

}
void insertionSort(node *nodeList)
{
	node *tempHolder, *head;
	int temp;
	head = nodeList;//start of the list
	while(nodeList)
	{
		tempHolder = head;//reset to the start of the list
		while(tempHolder != nodeList)//moves up to the position of the split
		{
			if(tempHolder->valueOfNode > nodeList->valueOfNode)// if the temp value is larger swap them
			{
				temp = nodeList->valueOfNode;
				nodeList->valueOfNode = tempHolder->valueOfNode;
				tempHolder->valueOfNode = temp;
			
			}
			else//otherwise, move up
			{
				tempHolder = tempHolder->behind;
			}
		
		}
		nodeList = nodeList->behind;//the next member in the sequence
	
	}
	nodeList = head;//back to the start of the list
}