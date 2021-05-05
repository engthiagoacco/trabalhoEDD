/*
Trabalho de Estrutura de Dados
Tema: Sistema que simula de forma simples o atendimento e as etapas da confecção do pedido, seguindo desde o pedido até a retirada dele após pronto.
Aluno: Thiago Leite de Oliveira Acco
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pedido.h"
#include "Caixa.h"

int main() {
    //Inicio de declaração de variaveis
    char Nome[20], Pedido[50];
    int Senha = 0, Status, op, SenhaRetirada, SenhaAlterar;
    float Valor;
    //Fim de declaração de variaveis

    caixa *Caixa = (caixa *) malloc(sizeof (caixa));
    No *Lista = NULL;

    InicializaCaixa(Caixa);

    //Inicio do Menu
    do {
        system("cls");
        printf("=========== Pedidos Efetuados ================\n");
        printa_Efetuados(Lista);
        printf("\n=============================================");

        printf("\n\n=========== Pedidos Em Producao ==============\n");
        printa_Producao(Lista);
        printf("\n==============================================\n");

        printf("\n\n=========== Pedidos Para Retirar =============\n");
        printa_Retirar(Lista);
        printf("\n==============================================\n");

        printf("\n\n-------- Menu do Caixa --------\n");
        printf("1 - Inserir Novo Pedido\n");
        printf("2 - Pedido Retirado\n");
        printf("3 - Finalizar Caixa\n");
        printf("\n\n-------- Menu da Cozinha --------\n");
        printf("4 - Iniciar Producao do Pedido\n");
        printf("5 - Pedido Finalizado\n\n");

        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: //Inserir Pedido
                printf("Nome: ");
                fflush(stdin);
                gets(Nome); // Pega o nome do cliente

                printf("Pedido: ");
                fflush(stdin);
                gets(Pedido); // Pega o pedido

                printf("Valor: ");
                scanf("%f", &Valor); // Pega o valor

                Senha++; //Cria uma senha nova
                Lista = inserir_no_inicio(Lista, Nome, Senha, Pedido, Valor, 1); //Insere o Pedido na lista
                InsereValorCaixa(Caixa, Valor); //Insere o valor pago pelo pedido no caixa
                break;
            case 2: //Pedido Retirado
                printf("Senha do Pedido: ");
                scanf("%d", &SenhaRetirada); // Pega senha do pedido a ser retirado
                Lista = excluir_Lista(Lista, SenhaRetirada); //Retira da lista o pedido retirado
                break;

            case 3: //Finalizar Caixa
                MostraCaixa(Caixa); // Mostra os valores do caixa
                FinalizaCaixa(Caixa); //Finaliza o caixa
                printf("\n");
                system("pause");
                op = 0; //Sai do menu
                break;

            case 4: //Pedido em Produção
                printf("Senha do Pedido: ");
                scanf("%d", &SenhaAlterar); // Pega a senha a ser alterada
                AlteraStatus(Lista, SenhaAlterar, 2); //Altera o status da senha passada para 2
                break;

            case 5: //Pedido Finalizado
                printf("Senha do Pedido: ");
                scanf("%d", &SenhaAlterar); // Pega a senha a ser alterada
                AlteraStatus(Lista, SenhaAlterar, 3); //Altera o status da senha passada para 3
                break;
			case 0: //Finalizar Programa
				op = 0;
				break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (op != 0);
    //Fim do Menu

    free(Caixa); //Libera o caixa
    return 0;
}
