#include <stdio.h> 
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
  
int main(int argc, char *argv[]) 
{
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
}