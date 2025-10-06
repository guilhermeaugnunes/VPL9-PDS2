#include "FrontEnd.hpp"
#include <iostream>

FrontEnd::FrontEnd(const int cpf, const std::string& nome, const int idade, const std::string& funcao) : 
    Funcionario(cpf, nome, idade, funcao), 
    Desenvolvedor(cpf, nome, idade, funcao) {}

void FrontEnd::executarFuncao() {
    std::cout << "Trabalhando com Interfaces Gráficas." << std::endl;
}