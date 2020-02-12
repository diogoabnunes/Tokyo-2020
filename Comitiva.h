#ifndef TOKYO2020_COMITIVA_H
#define TOKYO2020_COMITIVA_H

#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "Pessoa.h"
#include "Atleta.h"
#include "Staff.h"
#include "Data.h"
#include "Exception.h"

struct hFuncionario {
    //Hash function
    int operator()(const Staff &sta) const {
        int key = sta.getPassaporte();
        return key;
    }
};
struct eqFuncionario{
    //Hash equal function
    bool operator()(const Staff &sta1, const Staff &sta2) const {
        return sta1.getPassaporte() == sta2.getPassaporte();
    }
};

typedef unordered_set<Staff,hFuncionario, eqFuncionario> tabHFuncionario;
typedef priority_queue<Staff> HEAP_FUNCIONARIO;

class Comitiva {
private:
    vector<Pessoa*> pessoas;
    HEAP_FUNCIONARIO funcionarios;
    tabHFuncionario funcionarios_atuais;
    tabHFuncionario funcionarios_antigos;
public:
    ///@brief Esta função coloca no vetor "pessoas" todas as pessoas presentes no ficheiro "portugal.txt".
    ///@param comit String com o nome do ficheiro com Atletas e Staff a ser lido.
    ///@param funcs String com o nome do ficheiro de Funcionarios a ser lido
    ///@return Um objeto da classe Comitiva.
    Comitiva(string comit);
    ///@brief Retorna um vetor com toda a comitiva portuguesa (vetor "pessoas").
    ///@return Vector de apontador para Pessoa com as Pessoas da Comitiva.
    vector<Pessoa*> getComitiva() const;
    ///@brief Imprime nome, passaporte e tipo (Atleta ou Staff) de cada pessoa da comitiva portuguesa.
    void showComitiva() const;


    ///@brief Esta função adiciona uma Pessoa ao vetor "pessoas".
    void addPessoa();
    ///@brief Esta função adiciona um Atleta à Comitiva.
    void addAtleta();
    ///@brief Esta função adiciona um Staff à Comitiva.
    void addStaff();
    ///@brief Esta função adiciona um staff do vetor "pessoas", atualizando o ficheiro antes de retornar true.
    ///@param passport Inteiro que é o numero do passaporte do Funcionario a ser adicionado.
    ///@return bool Retorna true caso staff for adicionado com sucesso, false caso staff ja exista.
    bool addFuncionario(Staff &sta);
    ///@brief Esta função edita as informações de uma Pessoa.
    void editPessoa();

    ///@brief Esta função elimina uma Pessoa do vetor "pessoas".
    void elimPessoa();
    ///@brief Esta funcao elimina um staff do vetor "pessoas", atualizando o ficheiro antes de retornar true.
    ///@param passport Inteiro que é o numero do passaporte do Funcionario a ser eliminado.
    ///@return bool Retorna true caso a staff for removido com sucesso, false caso nao encontrado.
    bool elimFuncionario(int passport);

    ///@brief Retorna o custo diário de toda a comitiva portuguesa.
    ///@return Double com o custo diário de toda a comitiva portuguesa
    double getCustoDiario() const;
    ///@brief Imprime toda a informação detalhada de um vetor passado como argumento.
    void showPessoa(Pessoa *p);
    ///@brief Procura no vetor "pessoas" uma pessoa pelo numero de passaporte.
    void findPessoa();

    // Funcoes de pesquisa
    ///@brief Mostra todos os elementos com um nome específico.
    void searchByNome();
    ///@brief Mostra todos os elementos com uma data de nascimento específica.
    void searchByNascimento();
    ///@brief Mostra todos os elementos com um número de passaporte específico.
    void searchByPassaporte();
    ///@brief Mostra todos os elementos de um dado género.
    void searchByGenero();
    ///@brief Mostra todos os elementos com uma data de chegada a Tóquio específica.
    void searchByChegada();
    ///@brief Mostra todos os elementos com uma data de partida de Tóquio específica.
    void searchByPartida();
    ///@brief Mostra todos os elementos com uma modalidade específica de um vetor de atletas passado como argumento.
    void searchByModalidade( vector<Pessoa*> v);
    ///@brief Mostra todos os elementos com um peso específico de um vetor de atletas passado como argumento.
    void searchByPeso( vector<Pessoa*> v);
    ///@brief Mostra todos os elementos com uma altura específica de um vetor de atletas passado como argumento.
    void searchByAltura( vector<Pessoa*> v);
    ///@brief Mostra todos os elementos com um ranking específico de um vetor de atletas passado como argumento.
    void searchByRanking( vector<Pessoa*> v);
    ///@brief Mostra todos os elementos com uma competição específica de um vetor de atletas passado como argumento.
    void searchByCompeticoes( vector<Pessoa*> v);
    ///@brief Mostra todos os elementos com uma função específica de um vetor de membros de staff passado como argumento.
    void searchByFuncao(vector<Pessoa*> v);
    ///@brief Menu para procura por Atletas
    void searchByAtletas();
    ///@brief Menu para procura por membros do Staff
    void searchByStaff();

    // Funcoes de ordenacao
    ///@brief Mostra todos os elementos ordenados pelo nome.
    void orderByNome();
    ///@brief Mostra todos os elementos ordenados pelo nascimento.
    void orderByNascimento();
    ///@brief Mostra todos os elementos ordenados por passaporte.
    void orderByPassaporte();
    ///@brief Mostra todos os elementos ordenados por data de chegada a Tóquio.
    void orderByChegada();
    ///@brief Mostra todos os elementos ordenados por data de partida de Tóquio.
    void orderByPartida();
    ///@brief Mostra todos os elementos ordenados por modalidade
    void orderByModalidade( vector<Pessoa*> v);
    ///@brief Mostra todos os elementos ordenados por peso de um vetor de atletas passado como argumento.
    void orderByPeso( vector<Pessoa*> v);
    ///@brief Mostra todos os elementos ordenados por altura de um vetor de atletas passado como argumento.
    void orderByAltura( vector<Pessoa*> v);
    ///@brief Mostra todos os elementos ordenados por ranking de um vetor de atletas passado como argumento.
    void orderByRanking( vector<Pessoa*> v);
    ///@brief Mostra todos os elementos ordenados por função de um vetor de membros de staff passado como argumento.
    void orderByFuncao(vector<Pessoa*> v);
    ///@brief Menu para ordenação dos Atletas
    void orderByAtletas();
    ///@brief Menu para ordenação dos membros do Staff
    void orderByStaff();

    // Opcoes do menu principal
    ///@brief Esta função mostra as opções para interagir com a Comitiva (adicionar, editar, eliminar, ...).
    void aboutComitiva();

    //Priority Queue
    ///@brief Esta função mostra um menu de serviços que podem ser requeridos por atletas
    void requestService();
    ///@brief Esta função procura um massagista na heap 'funcionarios' e aumenta suas horas de indisponibilidade
    void procuraMassagista();
    ///@brief Esta função procura um enfermeiro na heap 'funcionarios' e aumenta suas horas de indisponibilidade
    void procuraEnfermeiro();
    ///@brief Esta função procura um médico na heap 'funcionarios' e aumenta suas horas de indisponibilidade
    void procuraMedico();
    ///@brief Esta função procura um treinador na heap 'funcionarios' e aumenta suas horas de indisponibilidade
    void procuraTreinador();
    ///@brief Esta função procura um alongador na heap 'funcionarios' e aumenta suas horas de indisponibilidade
    void procuraAlongamento();
    ///@brief Esta função procura um Staff na heap 'funcionarios' e aumenta suas horas de indisponibilidade
    void procuraAcompanhamento();
    ///@brief Esta função mostra como a heap 'funcionarios' está ordenada (no molde Nome - Horas - Especialidade)
    void showHeap();
    ///@brief Esta função atualiza o vector 'pessoas' a partir da heap 'funcionarios' para que o ficheiro 'portugal.txt' também seja atualizado conforme as mudanças feitas durante a execução do programa.
    void updateVector();
    ///@brief Esta função termina os serviços sendo feitos no momento, diminuíndo a indisponibilidade de todos os Staff em 1 hora.
    void endService();



    ///@brief Apenas chama a função de pesquisa que o utilizador escolher.
    void searchBy();
    ///@brief Apenas chama a função de ordenação que o utilizador escolher.
    void orderBy();

    // Atualiza o ficheiro portugal.txt
    ///@brief Esta função atualiza o ficheiro de pessoas (portugal.txt) no fim do programa.
    ///@param comit Nome da comitiva a ter o ficheiro atualizado.
    void refreshComitiva(string comit);


    ///@brief Retorna uma tabela de dispersao com todos os funcionarios, antigos e atuais.
    ///@return tabHFuncionario tabela de dispersao com todos os funcionarios.
    tabHFuncionario get_todos_funcionarios();
    ///@brief Mostra o menu para operacoes de funcionarios que podem ser feitas.
    void menu_funcionarios();
    ///@brief Imprime toda a informação detalhada numa tebela de dispersao com os funcionarios atuais.
    void showfuncionarios_atuais() ;
    ///@brief Imprime toda a informação detalhada numa tebela de dispersao com os funcionarios antigos.
    void showfuncionarios_antigos() ;
    ///@brief Imprime toda a informação detalhada numa tebela de dispersao com os funcionarios antigos e atuais.
    void showtodosfuncionarios() ;
    ///@brief Esta função atualiza o ficheiro de funcionarios antigos (staffantigos.txt) no fim do programa.
    void updateFuncionariofile();
    ///@brief Esta função remove um funcionario antigo do ficheiro (staffantigos.txt), adicionando aos funcionarios
    ///atuais e ao ficheiro da comitiva (portugal.txt).
    void contratar_funcionarioantigo();
    ///@brief Esta função remove um funcionario atual do ficheiro (portugal.txt), adicionando aos funcionarios
    ///antigos e ao ficheiro (staffantigos.txt).
    void despedir_funcionarioatual();

};

#endif //TOKYO2020_COMITIVA_H