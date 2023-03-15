#include "sighandler.h"
#include "UDPEchoClient.c"
#include "UDPEchoServer.c"
#include <thread.h>

int main(int argc, char *argv[]) 
{
    //initialize signal receptor
    signal(SIGINT, sighandler);

    //declarations
    int opt;
    char * ptr;
    int pingPacketCount = 0x7fffffff;
    double pingInterval = 1.0;
    int portNumber = 33333;
    int sizeInBytes = 12;
    int noPrint = 0;
    int server = 0;

    //loop to store all command arguments
    while((opt = getopt(argc, argv, ":if:lrx")) != -1) 
    {
        //values stored according to flag found
        switch(opt) 
        {
            case 'c':
                pingPacketCount = atoi(optarg);
                break;  
            case 'i': 
                pingInterval = strtod(optarg, &ptr);
                break;
            case 'p': 
                portNumber = atoi(optarg);
                break; 
            case 's': 
                sizeInBytes = atoi(optarg);
                break; 
            case 'n': 
                noPrint++;
                break; 
            case 'S': 
                server++;
                break; 
        } 
    }
    pthread_t client, server;
    extern struct a    



}