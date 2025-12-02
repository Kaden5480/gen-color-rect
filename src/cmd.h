#ifndef CMD_H
#define CMD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "0.1.0"

typedef enum ImageFormat {
    ImageFormat_PPM,
    ImageFormat_PAM,
} ImageFormat;

typedef struct Args {
    int width;
    int height;
    int hue;
    ImageFormat format;
    char *output;
} Args;

void Args_show_usage(int argc, char *argv[]);

Args Args_from(int argc, char *argv[]);

#endif // CMD_H
