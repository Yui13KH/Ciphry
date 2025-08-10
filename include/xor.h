#ifndef XOR_H
#define XOR_H

void xor_cipher(const unsigned char *input, size_t input_len, const char *key, size_t key_len, unsigned char *output);
void xor_run(int argc, char **argv);

#endif 
