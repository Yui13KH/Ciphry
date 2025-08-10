#include "xor.h"
#include "help.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// XOR cipher function: input_len bytes XORed with key (key_len bytes), output
// written to output
void xor_cipher(const unsigned char *input, size_t input_len, const char *key,
                size_t key_len, unsigned char *output) {
    for (size_t i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
}

void xor_run(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Error: Missing arguments for XOR cipher.\n");
        print_xor_help();
        return;
    }

    const char *mode = argv[2];
    const char *key = argv[3];
    const char *text = argv[4];

    size_t key_len = strlen(key);

    if (key_len == 0) {
        fprintf(stderr, "Error: Key cannot be empty.\n");
        return;
    }

    if (strcmp(mode, "--encrypt") == 0 || strcmp(mode, "encrypt") == 0) {
        size_t input_len = strlen(text);
        unsigned char *output = malloc(input_len);
        if (!output) {
            perror("malloc");
            return;
        }

        xor_cipher((const unsigned char *)text, input_len, key, key_len,
                   output);

        // Print encrypted output as hex string
        for (size_t i = 0; i < input_len; i++) {
            printf("%02X", output[i]);
        }
        printf("\n");

        free(output);
    } else if (strcmp(mode, "--decrypt") == 0 || strcmp(mode, "decrypt") == 0) {
        size_t hex_len = strlen(text);

        if (hex_len % 2 != 0) {
            fprintf(stderr,
                    "Error: Encrypted hex string length must be even.\n");
            return;
        }

        size_t byte_len = hex_len / 2;
        unsigned char *bytes = malloc(byte_len);
        if (!bytes) {
            perror("malloc");
            return;
        }

        for (size_t i = 0; i < byte_len; i++) {
            bytes[i] = hex_to_byte(text[i * 2], text[i * 2 + 1]);
        }

        unsigned char *output = malloc(byte_len);
        if (!output) {
            perror("malloc");
            free(bytes);
            return;
        }

        xor_cipher(bytes, byte_len, key, key_len, output);

        // Print decrypted output as raw bytes (may include non-printables)
        for (size_t i = 0; i < byte_len; i++) {
            putchar(output[i]);
        }
        putchar('\n');

        free(bytes);
        free(output);
    } else {
        fprintf(stderr, "Unknown mode: %s\n", mode);
        print_xor_help();
    }
}