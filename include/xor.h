#ifndef XOR_H
#define XOR_H

#include <stddef.h>

// Core XOR cipher function
void xor_cipher(const unsigned char *input, size_t input_len, const char *key,
                size_t key_len, unsigned char *output);

// CLI runner
void xor_run(int argc, char **argv);

// Test helpers: allocate and return malloc’d strings (caller must free)
char *xor_encrypt_str(const char *plaintext, const char *key);
char *xor_decrypt_str(const char *hextext, const char *key);

#endif // XOR_H
