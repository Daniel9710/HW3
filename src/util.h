#ifndef UTIL_H_
#define UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* get_current_time
// : 현재 시간에 대해 얻을 수 있는 함수
// parameter: x
// return: 현재 시간
*/
unsigned int get_current_time();

void increase_current_time();

FILE* open_file(char *file_path);
void close_file(FILE* fp);

#endif