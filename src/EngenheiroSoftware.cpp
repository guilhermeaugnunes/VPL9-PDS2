#include "EngenheiroSoftware.hpp"
#include <iostream>

    EngenheiroSoftware::EngenheiroSoftware(const int cpf, const std::string& nome, const int idade, const std::string& funcao) : 
        Funcionario(cpf, nome, idade, funcao) {}

    void EngenheiroSoftware::executarFuncao() {
        std::cout << "Arquitetando Solução." << std::endl;
    }
