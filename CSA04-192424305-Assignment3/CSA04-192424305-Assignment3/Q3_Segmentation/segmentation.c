#include <stdio.h>

typedef struct {
    int base, limit;
} Segment;

int main(void) {
    Segment st[] = {{1000, 400}, {3000, 600}, {5000, 200}};
    int tests[][2] = {
        {0, 20}, {1, 599}, {2, 200}, {1, 120},
        {0, 399}, {0, 400}, {2, 0}, {3, 10}
    };
    int n = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < n; i++) {
        int s = tests[i][0], off = tests[i][1];
        if (s < 0 || s >= 3 || off < 0 || off >= st[s].limit)
            printf("(%d,%d) -> segmentation fault/protection fault\n", s, off);
        else
            printf("(%d,%d) -> physical %d\n", s, off, st[s].base + off);
    }
    return 0;
}
