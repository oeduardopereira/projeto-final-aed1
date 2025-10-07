#include <iostream>

#include "Receita.h"
#include "pilha.h"
#include "Ingrediente.h"
#include "constantes.h"
#include "utils.h"

using namespace std;

int main() {
    int id_escolhido, camada_atual = 0;
    Receita receita = Receita("Hamburguer 1");
    pilha *receita_montada = criaPilha();
    Ingrediente ing;
    bool ok;

    

    while (true) {

        cout << endl << "Lista de ingredientes: " << endl;
        listaIngredientes();
        
        cout << endl << "Receita a ser feita: " << receita.getNome() << endl << endl;
        mostra_pilha(receita.getPilha());

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

            if (camada_atual == 7) {
                pilhas_iguais(receita.getPilha(), receita_montada) 
                    ? cout << endl << "PARABÉNS, A RECEITA FICOU PRONTA!" << endl
                    : cout << endl << "A RECEITA ESTA ERRADA!" << endl;
                    
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

    delete_pilha(receita.getPilha());
    return 0;
}