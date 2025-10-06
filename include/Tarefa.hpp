#ifndef TAREFA_HPP
#define TAREFA_HPP
#include "Equipe.hpp"
#include <string>

    class Tarefa {
        private: 
            int _id;
            std::string _descricao;
            int _peso;
            Equipe* _equipeResponsavel;
        
        public:
            Tarefa(int id, const std::string& descricao);
            std::string getDescricao() const;
            int getId() const;
            Equipe* getEquipeResponsavel() const;
            int getPeso() const;
            void setDescricao(const std::string& descricao);
            void setId(int id);
            void setEquipeResponsavel(Equipe* equipeResponsavel);
            void setPeso(int novoPeso);
    };

#endif