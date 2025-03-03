#include <stdio.h>
#include <stdlib.h>

int sum_of_digits (int number){
    int counter = 0;
    while (number>0){
        counter+=number%10;
        number/=10;
    }
    return counter;
}

int* formiraj (int *niz, int n, int *m) {
    int counter = 0;

    for (int i = 0; i<n; i++){
        if (niz[i]>0 && sum_of_digits(niz[i])%2==0) counter++;
    }
    int *array = (int*) malloc(counter * sizeof(int));
    if (counter==0){
        *m = 0;
        return NULL;
    }
    int index = 0;
       for (int i = 0; i<n; i++){
        if (niz[i]>0 && sum_of_digits(niz[i])%2==0) array[index++]=niz[i];
    }
    *m = counter;
    return array;
}

int prirodni (int mat[][10], int n, int m){
    int max_count = 0;
    int max_row_index = -1;

    for (int i = 0; i<n; i++){
        int counter;
        int *row = formiraj(mat[i], m, &counter);

        if (counter>max_count){
            max_count=counter;
            max_row_index = i;
        }
        if (row != NULL) free (row);
    }
    return max_row_index;
}

int main (int argc, char* argv[]){
    int mat[2][10] = {
        {3, 22, 4, 0, 0, 0, 0, 0, 0, 0},
        {1, 6, 8, 0, 0, 0, 0, 0, 0, 0}
    };

    int result = prirodni(mat,2,3);

    if (result !=-1) printf ("Red sa najviše brojeva je: %d\n", result);
    else printf ("Ne postoji validan red\n");
}
