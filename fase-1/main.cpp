#include <iostream>
#include "Receita.cpp"

using namespace std;

int main() {

    Receita r = Receita("Teste");

    for (int i = 0; i < 7; i++) {
        string nome = r.getIngredientes(i).getNome();
        cout << "pos["<< i << "] = " << nome << endl;
    }

    return 0;
}