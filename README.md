# gen-color-rect

A simple C program which generates a color rectangle of any
hue and size (configured through macros) and outputs it in a
[PPM](https://en.wikipedia.org/wiki/Netpbm#PPM_example)
format.

You can then convert the image to another format afterwards using a tool like
[ImageMagick](https://imagemagick.org/).

![Example](assets/example.png)

# Building
```sh
make build
```

# Running
```sh
./gen-color-rect
```
