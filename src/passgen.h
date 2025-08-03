#ifndef PASSGEN_H
#define PASSGEN_H

#include <stdbool.h>

char *build_charset(bool use_letters, bool use_digits, bool use_specials);
char *generate_password(const char *charset, int length);



#endif //PASSGEN_H