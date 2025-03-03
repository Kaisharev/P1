    int compare_complex_number_modulo (const void *a, const void *b){
    KOMPLEKS *c1 = (KOMPLEKS*) a;
    KOMPLEKS *c2 = (KOMPLEKS*) b;

    return complex_number_modulo(*c2)-complex_number_modulo(*c1);
    }

/*
    funkcija poređenja, prima const void *a i *b, unutar sebe ima dvije varijable
    tipa: tip_podatka *ime = (tip_podatka*) a i vraća njihovu razliku; a-b ako treba rastuće i 
    b-a ako treba opadajuće

*/