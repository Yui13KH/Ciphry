#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "atbash.h"
#include "caesar.h"
#include "help.h"
#include "interface.h"
#include "utils.h"
#include "vigenere.h"


int handle_command(int argc, char *argv[]) {
    if (argc == 1 || arg_is(argv[1], "--help") || arg_is(argv[1], "-h")) {
        print_general_help();
        return 0;
    }

    if (arg_is(argv[1], "--list") || arg_is(argv[1], "-l")) {
        list_ciphers();
        return 0;
    }

    if (arg_is(argv[1], "caesar")) {
        if (argc < 6) {
            printf("Error: Not enough arguments for Caesar cipher.\n");
            print_caesar_help();
            return 1;
        }

        const char *mode = argv[2];
        const char *text = argv[3];

        if (!arg_is(argv[4], "--key")) {
            printf("Error: Expected '--key' before the shift value.\n");
            print_caesar_help();
            return 1;
        }

        int key = atoi(argv[5]);

        if (arg_is(mode, "--encrypt")) {
            encrypt_caesar(text, key);
            return 0;
        } else if (arg_is(mode, "--decrypt")) {
            decrypt_caesar(text, key);
            return 0;
        } else {
            printf("Unknown mode: %s\n", mode);
            print_caesar_help();
            return 1;
        }
    }

    if (arg_is(argv[1], "atbash")) {
        if (argc < 4) {
            printf("Error: Not enough arguments for Atbash cipher.\n");
            print_atbash_help();
            return 1;
        }

        const char *mode = argv[2];
        const char *text = argv[3];

        if (arg_is(mode, "--encrypt") || arg_is(mode, "--decrypt")) {
            // Atbash encryption and decryption are identical
            atbash_cipher(text);
            return 0;
        } else {
            printf("Unknown mode: %s\n", mode);
            print_atbash_help();
            return 1;
        }
    }

    if (arg_is(argv[1], "vigenere")) {
        if (argc < 6) {
            printf("Error: Not enough arguments for Vigenère cipher.\n");
            print_vigenere_help();
            return 1;
        }

        const char *mode = argv[2];
        const char *text = argv[3];

        if (!arg_is(argv[4], "--key")) {
            printf("Error: Expected '--key' before the keyword.\n");
            print_vigenere_help();
            return 1;
        }

        const char *key = argv[5];

        if (arg_is(mode, "--encrypt")) {
            vigenere_cipher(text, key, 1);  // 1 = encrypt
            return 0;
        } else if (arg_is(mode, "--decrypt")) {
            vigenere_cipher(text, key, 0);  // 0 = decrypt
            return 0;
        } else {
            printf("Unknown mode: %s\n", mode);
            print_vigenere_help();
            return 1;
        }
    }

    printf("Unknown cipher: %s\n", argv[1]);
    print_general_help();
    return 1;
}