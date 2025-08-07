#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "vigenere.h"
#include "help.h"

void normalize_key(char *key) {
    int i = 0, j = 0;
    while (key[i]) {
        if (isalpha(key[i])) {
            key[j++] = tolower(key[i]);
        }
        i++;
    }
    key[j] = '\0';
}

void vigenere_cipher(const char *text, const char *key, int encrypt) {
    char normalized_key[256];
    strncpy(normalized_key, key, sizeof(normalized_key) - 1);
    normalized_key[sizeof(normalized_key) - 1] = '\0';
    normalize_key(normalized_key);

    int text_len = strlen(text);
    int key_len = strlen(normalized_key);
    int key_index = 0;

    for (int i = 0; i < text_len; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char key_char = normalized_key[key_index % key_len];
            int shift = key_char - 'a';

            if (!encrypt) {  // decrypt mode
                shift = -shift;
            }

            ch = (ch - base + shift + 26) % 26 + base;
            key_index++;
        }
        putchar(ch);
    }
    putchar('\n');
}

void vigenere_run(int argc, char *argv[]) {
    if (argc < 5) {
        print_vigenere_help();
        return;
    }

    const char *mode = argv[2];
    const char *text = argv[3];
    const char *key = argv[4];

    int encrypt;
    if (strcmp(mode, "--encrypt") == 0 || strcmp(mode, "encrypt") == 0){
        encrypt = 1;
    } else if (strcmp(mode, "--decrypt") == 0 || strcmp(mode, "decrypt") == 0){
        encrypt = 0;
    } else {
        fprintf(stderr, "Unknown mode '%s'. Use '--encrypt' or '--decrypt'.\n", mode);
        return;
    }

    vigenere_cipher(text, key, encrypt);
}