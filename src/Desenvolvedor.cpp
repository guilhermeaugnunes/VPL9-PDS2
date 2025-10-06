#include "Desenvolvedor.hpp"
#include <iostream>

Desenvolvedor::Desenvolvedor(const int cpf, const std::string& nome, const int idade, const std::string& funcao): 
    Funcionario(cpf, nome, idade, funcao) {}

Desenvolvedor::~Desenvolvedor() {}