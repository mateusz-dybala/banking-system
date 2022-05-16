#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "data.txt"

int get_number_of_accounts(FILE *fp) {
    int len = 0;
    char next;

    while ((next = fgetc(fp)) != EOF)
        if (next == '\n') len++;

    return len;
}


int save_account(char* name, char* surname, char* address, char* pesel, double balance) {
    FILE* fp = fopen(FILE_NAME, "a+");

    int account_number = 1 + get_number_of_accounts(fp);
    fprintf(fp, "%d;%s;%s;%s;%s;%.2lf;\n", account_number, name, surname, address, pesel, balance);

    fclose(fp);
    return account_number;
}