/*
 * @file src/freq-iq-generator.c
 *
 * Creates an I/Q file given a specific frequency via simple sine wave
 */

#include <stdio.h>
#include <math.h>

// I/Q sample in-phase and quadrature components
typedef struct IQ {
    double real;
    double imag;
} IQ;

IQ getIQ(double f, double t) {
    double real = sin(f * t);
    double imag = cos(f * t);
    IQ iq = { .real = real, .imag = imag };
    return iq;
}

int main() {
    FILE *fptr;
    fptr = fopen("freq.iq", "w");
    int samples = 88000;
    double fs = 44000.0;
    double f = 10000.0;
    for (int i = 0; i < samples; i++) {
        double t = i / fs;
        printf("%.6f\n", t);
        IQ res = getIQ(f, t);
        fprintf(fptr, "%.6f,%.6f\n", res.real, res.imag);
    }

    fclose(fptr);

    return 0;
}
