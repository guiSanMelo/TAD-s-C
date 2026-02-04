#include <stdlib.h>
#include <stdio.h>
#include "escolha.h"

TEscolha* iniciarEscolha(){
	TEscolha *escolha = (TEscolha*) malloc(sizeof(TEscolha));
	
	if(escolha == NULL){
		printf("Falha ao inicializar escolha");
		return NULL;
	}
	
	escolha->opcao = 1;
	escolha->check = true;
	escolha->encerrar = 1;
	
	return escolha;
}



void setEscolha(TEscolha *escolha, int valor){
	if(escolha != NULL){
		escolha->opcao = valor;	
	}
}

int getEscolha(TEscolha *escolha){
	if (escolha == NULL){
		return -1;
	} 
	return escolha->opcao;
}

void setCheck(TEscolha *escolha, bool valor){
    if(escolha != NULL){  // Adicionei verificação de NULL
        escolha->check = valor;
    }
}

bool getCheck(TEscolha *escolha){
	if (escolha == NULL){
		return false;
	} 
	return escolha->check;
}