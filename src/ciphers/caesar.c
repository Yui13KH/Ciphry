#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"
#include "help.h"

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

void rot13_cipher(const char *text){
    encrypt_caesar(text, 13);
}


void caesar_run(int argc, char *argv[]){
    if (argc < 5) {
        print_caesar_help();
        return;
    }

    const char *mode = argv[2];
    const char *text = argv[3];
    int key = atoi(argv[4]);

   if (strcmp(mode, "--encrypt") == 0 || strcmp(mode, "encrypt") == 0) {
    encrypt_caesar(text, key);
} else if (strcmp(mode, "--decrypt") == 0 || strcmp(mode, "decrypt") == 0) {
    decrypt_caesar(text, key);
} else {
    fprintf(stderr, "Unknown mode '%s'. Use '--encrypt' or '--decrypt'.\n", mode);
}
}


void rot13_run(int argc, char *argv[]) {
    if (argc < 3) {
        print_rot13_help();
        return;
    }

    rot13_cipher(argv[2]);
}