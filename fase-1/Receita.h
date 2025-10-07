#include <string>

#include "Ingrediente.h"
#include "pilha.h"

#ifndef RECEITA_H
#define RECEITA_H

using namespace std;

class Receita {
    private:
        string nome;
        const int id;
        static int id_counter;
        pilha *pilha_ingredientes;
        vector<Ingrediente> ingredientes;
        vector<int> receitaPorIds;
        bool pronta;

        void geraReceitaIds();
        void mapeiaIngredientePorId();

    public:
        Receita (string _nome); 
        ~Receita() {
            delete_pilha(pilha_ingredientes);
        }

        int getReceitaPorIds(int pos) const; 
        Ingrediente getIngredientes(int pos) const;
        string getNome() const;
        pilha* getPilha() const;
        bool getPronta() const;
};

#endif