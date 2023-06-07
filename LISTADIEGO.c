//LISTA 3 - INTEGRANTES: LEONARDO PEREIRA, PEDRO LACERDA E SAMUEL SALES
// dia 06/06
//PROF DIEGO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int le_valida_uf(char uf[], int val);
int le_valida_positivo();

int main() {
    
    typedef struct {
        char marca[40], site[40], uf[2];
        int ddd, telPrim, telSeg;
    }Fabricante;

    typedef struct {
        char descricao[40];
        int peso;
        float valorCompra, valorVenda, valorLucro, percenLucro;
        Fabricante fabricante;
    }Produto;

    char uf[2], bufferUF[2], pesUF[2], pesMarca[40];
    int i=0, j=0, numFabricantes=0, op, limProd, limite=0,  validado=10;
    int precoMAIOR=0, precoMENOR=10000; // simulando variaveis para serem comparadas e o maior sempre ser maior que 0 e menor sempre ser menor que esse valor
    
    Fabricante fabricante[5];
    Produto produto[50], aux;
    
    
    

    for(i=0;i<2;i++){
        printf("NOME DO FABRICANTE nº%d: ", i+1);
        scanf("%s", fabricante[i].marca);
        
        printf("SITE DO FABRICANTE nº%d: ", i+1);
        scanf("%s", fabricante[i].site);

        printf("DDD: ");
        fabricante[i].ddd=le_valida_positivo();
        printf("4 DIGITOS *INICIAIS* DO TELEFONE DO FABRICANTE nº%d: ", i+1);
        fabricante[i].telPrim=le_valida_positivo();
        printf("4 DIGITOS *FINAIS* DO TELEFONE DO FABRICANTE nº%d: ", i+1);
        fabricante[i].telSeg=le_valida_positivo();

        do{
            printf("UF FABRICANTE: ");
            scanf("%s", uf);
            
            for (j = 0; j < 2; j++){
                uf[j]=toupper(uf[j]);
            }
            
        validado=le_valida_uf(uf, validado);
            
        } while (validado == 10);

        for (j = 0; j < 2; j++){
                fabricante[i].uf[j]=uf[j];
        }
        
        validado = 10;

    }
    
    numFabricantes = 2;

    do{
        printf("MAIS REGISTROS? \n");
        printf("(1)- S\n");
        printf("(2) - N\n");
        scanf("%d", &op);
        switch (op){
            case 1:
                
                //lendo de novo agora com base no numero de fabricantes, que passou de 2
                
                printf("NOME DO FABRICANTE nº%d: ", i+1);
                scanf("%s", fabricante[numFabricantes].marca);
                
                printf("SITE DO FABRICANTE nº%d: ", i+1);
                scanf("%s", fabricante[numFabricantes].site);
                
                
                printf("DDD: ");
                fabricante[numFabricantes].ddd=le_valida_positivo();
                printf("4 DIGITOS *INICIAIS* DO TELEFONE DO FABRICANTE nº%d: ", i+1);
                fabricante[numFabricantes].telPrim=le_valida_positivo();
                printf("4 DIGITOS *FINAIS* DO TELEFONE DO FABRICANTE nº%d: ", i+1);
                fabricante[numFabricantes].telSeg=le_valida_positivo();

                do{
                    printf("UF: ");
                    scanf("%s", uf);
                        
                    for (j = 0; j < 2; j++){
                        uf[j]=toupper(uf[j]);
                    }
                    
                    validado=le_valida_uf(uf, validado);
                } while (validado ==  10);
 
                for (j = 0; j < 2; j++){
                    fabricante[numFabricantes].uf[j]=uf[j];
                }
                validado = 10;

                numFabricantes++; //AUMENTA O NUIMERO DE FABRICANTES CADA VEZ QUE RODA ESSA FUNCAO
                break;

            case 2:
                limite = 5;
                break;
            
            default:
                break;
        }
    } while (numFabricantes!=5 && limite ==0);
    
    limite = 5;
    for(i=0;i<5;i++){
        printf("DESCRICAO DO PRODUTO %d: ", i+1);
        scanf("%s", produto[i].descricao);
        
        printf("NUMERO DO FABRICANTE DO PRODUTO %d: \n", i+1);

        for (j=0; j<numFabricantes; j++){
            printf("FABRICANTE nº %d: %s\n", j+1, fabricante[j].marca);
        }
        do{
            scanf("%d", &op);
            switch (op){
                case 1:
                    produto[i].fabricante=fabricante[0];
                break;

                case 2:
                    produto[i].fabricante=fabricante[1];
                break;

                case 3:
                    if (numFabricantes<3){
                        op=10;
                        break;
                    }
                    produto[i].fabricante=fabricante[2];
                break;

                case 4:
                    if (numFabricantes<4){
                        op=10;
                        break;
                    }
                    produto[i].fabricante=fabricante[3];
                break;

                case 5:
                    if (numFabricantes<5){
                        op=10;
                        break;
                    }
                    produto[i].fabricante=fabricante[4];
                break;
                
                default:
                    op=10;
                break;
            }
        } while (op==10);

        printf("PESO DO PRODUTO %d: \n", i+1);
        produto[i].peso=le_valida_positivo();

        do{
            printf("VALOR DE COMPRA DO PRODUTO %d: \n", i+1);
            scanf("%f", produto[i].valorCompra);
            
        } while (produto[i].valorCompra<0); //TEM QUE SER MAIOR QUE 0

        do{
            printf("VALOR DE VENDA DO PRODUTO %d: \n", i+1);
            scanf("%f", &produto[i].valorVenda);
            
        } while (produto[i].valorVenda<0); // TEM QUE SER MAIOR QUE 0

        produto[i].valorLucro=produto[i].valorVenda-produto[i].valorCompra;
        produto[i].percenLucro=(produto[i].valorLucro/produto[i].valorVenda)*100;
    }
    limProd=5;

    do{
        printf("MAIS REGISTROS? \n");
        printf("(1)-S\n");
        printf("(2) - N\n");
        scanf("%d", &op);
        switch (op){
            case 1:
                printf("DESCRICAO DO PRODUTO %d: ", limProd+1);
                scanf("%s", &produto[limProd].descricao);
                
                printf("INUMERO DO FABRICANTE DO PRODUTO %d: \n", limProd+1);

                for (j=0; j<numFabricantes; j++){
                    printf("FABRICANTE nº %d: %s\n", j+1, fabricante[j].marca);
                }
                do{
                    scanf("%d", &op);
                    switch (op){
                        case 1:
                            produto[limProd].fabricante=fabricante[0];
                        break;

                        case 2:
                            produto[limProd].fabricante=fabricante[1];
                        break;

                        case 3:
                            produto[limProd].fabricante=fabricante[2];
                        break;

                        case 4:
                            produto[limProd].fabricante=fabricante[3];
                        break;

                        case 5:
                            produto[limProd].fabricante=fabricante[4];
                        break;
                        
                        default:
                            op=10;
                        break;
                    }
                } while (op==10);

                printf("PESO PRODUTO %d: \n", limProd+1);
                produto[limProd].peso=le_valida_positivo();

                do{
                    printf("VALOR DE COMPRA DO PRODUTO %d: \n", i+1);
                    scanf("%f", &produto[i].valorCompra);
                } while (produto[i].valorCompra<0);// TEM QUYE PASSAR DE 0 O VALOR...

                do{
                    printf("VALOR DE VENDA DO PRODUTO %d: \n", i+1);
                    scanf("%f", &produto[i].valorVenda);
                } while (produto[i].valorVenda<0); // TEM QUYE PASSAR DE 0 O VALOR...

                produto[limProd].valorLucro=produto[limProd].valorVenda-produto[limProd].valorCompra;
                produto[limProd].percenLucro=(produto[limProd].valorLucro/produto[limProd].valorVenda)*100;
                limProd++;
                break;

            case 2:
                limite=70;
                break;
            
            default:
                break;
        }
    } while (limProd!=50 && limite ==5);

    do{
        printf("- [1] Listar todas as marcas\n");
        printf("- [2] Listar todos os produtos\n");
        printf("- [3] Listar os produtos de um determinado estado\n");
        printf("- [4] Listar os produtos de uma determinada marca\n");
        printf("- [5] Apresentar o(s) estado(s) onde esta registrado o produto mais caro\n");
        printf("- [6] Apresentar o(s) fabricante(s) onde esta registrado o produto mais barato\n");
        printf("- [7] Listar todos os produtos em ordem crescente de valor\n");
        printf("- [8] Listar todos os produtos em ordem crescente de maior \"valor do lucro\"\n");
        printf("- [9] Listar todos os produtos em ordem crescente de maior \"percentual de lucro\"\n");
        printf("- [0] Sair do programa\n");
        scanf("%d", &limite);
        
        printf("%d\n", limite);

        switch (limite){
            
            case 1:
                printf("=====================================================================\n");
                printf("            RELATORIO 1 -LISTA DE TODAS AS MARCAS\n");
                printf("=====================================================================\n");
                printf("Marca\t|\tSite\t\t|\tTelefone\t|\tUF\n");
                
                for (i = 0; i < numFabricantes; i++){
                    bufferUF[0] = '\0';
                    for (j = 0; j < 2; j++){
                    bufferUF[j]=fabricante[i].uf[j];
                    }
                    printf("--------+-----------------------+-----------------------+------------\n");
                    printf("%s\t|\t%s\t|\t(%d)%d-%d\t|\t%c%c\n", fabricante[i].marca, fabricante[i].site, fabricante[i].ddd, fabricante[i].telPrim, fabricante[i].telSeg, bufferUF[0], bufferUF[1]);
                }
                printf("--------+-----------------------+-----------------------+------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("=====================================================================\n");
                    scanf("%d", &op);
                } while (op!=9 && op!=0);
                if (op==9){
                   limite=1000;
                }
                break;
            case 2:
                printf("==================================================================================================================================================\n");
                printf("                                              RELATORIO 2 -LISTA DE TODOS OS PRODUTOS\n");
                printf("==================================================================================================================================================\n");
                printf("Descricao\t|\tMarca\t|\tpeso\t|\tV. de compra\t|\tV. de venda\t|\tLucro\t\t|\tPer. de lucro\n");

                for (i = 0; i < limProd; i++){
                    printf("------------------------+---------------+---------------+-----------------------+-----------------------+---------------+-------------------------\n");
                    printf("%s\t|\t%s\t|\t%d\t|\t%f\t|\t%f\t|\t%f\t|\t%f\n", produto[i].descricao, produto[i].fabricante.marca, produto[i].peso, produto[i].valorCompra, produto[i].valorVenda, produto[i].valorLucro, produto[i].percenLucro);
                }
                printf("------------------------+---------------+---------------+-----------------------+-----------------------+---------------+-------------------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("==================================================================================================================================================\n");
                    scanf("%d", &op);
                } while (op!=9 && op!=0);
                if (op==9){
                   limite=1000;
                }
                break;

            case 3:
                printf("=====================================================================\n");
                printf("        RELATORIO 3 -LISTA DE TODOS OS PRODUTOS DE UM ESTADO\n");
                printf("=====================================================================\n");

                do{
                    printf("Informe a UF do estado: ");
                    scanf("%s", uf);
                    
                    for (j = 0; j < 2; j++){
                        uf[j]=toupper(uf[j]);
                    }
                validado=le_valida_uf(uf, validado);
                } while (validado==10);

                printf("Marca\t|\tSite\t\t|\tUF\n");

                for (j = 0; j < 2; j++){
                    pesUF[j]=uf[j];
                }
                
                for (i = 0; i < numFabricantes; i++){
                    if (fabricante[i].uf[0]==uf[0]){
                        if (fabricante[i].uf[1]==uf[1]){
                            bufferUF[0] = '\0';
                        for (j = 0; j < 2; j++){
                        bufferUF[j]=fabricante[i].uf[j];
                        }
                        printf("--------+-----------------------+------------\n");
                        printf("%s\t|\t%s\t|\t%c%c\n", fabricante[i].marca, fabricante[i].site, bufferUF[0], bufferUF[1]);
                        }
                    }
                    
                    
                }
                printf("--------+-----------------------+------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("=====================================================================\n");
                    scanf("%d", &op);
                } while (op!=9 && op!=0);
                if (op==9){
                   limite=1000;
                }

                break;
            case 4:
                printf("=====================================================================\n");
                printf("            RELATORIO 4 -LISTA DE TODOS OS PRODUTOS DE UMA MARCA\n");
                printf("=====================================================================\n");

                printf("Informe o nome do fabricante %d: ", i+1);
                scanf("%s", pesMarca);

                printf("Marca\t|\tSite\t\t|\tUF\n");
                
                for (i = 0; i < numFabricantes; i++){
                    if (fabricante[i].marca==pesMarca){

                    printf("--------+-----------------------+------------\n");
                    printf("%s\t|\t%s\t|\t%s\n", fabricante[i].marca, fabricante[i].site, bufferUF);
                        
                    }
                }
                
                printf("--------+-----------------------+------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("=====================================================================\n");
                    scanf("%d", &op);
                } while (op!=9 && op!=0);
                if (op==9){
                   limite=1000;
                }
                break;
            case 5:
                printf("===============================================================================\n");
                printf("                  RELATORIO 5 - ESTADO DOS PRODUTOS MAIS CAROS\n");
                printf("===============================================================================\n");
                
                printf("UF\t|\tV. de venda\n");
                 for (i = 0; i < limProd; i++){
                    if (produto[i].valorVenda>precoMAIOR){
                        precoMAIOR=produto[i].valorVenda;
                    }
                    
                }

                for (i = 0; i < limProd; i++){
                    if (produto[i].valorVenda==precoMAIOR){
                        printf("--------+----------------------------------------------------------------------\n");
                        printf("%s\t|\t%f\n", produto[i].fabricante.uf, produto[i].valorVenda);
                    }
                }
                printf("--------+----------------------------------------------------------------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("===============================================================================\n");
                    scanf("%d", &op);
                } while (op!=9 && op!=0);
                if (op==9){
                   limite=1000;
                }
                
                break;
            case 6:
                printf("===============================================================================\n");
                printf("              RELATORIO 6 - FABRICANTES DOS PRODUTOS MAIS BARATOS\n");
                printf("===============================================================================\n");
                
                printf("Marca\t|\tV. de venda\n");
                for (i = 0; i < limProd; i++){
                    if (produto[i].valorVenda<precoMENOR){
                        precoMENOR=produto[i].valorVenda;
                    }
                    
                }
                
                for (i = 0; i < limProd; i++){
                    if (produto[i].valorVenda==precoMENOR){
                        printf("--------+----------------------------------------------------------------------\n");
                        printf("%s\t|\t%f\n", produto[i].fabricante.marca, produto[i].valorVenda);
                    }
                }
                printf("--------+----------------------------------------------------------------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("===============================================================================\n");
                    scanf("%d", &op);
                } while (op!=9 && op!=0);
                if (op==9){
                   limite=1000;
                }
                break;
            case 7:
                printf("==================================================================================================================================================\n");
                printf("                                              RELATORIO 7 - PRODUTOS EM ORDEM CRESCENTE DE VALOR DE VENDA\n");
                printf("==================================================================================================================================================\n");

                for(i=0;i<limProd-1;i++){
                    for(j=0;j<limProd;j++){
                        if(produto[j].valorVenda>produto[j+1].valorVenda){
                            aux = produto[j+1];
                            produto[j+1] = produto[j];
                            produto[j] = aux;
                        }
                    }
                }
                        
               printf("Descricao\t|\tMarca\t|\tpeso\t|\tV. de compra\t|\tV. de venda\t|\tLucro\t\t|\tPer. de lucro\n");
                for (i = 0; i < limProd; i++){
                    printf("------------------------+---------------+---------------+-----------------------+-----------------------+---------------+-------------------------\n");
                    printf("%s\t|\t%s\t|\t%d\t|\t%f\t|\t%f\t|\t%f\t|\t%f\n", produto[i].descricao, produto[i].fabricante.marca, produto[i].peso, produto[i].valorCompra, produto[i].valorVenda, produto[i].valorLucro, produto[i].percenLucro);
                }
                printf("------------------------+---------------+---------------+-----------------------+-----------------------+---------------+-------------------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("==================================================================================================================================================\n");
                    scanf("%d", &op);
                } while (op!=9 && op!=0);
                if (op==9){
                   limite=1000;
                }
                break;
            case 8:
                printf("==================================================================================================================================================\n");
                printf("                                         RELATORIO 8 - PRODUTOS EM ORDEM CRESCENTE DE MAIOR \"VALOR DE LUCRO\"\n");
                printf("==================================================================================================================================================\n");

                for(i=0;i<limProd-1;i++){
                    for(j=0;j<limProd;j++){
                        if(produto[j].valorLucro>produto[j+1].valorLucro){
                            aux = produto[j+1];
                            produto[j+1] = produto[j];
                            produto[j] = aux;
                        }
                    }
                }
                        
               printf("Descricao\t|\tMarca\t|\tpeso\t|\tV. de compra\t|\tV. de venda\t|\tLucro\t\t|\tPer. de lucro\n");
                for (i = 0; i < limProd; i++){
                    printf("------------------------+---------------+---------------+-----------------------+-----------------------+---------------+-------------------------\n");
                    printf("%s\t|\t%s\t|\t%d\t|\t%f\t|\t%f\t|\t%f\t|\t%f\n", produto[i].descricao, produto[i].fabricante.marca, produto[i].peso, produto[i].valorCompra, produto[i].valorVenda, produto[i].valorLucro, produto[i].percenLucro);
                }
                printf("------------------------+---------------+---------------+-----------------------+-----------------------+---------------+-------------------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("==================================================================================================================================================\n");
                    scanf("%d", &op);
                } while (op!=9 && op!=0);
                if (op==9){
                   limite=1000;
                }
                break;
            case 9:
                printf("==================================================================================================================================================\n");
                printf("                                         RELATORIO 9 - PRODUTOS EM ORDEM CRESCENTE DE MAIOR \"PERCENTUAL DE LUCRO\"\n");
                printf("==================================================================================================================================================\n");

                for(i=0;i<limProd;i++){
                    for(j=0;j<limProd;j++){
                        if(produto[j].percenLucro>produto[j+1].percenLucro){
                            aux = produto[j+1];
                            produto[j+1] = produto[j];
                            produto[j] = aux;
                        }
                    }
                }
                        
               printf("Descricao\t|\tMarca\t|\tpeso\t|\tV. de compra\t|\tV. de venda\t|\tLucro\t\t|\tPer. de lucro\n");
                for (i = 0; i < limProd; i++){
                    printf("------------------------+---------------+---------------+-----------------------+-----------------------+---------------+-------------------------\n");
                    printf("%s\t|\t%s\t|\t%d\t|\t%f\t|\t%f\t|\t%f\t|\t%f\n", produto[i].descricao, produto[i].fabricante.marca, produto[i].peso, produto[i].valorCompra, produto[i].valorVenda, produto[i].valorLucro, produto[i].percenLucro);
                }
                printf("------------------------+---------------+---------------+-----------------------+-----------------------+---------------+-------------------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("==================================================================================================================================================\n");
                    scanf("%d", &op);
                } while (op!=9 && op!=0);
                if (op==9){
                   limite=1000;
                }
                break;
            case 0:
                limite=1000;
                break;
            default:
                break;
        }
    } while (limite!=1000);
    


    return 0;
}

int le_valida_uf(char uf[], int val){ // funcao para validar a uf inserida, dos estados
    
    val = 10;
        
        if (uf[0]=='A'){
            if (uf[1]=='C'){
                val=0;
            }else if (uf[1]=='L'){
                val=0;
            }else if (uf[1]=='P'){
                val=0;
            }else if (uf[1]=='M'){
                val=0;
            }
        }else if (uf[0]=='B') {
            if (uf[1]=='A')
                val=0;
        }else if (uf[0]=='C') {
            if (uf[1]=='E')
                val=0;
        }else if (uf[0]=='D') {
            if (uf[1]=='F')
                val=0;;
        }else if (uf[0]=='E') {
            if (uf[1]=='S')
                val=0;
        }else if (uf[0]=='G') {
            if (uf[1]=='O')
                val=0;
        }else if (uf[0]=='M'){
            if (uf[1]=='A'){
                val=0;
            }else if (uf[1]=='T'){
                val=0;
            }else if (uf[1]=='S'){
                val=0;
            }else if (uf[1]=='G'){
                val=0;
            }
        }else if (uf[0]=='P'){
            if (uf[1]=='A'){
                val=0;
            }else if (uf[1]=='B'){
                val=0;
            }else if (uf[1]=='R'){
                val=0;
            }else if (uf[1]=='E'){
                val=0;
            }else if (uf[1]=='I'){
                val=0;
            }
        }else if (uf[0]=='R'){
            if (uf[1]=='J'){
                val=0;
            }else if (uf[1]=='N'){
                val=0;
            }else if (uf[1]=='S'){
                val=0;
            }else if (uf[1]=='O'){
                val=0;
            }else if (uf[1]=='R'){
                val=0;
            }
        }else if (uf[0]=='S'){
            if (uf[1]=='C'){
                val=0;
            }else if (uf[1]=='P'){
                val=0;
            }else if (uf[1]=='E'){
                val=0;
            }
        }else if (uf[0]=='T'){
            if (uf[0]=='O')
                val=0;
        }
        
        
    return val;

    
}

int le_valida_positivo(){
    int num;

    do{
        printf("Informe: ");
        scanf("%d", &num);
    } while (num<0);
    

    return num;
}
