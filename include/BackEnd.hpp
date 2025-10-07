#ifndef BACKEND_HPP
#define BACKEND_HPP

#include "Desenvolvedor.hpp"
#include <string>

namespace GestaoTarefas {

    class BackEnd  : public virtual Desenvolvedor {
        public:
            BackEnd(const int cpf, const std::string& nome, const int idade, const std::string& funcao);
            void executarFuncao() override;
    };
    
}
#endif