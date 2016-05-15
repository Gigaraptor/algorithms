#ifndef INCLUDE_LCOK
#define INCLUDE_LOCK
#include "main.h"
#endif


int main(int argc, char *argv[])
{
	queue *test = newQueue(12);

	addNode(15, test);
	addNode(35, test);
	addNode(45, test);
	addNode(11, test);
	printQueue(test);
	removeNode(test);
	removeNode(test);
	printf("Set 2\n");
	printQueue(test);
}