#include <iostream>

#ifndef Ingrediente_H
#define Ingrediente_H

using namespace std;

class Ingrediente {

    private:
        string nome;
        int camada; 
        int id;

    public:   
        Ingrediente() {}

        Ingrediente(string nome, int camada, int _id): id(_id) {
            this->nome = nome;
            this->camada = camada;
        }

        string getNome() {
            return this->nome;
        }

        int getCamada() {
            return this->camada;
        }

        int getId() {
            return this->id;
        }
    
};

#endif