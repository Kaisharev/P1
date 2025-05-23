#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *s1, char *s2) {
    char *res = calloc(strlen(s1) + strlen(s2) + 1, sizeof(char));

    strcat(res, s1);
    strcat(res, s2);

    return res;
}

int add(int a, int b) {
    return a + b;
}

void spoji_saberi(int argc, char *argv[], char* (*dodaj)(char*, char*), int (*saberi)(int, int)) {
    char *concat = NULL; 
    int sum = 0;

    for (int i = 1; i < argc; ) {
        if (strcmp(argv[i], "-s") == 0) {
            i++;

            for(; i < argc && strcmp(argv[i], "-b") != 0; i++) {
                if (concat == NULL) {
                    concat = calloc(strlen(argv[i]) + 1, sizeof(char));
                    strcpy(concat, argv[i]);
                } else {
                    char *new_concat = dodaj(concat, argv[i]);
                    free(concat);
                    concat = new_concat;
                }
            }

            printf("String je '%s'. ", concat);
        } else if(strcmp(argv[i], "-b") == 0) {
            i++;

            for(; i < argc && strcmp(argv[i], "-s") != 0; i++) {
                sum = saberi(sum, atoi(argv[i]));
            }

            printf("Suma brojeva je %d. ", sum);
        }
    }

    printf("\n");

    // Free the concatenated string at the end
    if (concat != NULL) {
        free(concat);
    }
}

int main(int argc, char *argv[]) {
    spoji_saberi(argc, argv, concat, add);
    return 0;
}