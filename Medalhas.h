#ifndef TOKYO2020_MEDALHAS_H
#define TOKYO2020_MEDALHAS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "utils.h"
#include "Exception.h"

using namespace std;

class Pais {
    string pais;
    int gold = 0, silver = 0, bronze = 0;
public:
    ///@brief Cria um objeto da classe Pais, representando um país
    ///@param p String com nome do país objeto da classe Pais
    ///@param g Inteiro com número de medalhas de ouro atribuídas ao país objeto da classe Pais
    ///@param s Inteiro com número de medalhas de prata atribuídas ao país objeto da classe Pais
    ///@param b Inteiro com número de medalhas de bronze atribuídas ao país objeto da classe Pais
    ///@return Um objeto da classe Pais
    Pais(string p = "", int g = 0, int s = 0, int b = 0) { pais = p; gold = g; silver = s; bronze = b; }

    // Funcoes get
    ///@brief Retorna o nome do país objeto da classe Pais
    ///@return String com nome do país objeto da classe Pais
    string getPais() const { return pais; }
    ///@brief Retorna o número de medalhas de ouro do país objeto da classe Pais
    ///@return Inteiro com o número de medalhas de ouro do país objeto da classe Pais
    int getGold() const { return gold; }
    ///@brief Retorna o número de medalhas de prata do país objeto da classe Pais
    ///@return Inteiro com o número de medalhas de prata do país objeto da classe Pais
    int getSilver() const { return silver; }
    ///@brief Retorna o número de medalhas de bronze do país objeto da classe Pais
    ///@return Inteiro com o número de medalhas de bronze do país objeto da classe Pais
    int getBronze() const { return bronze; }

    ///@brief Adiciona uma ou mais medalhas de ouro a um país objeto da classe Pais
    ///@param g Inteiro com o número de medalhas de ouro a serem adicionadas ao país objeto da classe Pais
    void addGold(int g) { gold += g; }
    ///@brief Adiciona uma ou mais medalhas de prata a um país objeto da classe Pais
    ///@param s Inteiro com o número de medalhas de prata a serem adicionadas ao país objeto da classe Pais
    void addSilver(int s) { silver += s; }
    ///@brief Adiciona uma ou mais medalhas de bronze a um país objeto da classe Pais
    ///@param b Inteiro com o número de medalhas de bronze a serem adicionadas ao país objeto da classe Pais
    void addBronze(int b) { bronze += b; }
    ///@brief Remove uma ou mais medalhas de ouro a um país objeto da classe Pais
    ///@param g Inteiro com o número de medalhas de ouro a serem removidas do país objeto da classe Pais
    void removeGold(int g) { gold -= g; }
    ///@brief Remove uma ou mais medalhas de prata a um país objeto da classe Pais
    ///@param s Inteiro com o número de medalhas de prata a serem removidas do país objeto da classe Pais
    void removeSilver(int s) { silver -= s; }
    ///@brief Remove uma ou mais medalhas de bronze a um país objeto da classe Pais
    ///@param b Inteiro com o número de medalhas de bronze a serem removidas do país objeto da classe Pais
    void removeBronze(int b) { bronze -= b; }
};

class Medalhas {
private:
    const int maxGold = 306; // 306 competições
    const int maxSilver = 306; // Não complicando, excluindo ex-aequo (empates no pódio, porque alteraria estas contas)
    const int maxBronze = 306;
    int totalGold = 0;
    int totalSilver = 0;
    int totalBronze = 0;
    vector<Pais> paises;
public:
    ///@brief Cria um objeto da classe Medalhas
    ///@param ficheiro String com o nome do ficheiro de medalhas a ser lido
    ///@return Um objeto da classe Medalhas
    Medalhas(string ficheiro);

    // Funcoes get
    ///@brief Retorna o Vector de Pais com os países do objeto da classe Medalhas
    ///@return Vector de Pais com os países do objeto da classe Medalhas
    vector<Pais> getPaises();
    ///@brief Retorna o número máximo de medalhas de ouro
    ///@return Inteiro com o número máximo de medalhas de ouro
    int getMaxGold() const { return maxGold; }
    ///@brief Retorna o número máximo de medalhas de prata
    ///@return Inteiro com o número máximo de medalhas de prata
    int getMaxSilver() const { return maxSilver; }
    ///@brief Retorna o número máximo de medalhas de bronze
    ///@return Inteiro com o número máximo de medalhas de bronze
    int getMaxBronze() const { return maxBronze; }
    ///@brief Retorna o número total de medalhas de ouro
    ///@return Inteiro com o número total de medalhas de ouro
    int getTotalGold() const { return totalGold; }
    ///@brief Retorna o número total de medalhas de prata
    ///@return Inteiro com o número total de medalhas de prata
    int getTotalSilver() const { return totalSilver; }
    ///@brief Retorna o número total de medalhas de bronze
    ///@return Inteiro com o número total de medalhas de bronze
    int getTotalBronze() const { return totalBronze; }

    ///@brief Imprime a tabela de medalhas
    void showMedalTable();
    ///@brief Adiciona medalhas a um país
    void addMedals();
    ///@brief Elimina medalhas de um país
    void elimMedals();

    ///@brief Menu que lida com a intenção do usuário de atribuir medalhas, remover medalhas e ver o quadro de medalhas
    void menuMedalhas();
    ///@brief Esta função reescreve o ficheiro de medalhas conforme as alterações feitas durante o programa
    ///@param ficheiro String com o nome do ficheiro a ser escrito
    void refreshMedalhas(const string& ficheiro);
};

#endif //TOKYO2020_MEDALHAS_H
