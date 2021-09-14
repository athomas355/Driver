CC=gcc
CFLAGS=-g -Wall

driver: log.c driver.c
	gcc -o log log.c driver.c

clean:
    rm driver