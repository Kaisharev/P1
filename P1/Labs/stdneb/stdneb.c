#include "stdneb.h"
#include <stdio.h>
#include <limits.h>

double power_of (double argument, double exponent){
    double pow_value=1;
    for (int i = 1; i<=exponent; i++){
        pow_value*=argument;
    }
    return pow_value;
}

int is_prime (int number){
    if (number<2) return 0;
    for (int i = 2; i*i<=number; i++){
        if (number%i==0) return 0;
    }
    return 1;
}

int next_smallest_prime (int number){
       int next_prime = number+1;
       while (!is_prime(next_prime)){
        next_prime++;
       }
    return next_prime;
}
    


int sum_prime (int number){
    int sum_digits;
    int last_digit;
    
  

    while (number > 0){
        last_digit=number%10;
        if (is_prime(last_digit)) sum_digits+=last_digit;
        number/=10;
              
    }
      
    
    return sum_digits;
}

int factoriel_of_number (int number){
    int factoriel_value = 1;
    for (int i = 1; i<=number; i++) factoriel_value*=i;
    return factoriel_value;
}