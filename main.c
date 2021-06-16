#include <stdio.h>
#include "lista_encad_header.h"

void main(){
	Lista *li;
	struct ED_LE ed;
	short int opc;
	int num;

	li = cria_lista();

	libera_lista(li);
}
