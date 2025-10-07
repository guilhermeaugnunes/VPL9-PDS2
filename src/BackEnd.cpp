#include "BackEnd.hpp"
#include <iostream>

namespace GestaoTarefas {

    BackEnd::BackEnd(int cpf, const std::string& nome, const int idade, const std::string& funcao) :
        Funcionario(cpf, nome, idade, funcao),
        Desenvolvedor(cpf, nome, idade, funcao) {}

    void BackEnd::executarFuncao() {
        std::cout << "Trabalhando com regras de negócio." << std::endl;
    }

}