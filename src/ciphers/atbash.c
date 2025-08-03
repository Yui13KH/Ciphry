#include <ctype.h>
#include <stdio.h>
#include "atbash.h"

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
