#include <iostream>
#include "Receita.cpp"
#include "pilha.cpp"

using namespace std;

int main() {

    Receita r = Receita("Teste");
    pilha *p = criaPilha();
    Ingrediente ing;

    for (int i = 0; i < 7; i++) {
        string nome = r.getIngredientes(i).getNome();
        ing = Ingrediente(
            r.getIngredientes(i).getNome(),
            r.getIngredientes(i).getCamada(),
            r.getIngredientes(i).getId()
        );
        empilha(p, ing);
        cout << "pos["<< i << "] = " << nome << endl;
    }

    cout << "Desepilhando:" << endl;
    cout << "Topo -> ";

    bool ok;

    for (int i =0; i < 7; i++) {
        ing = desempilha(p, &ok);
        cout << ing.getNome() << endl;
    }

    delete_pilha(p);
    return 0;
}