#include <stdlib.h>
#include <stdio.h>
static const int ARRAY_SIZE = 5;

void BSort(int *array, int end);
void swap(int *a, int *b);
void printArray(char *title, int *array);

int main()
{
	int *array = malloc(sizeof(int) * ARRAY_SIZE);
	int i;
	for(i = 0; i < ARRAY_SIZE; i++)
	{
		printf("Please type in value %d : \n", i);
		scanf("%d", &array[i]);
	}
	printArray("Unsorted Array : ", array);
	BSort(array, ARRAY_SIZE - 1);
	printArray("Sorted Array : ", array);
	return 0;
}

void BSort(int *array, int end)
{
	int isSwapped, i;
	while(1 == 1)
	{
		isSwapped = 0;//initially there are no swaps
		for(i = 0; i < end; i++)
		{
			if(array[i] > array[i + 1])//if the one after the current is lower than the one before the swap them and take note they were swapped
			{
				swap(&array[i], &array[i + 1]);
				isSwapped = 1;
				
			}
			
		}
		if(isSwapped == 0)//if there were no swaps then things went well
		{
			break;
			
		}
	}
	
	
	
	
}
void swap(int *a, int *b)
{
	int swap;
	swap = *a;
	*a = *b;
	*b = swap;
	
}
void printArray(char *title, int *array)//prints an array of dynamically allocated integers
{
	int i = 0;
	printf("\n%s", title);
	while(i < ARRAY_SIZE)
	{
		printf("%d, ", array[i]);
		i++;
	}	
	
	
}