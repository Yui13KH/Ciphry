#include <criterion/criterion.h>
#include "railfence.h"

Test(railfence, encrypt_basic) {
    char output[256];
    railfence_cipher("hello world", 3, 1, output);
    cr_assert_str_eq(output, "horel ollwd");
}

Test(railfence, decrypt_basic) {
    char output[256];
    railfence_cipher("horel ollwd", 3, 0, output);
    cr_assert_str_eq(output, "hello world");
}
