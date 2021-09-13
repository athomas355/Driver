#include "log.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct cli_struct{
    bool t;
    int sec;
    char* logfile;
};

struct cli_struct parse_args(int argc, char* argv[]) {
    struct cli_struct cli_args;
    int option;
    cli_args.t = false;
    cli_args.sec = 0;

    while((option = getopt(argc, argv, "ht:")) != -1) {

        switch(option) {
            case 'h':
                printf("driver [-h] [-t sec] [logfile]\n\t-h: help (usage) message\n\t-t: messages are printed at specfic intervals");
                break;
            case 't':
                cli_args.t = true;
                cli_args.sec = atoi(optarg);
                printf("Hello, I am option t");
                break;
            case '?':
                printf("Unknown option: %s\n", optarg);
                exit(1);
        }
    }

    for(; optind < argc; optind++) {
        cli_args.logfile = argv[optind];
    }  

    return cli_args;  
}

int main(int argc, char* argv[]) {
    
    //parse arguments
    struct cli_struct args = parse_args(argc, argv);

    //cli_args test
    //printf("-t = %d, sec = %d, logfile = %s\n",args.t, args.sec, args.logfile);
    
    
    // time_t seconds;
    // struct tm *timeStruct;

    // seconds = time(NULL);

    // timeStruct = localtime(&seconds);

    // printf("Current time : %d:%d:%d\n", timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec);

    addmsg('I', "I love Soccer.");
    // addmsg('W', "Watch Out!");
    // addmsg('E', "This was a mistake.");
    // addmsg('F', "This is fatal.");



    
    return 0;
}
