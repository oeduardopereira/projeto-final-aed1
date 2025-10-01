#include <iostream>
#include "Ingrediente.cpp"
#include "constantes.cpp"
#include "utils.cpp"

using namespace std;

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