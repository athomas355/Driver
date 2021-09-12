#include <iostream>
#include <unistd.h>
using namespace std;

struct cli_struct{
    bool t;
    int sec;
    char* logfile;
};

cli_struct parse_args(int argc, char* argv[]) {
    cli_struct cli_args;
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
    cli_struct args = parse_args(argc, argv);

    printf("-t = %d, sec = %d, logfile = %s\n",args.t, args.sec, args.logfile);

    return 0;
}
