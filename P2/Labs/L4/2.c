#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359

FILE *open_file(char *name, char *type)
{

    FILE *fp_file = fopen(name, type);

    if (!fp_file)
    {
        perror("Greska");
        exit(EXIT_FAILURE);
    }
    return fp_file;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Fale parametri komandne linije. Ispravno pokretanje je: naziv_fajla.exe naziv_fajla.txt");
        return -1;
    }

    FILE *fp_input = open_file(argv[1], "r");
    double x, y, r, area;
    double largest_x = 0, largest_y = 0, largest_r = 0, largest_area = 0;

    while (fscanf(fp_input, " (%lf , %lf , %lf ) ", &x, &y, &r) == 3)

    {
        area = r * r * PI;
        if (area > largest_area)
        {
            largest_area = area;
            largest_x = x;
            largest_y = y;
            largest_r = r;
        }
    }
    fclose(fp_input);
    printf("Najvecu povrsinu (P=%.3lf) ima krug:\n (%lf, %lf, %lf)", largest_area, largest_x, largest_y, largest_r);
}
