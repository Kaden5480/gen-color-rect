#include "convert.h"

/**
 * See:
 * https://en.wikipedia.org/wiki/HSL_and_HSV#Color_conversion_formulae
 */
double hslf(double h, double s, double l, int n) {
    double a = s * fminf(l, 1.0-l);
    double k = fmodf((n + h/30.0), 12.0);

    return (l - a * fmaxf(-1.0,
        fminf(fminf(k-3.0, 9.0-k), 1.0)
    ));
}

double hsvf(double h, double s, double v, int n) {
    double k = fmodf((n + h/60), 6);

    return (v - v * s * fmaxf(0,
        fminf(fminf(k, 4 - k), 1)
    ));
}

Color Color_rgba(double r, double g, double b, double a) {
    return (Color) {
        .r = r,
        .g = g,
        .b = b,
        .a = a,
    };
}

Color Color_rgb(double r, double g, double b) {
    return Color_rgba(r, g, b, 1.0);
}

Color Color_hsla(double h, double s, double l, double a) {
    return Color_rgba(
        hslf(h, s, l, 0),
        hslf(h, s, l, 8),
        hslf(h, s, l, 4),
        a
    );
}

Color Color_hsl(double h, double s, double l) {
    return Color_hsla(h, s, l, 1.0);
}

Color Color_hsva(double h, double s, double v, double a) {
    return Color_rgba(
        hsvf(h, s, v, 5),
        hsvf(h, s, v, 3),
        hsvf(h, s, v, 1),
        a
    );
}

Color Color_hsv(double h, double s, double v) {
    return Color_hsva(h, s, v, 1.0);
}

void Color_show(Color color) {
    printf(
        "(%f, %f, %f, %f)\n",
        color.r, color.g,
        color.b, color.a
    );
}
