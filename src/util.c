#include "util.h"

unsigned long long current_time;

unsigned long long get_current_time() {
    return current_time;
}

void increase_current_time() {
    INC_CNT(current_time);
}

FILE* open_file(char *file_path) {
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) 
        PRINT_ERROR("File open fail");
    return fp;
}

void close_file(FILE* fp) {
    if (fp) {
        fclose(fp);
        fp = NULL;
    }
}