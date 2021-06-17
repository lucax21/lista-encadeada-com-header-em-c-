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
	li = NULL;
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
		li->final->prox = no;
	
	li->final = no;
	li->qtd++;
	return 1;
}

bool insere_lista_ordenada(Lista *li, struct ED_LE ed){
	if(li == NULL)  return 0;
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) return 0;

	no->dados = ed;
	if(li->inicio == NULL){
		li->inicio = no;
		li->final = no;
	}
	else{
		if(ed.dado < li->inicio->dados.dado){
			no->prox = li->inicio;
			li->inicio = no;
		}
		else if(ed.dado > li->final->dados.dado){
			no->prox = NULL;
			li->final->prox = no;
			li->final = no;
		}
		else{
			Elem *ant, *atual = li->inicio;
			while(atual != NULL && atual->dados.dado < ed.dado){
				ant = atual;
				atual = atual->prox;
			printf("ant: %d no: %d\n", ant->dados.dado, no->dados.dado);
			}
			no->prox = ant->prox;
			ant->prox = no;
		}
	}
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

bool remove_lista(Lista *li, int num){
	if(li == NULL || li->inicio == NULL) return 0;
	
	Elem *ant, *atual = li->inicio;	
	while(atual != NULL && atual->dados.dado != num){
		ant = atual;
		atual = atual->prox;
	}
	// nao acho o elemento
	if(atual == NULL) return 0;
	
	if(atual == li->inicio){
		if(li->inicio->prox == NULL){
			li->inicio = NULL;
			li->final = NULL;
			li->qtd--;
			free(atual);
			return 1;
		}
		else{
			li->inicio = atual->prox;
			li->qtd--;
			free(atual);
			return 1;
		}
	}
	else {
		if(atual->prox == NULL){
			li->final = ant;
			ant->prox = NULL;
			li->qtd--;
			free(atual);
			return 1;
		}
		else{
			ant->prox = atual->prox;
			li->qtd--;
			free(atual);
			return 1;
		}
	}
//	return 1;
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

bool consulta_lista_conteudo(Lista *li, int dado, struct ED_LE *ed){
	if(li == NULL || li->inicio == NULL) return 0;
	
	if(li->final->dados.dado == dado){
		*ed = li->final->dados;
		return 1;
	}
	else {
		Elem *no = li->inicio;
		while(no != li->final && no->dados.dado != dado){
			no = no->prox;
		}
		if(no == li->final)
			return 0;
		else{
			*ed = no->dados;
			return 1;
		}
	}
}

bool consulta_lista_pos(Lista *li, int pos, struct ED_LE *ed){
	if(li == NULL || li->qtd < 0 || pos < 0) return 0;

	if(pos > li->qtd)
		return 0;

	if(li->qtd == pos){
		*ed = li->final->dados;
		return 1;
	}
	else{
		Elem *no = li->inicio;
		int i = 1;
		while(no != NULL && i < pos){
			no = no->prox;
			i++;
		}
		*ed = no->dados;
		return 1;
	}
}

