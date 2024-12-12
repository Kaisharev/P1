/*
Napisati program koji učitava dvije matrice realnih brojeva, a zatim ispisuje njihov zbir (ako matrice mogu da
se saberu) i proizvod (ako matrice mogu da se pomnože). Učitavanje jedne matrice podrazumijeva učitavanje
njenih dimenzija nxm (n ≤ 10, m ≤ 10) i elemenata. Ako matrice ne mogu da se saberu, potrebno je ispisati
odgovarajuću poruku. Takođe, ako matrice ne mogu da se pomnože, potrebno je ispisati odgovarajuću poruku.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Matrix
{
    int rows;
    int columns;
    int **data;
} Matrix;



Matrix *mx_input(){
    Matrix *matrix = malloc(sizeof(Matrix));
    do{
        printf ("Unesite dimenzije matrice (n, m): ");
        scanf ("%d, %d", &matrix->rows, &matrix->columns);
    }while (matrix->rows<1||matrix->columns<1 ? printf("Dimenzije matrice [NxM] moraju biti pozitivne!\n"):
            matrix->rows>10 || matrix->columns>10 ? printf ("Dimenzije matrife [NxM] moraju biti manje od 10!\n"):0);

            matrix->data = malloc(matrix->rows * sizeof(int *));

    for (int i = 0; i < matrix->rows; i++)
    {
        matrix->data[i] = malloc(matrix->columns * sizeof(int));
        for (int j = 0; j < matrix->columns; j++)
        {
            printf("\nUnesite [%d,%d]:",i,j);
            scanf("%d", &matrix->data[i][j]);
        }
    }

    return matrix;
}

Matrix *mx_add(const Matrix *a, const Matrix *b){
    Matrix *result_matrix = malloc(sizeof(Matrix));

    if (a->rows != b->rows || a->columns!=b->columns) return NULL;

    result_matrix->rows = a->rows;
    result_matrix->columns = a->columns;
    result_matrix->data = malloc(result_matrix->rows * sizeof(int *));

    for (int i = 0; i<result_matrix->rows; i++){
        result_matrix->data[i] = malloc(result_matrix->columns * sizeof(int *));
        for (int j = 0; j<result_matrix->columns; j++){
            result_matrix->data[i][j]= a->data[i][j]+b->data[i][j];
        }
    }
    return result_matrix;
}

Matrix *mx_multiply(const Matrix *a, const Matrix *b){
    Matrix *result_matrix = malloc(sizeof(Matrix));

      if (a->columns != b->rows)
    {
        return NULL;
    }

    result_matrix->rows= a->rows;
    result_matrix->columns=b->columns;
    result_matrix->data = malloc(result_matrix->rows * sizeof(int *));

    for (int i = 0; i < result_matrix->rows; i++)
    {
        result_matrix->data[i] = malloc(result_matrix->columns * sizeof(int));
        for (int j = 0; j < result_matrix->columns; j++)
        {
            result_matrix->data[i][j] = 0;
            for (int k = 0; k < a->columns; k++)
            {
                result_matrix->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result_matrix;

}
void mx_print(const Matrix *mat){
    for (int i = 0; i<mat->rows; i++){
        for (int j = 0; j<mat->columns; j++){
            printf ("%d", mat->data[i][j]);
        }
    }
        printf("\n");

}

int compare_elements(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void mx_compare(const Matrix *mat){
    int rows = mat->rows, columns = mat->columns;


    int *array = malloc(rows * columns * sizeof(int));  

    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[k++] = mat->data[i][j];
        }
    }    
    int size = rows*columns;
    printf("Najveći član matrice je: %d\n", array[rows * columns - 1]);

    free(array); 
}
int main (){
    Matrix *a = mx_input(), *b=mx_input();
    Matrix *sum = mx_add(a,b);
    Matrix *product = mx_multiply(a,b);
    if (mx_add==NULL) printf ("Matrice se ne mogu sabrati!"); else mx_print(sum);
    if (mx_multiply==NULL) printf ("Matrice se ne mogu pomnožiti"); else mx_print(product);

    mx_compare(product);
    

}