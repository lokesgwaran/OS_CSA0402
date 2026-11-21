/* page_touch.c: allocate and touch memory in sequential/random order.
   Compile: gcc -O0 -Wall -Wextra page_touch.c -o page_touch */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv) {
    size_t mb = argc > 1 ? (size_t)strtoul(argv[1], 0, 10) : 64;
    size_t bytes = mb * 1024 * 1024, page = (size_t)sysconf(_SC_PAGESIZE);
    volatile unsigned char *p = malloc(bytes);
    if (!p) { perror("malloc"); return 1; }
    for (size_t i = 0; i < bytes; i += page) p[i] = 1; /* sequential */
    srand(7);
    for (size_t i = 0; i < bytes / page; i++) {
        size_t k = (size_t)rand() % (bytes / page);
        p[k * page]++; /* random page touches */
    }
    printf("Touched %zu MB; page size %zu bytes\n", mb, page);
    free((void *)p);
    return 0;
}
