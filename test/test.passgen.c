#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("[TEST] Normal case:\n");
    system("./bin/passgen -n 12");

    printf("[TEST] Short password (error expected):\n");
    system("./bin/passgen -n 4");

    printf("[TEST] Multiple passwords:\n");
    system("./bin/passgen -n 12 -c 3");

    return 0;
}
