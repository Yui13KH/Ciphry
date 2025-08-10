# Ciphry  
#### Video Demo:  <[Ciphry](https://www.youtube.com/watch?v=je6q_kdR9to)>  
#### Description:  

**Ciphry** is a modular command-line cryptography toolkit supporting classic and modern ciphers.  
It enables encryption and decryption of text via a clean CLI interface, designed for extensibility and learning.

---

## Motivation

Cryptography is a fascinating field blending math and programming.  
I built Ciphry to deepen my understanding of classic ciphers and gain experience designing modular, extensible C programs.  
By implementing several cipher algorithms, I learned how to handle string manipulation, modular code architecture, and CLI design.  
This project also sharpened my skills in testing with Criterion and working with build systems like Make.

---

## Features

- Modular architecture with a **cipher registry** for easy addition of new ciphers  
- Command-line interface supporting detailed help, cipher listing, and versatile usage  
- Currently includes:  
  - Caesar cipher (with encryption and decryption)  
  - ROT13 cipher  
  - Atbash cipher  
  - Vigenère cipher  
  - Affine cipher  
  - Railfence cipher  
  - XOR cipher  

---

## Build Instructions

Ensure you have `gcc` installed and are using a Unix-like environment (Linux, WSL, MSYS2, macOS).

1. Clone the repository:  
```bash
   git clone https://github.com/Yui13KH/Ciphry.git
   cd Ciphry
````

2. Build the project:

   ```bash
   make
   ```

3. This will produce two executables inside the `bin/` directory:

   * `ciphry` — the main program
   * `test_ciphry` — the test suite

---

## Usage

Change into the `bin` directory, then run the main program to encrypt or decrypt text:

```bash
cd bin
./ciphry <cipher> <mode> <text> [--key <key>]
```

* `<cipher>` — Name of the cipher to use (e.g., `caesar`)
* `<mode>` — Operation mode (`--encrypt` or `--decrypt`)
* `<text>` — The input text (wrap in quotes if containing spaces)
* `<key>` — Optional key or parameter required by some ciphers

Example usage:

```bash
./ciphry caesar --encrypt "HELLO WORLD" 3
```

Additional commands:

* `./ciphry --help` — Show general usage information
* `./ciphry --list` — List all available ciphers
* `./ciphry <cipher> --help` — Show help for a specific cipher

---

## Testing

Unit tests are implemented with the [Criterion](https://criterion.readthedocs.io/en/master/) framework, which provides automated testing with detailed reporting.

### Prerequisites for Testing

To run the unit tests, you need to have the Criterion testing framework installed.

* **On Debian/Ubuntu:**

  ```bash
  sudo apt install libcriterion-dev
  ```

* **On Arch Linux (Manjaro):**

  ```bash
  sudo pacman -S criterion
  ```

* **On Windows:**
  *Preferred method:* Use **Windows Subsystem for Linux (WSL)** with a Linux distro (e.g., Ubuntu), then install Criterion as on Debian/Ubuntu.
  This is by far the easiest and most reliable way to run the tests on Windows.

  *If WSL is unavailable:* You will need to build Criterion from source inside an MSYS2 MinGW64 shell. This requires installing dependencies like CMake, Ninja, and a build toolchain, then cloning and building Criterion manually. See [Criterion GitHub](https://github.com/Snaipe/Criterion) for detailed instructions.

### Running Tests

After installing Criterion, run all tests by changing into the `bin` directory and executing:

```bash
cd bin
./test_ciphry
```

The tests cover individual ciphers and utility functions to ensure correctness and robustness.

---

## Project Structure & Design

* `src/` — Source code
* `src/ciphers/` — Individual cipher implementations (e.g., Caesar, ROT13)
* `src/core/` — Core modules (main, interface, cipher registry, utils, help)
* `include/` — Header files
* `tests/` — Unit tests for each cipher and module
* `bin/` — Output folder for compiled executables

---

## Design Decisions

I chose a command-line interface to keep the project focused on core cryptography concepts without UI distractions.
The cipher registry pattern was implemented to allow easy addition of new ciphers without modifying core logic.
Using Criterion for testing enables automated verification of correctness and makes maintaining the codebase easier.
I opted for Makefiles to manage builds due to their simplicity and wide support across platforms.

---

## Extending Ciphry

Ciphry uses a **cipher registry** pattern, allowing new ciphers to be added modularly without changing main logic:

* Each cipher implements a standard interface: a `run` function, and optionally a `help` function.
* Ciphers are registered in a centralized registry file and discovered at runtime by name.

This design keeps the codebase clean and scalable, perfect for adding new classic or modern algorithms.

---

Thank you for reviewing my project!
