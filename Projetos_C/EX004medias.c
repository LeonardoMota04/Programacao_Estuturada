//
//  EX004medias.c
//  Projetos_C
//
//  Created by Leonardo Mota on 24/04/23.
// EX004 PROF. DIEGO - PROGRAMAÇÃO ESTRUTURADA

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float le_valida_media(void);
void exibe_cabecalho(void);
void exibe_rodape(float media_turma, float maior_nota, float menor_nota, int reprovados, int aprovados);

// Função para ler e validar uma média entre 0 e 10

int main(int argc, char *argv[]) {
    //setlocale(LC_ALL, "Portuguese");

    int qtdMedias, reprovados = 0, aprovados = 0;
    float soma_medias = 0, maior_nota = 0, menor_nota = 10;

    exibe_cabecalho();

    do {
        printf("QTD. DE MEDIAS A SEREM INSERIDAS: ");
        scanf("%d", &qtdMedias);
        if (qtdMedias > 25) {
            printf("\nMÁXIMO DE 25 ENTRADAS!!!\n\n");
        }
    } while (qtdMedias > 25);

    float *medias = (float *) malloc(qtdMedias * sizeof(float)); // Alocação dinâmica do array de médias

    // Ler as médias e calcular a soma, maior e menor nota
    for (int i = 0; i < qtdMedias; i++) {
        medias[i] = le_valida_media(); // Armazena a média no array
        soma_medias += medias[i];
        if (medias[i] > maior_nota) {
            maior_nota = medias[i];
        }
        if (medias[i] < menor_nota) {
            menor_nota = medias[i];
        }
        if (medias[i] <= 6.9) {
            reprovados++;
        } else {
            aprovados++;
        }
    }

    // Calcular a média da turma
    float media_turma = soma_medias / qtdMedias;

    // Exibir o relatório
    exibe_rodape(media_turma, maior_nota, menor_nota, reprovados, aprovados);

    // Liberar a memória alocada dinamicamente
    free(medias);

    return 0;
}

float le_valida_media(void) {
    float media;
    do {
        printf("Informe a media: ");
        scanf("%f", &media);
        if (media < 0 || media > 10) {
            printf("Insira um valor entre 0 e 10!\n");
        }
    } while (media < 0 || media > 10);
    return media;
}

// Procedimento para exibir o cabeçalho do relatório da turma
void exibe_cabecalho(void) {
    printf("------------------\n");
    printf("Relatorio da turma\n");
    printf("------------------\n");
}

// Procedimento para exibir o rodapé do relatório da turma
void exibe_rodape(float media_turma, float maior_nota, float menor_nota, int reprovados, int aprovados) {
    printf("------------------\n");
    printf("Media da turma: %.2f\n", media_turma);
    printf("Maior nota: %.2f\n", maior_nota);
    printf("Menor nota: %.2f\n", menor_nota);
    printf("Reprovados: %d\n", reprovados);
    printf("Aprovados: %d\n", aprovados);
    printf("------------------\n");
    }
