#ifndef SISTEMADISTRIBUICAO_HPP
#define SISTEMADISTRIBUICAO_HPP
#include "BackEnd.hpp"
#include "Backlog.hpp"
#include "Desenvolvedor.hpp"
#include "EngenheiroSoftware.hpp"
#include "Equipe.hpp"
#include "FrontEnd.hpp"
#include "FullStack.hpp"
#include "Funcionario.hpp"
#include "Gerente.hpp"
#include "Tarefa.hpp"
#include <vector>

namespace GestaoTarefas {

    class SistemaDistribuicao {
        private: 
            SistemaDistribuicao ();
            static SistemaDistribuicao* instancia; //unica instancia da classe (singleton)
            std::vector<Equipe> _equipes;
            std::vector<Funcionario*> _funcionariosOciosos;
            std::vector<Tarefa> _tarefasConcluidas;
            std::vector<Tarefa> _tarefasEmAndamento;
            Backlog _backlog;
            int _proximoIdEquipe = 1;
            
        public: 
            ~SistemaDistribuicao();
            SistemaDistribuicao(const SistemaDistribuicao&) = delete;
            void operator = (const SistemaDistribuicao&) = delete;
            static SistemaDistribuicao* criarSistema();

            void visualizarOciosos() const;
            void visualizarEquipes() const;
            void adicionarTarefaBacklog(const Tarefa& novaTarefa);
            void removerTarefaBacklog();
            void concluirTarefa(int idTarefa);
            void criarEquipe(int qtdeDesenvolvedores, int qtdeEngenheirosSoftware);
            void desfazerEquipe(int idEquipe);
            void demiteFuncionario(int cpf);
            void adicionarFuncionario(Funcionario* funcionario);
    };

}
#endif