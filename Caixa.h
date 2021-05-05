#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    float valor;
    struct node *prox;
} caixa;

int tam;

//Inicio de declaração de Funções
void InicializaCaixa(caixa *Caixa);
void MostraCaixa(caixa *Caixa);
caixa *AlocaElemento();
int VerificaVazio(caixa *Caixa);
void FinalizaCaixa(caixa *Caixa);
void InsereValorCaixa(caixa *Caixa, float v);
//Fim de declaração de Funções

// Fução responsavel por inicializar o caixa
void InicializaCaixa(caixa *Caixa) {
    Caixa->prox = NULL;
    tam = 0;
}

// Função responsavel por verificar se o caixa está vazio
int VerificaVazio(caixa *Caixa) {
    if (Caixa->prox == NULL) //Verifica se o caixa é nulo
        return 1;
    else
        return 0;
}

// Função responsavel por alocar e retornar novo elemento que será inserido no caixa
caixa *AlocaElemento() {
    caixa *novo = (caixa *) malloc(sizeof (caixa)); //Aloca elemento
    return novo; //Retorna elemento alocado
}



// Função resonsavel por listar todos os elementos armazenados no caixa
void MostraCaixa(caixa *Caixa) {
    int count = 0;

    if (VerificaVazio(Caixa)) { //Verifica se o caixa está vazio
        printf("O Caixa esta vazio!\n\n");
        return;
    }

    caixa* tmp; //Cria um elemento caixa temporario
    tmp = Caixa->prox; //Atribui ao elemento temporario o caixa com os dados

    while (tmp != NULL) { //Laço que percorre o caixa temporario
        count++;
        printf("\nID: %d\n", count);
        printf("Valor: %.2f\n\n", tmp->valor); //Exibe o valor inserido nessa posição
        tmp = tmp->prox; //Passa para a proxima posição
    }
}


// Função responsavel por finalizar o caixa e liberar toda a memoria alocada
void FinalizaCaixa(caixa *Caixa) {
    if (!VerificaVazio(Caixa)) { //Verifia se o caixa está diferente de vazio
        caixa *proxNode, *atual; //Declara Variaveis auxiliares

        atual = Caixa->prox; //Atribui a atual o primeiro valor do caixa
        while (atual != NULL) { //Verifica se chegou no final
            proxNode = atual->prox; //Pega o proximo valor a liberar
            free(atual); //Libera o atual
            atual = proxNode; //Atribui ao atual o proximo
        }
    }
}

// Função responsavel por inserir um novo elemento no caixa
void InsereValorCaixa(caixa *Caixa, float v) {
    caixa *novo = AlocaElemento(); //Chama função que aloca novo elemento
    novo->valor = v; //atribui ao novo o valor a ser inserido
    novo->prox = NULL; //atribui ao prox o valor null

    if (VerificaVazio(Caixa)) //verifica se o caixa esta vazio
        Caixa->prox = novo; //Se estiver vazio insere o elemento
    else {
        caixa *tmp = Caixa->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
    tam++;
}
