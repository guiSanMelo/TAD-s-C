#define TAMANHO_MAX 10


typedef struct 
{
	int itens[TAMANHO_MAX];
	int prim;
	int ult;
	int tamanho;
}TLista_Estatica;



void criarLista(TLista_Estatica *lista);

void inserirInicio();

void inserirMeio(TLista_Estatica *lista, int elemento);

int inserirFinal(TLista_Estatica *lista, int elemento);

void imprimirLista();
