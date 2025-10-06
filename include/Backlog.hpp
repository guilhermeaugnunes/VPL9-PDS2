#ifndef BACKLOG_HPP
#define BACKLOG_HPP
#include "Tarefa.hpp"
#include <vector>

    class Backlog {
        private: 
            std::vector<Tarefa> _tarefas;
        
        public: 
            Backlog();
            void adicionarTarefaBacklog(const Tarefa& novaTarefa);
            Tarefa removerTarefaBacklog();
            Tarefa* obterMaiorPeso();
    };

#endif