
#ifndef TOKYO2020_ATLETA_H
#define TOKYO2020_ATLETA_H

#include "Pessoa.h"
#include <iostream>
#include <vector>

using namespace std;

class Atleta : public Pessoa {
protected:
    string modalidade;
    double peso;
    double altura;
    int ranking;
    vector<string> competicoes;
    double custo;
public:
    ///@brief Cria um Atleta com os elementos passados como argumentos.
    ///@param n String com o nome do Atleta a ser criado.
    ///@param nasc Data com o nascimento do Atleta a ser criado.
    ///@param passp Inteiro com o número de passporte do Atleta a ser criado.
    ///@param gen String com o género do Atleta a ser criado.
    ///@param cheg Data de chegada a Tóquio do Atleta a ser criado.
    ///@param part Data de partida de Tóquio do Atleta a ser criado.
    ///@param mod String com a modalidade do Atleta a ser criado.
    ///@param pes Double com o peso do Atleta a ser criado.
    ///@param alt Double com a altura do Atleta a ser criado.
    ///@param rank Inteiro com o ranking do Atleta a ser criado.
    ///@param comp Vector de String com as competições do Atleta a ser criado.
    ///@return Retorna um objeto da classe Atleta.
    Atleta(string n = "", Data nasc = (0,0,0), int passp = 0, string gen = "", Data cheg = (0,0,0), Data part = (0,0,0),
           string mod = "", double pes = 0, double alt = 0, int rank = 0, vector<string> comp = {});

    // Funcoes set
    ///@brief Esta função atribui uma modalidade a um Atleta.
    ///@param mod String com a modalidade a ser atribuída a um Atleta.
    void setModalidade(string mod);
    ///@brief Esta função atribui um peso a um Atleta.
    ///@param pes Double com o peso a ser atribuído a um Atleta.
    void setPeso(double pes);
    ///@brief Esta função atribui uma altura a um Atleta.
    ///@param alt Double com a altura a ser atribuída a um Atleta.
    void setAltura(double alt);
    ///@brief Esta função atribui um ranking a um Atleta.
    ///@param rank Inteiro com o ranking a ser atribuído a um Atleta.
    void setRanking(int rank);
    ///@brief Esta função atribui competições a um Atleta.
    ///@param v Vector de String com as competições a serem atribuídas a um Atleta.
    void setCompeticoes(vector<string> v);

    // Funcoes get
    ///@brief Retorna a modalidade do Atleta.
    ///@return String com a modalidade do Atleta.
    string getModalidade() const;
    ///@brief Retorna o peso do Atleta.
    ///@return Double com o peso do Atleta.
    double getPeso() const;
    ///@brief Retorna a altura do Atleta.
    ///@return Double com a altura do Atleta.
    double getAltura() const;
    ///@brief Retorna o ranking do Atleta.
    ///@return Inteiro com o ranking do Atleta.
    int getRanking() const;
    ///@brief Retorna um vetor com as competições do Atleta.
    ///@return Vector de String com as competições do Atleta.
    vector<string> getCompeticoes();
    ///@brief Retorna o custo diário do Atleta.
    ///@return Double com o custo diário do Atleta.
    double getCusto() const;
    ///@brief Retorna o tipo (Atleta) de um Atleta.
    ///@return String com o tipo (Atleta) de um Atleta.
    string getTipo() const;

    ///@brief Decompõe os elementos exclusivos de Atleta de uma linha em "portugal.txt".
    ///@param s String com a pessoa a ser lida do ficheiro "portugal.txt" e a ser escrita no Vector de apontadores de Pessoas.
    void decompose(string s);
    ///@brief Imprime a informação detalhada de um Atleta.
    void show() const;
    ///@brief Esta função retorna as competições de um Atleta.
    ///@return String com as competições de um Atleta.
    string showCompeticoes();
};

#endif //TOKYO2020_ATLETA_H
