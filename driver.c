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
                exit(0);
            case 't':
                cli_args.t = true;
                cli_args.sec = atoi(optarg);
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
    
    int randomTime = 0;

    //if option -t is used
    if(args.t == true) { randomTime = rand() % (2 * args.sec); } 
       
    addmsg('I', "I love Soccer.");
    sleep(randomTime);
    addmsg('W', "Watch Out!");
    sleep(randomTime);
    addmsg('E', "This was a mistake.");
    sleep(randomTime);

    savelog("messages.log");

    getlog();

    clearlog();

    addmsg('I', "I love Soccer.");
    sleep(randomTime);
    addmsg('W', "Watch Out!");
    sleep(randomTime);
    addmsg('E', "This was a mistake.");
    sleep(randomTime);
    addmsg('F', "This is fatal.");

    
    return 0;
}
