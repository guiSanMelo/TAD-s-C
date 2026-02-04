#ifndef FILA_H
#define FILA_H
#include "../0.No/No.h"
typedef struct 
{
	TNo *head;
	TNo *tail;
	int tamanho;
}TFila;



TFila* criarFila(); 

void liberarFila(TFila *fila);

int tamanhoFila(TFila *fila);

int inserirFila(TFila *fila, int info);

int retirarFila(TFila *fila);

int imprimir(TFila *fila);

void menuFila();


#endif