#include <stdio.h>
#include <stdlib.h>

int string_length (const char *string){
    int counter = 0;
    for (int i = 1; string[i]!='\0'; i++) counter ++;
    return counter;
}

int is_space(char c){
    return c == ' ';
}

char* remove_spaces(const char *str){
    int count_chars = 0;
    for (int i = 0; i<string_length(str); i++){
        if (!is_space(str[i])) count_chars++;
    }

    char *modified_string = (char*)malloc (count_chars*sizeof(char));
    int counter = 0;
    for (int i = 0; i<string_length(str); i++){
        if (is_space(str[i])) continue;
        modified_string[counter] = str[i];
        counter++;
    }

    return modified_string;
}

int main (int argc, char *argv){
    char string[] = "Danas je 2. kolokvijum!";
    printf ("%s", remove_spaces(string));
}