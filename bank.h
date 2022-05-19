#ifndef __BANK_H__
#define __BANK_H__

#include <stdio.h>
#include <stdlib.h>
typedef struct Account Account;
int get_number_of_accounts(FILE*);
int save_account(char*, char*, char*, char*, double);
Account load_Account(FILE*);
int is_account_in_database(int);
void print_accounts();
int change_balance(int, double);
char* to_lower(char*);
int check_fields(Account, int, char*);
void search_for_accounts(int, char*);

#endif /* __BANK_H__ */