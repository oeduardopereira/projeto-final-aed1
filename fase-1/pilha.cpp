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

pilha* copia_pilha(pilha *pilha_atual) {
    pilha *copia = criaPilha();
    Ingrediente ing;
    bool ok;
    vector<Ingrediente> ingredientes_temp;

    // Desempilha a pilha à ser copiada
    // e armazena no vetor ingredientes_temp
    while (!vazia(pilha_atual)) {
        ing = desempilha(pilha_atual, &ok);
        if (ok) ingredientes_temp.push_back(ing);
        else cout << "Erro ao desempilhar na copia da pilha!" << endl;
    }

    // reempilha a pilha de origem e a sua copia
    for (int i = MAX_INGREDIENTES - 1; i >= 0; i--) {
        bool ok;
        Ingrediente ing = ingredientes_temp[i];

        empilha(pilha_atual, ing) ? cout : cout << "Erro ao empilhar a pilha original na copia_pilha!" << endl;
        empilha(copia, ing) ? cout : cout << "Erro ao empilhar a pilha copia na copia_pilha!" << endl;
    }

    return copia;
}

void mostra_pilha(pilha *p) {
    pilha *p_aux = copia_pilha(p);

    while(!vazia(p_aux)) {
        bool ok;
        Ingrediente ing = desempilha(p_aux, &ok);
        ok ? cout << ing.getNome() << endl : cout << "Erro ao desempilhar!" << endl;
    }

    free(p_aux);
}
