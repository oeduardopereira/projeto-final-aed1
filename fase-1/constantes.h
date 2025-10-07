#include <string>
#include <map>
#include <vector>

#ifndef Constantes_H
#define Constantes_H

using namespace std;

const map<int, string> INGREDIENTES_IDS = {
    {1, "Pão de Hamburguer"}, //done (perspective && shelf) --
    {2, "Pão-Brioche"}, // done (perspective && shelf) --
    {3, "Carne Bovina"}, // done (perspective && shelf) --
    {4, "Carne Vegana"}, // done (perspective && shelf) --
    {5, "Filé de Frango"}, // done (perspective && shelf) --
    {6, "Tomate"}, // done (perspective && shelf) --
    {7, "Alface"}, //done (shelf) --
    {8, "Cebola"}, // done(perspective && shelf) --
    {9, "Mostarda"}, 
    {10, "Maionese"},
    {11, "Bacon"}, // done (perspective && shelf) --
    {12, "Cebola Caramelizada"}, //done (perspective) --
    {-1, "-"}
};

const vector<vector<int>> INGREDIENTES = {
    {1, 2}, {3, 4, 5}, {-1, 6, 7, 8}, {-1, 9, 10}, {-1, 11, 12}
};

const int MAX_INGREDIENTES = 7;

#endif