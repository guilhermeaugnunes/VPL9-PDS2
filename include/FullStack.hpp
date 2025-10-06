#ifndef FULLSTACK_HPP
#define FULLSTACK_HPP
#include "BackEnd.hpp"
#include "FrontEnd.hpp"

    class FullStack  : public BackEnd,  public FrontEnd {

        public:
            FullStack(const int cpf, const std::string& nome, const int idade, const std::string& funcao);

            void executarFuncao() override;

    };

#endif