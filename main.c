#include "1/day_one.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {
        if (argc != 2) {
        printf("usage: day_one [filename]\n");
        exit(EXIT_FAILURE);
    }

    FILE_INFO *fi = calloc(1, sizeof(*fi));


    strcpy(fi->file_name, argv[1]);

    int d1_p1 = day_one(fi, true);
    printf("===== Day 1 Part 1 -- %d =====\n", d1_p1);


    int d1_p2 = day_one(fi, false);
    printf("===== Day 1 Part 2 -- %d =====\n", d1_p2);
    free(fi);
}