#include <stdio.h>
#include "lista_estatica.h"


void criarLista(TLista_Estatica *lista){
	lista->prim = 0;
	lista->ult = 0;
	lista->tamanho = 0;
}

void inserirInicio(){
	
}


int inserirFinal(TLista_Estatica *lista, int elemento){
	lista->itens[lista->ult] = elemento;
	
	lista->ult = lista->ult +1;
	
	
	lista->tamanho = lista->tamanho++;
	
	return 1;
}

int inserirMeio(TLista_Estatica *lista, int elemento, int posicao){
	
	if(lista->tamanho == TAMANHO_MAX){
		printf("Lista cheia \n");
		return 0;
	}
	int i;
	for (i = lista->tamanho-1; i >= posicao; i--){
		lista->itens[i+1] = lista->itens[i];
	}
	
	lista->itens[posicao] = elemento;
	lista->tamanho++;
	
	return 1;
}


void imprimirLista(TLista_Estatica *lista){
	int i;
	for ( i = lista->prim; i = lista->ult; i++){
		printf("Posição %d: %d", i , lista->itens[i]);
	}
}


