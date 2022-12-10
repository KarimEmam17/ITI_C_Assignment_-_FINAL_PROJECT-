#include "STD_Types.h"
#include "bank.h"
#include "client.h"
#include <stdio.h>
#include <stdlib.h>

extern  Client_Account *Head;  
extern  Client_Account *Last;
void find_Account_user()
{       

        Client_Account *ptr;
        u64 LOC_u64_SEARCH_BANK_ID;
        u64 LOC_u64_Password;
        u8 LOC_u8_select_Operation;
        u8 LOC_u8_var;
        u8 LOC_u8_CHECK=0;
        if(Head==NULL)
        {
                printf("No bank Account\n");
                
        }
        else
        {
                ptr=Head;
                
                while(ptr!=NULL)
                {
                        printf("the Bank ID:  %ld \n",ptr->u64_Bank_ID );
                        //printf("the Password:  %ld \n",ptr->u64_Password);
                        ptr=ptr->Next_Acc ;
                }
                printf("Enter The  Bank ID : \n  ");
                scanf("%d",&LOC_u64_SEARCH_BANK_ID);
                fflush(stdin);
                ptr=Head;
                while(ptr->u64_Bank_ID!=LOC_u64_SEARCH_BANK_ID)
                {
                     ptr=ptr->Next_Acc;
                }
                while (ptr->u64_Password!=LOC_u64_Password)
                {
                    
                    if(LOC_u8_CHECK==0)
                        {
                            printf("Enter The  password : \n  ");
                            scanf("%ld",&LOC_u64_Password);
                            LOC_u8_CHECK++;
                        }
                    else
                    {
                        printf("Enter The right password : \n  ");
                        scanf("%ld",&LOC_u64_Password);
                    }


                }
                printf("the name is : ");
                for (LOC_u8_var= 0; LOC_u8_var < 50;LOC_u8_var++)
                {
                    printf("%c",ptr->u8_Full_Name[LOC_u8_var]);
                }
                printf("\n the Addres is :  ");
                for (LOC_u8_var= 0; LOC_u8_var < 50; LOC_u8_var++)
                {
                    printf("%c",ptr->u8_Full_Address[LOC_u8_var]);
                }
                 printf("\nthe Acount status is :  ");
                if (ptr->u8_Account_status==Active)
                    {printf("ACTIVE\n");}
                else if(ptr->u8_Account_status==Closed)
                    {printf("Closed\n");}
                else if(ptr->u8_Account_status==Restricted)
                    {printf("Restricted\n");}
                printf("the Balance is : %ld \n",ptr->u64_Balance);
                printf("the AGE is : %d \n",ptr->u16_Age);
                printf("select the OPeration: \nMAke_Transaction=72 \nChange Account Password=38  \nGet_Cash=59 \nDeposit In Account=1  \nReturn to Main Menu=99 \n");
                scanf("%d",&LOC_u8_select_Operation);
                fflush(stdin);
               while(LOC_u8_select_Operation!=Return_to_Main_Menu)
               {
                switch (LOC_u8_select_Operation)
                {
                case MAke_Transaction:
                    MAke_Trans( ptr);
                    printf("select the OPeration: \nMAke_Transaction=72 \nChange Account Password=38  \nGet_Cash=59 \nDeposit In Account=1  \nReturn to Main Menu=99 \n");
                    scanf("%d",&LOC_u8_select_Operation);
                    break;
                case Change_Account_Password:
                    void_Change_Account_Password(ptr);
                    printf("select the OPeration: \nMAke_Transaction=72 \nChange Account Password=38  \nGet_Cash=59 \nDeposit In Account=1  \nReturn to Main Menu=99 \n");
                    scanf("%d",&LOC_u8_select_Operation);
                    break;
                case Get_Cash:
                
                void_Get_Cash(ptr);
                    break;
                case Deposit_In_Account:
                void_Deposit_In_Account( ptr );
                      break;
                case Return_to_Main_Menu:
                      break;
                }
               }
                

        }
}
void void_Change_Account_Password( Client_Account * PTR_Client_Account )
{
    u64  LoC_u64_PASSWord;
    printf("enter the new pass?\n");
    scanf("%ld",&LoC_u64_PASSWord);
    fflush(stdin);
    PTR_Client_Account-> u64_Password =LoC_u64_PASSWord;
    
}
              

