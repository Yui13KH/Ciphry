#ifndef CIPHER_REGISTRY_H
#define CIPHER_REGISTRY_H

// Function pointer types
typedef void (*cipher_func_t)(int argc, char *argv[]);
typedef void (*help_func_t)(void);

// The struct each cipher will register
typedef struct {
    const char *name;             // "vigenere", "caesar", etc.
    cipher_func_t run;           // function to call when running
    help_func_t show_help;       // function to print help
} Cipher;

// Function to get the list of all registered ciphers
const Cipher* get_registered_ciphers(int *count);

const Cipher* find_cipher_by_name(const char *name);

#endif // CIPHER_REGISTRY_H
