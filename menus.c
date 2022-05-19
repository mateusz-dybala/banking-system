#include <stdio.h>
#include <string.h>
#include "bank.h"
#include "validity.h"

#define MAX_LINE_LEN 60
#define ACC_NUM_LEN 5


void main_menu();
void search_menu();
void transfer_money_menu();
void deposit_money_menu();
void withdraw_money_menu();
void add_account();


void main_menu() {
    int sc = 0;
    int option = -1;

    while (sc != 1) {
        printf("1. List all accounts\n"
               "2. Search by field\n"
               "3. Make a transfer\n"
               "4. Make a deposit\n"
               "5. Make a withdrawal\n"
               "6. Add new account\n"
               "7. Close programme\n"
               "Enter number corresponding to the option:");
        sc = scanf("%d", &option);
        while (getchar()!='\n');
    }

    switch (option) {
        case 1:
            print_accounts();
            break;
        case 2:
            search_menu();
            break;
        case 3:
            transfer_money_menu();
            break;
        case 4:
            deposit_money_menu();
            break;
        case 5:
            withdraw_money_menu();
            break;
        case 6:
            add_account();
            break;
        case 7:
            return;
        default:
            break;
    }

    main_menu();
}

void search_menu() {
    int sc;
    int option = -1;
    char search_query[MAX_LINE_LEN];

    do {
        printf("Search by:\n"
               "1. Account number\n"
               "2. Name\n"
               "3. Surname\n"
               "4. Address\n"
               "5. Pesel\n"
               "Enter corresponding number:");
        sc = scanf("%d", &option);
        while (getchar()!='\n');
        if (sc == 0) continue;

        printf("Enter searched phrase:");
        sc += scanf("%s", search_query);
    } while (sc != 2 || option < 1 || option > 5);

    search_for_accounts(option, search_query);
}

void transfer_money_menu() {
    int sc, account_from, account_to;
    double amount;

    do {
        printf("To make a money transfer enter corresponding fields:\n");
        printf("Transfer from (account number):");
        sc = scanf("%d", &account_from);
        while (getchar()!='\n');

        printf("Transfer to (account number):");
        sc += scanf("%d", &account_to);
        while (getchar()!='\n');

        printf("Transfer amount:");
        sc += scanf("%lf", &amount);
        while (getchar()!='\n');
    } while (sc != 3);

    if (is_account_in_database(account_from) && is_account_in_database(account_to)) {
        if (!change_balance(account_from, -amount)) {
            printf("Not enough balance to make a transfer\n");
            return;
        }
        change_balance(account_to, amount);
        printf("Transferred %.2lf from %05d to %05d\n", amount, account_from, account_to);
    }else {
        printf("Account not in database\n");
    }
}

void deposit_money_menu() {
    int sc, acc_num;
    double amount;

    do {
        printf("To deposit money enter corresponding fields:\n");
        printf("Deposit to (account number):");
        sc = scanf("%d", &acc_num);
        while (getchar()!='\n');

        printf("Deposit amount:");
        sc += scanf("%lf", &amount);
        while (getchar()!='\n');
    } while (sc != 2 || amount <= 0);

    if (change_balance(acc_num, amount)) {
        printf("Deposited %.2lf to account %05d\n", amount, acc_num);
    }else {
        printf("Account not in database\n");
    }
}

void withdraw_money_menu() {
    int sc, acc_num;
    double amount;

    do {
        printf("To withdraw money enter corresponding fields:\n");
        printf("Withdraw from (account number):");
        sc = scanf("%d", &acc_num);
        while (getchar()!='\n');

        printf("Withdraw amount:");
        sc += scanf("%lf", &amount);
        while (getchar()!='\n');
    } while (sc != 2 || amount <= 0);

    int success = change_balance(acc_num, -amount);
    if (success) {
        printf("Withdraw  %.2lf from account %05d\n", amount, acc_num);
    }
    if(success == -1){
        printf("Account not in database\n");
    }else {
        printf("Not enough balance\n");
    }
}


void add_account() {
    int sc;
    char name[31];
    char surname[31];
    char address[51];
    char pesel[12];
    double balance;

    do {
        printf("To create an account enter corresponding fields:\n");
        printf("Name:");
        sc = scanf("%30s", name);
        while (getchar()!='\n');
        if (!is_valid_name(name)) continue;

        printf("Surname:");
        sc += scanf("%30s", surname);
        while (getchar()!='\n');
        if (!is_valid_name(surname)) continue;

        printf("Address:");
        sc += scanf("%50[^\n]", address);
        while (getchar()!='\n');
        if (!is_valid_address(address)) continue;

        printf("Pesel:");
        sc += scanf("%11s", pesel);
        while (getchar()!='\n');
        if (!is_valid_pesel(pesel)) continue;

        printf("Balance:");
        sc += scanf("%lf", &balance);
        while (getchar()!='\n');
    } while (sc != 5 || balance < 0);

    int acc_num = save_account(name, surname, address, pesel, balance);
    printf("Account number %05d saved\n", acc_num);
}














