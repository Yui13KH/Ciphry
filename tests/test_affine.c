#include <criterion/criterion.h>
#include "affine.h"

Test(affine, encrypt_basic) {
    char output[100];
    affine_cipher("HELLO", 5, 8, 1, output);
    cr_assert_str_eq(output, "RCLLA"); // example expected output
}

Test(affine, decrypt_basic) {
    char output[100];
    affine_cipher("RCLLA", 5, 8, 0, output);
    cr_assert_str_eq(output, "HELLO");
}
