#ifndef ESCOLHA_H
#define ESCOLHA_H

#include <stdbool.h>

typedef struct 
{
	int opcao;
	bool check;
	int encerrar;
}TEscolha;

TEscolha* iniciarEscolha();

void setEscolha(TEscolha *escolha, int valor);

int getEscolha(TEscolha *escolha);

void setCheck(TEscolha *escolha, bool valor);

bool getCheck(TEscolha *escolha);

#endif