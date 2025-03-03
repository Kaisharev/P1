/*

Definisati tip DATUM koji je opisan atributima dan, mjesec i godina. Definisati tip STUDENT kojim se
reprezentuju podaci o studentu. Svakog studenta karakteriše broj indeksa, ime, prezime, datum rođenja i
prosjek. Napisati program koji učitava prirodan broj n i niz od n podataka o studentima. Učitani niz podataka o
studentima sortirati po datumu rođenja (počevši od najstarijeg studenta), pa formatirano ispisati sortirani niz
podataka o studentima.
Primjer ispisa:
RB. PREZIME         IME             DATUM RODJ.     PROSJEK
=== =============== =============== =========== =======
1.  Bojanic         Bojana          15.09.2001.     9.31
2.  Jankovic        Janko           10.03.2003.     8.74
=== =============== =============== =========== =======

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int day;
    int month;
    int year;
}DATUM;

typedef struct 
{
    int id;
    char name[30];
    char lastname[30];
    DATUM dob;
    double gpa;
}STUDENT;

DATUM date_input (){
    DATUM date;
    scanf("%d/%d/%d", &date.day, &date.month, date.year);
    return date;
}
int compare_dates(const void *a, const void *b) {
   const STUDENT *student1 = (const STUDENT *)a;
    const STUDENT *student2 = (const STUDENT *)b;

    if (student1->dob.year != student2->dob.year) {
        return student1->dob.year - student2->dob.year;
    }
    if (student1->dob.month != student2->dob.month) {
        return student1->dob.month - student2->dob.month;
    }
    return student1->dob.day - student2->dob.day;
}
STUDENT student_input (){
    STUDENT student;
    printf("==============================\n");
    printf ("ID:            ");
    scanf ("%d", &student.id);
    printf ("Ime:           ");
    scanf ("%s", &student.name);
    printf ("Prezime:       ");
    scanf ("%s", &student.lastname);
    printf ("Datum rođenja: ");
    scanf ("%d.%d.%d", &student.dob.day, &student.dob.month, &student.dob.year);
    printf ("Prosjek:       ");
    scanf ("%lf", &student.gpa);
    printf("==============================\n");

    return student;

}

void print_students(int n, STUDENT arr[]){
     printf("RB. PREZIME         IME             DATUM RODJ. PROSJEK\n");
    printf("=== =============== =============== =========== =======\n");

    for (int i = 0; i < n; i++)
    {
        STUDENT s = arr[i];
        printf("%2d. %-15s %-15s %02d.%02d.%4d. %6.2f\n", i + 1, s.lastname, s.name, s.dob.day, s.dob.month, s.dob.year, s.gpa);
    }

    printf("=== =============== =============== =========== =======\n");
}
int main (){
    int n;
    do
    {
        printf ("Unesite broj n: ");
        scanf ("%d", &n);
    } while (n<0);

    STUDENT student[n];

    for (int i = 0; i<n; i++){
        student[i]=student_input();
    }

    qsort (student, n, sizeof(STUDENT), compare_dates);
    print_students(n, student);

}
