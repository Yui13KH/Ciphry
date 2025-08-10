#include <criterion/criterion.h>
#include "xor.h"

Test(xor, encrypt_decrypt_cycle) {
    const char *plaintext = "Hello XOR Cipher!";
    const char *key = "secret";

    char *encrypted = xor_encrypt_str(plaintext, key);
    cr_assert_not_null(encrypted);

    char *decrypted = xor_decrypt_str(encrypted, key);
    cr_assert_not_null(decrypted);

    cr_assert_str_eq(decrypted, plaintext);

    free(encrypted);
    free(decrypted);
}
