#include <stdio.h>
#include <stdlib.h>

int is_lower(char c){
    if (c>=97 && c<=122) return 1;
    else if (c>=65 && c<90) return 0;
    else return -1;
}
void upper(char *s){
    if (*s>=97 && *s<=122) *s=*s-32;
}
int string_lenght (const char *string){
    int counter = 0;
    for (int i = 0; string[i]!='\0'; i++){
        counter++;
    }
    return counter;
}

void clear_new_line (char *string){
    for (int i = 0; string[i]!='\0'; i++){
        if (string[i]=='\n') string[i]='\0';
    }
}


int main (int argc, char *argv[]){
    char string[100];
    printf ("Unesite string: ");
    fgets(string, sizeof(string), stdin);
    clear_new_line(string);

    for (int i = 0; i<string_lenght(string); i++){
        if (is_lower(string[i])) upper(&string[i]);
    }
        printf ("%s", string);

}