#include <iostream>

#include "Receita.h"

class HeapPrioridade {
    private:
        vector<Receita*> elementos;

        // Funções auxiliares para índices (0-based array)
        int get_pai_index(int i) { return (i - 1) / 2; }
        int get_esq_index(int i) { return 2 * i + 1; }
        int get_dir_index(int i) { return 2 * i + 2; }

        // Reorganiza para cima (após inserção ou diminuição de chave/tempo)
        void heapify_up(int i) {
            while (i != 0 && elementos[i]->getTempoConclusao() < elementos[get_pai_index(i)]->getTempoConclusao()) {
                swap(elementos[i], elementos[get_pai_index(i)]);
                i = get_pai_index(i);
            }
        }

        // Reorganiza para baixo (após extração ou construção do heap)
        void heapify_down(int i) {
            int n = elementos.size();
            int menor_prioridade = i;
            int esq = get_esq_index(i);
            int dir = get_dir_index(i);

            // Compara com o filho esquerdo
            if (esq < n && elementos[esq]->getTempoConclusao() < elementos[menor_prioridade]->getTempoConclusao()) {
                menor_prioridade = esq;
            }

            // Compara com o filho direito
            if (dir < n && elementos[dir]->getTempoConclusao() < elementos[menor_prioridade]->getTempoConclusao()) {
                menor_prioridade = dir;
            }

            if (menor_prioridade != i) {
                swap(elementos[i], elementos[menor_prioridade]);
                heapify_down(menor_prioridade);
            }
        }
        
        // Método de reorganização completa (build_heap)
        void build_heap() {
            int n = elementos.size();
            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify_down(i);
            }
        }

    public:
        HeapPrioridade() {}
        ~HeapPrioridade() {
            for (Receita* r : elementos) { delete r; } // Limpa a memória
        }

        bool estaVazio() const { return elementos.empty(); }
        size_t getSize() const { return elementos.size(); }
        void inserir(Receita* nova_receita) {
            if (nova_receita == nullptr) return;
            elementos.push_back(nova_receita);
            heapify_up(elementos.size() - 1);
        }

        Receita* extrairMinimo() {
            if (estaVazio()) return nullptr;
            Receita* receita_min = elementos[0];
            elementos[0] = elementos.back();
            elementos.pop_back();
            if (!estaVazio()) {
                heapify_down(0); 
            }
            return receita_min;
        }

        Receita* olharMinimo() const {
            if (estaVazio()) return nullptr;
            return elementos[0];
        }
        
        // Expõe os elementos para que o game loop possa iterar sobre eles
        vector<Receita*>& getElementos() {
            return elementos;
        }
        
        // Executa a reorganização completa após o tempo ser decrementado
        void rebalancear() {
            build_heap();
        }

        Receita* deletar(int i) {
            if (estaVazio()) return nullptr;
            Receita* r = elementos[i];
            elementos.erase(elementos.begin() + i);
            return r;
        }

        void clear() {
            elementos.clear();
        }

        int find(int rId) {
            for (int p = 0; p < elementos.size(); p++) {
                if (rId == elementos[p]->getId()) {
                    return p;
                }
            }
        }
};