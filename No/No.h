#ifndef NO_H
#define NO_H

typedef struct no {
    int info;
    struct no *prox;  // Mantém struct no* aqui
	struct no *ant;
} TNo;


#endif