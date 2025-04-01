#include <stdio.h>
int main()
{
FILE *fpo, *fpk;
if (fpo=fopen("proba.txt","rb")) // otvaranje originala
{
if (fpk=fopen("kopija.txt","wb")) // otvaranje kopije
{
int c;
while ((c = fgetc(fpo)) != EOF) // cita bajt po bajt
fputc(c,fpk);
fclose(fpk); // zatvaranje kopije
printf("Kopiranje je uspjesno zavrseno.\n");
}
else printf("Ne moze da se kreira kopija.\n");
fclose(fpo); // zatvaranje originala
}
return 0;
}
