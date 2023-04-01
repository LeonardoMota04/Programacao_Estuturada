#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void){
    setlocale (LC_ALL, "Portuguese");

    int idade;

    printf ("\n\tELEICOES\n\nInsira sua idade: ");
    scanf ("%d", &idade);

   
    if (idade < 0){
        printf ("\nNAO NASCEU AINDA");
       
    } else if (idade > 0 && idade < 16){
        printf ("\nNAO VOTA");

    } else if (idade > 15 && idade <18){
        printf ("\nVOTO OPCIONAL");

    } else if (idade > 17 && idade < 66){
        if (idade == 41){
            printf ("\nGANHA PREMIO E NAO VOTA");
        } else {
            printf ("\nVOTO OBRIGATORIO");
        }

    } else if (idade > 65){
        if (idade == 88){
            printf ("\nGANHA PREMIO E NAO VOTA");
        } else {
            printf ("\nVOTO OPCIONAL");
        }
    }
    
    return 0;
}