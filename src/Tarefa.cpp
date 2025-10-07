#include "Tarefa.hpp"
#include <iostream>

namespace GestaoTarefas {
    
    Tarefa::Tarefa(int id, const std::string& descricao) :
        _id(id), _descricao(descricao), _peso(0), _equipeResponsavel(nullptr) {}

    std::string Tarefa::getDescricao() const{ 
        return this-> _descricao;
    }
    int Tarefa::getId() const {
        return this-> _id;
    }

    Equipe* Tarefa::getEquipeResponsavel() const {
        return this-> _equipeResponsavel;
    }

    int Tarefa::getPeso() const {
        return this-> _peso;
    }

    void Tarefa::setDescricao(const std::string& descricao) {
        this-> _descricao = descricao;
    }

    void Tarefa::setId(int id) {
        this-> _id = id;
    }

    void Tarefa::setEquipeResponsavel(Equipe* equipeResponsavel) {
        this-> _equipeResponsavel = equipeResponsavel;
    }

    void Tarefa::setPeso(int novoPeso) {
        this-> _peso = novoPeso;
    }

}