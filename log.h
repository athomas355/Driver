#ifndef LOG_H
#define LOG_H

#include <time.h>

//Robbins/Robbins Program 2-11; p. 55
typedef struct data_struct {
    time_t time;        //Time stamp
    char type;          //Message type(I/W/E/F)
    char* string;      //Message string
    struct data_t *next;

} data_t;

int addmsg(const char type, const char* msg);
void clearlog();
char* getlog();
int savelog(char* filename);

#endif
