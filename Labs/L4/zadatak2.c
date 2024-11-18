/*
    Napisati program koji učitava mjesec i godinu 
    (npr. 3 2014 za mart 2014), a zatim ispisuje broj 
    dana u tom mjesecu. Obratiti pažnju na prestupne godine.
*/

#include <stdio.h>

int is_leap_year (int year){
    if (year % 400 == 0) return 29;
    else if (year % 100 != 0 && year % 4 == 0) return 29;
    else return 28;
}

void return_date_value (int month, int year){
    static char *months[12] = {"JANUAR", "FEBRUAR", "MART", "APRIL", "MAJ", "JUN", "JUL", "AVGUST", "SEPTEMBAR", "OKTOBAR", "NOVEMBAR", "DECEMBAR"};

    if (month == 1 ||month == 3 || month == 5 || month == 7 ||month == 8 || month == 10 ||month == 12){
        printf("Mjesec %s %d godine ima %d dan", months[month - 1], year, 31);
    } 
    else if (month == 2) {
        printf ("Mjesec FEBRUAR %d godine ima %d dana", year, is_leap_year(year));
    }
    else{
              printf("Mjesec %s %d godine ima %d dana", months[month - 1], year, 30);
  
    };
}



int main (int argc, char *argv[]){

    int year, month;
    printf ("Unesite godinu i mjesec (mjesec godina): ");
    scanf ("%d %d", &month, &year);
    return_date_value(month, year);

}