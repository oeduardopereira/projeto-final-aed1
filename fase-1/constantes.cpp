#include <iostream>
#include <map>
#include <vector>

using namespace std;

const map<int, string> INGREDIENTES_IDS = {
    {1, "Pão de Hamburguer"},
    {2, "Pão-Brioche"},
    {3, "Carne Bovina"},
    {4, "Carne Vegana"},
    {5, "Filé de Frango"},
    {6, "Tomamte"},
    {7, "Alface"},
    {8, "Cebola"},
    {9, "Mostarda"},
    {10, "Maionese"},
    {11, "Bacon"},
    {12, "Cebola Caramelizada"},
    {-1, ""}
};

const vector<vector<int>> INGREDIENTES = {
    {1, 2}, {3, 4, 5}, {-1, 6, 7, 8}, {-1, 9, 10}, {-1, 11, 12}
};