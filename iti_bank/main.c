#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "bank.h"
#include "Admin.h"
#include "client.h"

Client_Account *Head=NULL;  
Client_Account *Last=NULL;
int main ()
{
	while(1)
	{
	ITI_Bank_System();
	}
	return 0;

}