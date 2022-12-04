#include <stdio.h>
void main(){ float i; float password ;
	float id = 7777;
	float pw = 0000;
	char s[20] = "karim";
	printf("Please Enter ID: ");
	scanf("%f",&i);
	if(i==id)
	{
		printf("enter your password : ");
		scanf("%f",&password);
		if (pw==password)
			printf("HI %s\n ",s);
		else printf("incorrect password");
		
	}
		
	else printf("incorrect ID ");
}