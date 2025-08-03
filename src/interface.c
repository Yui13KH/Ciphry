#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "interface.h"

#include "help.h"

#include "caesar.h"

int handle_command(int argc, char * argv[]) {
    if (argc == 1 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        print_general_help();
        return 0;
    }

    if (strcmp(argv[1], "--list") == 0 || strcmp(argv[1], "-l") == 0) {
        list_ciphers();
        return 0;
    }

    if (strcmp(argv[1], "caesar") == 0) {
        if (argc < 6) {
            printf("Error: Not enough arguments for Caesar cipher.\n");
            print_caesar_help();
            return 1;
        }

        const char * mode = argv[2];
        const char * text = argv[3];

        if (strcmp(argv[4], "--key") != 0) {
            printf("Error: Expected '--key' before the shift value.\n");
            print_caesar_help();
            return 1;
        }

        int key = atoi(argv[5]);

        if (strcmp(mode, "--encrypt") == 0) {
            encrypt_caesar(text, key);
            return 0;
        } else if (strcmp(mode, "--decrypt") == 0) {
            decrypt_caesar(text, key);
            return 0;
        } else {
            printf("Unknown mode: %s\n", mode);
            print_caesar_help();
            return 1;
        }
    }

    printf("Unknown cipher: %s\n", argv[1]);
    print_general_help();
    return 1;
}