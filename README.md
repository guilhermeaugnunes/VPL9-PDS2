# VPL 9 - Sistema de Distribuição de Tarefas

Este repositório contém a implementação do VPL 9 para a disciplina de Programação e Desenvolvimento de Software 2.

## Enunciado

Você foi contratado por uma empresa para modelar um sistema de distribuição de tarefas aos empregados. Seu programa deverá utilizar classes, namespace, heranças e composição, além de ser modularizado e encapsulado. Seu programa deverá conter as seguintes classes e interfaces: Tarefa,  Backlog, SistemaDistribuição, Funcionario, Gerente, Desenvolvedor, BackEnd, FrontEnd, FullStack, EngenheiroSoftware e Equipe. Seu programa também deverá ter um arquivo main.cpp simulando o uso das funcionalidades que você implementou!

SistemaDistribuicao será implementado como uma Classe do tipo Singleton, isto é, só existe um objeto do tipo SistemaDistribuicao no sistema. Para isto, use um método estático criarSistema() que cria uma instância do objeto SistemaDistribuicao se ele nunca foi criado, e caso contrário, retorne a instância existente. Seu construtor deverá ser privado. 
 A classe deverá ter os seguintes atributos: coleção de Equipes; coleção de funcionários ociosos, coleção de tarefas em andamento; coleção de tarefas concluídas, e um Backlog (não é coleção). 
Esta classe deverá implementar os seguintes métodos:
 visualizarEquipes que imprimirá no console a coleção das equipes que a empresa possui
um método que irá realizar a adição de uma nova tarefa ao Backlog
um método removerTarefaBacklog que remover uma tarefa do Backlog e coloca na coleção de Tarefas Concluidas. O método deverá verificar se existe uma Equipe disponível para trabalhar no backlog. Caso exista, a tarefa deverá ser removida do backlog e inserida na coleção de trabalhos em andamento. Caso não exista, aumente o peso da tarefa em 1. 
Método concluirTarefa: remove Tarefa da coleção de tarefas e a coloca na coleção de tarefas concluídas. Também deverá tornar a Equipe responsável disponível. 
Método criarEquipe que recebe como parâmetro dois números inteiros positivos (quantidade de desenvolvedor e quantidade de EngenheiroSoftware), e dado os funcionários ociosos, verifica se é possível criar a Equipe. Caso não tenha funcionários disponíveis, imprima que não é possível criar equipe. Caso contrário, o método irá cria um novo objeto do tipo Equipe, o adicionando o à coleção de equipes, e deve remover os funcionários selecionados da coleção de funcionários ociosos. Seu propgrama deverá garantir que os dois inteiros não possam ser alterados durante a criação da Equipe (const/constexpr).
 Método desfazerEquipe, que desfaz a Equipe e coloca as pessoas na coleção de funcionários ociosos. 
Método demiteFuncionario, que exclui o funcionário das coleções que ele faz parte, isto é, você deverá garantir que o restante do programa está consistente. 
Tarefa deverá conter: descrição, id, ponteiro para a Equipe responsável, um inteiro peso que irá realizar a tarefa, métodos sets e getters para cada um dos atributos. Peso deverá ser inicializado como 0 e somente será atualizado ao chamar SistemaDistribuicao sis.removerTarefaBacklog. Você poderá trocar a Equipe responsável (método set), desde que exista uma equipe disponível.
Backlog mantém uma coleção de Tarefas que serão realizadas, e deverá ter os seguintes métodos: adicionarTarefaBacklog, em que se adiciona um objeto do tipo Tarefa a coleção de tarefas; removerTarefaBacklog, que remove a tarefa de maior peso do backlog. Caso o Backlog esteja vazio, imprima que não existe itens a serem removidos. Caso todas as tarefas tiver o mesmo peso, remover a primeira ocorrência do peso.
Funcionario deverá conter um número do cpf, nome, idade, função, e os métodos get e set associados. Construtor deverá ser protected. Deverá ter o método virtual executarFuncao.
Gerente, Desenvolvedor e EngenheiroSoftware deverão herdar de  Funcionario, e possuierem o método executarFunção(). 
Para o Gerente, o método deve imprimir: Gerenciado equipe. 
Desenvolvedor deverá ser uma classe abstrata, e não deverá implementar executarFuncao. 
O Engenheiro de Software deverá imprimir: Arquitetando Solução. 
Interfaces (.hpp) para Gerente, Desenvolvedor e EngenheiroSoftware deverão ter seus métodos virtuais (isto é, criando uma interface).
Extenda a classe Desenvolvedor com as classes FrontEnd e BackEnd. Crie uma nova classe FullStack que herda de FrontEnd e BackEnd. No executarFunção, FrontEnd deverá imprimir: Trabalhando com Interfaces Gráficas. BackEnd deverá imprimir: Trabalhando com regras de negócio. FullStack deverá imprimir: Trabalhando com Interfaces Gráficas e Regras de Negócio.
Equipe deverá conter um atributo status, Gerente e uma coleção de Funcionário. A equipe deverá ter os seguintes métodos:  imprimirEquipe que imprime o status atual da Equipe (se está disponível ou não), o nome do Gerente, e imprime o nome e função do Funcionários que participam da equipe.
Seu programa deverá implementar os desconstrutores para não haver memory leak!

Dicas para estudar pra prova ao fazer este VPL:

- Use ponteiros sempre que possível!

- Use namespace!

- Use métodos que recebe como parâmetro tanto ponteiros quanto endereços de memória.

- Crie um makefile para seu programa!

- Utilize as boas práticas de programação ensinadas nas aulas.

- Tente criar outros métodos estáticos.

## Visão Geral da Solução

A solução foi desenvolvida em C++11, aplicando os seguintes conceitos de POO:
* **Encapsulamento:** Todos os atributos das classes são privados e acedidos via métodos públicos.
* **Herança:** Foi criada uma hierarquia de `Funcionario` para modelar os diferentes cargos. A herança múltipla (e virtual) foi utilizada para a classe `FullStack`.
* **Polimorfismo:** O método `executarFuncao()` foi declarado como `virtual` para permitir comportamentos diferentes para cada tipo de funcionário.

## Como Compilar e Executar

Para compilar e executar o projeto, certifique-se de que tem o `g++` e o `make` instalados e execute o seguinte comando na raiz do projeto:

```bash
make run