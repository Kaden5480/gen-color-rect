#include "formats.h"

int ppm_write_header(FILE *fp, int width, int height) {
    if (fprintf(fp,
        "P3\n"
        "%d %d\n"
        "255\n",
        width, height
    ) < 0) {
        return 1;
    }

    return 0;
}

int ppm_write_color(FILE *fp, Color color) {
    int r = 255.0 * color.r;
    int g = 255.0 * color.g;
    int b = 255.0 * color.b;

    if (fprintf(fp,
        "%d %d %d\n",
        r, g, b
    ) < 0) {
        return 1;
    }

    return 0;
}

int pam_write_header(FILE *fp, int width, int height) {
    if (fprintf(fp,
        "P7\n"
        "WIDTH %d\n"
        "HEIGHT %d\n"
        "DEPTH 4\n"
        "MAXVAL 255\n"
        "TUPLTYPE RGB_ALPHA\n"
        "ENDHDR\n",
        width, height
    ) < 0) {
        return 1;
    }

    return 0;
}

int pam_write_color(FILE *fp, Color color) {
    int r = 255.0 * color.r;
    int g = 255.0 * color.g;
    int b = 255.0 * color.b;
    int a = 255.0 * color.a;

    int value = r
        | g << 8
        | b << 16
        | a << 24;

    if (fprintf(fp, "%d\n", value) < 0) {
        return 1;
    }

    return 0;
}
