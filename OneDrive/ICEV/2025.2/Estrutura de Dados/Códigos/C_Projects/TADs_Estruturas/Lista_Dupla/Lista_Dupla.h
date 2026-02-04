#ifndef LISTA_DUPLA_H 
#define LISTA_DUPLA_H
#include "../0.No/No.h"

typedef struct 
{
	TNo *prim;
	int tamanho;
} TListaDupla;

TListaDupla* criarListaDupla(); 

int inserirInicio(TListaDupla* lista, int info);

int inserirFinal(TListaDupla* lista, int info);

int inserirMeio(TListaDupla* lista, int info, int posicao);

int gerarValoresAutomaticos(TListaDupla* lista);

int remocaoInicio(TListaDupla* lista);

int remocaoMeio(TListaDupla* lista, int posicao);

int remocaoFinal(TListaDupla* lista);

int inverte(TListaDupla *lista1, TListaDupla *lista2);


int apagarLista(TListaDupla* lista);

void imprimirLista(TListaDupla* lista);

void menuListaDupla();

#endif