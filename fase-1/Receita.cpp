#include <iostream>
#include <vector>
#include <string>

#include "Receita.h"
#include "utils.h"
#include "constantes.h"
#include "pilha.h"

using namespace std;

int Receita::id_counter = 0;

/*
    Esta função é resposável por gerar uma receita aletoria,
    como cada ingrediente tem seu id, o array retornado desta funçao,
    representa os ingredientes escolhidos, e a ordem deles.
    Sendo que -1, é um espaço vazio.
*/
void Receita::geraReceitaIds() {
    int n;
    
    for (int i = 0; i < MAX_INGREDIENTES; i++) {
        switch(i) {
            case 0: {
                n = geraValorAleatorio(1, 2);
                receitaPorIds[i] = n;
                break;
            }

            case 1: {
                n = geraValorAleatorio(3, 5);
                receitaPorIds[i] = n;
                break;
            }

            case 2: {
                n = geraValorAleatorio(5, 8);
                if (n == 5) n = -1;
                receitaPorIds[i] = n;
                break;
            }

            case 3: {
                n = geraValorAleatorio(8, 10);
                if (n == 8) n = -1;
                receitaPorIds[i] = n;
                break;
            }

            case 4: {
                n = geraValorAleatorio(10 ,12);
                if (n == 10) n = -1;
                receitaPorIds[i] = n;
                break;
            }

            case 5: {
                n = geraValorAleatorio(2, 12);
                if (n == 2) n = -1;
                receitaPorIds[i] = n;
                break;
            }
                
            case 6: {
                receitaPorIds[i] = receitaPorIds[0];
                break;
            }
        }
    }
}

/*
    Essa função faz um mapeamento dos ids escolhidos aleatoriamente,
    para os ingredientes correspondentes no map de <id, ingrediente>
    e empilha na pilha_ingredientes.
*/
void Receita::mapeiaIngredientePorId() {
    if (this->pilha_ingredientes == NULL) return;
    
    for (int i = 0; i < MAX_INGREDIENTES; i++) {
        string nome_ing = "";
        
        if (INGREDIENTES_IDS.count(receitaPorIds[i])) nome_ing = INGREDIENTES_IDS.at(receitaPorIds[i]);
        else nome_ing = "Ingrediente Inválido";

        Ingrediente ing = Ingrediente(nome_ing, i, receitaPorIds[i]);
        empilha(this->pilha_ingredientes, ing);
    }
}


Receita::Receita (string _nome) : id(id_counter++), receitaPorIds(MAX_INGREDIENTES), ingredientes(MAX_INGREDIENTES) {
    this->nome = _nome;
    this->pronta = false;
    pilha_ingredientes = criaPilha();
    geraReceitaIds();
    mapeiaIngredientePorId();
}

int Receita::getReceitaPorIds(int pos) const {
    return this->receitaPorIds[pos];
} 

Ingrediente Receita::getIngredientes(int pos) const {
    return ingredientes[pos];
}

string Receita::getNome() const {
    return this->nome;
}

pilha* Receita::getPilha() const {
    return this->pilha_ingredientes;
}

bool Receita::getPronta() const {
    return this->pronta;
}
