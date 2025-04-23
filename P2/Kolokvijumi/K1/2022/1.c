/*
Neka je data matrica dimenzija mxn.
Napisati rekurzivnu funkciju koja računa ukupan broj
putanja kojima se može doći od prve (0, 0) do
posljednje ćelije u matrici (m-1, n-1). Moguće putanje
za naredni korak su desno i dole u odnosu na početnu
ćeliju. Smatrati da iz posljednjeg reda (m-1) ili
posljednje kolone (n-1) postoji samo jedna putanja do
posljednje ćelije. Prototip funkcije je:
int countPaths(int currentRow, int
currentColumn, int m, int n)

*/

int countPaths(int currentRow, int currentColumn, int m, int n)
{
    if (currentRow == m - 1 || currentColumn == n - 1)
        return 1;

    return countPaths(currentRow - 1, currentColumn, m, n) + countPaths(currentRow, currentColumn - 1, m, n);
}