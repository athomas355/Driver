Logging Utility

What it does:
    This is a linux utility that adds messages to a linked list logger, and it has functions that alter the list and does things with it was well. It can add more messages to linked list logger. It can clear the logger. Finally it can save the log to another file.

How to use it:
    /.driver [OPTIONS] [logfile]

    *Since I don't have a working makefile here are steps to make it run
        1. gcc -c log.c
            -there will be many warnings that pops up with this command. However the file still compiles.
        2. gcc log.o driver.c -o driver
        3. ./driver (default run)
            - ./driver -h
            - ./driver -t sec (sec being whatever number you wish to use)

OPTIONS:
    -h      Help message 
    -t      messages are printed every [sec] seconds.
        sec: command line argument that determines how many seconds.

Problems:
    -The getlog() function starts the string with random symbols. It originally didn't, but now they won't go away.
    -I don't have a working makefile
    -I hardcoded all the messages to test the functions. I am not sure if you wanted the messages to be user input




