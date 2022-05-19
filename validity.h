#ifndef __VALIDITY_H__
#define __VALIDITY_H__

#include <ctype.h>
#include <stdio.h>
#define MAX_NAME_LEN 30
#define MAX_ADDRESS_LEN 50
#define PESEL_LEN 11
int is_valid_name(char*);
int is_valid_address(char*);
int is_valid_pesel(char*);

#endif /* __VALIDITY_H__ */