#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif

/*
stringBinaryTree *createStringBinaryTree(char *string, int *success)

Creates the head element of a binary tree
*/
stringBinaryTree *createStringBinaryTree(char *string, int *success)
{
	stringBinaryTree *temp = malloc(sizeof(stringBinaryTree));
	if(!temp)//check
	{
		fprintf(stderr,"createStringBinaryTree() has failed : %s \n", strerror(errno));
		*success = FAIL;
		return NULL;
	}
	temp->string = string;
	temp->stringLength = strlen(string);
	temp->left = NULL;
	temp->right = NULL;
	temp->top = NULL;
	return temp;
}
/*
void addString(char *stringToAdd ,stringBinaryTree *tree, int *success)

adds a string to the binary tree
*/

void addString(char *stringToAdd ,stringBinaryTree *tree, int *success)
{
	stringBinaryTree *addressHolder, *previousAddress;
	char leftOrRight;
	int stringLength;
	
	addressHolder = tree;
	stringLength = strlen(stringToAdd);
	while(addressHolder != NULL)//check
	{
		leftOrRight = findDirection(stringToAdd, stringLength, addressHolder->string, addressHolder->stringLength);
		if(leftOrRight == LEFT)//go down the left
		{
			previousAddress = addressHolder;
			addressHolder = (stringBinaryTree *) addressHolder->left;
		}
		else if(leftOrRight == RIGHT)//go down the right
		{
			previousAddress = addressHolder;
			addressHolder = (stringBinaryTree *) addressHolder->right;
		}
	
	}
	if(leftOrRight == LEFT)//If the final bit is to the left
	{
		previousAddress->left = malloc(sizeof(stringBinaryTree));
		addressHolder = previousAddress->left;
	}
	else if(leftOrRight == RIGHT)//if the final bit is to the right
	{
		previousAddress->right = malloc(sizeof(stringBinaryTree));
		addressHolder = previousAddress->right;
	}
	addressHolder->string = stringToAdd;
	addressHolder->top = previousAddress;
	addressHolder->right = NULL;
	addressHolder->left = NULL;
	addressHolder->stringLength = stringLength;
}
/*
char findDirection(char *inputString, int inputLength, char *comparisonString, int comparisonLength)

finds which direction to add the string
*/
char findDirection(char *inputString, int inputLength, char *comparisonString, int comparisonLength)
{
	int i, limit;
	if(inputLength >= comparisonLength)
	{
		limit = inputLength;
	
	}
	else
	{
		limit = comparisonLength;
	}
	for(i = 0; i < limit; i++)
	{
		if(inputString[i] < comparisonString[i])//if the character is higher up the alphabet
		{
			return LEFT;
		
		}
		else if(inputString[i] > comparisonString[i])//if lower
		{
			return RIGHT;
		
		}
	}
	
	return MATCH;
}
/*
	void printBinaryTree(stringBinaryTree *tree)
	
	Prints the tree, starting by going down the lefts, the rights on the lefts, the lefts on right, the right on right

*/
void printBinaryTree(stringBinaryTree *tree)
{
	printf("%s\n", tree->string);
	if(tree->left)
	{
		printBinaryTree(tree->left);//prints the left of a sub tree, and continues travelling down the left
	}
	if(tree->right)
	{
		printBinaryTree(tree->right);//same but right
	}

}
/*
	char binarySearch(char *toSearch, stringBinaryTree *tree)

	searches tree
*/
char binarySearch(char *toSearch, stringBinaryTree *tree)
{
	char compareTo;
	int searchSize;
	
	searchSize = strlen(toSearch);
	compareTo = findDirection(toSearch, searchSize, tree->string, tree->stringLength);
	if(compareTo == LEFT && tree->left )//Searches something that exists
	{
		binarySearch(toSearch, tree->left);
	}
	else if(compareTo == RIGHT && tree->right)
	{
		binarySearch(toSearch, tree->right);
	}
	else if(compareTo == MATCH)
	{
		fprintf(stderr, "FOUND!\n");
	}
	else
	{
		fprintf(stderr, "NOT FOUND!\n");
	}
	
	return MATCH;

}