#include "Funcionario.hpp"
#include <iostream>
#include <string>

    Funcionario::Funcionario(const int cpf, const std::string& nome, const int idade, const std::string& funcao) :
        _cpf(cpf), _nome(nome), _idade(idade), _funcao(funcao) {}

    int Funcionario::getCpf() const {
        return this-> _cpf;
    }

    std::string Funcionario::getNome() const {
        return this-> _nome;
    }
    int Funcionario::getIdade() const {
        return this-> _idade;
    }
    std::string Funcionario::getFuncao() const {
        return this-> _funcao;
    }

    void Funcionario::setCpf(const int cpf) {
        this-> _cpf =  cpf;
    }

    void Funcionario::setNome(const std::string& nome) {
        this-> _nome = nome;
    }

    void Funcionario::setIdade(const int idade) {
        this-> _idade = idade;
    }

    void Funcionario::setFuncao(const std::string& funcao) {
        this-> _funcao = funcao;
    }
