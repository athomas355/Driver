#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static data_t *head;
static data_t *tail;
static int numOfStructs = 0;

void printList() {
    data_t *temp = head;
    printf("[ ");
    while(temp != NULL) {
        printf("%s, ", temp->string);
        temp = temp->next;
    }
    printf("]");
    printf("\n");
}


int addmsg(const char type, const char* msg) {

    int messageSize = 0;
    if(type == 'I' || type == 'W' || type == 'E' || type == 'F') {

        //create new data_t
        data_t *newMessage = malloc(sizeof(data_t));
        numOfStructs++;

        messageSize = strlen(msg);
        newMessage->string = malloc(messageSize);
        
        //getting current time
        //https://www.codevscolor.com/c-print-current-hour-minute-second
        time_t now;     
        now = time(NULL);   //current
        
        //defining data struct members
        newMessage->type = type;
        strcpy(newMessage->string, msg);
        newMessage->time = now;
        newMessage->next = NULL;
        
        //reevaulating head and tail
        if(head == NULL) {
            head = newMessage;
            tail = newMessage;
        }
        else { 
            tail->next = newMessage;
            tail = newMessage;
        }

        if(type == 'F') {
            savelog("messages.log");
            printf("Fatal message type\n");
            return(-1);
        }
        //printList();
        return 0;
    } 
    // else if(type == 'F') {
    //     printf("Fatal message type\n");
    //     return(-1);
    // }
    else {
        printf("Invalid message type\n");
        return(-1);
    }
    
}

//https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
void clearlog() {
    data_t *current = head;
    data_t *temp;

    while(current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }

    head = NULL;
}

//https://www.tutorialspoint.com/c_standard_library/c_function_realloc.htm
char* getlog() {

    data_t *current = head;
    int totalSize = 0;
    int currentSize;
    int runningTotal;
    char *string = "";

    string = malloc(numOfStructs * sizeof(char *));

    while(current != NULL) {
        currentSize = strlen(current->string);
        runningTotal = runningTotal + currentSize;
        string = (char *) realloc(string, runningTotal);
        strcat(string, current->string);  
        strcat(string, " ");
        current = current->next;
    }

    printf("%s\n", string);
    free(string);
}

//https://www.codegrepper.com/code-examples/c/write+string+to+disk+c+program
//https://slaystudy.com/c-program-to-read-write-linked-list-to-a-file/
int savelog(char* filename) {

    data_t *current = head;

    struct tm *timeStruct;

    FILE* file;
    file = fopen(filename, "w");

    if (file == NULL) {
        printf(stderr, "\nCouldn't open file\n");
        exit(-1);
    }

    while(current != NULL) {
        timeStruct = localtime(&current->time);
        fprintf(file, "%d:%d:%d\t%s\n", timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec, current->string);
        current = current->next;
    }

    if(fwrite != 0) { //it was successful
    }
    else {
        printf("Error While Writing\n");
    }
    
    
    fclose(file);
    return 0;
}
