#include <stdio.h>
#include <stdlib.h>

typedef struct datum {
 int d, m, g;
} DATUM;
typedef struct zadatak {
 int id; // identifikator
 char naziv[64];
 DATUM rok;
 int prioritet; // 0-najveći ... 4-najmanji
} ZADATAK;

int compare_priorities (const void *a, const void *b){
    const ZADATAK *task1 = (const ZADATAK *)a; 
    const ZADATAK *task2 = (const ZADATAK *)b;
    return task1->prioritet - task2->prioritet;
}

ZADATAK** razvrstaj(ZADATAK *niz, int n, int *br){

    /*треба сортирати матрицу, ми смо радили да се сортира преко петљи, али у Програмирању 2 ћемо радити као људи qsort() функцију. 
    Мени су на К2 признали употребу ње и ако је Обрадовић рекао да као неће. Тако да ћу ју овдје користити. Нађи на YouTube туторијал
    како ради, али јако је проста.
    */
   
    qsort(niz, n, sizeof(ZADATAK), compare_priorities);
    /* Računanje po prioritetu. U niz *br vraća broj zadataka sa prioritetima. */
    for (int i =0; i<n; i++) br[niz[i].prioritet]++;
    


    // kreiranje dinamičke matrice
    ZADATAK** array_sorted_by_priority = (ZADATAK**)malloc(5*sizeof(ZADATAK*));
    // провјера да ли је малок прошао. Није обавезно, али је лијепо имати - можда ти на испиту компензују на то ако негдје нешто погријешиш
    if (array_sorted_by_priority==NULL){
        printf ("Malloc nije prošao! ");
        exit (-1);
    }
    // Ubacivanje redova i kolona u matricu
    for (int i = 0; i<5; i++){
        array_sorted_by_priority[i] = (ZADATAK*) malloc(br[i]*sizeof(ZADATAK));
         // провјера да ли је малок прошао. Није обавезно, али је лијепо имати - можда ти на испиту компензују на то ако негдје нешто погријешиш
         if (array_sorted_by_priority[i] == NULL) {
            printf("Malloc nije prošao! ");
            for (int j = 0; j < i; j++) {
                free(array_sorted_by_priority[j]);
            }
            free(array_sorted_by_priority);
            exit(-1);
        }
    }

    //upis u matricu
    for (int i = 0; i<5; i++){
        for (int j = 0; j<br[i]; j++){
            /*  пошто је br[i] број чланова низа који имају дати приоритат, можемо рећи да је члан матрице са редом и и колоном ј
                једнак ј-ом члану низа*/
            array_sorted_by_priority[i][j]=niz[j];
        }
    }

    return array_sorted_by_priority;
}
/* Овдје се од нас очекује да напишемо једно квадрилион петљи и имплементирамо bubble-sort као на вјежбама
   али пошто су мени признали qsort на К2, ја ћу се њиме водити, али онда је ова функција у суштини редудантна. 
*/

int compare_by_ID(const void *a, const void *b){
    const ZADATAK *task1 = (const ZADATAK *)a; 
    const ZADATAK *task2 = (const ZADATAK *)b;
    return task1->id - task2->id;

    /*можеш примјетити да је ова функција скоро па идентична функцији compare_by_priority, али је једина разлика у return-u*/
}
void sortiraj(ZADATAK *niz, int n){
    qsort(niz, n, sizeof (ZADATAK), compare_by_ID);
}

void pisi(ZADATAK *niz, int n){
    for (int i = 0; i<n; i++){
        printf ("ID:%-4d, Naziv:%-64s, Rok:%-2d/%-2d/%4d, Prioritet:%1d\n", niz[i].id, niz[i].naziv, niz[i].rok.d, niz[i].rok.m, niz[i].rok.g, niz[i].prioritet);
    }
}

int main (int argc, char *argv){
    int current_date = 25;
    int month = 01;
    int year = 2025;
    int br[5]={0};
    ZADATAK niz[10];
    for (int i = 0; i<10; i++){
        niz[i].id = i;
        sprintf (niz[i].naziv, "Z%d", i);
        niz[i].prioritet = i/2;
        niz[i].rok.d=current_date+=1;
        if (current_date >= 31) {
            current_date = 1;
            month++;
        }
        niz[i].rok.m = month;
        niz[i].rok.g = year;
    }

       ZADATAK **matrica = razvrstaj(niz, 10, br);

    for (int i = 0; i < 5; i++) { 
        if (br[i] > 0) { 
            printf("\nZadaci sa prioritetom %d:\n", i);
            sortiraj(matrica[i], br[i]); 
            pisi(matrica[i], br[i]);    
        }
    }

    for (int i = 0; i < 5; i++) {
        free(matrica[i]); 
    }
    free(matrica);

    return 0;
}