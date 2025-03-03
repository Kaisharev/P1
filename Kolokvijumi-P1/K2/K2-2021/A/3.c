#include <stdio.h>
#include <stdlib.h>

int string_length (const char *s){
    int counter = 0;
    for (int i = 0; s[i]!='\0'; i++) counter++;
    return counter;
}
char* slova(const char *s){
    int count_letters=0;
    int length_of_string = string_length(s);
    for (int i = 0; i<length_of_string; i++){
        if (s[i]>='a'&&s[i]<='z' || s[i]>='A'&&s[i]<='Z') count_letters++;
    }

    char* onlychars = (void*)malloc(count_letters*sizeof(char));
    int counter = 0; 
    for (int i = 0; i<length_of_string; i++)
        if (s[i]>='a'&&s[i]<='z' || s[i]>='A'&&s[i]<='Z') onlychars[counter++]=s[i];

    return onlychars;
}

int compare_string (const void *a, const void *b){
    return *(char*)a-*(char*)b;
}
void sortiraj(char *s){
    qsort(s, string_length(s), sizeof(char), compare_string);
}

