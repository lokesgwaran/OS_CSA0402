/* lock_test.c */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>

static long long ns(struct timespec a, struct timespec b) {
    return (b.tv_sec - a.tv_sec) * 1000000000LL + (b.tv_nsec - a.tv_nsec);
}

int main(int argc, char **argv) {
    int lock = argc > 1 && strcmp(argv[1], "lock") == 0;
    size_t n = 8 * 1024 * 1024;
    volatile char *p = malloc(n);
    if (!p) { perror("malloc"); return 1; }
    size_t page = (size_t)sysconf(_SC_PAGESIZE);
    for (size_t i = 0; i < n; i += page) p[i] = 0; /* prefault */
    if (lock && mlock((const void *)p, n) != 0) {
        perror("mlock");
        free((void *)p);
        return 1;
    }
    struct timespec a, b;
    long long worst = 0;
    for (int k = 0; k < 100000; k++) {
        clock_gettime(CLOCK_MONOTONIC, &a);
        p[((size_t)k * 4096) % n]++;
        clock_gettime(CLOCK_MONOTONIC, &b);
        long long d = ns(a, b);
        if (d > worst) worst = d;
    }
    printf("mode=%s worst_observed_loop_access=%lld ns\n", lock ? "locked" : "unlocked", worst);
    if (lock) munlock((const void *)p, n);
    free((void *)p);
    return 0;
}
