  #ifndef ARVORE_H
#define ARVORE_H
#include "../0.No/No.h"
#include <stdlib.h>

 
typedef struct 
{
	TNoAvore *raiz;
}TArvore_Binaria;

void emOrdem(TNoAvore *no);

void preOrdem(TNoAvore *no);

void posOrdem(TNoAvore *no);


TArvore_Binaria* criarArvore();

int arvoreVazia(TArvore_Binaria *arvore;

int inserirArvore(TArvore_Binaria *arvore, int elemento);

int removeArvore(TArvore_Binaria *arvore, int valor);

TNoAvore* removeNo(TNoAvore *remove);

void menuArvore();

#endif