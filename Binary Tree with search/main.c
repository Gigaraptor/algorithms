#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif


int main(int argc, char *argv [])
{
	int success = SUCCESS;
	stringBinaryTree *test = createStringBinaryTree("C", &success);
	
	addString("AB", test, &success);
	addString("BD", test, &success);
	addString("DA", test, &success);
	addString("EA", test, &success);
	addString("CA", test, &success);
	addString("AA", test, &success);
	
	printBinaryTree(test);
	
	binarySearch("AA", test);
	binarySearch("ZZ", test);
	binarySearch("CB", test);
	binarySearch("CV", test);
	binarySearch("AB", test);
	return 0;
}