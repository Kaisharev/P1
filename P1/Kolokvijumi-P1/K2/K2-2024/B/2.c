#include <stdio.h>
#include <stdlib.h>
int string_length (const char *s){
    int length = 0;
    for (int i = 1; s[i]!='\0'; i++) length++;
    return length;
}
char* podstr(const char *s, int p, int d){
    if (p<0 || p>string_length(s)-1 || d<1 || p+d>string_length(s)) return NULL;
    char *string = (char*) calloc(d+1, sizeof(char));
    for (int i = p; i<=d; i++)
            string[i]=s[p+i];
    return string;
}

int startstr (const char *s, const char *t){
    for (int i = 0; i<string_length(t); i++) 
        if (s[i]!=t[i])return 0;
    return 1;
}

int main (int argc, char *argv){
    char base_string[22] = "Banja Luka, 16.1.2024";
    char *substring = podstr(base_string, 0, 9);
    char input_string[22];
    printf ("Unesite riječ: ");
    fgets(input_string, sizeof(input_string), stdin);

    printf ((startstr(substring, input_string)?"Počinju isto" : "Ne počinju isto"));
    free (substring);
}