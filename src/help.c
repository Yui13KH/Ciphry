#include <stdio.h>
#include "help.h"

void print_general_help() {
    printf("Ciphry - Command-line cryptography toolkit\n\n");
    printf("General Usage:\n");
    printf("  ciphry <cipher> <mode> \"<text>\" --key \"<key>\"\n\n");
    printf("Where:\n");
    printf("  <cipher>    The cipher to use\n");
    printf("  <mode>      Operation mode: --encrypt or --decrypt\n");
    printf("  <text>      The text to process\n");
    printf("  --key       The key or parameter for the cipher\n\n");
    printf("Additional commands:\n");
    printf("  ciphry -l | --list    List all available ciphers\n");
    printf("  ciphry <cipher> -h | --help     Show help for a specific cipher\n");
}

void print_caesar_help() {
    printf("Caesar Cipher Help:\n");
    printf("  --encrypt \"<text>\" --key <shift>    Encrypts the text using Caesar cipher\n");
    printf("  --decrypt \"<text>\" --key <shift>    Decrypts the text using Caesar cipher\n");
}

void list_ciphers() {
    printf("Available ciphers:\n");
    printf("  caesar    - Simple substitution cipher shifting letters by a fixed number.\n");
}
