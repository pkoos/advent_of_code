#ifndef UTIL_H_
#define UTIL_H_

#define MAX_FILENAME_LEN 64
#define MAX_BUFFER_LEN 1024 * 1024 * 10

typedef struct FILE_INFO {
    int file_size;
    char file_name[MAX_FILENAME_LEN];
    char file_data[MAX_BUFFER_LEN];
} FILE_INFO;

void open_file_readonly(FILE_INFO * fi);

#endif