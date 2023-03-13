#ifndef SIGHANDLER_H
#define SIGHANDLER_H

#include <stdio.h> 
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int signum)
{
    printf("Signal caught");
    exit(1);
}

#endif