#include "Ingrediente.h"
#include "constantes.h"

#ifndef PILHA_H
#define PILHA_H

typedef struct {
   int indexTopo;
   Ingrediente ingredientes[MAX_INGREDIENTES];
} pilha;

pilha* criaPilha();
bool delete_pilha(pilha *p);
bool cheia(pilha *p) ;
bool vazia(pilha *p); 
bool empilha(pilha *p, Ingrediente i);
Ingrediente desempilha(pilha *p, bool *deuCerto);
pilha* copia_pilha(pilha *pilha_atual);

#include <vector>
void mostra_pilha(pilha *p);
bool pilhas_iguais(pilha *p1, pilha *p2);

#endif
