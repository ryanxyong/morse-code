/*
 * @file src/text-to-morse.c
 *
 * Represents a string as a series of periods and underscores like Morse code
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* ALPHA_TO_MORSE[] = {
    "._", "_...", "_._.", "_..", ".",
    ".._.", "__.", "....", "..", ".___",
    "_._", "._..", "__", "_.", "___",
    ".__.", "__._", "._.", "...", "_",
    ".._", "..._", ".__", "_.._", "_.__",
    "__.."
};

const char* NUM_TO_MORSE[] = {
    "_____", ".____", "..___", "...__", "...._",
    ".....", "_....", "__...", "___..", "____."
};

const char* mapCharToMorse(char c) {
    if (isalnum(c)) {
        if (isalpha(c)) {
            c = toupper(c);
            int ascii = (int)c;
            return ALPHA_TO_MORSE[ascii-65];
        } else {
            int ascii = (int)c;
            return NUM_TO_MORSE[ascii-48];
        }
    } else if (c == ' ') {
        return " ";
    } else {
        return "";
    }
}

int main() {
    printf("Welcome to the string to Morse code converter\n");
    printf("Input a string to Morsify: ");
    char input[256];
    fgets(input, 256, stdin);

    char morse[strlen(input)];
    for (int i = 0; i < strlen(input); i++) {
        const char* convert = mapCharToMorse(input[i]);
        strcat(morse, convert);
    }

    printf("Here is the Morse code: %s\n", morse);
    return 0;
}
