#include <iostream>
#include "Receita.cpp"

using namespace std;

int main() {

    Receita r = Receita("Teste");
    cout << endl << "Receita infos: " << r.getNome() << endl;

    cout << endl << "Desepilhando:" << endl;
    cout << endl <<  "Topo -> ";
    
    mostra_pilha(r.getPilha());
    
    delete_pilha(r.getPilha());
    return 0;
}