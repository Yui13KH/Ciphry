#ifndef CLI_UTILS_H
#define CLI_UTILS_H

#include <stdbool.h>

int arg_is(const char *arg, const char *expected);
int has_flag(int argc, char *argv[], const char *flag);
int gcd(int x, int y);
bool is_coprime(int a, int b);
unsigned char hex_to_byte(char high, char low);

#endif