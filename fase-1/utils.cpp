#include <iostream>
#include <map>
#include <random>

using namespace std;

random_device rd;
mt19937 gerador(rd());

int geraValorAleatorio(int min, int max) {
    int n;
    uniform_int_distribution<> range(min, max);
    n = range(gerador);
    
    return n;
}

