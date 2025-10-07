#include "FullStack.hpp"
#include <iostream>

namespace GestaoTarefas {

    FullStack::FullStack(int cpf, const std::string& nome, const int idade, const std::string& funcao) : 
        Funcionario(cpf, nome, idade, funcao), 
        Desenvolvedor(cpf, nome, idade, funcao), 
        BackEnd(cpf, nome, idade, funcao), 
        FrontEnd(cpf, nome, idade, funcao) {}

    void FullStack::executarFuncao() {
        std::cout << "Trabalhando com Interfaces Gráficas e Regras de Negócio." << std::endl;
    }

}