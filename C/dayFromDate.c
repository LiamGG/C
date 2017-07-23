/*Returns the day of the week from the date & month (2014)*/

#include<stdlib.h>
#include<stdio.h>


int main(void)
{
	int month, n, date, total, m, d;
	// n=summed number of days in previous months, total=days in previous months+days in current month, m=remainder, d=day of week
	
	printf("Enter month (January=1, December=12)\n");
	scanf("%d", &month);
	
	switch (month)
	{
		case 1: n=0;
		break;
		
		case 2: n=31;
		break;
		
		case 3: n=59;
		break;
		
		case 4: n=90;
		break;
		
		case 5: n=120;
		break;
		
		case 6: n=151;
		break;
		
		case 7: n=181;
		break;
		
		case 8: n=212;
		break;
		
		case 9: n=243;
		break;
		
		case 10: n=273;
		break;
		
		case 11: n=304;
		break;
		
		case 12: n=334;
		break;
		
		default: printf("Invalid\n");
		break;
	}
  
	printf("Enter date in month\n");
	scanf("%d", &date);

	printf("The %d", date);
	
	switch (date)
	{
		case 1&&21&&31: printf("st");
		break;
		
		case 2: printf("nd");
		break;
		
		case 22: printf("nd");
		break;
		
		case 3: printf("rd");
		break;
		
		case 23: printf("rd");
		break;
		
		default: printf("th");
		break;
	}
	
	total=n+date;
	m=total%7;
	switch (month)
	{
		case 1: printf(" January");
		break;	
	
		case 2: printf( "February");
    	break;	

		case 3: printf(" March");
		break;
	
		case 4: printf(" April");
		break;
	
		case 5: printf(" May");
		break;
	
		case 6: printf (" June");
		break;
		
		case 7: printf(" July");
		break;
		
		case 8: printf (" August");
		break;
		
		case 9: printf(" September");
		break;
		
		case 10: printf(" October");
		break;

		case 11: printf(" November");
		break;
		
		case 12: printf(" December");
		break;
	}
	
	/*if (n==295)
	{
		printf(" is a ");
	}
	else if (n<295)
	{*/
		printf(" was a ");
	/*}
	else if (n>295)
	{
		printf(" will be a ");
	}*/
	
	switch (m)
	{
		case 1: printf("Wednesday.\n");
		break;
		
		case 2: printf("Thursday.\n");
		break;
		
		case 3: printf("Friday.\n");
		break;
		
		case 4: printf("Saturday.\n");
		break;
		
		case 5: printf("Sunday.\n");
		break;
		
		case 6: printf("Monday.\n");
		break;
		
		case 0: printf("Tuesday.\n");
		break;
	}
	
	system("pause");
	return 0;
}
