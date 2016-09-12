#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <sched.h>

void *PrintHello(void *threadid);
int GetCPUCount();