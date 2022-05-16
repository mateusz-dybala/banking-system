#include <stdio.h>


int save_account(char* name, char* surname, char* address, char* pesel, float balance) {

    printf("%s %s %s %s %f\n", name, surname, address, pesel, balance);

    return 0;
}