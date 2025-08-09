#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "affine.h"
#include "utils.h"

#define MODULUS 26 // assuming english alphabet

// Encrypt/Decrypt function
void affine_cipher(const char *text, int a, int b, int encrypt) {
    for (size_t i = 0; i < strlen(text); i++) {
        char c = text[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int x = c - base;

            if (encrypt) {
                // Encryption: E(x) = (a*x + b) mod m
                int enc = (a * x + b) % MODULUS;
                printf("%c", base + enc);
            } else {
                // Decryption: D(x) = a_inv * (x - b) mod m
                int a_inv = 0;

                // Find multiplicative inverse of a mod m
                for (int i = 1; i < MODULUS; i++) {
                    if ((a * i) % MODULUS == 1) {
                        a_inv = i;
                        break;
                    }
                }

                int dec = (a_inv * ((x - b + MODULUS) % MODULUS)) % MODULUS;
                printf("%c", base + dec);
            }
        } else {
            printf("%c", c); // Non-alphabetic characters unchanged
        }
    }
    printf("\n");
}

// CLI handler for affine
void affine_run(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: ciphry affine --encrypt/--decrypt <text> --a <a> --b <b>\n");
        return;
    }

    int encrypt = -1;
    const char *text = NULL;
    int a = 0, b = 0;

    // Simple arg parsing
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "--encrypt") == 0) {
            encrypt = 1;
            text = argv[++i];
        } else if (strcmp(argv[i], "--decrypt") == 0) {
            encrypt = 0;
            text = argv[++i];
        } else if (strcmp(argv[i], "--a") == 0) {
            a = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--b") == 0) {
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

    affine_cipher(text, a, b, encrypt);
}
