#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lista_encad_header.h"

struct elemento{
	struct ED_LE dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

struct descritor {
	struct elemento *inicio;
	struct elemento *final;
	int qtd;
};

Lista *cria_lista(){
	Lista *li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL){
		li->inicio = NULL;
		li->final = NULL;
		li->qtd = 0;
	}
	return li;
}

void libera_lista(Lista *li){
	if(li != NULL){
		Elem *no;
		while((li->inicio) != NULL) {
			no = li->inicio;
			li->inicio = li->inicio->prox;
			free(no);
		}
		free(li);
	}
}

bool insere_lista_inicio(Lista *li, struct ED_LE ed){
	if(li == NULL) return 0;
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) return 0;
	no->dados = ed;
	no->prox = li->inicio;
	if(li->inicio == NULL)
		li->final = no;
	li->inicio = no;
	li->qtd++;
	return 1;
}

bool insere_lista_final(Lista *li, struct ED_LE ed){
	if(li == NULL) return 0;
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) return 0;
	no->dados = ed;
	no->prox = NULL;
	if(li->inicio == NULL)
		li->inicio = no;
	else
		li->final = no;
	
	li->final = no;
	li->qtd++;
	return 1;
}

bool remove_lista_inicio(Lista *li){
	if(li == NULL)  return 0;
	if(li->inicio == NULL) return 0;
	Elem *no = li->inicio;
	li->inicio = no->prox;
	free(no);
	if(li->inicio == NULL)
		li->final = NULL;
	li->qtd--;
	return 1;
}

bool remove_lista_final(Lista *li){
	if(li == NULL || li->inicio == NULL) return 0;
	Elem *ant, *no = li->inicio;
	while(no->prox != NULL){
		ant = no;
		no = no->prox;
	}
	if(no == li->inicio){
		li->inicio = NULL;
		li->final = NULL;
	}
	else {
		ant->prox = NULL;
		li->final = ant;
	}
	free(no);
	li->qtd--;
	return 1;
}

void imprime_lista(Lista *li){
	if(li == NULL){
		printf("Lista não existe\n");
	}	
	else if((li->inicio) == NULL){
		printf("Lista vazia\n");
	}

	else{
		printf("aaaaaaa\n");
		Elem *no = li->inicio;
		while(no != NULL){
			printf(" %d ", no->dados.dado);
			no = no->prox;
		}
		printf("\n");
	}
		
}
