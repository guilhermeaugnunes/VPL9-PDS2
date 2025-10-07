#include "SistemaDistribuicao.hpp"
#include <iostream>
#include <vector>

namespace GestaoTarefas {
    SistemaDistribuicao* SistemaDistribuicao::instancia = nullptr;
    SistemaDistribuicao::SistemaDistribuicao() {}


    SistemaDistribuicao* SistemaDistribuicao::criarSistema() {
        if (instancia == nullptr) {
            instancia = new SistemaDistribuicao();
        }
        return instancia;
    }

    void SistemaDistribuicao::visualizarOciosos() const {
        std::cout << "FUNCIONARIOS OCIOSOS" << std::endl;
        if (_funcionariosOciosos.empty()) {
            std::cout << "(Nenhum funcionario ocioso no momento)" << std::endl;
            return;
        }
        for (Funcionario* func : _funcionariosOciosos) {
            if (func != nullptr) {
                std::cout << "-Nome: " << func->getNome() << std::endl;
                std::cout << "-CPF: " << func->getCpf() << std::endl;
                std::cout << "-Funcao: " << func->getFuncao() << std::endl;
                //std::cout << " " << std::endl;
            }
        }
    } 

    void SistemaDistribuicao::visualizarEquipes() const {
        if (!_equipes.empty()) {
            for (size_t i = 0; i < _equipes.size(); i++) {
                _equipes[i].imprimirEquipe();
            }
        } else {
            std::cout << "Não há equipes no momento" << std::endl;
        }
    }

    void SistemaDistribuicao::adicionarTarefaBacklog(const Tarefa& novaTarefa) {
        this->_backlog.adicionarTarefaBacklog(novaTarefa); 
    }

    void SistemaDistribuicao::removerTarefaBacklog() {
        Equipe* equipeDisponivel = nullptr;
        for (size_t i = 0; i < _equipes.size(); i++) {
            if (_equipes[i].getDisponivel() == true) {
                equipeDisponivel = &_equipes[i];
                break;
            }
        }

        if (equipeDisponivel != nullptr) {
            Tarefa tarefaMovida = _backlog.removerTarefaBacklog();
            tarefaMovida.setEquipeResponsavel(equipeDisponivel);
            equipeDisponivel->setDisponivel(false);
            _tarefasEmAndamento.push_back(tarefaMovida);
            std::cout << "Tarefa " << tarefaMovida.getId() << " alocada para uma equipe." << std::endl;
        } else {
            Tarefa* tarefaParaAtualizar = _backlog.obterMaiorPeso();

            if (tarefaParaAtualizar != nullptr) { 
                int pesoAtual = tarefaParaAtualizar->getPeso();
                tarefaParaAtualizar->setPeso(pesoAtual + 1);

                std::cout << "Nenhum equipe disponível, peso da tarefa de ID: " << tarefaParaAtualizar->getId() << "aumentado para" << tarefaParaAtualizar->getPeso() << "." <<std::endl;
            }
        }
    }

    void SistemaDistribuicao::concluirTarefa(int idTarefa) {
        for (size_t i = 0; i < _tarefasEmAndamento.size(); i++) {
            if (_tarefasEmAndamento[i].getId() == idTarefa) {
                Equipe* equipe = _tarefasEmAndamento[i].getEquipeResponsavel();
                _tarefasConcluidas.push_back(_tarefasEmAndamento[i]);
                _tarefasEmAndamento.erase(_tarefasEmAndamento.begin() + i);

                if (equipe != nullptr) {
                    equipe->setDisponivel(true);
                }
                break;
            }
        }
    }

    void SistemaDistribuicao::criarEquipe(int qtdeDesenvolvedores, int qtdeEngenheirosSoftware) {
        std::vector <Gerente*>  gerentesOciosos;
        std::vector <Desenvolvedor*>  desenvolvedoresOciosos;
        std::vector <EngenheiroSoftware*>  engenheirosSoftwareOciosos;

        for (size_t i = 0; i < _funcionariosOciosos.size(); i++) {
            Funcionario* func_atual = _funcionariosOciosos[i];
            Gerente* g = dynamic_cast<Gerente*>(func_atual);
            if (g != nullptr) {
                gerentesOciosos.push_back(g);
                continue;
            }

            Desenvolvedor* d = dynamic_cast<Desenvolvedor*>(func_atual);
            if (d != nullptr) {
                desenvolvedoresOciosos.push_back(d);
                continue;
            }
            
            EngenheiroSoftware* e = dynamic_cast<EngenheiroSoftware*>(func_atual);
            if (e != nullptr) {
                engenheirosSoftwareOciosos.push_back(e);
                continue;
            }
        }

        if (gerentesOciosos.size() >= 1 && desenvolvedoresOciosos.size() >= qtdeDesenvolvedores && engenheirosSoftwareOciosos.size() >= qtdeEngenheirosSoftware) {
            Gerente* gerentesEscolhido = gerentesOciosos[0];
            /*Desenvolvedor* desenvolvedorEscolhido; = desenvolvedoresOciosos[qtdeDesenvolvedores];
            EngenheiroSoftware* engenheiroSoftwareEscolhido; = engenheirosSoftwareOciosos[qtdeEngenheirosSoftware];*/
            std::vector<Funcionario*> membrosNovaEquipe;

            for (int i = 0; i < qtdeDesenvolvedores; i++) {
                membrosNovaEquipe.push_back(desenvolvedoresOciosos[i]); 
            }

            for (int i = 0; i < qtdeEngenheirosSoftware; i++) {
                membrosNovaEquipe.push_back(engenheirosSoftwareOciosos[i]); 
            }

            Equipe novaEquipe(_proximoIdEquipe, gerentesEscolhido, membrosNovaEquipe);
            _proximoIdEquipe++;
            _equipes.push_back(novaEquipe);
            std::vector <Funcionario*> novosFuncionariosOciosos;

            for (Funcionario* funcionarioOcioso : _funcionariosOciosos) {
                bool foiEscolhido = false;
                
                if (funcionarioOcioso == gerentesEscolhido) {
                    foiEscolhido = true;
                } 
                
                if (!foiEscolhido) {
                    for (Funcionario* membro : membrosNovaEquipe) {
                        if (funcionarioOcioso == membro) {
                            foiEscolhido = true;
                            break;
                        }
                    } 
                }

                if (!foiEscolhido) {
                    novosFuncionariosOciosos.push_back(funcionarioOcioso);
                }
            }
            _funcionariosOciosos = novosFuncionariosOciosos;
        }
    }

    void SistemaDistribuicao::desfazerEquipe(int idEquipe) {
        for (size_t i = 0; i < _equipes.size(); i++) {
            if (_equipes[i].getId() == idEquipe) {
                Gerente* gerente = _equipes[i].getGerente();

                if (gerente != nullptr)
                    _funcionariosOciosos.push_back(gerente);
                
                const std::vector<Funcionario*>& membros = _equipes[i].getFuncionarios();
                for (Funcionario* membro : membros) {
                    _funcionariosOciosos.push_back(membro);
                }
                _equipes.erase(_equipes.begin() + i);
                break;
            }
        }
    }

    void SistemaDistribuicao::demiteFuncionario(int cpf) {
        for (size_t i = 0; i < _funcionariosOciosos.size(); i++) {
            if (_funcionariosOciosos[i]->getCpf() == cpf) {
                delete _funcionariosOciosos[i];
                _funcionariosOciosos.erase(_funcionariosOciosos.begin() + i);
                return;
            }
        }

        for (size_t i = 0; i < _equipes.size(); i++) {
            Gerente* gerente = _equipes[i].getGerente();
            if (gerente != nullptr && gerente->getCpf() == cpf) {
                const std::vector<Funcionario*>& membros = _equipes[i].getFuncionarios();

                for (Funcionario* membro : membros) {
                    _funcionariosOciosos.push_back(membro);
                }
                delete gerente;
                _equipes.erase(_equipes.begin() + i);
                return;
            }
            std::vector<Funcionario*>& membros = _equipes[i].getFuncionarios();
            for (size_t j = 0;  j < membros.size(); j++) {
                if (membros[j]->getCpf() == cpf) {
                    delete membros[j];
                    membros.erase(membros.begin() + j);
                    return;
                }
            }
        } 
    }

    void SistemaDistribuicao::adicionarFuncionario(Funcionario* funcionario) {
        if (funcionario != nullptr) {
            this->_funcionariosOciosos.push_back(funcionario);
        }
    }

    // Implementação do DESTRUTOR para limpar toda a memória
    SistemaDistribuicao::~SistemaDistribuicao() {
        std::cout << "\n--- DESLIGANDO SISTEMA E LIMPANDO MEMORIA ---" << std::endl;
        // Apaga os funcionários que estavam ociosos
        for (Funcionario* f : _funcionariosOciosos) {
            delete f;
        }
        // Apaga os funcionários que ainda estavam em equipes
        for (Equipe& equipe : _equipes) {
            delete equipe.getGerente();
            // Cuidado para não apagar duas vezes, se o getFuncionarios() retornar
            // um ponteiro que já foi limpo, mas neste caso está seguro.
            for (Funcionario* f : equipe.getFuncionarios()) {
                delete f;
            }
        }
        std::cout << "Memoria limpa." << std::endl;
    }
    
}