#include <assert.h>

#include "cmd.h"
#include "lib/convert.h"
#include "lib/formats.h"

#define HUE 110

void write_output(Args args, FILE *fp, int (*writer)(FILE*, Color)) {
    double width = args.width;
    double height = args.height;

    printf(
        "Writing image:\n"
        "- width:  %d\n"
        "- height: %d\n",
        args.width, args.height
    );

    for (double y = 0; y < height; y++) {
        for (double x = 0; x < width; x++) {
            Color color = Color_hsv(HUE, x/width, 1-(y/height));
            writer(fp, color);
        }
    }

    printf("Wrote output to: %s\n", args.output);
}

int main(int argc, char *argv[]) {
    Args args = {0};
    FILE *fp = NULL;
    int (*writer)(FILE*, Color) = NULL;

    if (argc < 1) {
        return 1;
    }

    args = Args_from(argc, argv);

    fp = fopen(args.output, "w");
    if (fp == NULL) {
        perror("Failed opening output for writing");
        return 1;
    }

    switch (args.format) {
        case ImageFormat_PPM:
            if (ppm_write_header(fp, args.width, args.height) != 0) {
                perror("Failed writing PPM header");
                return 1;
            }
            writer = ppm_write_color;
            break;
        case ImageFormat_PAM:
            if (pam_write_header(fp, args.width, args.height) != 0) {
                perror("Failed writing PAM header");
                return 1;
            }
            writer = pam_write_color;
            break;
        default:
            fprintf(stderr,
                "Unexpected image format: %d\n",
                args.format
            );
            return 1;
    }

    assert(writer != NULL);

    write_output(args, fp, writer);
}
