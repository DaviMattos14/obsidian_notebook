#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double pi(int n){
    long double term;
    term = (4.0 / ((8.0 * n) + 1.0)) -
           (2.0 / ((8.0 * n) + 4.0)) -
           (1.0 / ((8.0 * n) + 5.0)) -
           (1.0 / ((8.0 * n) + 6.0));

    return term * (1.0 / pow(16.0, n));
}
int main(int argc, char*argv[]){
    if (argc < 2)
    {
        printf("Error! digite %s <n de iteracoes>", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    
    long double valor_pi = 0.0;
    for(int i=0; i<n; i++){
        valor_pi += pi(i);
    }
    printf("pi = %Lf\n", valor_pi);
    return 0;
}