/*
    Napisati program koji učitava dužine stranica trougla (a, b, c), 
    a zatim određuje da li se može formirati trougao od učitanih stranica. 
    Ukoliko može, odrediti da li je trougao jednakokraki, jednakostranični ili raznostranični,
    te odrediti da li je trougao pravougli, a zatim izračunati njegovu površinu i obim.
*/


#include <stdio.h>
#include <math.h>
int main (int argc, char *argv[]){

    int a,b,c;

    printf ("Unesite dužine stranica trougla (a, b, c): "); 
    scanf ("%d, %d, %d", &a, &b, &c);

    double obim = a+b+c;
    int poluobim = obim/2;
    double povrsina = sqrt(poluobim * (poluobim - a) * (poluobim - b) * (poluobim - c));

    if (a+b<c || a-b>c) {
        printf ("Trougao je nemoguće formirati");
        return 0;
    }
    if (a==b==c){
        printf ("Trougao je jednakostranični\n");
        printf ("Površina iznosi: %.2f \n Obim iznosi: %.2f", povrsina, obim);
    }
    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
        printf("Trougao je pravougli\n");
    }

    if ((a==b && b!=c) || (a==c && c!=b) || (b==c && c!=a)){
        printf ("Trougao je jednakokraki");
        printf ("Površina iznosi: %.2f \n Obim iznosi: %.2f", povrsina, obim);
        
    }

    if (a!=b&&b!=c){
        printf ("Trougao je raznostranični\n");
        printf ("Površina iznosi: %.2f \n Obim iznosi: %.2f", povrsina, obim);
    }
    
}