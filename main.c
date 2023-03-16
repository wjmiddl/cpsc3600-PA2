#include "sighandler.h"
#include "Practical.h"
#include "UDPEchoClient.c"
#include "UDPEchoServer.c"

int main(int argc, char *argv[]) 
{
    //initialize signal receptor
    signal(SIGINT, sighandler);

    //declarations
    int opt;
    char * ptr;
    struct arg_struct args;
    args.pingPacketCount = 0x7fffffff;
    args.pingInterval = 1.0;
    args.portNumber = 33333;
    args.sizeInBytes = 12;
    args.noPrint = 0;
    args.server = 0;

    //loop to store all command arguments
    while((opt = getopt(argc, argv, "c:i:p:s:nS")) != -1) 
    {
        //values stored according to flag found
        switch(opt) 
        {
            case 'c':
                args.pingPacketCount = atoi(optarg);
                break;  
            case 'i': 
                args.pingInterval = strtod(optarg, &ptr);
                break;
            case 'p': 
                args.portNumber = atoi(optarg);
                break; 
            case 's': 
                args.sizeInBytes = atoi(optarg);
                break; 
            case 'n': 
                args.noPrint++;;
                break; 
            case 'S': 
                args.server++;
                break; 
        } 
    }

    //echo to stderr
    fprintf(stderr, "Count %*d\n", 14, args.pingPacketCount);
    fprintf(stderr, "Size %*d\n", 15, args.sizeInBytes);
    fprintf(stderr, "Interval       %0.3f\n", args.pingInterval);
    fprintf(stderr, "Port %*d\n", 15, args.portNumber);
    fprintf(stderr, "Server_ip %*s\n", 10, argv[argc - 1]);


    pthread_t server, client;

    pthread_create(&server, NULL, runserver, &args.portNumber);
    //loop to run threads
    while(1)
    {
        //stand in for threads
        printf("Put threads here\n");
        sleep(1);
    }
}