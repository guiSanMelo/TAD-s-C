#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
//Ultilidades
#include "menu.h"
#include "escolha.h"
//TAds
#include "../Lista_Dinamica/Lista_Dinamica.h"
#include "../Lista_Dupla/Lista_Dupla.h"
#include "../Lista_Estatica/lista_estatica.h"
#include "../Fila/fila.h"
#include "../Pilha/Pilha.h"
#include "escolha.h"

void menuMaior(){
	int valor;
	setlocale(LC_ALL, "");
	TEscolha *escolha = NULL;
	
	do{
		escolha = iniciarEscolha();
		
		printf("Digite a operação \n");
		printf("1. Lista \n");
		printf("2. Lista Duplamente Encadeada \n");
		printf("3. Pilha \n");
		printf("4. Fila \n");
		printf("0. Sair \n");
		
		scanf("%d", &valor);
		setEscolha(escolha, valor);
		
		switch (escolha->opcao) {
			case 0:
				printf("Programa fechado com sucesso");
				escolha->encerrar = 0;
			case 1:
				menuListaDinamica();
				
				break;
			case 2:
				menuListaDupla();
				break;
			case 3:
				menuPilha();
				break;
			case 4:
				menuFila();
				break;
			default:
				printf("Escolha inválida, tente outro número \n");
				break;
		}

	}while(escolha->encerrar != 0);
}






