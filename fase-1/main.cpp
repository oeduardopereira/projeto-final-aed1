#include <iostream>
#include "Receita.cpp"
#include "pilha.cpp"

using namespace std;

int main() {

    Receita r = Receita("Teste");
    pilha *p = criaPilha();
    Ingrediente ing;

    for (int i = 0; i < 7; i++) {
        ing = r.getIngredientes(i);
        
        empilha(p, ing) ? cout << "pos["<< i << "] = " << ing.getNome() << endl
            : cout << "Erro ao empilhar " << ing.getNome() << endl;
    }

    cout << endl << "Desepilhando:" << endl;
    cout << endl <<  "Topo -> ";

    bool ok;

    for (int i = 0; i < 7; i++) {
        ing = desempilha(p, &ok);
        ok ? cout << ing.getNome() << endl : cout << "Erro ao desempilhar o ingrediente " << i << endl;
    }

    delete_pilha(p);
    return 0;
}