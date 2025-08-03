#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "utils.h"

#include "interface.h"

#include "help.h"

#include "caesar.h"

int handle_command(int argc, char * argv[]) {
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

        const char * mode = argv[2];
        const char * text = argv[3];

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

    

    printf("Unknown cipher: %s\n", argv[1]);
    print_general_help();
    return 1;
}