#include <stdio.h>
#include <stdlib.h>

int** ucitaj(int *n, int *m){
    int **matrix = (int**)malloc (*n*sizeof(int*)) ;
    for (int i = 0; i<n; i++){
        matrix[i] = (int*)malloc(*m*sizeof(int));
        if (matrix[i]==NULL) {
            printf ("MALLOC nije prošao za red %d", i);
            for (int j = 0; j<i; j++) free (matrix[j]);
            free (matrix);
            exit(-1);
        }

        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                printf ("Clan [%d][%d]: ", i,j);
                scanf ("%d", &matrix[i][j]);
            }
        }
    }
    return matrix;
}

int** saberi(int **m1, int **m2, int n, int m){
    int **add_matrices = (int**)malloc (n*sizeof(int*));
    for (int i = 0; i<n; i++){
        add_matrices[i]=(int*)malloc (m*sizeof(int));
        if (add_matrices[i]==NULL) {
            printf ("MALLOC nije prošao za red %d", i);
            for (int j = 0; j<i; j++) free (add_matrices[j]);
            free (add_matrices);
                exit(-1);

        }
    }

    for (int i = 0;  i<n; i++){
        for (int j =0; j<m; j++){
            add_matrices[i][j]=m1[i][j]+m2[i][j];
        }
    }

    return add_matrices;

}

int** transponuj(int **mat, int n, int m){
    int **transposed_matrix = (int**)malloc (n*sizeof(int*));
    
    for (int i = 0; i<n; i++){
        transposed_matrix[i]=(int*)malloc(m*sizeof(int));
    }

    for (int i = 0; i<n; i++){
        for (int j =0; j<m; j++){
            transposed_matrix[j][i]=mat[i][j];
        }
    }

    return transposed_matrix;
}
