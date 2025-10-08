#include <iostream>
#include <sstream>

#include "Receita.h"
#include "pilha.h"
#include "Ingrediente.h"
#include "constantes.h"
#include "utils.h"

using namespace std;

int main() {
    int id_escolhido;
    int camada_atual;
    int id_receita = 0;
    Ingrediente ing;
    bool ok = true;
    string prefixo_receita = "Hamburguer";
    

    while (ok) {
        id_escolhido = 0;
        camada_atual = 0;
        stringstream nome;
        nome << prefixo_receita;
        nome << " ";
        nome << id_receita;
        Receita* receita = new Receita(nome.str());
        pilha *receita_montada = criaPilha();
        while (true) {
            cout << endl << "Lista de ingredientes: " << endl;
            listaIngredientes();
            
            cout << endl << "Receita a ser feita: " << (*receita).getNome() << endl << endl;
            mostra_pilha((*receita).getPilha());

            cout << endl << "Sua receita: " << endl;
            mostra_pilha(receita_montada);

            cout << endl << "Digite o ID para empilhar o ingrediente (para desempilhar digite -99): ";
            cin >> id_escolhido;

            if (id_escolhido != -99) {

                string ingrediente_nome = INGREDIENTES_IDS.at(id_escolhido);
                
                cout << endl << "Ingrediente empilhado: " << ingrediente_nome << endl;
                
                ing = Ingrediente(ingrediente_nome, camada_atual, id_escolhido);
                empilha(receita_montada, ing);

                camada_atual++;

                if (camada_atual == (*receita).getQtdIngredientes()) {
                    if (pilhas_iguais((*receita).getPilha(), receita_montada)) {
                        cout << "Parabéns! Você acertou a receita!" << endl;
                        break;
                    } else {
                        cout << "Que pena! Você errou a receita!" << endl;
                        ok = false;
                        break;
                    }
                        
                    cout << endl << "Sua receita: " << endl;
                    mostra_pilha(receita_montada);
                    break;
                }

            } else {
                ing = desempilha(receita_montada, &ok);
                if (ok) cout << endl << "\033[31m" << ing.getNome() << " foi desempilhado!" << "\033[0m" << endl;
                camada_atual--;
            }

            cout << endl << "#####################################################" << endl;
            cout << endl << "\033[31m" << "Camada atual: " << camada_atual << "\033[0m" << endl;
        }
        delete receita;
        delete_pilha(receita_montada);
    }
    return 0;
}