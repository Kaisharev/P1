#include <stdio.h>
#include <stdlib.h>

typedef struct datum {
 int d, m, g; // dan, mesec, godina
} DATUM;
typedef struct kontakt {
 char ime[51], email[21];
 DATUM datum_rodjenja;
} KONTAKT;

int string_length (const char *s) {
    int counter = 0;
    for (int i = 0; s[i]!='\0'; i++) counter++;
    return counter;
}

void clear_new_line (char *string){
    for (int i = 0; string[i]!='\0'; i++){
        if (string[i]=='\n') string[i]='\0';
    }
}

void ucitaj(KONTAKT *k){
    printf ("Ime: ");
    fgets(k->ime, sizeof(k->ime), stdin);
    clear_new_line(k->ime);
    printf ("Email: ");
    fgets(k->email, sizeof(k->email), stdin);
    clear_new_line(k->email);
    printf ("Datum rođenja (DD/MM/GGGG): ");
    scanf("%d/%d/%d", &k->datum_rodjenja.d, &k->datum_rodjenja.m, &k->datum_rodjenja.g);
    getchar();

}

void ispisi(KONTAKT k){
    printf ("Ime: %s\n", k.ime);
    printf ("EMail: %s\n", k.email);
    printf ("Datum rođenja: %d/%d/%d\n", k.datum_rodjenja.d, k.datum_rodjenja.m, k.datum_rodjenja.g);
}

void ispisi_r(KONTAKT *niz, int n, int d, int m){
        int counter = 1;

    for (int i = 0; i<n; i++){
        if(niz[i].datum_rodjenja.d == d && niz[i].datum_rodjenja.m == m){
            printf ("\n\n========================================\n");
            printf ("Kontakt: %d\n", counter++);
            ispisi(niz[i]);
        }
    }
}

int main (int argc, char *argv[]){
    int n = 0;

    printf ("Unesite broj kontakata: ");
    scanf ("%d", &n);
    getchar();

    KONTAKT *contacts = (KONTAKT*)malloc(n*sizeof(KONTAKT));

    for (int i = 0; i<n; i++){
            printf ("========================================\n");
            printf ("Kontakt: %d\n", i+1);
            ucitaj(&contacts[i]);
    }

    ispisi_r(contacts, n,11,01);
    
}