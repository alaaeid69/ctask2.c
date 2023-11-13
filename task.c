#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[20];
    char password[12];
    union {
        int active_flag;
        char active_flag_str[5];
    } flag;
};

int main() {
    struct User user;
    char input_username[20];
    char input_password[12];
    
    printf("Welcome to registration\n");
    printf("Enter username: ");
    scanf("%s", user.username);

    printf("Enter password: ");
    scanf("%s", user.password);

    printf("Set user status (true/1 or false/0): ");
    scanf("%s", user.flag.active_flag_str);

    printf("User registered successfully.\n");

    printf("Welcome to login\n");
    printf("Enter your username: ");
    scanf("%s", input_username);
    printf("Enter your password: ");
    scanf("%s", input_password);

    if (strcmp(input_username, user.username) == 0 && strcmp(input_password, user.password) == 0) {
        if (strcmp(user.flag.active_flag_str, "true") == 0 || strcmp(user.flag.active_flag_str, "1") == 0) {
            printf("Login successful!\n");
        } else {
            printf("You are not an active user.\n");
        }
    } else {
        printf("Wrong username or password, please try again.\n");
    }

    return 0;
}