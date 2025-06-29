#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("[TEST] Normal case:\n");
    system("./bin/passgen --length 12");

    printf("[TEST] Short password (error expected):\n");
    system("./bin/passgen --length 4");

    printf("[TEST] Multiple passwords:\n");
    system("./bin/passgen --length 12 --count 3");

    return 0;
}
