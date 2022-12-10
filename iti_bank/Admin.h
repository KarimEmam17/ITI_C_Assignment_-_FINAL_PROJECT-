#ifndef ADMIN_H_
#define ADMIN_H_
#include "STD_Types.h"


//typedef struct Bank_Account Client_Account;
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
void find_Account(void);
u8 u8_Admin_username_Password (u32 Copy_u32_Admin_UserName ,u32 Copy_u32_Admin_Password );





#endif