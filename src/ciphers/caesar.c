#include <stdio.h>
#include <ctype.h>
#include "caesar.h"

void encrypt_caesar(const char *plaintext, int shift_key) {
    for (int index = 0; plaintext[index] != '\0'; index++) {
        char current_char = plaintext[index];
        if (isalpha(current_char)) {
            char ascii_offset = (current_char >= 'a' && current_char <= 'z') ? 'a' : 'A';
            current_char = (current_char - ascii_offset + shift_key) % 26 + ascii_offset;
        }
        putchar(current_char);
    }
    putchar('\n');
}

void decrypt_caesar(const char *ciphertext, int shift_key) {
    encrypt_caesar(ciphertext, 26 - (shift_key % 26));
}
