#ifndef BANK_H_
#define BANK_H_
#include"STD_Types.h"
#include"stdio.h" 
// account  status 
#define Active                   3
#define Closed                   10
#define Restricted               17
// the  age  that  if it younger   we need gurdian 
#define Guardian_for_client_Age  21
// the national id  digits 
#define National_ID_14_digit     14
 // the modes
#define Admin                    6  
#define Client                   2
 //the modes in adimn mood 
#define Creat_New_Account        8
#define Open_Existing_Account    22
#define Exit_System              11
#define MAke_Transaction         72
//admin 
#define Change_Account_Password  38
#define Change_Account_Status    148
#define Get_Cash                 59
#define Deposit_In_Account       1
#define Return_to_Main_Menu      99

#define the_Admin_pass           75
#define the_Admin_use_name       1234
#define Right_Pass               9
#define Wronge_pass              204



typedef struct Bank_Account Client_Account;
struct Bank_Account
{
    u8  u8_Full_Name[50];                //the full  name of the  client :karim Mohamed Emam Mohamed
    u8  u8_Full_Address[50];             //the full  Address  of the client: 
    u8  u8_National_ID[20];                 //the national  id  for  the client  14 digites 
    u16 u16_Age;                         // the age of the clinte
    u64 u64_Bank_ID;                     // the bank  account  of the client  10digites
    // the guardian is  need if client  less than  21
    u8  u8_Full_Name_of_Guardian[50];    //the full  name of the Guardian :ex ..karim Mohamed Emam Mohamed
    u8  u8_National_ID_of_Guardian[20];     //the national  id  for  the client  14 digites
    u8  u8_Account_status ;              //Account status Active =3  closed =10  Restricted =17  the defualt  is active
    u64 u64_Balance ;                    //the  balance of the client account
    u64 u64_Password;                    //the password  of  the Account  
    Client_Account *Next_Acc;
    Client_Account *Previous_Acc;
};
 


void MAke_Trans( Client_Account * PTR_Client_Account );
void void_Get_Cash( Client_Account * PTR_Client_Account );
void void_Deposit_In_Account( Client_Account * PTR_Client_Account );
void ITI_Bank_System(void);
void void_Change_Account_Status( Client_Account * PTR_Client_Account );


#endif