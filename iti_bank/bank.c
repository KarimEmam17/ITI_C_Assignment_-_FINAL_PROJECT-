#include"STD_Types.h"
#include<stdlib.h>
#include<stdio.h>
#include "bank.h"
#include "Admin.h"
#include "client.h"
extern  Client_Account *Head;  
extern  Client_Account *Last;
/* this is the main  function  of the system  of the all the bank  this calls one of two  func  ADMIN_WINDOW OR USER_WINdoW */
void ITI_Bank_System(void)
    {
        u8 u8_ITI_Mood;  //Select The  MOOD Admin=6  Client=2
        u32 u32_Admin_pass;   // pass= 75
        u32 u32_Admin_UserName;//user=1234
	    u8 LOC_u8_pass_status; //var that 
        printf("Select The  MODE:\nAdmin=6\nClient=2\n");
	    scanf("%d",&u8_ITI_Mood);
	    fflush(stdin);  
    
       if (u8_ITI_Mood==Admin)
	   {
        printf("please  enter  the  username of the admin ? \n ");
	    scanf("%d",&u32_Admin_UserName);//Ask  the username
        printf("please  enter  the  password of the admin ? \n ");
	    scanf("%d",&u32_Admin_pass);// Ask  to  enter  the password 
        LOC_u8_pass_status= u8_Admin_username_Password (u32_Admin_UserName,u32_Admin_pass);// this func check  the user and password and return  it  if right  or wrong
		  if(LOC_u8_pass_status== Right_Pass)
          { Admin_Window();// this fun is the main  system  of the admin 
          }
          else{
          printf("Wrong  pass \n");}
	   }
       else if (u8_ITI_Mood==Client)    
       {
                find_Account_user(); //this func  is the main system  of client (user) 
       }
       else
	   {
                printf("wronge Selected MODE  \n");
    
        } 
}

/*this func is  called  by  both  Admin_Window  And USER_window ----------   and control  the balance */
void MAke_Trans( Client_Account * PTR_Client_Account )
{
    u64  LoC_u64_tran_mount;//var takes the amount  of the money  that  will  transfer from one acount  to anather  
    u64  loc_u64_Bank_ID;//the var is used to  serch  the bank id that will  transfer the money  to  it 
    Client_Account *PTR;
    if(PTR_Client_Account->u8_Account_status==Active)// check  the accoount status if is it Active it will  continue
    {
    printf("enter the mount of money?\n"); 
    scanf("%ld",&LoC_u64_tran_mount);
    fflush(stdin);
    PTR_Client_Account->u64_Balance -=LoC_u64_tran_mount;   // we subtract  the money  from  the balance of first  client 
    printf("enter the bank id?\n");
    scanf("%ld",&loc_u64_Bank_ID);
    fflush(stdin);
                PTR=Head;
                while(PTR->u64_Bank_ID!=loc_u64_Bank_ID)
                {
                     PTR=PTR->Next_Acc; //we search  for  this ID 
                }
                PTR->u64_Balance += LoC_u64_tran_mount;// we summation  the money with   the balance of second  client 
    }
    else{
        printf("the account is not  Active\n");
    }            
}

/*this func is  called  by  both  Admin_Window  ----------   and control  the status of account  */
void void_Change_Account_Status( Client_Account * PTR_Client_Account )
{
    
    u64  loc_Account_status;  // var that will contain new status 

    printf("enter the  status ? Active =3    Closed=10  Restricted=17 \n");
    scanf("%ld",&loc_Account_status);
    fflush(stdin);
    PTR_Client_Account->u8_Account_status=loc_Account_status;
}

/*this func is  called  by  both  Admin_Window  And USER_window ----------   and control  the balance */
void void_Get_Cash( Client_Account * PTR_Client_Account )
{
    u64  LoC_u64_tran_mount;// var is get  the ammount of money that will  subtract from  Account     
    
    
    if(PTR_Client_Account->u8_Account_status==Active)// check  if the  account status is Active 
    {
    printf("enter the mount of money?\n");
    scanf("%ld",&LoC_u64_tran_mount);
    fflush(stdin);
    PTR_Client_Account->u64_Balance -=LoC_u64_tran_mount;
    
    }
    else{
        printf("the account is not  active\n");
    }            
}


/*this func is  called  by  both  Admin_Window  And USER_window ----------   and control  the balance */
void void_Deposit_In_Account( Client_Account * PTR_Client_Account )
{
    u64  LoC_u64_tran_mount;// var that  contian the money 
    
    
    if(PTR_Client_Account->u8_Account_status==Active)
    {
    printf("enter the mount of money?\n");
    scanf("%ld",&LoC_u64_tran_mount);
    fflush(stdin);
    PTR_Client_Account->u64_Balance +=LoC_u64_tran_mount;//   we summation the current  balance with the var  
    
    }
    else{
        printf("the account is not  active\n");
    }            
}

