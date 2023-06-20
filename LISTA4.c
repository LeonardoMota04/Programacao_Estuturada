//LISTA 4 - INTEGRANTES: LEONARDO PEREIRA, PEDRO LACERDA E SAMUEL SALES
//PROF DIEGO

#include <stdio.h>
#include <stdlib.h> // biblioteca para fazer a alocação dinâmica
#include <string.h>
#include <ctype.h>

#define MAX_DESCRICAO 100
#define MAX_MARCA 50
#define MAX_SITE 100
#define MAX_TELEFONE 20
#define MAX_UF 3

typedef struct {
    char descricao[MAX_DESCRICAO];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    int fabricanteIndex;
} Produto;

typedef struct {
    char marca[MAX_MARCA];
    char site[MAX_SITE];
    char telefone[MAX_TELEFONE];
    char uf[MAX_UF];
} Fabricante;

void le_valida_peso(float *peso) {
    do {
        printf("Peso (em gramas): ");
        scanf("%f", peso);
        getchar();  // Limpar o caractere de nova linha
        if (*peso < 50 || *peso > 50000) {
            printf("Peso inválido. Digite um valor entre 50g e 50kg.\n");
        }
    } while (*peso < 50 || *peso > 50000);
}

void le_valida_valor(float *valor, float min, float max) {
    do {
        printf("Valor: R$ ");
        scanf("%f", valor);
        getchar();  // Limpar o caractere de nova linha
        if (*valor < min || *valor > max) {
            printf("Valor inválido. Digite um valor entre R$ %.2f e R$ %.2f.\n", min, max);
        }
    } while (*valor < min || *valor > max);
}

void le_valida_uf(char *uf) {
    char ufs[28][3] = {
        "AC", "AL", "AM", "AP", "BA", "CE", "DF", "ES", "GO", "MA", "MG", "MS", "MT", "PA", "PB", "PE",
        "PI", "PR", "RJ", "RN", "RO", "RR", "RS", "SC", "SE", "SP", "TO"
    };

    int i;
    do {
        printf("UF: ");
        fgets(uf, MAX_UF, stdin);
        uf[strcspn(uf, "\n")] = '\0';
        if (strlen(uf) != 2) {
            printf("UF inválida. Digite uma sigla de 2 caracteres.\n");
            continue;
        }
        for (i = 0; i < 28; i++) {
            if (strcmp(uf, ufs[i]) == 0) {
                return;
            }
        }
        printf("UF inválida. Digite uma sigla de Unidade Federativa válida (ex: SP, RJ, MG).\n");
    } while (1);
}

void cadastrarFabricante(Fabricante *fabricantes, int *numFabricantes) {
    if (*numFabricantes == 5) {
        printf("Número máximo de fabricantes atingido.\n");
        return;
    }

    Fabricante *fabricante = &fabricantes[*numFabricantes];
    printf("\n\n=== Cadastro de Fabricante ===\n");
    printf("Marca: ");
    fgets(fabricante->marca, MAX_MARCA, stdin);
    fabricante->marca[strcspn(fabricante->marca, "\n")] = '\0';
    printf("Site: ");
    fgets(fabricante->site, MAX_SITE, stdin);
    fabricante->site[strcspn(fabricante->site, "\n")] = '\0';
    printf("Telefone: ");
    fgets(fabricante->telefone, MAX_TELEFONE, stdin);
    fabricante->telefone[strcspn(fabricante->telefone, "\n")] = '\0';
    le_valida_uf(fabricante->uf);

    (*numFabricantes)++;
}

void cadastrarProduto(Produto *produtos, int *numProdutos, Fabricante *fabricantes, int numFabricantes) {
    if (*numProdutos == 50) {
        printf("Número máximo de produtos atingido.\n");
        return;
    }

    Produto *produto = &produtos[*numProdutos];
    printf("\n\n=== Cadastro de Produto ===\n");
    printf("Descrição: ");
    fgets(produto->descricao, MAX_DESCRICAO, stdin);
    produto->descricao[strcspn(produto->descricao, "\n")] = '\0';
    le_valida_peso(&produto->peso);
    le_valida_valor(&produto->valorCompra, 0.5, 8000);
    le_valida_valor(&produto->valorVenda, 1, 10000);
    produto->valorLucro = produto->valorVenda - produto->valorCompra;
    produto->percentualLucro = (produto->valorLucro / produto->valorCompra) * 100;

    int i;
    for (i = 0; i < numFabricantes; i++) {
        printf("%d - %s\n", i + 1, fabricantes[i].marca);
    }

    do {
        printf("Índice do fabricante: ");
        scanf("%d", &produto->fabricanteIndex);
        getchar();  // Limpar o caractere de nova linha
        if (produto->fabricanteIndex < 1 || produto->fabricanteIndex > numFabricantes) {
            printf("Índice inválido. Digite um índice válido.\n");
        }
    } while (produto->fabricanteIndex < 1 || produto->fabricanteIndex > numFabricantes);

    (*numProdutos)++;
}

void listarMarcas(Fabricante *fabricantes, int numFabricantes) {
    printf("\n\n=== Lista de Marcas ===\n");
    int i;
    for (i = 0; i < numFabricantes; i++) {
        printf("%d - %s\n", i + 1, fabricantes[i].marca);
    }
    printf("=======================\n");
}

// ======================= SEÇÃO PARA COMPARAR PRODUTOS E BOTAR EM ORDEM CRESCENTE =========================================
int compararProdutos(const void *a, const void *b) {
    const Produto *produtoA = (const Produto *)a;
    const Produto *produtoB = (const Produto *)b;
    return strcmp(produtoA->descricao, produtoB->descricao);
}

void listarProdutosOrdemCrescente(Produto *produtos, int numProdutos, Fabricante *fabricantes, int numFabricantes) {

    Produto *produtosCopia = malloc(numProdutos * sizeof(Produto));
    memcpy(produtosCopia, produtos, numProdutos * sizeof(Produto));


    qsort(produtosCopia, numProdutos, sizeof(Produto), compararProdutos);


    printf("\n=== Lista de Produtos em Ordem Alfabética Crescente ===\n");
    int i;
    for (i = 0; i < numProdutos; i++) {
        Produto *produto = &produtosCopia[i];
        Fabricante *fabricante = &fabricantes[produto->fabricanteIndex - 1];
        printf("Descrição: %s\n", produto->descricao);
        printf("Peso: %.2fg\n", produto->peso);
        printf("Valor de Compra: R$ %.2f\n", produto->valorCompra);
        printf("Valor de Venda: R$ %.2f\n", produto->valorVenda);
        printf("Valor do Lucro: R$ %.2f\n", produto->valorLucro);
        printf("Percentual do Lucro: %.2f%%\n", produto->percentualLucro);
        printf("Fabricante: %s\n", fabricante->marca);
        printf("=======================\n");
    }

    free(produtosCopia);
}
// =======================SEÇÃO PARA COMPARAR PRODUTOS E BOTAR EM ORDEM CRESCENTE =========================================


// =======================SEÇÃO PARA COMPARAR FABRICANTES E BOTAR EM ORDEM DECRESCENTE =========================================

int compararFabricantes(const void *a, const void *b) {
    const Fabricante *fabricanteA = (const Fabricante *)a;
    const Fabricante *fabricanteB = (const Fabricante *)b;
    return strcmp(fabricanteB->marca, fabricanteA->marca);
}

void listarMarcasOrdemDecrescente(Fabricante *fabricantes, int numFabricantes) {
    //  cópia do array original
    Fabricante *fabricantesCopia = malloc(numFabricantes * sizeof(Fabricante));
    memcpy(fabricantesCopia, fabricantes, numFabricantes * sizeof(Fabricante));

    // Ordenaçao da cópia em ordem alfabética decrescente
    qsort(fabricantesCopia, numFabricantes, sizeof(Fabricante), compararFabricantes);

    printf("\n=== Lista de Marcas em Ordem Alfabética Decrescente ===\n");
    for (int i = 0; i < numFabricantes; i++) {
        printf("%d - %s\n", i + 1, fabricantesCopia[i].marca);
    }
    printf("=======================\n");


    free(fabricantesCopia);
}


// =================================================================

void listarProdutos(Produto *produtos, int numProdutos, Fabricante *fabricantes, int numFabricantes) {
    printf("\n\n=== Lista de Produtos ===\n");
    int i;
    for (i = 0; i < numProdutos; i++) {
        Produto *produto = &produtos[i];
        Fabricante *fabricante = &fabricantes[produto->fabricanteIndex - 1];
        printf("Descrição: %s\n", produto->descricao);
        printf("Peso: %.2fg\n", produto->peso);
        printf("Valor de Compra: R$ %.2f\n", produto->valorCompra);
        printf("Valor de Venda: R$ %.2f\n", produto->valorVenda);
        printf("Valor do Lucro: R$ %.2f\n", produto->valorLucro);
        printf("Percentual do Lucro: %.2f%%\n", produto->percentualLucro);
        printf("Fabricante: %s\n", fabricante->marca);
        printf("=======================\n");
    }
}

void listarProdutosEstado(Produto *produtos, int numProdutos, Fabricante *fabricantes, int numFabricantes, char *uf) {
    printf("\n\n=== Lista de Produtos do Estado %s ===\n", uf);
    int i;
    for (i = 0; i < numProdutos; i++) {
        Produto *produto = &produtos[i];
        Fabricante *fabricante = &fabricantes[produto->fabricanteIndex - 1];
        if (strcmp(fabricante->uf, uf) == 0) {
            printf("Descrição: %s\n", produto->descricao);
            printf("Peso: %.2fg\n", produto->peso);
            printf("Valor de Compra: R$ %.2f\n", produto->valorCompra);
            printf("Valor de Venda: R$ %.2f\n", produto->valorVenda);
            printf("Valor do Lucro: R$ %.2f\n", produto->valorLucro);
            printf("Percentual do Lucro: %.2f%%\n", produto->percentualLucro);
            printf("Fabricante: %s\n", fabricante->marca);
            printf("=======================\n");
        }
    }
}

void listarProdutosMarca(Produto *produtos, int numProdutos, Fabricante *fabricantes, int numFabricantes, char *marca) {
    printf("\n\n=== Lista de Produtos da Marca %s ===\n", marca);
    int i;
    for (i = 0; i < numProdutos; i++) {
        Produto *produto = &produtos[i];
        Fabricante *fabricante = &fabricantes[produto->fabricanteIndex - 1];
        if (strcmp(fabricante->marca, marca) == 0) {
            printf("Descrição: %s\n", produto->descricao);
            printf("Peso: %.2fg\n", produto->peso);
            printf("Valor de Compra: R$ %.2f\n", produto->valorCompra);
            printf("Valor de Venda: R$ %.2f\n", produto->valorVenda);
            printf("Valor do Lucro: R$ %.2f\n", produto->valorLucro);
            printf("Percentual do Lucro: %.2f%%\n", produto->percentualLucro);
            printf("Fabricante: %s\n", fabricante->marca);
            printf("=======================\n");
        }
    }
}

void encontrarEstadoProdutoMaisCaro(Produto *produtos, int numProdutos, Fabricante *fabricantes, int numFabricantes) {
    float maxValor = 0;
    int i;
    for (i = 0; i < numProdutos; i++) {
        Produto *produto = &produtos[i];
        if (produto->valorVenda > maxValor) {
            maxValor = produto->valorVenda;
        }
    }

    printf("\n\n=== Estado(s) com o Produto mais caro ===\n");
    for (i = 0; i < numProdutos; i++) {
        Produto *produto = &produtos[i];
        if (produto->valorVenda == maxValor) {
            Fabricante *fabricante = &fabricantes[produto->fabricanteIndex - 1];
            printf("%s\n", fabricante->uf);
        }
    }
    printf("=======================\n");
}

void encontrarFabricanteProdutoMaisBarato(Produto *produtos, int numProdutos, Fabricante *fabricantes, int numFabricantes) {
    float minValor = produtos[0].valorVenda;
    int i;
    for (i = 0; i < numProdutos; i++) {
        Produto *produto = &produtos[i];
        if (produto->valorVenda < minValor) {
            minValor = produto->valorVenda;
        }
    }

    printf("\n\n=== Fabricante(s) com o Produto mais barato ===\n");
    for (i = 0; i < numProdutos; i++) {
        Produto *produto = &produtos[i];
        if (produto->valorVenda == minValor) {
            Fabricante *fabricante = &fabricantes[produto->fabricanteIndex - 1];
            printf("%s\n", fabricante->marca);
        }
    }
    printf("=======================\n");
}

void ordenarProdutosValor(Produto *produtos, int numProdutos) {
    int i, j;
    for (i = 0; i < numProdutos - 1; i++) {
        for (j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorVenda > produtos[j + 1].valorVenda) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

void ordenarProdutosLucro(Produto *produtos, int numProdutos) {
    int i, j;
    for (i = 0; i < numProdutos - 1; i++) {
        for (j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorLucro > produtos[j + 1].valorLucro) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

void ordenarProdutosPercentualLucro(Produto *produtos, int numProdutos) {
    int i, j;
    for (i = 0; i < numProdutos - 1; i++) {
        for (j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].percentualLucro > produtos[j + 1].percentualLucro) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

int main() {
    int opcao;
    int numFabricantes = 0;
    int numProdutos = 0;
    Fabricante *fabricantes = malloc(5 * sizeof(Fabricante));
    Produto *produtos = malloc(50 * sizeof(Produto));

    do {
        printf("[1] Cadastrar fabricante\n");
        printf("[2] Cadastrar produto\n");
        printf("[3] Listar todas as marcas\n");
        printf("[4] Listar todos os produtos\n");
        printf("[5] Listar os produtos de um determinado estado\n");
        printf("[6] Listar os produtos de uma determinada marca\n");
        printf("[7] Apresentar o(s) estado(s) onde está registrado o produto mais caro\n");
        printf("[8] Apresentar o(s) fabricante(s) onde está registrado o produto mais barato\n");
        printf("[9] Listar todos os produtos em ordem crescente de valor\n");
        printf("[10] Listar todos os produtos em ordem crescente de lucro\n");
        printf("[11] Listar todos os produtos em ordem crescente de percentual de lucro\n");
        printf("[12] Listar todos os produtos em ordem alfabética crescente (A-Z)\n");
        printf("[13] Listar todas as marcas em ordem alfabética decrescente (Z-A)\n");
        printf("[0] Sair\n");
        printf("\nDigite uma opção: ");
        scanf("%d", &opcao);
        getchar();  // Limpar o caractere de nova linha
        
        
        switch (opcao) {
            case 1:
                cadastrarFabricante(fabricantes, &numFabricantes);
                break;
                
            case 2:
                cadastrarProduto(produtos, &numProdutos, fabricantes, numFabricantes);
                break;
                
            case 3:
                listarMarcas(fabricantes, numFabricantes);
                break;
                
            case 4:
                listarProdutos(produtos, numProdutos, fabricantes, numFabricantes);
                break;
                
            case 5: {
                char uf[MAX_UF];
                le_valida_uf(uf);
                listarProdutosEstado(produtos, numProdutos, fabricantes, numFabricantes, uf);
                break;
            }
                
            case 6: {
                char marca[MAX_MARCA];
                printf("Marca: ");
                fgets(marca, MAX_MARCA, stdin);
                marca[strcspn(marca, "\n")] = '\0';
                listarProdutosMarca(produtos, numProdutos, fabricantes, numFabricantes, marca);
                break;
            }
                
            case 7:
                encontrarEstadoProdutoMaisCaro(produtos, numProdutos, fabricantes, numFabricantes);
                break;
                
            case 8:
                encontrarFabricanteProdutoMaisBarato(produtos, numProdutos, fabricantes, numFabricantes);
                break;
                
            case 9:
                ordenarProdutosValor(produtos, numProdutos);
                listarProdutos(produtos, numProdutos, fabricantes, numFabricantes);
                break;
                
            case 10:
                ordenarProdutosLucro(produtos, numProdutos);
                listarProdutos(produtos, numProdutos, fabricantes, numFabricantes);
                break;
                
            case 11:
                ordenarProdutosPercentualLucro(produtos, numProdutos);
                listarProdutos(produtos, numProdutos, fabricantes, numFabricantes);
                break;
                
            case 12:
                listarProdutosOrdemCrescente(produtos, numProdutos, fabricantes, numFabricantes);
                break;
                
            case 13:
                listarMarcasOrdemDecrescente(fabricantes, numFabricantes);
                break;
                
            case 0:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opção inválida. Digite uma opção válida.\n");
                break;
        }


        printf("\n");
        
    } while (opcao != 0);

    free(fabricantes);
    free(produtos);

    return 0;
}
