#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void){
    setlocale (LC_ALL, "Portuguese");

    double notas[5];
    float media=0, soma=0;
    int i;

    for(i = 0; i<5; i++){
        printf ("Insira a %dª nota: ", i+1);
        scanf ("%lf", &notas[i]);
        soma+=notas[i];
    }
    
    media = soma/5;

    printf ("\nA média foi %.2f", media);

    return 0;
}