/*
    PRVI ZADATAK
    Napisati program koji učitava prirodne brojeve a i b
    (a<b), a zatim ispisuje proste brojeve iz
    segmenta [a,b] čiji ternarni ekvivalent sadrži
    cifru 2. Na primer, broj 5 je prost, a ternarni
    ekvivalent broja 5 (123) sadrži cifru 2. Prirodan
    broj veći od jedan je prost ako je deljiv samo sa
    jedan i samim sobom.
*/


#include <stdio.h>

/*
    Funkcija koja provjerava da li je neki broj prost 
    Funkcija vraća vrijednost 1 (TRUE) ukoliko je broj 
    prost i vrijednost 0 (FALSE) ukoliko broj nije prost.
*/
int is_prime_number (int number){
    
    //Ukoliko je broj manji od dva, on se ne smatra prostim.

    if (number < 2) return 0;

    /*
        Provjerava da li postoji djelioc datog broja. 
        I ukoliko postoji, vraća vrijednost 0 (FALSE) */

        for (int i = 2; i*i<=number; i++){
            if (number%i ==0) return 0;
        }
    return 1;
}

/*
    Funkcija koja provjerava da li broj u bazi 3 
    sadrži cifru dva. F-ja vraća vrijednost 1 (TRUE)
    ukoliko postoji cifra ili vraća vrijednost 0 (FALSE)
    ukoliko ne postoji.
*/
int contains_two_in_base_three (int number){
    while (number>0)
    {
        if (number%3==2) return 1;
        number /=3;
    }
    
    return 0;
}

int main (void){

    int a, b;
    // Unos brojeva a i b, gdje je a<b

    do{
        printf ("Unesite brojeve a, b gdje je a manje od b: ");
        scanf("%d, %d", &a, &b);
    }while (a>b);


    // Petlja koja se vrti za sve brojeve koji su u intervalu od a do b
    for (int i = a; i<=b; i++){

        // Ukoliko funkcija 'is_prime_number' i funkcija 'contains_base_two_in_base_three' vraćaju TRUE, ispisuje taj broj
        if (is_prime_number(i) && contains_two_in_base_three(i)){
            printf("Broj %d je prost i ima cifru 2 u tenarnom brojnom sistemu.\n", i);
        }

    }
    
}
