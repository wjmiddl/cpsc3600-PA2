#include <stdio.h> 
#include <unistd.h> 
  
int main(int argc, char *argv[]) 
{
    int opt;
    char * flags;
    int pingPacketCount = 0x7fffffff
    double pingInterval = 1.0;
    int portNumber = 33333;
    int sizeInBytes = 12;
    int noPrint = 0;
    int server = 0;
    while((opt = getopt(argc, argv, “:if:lrx”)) != -1) 
    {
        switch(opt) 
        { 
            case ‘c’:

                break;  
            case ‘i’: 

                break;
            case ‘p’: 

                break; 
            case ‘s’: 
                
                break; 
            case ‘n’: 
                
                break; 
            case ‘S’: 
                
                break; 
        } 
    }

    return 0;
}