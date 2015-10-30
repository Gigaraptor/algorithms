#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	A crappy implementation of Euclid's Algorithm using the example presented in The Art Of Computer Programming By Donald Knuth, page 39 on the pdf

	By Gigaraptor / Elliot Lake
*/
int extendedEuclidAlgor(int firstNumber, int secondNumber);

/*
Main does the neccessary things, recieving input from the user and outputing the value

*/

int main(int argc, char *argv[])
{
	int mVal, nVal, quotientCompleteDivision;
	double seconds;
	clock_t timeTaken;
	printf("EUCLID'S ALGORITHM\n");
	printf("am + bn = d\n");
	printf("a`m + b`n = c\n"); 
	printf("Please input the first integer to compute\n");
	scanf("%d", &mVal);
	printf("\nPlease input the second integer to compute\n");
	scanf("%d", &nVal);
	timeTaken = clock();
	quotientCompleteDivision = extendedEuclidAlgor(mVal,nVal);
	timeTaken = clock() - timeTaken;
	printf("The quotient where the remainder is 0 is %d, to %lf seconds", quotientCompleteDivision, (double) timeTaken / CLOCKS_PER_SEC);

}

/*
	step 1, set appropriate variables to starting values
	step 2, get remainders and quotients from the values provided
	step 3, if the remainder is 0 then we have the correct value
	step 4, otherwise, than shake around the values as specified (should be easy to interpret
	
	I have no idea of they are actually differentials, but the way Professor Knuth writes the variables it uses the notation indicative of that

*/
int extendedEuclidAlgor(int firstNumber, int secondNumber)
{
	int coeffC, coeffD, differentialCoeffC, differentialCoeffD, cVal, dVal, quotientHolder, remainderHolder, tempHolder; //coeffC is a, coeffD is b
	coeffC = 0;
	coeffD = 1;
	differentialCoeffC = 1;
	differentialCoeffD = 0;
	cVal = firstNumber;
	dVal = secondNumber;
	retry:    //dijstra would be turning in his grave, but it works fine and perfectly readable unless you have dyslexia or blindness, in which case tough luck
		quotientHolder = cVal / dVal;
		remainderHolder = cVal % dVal;
	
		if(remainderHolder == 0)
		{
			printf("\n(%d x %d ) + (%d x %d) = %d\n", coeffC, firstNumber, coeffD, secondNumber, dVal);
			printf("\n(%d x %d ) + (%d x %d) = %d\n", differentialCoeffC, firstNumber, differentialCoeffD, secondNumber, cVal);
			return quotientHolder;
	
		}
		else
		{
			cVal = dVal;
			dVal = remainderHolder;
			tempHolder = differentialCoeffC;
			differentialCoeffC = coeffC;
			coeffC = (tempHolder - (quotientHolder * coeffC));
			tempHolder = differentialCoeffD;
			differentialCoeffD = coeffD;
			coeffD = (tempHolder - (quotientHolder * coeffD));
			goto retry;
		}


}