#ifndef TOKYO2020_RECORDS_H
#define TOKYO2020_RECORDS_H

#include "bst.h"
#include "algorithm"
#include "fstream"
#include "iostream"
#include "Atleta.h"
#include "Exception.h"

class Time {
    int hours;
    int minutes;
    int seconds;
    int hundredths;
public:
    ///@brief Cria um objeto da classe Time, que representa um tempo realizado.
    ///@param t String a decompor em horas, minutos, segundos e centésimos.
    ///@return Um objeto da classe Time.
    Time(string t);
    ///@brief Cria um objeto da classe Time, que representa um tempo realizado.
    ///@param h Inteiro que representa o numero de horas.
    ///@param m Inteiro que representa o numero de minutos.
    ///@param s Inteiro que representa o numero de segundos.
    ///@param hs Inteiro que representa o numero de centesimos.
    ///@return Um objeto da classe Time.
    Time(int h = 0, int m = 0, int s = 0, int hs = 0);
    ///@brief Verifica se um objeto da classe Time é menor que outro.
    ///@param t Objeto da classe Time a ser verificado.
    ///@return Um booleano que confirma (ou nao) se um objeto da classe Time é menor que outro.
    bool operator<(const Time &t) const;
};

class Distance {
    int meters;
    int centimeters;
public:
    ///@brief Cria um objeto da classe Distance, que representa uma distancia realizada.
    ///@param t String a decompor em metros e centimetros.
    ///@return Um objeto da classe Distance.
    Distance(string d);
    ///@brief Cria um objeto da classe Distance, que representa uma distancia realizada.
    ///@param m Inteiro que representa o numero de metros.
    ///@param c Inteiro que representa o numero de centimetros.
    ///@return Um objeto da classe Distance.
    Distance(int m = 0, int c = 0);
    ///@brief Verifica se um objeto da classe Distance é menor que outro.
    ///@param d Objeto da classe Distance a ser verificado.
    ///@return Um booleano que confirma (ou nao) se um objeto da classe Distance é menor que outro.
    bool operator<(const Distance &d) const;
};

class Points {
    int units;
    int decimals;
public:
    ///@brief Cria um objeto da classe Points, que representa uma pontuacao realizada.
    ///@param t String a decompor em unidades e casas decimais.
    ///@return Um objeto da classe Points.
    Points(string p);
    ///@brief Cria um objeto da classe Points, que representa uma pontuacao realizada.
    ///@param u Inteiro que representa o numero de unidades.
    ///@param d Inteiro que representa o numero nas casas decimais.
    ///@return Um objeto da classe Points.
    Points(int u = 0, int d = 0);
    ///@brief Verifica se um objeto da classe Points é menor que outro.
    ///@param p Objeto da classe Points a ser verificado.
    ///@return Um booleano que confirma (ou nao) se um objeto da classe Points é menor que outro.
    bool operator<(const Points &p) const;
};

class Record {
    string tipo;
    string modalidade;
    string competicao;
    string realrecord;
    string nome;
    Data data;
    string local;
public:
    ///@brief Cria um objeto da classe Record, que representa um recorde realizado.
    ///@param t String a decompor em tipo, modalidade, competicao, recorde, nome, data e local.
    ///@return Um objeto da classe Record.
    Record(string r);
    ///@brief Cria um objeto da classe Record, que representa um recorde realizado.
    ///@param t String que representa o tipo de recorde (Tempo, Distancia ou Pontuacao).
    ///@param m String que representa a modalidade.
    ///@param c String que representa a competicao.
    ///@param r String que representa o recorde.
    ///@param n String que representa o nome do recordista.
    ///@param d Data que representa a data do recorde.
    ///@param l String que representa o local do recorde.
    ///@return Um objeto da classe Record.
    Record(string t, string m, string c, string r, string n, Data d, string l);
    ///@brief Retorna o tipo (Tempo, Distancia ou Pontuacao) de um Record.
    ///@return String com o tipo (Tempo, Distancia ou Pontuacao) de um Record.
    string getTipo() const;
    ///@brief Retorna a modalidade do recorde.
    ///@return String com a modalidade do recorde.
    string getModalidade() const;
    ///@brief Retorna a competicao do recorde.
    ///@return String com a competicao do recorde.
    string getCompeticao() const;
    ///@brief Retorna o recorde do objeto da classe Record.
    ///@return String com o recorde do objeto da classe Record.
    string getRealRecord() const;
    ///@brief Retorna o nome do recordista.
    ///@return String com o nome do recordista.
    string getNome() const;
    ///@brief Retorna a data do recorde.
    ///@return Data com a data do recorde.
    Data getData() const;
    ///@brief Retorna o local do recorde.
    ///@return String com o local do recorde.
    string getLocal() const;
    ///@brief Esta função atribui uma competicao a um recorde (apenas para resolução de um erro).
    ///@param c String com a competicao a ser atribuida ao objeto da classe Record.
    void setCompeticao(string c) { competicao = c; }
    ///@brief Operator overload para imprimir um objeto da classe Record.
    ///@param os ostream a ser usado para a impressao.
    ///@param r Record a ser impresso.
    ///@return Impressao feita.
    friend ostream &operator<< (ostream &os, const Record &r);
    ///@brief Verifica se um objeto da classe Record é menor que outro.
    ///@param r1 Objeto da classe Record a ser verificado.
    ///@return Um booleano que confirma (ou nao) se um objeto da classe Record é menor que outro.
    bool operator<(const Record &r1) const;
    ///@brief Verifica se um objeto da classe Record é igual a outro.
    ///@param t Objeto da classe Record a ser verificado.
    ///@return Um booleano que confirma (ou nao) se um objeto da classe Record é igual a outro.
    bool operator==(const Record &r1) const;
};

class Records_Tree {
    BST<Record> recordes;
public:
    ///@brief Esta função coloca na BST "recordes" todos os recordes presentes no ficheiro "records.txt".
    ///@param recs String com o nome do ficheiro com os recordes a serem lidos.
    ///@return Um objeto da classe Records_Tree.
    Records_Tree(string recs);
    ///@brief Imprime todos os recordes na BST "Recordes" no mesmo formato do ficheiro "records.txt".
    void showRecords() const;
    ///@brief Adiciona um resultado e, se necessario, atualiza a BST "recordes".
    void addResult();
    ///@brief Mostra todos os recordes com um tipo especifico.
    void recSearchByTipo();
    ///@brief Mostra todos os recordes com uma modalidade especifica.
    void recSearchByModalidade();
    ///@brief Mostra todos os recordes com uma competicao especifica.
    void recSearchByCompeticao();
    ///@brief Mostra todos os recordes com um nome especifico.
    void recSearchByNome();
    ///@brief Mostra todos os recordes com uma data especifica.
    void recSearchByData();
    ///@brief Mostra todos os recordes com um local especifico.
    void recSearchByLocal();
    ///@brief Apenas chama a função de pesquisa que o utilizador escolher.
    void searchBy();
    ///@brief Mostra todos os recordes ordenados pelo nome.
    void recOrderByNome();
    ///@brief Mostra todos os recordes ordenados pela data.
    void recOrderByData();
    ///@brief Mostra todos os recordes ordenados pelo local.
    void recOrderByLocal();
    ///@brief Apenas chama a função de ordenacao que o utilizador escolher.
    void orderBy();
    ///@brief Esta função mostra as opções para interagir com a classe Records_Tree (Ver recordes, Adicionar, procurar, ordenar).
    void menuRecords();
    ///@brief Esta função atualiza o ficheiro de recordes (records.txt) no fim do programa.
    ///@param recs Nome do ficheiro de recordes a ter o ficheiro atualizado.
    void refreshRecords(string recs);
};


#endif //TOKYO2020_RECORDS_H
