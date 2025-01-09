#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct datum {
 int d, m, g;
} DATUM;
typedef struct student {
 char indeks[10]; // broj indeksa
 char ime[21];
 char prezime[21];
 DATUM datum_rodjenja;
 double prosek; // prosecna ocena
} STUDENT;

int string_compare (const char *string_one, const char *string_two){
    while (*string_one && (*string_one==*string_two)){
        string_one++;
        string_two++;
    }
    return *(unsigned char *) string_one - *(unsigned char *) string_two;
}

void clear_new_line (char *string){
    for (int i = 0; string[i]!='\0'; i++){
        if (string[i]=='\n') string[i]='\0';
    }
}

void input_student (STUDENT *student){
    printf ("\nBroj indeksa: ");
    fgets (student->indeks, sizeof(student->indeks), stdin);
    clear_new_line(student->indeks);

    printf ("Ime: ");
    fgets (student->ime, sizeof(student->ime), stdin);
    clear_new_line(student->ime);

    printf ("Prezime: ");
    fgets (student->prezime, sizeof(student->prezime), stdin);
    clear_new_line(student->prezime);

    printf ("Datum Rodenja: ");
    while (scanf ("%d/%d/%d", &student->datum_rodjenja.d, &student->datum_rodjenja.m, &student->datum_rodjenja.g) !=3){
        printf ("Pogrešan unos, pokušajte ponovo: ");
        getchar();
    }

    printf ("Prosjek ocjena: ");
    scanf ("%lf", &student->prosek);
    getchar();
}

STUDENT* ucitaj(int *pn){
    STUDENT *student_array = (STUDENT*)malloc(*pn*sizeof(STUDENT));

    if (student_array==NULL){
        printf ("MALLOC nije dobro alocirao :(");
        exit (-1);
    }

    for (int i = 0; i<*pn; i++){
        printf ("Student %d", i);
        input_student(&student_array[i]);
    }

    return student_array;
}


STUDENT* pronadji(STUDENT *niz, int n, const char *indeks){
  
    for (int i = 0; i<n; i++){
        if (!string_compare(niz[i].indeks, indeks)){
            return &niz[i];
        }
    }
    return NULL; 
}
int compare_by_GPA (const void *a, const void *b){
    STUDENT *student1 = (STUDENT*) a;
    STUDENT *student2 = (STUDENT*) b;
    if (student1->prosek > student2->prosek) return 1;
    if (student1->prosek < student2->prosek) return -1;
    return 0;
}
void sortiraj(STUDENT *niz, int n){
    qsort (niz, n, sizeof(STUDENT),compare_by_GPA);
}
void ispisi(STUDENT *niz, int n){
     for (int i = 0; i < n; i++) {
        printf("\nStudent %d:", i + 1);
        printf("Indeks: %s", niz[i].indeks);
        printf("Ime: %s", niz[i].ime);
        printf("Prezime: %s", niz[i].prezime);
        printf("Datum rođenja: %02d/%02d/%04d", niz[i].datum_rodjenja.d,
               niz[i].datum_rodjenja.m, niz[i].datum_rodjenja.g);
        printf("Prosek: %.2f", niz[i].prosek);
    }
}




int main (int argc, char *argv){
        int n;
    printf("Unesite broj studenata: ");
    scanf("%d", &n);
    getchar(); // Čišćenje bafera nakon `scanf`

    STUDENT *studenti = ucitaj(&n);

    printf("\nPodaci o studentima:\n");
    sortiraj (studenti, n);
    pronadji(studenti, n, "1196/24");
    ispisi(studenti, n);
    free(studenti);
    return 0;
}