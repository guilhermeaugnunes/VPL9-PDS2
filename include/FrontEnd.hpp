#ifndef FRONTEND_HPP
#define FRONTEND_HPP
#include "Desenvolvedor.hpp"

namespace GestaoTarefas {

    class FrontEnd  : public virtual Desenvolvedor {
        public:
            FrontEnd(const int cpf, const std::string& nome, const int idade, const std::string& funcao);
            void executarFuncao() override;
    };

}
#endif