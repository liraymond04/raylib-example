# raylib CMake Project

This provides a base project template which builds with [CMake](https://cmake.org).

## Usage

To compile the example, use one of the following depending on your build target...

### Desktop

Use the following to build for desktop:

``` bash
# Use the -d flag to build for debugging
./build.sh
```

### Web

Compiling for the web requires the [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html):

``` bash
# Use the -d flag to build for debugging
./build.sh -t web
```
