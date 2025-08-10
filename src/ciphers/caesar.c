#include "caesar.h"
#include "help.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_caesar_str(const char *plaintext, int shift_key, char *output) {
    int index = 0;
    while (plaintext[index] != '\0') {
        char current_char = plaintext[index];
        if (isalpha(current_char)) {
            char ascii_offset =
                (current_char >= 'a' && current_char <= 'z') ? 'a' : 'A';
            current_char =
                (current_char - ascii_offset + shift_key) % 26 + ascii_offset;
        }
        output[index] = current_char;
        index++;
    }
    output[index] = '\0';
}

void decrypt_caesar_str(const char *ciphertext, int shift_key, char *output) {
    encrypt_caesar_str(ciphertext, 26 - (shift_key % 26), output);
}

void encrypt_caesar(const char *plaintext, int shift_key) {
    char output[1024];
    encrypt_caesar_str(plaintext, shift_key, output);
    printf("%s\n", output);
}

void decrypt_caesar(const char *ciphertext, int shift_key) {
    char output[1024];
    decrypt_caesar_str(ciphertext, shift_key, output);
    printf("%s\n", output);
}

void rot13_cipher(const char *text) {
    encrypt_caesar(text, 13);
}

// CLI interface function unchanged except calling printing versions
void caesar_run(int argc, char *argv[]) {
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
        fprintf(stderr, "Unknown mode '%s'. Use '--encrypt' or '--decrypt'.\n",
                mode);
    }
}

void rot13_run(int argc, char *argv[]) {
    if (argc < 3) {
        print_rot13_help();
        return;
    }
    rot13_cipher(argv[2]);
}
