#include <string.h>
#include "utils.h"

int arg_is(const char *arg, const char *expected){
    return strcmp(arg, expected) == 0;
}

int has_flag(int argc, char *argv[], const char *flag) {
    for(int i = 1; i < argc; i++){
        if(arg_is(argv[i], flag)) {
            return 1;
        }
    }
    return 0;
}