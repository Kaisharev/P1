#include <stdio.h>
#include <stdlib.h>

int string_length (const char *str){
    int counter = 0;
    for (int i = 0; str[i]!='\0'; i++){
        counter++;
    }
    return counter;
}
int is_digit(char c){
    if (c >=48 && c<=57) return 1;
    return 0;
}
char* remove_digits(const char *str){
    int count_chars = 0;
    for (int i = 0; i<string_length(str); i++){
        if (is_digit(str[i])) continue;
        count_chars++;
    }

    char *digitless_string = (char*)calloc (count_chars+1, count_chars+1*sizeof(char));
    int counter = 0;
    for (int i = 0; i<string_length(str); i++){
        if (is_digit(str[i])) continue;
        digitless_string[counter]=str[i];
        counter++;
    }

    return digitless_string;
}
int main (int argc, char *argv){
    char string[]= "Danas je 2. kolokvijum!";
    printf ("%s", remove_digits(string));
}