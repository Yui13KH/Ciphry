#include <ctype.h>
#include <stdio.h>

#include "atbash.h"
#include "help.h"

void atbash_cipher(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isupper(ch)) {
            ch = 'A' + (25 - (ch - 'A'));
        } else if (islower(ch)) {
            ch = 'a' + (25 - (ch - 'a'));
        }
        putchar(ch);
    }
    putchar('\n');
}

void atbash_run(int argc, char *argv[]) {
    if (argc < 3) {
        print_atbash_help();
        return;
    }

    const char *text = argv[2];
    atbash_cipher(text);
}