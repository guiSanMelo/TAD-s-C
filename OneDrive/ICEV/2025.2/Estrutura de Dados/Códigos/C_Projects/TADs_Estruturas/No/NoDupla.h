#ifndef NODUPLA_H
#define NODUPLA_H

typedef struct nodup
{
	int info;
	struct nodup* ant;
	struct nodup* prox;
}TNoDup;

#endif