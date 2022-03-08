#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// This struct contain the numerator and the denominator of the fraction // 
struct fraction
{
	int mone;
	int mehane;
}typedef frac;
void takemoneandmehane(frac*);
int calculatemutualdivider(int q1, int q2);
void printresult(frac*, int num1, int num2, int q1, int integer, int i);
int ifmonebiggerthanmehane(int* mone1, int* mehane1);
int main()
{
	frac* s;
	s = (frac*)malloc(10 * sizeof(frac));
	if (!s)
	{
		printf("Cannot allocate memory!");
		exit(1);
	}
	printf("Enter fractions(max 9) by pairs of integers(0 0 to finish) : \n");
	takemoneandmehane(s);
	free(s);
	return 0;
}
// function name: takemoneandmehane //
// input : numerator and denominator from the user and fraction struct array from the main//
// output : calculates the mutual denominator and his numerator//
// algorithim: two while loops //
void takemoneandmehane(frac* p)
{
	int i = -1, mutualmone = 0, mutualmehane = 1, mutualdivider, integer, k = -2;
	while (i < 8 && (p[i].mone && p[i].mehane))
	{
		if (i == k && p[i].mone == 1)
			p[i].mone = 0;
		i++;
		printf("        %d(mone mehane) : ", i + 1);
		scanf("%d%d", &p[i].mone, &p[i].mehane);
		printf("\n");
		if (p[i].mehane == 0 && p[i].mone != 0)
		{
			while (p[i].mehane == 0)
			{
				printf("The mehane cannot be zero Enter new one : ");
				scanf("%d", &p[i].mehane);
			}
		}
		if (p[i].mone != 0)
		{
			mutualmehane = mutualmehane * p[i].mehane;
			mutualmone = (mutualmehane / p[i].mehane * p[i].mone + (mutualmone * p[i].mehane));
		}
		if (p[i].mone == 0 && p[i].mehane != 0)
		{
			k = i;
			p[i].mone = 1;
		}
	}
	if (mutualmone >= mutualmehane)
		integer = ifmonebiggerthanmehane(&mutualmone, &mutualmehane);
	else
		integer = 0;
	mutualdivider = calculatemutualdivider(mutualmone, mutualmehane);
	printresult(p, mutualmone, mutualmehane, mutualdivider, integer, i);
}
// function name : calculatemutualdivider //
// input : mutual denominator and his numerator //
// output : The mutual divider of denominator and his numerator //
// algorithim : while loop //
int calculatemutualdivider(int num3, int num4)
{
	int q1, q2, t, i = 0;
	if (num3 >= num4)
	{
		q1 = num3;
		q2 = num4;
	}
	else
	{
		q1 = num4;
		q2 = num3;
	}
	while (i < 5 && q2 != 0)
	{
		t = q1 % q2;
		if (2 * t > q2)
			t = q2 - t;
		q1 = q2;
		q2 = t;
		i++;
	}
	return q1;
}
// function name : ifmonebiggerthanmehane //
// input : mutual denominator and his numerator //
// output : returns how many integers in the fraction //
// algorithim : while loop //
int ifmonebiggerthanmehane(int* mone1, int* mehane1)
{
	int integer = 0;
	while (*mone1 >= *mehane1)
	{
		*mone1 = *mone1 - *mehane1;
		integer++;
	}
	return integer;
}
// function name : printresult //
// input : The mutual denominator and his numerator,their mutual divider,how many integers and how many numbers did the user entered //
// output : prints the result //
// algorithim : for loop //
void printresult(frac* p, int num1, int num2, int q1, int integer, int i)
{
	int j, num3;
	printf("        ");
	for (j = 0; j <= i; j++)
	{
		if (j <= i && p[j].mone != 0)
			printf("%d/%d", p[j].mone, p[j].mehane);
		if (j < i && p[j + 1].mone != 0)
			printf("+");
	}
	num1 = num1 / q1;
	num2 = num2 / q1;
	num3 = (integer * num2) + num1;
	printf("=%d/%d", num3, num2);
	if (num1 != 0)
		printf("=%d and %d/%d", integer, num1, num2);
	else
		printf("=%d and 0", integer);
}
