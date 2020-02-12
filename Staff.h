#ifndef TOKYO2020_STAFF_H
#define TOKYO2020_STAFF_H

#include <iostream>
#include <unordered_set>
#include "Pessoa.h"

using namespace std;

class Staff : public Pessoa {
protected:
    string funcao;
    double custo;
    unsigned int horasIndisp;
    string especialidade;
public:
    ///@brief Cria um elemento do Staff com os elementos passados como argumentos.
    ///@param n String com o nome do elemento do Staff a ser criado.
    ///@param nasc Data de nascimento do elemento do Staff a ser criado.
    ///@param passp Inteiro com o número de passporte do elemento do Staff a ser criado.
    ///@param gen String com o género do elemento do Staff a ser criado.
    ///@param cheg Data de chegada a Tóquio do elemento do Staff a ser criado.
    ///@param part Data de partida de Tóquio do elemento do Staff a ser criado.
    ///@param func String com a função do elemento do Staff a ser criado.
    ///@param custo Inteiro com o custo diário do elemento do Staff a ser criado.
    ///@return Um objeto da classe Staff.
    Staff(string n = "", Data nasc = (0,0,0), int passp = 0, string gen = "", Data cheg = (0,0,0), Data part = (0,0,0),
          string func = "", int custo = 0, unsigned int hInd = 0, string esp = "");

    // Funcoes get
    ///@brief Retorna a função de um elemento do Staff.
    ///@return String com a função do elemento do Staff.
    string getFuncao() const;
    ///@brief Retorna o custo diário de um elemento do staff.
    ///@return Double com o custo diário do elemento do Staff.
    double getCusto() const;
    ///@brief Retorna o tipo (Staff) de um elemento do Staff.
    ///@return String com o tipo (Staff) de um elemento do Staff.
    string getTipo() const;
    ///@brief Retorna o número de horas de indisponibilidade de um elemento do Funcionario.
    ///@return Inteiro com o número de horas de indisponibilidade do elemento do Funcionario.
    unsigned int getHorasIndisp() const;
    ///@brief Retorna a especialidade de um elemento do Funcionario.
    ///@return String com a especialidade do elemento do Funcionario.
    string getEspecialidade() const;

    // Funcoes set
    ///@brief Esta função atribui uma função a um Staff.
    ///@param f String com uma função para atribuir a um elemento de Staff.
    void setFuncao(string f);
    ///@brief Esta função atribui um número de horas de indisponibilidade a um elemento de Staff
    ///@param hInd Inteiro com o número de horas de indisponibilidade a serem atribuídas a um elemnto de Staff
    void setHorasIndisp(unsigned int hInd);
    ///@brief Esta função atribui uma especialidade a um Staff.
    ///@param esp String com uma especialidade para atribuir a um elemento de Staff.
    void setEspecialidade(string esp);
    ///@brief Esta função incrementa um número de horas de indisponibilidade a um Staff.
    ///@param hIndisp Inteiro com um número de horas de indisponibilidade para incrementar a um elemento de Staff.
    void increaseHorasIndisp(unsigned int inc);
    ///@brief Esta função decrementa um número de horas de indisponibilidade a um Staff.
    ///@param hIndisp Inteiro com um número de horas de indisponibilidade para decrementar a um elemento de Staff.
    void decreaseHorasIndisp(unsigned int dec);

    ///@brief Decompõe uma linha de um elemento do Staff em "portugal.txt" nos argumentos do Staff.
    ///@param s String com a linha de um elemento do Staff em "portugal.txt" a ser escrito no Vector de apontadores de Pessoas.
    void decompose(string s);
    ///@brief Imprime a informação detalhada de um elemento do Staff.
    void show() const;

    //Operator overloads
    ///@brief Esta função compara Funcionarios de acordo com sua indisponibilidade
    ///@return Booleano sendo True quando a indisponibilidade do primeiro for maior do que a do segundo; e False no caso contrário
    bool operator <(const Staff &func) const;


};

#endif //TOKYO2020_STAFF_H