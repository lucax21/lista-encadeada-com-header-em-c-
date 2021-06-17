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

bool remove_lista(Lista *li, int num);

bool consulta_lista_conteudo(Lista *li, int dado, struct ED_LE *ed);

bool consulta_lista_pos(Lista *li, int pos, struct ED_LE *ed);

void imprime_lista(Lista *li);
