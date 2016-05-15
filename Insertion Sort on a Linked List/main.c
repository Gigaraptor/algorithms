#ifndef INCLUDE_LOCK
#define INCLUDE_LCOK
#include "main.h"
#endif


int main(int argc, char *argv[])
{
	node *nodeList = createNode(12132);
	
	addNode(nodeList, 32313);
	addNode(nodeList, 1235);
	addNode(nodeList, 7123);
	addNode(nodeList, 71232);
	addNode(nodeList, 7121233);
	addNode(nodeList, 712133);
	addNode(nodeList, 23129);
	
	removeNode(2, nodeList);
	
	printNodeList(nodeList);
	
	insertionSort(nodeList);
	
	printf("set 2\n");
	printNodeList(nodeList);
	return 0;
}