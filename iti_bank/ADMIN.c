#include "STD_Types.h"
#include "bank.h"
#include "Admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern  Client_Account *Head;  
extern  Client_Account *Last;

void Admin_Window (void)
{
    u8 u8_Admin_Mood;
    printf("Select The  MOOD:\nCreat New Account=8\nOpen_Existing_Account=22 \nExit_System=11\n"); 
    scanf("%d",&u8_Admin_Mood);
    fflush(stdin);
   // fflush();
    while(u8_Admin_Mood!=Exit_System){
    switch (u8_Admin_Mood)
        {
            case Creat_New_Account :
                Creat_New_Client_Account();
                printf("Select The  MOOD:\nCreat New Account=8\nOpen_Existing_Account=22 \nExit_System=11\n"); 
                scanf("%d",&u8_Admin_Mood);
                fflush(stdin);
                break;
            case Open_Existing_Account:
                find_Account();
                printf("Select The  MOOD:\nCreat New Account=8\nOpen_Existing_Account=22 \nExit_System=11\n"); 
                scanf("%d",&u8_Admin_Mood);
                fflush(stdin);
                break;
            case Exit_System:

                break;
            
            default:
            printf("wronge Selected MOOD  \n");
			 printf("Select The  MOOD:\nCreat New Account=8\nOpen_Existing_Account=22 \nExit_System=11\n"); 
                scanf("%d",&u8_Admin_Mood);
                fflush(stdin);
                
                break;
        } }

}

void Creat_New_Client_Account(void) 
 {
    Client_Account *temp ,*Ptr;
    temp=(Client_Account*)malloc(sizeof(Client_Account));
    if(Head==NULL)
    {
        Head=temp;
    }
    else
    {
        Ptr=Head;
        while(Ptr->Next_Acc!= NULL)
        {
            Ptr=Ptr->Next_Acc;
        }
        temp->Previous_Acc = Ptr;
        Ptr->Next_Acc=temp;
        
    }
    void_Enter_Full_Name(temp);
    void_Enter_Full_Address(temp);
    void_Enter_National_ID(temp);
    void_Enter_Age(temp);
    void_Enter_Bank_ID(temp);
    if(temp->u16_Age<21)
    {
         void_Enter_Full_Name_of_Guardian(temp);
         void_Enter_National_ID_of_Guardian(temp);
    }
    void_Set_ACTIVE_Account_Status_(temp);
    void_Enter_PassWord(temp);
    void_Set_Balance(temp);

 }
 /*this func  used by  admin   takes and asigned it  name arr  in  struct  of the client   */
void void_Enter_Full_Name(Client_Account *ptr_Client_Account)
 {
    u8 Copy_Full_Name_Arr[50];
    u8 LOC_var;
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0;
    for(LOC_var=0;LOC_var<50;LOC_var++)
    {
       Copy_Full_Name_Arr[LOC_var]=' ';
    }
    while (LOC_ERROR_check)
    {
    if(LOC_Counter_Check==0)
    {    
         
    printf(" Please Enter Full Name Of THE Client ?\n ");
    scanf("%[^\n]%*c",Copy_Full_Name_Arr);
    fflush(stdin);
    LOC_Counter_Check++;
    }
    else
    {
        for(LOC_var=0;LOC_var<50;LOC_var++)
        {
        Copy_Full_Name_Arr[LOC_var]=' ';
        }   
        printf(" Please Enter Full Name Of THE Client only  capital & Small charcter & spaces  \n");
        scanf("%[^\n]%*c",Copy_Full_Name_Arr);
        fflush(stdin);
    }
    while(strlen(Copy_Full_Name_Arr)<=20)
    {
         printf(" Please Enter Full Name Of THE Client only  capital & Small charcter & spaces  not less 20 char \n");
        scanf("%[^\n]%*c",Copy_Full_Name_Arr);
        fflush(stdin);
    }
    for(LOC_var=0;LOC_var<50;LOC_var++)
    {
       if(((Copy_Full_Name_Arr[LOC_var]>64)&&(Copy_Full_Name_Arr[LOC_var]<91))||((Copy_Full_Name_Arr[LOC_var]>96)&&(Copy_Full_Name_Arr[LOC_var]<123))||(Copy_Full_Name_Arr[LOC_var]==32)||(Copy_Full_Name_Arr[LOC_var]=='\0'))
        {
            LOC_ERROR_check=0;
        }
        else
        {
            LOC_ERROR_check=1;
            break;
        } 
    }
    }
    for(LOC_var=0;LOC_var<50;LOC_var++)
        {
        ptr_Client_Account->u8_Full_Name[LOC_var] = Copy_Full_Name_Arr[LOC_var];  
        }   
    
 }
 /*this func  used by  admin   takes and asigned it  Address arr  in  struct  of the client   */
void void_Enter_Full_Address(Client_Account *ptr_Client_Account)
 {
    u8 Copy_Full_Address_Arr[50];
    u8 LOC_var;
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0;
    for(LOC_var=0;LOC_var<50;LOC_var++)
    {
       Copy_Full_Address_Arr[LOC_var]=' ';
    }
    while (LOC_ERROR_check)
    {
        if(LOC_Counter_Check==0)
        {    
            printf(" Please Enter Full Address Of THE Client \n");
            scanf("%[^\n]%*c",Copy_Full_Address_Arr);
            fflush(stdin);
            LOC_Counter_Check++;
        }
        else
        {
            for(LOC_var=0;LOC_var<50;LOC_var++)
            {
            Copy_Full_Address_Arr[LOC_var]=' ';
            }   
            printf(" Please Enter Full Address Of THE Client only  Capital & Small charcter & Spaces & Numbers \n");
            scanf("%[^\n]%*c",Copy_Full_Address_Arr);
            fflush(stdin);
        }
        while(strlen(Copy_Full_Address_Arr)<=15)
         {
            printf(" Please Enter Full Address Of THE Client only  Capital & Small charcter & Spaces & Numbers   not less 15 \n");
            scanf("%[^\n]%*c",Copy_Full_Address_Arr);
            fflush(stdin);
         }
        for(LOC_var=0;LOC_var<50;LOC_var++)
        {
        if(((Copy_Full_Address_Arr[LOC_var]>64)&&(Copy_Full_Address_Arr[LOC_var]<91))||((Copy_Full_Address_Arr[LOC_var]>96)&&(Copy_Full_Address_Arr[LOC_var]<123))||(Copy_Full_Address_Arr[LOC_var]==32)||(Copy_Full_Address_Arr[LOC_var]=='\0')||((Copy_Full_Address_Arr[LOC_var]>47)&&(Copy_Full_Address_Arr[LOC_var]<58)))
            {
                LOC_ERROR_check=0;
            }
            else
            {
                LOC_ERROR_check=1;
                break;
            } 
        }
    }
    for(LOC_var=0;LOC_var<50;LOC_var++)
        {
            ptr_Client_Account->u8_Full_Address[LOC_var] = Copy_Full_Address_Arr[LOC_var];  
        }   
    
 }
 /*this func  used by  admin   takes and asigned it  NAtional ID  in  struct  of the client   */
void void_Enter_National_ID(Client_Account *ptr_Client_Account)
{
    u8 Copy_National_ID[20];
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0;
    u8 LOC_var;
    for(LOC_var=0;LOC_var<20;LOC_var++)
    {
       Copy_National_ID[LOC_var]=' ';
    }
    while (LOC_ERROR_check)
    {
        if(LOC_Counter_Check==0)
        {    
            printf(" Please Enter Full National ID Of THE Client \n");
            scanf("%[^\n]%*c",Copy_National_ID);
            fflush(stdin);
            LOC_Counter_Check++;
            LOC_ERROR_check=0;
        }
        else
        {
              
            printf(" Please Enter Full National ID Of THE Client only Numbers \n");
            scanf("%[^\n]%*c",Copy_National_ID);
            fflush(stdin);
            LOC_ERROR_check=0;
        }
        fflush(stdin);
        
       if ((strlen(Copy_National_ID)!=14))
        {
            LOC_ERROR_check=1;
        }
        else
        {
            LOC_ERROR_check=0;
        }
        
        /*
        for(LOC_var=0;LOC_var<14;LOC_var++)
        {
             if((Copy_National_ID[LOC_var]<48)||(Copy_National_ID[LOC_var]>57))
            {
                LOC_ERROR_check=1;
                
            } 
            else
            {
                LOC_ERROR_check=0;
            }        
        }
        for(LOC_var=14;LOC_var<20;LOC_var++)
        {
             if((Copy_National_ID[LOC_var]!=32)||(Copy_National_ID[LOC_var]!='\0'))
            {
                LOC_Err_CHECK=1;
               
                
            }  
             else
            {
                LOC_Err_CHECK=0;
                 break;
            }      
        } */  
        
    }
     for(LOC_var=0;LOC_var<14;LOC_var++)
        {
           
                ptr_Client_Account->u8_National_ID[LOC_var] = Copy_National_ID[LOC_var]; 
                
                     
        }
     
        
}
 /*this func  used by  admin   takes and asigned it  AGE in  struct  of the client   */
void void_Enter_Age(Client_Account *ptr_Client_Account)
{
    u64 Copy_Age;
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0;
    
    while (LOC_ERROR_check)
    {
        if(LOC_Counter_Check==(u64)0)
        {    
            printf(" Please Enter Age Of THE Client \n");
            scanf("%d",&Copy_Age);
            fflush(stdin);
            LOC_Counter_Check++;
        }
        else
        {
              
            printf(" Please Enter Age Of THE Client only Numbers \n");
            scanf("%d",&Copy_Age);
            fflush(stdin);
        }
        if((Copy_Age>(u64)0)&&(Copy_Age<(u64)100))
            {
                LOC_ERROR_check=(u64)0;
            }
            else
            {
                LOC_ERROR_check=(u64)1;
                break;
            } 
        
    }
    ptr_Client_Account->u16_Age = Copy_Age;  
        
}
/*this func  used by  admin   takes and asigned it  BANK ID in  struct  of the client   */
void void_Enter_Bank_ID(Client_Account *ptr_Client_Account)
{
    u64 Copy_Bank_ID;
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0,LOC_var_counter;
    Copy_Bank_ID=ptr_Client_Account->u8_Full_Name[0]*(100000000);
    while (LOC_ERROR_check)
    {
        for(LOC_var_counter=0;LOC_var_counter<50;LOC_var_counter++)
        {
            Copy_Bank_ID+=ptr_Client_Account->u8_Full_Name[LOC_var_counter];
        }
        if((Copy_Bank_ID>999999999)&&(Copy_Bank_ID<10000000000))
            {
                LOC_ERROR_check=0;
            }
            else
            {
                LOC_ERROR_check=1;
                break;
            } 
        
    }
    ptr_Client_Account->u64_Bank_ID = Copy_Bank_ID;  
    printf(" Bank ID : %d\n", ptr_Client_Account->u64_Bank_ID) ;    
}
/*this func  used by  admin   takes and asigned it  Name of Guardian  arrin  struct  of the client   */
void void_Enter_Full_Name_of_Guardian(Client_Account *ptr_Client_Account)
 {
    u8 Copy_Full_Name_of_Guardian_Arr[50];
    u8 LOC_var;
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0;
    for(LOC_var=0;LOC_var<50;LOC_var++)
    {
       Copy_Full_Name_of_Guardian_Arr[LOC_var]=' ';
    }
    while (LOC_ERROR_check)
    {
    if(LOC_Counter_Check==0)
    {    
    printf(" Please Enter Full Name Of Guardian Of THE Client \n");
    scanf("%[^\n]%*c",Copy_Full_Name_of_Guardian_Arr);
    fflush(stdin);
    LOC_Counter_Check++;
    }
    else
    {
        for(LOC_var=0;LOC_var<50;LOC_var++)
        {
        Copy_Full_Name_of_Guardian_Arr[LOC_var]=' ';
        }   
        printf(" Please Enter Full Name Of Guardian For THE Client only  capital & Small charcter & spaces  \n");
        scanf("%[^\n]%*c",Copy_Full_Name_of_Guardian_Arr);
        fflush(stdin);
    }
      while(strlen(Copy_Full_Name_of_Guardian_Arr)<=20)
         {
            printf(" Please Enter Full Name Of Guardian For THE Client only  capital & Small charcter & spaces  not less 20 \n");
            scanf("%[^\n]%*c",Copy_Full_Name_of_Guardian_Arr);
            fflush(stdin);
         }
    for(LOC_var=0;LOC_var<50;LOC_var++)
    {
       if(((Copy_Full_Name_of_Guardian_Arr[LOC_var]>64)&&(Copy_Full_Name_of_Guardian_Arr[LOC_var]<91))||((Copy_Full_Name_of_Guardian_Arr[LOC_var]>96)&&(Copy_Full_Name_of_Guardian_Arr[LOC_var]<123))||(Copy_Full_Name_of_Guardian_Arr[LOC_var]==32)||(Copy_Full_Name_of_Guardian_Arr[LOC_var]=='\0'))
        {
            LOC_ERROR_check=0;
        }
        else
        {
            LOC_ERROR_check=1;
            break;
        } 
    }
    }
    for(LOC_var=0;LOC_var<50;LOC_var++)
        {
        ptr_Client_Account->u8_Full_Name_of_Guardian[LOC_var] = Copy_Full_Name_of_Guardian_Arr[LOC_var];  
        }   
    
 }
/*this func  used by  admin   takes and asigned it  National ID of Guardian  in  struct  of the client   */
void void_Enter_National_ID_of_Guardian(Client_Account *ptr_Client_Account)
{
    u8 Copy_National_ID_of_Guardian[20];
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0;
    u8 LOC_var;
    for(LOC_var=0;LOC_var<20;LOC_var++)
    {
       Copy_National_ID_of_Guardian[LOC_var]=' ';
    }
    while (LOC_ERROR_check)
    {
        if(LOC_Counter_Check==0)
        {    
            printf(" Please Enter Full National ID Of THE Guardiant \n");
            scanf("%[^\n]%*c",Copy_National_ID_of_Guardian);
            fflush(stdin);
            LOC_Counter_Check++;
            LOC_ERROR_check=0;
        }
        else
        {
              
            printf(" Please Enter Full National ID Of THE Guardian only Numbers \n");
            scanf("%[^\n]%*c",Copy_National_ID_of_Guardian);
            fflush(stdin);
            LOC_ERROR_check=0;
        }
        fflush(stdin);
          
       if ((strlen(Copy_National_ID_of_Guardian)!=14))
        {
            LOC_ERROR_check=1;
        }
        else
        {
            LOC_ERROR_check=0;
        }
        
    }
     for(LOC_var=0;LOC_var<14;LOC_var++)
        {
           
                ptr_Client_Account->u8_National_ID_of_Guardian[LOC_var] = Copy_National_ID_of_Guardian[LOC_var]; 
                
                     
        }
     
         
}
/*this func  used by  admin   takes and asigned it  Account status   in  struct  of the client   */
void void_Set_ACTIVE_Account_Status_(Client_Account *ptr_Client_Account)
{
    ptr_Client_Account->u8_Account_status=  Active;  
}
/*this func  used dynamicly   takes and asigned it  Balance   in  struct  of the client   */
void void_Set_Balance(Client_Account *ptr_Client_Account)
{
    u64 Copy_Balance;
    printf("Enter the Balance \n");
    scanf("%d",&Copy_Balance);
    fflush(stdin);
    ptr_Client_Account->u64_Balance=  Copy_Balance; 

}
/*this func  used dynamicly   takes and asigned it  password  in  struct  of the client   */
void void_Enter_PassWord(Client_Account *ptr_Client_Account)
{
    u64 Copy_Password;
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0,LOC_var_counter;
    Copy_Password=ptr_Client_Account->u8_Full_Name[3]*(100000000);
    while (LOC_ERROR_check)
    {
        for(LOC_var_counter=0;LOC_var_counter<50;LOC_var_counter++)
        {
            Copy_Password+=ptr_Client_Account->u8_Full_Name[LOC_var_counter];
             if (Copy_Password<0)
                    {Copy_Password*=-1;}
                
        }
        if((Copy_Password>999999999)&&(Copy_Password<10000000000))
            {
                if (Copy_Password>0)
                {
                    LOC_ERROR_check=0;
                }
               
            }
            else
            {
                LOC_ERROR_check=1;
                break;
            } 
        
    }
    ptr_Client_Account->u64_Password = Copy_Password;  
    printf(" Password : %d\n", ptr_Client_Account->u64_Password) ; 

}
/*this func  used by Admin  find  the account  information  and can  make som action  on  the account     */
void find_Account()
{       

        Client_Account *ptr;
        u64 LOC_u64_SEARCH_BANK_ID;
        u8 LOC_u8_select_Operation;
        u8 LOC_u8_var;
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
                printf("select the OPeration: \nMAke Transaction=72 \nChange Account Status=148  \nGetCash=59 \nDeposit_In_Account=1  \nReturn_to_Main_Menu=99 \n");
                scanf("%d",&LOC_u8_select_Operation);
                fflush(stdin);
               while(LOC_u8_select_Operation!=Return_to_Main_Menu)
               {
                switch (LOC_u8_select_Operation)
                {
                case MAke_Transaction:
                    MAke_Trans( ptr);
                    printf("select the OPeration: \nMAke Transaction=72 \nChange Account Status=148  \nGetCash=59 \nDeposit_In_Account=1  \nReturn_to_Main_Menu=99 \n");
                    scanf("%d",&LOC_u8_select_Operation);
                    fflush(stdin);
                    break;
                case Change_Account_Status:
                    void_Change_Account_Status(ptr);
                    printf("select the OPeration: \nMAke Transaction=72 \nChange Account Status=148  \nGetCash=59 \nDeposit_In_Account=1  \nReturn_to_Main_Menu=99 \n");
                    scanf("%d",&LOC_u8_select_Operation);
                    fflush(stdin);
                    break;
                case Get_Cash:
                    printf("select the OPeration: \nMAke Transaction=72 \nChange Account Status=148  \nGetCash=59 \nDeposit_In_Account=1  \nReturn_to_Main_Menu=99 \n");
                    scanf("%d",&LOC_u8_select_Operation);
                    fflush(stdin);
                    void_Get_Cash(ptr);
                    break;
                case Deposit_In_Account:
                    printf("select the OPeration: \nMAke Transaction=72 \nChange Account Status=148  \nGetCash=59 \nDeposit_In_Account=1  \nReturn_to_Main_Menu=99 \n");
                    scanf("%d",&LOC_u8_select_Operation);
                    fflush(stdin);
                    void_Deposit_In_Account( ptr );
                    break;
                case Return_to_Main_Menu:
                      break;
                }
               }
                

        }
}
/*check  if  adimn  username and and password    */
u8 u8_Admin_username_Password (u32 Copy_u32_Admin_UserName ,u32 Copy_u32_Admin_Password )
{
   u8 u8_pass_status;
    if ((Copy_u32_Admin_Password == the_Admin_pass)&&(Copy_u32_Admin_UserName==the_Admin_use_name) )
    {
        u8_pass_status = Right_Pass;
    }
    else {
       u8_pass_status = Wronge_pass;
    }

    return u8_pass_status;
}

