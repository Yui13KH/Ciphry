#include "xor.h"
#include "help.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Core XOR cipher (unchanged)
void xor_cipher(const unsigned char *input, size_t input_len, const char *key,
                size_t key_len, unsigned char *output) {
    for (size_t i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
}

// Helper for tests: encrypt plaintext to malloc’d hex string
char *xor_encrypt_str(const char *plaintext, const char *key) {
    size_t len = strlen(plaintext);
    unsigned char *output_bytes = malloc(len);
    if (!output_bytes)
        return NULL;

    xor_cipher((const unsigned char *)plaintext, len, key, strlen(key),
               output_bytes);

    // Allocate hex output string (2 chars per byte + null)
    char *hex_out = malloc(len * 2 + 1);
    if (!hex_out) {
        free(output_bytes);
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        sprintf(hex_out + i * 2, "%02X", output_bytes[i]);
    }
    hex_out[len * 2] = '\0';

    free(output_bytes);
    return hex_out;
}

// Helper for tests: decrypt hex string to malloc’d plaintext string
char *xor_decrypt_str(const char *hextext, const char *key) {
    size_t hex_len = strlen(hextext);
    if (hex_len % 2 != 0)
        return NULL;

    size_t byte_len = hex_len / 2;
    unsigned char *bytes = malloc(byte_len);
    if (!bytes)
        return NULL;

    for (size_t i = 0; i < byte_len; i++) {
        bytes[i] = hex_to_byte(hextext[i * 2], hextext[i * 2 + 1]);
    }

    unsigned char *output = malloc(byte_len + 1);
    if (!output) {
        free(bytes);
        return NULL;
    }

    xor_cipher(bytes, byte_len, key, strlen(key), output);
    output[byte_len] = '\0'; // null-terminate

    free(bytes);
    return (char *)output;
}

// CLI runner (unchanged)
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
