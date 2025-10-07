#ifndef GERENTE_HPP
#define GERENTE_HPP
#include "Funcionario.hpp"

namespace GestaoTarefas {

    class Gerente : public Funcionario {
        public: 
            Gerente(const int cpf, const std::string& nome, const int idade, const std::string& funcao);
            void executarFuncao() override;
    };  

}
#endif