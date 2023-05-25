// Lista 2 - Prof. Diego - Algoritmos e Programação Estruturada
// ALUNOS:
// - LEONARDO PEREIRA MOTA
// - PEDRO LACERDA DE CASTRO
// - SAMUEL SALES SOUZA


#include <stdio.h>
#include <string.h>

#define MAX_PROFESSORES 3
#define MAX_DISCIPLINAS 2
#define MAX_ESTUDANTES 15

typedef enum {
    ESPECIALISTA,
    MESTRE,
    DOUTOR
} Titulacao;

typedef struct {
    char nome[50];
    int funcional;
    Titulacao titulacao;
} Professor;

typedef struct {
    char nome[50];
    int codigo;
    int carga_horaria;
    Professor* professor_responsavel;
} Disciplina;

typedef struct {
    char nome[50];
    int matricula;
    int idade;
} Estudante;

void bubbleSort(Estudante *array, int size);
int le_valida_idade(int idade);

int main() {
    Professor professores[MAX_PROFESSORES];
    Disciplina disciplinas[MAX_DISCIPLINAS];
    Estudante estudantes[MAX_ESTUDANTES];


    strcpy(professores[0].nome, "Professor 1");
    professores[0].funcional = 1001;
    professores[0].titulacao = DOUTOR;

    strcpy(professores[1].nome, "Professor 2");
    professores[1].funcional = 1002;
    professores[1].titulacao = MESTRE;

    strcpy(professores[2].nome, "Professor 3");
    professores[2].funcional = 1003;
    professores[2].titulacao = ESPECIALISTA;


    strcpy(disciplinas[0].nome, "Disciplina 1");
    disciplinas[0].codigo = 101;
    disciplinas[0].carga_horaria = 60;
    disciplinas[0].professor_responsavel = &professores[0];

    strcpy(disciplinas[1].nome, "Disciplina 2");
    disciplinas[1].codigo = 102;
    disciplinas[1].carga_horaria = 80;
    disciplinas[1].professor_responsavel = &professores[1];


    strcpy(estudantes[0].nome, "Estudante 1");
    estudantes[0].matricula = 2001;
    estudantes[0].idade = 20;
    strcpy(estudantes[1].nome, "Estudante 2");
    estudantes[1].matricula = 2002;
    estudantes[1].idade = 22;
    strcpy(estudantes[2].nome, "Estudante 3");
    estudantes[2].matricula = 2003;
    estudantes[2].idade = 19;

    disciplinas[0].professor_responsavel = &professores[0];
    disciplinas[0].professor_responsavel = &professores[1];


    strcpy(estudantes[3].nome, "Estudante 4");
    estudantes[3].matricula = 2004;
    estudantes[3].idade = 24;
    strcpy(estudantes[4].nome, "Estudante 5");
    estudantes[4].matricula = 2005;
    estudantes[4].idade = 23;
    strcpy(estudantes[5].nome, "Estudante 6");
    estudantes[5].matricula = 2006;
    estudantes[5].idade = 21;

    disciplinas[1].professor_responsavel = &professores[2];
    disciplinas[1].professor_responsavel = &professores[1];

    
    bubbleSort(estudantes, 3);

    
    printf("Relatorio dos alunos matriculados na primeira disciplina ordenados por idade:\n");
    printf("CoddDisciplina | Professor | Estudante | IdaEstudante\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\t%s\t%s\t%d\n", disciplinas[0].codigo, disciplinas[0].professor_responsavel->nome, estudantes[i].nome, estudantes[i].idade);
    }

    
    bubbleSort(estudantes + 3, 3);

   
    printf("\nRelatorio dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente:\n");
    printf("CoddDisciplina | Professor | Estudante | IdaEstudante\n");
    for (int i = 5; i >= 3; i--) {
        printf("%d\t%s\t%s\t%d\n", disciplinas[1].codigo, disciplinas[1].professor_responsavel->nome, estudantes[i].nome, estudantes[i].idade);
    }

    return 0;
}

void bubbleSort(Estudante *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].idade > array[j + 1].idade) {
                Estudante temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int le_valida_idade(int idade) {
    if (idade >= 16 && idade <= 26) {
        return 1;
    } else {
        return 0;
    }
}
