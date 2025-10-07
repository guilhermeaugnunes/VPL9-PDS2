#ifndef ENGENHEIROSOFTWARE_HPP
#define ENGENHEIROSOFTWARE_HPP

#include "Funcionario.hpp"

namespace GestaoTarefas {

    class EngenheiroSoftware  : public Funcionario {
        public:
            EngenheiroSoftware(const int cpf, const std::string& nome, const int idade, const std::string& funcao);
            void executarFuncao() override;
    };
    
}
#endif