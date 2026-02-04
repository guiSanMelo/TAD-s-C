#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
#include "../0.No/No.h"
typedef struct 
{
	int tamanho;
	TNo *prim;
}TLista_Circular;


TLista_Circular* criarLista();

int inserirInicio(TLista_Circular *lista, int info);

int removeInicio(TLista_Circular *lista);

int removeFinal(TLista_Circular *lista);








#endif

