#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "day_one.h"
#include "../util.h"

#define FLOOR_UP '('
#define FLOOR_DOWN ')'

int day_one(FILE_INFO * fi, bool part_one) {
    int floornum = 0;

    open_file_readonly(fi);
    for(int i = 0;i < fi->file_size;i++) {
        char current = fi->file_data[i];
        if (current == '\n') {
            printf("floornum: %d\n", floornum);
            floornum = 0;
        }
        else if(current == FLOOR_UP)
            floornum++;
        else if(current == FLOOR_DOWN)
            floornum--;
        
        if (!part_one && floornum == -1) {
            floornum = i + 1;
            break;
        }
    }

    return floornum;
}
