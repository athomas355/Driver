#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static data_t *head;
static data_t *tail;

void printList() {
    data_t *temp = head;
    
    while(temp != NULL) {
        printf("%s\t", temp->string);
    }
}


int addmsg(const char type, const char* msg) {

    if(type == 'I' || type == 'W' || type == 'E') {

        //create new data_t
        data_t *newMessage = malloc(sizeof(data_t));

        //getting current time
        time_t seconds;     
        seconds = time(NULL);   //current

        //defining data struct members
        newMessage->type = type;
        strcpy(newMessage->string, msg);
        newMessage->time = seconds;

        //reevaulating head and tail
        if(head == NULL) {
            head = newMessage;
            tail = newMessage;
        }
        else {
            tail->next = newMessage;
            tail = newMessage;
            tail->next = NULL;
        }

        return 0;
    } 
    else if(type == 'F') {
        printf("Fatal message type");
        return(-1);
    }
    else {
        printf("Invalid message type");
        return(-1);
    }

    return 0;
}

// void clearlog() {

// }

// char* getlog() {

// }

// int savelog(char* filename) {

//     return 0;
// }
