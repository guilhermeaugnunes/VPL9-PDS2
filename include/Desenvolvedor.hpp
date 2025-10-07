#ifndef DESENVOLVEDOR_HPP
#define DESENVOLVEDOR_HPP

#include "Funcionario.hpp"

namespace GestaoTarefas {

    class Desenvolvedor  : public virtual Funcionario {
        public:
            Desenvolvedor(const int cpf, const std::string& nome, const int idade, const std::string& funcao);
            void executarFuncao() override = 0;
            virtual ~Desenvolvedor();
    };

}
#endif