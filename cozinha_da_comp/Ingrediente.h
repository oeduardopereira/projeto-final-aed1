#include <string>

#ifndef INGREDIENTE_H
#define INGREDIENTE_H

using namespace std;

class Ingrediente {
    private:
        string nome;
        int camada; 
        int id;

    public:   
        // Construtor default necessário para a pilha
        Ingrediente() : nome(""), camada(-1), id(-1) {}

        Ingrediente(string nome, int camada, int _id): id(_id) {
            this->nome = nome;
            this->camada = camada;
        }

        string getNome() const { return this->nome; }
        int getCamada() const { return this->camada; }
        int getId() const { return this->id; }
};

#endif