#ifndef TOKYO2020_EXCEPTION_H
#define TOKYO2020_EXCEPTION_H

#include <string>
#include <iostream>
using namespace std;

class NumeroInvalido {
    string msg;
public:
    ///@brief Cria um objeto da classe NumeroInvalido para lidar com uma exceção de número inválido.
    ///@return Um objeto da classe NumeroInvalido.
    NumeroInvalido();
    ///@brief Esta função retorna a mensagem de erro de número inválido.
    ///@return String com mensagem de erro de número inválido.
    string getMSG();
};

class TipoInvalido {
    string msg;
public:
    ///@brief Cria um objeto da classe TipoInvalido para lidar com uma exceção de tipo inválido.
    ///@return Um objeto da classe TipoInvalido.
    TipoInvalido();
    ///@brief Esta função retorna a mensagem de erro de tipo inválido.
    ///@return String com mensagem de erro de tipo inválido.
    string getMSG();
};

class NoMoreMedalhas {
    string msg;
public:
    ///@brief Cria um objeto da classe NoMoreMedalhas para lidar com uma exceção de passar do limite de medalhas.
    ///@return Um objeto da classe NoMoreMedalhas.
    NoMoreMedalhas();
    ///@brief Esta função retorna a mensagem de erro de passar do limite de medalhas.
    ///@return String com mensagem de erro de passar do limite de medalhas.
    string getMSG();
};

class NoSuchMedalhas {
    string msg;
public:
    ///@brief Cria um objeto da classe NoSuchMedalhas para lidar com uma exceção de medalhas insuficientes.
    ///@return Um objeto da classe NoSuchMedalhas.
    NoSuchMedalhas();
    ///@brief Esta função retorna a mensagem de erro de medalhas insuficientes.
    ///@return String com mensagem de erro de medalhas insuficientes.
    string getMSG();
};

class NoSuchCountry {
    string msg;
public:
    ///@brief Cria um objeto da classe NoSuchCountry para lidar com uma exceção de país inexistente.
    ///@return Um objeto da classe NoSuchCountry.
    NoSuchCountry();
    ///@brief Esta função retorna a mensagem de erro de país inexistente.
    ///@return String com mensagem de erro de país inexistente.
    string getMSG();
};

class NomeInexistente{
    string msg;
public:
    ///@brief Cria um objeto da classe NomeInexistente para lidar com uma exceção de nome inexistente.
    ///@return Um objeto da classe NomeInexistente.
    NomeInexistente();
    ///@brief Esta função retorna a mensagem de erro de nome inexistente.
    ///@return String com mensagem de erro de nome inexistente.
    string getMSG();
};

class DataNascimentoNaoEncontrado{
    string msg;
public:
    ///@brief Cria um objeto da classe DataNascimentoNaoEncontrado para lidar com uma exceção de nascimento não encontrado.
    ///@return Um objeto da classe DataNascimentoNaoEncontrado.
    DataNascimentoNaoEncontrado();
    ///@brief Esta função retorna a mensagem de erro de nascimento não encontrado.
    ///@return String com mensagem de erro de nascimento não encontrado.
    string getMSG();
};

class PassaporteInexistente{
    string msg;
public:
    ///@brief Cria um objeto da classe PassaporteInexistente para lidar com uma exceção de passaporte inexistente.
    ///@return Um objeto da classe PassaporteInexistente.
    PassaporteInexistente();
    ///@brief Esta função retorna a mensagem de erro de passaporte inexistente.
    ///@return String com mensagem de erro de passaporte inexistente.
    string getMSG();
};

class PassaporteJaExistente{
    string msg;
public:
    ///@brief Cria um objeto da classe PassaporteJaExistente para lidar com uma exceção de passaporte já existente.
    ///@return Um objeto da classe PassaporteJaExistente.
    PassaporteJaExistente();
    ///@brief Esta função retorna a mensagem de erro de passaporte já existente.
    ///@return String com mensagem de erro de passaporte já existente.
    string getMSG();
};

class GeneroNaoEncontrado{
    string msg;
public:
    ///@brief Cria um objeto da classe GeneroNaoEncontrado para lidar com uma exceção de género não encontrado.
    ///@return Um objeto da classe GeneroNaoEncontrado.
    GeneroNaoEncontrado();
    ///@brief Esta função retorna a mensagem de erro de género não encontrado.
    ///@return String com mensagem de erro de género não encontrado.
    string getMSG();
};

class ChegadaInexistente{
    string msg;
public:
    ///@brief Cria um objeto da classe ChegadaInexistente para lidar com uma exceção de chegada inexistente.
    ///@return Um objeto da classe ChegadaInexistente.
    ChegadaInexistente();
    ///@brief Esta função retorna a mensagem de erro de chegada inexistente.
    ///@return String com mensagem de erro de chegada inexistente.
    string getMSG();
};

class PartidaInexistente{
    string msg;
public:
    ///@brief Cria um objeto da classe PartidaInexistente para lidar com uma exceção de partida inexistente.
    ///@return Um objeto da classe PartidaInexistente.
    PartidaInexistente();
    ///@brief Esta função retorna a mensagem de erro de partida inexistente.
    ///@return String com mensagem de erro de partida inexistente.
    string getMSG();
};

class AnoInvalido{
    string msg;
public:
    ///@brief Cria um objeto da classe AnoInvalido para lidar com uma exceção de ano inválido.
    ///@return Um objeto da classe AnoInvalido.
    AnoInvalido();
    ///@brief Esta função retorna a mensagem de erro de ano inválido.
    ///@return String com mensagem de erro de ano inválido.
    string getMSG();
};

class MesInvalido{
    string msg;
public:
    ///@brief Cria um objeto da classe MesInvalido para lidar com uma exceção de mês inválido.
    ///@return Um objeto da classe MesInvalido.
    MesInvalido();
    ///@brief Esta função retorna a mensagem de erro de mês inválido.
    ///@return String com mensagem de erro de mês inválido.
    string getMSG();
};

class DiaInvalido{
    string msg;
public:
    ///@brief Cria um objeto da classe DiaInvalido para lidar com uma exceção de dia inválido.
    ///@return Um objeto da classe DiaInvalido.
    DiaInvalido();
    ///@brief Esta função retorna a mensagem de erro de dia inválido.
    ///@return String com mensagem de erro de dia inválido.
    string getMSG();
};

class DataInvalida{
    string msg;
public:
    ///@brief Cria um objeto da classe DataInvalida para lidar com uma exceção de data inválida.
    ///@return Um objeto da classe DataInvalida.
    DataInvalida();
    ///@brief Esta função retorna a mensagem de erro de data inválida.
    ///@return String com mensagem de erro de data inválida.
    string getMSG();
};

class StringVazia{
    string msg;
public:
    ///@brief Cria um objeto da classe StringVazia para lidar com uma exceção de string vazia.
    ///@return Um objeto da classe StringVazia.
    StringVazia();
    ///@brief Esta função retorna a mensagem de erro de string vazia.
    ///@return String com mensagem de erro de string vazia.
    string getMSG();
};

class DataChegadaPartida{
    string msg;
public:
    ///@brief Cria um objeto da class DataChegadaPartida para lidar com datas anteriores serem posteriores a datas posteriores.
    ///@return Um objeto da class DataChegadaPartida.
    DataChegadaPartida();
    ///@brief Esta função retorna a mensagem de erro de datas anteriores serem posteriores a datas posteriores.
    ///@return String com mensagem de erro de data de chegada posterior a data de partida.
    string getMSG();
};
class FuncionarioInexistente{
    string msg;
public:
    ///@brief Cria um objeto da class FuncionarioInexistente para lidar com procura de funcionario inexistentes.
    ///@return Um objeto da class FuncionarioInexistente.
    FuncionarioInexistente();
    ///@brief Esta função retorna a mensagem de erro de funcionario inexistentes.
    ///@return String com mensagem de erro de data de funcionario inexistentes.
    string getMSG();
};

class FuncionarioJaExistente{
    string msg;
public:
    ///@brief Cria um objeto da class FuncionarioJaExistente para lidar com procura de funcionario ja existentes.
    ///@return Um objeto da class FuncionarioJaExistente.
    FuncionarioJaExistente();
    ///@brief Esta função retorna a mensagem de erro de FuncionarioJaExistente.
    ///@return String com mensagem de erro de data de FuncionarioJaExistente.
    string getMSG();
};

#endif //TOKYO2020_EXCEPTION_H