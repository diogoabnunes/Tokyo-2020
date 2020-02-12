#ifndef TOKYO2020_PESSOA_H
#define TOKYO2020_PESSOA_H
#include <iostream>
#include <string>
#include "Data.h"
#include "utils.h"
using namespace std;

class Pessoa {
protected:
    string nome;
    Data nascimento;
    int passaporte;
    string genero;
    Data chegada;
    Data partida;
public:
    ///@brief Cria uma Pessoa com os elementos passados como argumentos.
    ///@param n String com o nome da Pessoa a ser criada.
    ///@param nasc Data com a data de nascimento da Pessoa a ser criada.
    ///@param passp Inteiro com o número de passaporte da Pessoa a ser criada.
    ///@param gen String com o género da Pessoa a ser criada.
    ///@param cheg Data com a data de chegada a Tóquio da Pessoa a ser criada.
    ///@param part Data com a data de partida de Tóquio da Pessoa a ser criada.
    ///@return Um objeto da classe Pessoa.
    Pessoa(string n, Data nasc, int passp, string gen, Data cheg, Data part);

    // Funcoes get
    ///@brief Retorna o nome da Pessoa.
    ///@return String com o nome da Pessoa.
    string getNome() const;
    ///@brief Retorna a data de nascimento da Pessoa.
    ///@return Data com a data de nascimento da Pessoa.
    Data getNascimento() const;
    ///@brief Retorna o número de passaporte da Pessoa.
    ///@return Inteiro com o número de passaporte da Pessoa.
    int getPassaporte() const;
    ///@brief Retorna o género da Pessoa.
    ///@return String com o género da Pessoa.
    string getGenero() const;
    ///@brief Retorna a Data de chegada a Tóquio da Pessoa.
    ///@return Data com a data de chegada a Tóquio da Pessoa.
    Data getChegada() const;
    ///@brief Retorna a Data de partida de Tóquio da Pessoa.
    ///@return Data com a data de partida de Tóquio da Pessoa.
    Data getPartida() const;
    ///@brief Esta função retorna a modalidade de um Atleta.
    ///@return String com a modalidade do Atleta.
    virtual string getModalidade() const { return ""; }
    ///@brief Esta função retorna o peso de um Atleta.
    ///@return Double com o peso do Atleta.
    virtual double getPeso() const { return 0; }
    ///@brief Esta função retorna a altura de um Atleta.
    ///@return Double com a altura do Atleta.
    virtual double getAltura() const { return 0; }
    ///@brief Esta função retorna o ranking de um Atleta.
    ///@return Inteiro com o ranking do Atleta.
    virtual int getRanking() const {return 0; }
    ///@brief Esta função retorna as competições de um Atleta.
    ///@return Vector de String com as competições do Atleta.
    virtual vector<string> getCompeticoes() const { vector<string> v; return v; }
    ///@brief Esta função retorna a função de um membro do Staff.
    ///@return String com a função do membro do Staff.
    virtual string getFuncao() const { return ""; }
    ///@brief Retorna 0, visto que o custo é uma propriedade que muda conforme o tipo de pessoa (Atleta ou Staff).
    ///@return Double com o custo da Pessoa.
    virtual double getCusto() const;
    ///@brief Retorna uma string vazia, visto que o tipo de pessoa (Atleta ou Staff) está definido nas suas classes respetivas.
    ///@return String vazia.
    virtual string getTipo() const { return ""; }
    ///@brief Retorna o número de horas de indisponibilidade de um elemento do Funcionario.
    ///@return Inteiro com o número de horas de indisponibilidade do elemento do Funcionario.
    virtual unsigned int getHorasIndisp() const { return 0; }
    ///@brief Retorna a especialidade de um elemento do Funcionario.
    ///@return String com a especialidade do elemento do Funcionario.
    virtual string getEspecialidade() const { return 0; }


    // Funcoes set
    ///@brief Esta função atribui um nome a uma Pessoa.
    ///@param newName String com o nome a ser atribuído a uma Pessoa.
    void setNome(string newName);
    ///@brief Esta função atribui um nascimento a uma Pessoa.
    ///@param newBirthday Data de nascimento a ser atribuída a uma Pessoa.
    void setNascimento(Data newBirthday);
    ///@brief Esta função atribui um passaporte a uma Pessoa.
    ///@param newPassport Inteiro com o número de passaporte a ser atribuído a uma Pessoa.
    void setPassaporte(int newPassport);
    ///@brief Esta função atribui um género a uma Pessoa.
    ///@param newGender String com o género a ser atribuído a uma Pessoa.
    void setGenero(string newGender);
    ///@brief Esta função atribui uma chegada a uma Pessoa.
    ///@param newArrival Data de chegada a Tóquio a ser atribuída a uma Pessoa.
    void setChegada(Data newArrival);
    ///@brief Esta função atribui uma partida a uma Pessoa.
    ///@param newDeparture Data de partida de Tóquio a ser atribuída a uma Pessoa.
    void setPartida(Data newDeparture);
    ///@brief Esta função atribui uma modalidade a um Atleta.
    ///@param mod String com a modalidade a ser atribuída ao Atleta.
    virtual void setModalidade(string mod) { }
    ///@brief Esta função atribui um peso a um Atleta.
    ///@param pes Double com o peso a ser atribuído a um Atleta.
    virtual void setPeso(double pes) { }
    ///@brief Esta função atribui uma altura a um Atleta.
    ///@param alt Double com a altura a ser atribuída a um Atleta.
    virtual void setAltura(double alt) { }
    ///@brief Esta função atribui um ranking a um Atleta.
    ///@param rank Inteiro com o ranking a ser atribuído a um Atleta.
    virtual void setRanking(int rank) { }
    ///@brief Esta função atribui competições a um Atleta.
    ///@param v Vector de String com as competições a serem atribuídas a um Atleta.
    virtual void setCompeticoes(vector<string> v) { }
    ///@brief Esta função atribui uma função a um Staff.
    ///@param f String com a função a ser atribuída a um membro do Staff.
    virtual void setFuncao(string f) { }
    ///@brief Esta função atribui um número de horas de indisponibilidade a um Staff.
    ///@param hIndisp Inteiro com um número de horas de indisponibilidade para atribuir a um elemento de Staff.
    virtual void setHorasIndisp(unsigned int hInd) { }
    ///@brief Esta função atribui uma especialidade a um Staff.
    ///@param esp String com uma especialidade para atribuir a um elemento de Staff.
    virtual void setEspecialidade(string esp) { }
    ///@brief Esta função incrementa um número de horas de indisponibilidade a um Staff.
    ///@param hIndisp Inteiro com um número de horas de indisponibilidade para incrementar a um elemento de Staff.
    virtual void increaseHorasIndisp(unsigned int inc) { }
    ///@brief Esta função decrementa um número de horas de indisponibilidade a um Staff.
    ///@param hIndisp Inteiro com um número de horas de indisponibilidade para decrementar a um elemento de Staff.
    virtual void decreaseHorasIndisp(unsigned int dec) { }

    ///@brief Decompõe os elementos comuns de Atleta e Staff de uma linha em "portugal.txt".
    ///@param s String com a pessoa a ser lida do ficheiro "portugal.txt" e a ser escrita no Vector de apontadores de Pessoas.
    virtual void decompose(string s);
    ///@brief Imprime a informação detalhada dos elementos comuns de Atleta e Staff de uma pessoa.
    virtual void show() const;
    ///@brief Esta função retorna as competições de um Atleta numa string.
    ///@return String com as competições de um Atleta.
    virtual string showCompeticoes() { return ""; };

    virtual bool operator<(Pessoa p) { return false;}
};



#endif //TOKYO2020_PESSOA_H