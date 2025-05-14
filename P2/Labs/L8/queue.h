    #pragma once

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../UTIL/stdneb.h"

    typedef struct process {

        const char* name;
        int time;
        struct process *next;

    } PROCESS;

    typedef struct {

        PROCESS *head;
        PROCESS *tail;

    } PROCESS_QUEUE;

    void enqueue (PROCESS_QUEUE *queue, const char *name, int time){

        PROCESS *new_process = (PROCESS*) malloc(sizeof(PROCESS));
        malloc_check(new_process);

        new_process->name = strdup(name);
        new_process -> time = time;
        new_process -> next = NULL;

        if (queue->tail == NULL) {
            queue->tail = queue->head = new_process;
        }else {
            queue ->tail->next = new_process;
            queue ->tail=new_process;
        }
    }

    int dequeue (PROCESS_QUEUE *queue,  PROCESS *current){

        if (queue->head == NULL) return 0;

        PROCESS *temp = queue->head;
        current -> name = temp->name;
        current -> time  = temp -> time; 

        queue->head=queue->head->next;
        if (queue->head==NULL) queue->tail=NULL;

        free (temp);
        return 1;
    }

    void free_queue (PROCESS_QUEUE *queue){

        PROCESS *current_node = queue->head;

        while (current_node != NULL){
            PROCESS *next_node = current_node->next;
            free (current_node->name);
            free (current_node);

            current_node=next_node;
        }

        queue -> head=queue -> tail = NULL;
    }