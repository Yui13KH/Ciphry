#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "atbash.h"
#include "caesar.h"
#include "help.h"
#include "interface.h"
#include "utils.h"
#include "vigenere.h"


int handle_command(int argc, char * argv[]) {
    #include "cipher_registry.h"

    if (argc < 2) {
        print_general_help();
        return 1;
    }

     const char *cmd = argv[1];

    if (strcmp(cmd, "-h") == 0 || strcmp(cmd, "--help") == 0) {
        print_general_help();
        return 0;
    }

    if (strcmp(cmd, "-l") == 0 || strcmp(cmd, "--list") == 0) {
        list_ciphers();
        return 0;
    }

    const Cipher *cipher = find_cipher_by_name(cmd);
    if (cipher) {
        cipher->run(argc, argv);
        return 0;
    } else {
        printf("Unknown command or cipher: %s\n", cmd);
        printf("Try --help for usage.\n");
        return 1;
    }
}   