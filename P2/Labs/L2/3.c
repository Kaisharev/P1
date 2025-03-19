#include <stdio.h>
#include <stdlib.h>

void saberi(double *vektor_a, double *vektor_b, double *vektor_rez, int n){
    if (n==0) return;
    vektor_rez[n - 1] = vektor_a[n - 1] + vektor_b[n - 1];
    saberi(vektor_a, vektor_b, vektor_rez, n-1);
}

double input_vectors (double *vector, int n, int number){
    printf ("\nElementi %d. vektora: ", number);
    for (int i = 0; i<n; i++){
        printf ("\n Vektor[%d]: ", i);
        scanf ("%lf", &vector[i]);
    }
}
int main (){
    int n; 
    printf ("Unesite dimenziju vektorskog prostora: ");
    scanf ("%d", &n);

    double *first_vector = (double*)malloc (n*sizeof(double));
    double *second_vector = (double*)malloc (n*sizeof(double));
    double *sum_of_vectors = (double*)malloc (n*sizeof(double));
    input_vectors(first_vector, n, 1);
    input_vectors(second_vector, n, 2);
    saberi (first_vector, second_vector, sum_of_vectors, n);
    printf("Zbir vektora je:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", sum_of_vectors[i]);
    }
    printf("\n");
}