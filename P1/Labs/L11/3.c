#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char name [30];
    char extension [10];
    int size_of;
} DOKUMENT;

DOKUMENT* formiraj(int *number_of_files){
    DOKUMENT *documents = (DOKUMENT*) malloc (*number_of_files*sizeof(DOKUMENT));
    for (int i = 0; i<*number_of_files; i++){
        printf ("\nDokument[%d]: Unesite ime, ekstenziju i veličinu (ime eks size_of): ",i+1);
    scanf("%s %s %d", documents[i].name, documents[i].extension, &documents[i].size_of);
    }
    return documents;
}

void ispisi(DOKUMENT document){
    printf ("%s.%s | velicina %d[B]\n", document.name, document.extension, document.size_of);
}

int main(){
    int n, min_size;
    printf ("Unesite broj do kumenata i minimalnu veličinu: ");
    scanf ("%d %d", &n, &min_size);
    DOKUMENT *documents =formiraj(&n);


    for (int i = 0; i<n; i++){
        if (documents[i].size_of>min_size) ispisi(documents[i]);

    }

        
    free (documents);
}