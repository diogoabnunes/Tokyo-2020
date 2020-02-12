#include "Atleta.h"
using namespace std;

Atleta::Atleta(string n, Data nasc, int passp, string gen, Data cheg, Data part, string mod, double pes, double alt, int rank,
               vector<string> comp) : Pessoa(n, nasc, passp, gen, cheg, part) {
    modalidade = mod;
    peso = pes;
    altura = alt;
    ranking = rank;
    competicoes = comp;
    custo = 250;
}

string Atleta::getModalidade() const {
    return modalidade;
}
double Atleta::getPeso() const {
    return peso;
}
double Atleta::getAltura() const {
    return altura;
}
int Atleta::getRanking() const {
    return ranking;
}
vector<string> Atleta::getCompeticoes() {
    return competicoes;
}
double Atleta::getCusto() const {
    return custo;
}

void Atleta::decompose(string s) {
    Pessoa::decompose(s);

    s = s.substr(s.find_first_of("-") +1);
    for (int i = 1; i <= 6; i++)
        s.erase(0, s.find_first_of("-") +1); // retira a substring de Pessoa

    modalidade = trim(s.substr(0,s.find_first_of("-")));
    s.erase(0, s.find_first_of("-")+1);

    peso = stod(trim(s.substr(0, s.find_first_of("-"))));
    s.erase(0, s.find_first_of("-")+1);

    altura = stod(trim(s.substr(0, s.find_first_of("-"))));
    s.erase(0, s.find_first_of("-")+1);

    ranking = stoi(trim(s.substr(0, s.find_first_of("-"))));
    s.erase(0, s.find_first_of("-")+1);

    string comp = trim(s);
    vector<string> v = string_to_vector(comp);
    competicoes = v;
    s.erase();
}

void Atleta::show() const {
    Pessoa::show();
    cout << "Modalidade: " << getModalidade() << endl;
    cout << "Peso: " << getPeso() << endl;
    cout << "Altura: " << getAltura() << endl;
    cout << "Ranking: " << getRanking() << endl;
    cout << "Competicoes: " << comp_vec_to_str(competicoes) << endl;
    cout << "Custo diario: " << getCusto() << endl;
}

string Atleta::getTipo() const {
    return Pessoa::getTipo()+"Atleta";
}

string Atleta::showCompeticoes() {
    vector<string> v = competicoes;
    string total;
    int n = v.size();
    if (n == 0) return "";
    else if (n == 1) return v[0];
    else if (n == 2) return v[0] + ", " + v[1];
    else {
        for (int i = 0; i < n - 1; i++) {
            total += v[i] + ", ";
        }
        total += v[n - 1];
    }
    return total;
}

void Atleta::setModalidade(string mod) { modalidade = mod; }
void Atleta::setPeso(double pes) { peso = pes; }
void Atleta::setAltura(double alt) { altura = alt; }
void Atleta::setRanking(int rank) { ranking = rank; }
void Atleta::setCompeticoes(vector<string> v) { competicoes = v; }