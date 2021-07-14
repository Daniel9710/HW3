#ifndef HOST_H_
#define HOST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "parser.h"
#include "util.h"

typedef struct Host{
    FILE* trace_file;
    Proc* next_process;
    unsigned int finish;
    unsigned int total_request_cnt;
    unsigned int request_cnt;
    unsigned int service_cnt;
    unsigned int turnaround_time;
    unsigned int progress_cnt;
} Host;

int init_host(Parser* parameters);
void terminate_host();

unsigned int is_simulation_on_going();
void print_progress_bar(unsigned int ratio);

/* create_if_next_process_available
// : host로부터 해당 time에 create된 process가 있는지 알 수 있음. 매 cycle이 시작될 때마다 호출됨
// parameter: x
// return: 해당 time에 create된 process가 있을 경우 생성된 process의 pointer
//         없을 경우 NULL
*/
Proc* create_if_next_process_available();

/* terminate_process
// : process를 terminate시키고 싶을 때 호출하는 함수.
// parameter: terminate시키고 싶은 process의 pointer
// return: x
*/
void terminate_process(Proc* candidate_process);


#endif