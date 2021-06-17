#include <stdbool.h>

struct ED_LE{
	int dado;
};

typedef struct descritor Lista;

Lista *cria_lista();

void libera_lista(Lista *li);

bool insere_lista_inicio(Lista *li, struct ED_LE ed);

bool insere_lista_final(Lista *li, struct ED_LE ed);

bool insere_lista_ordenada(Lista *li, struct ED_LE ed);

bool remove_lista_inicio(Lista *li);

bool remove_lista_final(Lista *li);

void imprime_lista(Lista *li);
