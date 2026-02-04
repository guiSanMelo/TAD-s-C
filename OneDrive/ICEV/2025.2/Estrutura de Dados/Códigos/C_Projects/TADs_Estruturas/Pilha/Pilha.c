#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"
#include "../ultil/escolha.h"


TPilha* criarPilha(){
	TPilha *novaPilha = (TPilha*) malloc(sizeof(TPilha));
	
	if(novaPilha != NULL){
		novaPilha->top == NULL;
		novaPilha->tamanho == NULL;
	}
	return novaPilha;
}

int inserirPilha(TPilha *pilha, int info){
	
	if(pilha == NULL){
		return 0;
	}
	else if (pilhaVazia(pilha) == 1){
		TNo *novoNo = (TNo*) malloc(sizeof(TNo));
		novoNo->info = info;
		novoNo->prox = NULL;
		pilha->top = novoNo;		
		return 1;
	}
	else
	{
		TNo *novoNo = (TNo*) malloc(sizeof(TNo));
		novoNo->info = info;
		novoNo->prox = pilha->top;
		pilha->top = novoNo;
		return 1;
	}
}

int removerPilha(TPilha *pilha){
	
	if(pilhaVazia(pilha) == 1){
		return 0;
	}
	else if(pilha->top == NULL)
	{
		TNo *remove = pilha->top;
		pilha->top = NULL;
		free(remove);
		return 1;
	}
	else
	{
		TNo *remove = pilha->top;
		pilha->top = remove->prox;
		free(remove);
		return 1;
	}
}

int tamanhoPilha(TPilha *pilha){
	
	int cont = 0;
	TNo *aux = pilha->top;
	
	while(aux->prox != NULL)
	{
		aux = aux->prox;
		cont++;
	}
	return cont;	
}

int pilhaVazia(TPilha *pilha){
	
	if(pilha->top == NULL){
		return 1;
	}
	else
	{
		return 0;
	}
}

int liberarPilha(TPilha *pilha){
	if(pilha != NULL){
		
		TNo *aux;
		while(pilha->top != NULL)
		{
			aux = pilha->top;
			pilha->top = pilha->top->prox;
			free(aux);
		}
		free(pilha);
		return 1;
	}
	return 0;
}


void menuPilha(){
	int valor;
	TPilha *pilha = NULL;
	TEscolha *escolha;
	do{
		
		escolha = iniciarEscolha();
		
		printf("Digite a operação \n");
		printf("1. Criar Pilha\n");
		printf("2. Inserir valor no topo\n");
		printf("3. Remover o valor inicial \n");
		printf("4. Imprimir a Pilha \n");
		printf("5. Mostrar valor no topo atual \n");
		printf("6. Apagar a pilha \n");
		printf("7. Gerar valores automáticos (5/vez)\n");
		printf("0. Sair \n");
		
		scanf("%d", &valor);
		setEscolha(escolha, valor);
		
		switch (escolha->opcao) {
			case 0:
				
				printf("Voltando ao menu principal \n");
				escolha->encerrar = 0;
				
				break;
			case 1: 
				
				break;
			case 2: 
				
				break;
			case 3: 
				
				break;
			case 4: 
				
				break;
			case 5: 
				
				break;
			default:
				printf("Escolha inválida, tente outro número");
				break;
		}

	}while(escolha->encerrar != 0);

}










