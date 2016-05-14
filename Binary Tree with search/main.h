#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const static int SUCCESS = 0;
const static int FAIL = 1;
const static char LEFT = 'l';
const static char RIGHT = 'r';
const static char MATCH = 'm';

typedef struct stringBinaryTree
{
	struct stringBinaryTree *top, *left, *right;
	char *string;
	int stringLength;

}stringBinaryTree;


stringBinaryTree *createStringBinaryTree(char *string, int *success);
void addString(char *stringToAdd ,stringBinaryTree *tree, int *success);
char findDirection(char *inputString, int inputLength, char *comparisonString, int comparisonLength);
char binarySearch(char *toSearch, stringBinaryTree *tree);
void printBinaryTree(stringBinaryTree *tree);