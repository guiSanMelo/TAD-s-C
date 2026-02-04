#ifndef NO_H
#define  NO_H

typedef struct no
{
	int info;
	no *prox;
	no *ant;
}TNo;


typedef struct 
{
	int valor;
}TElem;

typedef struct 
{
	TElem elemento;
	int alt;
	TNo *esq;
	TNo *dir;
}TNoAvore;

 


#endif