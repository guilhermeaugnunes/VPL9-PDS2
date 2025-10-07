#include "Backlog.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

namespace GestaoTarefas {

    Backlog::Backlog() {}

    void Backlog::adicionarTarefaBacklog(const Tarefa& novaTarefa) {
        this-> _tarefas.push_back(novaTarefa);
    }

    Tarefa Backlog::removerTarefaBacklog() {
        if (_tarefas.empty()) {
            throw std::runtime_error ("Não existe itens a serem removidos.");   
        }
        
        int maiorPeso = _tarefas[0].getPeso();
        int indiceTarefa = 0;
        
        for (size_t i = 1; i < _tarefas.size(); i++) {
            if (_tarefas[i].getPeso() > maiorPeso) {
                maiorPeso = _tarefas[i].getPeso();
                indiceTarefa = i;
            }
        }

        Tarefa tarefaRemovida = _tarefas[indiceTarefa];

        _tarefas.erase(_tarefas.begin() + indiceTarefa);

        return tarefaRemovida;

    }

    Tarefa* Backlog::obterMaiorPeso() {
        if (_tarefas.empty()) {
            return nullptr;      
        }
        
        int maiorPeso = _tarefas[0].getPeso();
        int indiceTarefa = 0;
        
        for (size_t i = 1; i < _tarefas.size(); i++) {
            if (_tarefas[i].getPeso() > maiorPeso) {
                maiorPeso = _tarefas[i].getPeso();
                indiceTarefa = i;
            }
        }

        return &_tarefas[indiceTarefa];
    }

}