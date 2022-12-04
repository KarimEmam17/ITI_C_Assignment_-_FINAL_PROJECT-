#include"STD_Types.h"
#include "bank.h"
#include<stdlib.h>
#include<stdio.h>
//#include<stdint.h>

 Client_Account *Head=NULL;  
 Client_Account *Last=NULL;

void ITI_Bank_System(void)
{
   
        u8 u8_ITI_Mood;   //Select The  MOOD Admin=6  Client=2
        printf("Select The  MOOD:\nAdmin=6\nClient=2 \n"); 
        scanf("%d",u8_ITI_Mood);
       // fflush();
        switch (u8_ITI_Mood)
        {
            case Admin :
                Admin_Window();
                break;
            case Client:
                find_Account_user();
                break;
            default:
                printf("wronge Selected MOOD  \n");
                break;
        } 
    
}

void Admin_Window (void)
{
    u8 u8_Admin_Mood;
    printf("Select The  MOOD:\nCreat New Account=8\nOpen_Existing_Account=22 \nExit_System=11\n"); 
    scanf("%d",u8_Admin_Mood);
   // fflush();
    while(u8_Admin_Mood!=Exit_System){
    switch (u8_Admin_Mood)
        {
            case Creat_New_Account :
                Creat_New_Client_Account();
                break;
            case Open_Existing_Account:
                find_Account();
                break;
            case Exit_System:

                break;
            
            default:
                printf("wronge Selected MOOD  \n");
                break;
        } }

}
/*void User_Window(Client_Account *Cpoy_str_Ptr)
{
    u8 u8_user_Mood;
    printf("Select The  MOOD:\nMAke Transaction=72\nChange Account Password=38 \nGet Cash=59\nDeposit In Account=1\nReturn to Main Menu=99"); 
    scanf("%d",u8_user_Mood);
    switch (u8_user_Mood)
        {
            case MAke_Transaction :
                break;
            case Change_Account_Password:
                break;
            case Get_Cash:
                break;
            case Deposit_In_Account:
                break;
            case Return_to_Main_Menu:
                break;
            default:
                printf("wronge Selected MOOD  \n");
                break;
        } 

}
*/
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
    if((temp->u16_Age)<21)
    {
         void_Enter_Full_Name_of_Guardian(temp);
         void_Enter_National_ID_of_Guardian(temp);
    }
    void_Set_ACTIVE_Account_Status_(temp);
    void_Set_Balance(temp);
 }

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
    printf(" Please Enter Full Name Of THE Client \n");
    scanf("%[^\n]%*c",Copy_Full_Name_Arr);
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

void void_Enter_National_ID(Client_Account *ptr_Client_Account)
{
    u64 Copy_National_ID;
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0;
    
    while (LOC_ERROR_check)
    {
        if(LOC_Counter_Check==0)
        {    
            printf(" Please Enter Full National ID Of THE Client \n");
            scanf("%d",&Copy_National_ID);
            LOC_Counter_Check++;
        }
        else
        {
              
            printf(" Please Enter Full National ID Of THE Client only Numbers \n");
            scanf("%d",&Copy_National_ID);
        }
        if((Copy_National_ID>9999999999999)&&(Copy_National_ID<100000000000000))
            {
                LOC_ERROR_check=0;
            }
            else
            {
                LOC_ERROR_check=1;
                break;
            } 
        
    }
    ptr_Client_Account->u64_National_ID = Copy_National_ID;  
        
}


void void_Enter_Age(Client_Account *ptr_Client_Account)
{
    u64 Copy_Age;
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0;
    
    while (LOC_ERROR_check)
    {
        if(LOC_Counter_Check==0)
        {    
            printf(" Please Enter Age Of THE Client \n");
            scanf("%d",&Copy_Age);
            LOC_Counter_Check++;
        }
        else
        {
              
            printf(" Please Enter Age Of THE Client only Numbers \n");
            scanf("%d",&Copy_Age);
        }
        if((Copy_Age>0)&&(Copy_Age<100))
            {
                LOC_ERROR_check=0;
            }
            else
            {
                LOC_ERROR_check=1;
                break;
            } 
        
    }
    ptr_Client_Account->u16_Age = Copy_Age;  
        
}


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

void void_Enter_National_ID_of_Guardian(Client_Account *ptr_Client_Account)
{
    u64 Copy_National_ID_of_Guardian;
    u8 LOC_ERROR_check=1,LOC_Counter_Check=0;
    
    while (LOC_ERROR_check)
    {
        if(LOC_Counter_Check==0)
        {    
            printf(" Please Enter Full National ID Of Guardian FOR THE Client \n");
            scanf("%d",&Copy_National_ID_of_Guardian);
            LOC_Counter_Check++;
        }
        else
        {
              
            printf(" Please Enter Full National ID Of Guardian FOR THE Client only Numbers \n");
            scanf("%d",&Copy_National_ID_of_Guardian);
        }
        if((Copy_National_ID_of_Guardian>9999999999999)&&(Copy_National_ID_of_Guardian<100000000000000))
            {
                LOC_ERROR_check=0;
            }
            else
            {
                LOC_ERROR_check=1;
                break;
            } 
        
    }
    ptr_Client_Account->u64_National_ID_of_Guardian = Copy_National_ID_of_Guardian;  
        
}


void void_Set_ACTIVE_Account_Status_(Client_Account *ptr_Client_Account)
{
    ptr_Client_Account->u8_Account_status=  Active;  
}

void void_Set_Balance(Client_Account *ptr_Client_Account)
{
    u64 Copy_Balance;
    printf("Enter the Balance \n");
    scanf("%d",&Copy_Balance);
    ptr_Client_Account->u64_Balance=  Copy_Balance; 

}


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
        }
        if((Copy_Password>999999999)&&(Copy_Password<10000000000))
            {
                LOC_ERROR_check=0;
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

void find_Account_user()
{       

        Client_Account *ptr;
        u64 LOC_u64_SEARCH_BANK_ID;
        u8 LOC_u8_select_Operation;
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
                ptr=Head;
                while(ptr->u64_Bank_ID!=LOC_u64_SEARCH_BANK_ID)
                {
                     ptr=ptr->Next_Acc;
                }
                printf("select the OPeration MAke_Transaction=72 Change_Account_Password=38  Get_Cash=59 Deposit_In_Account=1  Return_to_Main_Menu=99 \n");
                scanf("%d",&LOC_u8_select_Operation);
               while(LOC_u8_select_Operation!=Return_to_Main_Menu)
               {
                switch (LOC_u8_select_Operation)
                {
                case MAke_Transaction:
                    MAke_Trans( ptr);
                    break;
                case Change_Account_Password:
                   void_Change_Account_Password(ptr);
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

void find_Account()
{       

        Client_Account *ptr;
        u64 LOC_u64_SEARCH_BANK_ID;
        u8 LOC_u8_select_Operation;
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
                ptr=Head;
                while(ptr->u64_Bank_ID!=LOC_u64_SEARCH_BANK_ID)
                {
                     ptr=ptr->Next_Acc;
                }
                printf("select the OPeration MAke_Transaction=72 Change_Account_Status=148  Get_Cash=59 Deposit_In_Account=1  Return_to_Main_Menu=99 \n");
                scanf("%d",&LOC_u8_select_Operation);
               while(LOC_u8_select_Operation!=Return_to_Main_Menu)
               {
                switch (LOC_u8_select_Operation)
                {
                case MAke_Transaction:
                    MAke_Trans( ptr);
                    break;
                case Change_Account_Status:
                    void_Change_Account_Status(ptr);
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


void MAke_Trans( Client_Account * PTR_Client_Account )
{
    u64  LoC_u64_tran_mount;
    u64  loc_u64_Bank_ID;
    Client_Account *PTR;
    if(PTR_Client_Account->u8_Account_status==Active)
    {
    printf("enter the mount of money?\n");
    scanf("%ld",&LoC_u64_tran_mount);
    PTR_Client_Account->u64_Balance -=LoC_u64_tran_mount;
    printf("enter the bank id?\n");
    scanf("%ld",&loc_u64_Bank_ID);
                PTR=Head;
                while(PTR->u64_Bank_ID!=loc_u64_Bank_ID)
                {
                     PTR=PTR->Next_Acc;
                }
                PTR->u64_Balance += LoC_u64_tran_mount;
    }
    else{
        printf("the account is not  active\n");
    }            
}
void void_Change_Account_Status( Client_Account * PTR_Client_Account )
{
    
    u64  loc_Account_status;

    printf("enter the  status ? Active =3    Closed=10  Restricted=17 \n");
    scanf("%ld",&loc_Account_status);
    PTR_Client_Account->u8_Account_status=loc_Account_status;
}

void void_Get_Cash( Client_Account * PTR_Client_Account )
{
    u64  LoC_u64_tran_mount;
    
    
    if(PTR_Client_Account->u8_Account_status==Active)
    {
    printf("enter the mount of money?\n");
    scanf("%ld",&LoC_u64_tran_mount);
    PTR_Client_Account->u64_Balance -=LoC_u64_tran_mount;
    
    }
    else{
        printf("the account is not  active\n");
    }            
}

void void_Deposit_In_Account( Client_Account * PTR_Client_Account )
{
    u64  LoC_u64_tran_mount;
    
    
    if(PTR_Client_Account->u8_Account_status==Active)
    {
    printf("enter the mount of money?\n");
    scanf("%ld",&LoC_u64_tran_mount);
    PTR_Client_Account->u64_Balance +=LoC_u64_tran_mount;
    
    }
    else{
        printf("the account is not  active\n");
    }            
}

void void_Change_Account_Password( Client_Account * PTR_Client_Account )
{
    u64  LoC_u64_PASSWord;
    
    
    
    printf("enter the new pass?\n");
    scanf("%ld",&LoC_u64_PASSWord);
    PTR_Client_Account-> u64_Password =LoC_u64_PASSWord;
    
}
              

