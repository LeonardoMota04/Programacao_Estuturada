#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void){
    setlocale (LC_ALL, "Portuguese");

    int idade;

    printf ("INSIRA SUA IDADE: ");
    scanf ("%d", &idade);

    //Não sei como fazer esse exercicio sem utilizar o ELSE IF e o &&, pelo menos não entendi, já que quem tem 71 anos tem mais de 70 e mais de 21 ao mesmo tempo.
    if (idade > 70){
        printf ("Novos 50.");
    } else if (idade > 21 && idade <71){
        printf ("Adulto.");
    } else {
        printf ("Jovem.");
    }
    
    return 0;
}