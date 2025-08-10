#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "affine.h"
#include "utils.h"

#define MODULUS 26 // assuming english alphabet

// Encrypt/Decrypt function writing to output buffer
void affine_cipher(const char *text, int a, int b, int encrypt, char *output) {
    size_t len = strlen(text);
    for (size_t i = 0; i < len; i++) {
        char c = text[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int x = c - base;

            if (encrypt) {
                // Encryption: E(x) = (a*x + b) mod m
                int enc = (a * x + b) % MODULUS;
                output[i] = base + enc;
            } else {
                // Decryption: D(x) = a_inv * (x - b) mod m
                int a_inv = 0;

                // Find multiplicative inverse of a mod m
                for (int j = 1; j < MODULUS; j++) {
                    if ((a * j) % MODULUS == 1) {
                        a_inv = j;
                        break;
                    }
                }

                int dec = (a_inv * ((x - b + MODULUS) % MODULUS)) % MODULUS;
                output[i] = base + dec;
            }
        } else {
            output[i] = c; // Non-alphabetic characters unchanged
        }
    }
    output[len] = '\0'; // Null-terminate output string
}

// CLI handler for affine
void affine_run(int argc, char *argv[]) {
    if (argc < 7) { // Adjusted expected args count due to flags and params
        fprintf(stderr, "Usage: ciphry affine --encrypt/--decrypt <text> --a "
                        "<a> --b <b>\n");
        return;
    }

    int encrypt = -1;
    const char *text = NULL;
    int a = 0, b = 0;

    // Simple arg parsing
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "--encrypt") == 0) {
            encrypt = 1;
            if (i + 1 < argc)
                text = argv[++i];
        } else if (strcmp(argv[i], "--decrypt") == 0) {
            encrypt = 0;
            if (i + 1 < argc)
                text = argv[++i];
        } else if (strcmp(argv[i], "--a") == 0) {
            if (i + 1 < argc)
                a = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--b") == 0) {
            if (i + 1 < argc)
                b = atoi(argv[++i]);
        }
    }

    if (encrypt == -1 || !text) {
        fprintf(stderr, "Error: Missing encryption/decryption mode or text.\n");
        return;
    }

    if (!is_coprime(a, MODULUS)) {
        fprintf(stderr, "Error: 'a' must be coprime with %d.\n", MODULUS);
        return;
    }

    char output[1024]; // buffer large enough for most uses
    affine_cipher(text, a, b, encrypt, output);
    printf("%s\n", output);
}
