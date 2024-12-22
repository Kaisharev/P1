#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int number_of_goals;
    int number_of_taken_goals;
    int number_of_points;
} TIM;

void ucitaj (TIM *team){
    printf ("=========================================");
    printf ("\nUnesite ime tima: ");
    scanf ("%s", &team->name);
    printf ("\nUnesite broj postignutih golova: ");
    scanf ("%d", &team->number_of_goals);
    printf ("\nUnesite broj primljenih golova: ");
    scanf ("%d", &team->number_of_taken_goals);
    printf("\nUnesite broj bodova: ");
    scanf ("%d", &team->number_of_points);
}
TIM* formiraj(int *number_of_teams){
    TIM *formed_team = (TIM*) malloc (*number_of_teams*sizeof(TIM));
    for (int i = 0; i<*number_of_teams; i++){
        printf("\nUnos za tim %d:\n", i + 1);
        ucitaj(&formed_team[i]);
    }

    return formed_team;
}

int compare(const void *a, const void *b){
    TIM *team_1 = (TIM*) a;
    TIM *team_2 = (TIM*) b;
    if (team_2->number_of_points == team_1->number_of_points) return team_1->number_of_goals-team_2->number_of_goals;
    return team_2->number_of_points-team_1->number_of_points;
}
void sortiraj (TIM *team, int number_of_teams){
    qsort(team, number_of_teams, sizeof(TIM), compare);
}

void ispisi(TIM *teams, int number_of_teams) {
    printf("RB. NAZIV                 GPO GPR GR  BOD\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < number_of_teams; i++) {
        int goal_difference = teams[i].number_of_goals - teams[i].number_of_taken_goals;
        printf("%2d. %-20s %3d %3d %3d %4d\n", 
               i + 1, 
               teams[i].name, 
               teams[i].number_of_goals, 
               teams[i].number_of_taken_goals, 
               goal_difference, 
               teams[i].number_of_points);
    }
}

int main (){
    int n;
    printf ("Unesite broj timova: ");
    scanf ("%d", &n);
    TIM *team = (TIM*) malloc(n*sizeof(TIM));
    team = formiraj(&n);

    sortiraj (team, n);
    ispisi (team, n);

    free (team);
}