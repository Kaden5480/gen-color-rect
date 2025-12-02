#ifndef FORMATS_H
#define FORMATS_H

#include <stdio.h>

#include "convert.h"

int ppm_write_header(FILE *fp, int width, int height);

int ppm_write_color(FILE *fp, Color color);

int pam_write_header(FILE *fp, int width, int height);

int pam_write_color(FILE *fp, Color color);

#endif // FORMATS_H
