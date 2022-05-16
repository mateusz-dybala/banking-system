#ifndef __BANK_H__
#define __BANK_H__

#include <stdio.h>
#include <stdlib.h>
int get_number_of_accounts(FILE *fp);
int save_account(char*, char*, char*, char*, double);

#endif /* __BANK_H__ */