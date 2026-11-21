#include <stdio.h>
#include <stdlib.h>

#define N 8
#define MAXCYL 199

int cmp_asc(const void *a, const void *b) {
    return (*(const int *)a - *(const int *)b);
}

void run_fcfs(const int req[], int head) {
    int pos = head, total = 0;
    printf("FCFS  : %d", pos);
    for (int i = 0; i < N; i++) {
        total += abs(req[i] - pos);
        pos = req[i];
        printf(" -> %d", pos);
    }
    printf(" | Total Movement: %d cylinders\n", total);
}

void run_sstf(const int req[], int head) {
    int done[N] = {0}, pos = head, total = 0;
    printf("SSTF  : %d", pos);
    for (int k = 0; k < N; k++) {
        int best = -1, best_dist = MAXCYL + 1;
        for (int i = 0; i < N; i++) {
            if (!done[i]) {
                int d = abs(req[i] - pos);
                if (d < best_dist) {
                    best_dist = d;
                    best = i;
                }
            }
        }
        total += best_dist;
        pos = req[best];
        done[best] = 1;
        printf(" -> %d", pos);
    }
    printf(" | Total Movement: %d cylinders\n", total);
}

void run_scan_down(const int req[], int head) {
    int sorted[N];
    for (int i = 0; i < N; i++) sorted[i] = req[i];
    qsort(sorted, N, sizeof(int), cmp_asc);

    int pos = head, total = 0;
    printf("SCAN  : %d", pos);
    for (int i = N - 1; i >= 0; i--) {
        if (sorted[i] <= head) {
            total += abs(sorted[i] - pos);
            pos = sorted[i];
            printf(" -> %d", pos);
        }
    }
    total += abs(0 - pos);
    pos = 0;
    printf(" -> 0");
    for (int i = 0; i < N; i++) {
        if (sorted[i] > head) {
            total += abs(sorted[i] - pos);
            pos = sorted[i];
            printf(" -> %d", pos);
        }
    }
    printf(" | Total Movement: %d cylinders\n", total);
}

void run_look_down(const int req[], int head) {
    int sorted[N];
    for (int i = 0; i < N; i++) sorted[i] = req[i];
    qsort(sorted, N, sizeof(int), cmp_asc);

    int pos = head, total = 0;
    printf("LOOK  : %d", pos);
    for (int i = N - 1; i >= 0; i--) {
        if (sorted[i] <= head) {
            total += abs(sorted[i] - pos);
            pos = sorted[i];
            printf(" -> %d", pos);
        }
    }
    for (int i = 0; i < N; i++) {
        if (sorted[i] > head) {
            total += abs(sorted[i] - pos);
            pos = sorted[i];
            printf(" -> %d", pos);
        }
    }
    printf(" | Total Movement: %d cylinders\n", total);
}

int main(void) {
    int req[N] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    run_fcfs(req, head);
    run_sstf(req, head);
    run_scan_down(req, head);
    run_look_down(req, head);
    return 0;
}
