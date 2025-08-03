#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "passgen.h"

char *build_charset(bool use_letters, bool use_digits, bool use_specials)
{
    char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *digits = "0123456789";
    char *specials = "!@#$%^&*()_+-=[]{};:,.<>?";

    int total = 0;
    if (use_letters) total += strlen(letters);
    if (use_digits) total += strlen(digits);
    if (use_specials) total += strlen(specials);

    if(total == 0) return NULL;

    char *charset = malloc(total +1);

    charset[0] = '\0';

    if (use_letters) strcat(charset, letters);
    if (use_digits) strcat(charset, digits);
    if (use_specials) strcat(charset, specials);

    return charset;
}

char *generate_password(const char *charset, int length)
{
    if (charset == NULL || length <= 0) return NULL;

    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++)
    {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
    
    return password;
}
