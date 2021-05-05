#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[20];
    int senha;
    int status;
    char pedido[50];
    float valor;
    struct no *next;
} No;

//Inicio de declaração de Funções
No* criarNo();
No* inserir_no_inicio(No* Lista, char Nome[], int Senha, char Pedido[], float Valor, int Status);
void printa_Efetuados(No* Lista);
void printa_Producao(No* Lista);
void printa_Retirar(No* Lista);
No* AlteraStatus(No* Lista, int Senha, int Status);
No* excluir_Lista(No* Lista, int j);
//Fim de declaração de Funções

//Função responsavel por criar novo elemento
No* criarNo() {
    return (No*) malloc(sizeof (No)); //Aloca novo elemento
}

//Função responsavel por ionserir novo elemento no inicio da lista
No* inserir_no_inicio(No* Lista, char Nome[], int Senha, char Pedido[], float Valor, int Status) {

    No *novo_No = criarNo();
    //novo_No->nome= Nome;
    strcpy(novo_No->nome, Nome);
    novo_No->senha = Senha;
    novo_No->status = Status;
    //novo_No->pedido = Pedido;
    strcpy(novo_No->pedido, Pedido);
    novo_No->valor = Valor;

    if (Lista == NULL) { //se lista vazia

        Lista = novo_No;
        novo_No->next = NULL;

    } else {
        novo_No->next = Lista; //se lista estiver preenchida
        Lista = novo_No;
    }
    return Lista;
}

//Função responsavel por listar pedidos efetuados
void printa_Efetuados(No* Lista) {
    int count = 0; //Variavel que vai contar os elementos listados
    No *aux = Lista; //Cria elemento auxiliar que recebe lista

    while (aux != NULL) { //Percorre o aux enquanto for diferente de null
        if (aux->status == 1) { //Se o status do item atual for igual a 2 imprime ele
            count++; //Aumenta o contador
            printf(" \n Nome: %s", aux->nome); //Exibe Nome
            printf(" \n Pedido: %s", aux->pedido); //Exibe Pedido
            printf(" \n Senha: %d", aux->senha); //Exibe Senha
            printf(" \n Valor: %.2f\n\n", aux->valor); //Exibe Valor
        }
        aux = aux->next; //Pega o proximo valor
    }
    if(count < 1) //Verifica se o count é menor que 1
      printf("Sem Registros"); //Se for menor que 1 exibe a mensagem que não tem registros.
}

//Função responsavel por listar pedidos em produção
void printa_Producao(No* Lista) {
    int count = 0; //Variavel que vai contar os elementos listados
    No *aux = Lista; //Cria elemento auxiliar que recebe lista

    while (aux != NULL) { //Percorre o aux enquanto for diferente de null
        if (aux->status == 2) { //Se o status do item atual for igual a 2 imprime ele
            count++; //Aumenta o contador
            printf(" \n Pedido: %s", aux->pedido); //Exibe Pedido
            printf(" \n Senha: %d\n\n", aux->senha); //Exibe Senha
        }
        aux = aux->next; //Pega o proximo valor
    }
    if(count < 1) //Verifica se o count é menor que 1
      printf("Sem Registros"); //Se for menor que 1 exibe a mensagem que não tem registros.
}

//Função responsavel por listar pedidos prontos para serem retirados
void printa_Retirar(No* Lista) {
    int count = 0; //Variavel que vai contar os elementos listados
    No *aux = Lista; //Cria elemento auxiliar que recebe lista

    while (aux != NULL) { //Percorre o aux enquanto for diferente de null
        if (aux->status == 3) { //Se o status do item atual for igual a 3 imprime ele
            count++; //Aumenta o contador
            printf(" \n Nome: %s", aux->nome); //Exibe Nome
            printf(" \n Senha: %d\n\n", aux->senha); //Exibe Senha
        }
        aux = aux->next; //Pega o proximo valor
    }
    if(count < 1) //Verifica se o count é menor que 1
      printf("Sem Registros"); //Se for menor que 1 exibe a mensagem que não tem registros.
}

//Função responsavel por alterar o status atual do pedido
No* AlteraStatus(No* Lista, int Senha, int Status) {
    if (Lista == NULL) { //Verifica se a lista é vazia
        printf("\n Lista Vazia");
    }
    No *aux = Lista; //cria um elemento auxiliar que recebe a lista atual

    while (aux != NULL) { //Percorre enquanto aux for diferente de null
        if (aux->senha == Senha) { //Se a senha atual for a senha enviada para ser alterada
            aux->status = Status; //Altera o status atual pelo novo status
        }
        aux = aux->next; //Pega o proximo valor
    }
    return Lista; //Retorna a lista
}

//Função responsavel por retirar pedido da lista quando o usuário retirar ele
No* excluir_Lista(No* Lista, int j) {

    No *anterior, *atual;

    if (Lista == NULL) {

        printf("\n Lista vazia!");
    } else {
        anterior = Lista;
        atual = Lista;
        while (atual != NULL) {
            if (atual->senha == j) {

                if (atual == Lista) {
                    Lista = Lista->next;
                    printf("valor excluido: %d ", j);
                    free(atual);
                    break;

                } else {

                    anterior->next = atual->next; // DUVIDA SE NAO FUNCIONAR TENTAR Lista->Lista->Next
                    printf("valor excluido: %d ", j);
                    free(atual);
                    break;

                }

            } else {
                anterior = atual;
                atual = atual->next;
            }
        }
    }
    return Lista;
}
