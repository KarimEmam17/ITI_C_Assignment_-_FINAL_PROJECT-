#include <stdio.h>



void main()
{
	int no1,no2;
    //char first_char;
	printf("what is your work  rate \n");
	scanf(" %d",&no1);
//  printf("what is second num\n");
//  scanf(" %d",&no2);
//  no1=1<<no1;
//  no2|=no1;
	no2=no1*50;
	if(no1<40)
	{
		no2=no2-((no2*10)/100);
	}
	
	//printf("first %d\n",no1>6);
	printf("second is %d\n",no2);
	
}