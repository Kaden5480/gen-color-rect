#ifndef CONVERT_H
#define CONVERT_H

#include <stdio.h>
#include <math.h>

/**
 * A color containing r, g, b, and a
 * values (between 0-1).
 */
typedef struct Color {
    double r;
    double g;
    double b;
    double a;
} Color;

/**
 * Creates a color from rgba values.
 */
Color Color_rgba(double r, double g, double b, double a);

/**
 * Creates a color from rgb values.
 */
Color Color_rgb(double r, double g, double b);

/**
 * Creates a color from hsla values.
 */
Color Color_hsla(double h, double s, double l, double a);

/**
 * Creates a color from hsl values.
 */
Color Color_hsl(double h, double s, double l);

/**
 * Creates a color from hsva values.
 */
Color Color_hsva(double h, double s, double v, double a);

/**
 * Creates a color from hsv values.
 */
Color Color_hsv(double h, double s, double v);

/**
 * Displays a color.
 */
void Color_show(Color color);

#endif // CONVERT_H
