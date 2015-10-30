#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static const int ARRAY_SIZE = 5;
void QSort(int *array, int start, int end);
void swap(int *a, int *b);
void printArray(char *Title, int *array);
int main()
{
	int *array = malloc(sizeof(int) * ARRAY_SIZE);
	int i = 0;
	while(i < ARRAY_SIZE)
	{
		printf("\nPlease input Integer for sort\n");
		scanf("%d", &array[i]);
		i++;
	}
	//prints arrays and sorts arrays
	printArray("\nUnsorted Array : ", array);
	QSort(array, 0, ARRAY_SIZE - 1);
	printArray("Sorted Array : ", array);

}


void QSort(int *array, int start, int end)
{
	int left, right ,pivot;
	if(end - start > 2)
	{
		pivot = array[end / 2];//finds basically the middle of the array (its integer so not always accurate)
		left = start;
		right = end;
		while(left <= right)
		{
			while(array[left] < pivot)//converges on non equal elements
			{
				left++;
			}
			while(array[right] > pivot)//same as above
			{
				right--;
			}
			if(left <= right)//if the loop can keep going and the above is true then sort the motherfucker
			{
				swap(&array[left], &array[right]);
				left++;
				right--;
			}
			
		}
		QSort(array, start, right);//run again for the new splitted array
		QSort(array, right, end);
	
	}
	
}
void swap(int *a, int *b)//sorts two dynamically allocated integers
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