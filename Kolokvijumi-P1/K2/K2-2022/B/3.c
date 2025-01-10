#include <stdio.h>
#include <stdlib.h>

int string_length (const char *s){
    int counter = 0; 
    for (int i = 0; s[i]!='\0'; i++) counter++;
    return counter;
}
int is_digit(char c){
    if (c>='0'&&c<='9')return 1;
    return 0;
}
void hide_digits(char *s){
    if (is_digit(*s)) *s = '*';
}

int main (int argc, char *argv[]){
    char string[100];
    printf ("Unesite string: ");
    fgets (string, sizeof(string), stdin);

    int length_of_strign = string_length(string);

    for (int i = 0; i<length_of_strign; i++){
        if (is_digit(string[i])) hide_digits(&string[i]);
    }
    printf ("\nNovi string je: %s", string);
}