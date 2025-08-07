#include "cipher_registry.h"
#include "atbash.h"
#include "caesar.h"
#include "vigenere.h"
#include "help.h"
#include <string.h>

// Define the list of ciphers 
static Cipher cipher_list[] = {
    { "atbash",   atbash_run,   print_atbash_help, ""},
    { "caesar",   caesar_run,   print_caesar_help, ""},
    { "vigenere", vigenere_run, print_vigenere_help, ""},
    { "rot13" , rot13_run, print_rot13_help, ""}
    // add more ciphers easily here
};

    const Cipher* get_registered_ciphers(int *count) {
        if (count != NULL) {
            *count = sizeof(cipher_list) / sizeof(Cipher);
        }
        return cipher_list;
    }

const Cipher* find_cipher_by_name(const char *name) {
    int count;
    const Cipher *list = get_registered_ciphers(&count);
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].name, name) == 0) {
            return &list[i];
        }
    }
    return NULL;
}
