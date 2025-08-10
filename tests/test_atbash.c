#include <criterion/criterion.h>
#include "atbash.h"

Test(atbash, basic_uppercase) {
    char output[100];
    atbash_cipher("HELLO", output);
    cr_assert_str_eq(output, "SVOOL");
}

Test(atbash, basic_lowercase) {
    char output[100];
    atbash_cipher("hello", output);
    cr_assert_str_eq(output, "svool");
}

Test(atbash, mixed_case) {
    char output[100];
    atbash_cipher("HelloWorld", output);
    cr_assert_str_eq(output, "SvoolDliow");
}

Test(atbash, non_alpha_characters) {
    char output[100];
    atbash_cipher("Hello, World! 123", output);
    cr_assert_str_eq(output, "Svool, Dliow! 123");
}

Test(atbash, empty_string) {
    char output[100];
    atbash_cipher("", output);
    cr_assert_str_eq(output, "");
}
