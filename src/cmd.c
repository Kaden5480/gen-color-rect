#include "cmd.h"

void Args_show_usage(int argc, char **argv) {
    (void) argc;

    printf(
        "%s, v%s\n"
        "Usage:\n"
        "  %s [option...] <output>\n"
        "Options:\n"
        "  -h --help        Display the usage\n"
        "  -p --ppm         Use PPM for the output (default)\n"
        "  -P --pam         Use PAM for the output\n"
        "  -w --width <n>   The width of the generated image (default: 128)\n"
        "  -H --height <n>  The height of the generated image (default: 128)\n"
        "  --hue <n>        The hue to use (0-360, default: 0)\n",
        argv[0], VERSION, argv[0]
    );
}

Args Args_from(int argc, char **argv) {
    Args args = {
        .width = 128,
        .height = 128,
        .hue = 0,
        .format = ImageFormat_PPM,
        .output = NULL
    };

    char *arg = NULL;

    for (int i = 1; i < argc; i++) {
        arg = argv[i];

        if (strcmp("-h", arg) == 0
            || strcmp("--help", arg) == 0
        ) {
            Args_show_usage(argc, argv);
            exit(0);
        }
        else if (strcmp("-p", arg) == 0
            || strcmp("--ppm", arg) == 0
        ) {
            args.format = ImageFormat_PPM;
        }
        else if (strcmp("-P", arg) == 0
            || strcmp("--pam", arg) == 0
        ) {
            args.format = ImageFormat_PAM;
        }
        else if (strcmp("-w", arg) == 0
            || strcmp("--width", arg) == 0
        ) {
            if (i + 1 >= argc) {
                Args_show_usage(argc, argv);
                exit(1);
            }

            i++;
            args.width = atoi(argv[i]);
        }
        else if (strcmp("-H", arg) == 0
            || strcmp("--height", arg) == 0
        ) {
            if (i + 1 >= argc) {
                Args_show_usage(argc, argv);
                exit(1);
            }

            i++;
            args.height = atoi(argv[i]);
        }
        else if (strcmp("--hue", arg) == 0) {
            if (i + 1 >= argc) {
                Args_show_usage(argc, argv);
                exit(1);
            }

            i++;
            args.hue = atoi(argv[i]);
        }
        else if (args.output == NULL) {
            args.output = arg;
        }
        else {
            fprintf(stderr, "Unexpected argument: %s\n", arg);
            Args_show_usage(argc, argv);
            exit(1);
        }
    }

    if (args.output == NULL) {
        fprintf(stderr, "Missing required argument: output\n");
        Args_show_usage(argc, argv);
        exit(1);
    }

    return args;
}
