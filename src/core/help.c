#include <stdio.h>
#include "help.h"
#include "cipher_registry.h"

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

void print_atbash_help() {
    printf("Atbash Cipher Help:\n");
    printf("  --encrypt \"<text>\"    Encrypts the text using Atbash cipher\n");
    printf("  --decrypt \"<text>\"    Decrypts the text using Atbash cipher (same as encrypt)\n");
}

void print_vigenere_help() {
    printf("Vigenère Cipher Help:\n");
    printf("  --encrypt \"<text>\" --key <keyword>    Encrypts the text using the Vigenère cipher\n");
    printf("  --decrypt \"<text>\" --key <keyword>    Decrypts the text using the Vigenère cipher\n");
}

void print_rot13_help(){
    printf("Rot13 Cipher Help:\n");
    printf("  --encrypt \"<text>\"    Encrypts the text using the rot13 cipher\n");
    printf("  --decrypt \"<text>\"    Decrypts the text using the rot13 cipher\n");
}

void print_affine_help() {
    printf("Affine Cipher Help:\n");
    printf("  --encrypt \"<text>\" --a <a> --b <b>    Encrypts text with the Affine cipher\n");
    printf("  --decrypt \"<text>\" --a <a> --b <b>    Decrypts text with the Affine cipher\n");
}

void print_railfence_help(void) {
    printf("Rail Fence Cipher Help:\n");
    printf("  --encrypt \"<text>\" <rails>    Encrypt text with specified number of rails\n");
    printf("  --decrypt \"<text>\" <rails>    Decrypt text with specified number of rails\n");
}



void list_ciphers() {
    printf("Available ciphers:\n");
    int count = 0;
    const Cipher *ciphers = get_registered_ciphers(&count);
    printf("Supported ciphers (%d):\n", count);
    for (int i = 0; i < count; i++) {
        printf("  %s - %s\n", ciphers[i].name, ciphers[i].description);
    }
}

