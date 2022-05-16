#include <stdio.h>

#define MAX_LINE_LEN 60
#define ACC_NUM_LEN 5


void main_menu();
void search_menu();
void transfer_money_menu();
void deposit_money_menu();
void withdraw_money_menu();


int get_input(char* line, int size) {
    char next;
    int index = 0;
    while((next=getchar())!='\n' && index < size) {
        line[index] = next;
        index++;
    }
    if (index == 0) return 0;
    return 1;
}


void main_menu() {
    int sc = 0;
    int option = -1;

    while (sc != 1) {
        printf("1. List all accounts\n"
               "2. Search by field\n"
               "3. Make a transfer\n"
               "4. Make a deposit\n"
               "5. Make a withdrawal\n"
               "6. Close programme\n"
               "Enter number corresponding to the option:");
        sc = scanf("%d", &option);
        while (getchar()!='\n');
    }

    switch (option) {
        case 1:
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

        printf("Enter searched phrase:");
        sc += scanf("%s", search_query);\
    } while (sc != 2 || option < 1 || option > 5);

    printf("%d: %s\n", option, search_query);
}

void transfer_money_menu() {
    int sc;
    double amount;
    char account_from[ACC_NUM_LEN + 1];
    char account_to[ACC_NUM_LEN + 1];

    do {
        printf("To make a money transfer enter corresponding fields:\n");
        printf("Transfer from (account number):");
        sc = scanf("%5s", account_from);
        while (getchar()!='\n');

        printf("Transfer to (account number):");
        sc += scanf("%5s", account_to);
        while (getchar()!='\n');

        printf("Transfer amount:");
        sc += scanf("%lf", &amount);
        while (getchar()!='\n');
    } while (sc != 3);

    printf("From %s to %s transfer %.2lf\n", account_from, account_to, amount);
}

void deposit_money_menu() {
    int sc;
    double amount;
    char account[ACC_NUM_LEN + 1];

    do {
        printf("To deposit money enter corresponding fields:\n");
        printf("Deposit to (account number):");
        sc = scanf("%5s", account);
        while (getchar()!='\n');

        printf("Deposit amount:");
        sc += scanf("%lf", &amount);
        while (getchar()!='\n');
    } while (sc != 2 || amount <= 0);

    printf("Deposited %.2lf to account %s\n", amount, account);
}

void withdraw_money_menu() {
    int sc;
    double amount;
    char account[ACC_NUM_LEN + 1];

    do {
        printf("To withdraw money enter corresponding fields:\n");
        printf("Withdraw from (account number):");
        sc = scanf("%5s", account);
        while (getchar()!='\n');

        printf("Withdraw amount:");
        sc += scanf("%lf", &amount);
        while (getchar()!='\n');
    } while (sc != 2 || amount <= 0);

    printf("Withdrawn %.2lf from account %s\n", amount, account);
}
















