#include <stdio.h>

void main()
{	
	/*
int degree;
printf("please enter your degree\n"); // enter  yor  degree
scanf("%d",&degree);				  // scanf  the input  
if (0<=degree && degree<50)			  //check  the degree  range 0:50
{
printf("failed");	 				 
}
else if (50<=degree && degree<65)     //check  the degree  range 50:65
{
	printf("normal");
}
else if (65<=degree && degree<75)	//check  the degree  range 65:75
{
	printf("good");
}
else if (75<=degree && degree<85)   //check  the degree  range 75:85
{
	printf("very good ");
}
else if (85<=degree )    			//check  the degree  range 85
{
	printf("excellent");
}
*/
/*
int first_num, second_num,third_num ;
printf("enter  the first number\n");
scanf("%d",&first_num);
printf("enter  the second number\n");
scanf("%d",&second_num);
printf("enter  the third number\n");
scanf("%d",&third_num);
if(first_num>second_num && first_num>third_num)
{
printf("the first  number is the biggest num %d\n",first_num);
	 
//		printf("the third number is the biggest num %d\n",third_num);

}
else if (second_num>first_num&&second_num>third_num)
{
	
printf("the second number is the biggest num %d\n",second_num);
	
	
//	printf("the third number is the biggest num %d\n",third_num);
	
}
else if(second_num<third_num&&first_num<third_num)
{
	printf("the third number is the biggest num %d\n",third_num);
}


(first_num>=second_num)?((first_num>=third_num)?printf("first number",first_num):printf("third number",third_num)):((second_num>=third_num)?printf("second number",second_num):printf("third number",third_num));
	*/
	
/*
char c;
printf("enter charcter \n");
scanf("%c",&c);
if ((c>64 && c<91)||(c>96&&c<123))
{
	printf("this is charcter :%c",c);
}
else
	printf("this is not charcter :%c",c);
*/
/*
int multiple=1  ,num,sum=0;
float avarage=0;

for(int i=0;i<5;i++)
{
	printf("enter  num %d\n",(i+1));
	scanf("%d",&num);
	sum+=num;
	
	
}
avarage=(float)sum/5;
printf("the sum %d the ava %f",sum ,avarage);
*/
/*int x=0;
printf("please enter  the value  of 3x4= ??\n");

while(x!=12)
{
	scanf("%d",&x);
	if (x==12)
		break;
	else
		printf ("not correct  please try  agin :\n");
}
printf("ok");

*/
int x=1,y;
printf("enter rhe num ");
scanf("%d",&y);
while(y>=1)
{
	x*=y;
	y--;
}
printf("%d",x);

}