#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "atbash.h"
#include "help.h"

void atbash_cipher(const char *text, char *output) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isupper(ch)) {
            ch = 'A' + (25 - (ch - 'A'));
        } else if (islower(ch)) {
            ch = 'a' + (25 - (ch - 'a'));
        }
        output[i] = ch;
    }
    output[strlen(text)] = '\0'; // null-terminate output
}

void atbash_run(int argc, char *argv[]) {
    if (argc > 3) {
        print_atbash_help();
        return;
    }

    const char *text = argv[2];
    char output[1024]; // big enough buffer
    atbash_cipher(text, output);
    printf("%s\n", output);
}
