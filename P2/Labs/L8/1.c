#include "queue.h"
#include <unistd.h>
#include <time.h>

int main (void){
    srand(time(NULL));

    PROCESS_QUEUE queue;
    queue.head = queue.tail = NULL;

    int n;
    printf ("Unesite broj procesa: ");
    scanf ("%d", &n);
    getchar();

    for (int i = 1; i<=n; i++){
        char process_name [20];
        snprintf (process_name, sizeof(process_name), "proces%d", i);
        int process_time = rand() %5+1;
        printf ("naziv_procesa: %s; vrijeme_izvrsavanja:%ds\n", process_name, process_time);
        enqueue (&queue, process_name, process_time);
    }

    printf ("Unesite START da pokrenete izvrsenje: ");
    char input[10];
    fgets(input,6,stdin);
    input [ strcspn (input, "\n")] = 0;
    if(strcmp(input, "START") == 0){
        while (&queue.head != NULL){
 
            PROCESS *current;
            if (dequeue(&queue, &current)) {
                printf("%s\n", current->name);
                fflush(stdout);
                sleep(current->time);
                free(current->name);
                free(current->time);
                free(current);
            }
        }
    }
    queue_free(&queue);
    return 0;

}