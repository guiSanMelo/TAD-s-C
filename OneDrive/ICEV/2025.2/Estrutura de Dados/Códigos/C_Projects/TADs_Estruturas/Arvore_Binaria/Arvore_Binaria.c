#include "Arvore_Binaria.h"
#include "../0.No/No.h"
#include "../ultil/escolha.h"
#include <stdlib.h>
#include <stdio.h>

 


void emOrdem(TNoAvore *no){
	if(raiz !=NULL){
		emOrdem(no->esq);
		printf("\n Elemento %d", raiz->elemento.valor);
		emOrdem(no->dir);
	}
}

void preOrdem(TNoAvore *no){
	if(raiz != NULL){
		printf("\n Elemento %d", raiz->elemento.valor);
		preOrdem(no->esq);
		preOrdem(no->dir);
	}
}

void posOrdem(TNoAvore *no){
	if(raiz != NULL){
		posOrdem(no->esq);
		posOrdem(no->dir);
		printf("\n Elemento: %d", raiz->elemento.valor);
	}
}



TArvore_Binaria* criarArvore(){
		TArvore_Binaria *nova =(TArvore_Binaria*)malloc(sizeof(TArvore_Binaria));
		if(nova != NULL){
			nova->raiz=NULL;
			
		}
		return nova;
	} 

int arvoreVazia(TArvore_Binaria *arvore){
	if(arvore->raiz == NULL){
		return 1;
	}
	else
	{
		return 0;
	}
}

int inserirArvore(TArvore_Binaria *arvore, int num){
	
	if(arvore == NULL){
		return 0
	}
	TNoAvore *novoNo = (TNoAvore*) malloc(sizeof(TNoAvore));
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	novoNo->elemento->valor = num;
		
	if (arvoreVazia(arvore) == 1){
	
		novoNo->esq = NULL;
		novoNo->dir = NULL;
		novoNo->elemento->valor = elemento;
	}
	else
	{
			TNoAvore *atual = arvore->raiz;
			TNoAvore *ant = NULL;
			
			while(atual != NULL)
			{
				ant = atual;
				if(num == atual->elemento->valor){
					return 0;
				}
				else if(elemento->valor > atual->elemento->valor){
					atual = atual->dir;
				}
				else
				{
					atual = atual->esq;
				}
			}
			if(num > ant->elemento)
			{
				ant->dir = novoNo;
			}
			else
			{
				ant->esq = novoNo;
			}
			return 1;	
	}
}



int removeArvore(TArvore_Binaria *arvore, int valor){
	if(arvoreVazia() == 1){
		return 0;
	}
	TNoAvore* ant = NULL;
	TNoAvore* remove = arvore->raiz;
	
	while(remove != NULL)
	{
		if(valor == remove->elemento.valor){
			if (remove == arvore->raiz){
				arvore->raiz = removeNo(remove);
			}
			else
			{
				if(remove == ant->dir){
					ant->dir = removeNo(remove);
				}
				else
				{
					ant->esq = removeNo(remove);
				}
			}
			return 1;
		}
		else
		{
			ant = remove;
			if(valor > remove->elemento.valor){
				remove = remove->dir;
			}
			else
			{
				remove = remove->dir;
			}
		}
	}
	return 0;
}

TNoAvore* removeNo(TNoAvore *remove){
	TNoAvore *no1, *no2;
	if (remove->esq == NULL){ //Se não tiver filho à esquerda
		no2 = remove->dir;
		free(remove);
		return no2;
	}
	no1 = remove;
	no2 = remove->esq;
	while(no2->dir != NULL)
	{
		no1 = no2;
		no2 = no2->dir;
	}
	if(no1 != remove){
		no1->dir = no2->esq;
		no2->esq = remove->esq;
	}
	no2->dir = remove->dir;
	free(remove);
	return no2;
}


void menuArvore(){
	
}
