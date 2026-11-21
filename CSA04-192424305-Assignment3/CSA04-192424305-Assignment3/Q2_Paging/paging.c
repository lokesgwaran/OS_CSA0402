#include <stdio.h>

#define PAGE_SIZE 1024
#define PAGES 8

int page_table[PAGES] = {5, 2, -1, 7, 0, -1, 3, -1};

int main(void) {
    unsigned logical[] = {0, 1500, 3100, 6200, 9000, 2049};
    printf("=== Address Translation (PAGE_SIZE = 1024) ===\n");
    for (int i = 0; i < 6; i++) {
        unsigned a = logical[i];
        unsigned p = a / PAGE_SIZE, d = a % PAGE_SIZE;
        printf("%u -> page %u offset %u: ", a, p, d);
        if (p >= PAGES) puts("invalid address");
        else if (page_table[p] == -1) puts("page fault");
        else printf("physical %u\n", (unsigned)page_table[p] * PAGE_SIZE + d);
    }

    printf("\n=== Address Translation (PAGE_SIZE = 2048) ===\n");
    unsigned ps2 = 2048;
    for (int i = 0; i < 6; i++) {
        unsigned a = logical[i];
        unsigned p = a / ps2, d = a % ps2;
        printf("%u -> page %u offset %u: ", a, p, d);
        if (p >= PAGES) puts("invalid address");
        else if (page_table[p] == -1) puts("page fault");
        else printf("physical %u\n", (unsigned)page_table[p] * ps2 + d);
    }
    return 0;
}
