#ifndef NOCIRC_H
#define NOCIRC_H


typedef struct nocirc
{
	int info;
	struct nocirc *prox;
	struct nocirc *ant;
}TNoCirc;


endif