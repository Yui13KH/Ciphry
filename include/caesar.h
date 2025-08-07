#ifndef CAESAR_H
#define CAESAR_H

void encrypt_caesar_str(const char *plaintext, int shift_key, char *output);
void decrypt_caesar_str(const char *ciphertext, int shift_key, char *output);

void encrypt_caesar(const char *plaintext, int shift_key);
void decrypt_caesar(const char *ciphertext, int shift_key);
void rot13_cipher(const char *text);

void caesar_run(int argc, char *argv[]);
void rot13_run(int argc, char *argv[]);

#endif