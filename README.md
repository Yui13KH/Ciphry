# Ciphry

Ciphry is a command-line cryptography toolkit implementing classic and modern ciphers.  
It allows you to encrypt and decrypt text using a variety of algorithms via simple CLI commands.

---

## Features

- Modular design supporting multiple ciphers  
- Command-line interface with help and listing commands  
- Currently supports: Caesar cipher (more coming soon!)  

---

## Build Instructions

Make sure you have GCC installed and a Unix-like environment (Linux, WSL, MSYS2, etc.).

1. Clone this repo:
   ```bash
   git clone https://github.com/Yui13KH/Ciphry
   cd ciphry
   make 
   ./ciphry --help
   ```

## Usage 
```
ciphry <cipher> <mode> <text> --key <key>
```
cipher: Name of the cipher (e.g., caesar)

mode: Operation mode (--encrypt or --decrypt)

text: Text to encrypt or decrypt (wrap in quotes if it contains spaces)

--key: Key or parameter for the cipher

## Example 
```
ciphry caesar --encrypt "HELLO" --key 3
```