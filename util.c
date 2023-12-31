#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "util.h"

void open_file_readonly(FILE_INFO * fi) {
    
    assert(fi->file_name != NULL || fi->file_data != NULL);
    FILE *file;
    
    file = fopen(fi->file_name, "r");
    if (file == NULL) {
        perror("error opening file: ");
        exit(EXIT_FAILURE);
    }


    fseek(file, 0, SEEK_END);
        long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    long buffersize = strlen(fi->file_data);

    assert(filesize < MAX_BUFFER_LEN && buffersize < MAX_BUFFER_LEN);

    fi->file_size = filesize;
    int readcode = fread(fi->file_data, 1, fi->file_size, file);

    if (readcode == 0) {
        perror("error reading file");
        exit(EXIT_FAILURE);
    }
    
    assert(filesize == readcode);

    fclose(file);
}