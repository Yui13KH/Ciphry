#include <criterion/criterion.h>
#include "caesar.h"

// Encrypt tests
Test(caesar, encrypt_basic) {
    char output[100];
    encrypt_caesar_str("HELLO", 3, output);
    cr_assert_str_eq(output, "KHOOR");
}

Test(caesar, encrypt_wrap_around) {
    char output[100];
    encrypt_caesar_str("XYZ", 3, output);
    cr_assert_str_eq(output, "ABC");
}

Test(caesar, encrypt_zero_shift) {
    char output[100];
    encrypt_caesar_str("HELLO", 0, output);
    cr_assert_str_eq(output, "HELLO");
}

Test(caesar, encrypt_negative_shift) {
    char output[100];
    encrypt_caesar_str("DEF", -3, output);
    cr_assert_str_eq(output, "ABC");
}

Test(caesar, encrypt_mixed_case) {
    char output[100];
    encrypt_caesar_str("Hello, World!", 5, output);
    cr_assert_str_eq(output, "Mjqqt, Btwqi!");
}

Test(caesar, encrypt_non_alpha) {
    char output[100];
    encrypt_caesar_str("1234! @#", 4, output);
    cr_assert_str_eq(output, "1234! @#");
}

Test(caesar, encrypt_empty_string) {
    char output[100];
    encrypt_caesar_str("", 5, output);
    cr_assert_str_eq(output, "");
}

// Decrypt tests
Test(caesar, decrypt_basic) {
    char output[100];
    decrypt_caesar_str("KHOOR", 3, output);
    cr_assert_str_eq(output, "HELLO");
}

Test(caesar, decrypt_wrap_around) {
    char output[100];
    decrypt_caesar_str("ABC", 3, output);
    cr_assert_str_eq(output, "XYZ");
}

Test(caesar, decrypt_mixed_case) {
    char output[100];
    decrypt_caesar_str("Mjqqt, Btwqi!", 5, output);
    cr_assert_str_eq(output, "Hello, World!");
}
