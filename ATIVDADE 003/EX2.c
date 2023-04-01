#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void){
    setlocale (LC_ALL, "Portuguese");

    int idade;

    printf ("Insira sua idade: ");
    scanf ("%d", &idade);

    if (idade<30)
        printf ("Voce e muito jovem.");

    return 0;
}