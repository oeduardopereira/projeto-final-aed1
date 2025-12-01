#include <string>
#include <iostream>
#include <map>
#include <random>

#include "constantes.h"

using namespace std;

#ifndef UTILS_H
#define UTILS_H

int geraValorAleatorio(int min, int max);
void listaIngredientes();

random_device rd;
mt19937 gerador(rd());

int geraValorAleatorio(int min, int max) {
    int n;
    uniform_int_distribution<> range(min, max);
    n = range(gerador);
    
    return n;
}

void listaIngredientes() {

    for (auto i = INGREDIENTES_IDS.begin(); i != INGREDIENTES_IDS.end(); i++) {
        cout << "ID: " << i->first << " | Ingrediente: " << i->second << endl;
    }
}

#endif