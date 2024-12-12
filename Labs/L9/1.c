#include <stdio.h>

void factoriel_of_large_number (int n, int factoriel_array[]){
    int carry,array_length;
	array_length = 1; 
    carry = 0;
    for(int i=1;i<=n;i++) {
		for(int j=0;j<array_length;j++) {
			int temp = factoriel_array[j]*i + carry;
			factoriel_array[j] = temp%10;
			carry = temp/10;
		}
		while(carry>0) {
			factoriel_array[array_length] = carry%10;
			carry = carry/10;
			array_length++;
		}
	}

   	printf ("\nFaktorijel broja %d je: ",n);
	for(int i=array_length-1;i>=0;i--)
		printf("%d",factoriel_array[i]);
    
}
int main(void) {
     
	int  n;
	int factoriel_array[158] = {0};   
	factoriel_array[0] = 1;


    do
    {
        printf ("Unesite broj kojem želite izračunati faktorijel: ");
        scanf ("%d", &n);
    } while (n<0 || n>100);
    
    factoriel_of_large_number(n, factoriel_array);
	

	
	return 0;
}