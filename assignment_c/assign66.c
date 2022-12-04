#include <stdio.h>
 void main(){
	 int x =0 ,y=1 ,z=2;
	 int *p=&x , *q=&y, *r=&z;
	 printf("%d \n", x);
	 printf("%d \n", y);
	 printf("%d \n", z);
	 printf("%d \n", p);
	 printf("%d \n", q);
	 printf("%d \n", r);
	 printf("%d \n", *p);
	 printf("%d \n", *q);
	 printf("%d \n", *r);
	 printf("swapping pointers: \n ");
	 r = p;
	 p=q;
	 q=r;
	 printf("%d \n", x);
	 printf("%d \n", y);
	 printf("%d \n", z);
	 printf("%d \n", p);
	 printf("%d \n", q);
	 printf("%d \n", r);
	 printf("%d \n", *p);
	 printf("%d \n", *q);
	 printf("%d \n", *r);
	 
	 
 }
