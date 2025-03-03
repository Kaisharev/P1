#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    char oznaka;      
    double x;          
    double y;          
} TACKA;

typedef struct {
    TACKA vrh1;        
    TACKA vrh2;        
    TACKA vrh3;        
} TROUGAO;

void citaj(TACKA *t){
    printf("Unesite slovnu oznaku tačke: ");
    scanf(" %c", &t->oznaka);
    printf("Unesite x i y koordinate tačke %c: ", t->oznaka);
    scanf("%lf %lf", &t->x, &t->y);
}
int provjera(TACKA *t){
    double d1 = sqrt(pow(t[1].x - t[0].x, 2) + pow(t[1].y - t[0].y, 2));
    double d2 = sqrt(pow(t[2].x - t[1].x, 2) + pow(t[2].y - t[1].y, 2));
    double d3 = sqrt(pow(t[0].x - t[2].x, 2) + pow(t[0].y - t[2].y, 2));
    
    if (d1 + d2 > d3 && d1 + d3 > d2 && d2 + d3 > d1) {
        return 1; 
    }
    return 0; 
}
TROUGAO trougao(TACKA *t){
    TROUGAO tr = {t[0], t[1], t[2]};
    return tr;
}
double obim(TROUGAO tr){
    double d1 = sqrt(pow(tr.vrh2.x - tr.vrh1.x, 2) + pow(tr.vrh2.y - tr.vrh1.y, 2));
    double d2 = sqrt(pow(tr.vrh3.x - tr.vrh2.x, 2) + pow(tr.vrh3.y - tr.vrh2.y, 2));
    double d3 = sqrt(pow(tr.vrh1.x - tr.vrh3.x, 2) + pow(tr.vrh1.y - tr.vrh3.y, 2));
    return d1 + d2 + d3;
}

int main() {
    TACKA tacke[3];
    TROUGAO tr;
    
    for (int i = 0; i < 3; i++) {
        printf("Unos za tačku %d:\n", i + 1);
        citaj(&tacke[i]);
    }
    
    if (provjera(tacke)) {
        tr = trougao(tacke);
        printf("Trougao je formiran.\n");
        printf("Obim trougla: %.2f\n", obim(tr));
    } else {
        printf("Ne može se formirati trougao sa unesenim tačkama.\n");
    }

    return 0;
}