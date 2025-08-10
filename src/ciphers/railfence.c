#include "railfence.h"
#include "help.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void railfence_cipher(const char *text, int rails, int encrypt, char *output) {
    if (rails < 2) {
        fprintf(stderr, "Number of rails must be at least 2.\n");
        output[0] = '\0';
        return;
    }

    int len = (int)strlen(text);
    char *result = malloc(len + 1);
    if (!result) {
        fprintf(stderr, "Memory allocation failed.\n");
        output[0] = '\0';
        return;
    }

    if (encrypt) {
        int idx = 0;
        for (int r = 0; r < rails; r++) {
            int step_down = 2 * (rails - r - 1);
            int step_up = 2 * r;
            int i = r;
            int down = 1;

            while (i < len) {
                result[idx++] = text[i];

                if (r == 0 || r == rails - 1)
                    i += (step_down + step_up);
                else {
                    if (down) {
                        i += step_down ? step_down : step_up;
                    } else {
                        i += step_up ? step_up : step_down;
                    }
                    down = !down;
                }
            }
        }
        result[idx] = '\0';
    } else {
        int *pos = calloc(len, sizeof(int));
        if (!pos) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(result);
            output[0] = '\0';
            return;
        }

        int row = 0, direction = 1;
        for (int i = 0; i < len; i++) {
            pos[i] = row;
            row += direction;
            if (row == 0 || row == rails - 1)
                direction = -direction;
        }

        int *row_counts = calloc(rails, sizeof(int));
        if (!row_counts) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(result);
            free(pos);
            output[0] = '\0';
            return;
        }

        for (int i = 0; i < len; i++)
            row_counts[pos[i]]++;

        int *row_starts = malloc(rails * sizeof(int));
        if (!row_starts) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(result);
            free(pos);
            free(row_counts);
            output[0] = '\0';
            return;
        }

        row_starts[0] = 0;
        for (int i = 1; i < rails; i++)
            row_starts[i] = row_starts[i - 1] + row_counts[i - 1];

        int *row_indices = calloc(rails, sizeof(int));
        if (!row_indices) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(result);
            free(pos);
            free(row_counts);
            free(row_starts);
            output[0] = '\0';
            return;
        }

        for (int i = 0; i < len; i++) {
            int r = pos[i];
            result[i] = text[row_starts[r] + row_indices[r]];
            row_indices[r]++;
        }
        result[len] = '\0';

        free(pos);
        free(row_counts);
        free(row_starts);
        free(row_indices);
    }

    // Copy result to output buffer
    strcpy(output, result);
    free(result);
}

void railfence_run(int argc, char *argv[]) {
    if (argc < 5) {
        print_railfence_help();
        return;
    }

    const char *mode = argv[2];
    const char *text = argv[3];
    int rails = atoi(argv[4]);

    if (rails < 2) {
        fprintf(stderr, "Rails must be >= 2\n");
        return;
    }

    char output[2048]; // enough buffer for typical use cases

    if (strcmp(mode, "--encrypt") == 0 || strcmp(mode, "encrypt") == 0) {
        railfence_cipher(text, rails, 1, output);
    } else if (strcmp(mode, "--decrypt") == 0 || strcmp(mode, "decrypt") == 0) {
        railfence_cipher(text, rails, 0, output);
    } else {
        fprintf(stderr, "Unknown mode '%s'. Use '--encrypt' or '--decrypt'.\n",
                mode);
        return;
    }

    printf("%s\n", output);
}
