#include "../0.No/No.h"

typedef struct 
{
	TNo *prim;
	TNo	*ultm;
	int tamanho;
}TLista_Din;

TLista_Din* CriarLista();
bool listaExiste();


int InserirInicio(TLista_Din *lista, int infoData);

int inserirMeio(TLista_Din *lista, int infoData);

int inserirFinal(TLista_Din *lista, int infoData);

void imprimirLista(TLista_Din *lista);

int removerInicio(TLista_Din *lista);

int removerFinal(TLista_Din *lista);

void menuListaDinamica();




