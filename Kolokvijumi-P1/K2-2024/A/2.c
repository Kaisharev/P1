#include <stdio.h>
#include <stdlib.h>
int string_length (const char *str){
    int counter = 0;
    for (int i = 0; str[i]!='\0'; i++){
        counter++;
    }
    return counter;
}
char* podstring (const char *str, int s, int d){
    if (s>d || s<0||s>string_length(str)-1||d>string_length(str)-1) return NULL;
    int strlength = d-s+1;
    char *substring = (char *)malloc ((strlength+1)*sizeof (char));
    int counter = 0;
    for (int i = s; i<= d; i++){
        
        substring[counter++]=str[i];
    }
    substring[counter] = '\0';  
    return substring;
}

int pocinje (const char *s, const char *t){
    int counter = 0;
    for (int i = 0; i<string_length(t); i++){
        if (s[i] != t[i] || s[i]=='\0') return 0;
    }
    return 1;
}

int main (){
    char str[] = "Danas je 2. kolokvijum!";
    char *result = podstring(str, 0, 5);

    printf ("%s", result);
    char input_string[100];
    printf ("Unesite string: ");
    scanf ("%s", &input_string);
    if (pocinje(result, input_string)) printf ("Počinje"); 
    else printf ("Ne počinje");
    free (result);
}