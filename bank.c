#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "data.txt"

typedef struct Account {
    int number;
    char name[31];
    char surname[31];
    char address[31];
    char pesel[12];
    double balance;
} Account;


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


Account load_Account(FILE *fp) {
    Account account;
    fscanf(fp, "%d;%30[^;];%30[^;];%50[^;];%11[^;];%lf;\n", &account.number, account.name, account.surname, account.address, account.pesel, &account.balance);
    return account;
}


int is_account_in_database(int acc_num) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) return 0;

    Account account;

    while (!feof(fp)) {
        account = load_Account(fp);
        if (account.number == acc_num) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// TODO https://www.geeksforgeeks.org/using-variable-format-specifier-c/
void print_accounts() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("No accounts in database\n");
        return;
    }
    Account account;

    printf("\n");
    while (!feof(fp)) {
        account = load_Account(fp);
        printf("Account number: %05d\n"
               "Name: %s %s\n"
               "Pesel: %s\n"
               "Address: %s\n"
               "Balance: %.2lf\n\n",
               account.number, account.name, account.surname, account.pesel, account.address, account.balance);
    }
    fclose(fp);
}


int change_balance(int acc_num, double value) {
    FILE *fp = fopen(FILE_NAME, "r");
    char *temp_name = "temp.txt";
    FILE *temp = fopen(temp_name, "w");

    Account account;
    int success = 0;

    while (!feof(fp)) {
        account = load_Account(fp);

        if (account.number == acc_num && account.balance - value >= 0) {
            account.balance += value;
            success = 1;
        }
        fprintf(temp, "%d;%s;%s;%s;%s;%.2lf;\n", account.number, account.name, account.surname, account.address, account.pesel, account.balance);
    }
    fclose(fp);
    fclose(temp);

    if (!success) {
        remove(temp_name);
        return 0;
    }

    remove(FILE_NAME);
    rename(temp_name, FILE_NAME);
    return 1;

}


char* to_lower(char* str) {
    int index = 0;
    while (str[index] != '\0') {
        str[index] = (char) tolower(str[index]);
        index++;
    }
    return str;
}


int check_fields(Account account, int field, char* query) {
    switch (field) {
        case 1:
            if (account.number == strtol(query, NULL, 10))
                return 1;
        case 2:
            if (strstr(to_lower(account.name), query))
                return 1;
        case 3:
            if (strstr(to_lower(account.surname), query))
                return 1;
        case 4:
            if (strstr(to_lower(account.address), query))
                return 1;
        case 5:
            if (strstr(to_lower(account.pesel), query))
                return 1;
        default:
            return 0;
    }
}


void search_for_accounts(int field, char* query) {
    FILE *fp = fopen(FILE_NAME, "r");
    int max_size = get_number_of_accounts(fp);
    rewind(fp);

    Account results[max_size];
    int size = 0;
    while (!feof(fp)) {
        Account account = load_Account(fp);

        if (check_fields(account, field, to_lower(query))) {
            results[size] = account;
            size++;
        }
    }
    fclose(fp);

    printf("Found %d %s:\n\n", size, size == 1 ? "result" : "results");
    for (int index = 0; index < size; index++) {
        printf("Account number: %05d\n"
               "Name: %s %s\n"
               "Pesel: %s\n"
               "Address: %s\n"
               "Balance: %.2lf\n\n",
               results[index].number,
               results[index].name,
               results[index].surname,
               results[index].pesel,
               results[index].address,
               results[index].balance);
    }
}
