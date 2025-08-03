#ifndef CLI_UTILS_H
#define CLI_UTILS_H

int arg_is(const char *arg, const char *expected);
int has_flag(int argc, char *argv[], const char *flag);

#endif