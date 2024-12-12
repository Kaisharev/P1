/*
Definisati tip TROUGAO kojim se reprezentuje trougao (svaki trougao je opisan dužinama stranica). Napisati
program koji učitava jedan trougao, a zatim ispisuje njegov obim i površinu. Pri učitavanju trougla, voditi
računa o tome da se učitaju validne dužine stranica, tj. validan trougao.
*/
#include <math.h>

#include <stdio.h>


typedef struct{
    double a;
    double b;
    double c;
}TROUGAO;

TROUGAO triangle_input (){
    TROUGAO triangle;
    printf ("Unesite stranice trougla u formatu a b c: ");
    scanf ("%lf %lf %lf", &triangle.a, &triangle.b, &triangle.c);

    if (triangle.a + triangle.b <= triangle.c || triangle.a + triangle.c <= triangle.b || triangle.b + triangle.c <= triangle.a) return triangle_input();
    
    return triangle;
}

double perimeter_of_triangle (TROUGAO triangle){
    return triangle.a+triangle.b+triangle.c;
}

double triangle_area (TROUGAO triangle){
    double semi_perimeter = perimeter_of_triangle(triangle)/2.0;
    double area = (double) semi_perimeter*(semi_perimeter-triangle.a)*(semi_perimeter-triangle.b)*(semi_perimeter-triangle.c);
    return sqrt(area);
}
int main (){
    TROUGAO triangle = triangle_input();
    printf ("Obim trougla je: %lf, a površina je: %lf", perimeter_of_triangle(triangle), triangle_area(triangle));
}