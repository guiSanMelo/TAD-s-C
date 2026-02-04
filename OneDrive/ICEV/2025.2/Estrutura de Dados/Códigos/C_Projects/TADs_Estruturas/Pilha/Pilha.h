#ifndef PILHA_H
#define PILHA_H
#include "../0.No/No.h"
typedef struct 
{
	TNo *top;
	int tamanho;
}TPilha;


TPilha* criarPilha();

int inserirPilha(TPilha *pilha, int info);

int removerPilha(TPilha *pilha);

int tamanhoPilha(TPilha *pilha);

int pilhaVazia(TPilha *pilha);

int liberarPilha(TPilha *pilha);

void menuPilha();










#endif