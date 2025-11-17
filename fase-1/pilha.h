#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "Ingrediente.h"
#include "constantes.h"

using namespace std;

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
string retornaString(pilha *p);
bool pilhas_iguais(pilha *p1, pilha *p2);

// cria uma nova pilha e retorna a referência
pilha* criaPilha() {
   pilha *p = new pilha; // aloca a memória estática para pilha
   if (p == nullptr) return NULL;
   p->indexTopo = -1; // indica que a pilha está vazia
   return p;
}

bool delete_pilha(pilha *p) {
    if (p == nullptr) return false;
    delete p;
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
    if (p == NULL) return false;

    if (cheia(p)) return false;
    else {
            p->indexTopo += 1; // atualiza o topo
            p->ingredientes[p->indexTopo] = i; // insere o valor no topo
        return true;
    }
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
    for (int i = ingredientes_temp.size() - 1; i >= 0; i--) {
        Ingrediente ing = ingredientes_temp[i];

        empilha(pilha_atual, ing); //? cout << "" : cout << "Erro ao empilhar a pilha original na copia_pilha!" << endl;
        empilha(copia, ing) ? cout << "" : cout << "Erro ao empilhar a pilha copia na copia_pilha!" << endl;
    }

    return copia;
}

void mostra_pilha(pilha *p) {
    pilha *p_aux = copia_pilha(p);

    if (p_aux == NULL) return; 

    while(!vazia(p_aux)) {
        bool ok;
        Ingrediente ing = desempilha(p_aux, &ok);
        ok ? cout << "\033[1;33m" << ing.getNome() << "\033[0m" << endl : cout << "Erro ao desempilhar!" << endl;
    }

    delete_pilha(p_aux);
}

string retornaString(pilha *p) {
    pilha *p_aux = copia_pilha(p);
    if (p_aux == NULL) return "Erro na pilha"; 

    stringstream ss;

    while(!vazia(p_aux)) {
        bool ok;
        Ingrediente ing = desempilha(p_aux, &ok);
        ok ? ss << ing.getNome() << endl : ss << "Erro ao desempilhar!" << endl;
    }

    ss << "-- Fim da receita --" << endl;

    delete_pilha(p_aux);

    return ss.str();
}

bool pilhas_iguais(pilha *p1, pilha *p2) {
    if (p1 == NULL || p2 == NULL) return false;

    pilha *p1_aux, *p2_aux;
    bool iguais = true, ok;

    p1_aux = copia_pilha(p1);
    p2_aux = copia_pilha(p2);

     if (p1_aux == NULL || p2_aux == NULL) {
        delete_pilha(p1_aux);
        delete_pilha(p2_aux);
        return false;
    }

    if (p1_aux->indexTopo != p2_aux->indexTopo) {
        delete_pilha(p1_aux);
        delete_pilha(p2_aux);
        return false;
    }

    while (!vazia(p1_aux)) {
        Ingrediente ing_p1, ing_p2;

        ing_p1 = desempilha(p1_aux, &ok);
        ing_p2 = desempilha(p2_aux, &ok);

        if (ing_p1.getId() != ing_p2.getId()) iguais = false;
    }

    delete_pilha(p1_aux);
    delete_pilha(p2_aux);

    return iguais;
}


#endif
