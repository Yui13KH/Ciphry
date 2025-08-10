#include <criterion/criterion.h>
#include "vigenere.h"

Test(vigenere, encrypt_basic) {
    char output[256];
    vigenere_cipher("ATTACKATDAWN", "LEMON", 1, output);
    cr_assert_str_eq(output, "LXFOPVEFRNHR");
}

Test(vigenere, decrypt_basic) {
    char output[256];
    vigenere_cipher("LXFOPVEFRNHR", "LEMON", 0, output);
    cr_assert_str_eq(output, "ATTACKATDAWN");
}