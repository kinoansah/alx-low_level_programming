#!/bin/bash

# Compile all .c files except _putchar.c into object files
gcc -c -Wall -Werror -fpic $(ls *.c | grep -v "_putchar.c")

# Compile dynamic.c separately
gcc -c -Wall -Werror -fpic dynamic.c

# Create the dynamic library liball.so
gcc -shared -o liball.so *.o

# List the symbols (functions) defined in the library
nm -D --defined-only liball.so
