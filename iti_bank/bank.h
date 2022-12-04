#include"STD_Types.h"
#define Active                   3
#define Closed                   10
#define Restricted               17

#define Guardian_for_client_Age  21
#define National_ID_14_digit     14
 
#define Admin                    6  
#define Client                   2
 
#define Creat_New_Account        8
#define Open_Existing_Account    22
#define Exit_System              11
 
#define MAke_Transaction         72
#define Change_Account_Password  38
#define Change_Account_Status    148
#define Get_Cash                 59
#define Deposit_In_Account       1
#define Return_to_Main_Menu      99
typedef struct Bank_Account Client_Account;
struct Bank_Account
{
    u8  u8_Full_Name[50];                //the full  name of the  client :karim Mohamed Emam Mohamed
    u8  u8_Full_Address[50];             //the full  Address  of the client: 
    u64 u64_National_ID;                 //the national  id  for  the client  14 digites 
    u16 u16_Age;                         // the age of the clinte
    u64 u64_Bank_ID;                     // the bank  account  of the client  10digites
    // the guardian is  need if client  less than  21
    u8  u8_Full_Name_of_Guardian[50];    //the full  name of the Guardian :ex ..karim Mohamed Emam Mohamed
    u64 u64_National_ID_of_Guardian;     //the national  id  for  the client  14 digites
    u8  u8_Account_status ;              //Account status Active =3  closed =10  Restricted =17  the defualt  is active
    u64 u64_Balance ;                    //the  balance of the client account
    u64 u64_Password;                    //the password  of  the Account  
    Client_Account *Next_Acc;
    Client_Account *Previous_Acc;
};
void Admin_Window(void);
void Creat_New_Client_Account(void);
void void_Enter_Full_Name(Client_Account *ptr_Client_Account);
void void_Enter_Full_Address(Client_Account *ptr_Client_Account);
void void_Enter_National_ID(Client_Account *ptr_Client_Account);
void void_Enter_Age(Client_Account *ptr_Client_Account);
void void_Enter_Bank_ID(Client_Account *ptr_Client_Account);
void void_Enter_Full_Name_of_Guardian(Client_Account *ptr_Client_Account);
void void_Enter_National_ID_of_Guardian(Client_Account *ptr_Client_Account);
void void_Set_ACTIVE_Account_Status_(Client_Account *ptr_Client_Account);
void void_Set_Balance(Client_Account *ptr_Client_Account);
void void_Enter_PassWord(Client_Account *ptr_Client_Account);
void find_Account_user();
void find_Account();
void MAke_Trans( Client_Account * PTR_Client_Account );
void void_Change_Account_Status( Client_Account * PTR_Client_Account );
void void_Get_Cash( Client_Account * PTR_Client_Account );
void void_Deposit_In_Account( Client_Account * PTR_Client_Account );
void ITI_Bank_System(void);
void void_Change_Account_Password( Client_Account * PTR_Client_Account );
