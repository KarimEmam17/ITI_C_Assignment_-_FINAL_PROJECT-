#include<stdio.h>
typedef  unsigned int  u32;
typedef  unsigned char u8;
struct stu  
{
	u32 math ;
	u32 language ;
	u32 physics ;
	u32 chemistry ;
}arr[3];
//void degrees_stu(struct stu *ptr ,struct stu *ret_ptr,u32 num_stu,u32 id );
struct stu degrees_stu1(struct stu *ptr ,struct stu *ret_ptr,u32 num_stu,u32 id );

void main ()
{
struct stu  *reu; 
u32 id ;
printf("please enter  the id \n");
scanf("%d",&id);
degrees_stu(&arr[0],&reu,3,id );

printf("math degree =%d\n",reu.math);
printf("language degree =%d\n",reu.language);
printf("physics degree =%d\n",reu.physics);
printf("chemistry degree =%d\n",reu.chemistry);



}

struct stu degrees_stu1(struct stu *ptr ,struct stu *ret_ptr,u32 num_stu,u32 id );
{
	for  ( u32 var=0;var<num_stu;var++)
	{	
	printf ("please  enter math degree %d \n",var+1);
	scanf("%d",&(ptr+var)->math);
	printf ("please  enter language degree %d \n",var+1);
	scanf("%d",&(ptr+var)->language);
	printf ("please  enter physics degree %d\n",var+1);	
	scanf("%d",&(ptr+var)->physics);
	printf ("please  enter  chemistry %d \n",var+1);
	scanf("%d",&(ptr+var)->chemistry);	
	}
	
	if ((id <= num_stu) )
	{	printf("hi\n");
		ret_ptr->math = (ptr+(id-1))->math;
		printf("hi\n");
		ret_ptr->language = (ptr+(id-1))->language;
		ret_ptr->physics  = (ptr+(id-1)) ->physics;
		ret_ptr->chemistry=(ptr+(id-1))->chemistry;
		
	}
	
}

/*

void degrees_stu(struct stu *ptr ,struct stu ret_ptr,u32 num_stu,u32 id )
{
	for  ( u32 var=0;var<num_stu;var++)
	{	
	printf ("please  enter math degree %d \n",var+1);
	scanf("%d",&(ptr+var)->math);
	printf ("please  enter language degree %d \n",var+1);
	scanf("%d",&(ptr+var)->language);
	printf ("please  enter physics degree %d\n",var+1);	
	scanf("%d",&(ptr+var)->physics);
	printf ("please  enter  chemistry %d \n",var+1);
	scanf("%d",&(ptr+var)->chemistry);	
	}
	
	if ((id <= num_stu) )
	{	printf("hi\n");
		ret_ptr->math = (ptr+(id-1))->math;
		printf("hi\n");
		ret_ptr->language = (ptr+(id-1))->language;
		ret_ptr->physics  = (ptr+(id-1)) ->physics;
		ret_ptr->chemistry=(ptr+(id-1))->chemistry;
		
	}
	
}
*/
