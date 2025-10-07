#ifndef EQUIPE_HPP
#define EQUIPE_HPP
#include <vector>
#include "Gerente.hpp"
#include "Funcionario.hpp"
#include <string>

class Equipe {

    private:
        bool _status;
        Gerente* _gerente;
        std::vector<Funcionario*> _funcionarios;
        int _id;

    public: 
        Equipe(int id, Gerente* gerente, const std::vector<Funcionario*>& funcionarios);
        void imprimirEquipe() const;
        std::vector<Funcionario*>& getFuncionarios();
        Gerente* getGerente() const;
        int getId() const;
        bool getDisponivel() const;
        void setDisponivel(bool status);

};

#endif