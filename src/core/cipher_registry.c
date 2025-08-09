#include "cipher_registry.h"
#include "atbash.h"
#include "caesar.h"
#include "vigenere.h"
#include "affine.h"
#include "help.h"
#include <string.h>

// Define the list of ciphers 
static Cipher cipher_list[] = {
    {"atbash", atbash_run, print_atbash_help,
     "Substitution cipher: reverses the alphabet (A ↔ Z, B ↔ Y, ...)"},
    {"caesar", caesar_run, print_caesar_help,
     "Shift cipher: shifts letters by a fixed key (e.g., A → D)"},
    {"vigenere", vigenere_run, print_vigenere_help,
     "Polyalphabetic cipher: uses a keyword to shift letters"},
    {"rot13", rot13_run, print_rot13_help,
     "Special Caesar cipher with fixed shift of 13 (A ↔ N)"},
    {"affine", affine_run, print_affine_help, "Affine cipher with keys a (coprime) and b for linear transformation"}


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
