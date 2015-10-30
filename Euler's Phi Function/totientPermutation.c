#include <stdio.h>
#include <stdlib.h>

int extendedEuclidAlgor(int firstNumber, int Secondnumber);
int eulersTotient(int toCompute);
/*
	Finds all numbers that are relatively prime to a number lower than 10^7

	suffice to say euclids algorithm was useful here
*/
int main(int argc, char *argv[])
{
	int valToCompute;
	printf("EULER'S TOTIENT FUNCTION\n");
	printf("Returns the number of relatively prime numbers less than or equal to the number\n");
	printf("Please enter the value to compute\n");
	scanf("%d", &valToCompute);
	valToCompute = eulersTotient(valToCompute);
	printf("\nNumber of coprimes : %d", valToCompute); 


	return 0;
}

int eulersTotient(int toCompute)
{
	int numberOfCoPrimes = 0;
	int mainLooper;
	
	for(mainLooper=0;mainLooper <= toCompute;mainLooper++)
	{
		if(extendedEuclidAlgor(mainLooper, toCompute) == 1)
		{
			numberOfCoPrimes += 1;
		
		}
	
	}
	return numberOfCoPrimes;
	
}


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
			//printf("%d", dVal);
			return dVal;
	
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