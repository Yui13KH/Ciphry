#include "utils.h"
#include <ctype.h>
#include <string.h>

int arg_is(const char *arg, const char *expected) {
    return strcmp(arg, expected) == 0;
}

int has_flag(int argc, char *argv[], const char *flag) {
    for (int i = 1; i < argc; i++) {
        if (arg_is(argv[i], flag)) {
            return 1;
        }
    }
    return 0;
}

// Euclidean algorithm for GCD https://en.wikipedia.org/wiki/Euclidean_algorithm
int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

bool is_coprime(int a, int b) {
    return gcd(a, b) == 1;
}

unsigned char hex_to_byte(char high, char low) {
    unsigned char h =
        (unsigned char)(isdigit(high) ? high - '0' : toupper(high) - 'A' + 10);
    unsigned char l =
        (unsigned char)(isdigit(low) ? low - '0' : toupper(low) - 'A' + 10);
    return (h << 4) | l;
}

unsigned char hex_char_to_val(char c) {
    if ('0' <= c && c <= '9')
        return c - '0';
    if ('a' <= c && c <= 'f')
        return 10 + c - 'a';
    if ('A' <= c && c <= 'F')
        return 10 + c - 'A';
    return 0;
}