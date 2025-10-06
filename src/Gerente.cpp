#include "Gerente.hpp"
#include <iostream>

    Gerente::Gerente(const int cpf, const std::string& nome, const int idade, const std::string& funcao) : Funcionario(cpf, nome, idade, funcao) {}

    void Gerente::executarFuncao() {
        std::cout <<"Gerenciado equipe." << std::endl;
    }
