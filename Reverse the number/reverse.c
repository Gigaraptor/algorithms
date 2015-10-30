#include <stdlib.h>
#include <stdio.h>

static const int BASE = 10;


int getReversedNumber(int originalNumber);
int getFactorsTen(int toGet);
int main()
{
	int inputNumber, reversedNumber;
	//get the value
	printf("Please input a number to reverse : ");
	scanf("%d", &inputNumber);
	//compute
	reversedNumber = getReversedNumber(inputNumber);
	printf("\nThe reversed Number : %d", reversedNumber); 


}

int getReversedNumber(int originalNumber)
{
	int divisor, newNo, newNoColumn, temp, holder; 
	/*
		The value will be:
		0 : Units
		1 : tens
		2 : Hundreds
		etc. for the new number
	*/
	divisor = BASE;
	holder = originalNumber;
	newNoColumn = power(BASE,getFactorsTen(originalNumber) - 2);
	newNo = 0;
	while(holder != 0)
	{
		temp = holder % divisor;
		newNo += (temp * newNoColumn);
		newNoColumn /= BASE;
		holder /= BASE;
		printf("\n Digit : %d , New Factor : %d", temp, newNoColumn);
	}
	
	return newNo;
}
int getFactorsTen(int toGet)
{
	int factors, temp;
	factors = 0;
	temp = toGet;
	while(temp != 0)
	{
		factors++;
		temp /= 10;
		
	}
	printf("\nFactors : %d", factors);
	return factors;
}

int power(int coefficient, int exponent)
{
	int looper;
	int newNo = coefficient;
	for(looper = 0; looper < exponent; looper++)
	{
		newNo = newNo * coefficient;
		
		
	}
	return newNo;
	
}