#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Ingrediente.cpp"
#include "constantes.cpp"

typedef struct {
   int indexTopo;
   Ingrediente ingredientes[MAX_INGREDIENTES];
} pilha;

// cria uma nova pilha e retorna a referência
pilha* criaPilha() {
   pilha *p = (pilha*) malloc(sizeof(pilha)); // aloca a memória estática para pilha
   p->indexTopo = -1; // indica que a pilha está vazia
   return p;
}

bool delete_pilha(pilha *p) {
    free(p);
    return true;
}

// checa se a pilha está cheia
bool cheia(pilha *p) {
   return p->indexTopo >= MAX_INGREDIENTES - 1;
}

// checa se a pilha está vazia
bool vazia(pilha *p) {
   return p->indexTopo == -1;
} 
    
// Empilha o elemento x na pilha 'p'. Retorna se a operação de certo (true = deu certo, false = não deu certo)
bool empilha(pilha *p, Ingrediente i) {
   if (!cheia(p)) { // checa se a pilha está cheia antes de inserir um valor
        p->indexTopo += 1; // atualiza o topo
        p->ingredientes[p->indexTopo] = i; // insere o valor no topo
       return true;
   }
   else return false;
}

// remove o elemento do topo da pilha e retorna, por referência, se deu certo, e o elemento que foi desempilhado
Ingrediente desempilha(pilha *p, bool *deuCerto) {
   if(!vazia(p)) {
       Ingrediente desempilhado = p->ingredientes[p->indexTopo]; // valor que vai ser desempilhado
       p->indexTopo--; // atualiza o topo
       *deuCerto = true;
       return desempilhado;
   } else {
       *deuCerto = false;
       Ingrediente i = Ingrediente("Erro ao desempilhar!", -2, -2);
       return i;
   }
}
