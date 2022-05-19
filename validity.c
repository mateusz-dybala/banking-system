#include <ctype.h>
#include <stdio.h>

#define MIN_NAME_LEN 3
#define MAX_NAME_LEN 30
#define MIN_ADDRESS_LEN 8
#define MAX_ADDRESS_LEN 50
#define PESEL_LEN 11
#define SEMICOLON ';'
#define SPACE ' '

int is_valid_name(char* name) {
    if (name == NULL) return 0;

    int index = 0;
    char char_value = name[index];

    while (char_value != '\0') {
        if (!isalpha(char_value) || index >= MAX_NAME_LEN || char_value == SEMICOLON) {
            return 0;
        }
        index++;
        char_value = name[index];
    }

    if (index < MIN_NAME_LEN) {
        return 0;
    }

    return 1;
}

int is_valid_address(char* address) {
    if (address == NULL) return 0;

    int index = 0;
    char char_value = address[index];

    while (char_value != '\0') {
        if ((!isalnum(char_value) && char_value != SPACE) || index >= MAX_ADDRESS_LEN || char_value == SEMICOLON) {
            return 0;
        }

        index++;
        char_value = address[index];
    }

    if (index < MIN_ADDRESS_LEN) {
        return 0;
    }

    return 1;
}

int is_valid_pesel(char* pesel) {
    int index = 0;
    char char_value = pesel[index];

    while (char_value != '\0') {
        if (!isdigit(char_value) || index > PESEL_LEN || char_value == SEMICOLON) {
            return 0;
        }
        index++;
        char_value = pesel[index];
    }

    if (index != PESEL_LEN) return 0;
    return 1;
}


























