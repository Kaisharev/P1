#include <stdio.h>
#include <stdlib.h>
int contains_digit_c (int number, int digit){
    int last_digit;
    while (number > 0){
        last_digit = number%10;
        if (last_digit == digit) return 1;
        number/=10;
    }
    return 0;
}
long* cifra(long *niz, int n, int c, int *m){
    int elements_that_contain_digit_c = 0;
    for (int i = 0; i<n; i++)
        if (contains_digit_c(niz[i], c)) elements_that_contain_digit_c++;

 
    
    if (elements_that_contain_digit_c == 0) {
        *m = 0;
        return NULL;
    }
   long *new_array_of_digits = (long*)malloc (elements_that_contain_digit_c*sizeof(long));

    if (new_array_of_digits == NULL){
        exit (-1);
    }
    
    int counter = 0;
    for (int i = 0; i<n; i++)
        if (contains_digit_c(niz[i], c)) new_array_of_digits[counter++] = niz[i];
    
    *m = counter;
    return new_array_of_digits;
}

int cfr(long mat[][10], int n, int m, int c){
    int max_count = 0; 
    int largest_index = -1;
    for (int i = 0; i<n; i++){
        int count = 0;
        long *filtered_array = cifra(mat[i], n,c,&count);

        if (count > max_count){
            max_count = count;
            largest_index = i;
        }

        if (filtered_array != NULL && count >0){
            for (int j = 0; j<count; j++){
                printf("%ld ", filtered_array[j]);

            }
        }
    }

    if (largest_index == -1){
     printf("Matrica ne sadrži nijedan broj sa cifrom %d.\n", c);
    }else {
        printf ("Najveći red je: %d", largest_index);
    }
    return largest_index;

}

int main (int argc, char* argv[]){
  long mat[3][10] = {
        {123, 45, 678},
        {12, 345, 789},
        {901, 234, 567}
    };

    // Dimenzije matrice
    int n = 3;  // Broj vrsta
    int m = 3;  // Broj kolona

    // Cifra koju tražimo
    int c = 3;

    // Poziv funkcije cfr i prikaz rezultata
    int result = cfr(mat, n, m, c);

    // Provera rezultata i ispis odgovarajuće poruke
    if (result == -1) {
        printf("Matrica ne sadrži nijedan broj sa cifrom %d.\n", c);
    } else {
        printf("Vrsta s najviše brojeva koji sadrže cifru %d je: %d\n", c, result);
    }

    return 0;
}