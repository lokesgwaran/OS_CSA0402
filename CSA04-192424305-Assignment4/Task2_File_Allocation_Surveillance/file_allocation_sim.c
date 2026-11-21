#include <stdio.h>
#include <string.h>

#define BLOCKS 32

char disk[BLOCKS];

void init_disk(void) {
    memset(disk, '.', BLOCKS);
}

void print_disk(const char *label) {
    printf("%-24s: ", label);
    for (int i = 0; i < BLOCKS; i++) {
        putchar(disk[i]);
    }
    putchar('\n');
}

int alloc_contiguous(char file, int size) {
    if (size <= 0 || size > BLOCKS) return -1;
    for (int start = 0; start <= BLOCKS - size; start++) {
        int j;
        for (j = 0; j < size; j++) {
            if (disk[start + j] != '.') break;
        }
        if (j == size) {
            for (j = 0; j < size; j++) {
                disk[start + j] = file;
            }
            return start;
        }
        start += j;
    }
    return -1;
}

void free_file(char file) {
    for (int i = 0; i < BLOCKS; i++) {
        if (disk[i] == file) disk[i] = '.';
    }
}

int alloc_indexed(char file, int size, int *index_block, int data_blocks[]) {
    int free_list[BLOCKS], free_cnt = 0;
    for (int i = 0; i < BLOCKS; i++) {
        if (disk[i] == '.') free_list[free_cnt++] = i;
    }
    if (free_cnt < size + 1) return -1;

    *index_block = free_list[0];
    disk[*index_block] = 'I';
    for (int k = 0; k < size; k++) {
        data_blocks[k] = free_list[k + 1];
        disk[data_blocks[k]] = file;
    }
    return 0;
}

int main(void) {
    init_disk();
    alloc_contiguous('A', 6);
    alloc_contiguous('B', 8);
    alloc_contiguous('C', 5);
    alloc_contiguous('D', 8);
    print_disk("After A, B, C, D");

    free_file('B');
    free_file('D');
    print_disk("After freeing B and D");

    int c_start = alloc_contiguous('E', 10);
    if (c_start == -1) {
        printf("E (10 blocks) contiguous: FAILED (external fragmentation)\n");
    } else {
        printf("E (10 blocks) contiguous: start %d\n", c_start);
    }

    int idx_blk = -1, data_blks[10];
    if (alloc_indexed('E', 10, &idx_blk, data_blks) == 0) {
        printf("E (10 blocks) indexed   : index block %d, data blocks", idx_blk);
        for (int i = 0; i < 10; i++) printf(" %d", data_blks[i]);
        printf("\n");
        print_disk("After Indexed E");
    }
    return 0;
}
