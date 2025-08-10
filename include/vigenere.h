#ifndef VIGENERE_H
#define VIGENERE_H

void vigenere_cipher(const char *text, const char *key, int encrypt,
                     char *output);
void vigenere_run(int argc, char *argv[]);

#endif
