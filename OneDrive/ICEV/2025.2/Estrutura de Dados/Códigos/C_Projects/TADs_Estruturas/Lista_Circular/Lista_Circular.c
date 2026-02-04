#include <stdlib.h>
#include <stdio.h>
#include "Lista_Circular.h"
#include "../No/No.h"
TLista_Circular* criarLista(){
	
	TLista_Circular *novaLista = (TLista_Circular*) malloc(sizeof(TLista_Circular));
	if( novaLista == NULL ){
		novaLista->prim = NULL;
		novaLista->tamanho = 0;
	}
	else
	{
		printf("Não foi possível criar a lista");
	}
	
	return novaLista;
}

int inserirInicio(TLista_Circular *lista, int info){
	if(lista == NULL){
		printf("Lista Vazia \n");
		return 0;
	}
	else
	{
		TNo *novoNo = (TNo*) malloc(sizeof(TNo));
		novoNo->info = info;
		if(lista->prim == NULL){
			lista->prim = novoNo;
			novoNo->prox = novoNo;
			lista->tamanho++;
			return 1;
		}
		
		TNo *aux = lista->prim;
		while(aux->prox != lista->prim)
		{
			aux = aux->prox;
		}
		
		aux->prox = novoNo;
		novoNo->prox = lista->prim;
		lista->prim = novoNo;
		lista->tamanho++;
		return 1;
	}   
		
	return 0;
}


int removeInicio(TLista_Circular *lista){
	if(lista->prim == NULL){
		return 0;
	}
	else if (lista->prim->prox == lista->prim){
		free(lista->prim);			  
		lista->prim = NULL;
		lista->tamanho--;
		return 1;
	}
	else
	{
		TNo *aux = lista->prim;
		while(aux->prox != lista->prim)
		{
			aux = aux->prox;
		}
		TNo *remove = lista->prim;
		aux->prox = remove->prox;
		lista->prim = remove->prox;
		free(remove);
		lista->tamanho--;
		return 1;
	}
	return 0;
}

int removeFinal(TLista_Circular *lista){
		if(lista->prim == NULL){
		return 0;
	}
	else if (lista->prim->prox == lista->prim){
		free(lista->prim);			  
		lista->prim = NULL;
		lista->tamanho--;
		return 1;
	}
	else
	{
		TNo *remove = lista->prim;
		TNo *anterior;
		while(remove->prox != lista->prim)
		{
			anterior = remove;
			remove = remove->prox;
		}
		
		anterior->prox = remove->prox;
		free(remove);
		lista->tamanho--;
		return 1;
	}
	return 0;	
}



void imprimirLista(TLista_Circular *lista){
	TNo *aux = lista->prim;
	int i = 0;
	while(aux->prox != lista->prim){	
		printf("Elemento %d, posição: &d \n", aux->info, i);
		i++;
		aux = aux->prox;
	}

}