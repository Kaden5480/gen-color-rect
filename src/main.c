#include <math.h>
#include <stdio.h>

#define WIDTH  200
#define HEIGHT 150
#define HUE    0
#define OUTPUT "output.ppm"

/**
 * See:
 * https://en.wikipedia.org/wiki/HSL_and_HSV#Color_conversion_formulae
 */
float hslf(float h, float s, float l, int n) {
    float a = s * fminf(l, 1.0-l);
    float k = fmodf((n + h/30.0), 12.0);

    float value = 255.0 * (l - a * fmaxf(-1.0,
        fminf(fminf(k-3.0, 9.0-k), 1.0)
    ));

    return value;
}

/**
 * Writes an HSL value as RGB to a file in PPM format.
 */
int write_hsl(FILE *fp, float h, float s, float l) {
    int r = hslf(h, s, l, 0);
    int g = hslf(h, s, l, 8);
    int b = hslf(h, s, l, 4);

    if (fprintf(fp, "%d %d %d\n", r, g, b) < 0) {
        perror("Failed writing RGB");
        return 1;
    }

    return 0;
}

/**
 * Writes the PPM header to a file pointer `fp`.
 */
void write_header(FILE *fp) {
    if (fprintf(fp,
        "P3\n"
        "%d %d\n"
        "255\n",
        WIDTH, HEIGHT
    ) < 0) {
        perror("Failed writing header");
    }
}

int main(void) {
    FILE *fp = fopen(OUTPUT, "w");
    if (fp == NULL) {
        fprintf(stderr, "Failed opening '%s'\n", OUTPUT);
        return 1;
    }

    write_header(fp);

    for (float y = 0; y < HEIGHT; y += 1) {
        for (float x = 0; x < WIDTH; x += 1) {
            write_hsl(fp, HUE, x/WIDTH, 1-(y/HEIGHT));
        }
    }

    fclose(fp);
}
