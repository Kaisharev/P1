    #pragma once

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../UTIL/stdneb.h"

    typedef struct process {

        char* name;
        int time;
        struct process *next;

    } PROCESS;

    typedef struct {

        PROCESS *head;
        PROCESS *tail;

    } PROCESS_QUEUE;

    void enqueue (PROCESS_QUEUE *queue, const char *name, int time);
    int dequeue (PROCESS_QUEUE *queue,  PROCESS **current);
    void queue_free (PROCESS_QUEUE *queue);
