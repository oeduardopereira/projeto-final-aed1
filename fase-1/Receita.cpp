#include <iostream>
#include <random>
#include "Ingrediente.cpp"
#include "constantes.cpp"

using namespace std;

random_device rd;
mt19937 gerador(rd());

class Receita {

    private:
        string nome;
        const int id;
        static int id_counter;
        Ingrediente *ingredientes;
        int *receitaPorIds;
        bool pronta;

        /*
            Esta função é resposável por gerar uma receita aletoria,
            como cada ingrediente tem seu id, o array retornado desta funçao,
            representa os ingredientes escolhidos, e a ordem deles.
            Sendo que -1, é um espaço vazio.
        */
        void geraReceitaIds() {
            int n;
            
            for (int i = 0; i < 7; i++) {
                switch(i) {
                    case 0: {
                        uniform_int_distribution<> range(1, 2);
                        n = range(gerador);
                        receitaPorIds[i] = n;
                        break;
                    }

                    case 1: {
                        uniform_int_distribution<> range(3, 5);
                        n = range(gerador);
                        receitaPorIds[i] = n;
                        break;
                    }

                    case 2: {
                        uniform_int_distribution<> range(5, 8);
                        n = range(gerador);
                        if (n == 5) n = -1;
                        receitaPorIds[i] = n;
                        break;
                    }
 
                    case 3: {
                        uniform_int_distribution<> range(8, 10);
                        n = range(gerador);
                        if (n == 8) n = -1;
                        receitaPorIds[i] = n;
                        break;
                    }
 
                    case 4: {
                        uniform_int_distribution<> range(10, 12);
                        n = range(gerador);
                        if (n == 10) n = -1;
                        receitaPorIds[i] = n;
                        break;
                    }
 
                    case 5: {
                        uniform_int_distribution<> range(2, 12);
                        n = range(gerador);
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
        */
        void mapeiaIngredientePorId() {
            for (int i = 0; i < MAX_INGREDIENTES; i++) {
                int n = receitaPorIds[i];
                Ingrediente ing = Ingrediente(INGREDIENTES_IDS.at(receitaPorIds[i]), i, receitaPorIds[i]);
                ingredientes[i] = ing;
            }
        }


    public:

        Receita (string _nome) : id(id_counter++) {
            id_counter = 0;
            this->nome = nome;
            this->pronta = false;
            this->receitaPorIds = new int[MAX_INGREDIENTES];
            this->ingredientes = new Ingrediente[MAX_INGREDIENTES];
            geraReceitaIds();
            mapeiaIngredientePorId();
        }

        int getReceitaPorIds(int pos) {
            return this->receitaPorIds[pos];
        } 

        Ingrediente getIngredientes(int pos) {
            return ingredientes[pos];
        }

        ~Receita() {
            delete[] this->ingredientes;
            delete[] this->receitaPorIds;
        }
};

int Receita::id_counter = 0;