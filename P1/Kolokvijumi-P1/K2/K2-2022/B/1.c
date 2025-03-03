#include <stdio.h>
#include <stdlib.h>

float** ucitaj(int *r, int *k){
    float **matrix = (float**)malloc(*r*sizeof(float*));
    if (matrix==NULL){
            printf ("Malloc nije prošao");
            free(matrix);
            exit(-1);
    } 

    for (int i = 0; i<*r; i++){
        matrix[i]= (float*)malloc(*k*sizeof(float));
        if (matrix[i]==NULL){
            printf ("Malloc nije prošao na redu: %d", i);
            for (int j=0; j<i; j++) free (matrix[j]);
            free(matrix);
            exit(-1);
        }
    }

    for (int i = 0; i<*r; i++){
        for (int j = 0; j<*k; j++){
            printf ("Clan [%d][%d]: ");
            scanf ("%f", &matrix[i][j]);
        }
    }
}
float** saberi(float **m1, int r1, int k1, float **m2, int r2, int k2){
    if (r1!=r2 || k1!=k2 ) return NULL;
    float **add_matrices = (float**)malloc(r1*sizeof(float*));
    if (add_matrices==NULL){
        printf ("MALLOC nije prošao!");
        free (add_matrices);
        exit(-1);
    }

    for (int i = 0; i<r1; i++){
        add_matrices[i]= (float*)malloc(k1*sizeof(float));
        if (add_matrices[i]==NULL){
            printf ("MALLOC nije prošao na redu %d", i);
            for (int j = 0; j<i; j++){
                free (add_matrices[j]);
            }
            free(add_matrices);
            exit (-1);
        }
    }

    for (int i =0; i<r1; i++){
        for (int j = 0; j<k1; j++){
            add_matrices[i][j]=m1[i][j]+m2[i][j];
        }
    }
    return add_matrices;
}
float** transponuj(float **mat, int n){
    float **transposed_matrix = (float**)malloc(n*sizeof(float*));
    for (int i =0; i<n; i++){ 
        transposed_matrix[i]=(float*)malloc(n*sizeof(float));
    }

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++) transposed_matrix[j][i] = mat[i][j];
    }

    return transposed_matrix;
}
