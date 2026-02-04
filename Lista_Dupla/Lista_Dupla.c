#include "Lista_Dupla.h"
#include "../ultil/escolha.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



TListaDupla* criarListaDupla(){
	TListaDupla *novaLista = (TListaDupla*) malloc(sizeof(TListaDupla));
	
	if(novaLista == NULL){
		return NULL;
	}
	
	novaLista->prim = NULL;
	novaLista->tamanho = 0;
	return novaLista;
};

int inserirInicio(TListaDupla* lista, int info){	
	
	if (lista == NULL){
		
		return 0;
	}
	
	TNo *novoNo = (TNo*) malloc(sizeof(TNo));
	novoNo -> info = info;
	
	if(lista->prim == NULL){
		lista->prim = novoNo;
		novoNo->prox = NULL;
		novoNo->ant = NULL;
		lista->tamanho = lista->tamanho++;
		return 1;
	}	
	
	else
	{
		novoNo->prox = lista->prim;
		lista->prim->ant = novoNo;
		lista->prim = novoNo;
		novoNo->ant = NULL;
		lista->tamanho = lista->tamanho++;
		return 1;
	}
	return 0;
}

int inserirMeio(TListaDupla* lista, int info, int posicao){
	
	if(lista == NULL){
		printf("Vazia \n");
		return 0;
	}
	
	else if(posicao >= lista->tamanho+1){
		printf("Posição fora da lista \n");
		return 0;
	}
	
	else if(posicao==0){
		inserirInicio(lista, info);
		return 1;
	}
	
	else if(posicao == lista->tamanho)
	{
		inserirFinal(lista, info);
		return 1;
	}
	
	else
	{
		TNo *novoNo = (TNo*) malloc(sizeof(TNo));
		novoNo->info = info;
		TNo *aux;
		int cont = 0;
		
		while(cont < posicao - 1)
		{
			aux = aux->prox;
			cont++;
		}
		
		novoNo->prox = aux->prox;
		novoNo->ant = aux;
		aux->prox->ant = novoNo;
		aux->prox = novoNo;
	
		lista->tamanho++;
		
	}
	
	return 1;
}

int inserirFinal(TListaDupla* lista, int info){
	TNo *novoNo = (TNo*) malloc(sizeof(TNo));

	if (lista == NULL){
		printf("Lista inesistente \n");
		return 0;
	}
	else
	{
		
		TNo *aux = lista->prim;
		while (aux->prox != NULL){
			aux = aux->prox;
		}
		
		aux->prox = novoNo;
		novoNo->ant = aux;
		novoNo->prox = NULL;
		lista->tamanho = lista->tamanho++;
		return 1;
	}
	return 0;
}

int remocaoInicio(TListaDupla* lista){
	
	if (lista->prim == NULL || lista == NULL){
		return 0;
	}
	
	TNo *remove = lista->prim;
	lista->prim = remove->prox;
	
	if (remove->prox != NULL){
		remove->prox->ant = NULL;
	}
	
	free(remove);
	
	return 1;
	
}

int remocaoFinal(TListaDupla* lista){
	if (lista->prim == NULL || lista == NULL){
		return 0;
	}
	
	TNo *remove = lista->prim;
	
	while(remove->prox != NULL)
	{
		remove = remove->prox;
	}
	
	if(remove->ant == NULL){
		lista->prim = remove->prox;
	}
	else
	{
		remove->ant->prox = NULL;
	}
	
	free(remove);
	return 1;
}

int gerarValoresAutomaticos(TListaDupla* lista){
	int i;
	srand(time(NULL));
	if(lista == NULL){
		return 0;
	}
	else{
	for(i = 0; i = 5; i++){
		int a = rand() % 50;
		if(lista->tamanho == 0){
			inserirInicio(lista, a);
		}
		else
		{
			 inserirFinal(lista, a);	
		}
	}
	return 1;
	}	
}


int inverte(TListaDupla *lista1, TListaDupla *lista2){
	TNo *aux = lista1->prim;
	while(aux != NULL)
	{
		inserirInicio(lista2, aux->info);
		aux= aux->prox;
	}
	return 1;
}



void imprimirLista(TListaDupla* lista){
	TNo *aux = lista->prim;
	int posicao = 0;
	while(aux != NULL){
		printf("Elemento: %d -- Posição: %d", aux->info, posicao);
		aux = aux->prox;
		posicao++;
	}
}


void menuListaDupla(){
	int valor;
	int posicao;
	TListaDupla *lista = NULL;
	TEscolha *escolha;
	do{
		
		escolha = iniciarEscolha();
		
		printf("Digite a operação \n");
		printf("1. criarLista \n");
		printf("2. inserir valor no início \n");
		printf("3. inserir valor na posição N \n");
		printf("4. inserir valor no final \n");
		printf("5. Remover o valor inicial \n");
		printf("6. Remover o valor final \n");
		printf("7. Imprimir a lista Duplamente Encadeada \n");
		printf("8. Gerar valores automáticos (5/vez)\n");
		printf("0. Sair \n");
		
		scanf("%d", &valor);
		setEscolha(escolha, valor);
		
		switch (escolha->opcao) {
			case 0:
				
				printf("Voltando ao menu principal \n");
				escolha->encerrar = 0;
				
				break;
			case 1:
				system("clear");	
				lista = criarListaDupla();
				
				break; 
			case 2:
				system("clear"); 
				printf("Digite o valor inserido: \n");
				scanf("%d", &valor);
				inserirInicio(lista, valor);
				
        		break;
			case 3:
				system("clear");
				printf("Digite o item e a posição a ser inserida (X X) \n");
				scanf("%d %d", &valor, &posicao);
				inserirMeio(lista, valor, posicao);
				break;
			case 4:
				system("clear");
				printf("Digite o valor a ser inserido \n");
				scanf("%d", &valor);
				inserirFinal(lista, valor);
				break;
			case 5:
				printf("EM OBRAS");
				break;
			case 6:
				printf("EM OBRAS");
				break;
			case 7:
				imprimirLista(lista);
				break;
			case 8:
				gerarValoresAutomaticos(lista);
				break;
			default:
				printf("Escolha inválida, tente outro número \n");
				break;
		}

	}while(escolha->encerrar != 0);
}




