#include <stdlib.h>
#include <stdio.h>
#include "../ultil/escolha.h"
#include "Lista_Dinamica.h"
#include "../0.No/No.h"


TLista_Din* CriarLista(){
	TLista_Din *novalista = (TLista_Din*) malloc(sizeof(TLista_Din));
	
	if(novalista == NULL){
		printf("Nova lista não criada");
		return NULL;
	}
	
	novalista->tamanho = 0;
	novalista->prim = NULL;
	novalista->ultm = NULL;
	
	return novalista;
};

int InserirInicio(TLista_Din *lista, int infoData){
	
	TNo *novoNo = (TNo*) malloc(sizeof(TNo));
	novoNo->info = infoData;
	
	if(lista == NULL){
		printf("Lista não criada ainda, não é possível inserir");
		return 0;
	}
	else if(novoNo == NULL)
	{
		printf("Novo nó não foi criado!");
		return 0;
	}
	
	else if(lista->prim == NULL){
		lista->prim = novoNo;
		lista->ultm = novoNo;
		lista->tamanho = lista->tamanho++;
		novoNo->prox = NULL;
		return 1;
	  }	
	else
	{
		novoNo->prox = lista->prim;
		lista->prim = novoNo;
		return 1;
	}
	
};

int inserirFinal(TLista_Din *lista, int infoData){
	
	TNo *novoNo = (TNo*) malloc(sizeof(TNo));
	novoNo->info = infoData;
	
	if(lista->prim == NULL){
		lista->prim = novoNo;
		lista->ultm = novoNo;
		lista->tamanho = lista->tamanho++;
		novoNo->prox = NULL;
		return 1;
	  }
	else
	  {
		lista->ultm->prox = novoNo;
		novoNo->prox = NULL;
		lista->ultm = novoNo;
	  }	
};


int inserirMeio(TLista_Din *lista, int infoData){
	
}


void imprimirLista(TLista_Din *lista){
	TNo *aux = lista->prim;
	int i = 0;
	while(aux != 0)
	{
		printf("Elemento &d: &d", i, aux->info);
		aux = aux->prox;
		i++;
	}
};


int removerInicio(TLista_Din *lista){
	
	if(lista == NULL){
		printf("Lista não criada");
		return 0;
	}
	if(lista->prim == NULL){
		printf("Lista vazia");
		return 0;
	}
	else
	{
		TNo *NoRemove = lista->prim;
    	lista->prim = lista->prim->prox;	
		free(NoRemove);
	    return 1;
	   }
};

int removerFinal(TLista_Din *lista) {
    if (lista == NULL || lista->prim == NULL) {
        printf(lista == NULL ? "Lista nao criada\n" : "Lista vazia\n");
        return 0;
    }
    
    TNo *ultimo = lista->ultm;
    
    // Se só tem um elemento
    if (lista->prim == ultimo) {
        free(ultimo);
        lista->prim = NULL;
        lista->ultm = NULL;
        return 1;
    }
    
    // Precisa achar o penúltimo
    TNo *penultimo = lista->prim;
    while (penultimo->prox != ultimo) {
        penultimo = penultimo->prox;
    }
    
    penultimo->prox = NULL;
    lista->ultm = penultimo;
    free(ultimo);
    
    return 1;
}



void menuListaDinamica(){
	int valor;
	TLista_Din *lista = NULL;
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
		printf("7. Imprimir a lista dinâmica \n");
		printf("0. Sair \n");
		
		scanf("%d", &valor);
		setEscolha(escolha, valor);
		
		switch (escolha->opcao) {
			case 0:
				
				printf("Voltando ao menu principal \n");
				escolha->encerrar = 0;
				
				break;
			case 1:
					
				lista = CriarLista();
				
				break; 
			case 2:
				 
				printf("Digite o valor inserido: ");
				scanf("%d", &valor);
				InserirInicio(lista, valor);
				
        		break;
			case 3:
				
				break;
			case 4:
				
				printf("Digite o valor a ser inserido");
				scanf("%d", &valor);
				inserirFinal(lista, valor);
				
			default:
				printf("Escolha inválida, tente outro número");
				break;
		}

	}while(escolha->encerrar != 0);
}



