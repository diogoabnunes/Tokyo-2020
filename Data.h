#ifndef TOKYO2020_DATA_H
#define TOKYO2020_DATA_H
#include <iostream>
#include <string>
using namespace std;

class Data {
private:
    int dia, mes, ano;
public:
    ///@brief Cria uma Data com os elementos passados como argumentos.
    ///@param d Dia da Data.
    ///@param m Mês da Data.
    ///@param a Ano da Data.
    ///@return Objeto da classe Data.
    Data(int d = 1, int m = 1, int a = 1900);
    ///@brief Cria uma Data a partir da string passada como argumento.
    ///@param s String com a Data separada por '/'.
    ///@return Objeto da classe Data.
    Data(string s);

    // Funcoes get
    ///@brief Retorna o dia da Data.
    ///@return Inteiro com o dia da Data.
    int getDia() const;
    ///@brief Retorna o mês da Data.
    ///@return Inteiro com o mês da Data.
    int getMes() const;
    ///@brief Retorna o ano da Data.
    ///@return Inteiro com o ano da Data.
    int getAno() const;

    // Funcoes de validacao da data
    ///@brief Confirma se o dia (elemento passado como argumento) existe.
    ///@param d Dia da Data.
    ///@param m Mes da Data.
    ///@param a Ano da Data.
    ///@return Booleano apontando se o dia existe.
    static bool validDia(int d, int m, int a);
    ///@brief Confirma se o mês (elemento passado como argumento) existe.
    ///@param m Mês da Data.
    ///@return Booleano apontando se o mês existe.
    static bool validMes(int m);
    ///@brief Confirma se o ano (elemento passado como argumento) existe.
    ///@param a Ano da Data.
    ///@return Booleano apontando se o ano existe.
    static bool validAno(int a);
    ///@brief Confirma se a Data é válida.
    ///@param d Inteiro com o dia.
    ///@param m Inteiro com o mês.
    ///@param a Inteiro com o ano.
    ///@return Retorna a validade de uma data.
    static bool validData(int d, int m, int a);

    ///@brief Imprime a data no formato DD/MM/AAAA.
    void show() const;

    // Operadores
    ///@brief Confirma se duas Datas são iguais.
    ///@param d1 Data a ser comparada.
    ///@return Booleano apontando se as Datas são iguais.
    bool operator==(Data d1);
    ///@brief Checa se uma Data é menor do que a outra.
    ///@param d1 Data a ser checada.
    ///@return Booleano apontando se uma Data é menor do que a outra.
    bool operator<(Data d1);
};

#endif //TOKYO2020_DATA_H