# gen-color-rect

A simple C program which generates a color rectangle of any
hue and size (configured through macros) and outputs it in a
[PPM](https://en.wikipedia.org/wiki/Netpbm#PPM_example)
format.

You can then convert the image to another format afterwards using a tool like
[ImageMagick](https://imagemagick.org/).

<p align="center">
    <img src="assets/1.png" style="width: 25%">
    <img src="assets/2.png" style="width: 25%">
    <img src="assets/3.png" style="width: 25%">
</p>

# Building
```sh
make build
```

# Running
```sh
./gen-color-rect
```
