#include <iostream>
#include "Ingredientes.h"

using namespace std;

class Receitas {

    private:
        string nome;
        unsigned int id;
        Ingredientes ingredientes[7];
        bool pronta;

    public:
        Receitas () {}

        Receitas (string nome, unsigned int id, Ingredientes Ingredientes[]) {
            this->nome = nome; 
            this->id = id;
            this->pronta = false;
        }
    
};