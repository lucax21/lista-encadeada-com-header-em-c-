#include <stdio.h>
#include <stdlib.h>
#include "lista_encad_header.h"

struct elemento{
	struct ED_LE dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

struct descritor {
	struct elemento *inicio;
	struct elemento *fim;
	int qtd;
};

Lista *cria_lista(){
	Lista *li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL){
		li->inicio = NULL;
		li->fim = NULL;
		li->qtd = 0;
	}
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
