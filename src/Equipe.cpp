#include "Equipe.hpp"
#include <iostream> 
#include <vector>
#include <string>

namespace GestaoTarefas {

    Equipe::Equipe(int id, Gerente* gerente, const std::vector<Funcionario*>& funcionarios) :
        _id(id), _gerente(gerente), _funcionarios(funcionarios), _status(true) {}

    void Equipe::imprimirEquipe() const {
        std::cout << "Status da Equipe: " << _status << std::endl; 
        std::cout << "Gerente: " << _gerente->getNome() << std::endl; 

        std::cout << "Membros:" << std::endl;
        for (Funcionario* func : _funcionarios) {
            std::cout << "Nome: " << func->getNome() << std::endl;
            std::cout << "Funcao: "<< func->getFuncao() << std::endl;
        }
    }

    std::vector<Funcionario*>&Equipe::getFuncionarios() {
        return this-> _funcionarios;
    }

    Gerente* Equipe::getGerente() const {
        return this-> _gerente;
    }

    int Equipe::getId() const {
        return this-> _id;
    }

    bool Equipe::getDisponivel() const {
        return this-> _status;
    }
    void Equipe::setDisponivel(bool status) {
        this-> _status = status;
    }

}