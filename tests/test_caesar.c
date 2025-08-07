#include <criterion/criterion.h>
#include "caesar.h"  // include the header to get the declarations

Test(caesar, encrypt_basic) {
    char output[100];
    encrypt_caesar_str("HELLO", 3, output);
    cr_assert_str_eq(output, "KHOOR");
}

Test(caesar, decrypt_basic) {
    char output[100];
    decrypt_caesar_str("KHOOR", 3, output);
    cr_assert_str_eq(output, "HELLO");
}
