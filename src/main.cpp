#include <iostream>
#include "SistemaDistribuicao.hpp"
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

using namespace GestaoTarefas;

int main() {
    std::cout << "--- INICIANDO SIMULACAO DO SISTEMA ---" << std::endl;

    SistemaDistribuicao* sistema = SistemaDistribuicao::criarSistema();

    std::cout << "--- CONTRATANDO FUNCIONARIOS ---" << std::endl;

    sistema->adicionarFuncionario(new Gerente(111, "Carlos", 40, "Gerente"));
    sistema->adicionarFuncionario(new EngenheiroSoftware(555, "Maria", 35, "Engenheiro"));
    sistema->adicionarFuncionario(new EngenheiroSoftware(666, "Pedro", 32, "Engenheiro"));
    sistema->adicionarFuncionario(new FrontEnd(222, "Ana", 25, "FrontEnd"));
    sistema->adicionarFuncionario(new Gerente(298, "Mariana", 39, "Gerente"));
    sistema->adicionarFuncionario(new EngenheiroSoftware(101, "Felipe", 27, "Engenheiro"));
    sistema->adicionarFuncionario(new FrontEnd(108, "Marcos", 28, "FrontEnd"));
    sistema->adicionarFuncionario(new BackEnd(232, "Paulo", 32, "Backend"));
    
    sistema->visualizarOciosos();//Mostra os funcionarios ociosos
    
    std::cout << "\n--- CRIANDO EQUIPE 1 ---" << std::endl;
    sistema->criarEquipe(1, 2); 
    
    std::cout << "\n--- EQUIPES ATUAIS ---" << std::endl;
    sistema->visualizarEquipes();
    sistema->visualizarOciosos();//Mostra os funcionarios ociosos depois de criar a equipe

    std::cout << "\n--- CRIANDO EQUIPE 2 ---" << std::endl;
    sistema->criarEquipe(2, 1); 

    std::cout << "\n--- EQUIPES ATUAIS ---" << std::endl;
    sistema->visualizarEquipes();
    sistema->visualizarOciosos();//Mostra os funcionarios ociosos depois de criar a equipe

    std::cout << "\n--- ADICIONANDO TAREFA AO BACKLOG ---" << std::endl;

    sistema->adicionarTarefaBacklog(Tarefa(101, "Implementar nova interface"));
    sistema->adicionarTarefaBacklog(Tarefa(102, "Editar interface"));
    sistema->adicionarTarefaBacklog(Tarefa(103, "Implementar novos atributos na interface"));
    
    std::cout << "\n--- PROCESSANDO TAREFA DO BACKLOG ---" << std::endl;

    sistema->removerTarefaBacklog();
    sistema->removerTarefaBacklog();

    std::cout << "\n--- EQUIPES APOS PROCESSAR TAREFA ---" << std::endl;
    sistema->visualizarEquipes();

    std::cout << "\n--- CONCLUINDO TAREFA 101 ---" << std::endl;

    sistema->concluirTarefa(101);

    std::cout << "\n--- EQUIPES APOS CONCLUIR TAREFA ---" << std::endl;
    sistema->visualizarEquipes();
    
    std::cout << "\n--- CONCLUINDO TAREFA 102 ---" << std::endl;

    sistema->concluirTarefa(102);

    std::cout << "\n--- EQUIPES APOS CONCLUIR TAREFA ---" << std::endl;
    sistema->visualizarEquipes();

    std::cout << "\n--- DESFAZENDO EQUIPES ---" << std::endl;
    sistema->desfazerEquipe(1);
    sistema->desfazerEquipe(2);

    std::cout << "\n--- EQUIPES RESTANTES ---" << std::endl;
    sistema->visualizarEquipes();

    std::cout << "\n--- DEMITINDO FUNCIONARIOS ---" << std::endl;
    sistema->demiteFuncionario(555);
    sistema->demiteFuncionario(666);
    sistema->demiteFuncionario(111);
    sistema->demiteFuncionario(222);
    sistema->demiteFuncionario(298);
    sistema->demiteFuncionario(232);

    std::cout << "\n--- FUNCIONARIOS RESTANTES ---" << std::endl;
    sistema->visualizarOciosos();

    std::cout << "\n--- FIM DA SIMULACAO ---" << std::endl;

    delete sistema;

    return 0;
}