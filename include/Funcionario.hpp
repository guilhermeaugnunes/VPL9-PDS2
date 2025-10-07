#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <string>

namespace GestaoTarefas {

    class Funcionario {
        private:
            int _cpf;
            std::string _nome;
            int _idade;
            std::string _funcao;
            
        protected:
            Funcionario(const int cpf, const std::string& nome, const int idade, const std::string& funcao);

        public: 
            virtual ~Funcionario() {};
            int getCpf() const;
            std::string getNome() const;
            int getIdade() const;   
            std::string getFuncao() const;

            void setCpf(const int cpf);
            void setNome(const std::string& nome);
            void setIdade(const int idade);
            void setFuncao(const std::string& funcao);

            virtual void executarFuncao() = 0;
    };

}
#endif
