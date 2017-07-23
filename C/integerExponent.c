/*Entering a variable x and an integer i, x^i is returned*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double pow_new(double x, double exponent);

int main(void)
{
	double a;
	int b;
	double print_answer;
	
	printf("Please enter your value for x: ");
	scanf("%lf", &a);
	printf("Please enter your integer exponent: ");
	scanf("%d", &b);
	
	if (b<20 && b>0)
	{
		print_answer=pow_new(a,b);
	}
	else
	{
		print_answer=pow(a,b);	printf("\n Using original pow() function");
	}
	
	printf("\n%lf to the power of %d = %lf\n", a, b, print_answer);
	
	system("pause");
	return 0;
}

double pow_new(double x, double exponent)
{
	double total = 1;
	int i;
	
	for (i=1; i<=exponent; i++)
	{
		total*=x;
	}
	return total;
}
