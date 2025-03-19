#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

char* formiraj(int n, ...){
    va_list args;
    va_start(args, n);

    size_t number_of_strings = 1;
    for (int i = 0; i<n; i++){
        number_of_strings += snprintf(NULL, 0, "%d",va_arg(args, int));
    }
    va_end(args);

    char *result =(char*)malloc(number_of_strings), next_string[12];
    result[0] = '\0';
    

    va_start(args, n);

    for (int i = 0; i<n; i++){
        sprintf(next_string, "%d",va_arg(args, int));  
        strcat(result,next_string);
    }

    va_end(args);
    
    return result;
}


int main (){
    char* s = formiraj(4, 123, 456, 789, 169420);
    printf("%s",s);
    free (s);
}