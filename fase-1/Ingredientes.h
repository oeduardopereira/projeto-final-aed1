#include <iostream>

using namespace std;

class Ingredientes {

    private:
        string nome;
        unsigned int camada; 
        unsigned int id;

    public:
        Ingredientes() {}    

        Ingredientes(string nome, unsigned int camada, unsigned int id) {
            this->nome = nome;
            this->camada = camada;
            this->id = id;
        }
    
};
