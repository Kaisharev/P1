#include <stdio.h>

int clan(int n) {
    if (n == 1) return 1; 
    if (n == 2) return 2;  
    if (n == 3) return 3;  
    return clan(n - 1) + clan(n - 2) + clan(n - 3);  
}

int main() {
    int n;
    printf("Unesite prirodan broj n: ");
    scanf("%d", &n);

    if(n<4){
        printf ("n mora biti vece od 4!");
        return 0;
    }
    printf("%d. član niza je: %d\n", n, clan(n));

    return 0;
}