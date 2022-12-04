#include<stdio.h>
typedef  unsigned int  u32;
typedef  unsigned char u8;
void main ()
{
u32 id;
 struct  
{
	u32 math ;
	u32 language ;
	u32 physics ;
	u32 chemistry ;
}arr[3];

for(u32 i=0;i<3;i++){
printf ("please  enter math degree %d \n",i+1);
scanf("%d",&arr[i].math);
printf ("please  enter language degree \n",i+1);
scanf("%d",&arr[i].language);
printf ("please  enter physics degree\n",i+1);	
scanf("%d",&arr[i].physics);
printf ("please  enter  chemistry %d \n",i+1);
scanf("%d",&arr[i].chemistry);
}

printf("the id of student \n");
scanf("%d",&id);
if (id<3 && id>0)
{
	printf (" math degree %d \n",arr[id-1].math);
	printf (" language degree %d \n",arr[id-1].language);
	printf (" physics degree %d \n",arr[id-1].physics);
	printf (" chemistry degree %d \n",arr[id-1].chemistry);
}


/*
printf ("please  enter the salary of  waleed \n");
scanf("%d",&waleed.salary);
printf ("please  enter the bouns of  waleed \n");
scanf("%d",&waleed.bouns);
printf ("please  enter the deductions of  waleed \n");	
scanf("%d",&waleed.deductions);

printf ("please  enter the salary of  waleed \n");
scanf("%d",&karim.salary);
printf ("please  enter the bouns of  waleed \n");
scanf("%d",&karim.bouns);
printf ("please  enter the deductions of  waleed \n");	
scanf("%d",&karim.deductions);

total=(ahmed.salary+waleed.salary+karim.salary)+(ahmed.bouns+karim.bouns+waleed.bouns)+(-karim.deductions-waleed.deductions-ahmed.deductions);

printf("the total  needed %d",total);
*/	
}