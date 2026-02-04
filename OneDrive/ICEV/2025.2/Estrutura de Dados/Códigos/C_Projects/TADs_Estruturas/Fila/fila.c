#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include "../ultil/escolha.h"


TFila* criarFila(){
	TFila *nova = (TFila*) malloc(sizeof(TFila));
	
	if(nova != NULL){
		nova->tail = NULL;
		nova->head = NULL;
	}
	return nova;
}

void liberarFila(TFila *fila){
	TNo *aux;
	while(fila->tail != NULL)
	{
		aux = fila->tail;
		fila->tail = fila->tail->prox;
		free(aux);
	}
	free(fila);	
}

int tamanhoFila(TFila *fila){
	
	TNo *aux = fila->tail;
	int cont = 0;
	while (aux != NULL){
		cont++;
		aux = aux->prox;
	}
	return cont;
}

int inserirFila(TFila *fila, int info){
	
	if(fila == NULL){
		return 0;
	}
	else if(fila->tail==NULL)
	{
		TNo *novoNo = (TNo*)malloc(sizeof(TNo));
		fila->tail = novoNo;
		fila->head = novoNo;
		fila->tamanho++;
		return 1;
	}
	else
	{
		TNo *novoNo = (TNo*)malloc(sizeof(TNo));
		fila->tail->prox = novoNo;
		fila->tail = novoNo;
		fila->tamanho++;
		return 1;
	}
}

int retirarFila(TFila *fila){
	TNo *aux;
	
	if(fila == NULL || fila->head == NULL){
		return 0;
	}
	else if(fila->tail == fila->head)
	{
		aux = fila->head;
		fila->tail = NULL;
		fila->head = NULL;
		free(aux);
		fila->tamanho--;
		return 1;
	}
	else
	{
		aux = fila->head;
		fila->head = fila->head->prox;
		free(aux);
		fila->tamanho--;
		return 1;
	}
}

int imprimir(TFila *fila){
	if(fila->head == NULL){
		return 0;
	}
	else
	{
		TNo *aux = fila->head;
		int i = 0;
        while (aux != NULL){
		printf("Elemento: %d -- Posição: %d \n", aux->info, i);
		aux = aux->prox;
		i++;
	    }
		return 1;	
	}
}

void menuFila(){
	int valor;
	int posicao;
	int tam;
	TFila *fila = NULL;
	TEscolha *escolha;
	do{
		
		escolha = iniciarEscolha();
		
		printf("Digite a operação \n");
		printf("1. Criar Fila \n");
		printf("2. Inserir elemento  \n");
		printf("3. Remover elemento  \n");
		printf("4. Imprimir tamanho da fila  \n");
		printf("5. Imprimir fila  \n");
		printf("0. Sair \n");
		
		scanf("%d", &valor);
		setEscolha(escolha, valor);
		
		switch (getEscolha(escolha)) {
			case 0:
				system("clear");
				printf("Voltando ao menu principal \n");
				escolha->encerrar = 0;
				
				break;
			case 1:
				system("clear");
				fila = criarFila();
				if(fila != NULL){
					printf("Fila criada com sucesso \n");
					}
					else
					{
						printf("erro ao criar fila \n");
					}
				break;
			case 2:
				system("clear");
				printf("Digite o valor inserido \n");
				scanf("%d", &valor);
				setEscolha(escolha, valor);
				inserirFila(fila, getEscolha(escolha));
				if(inserirFila(fila, getEscolha(escolha)) == 0){
					printf("Falha ao inserir elemento");
				}else
				{
					printf("Elemento inserido com sucesso");
				}
				break;
			case 3:
				system("clear");
				retirarFila(fila);
				if(retirarFila(fila) == 0){
					printf("Não foi possível retirar da fila \n");
				}else
				{
					printf("Elemento inicial retirado com sucesso \n");
				}
				break;
			case 4:
				system("clear");
				tam = tamanhoFila(fila);
				printf("A fila possui tamanho %d \n", tam);
				break;
			case 5:
				system("clear");
				imprimir(fila);
				break;
			default:
				printf("Escolha inválida, tente outro número");
				break;
		}

	}while(escolha->encerrar != 0);
	
		
	
}