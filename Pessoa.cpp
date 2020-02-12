#include "Pessoa.h"
using namespace std;

Pessoa::Pessoa(string n, Data nasc, int passp, string gen, Data cheg, Data part) {
    nome = n;
    nascimento = nasc;
    passaporte = passp;
    genero = gen;
    chegada = cheg;
    partida = part;
}


void Pessoa::setNome(string n) { nome = n; }
void Pessoa::setNascimento(Data nasc) { nascimento = nasc; }
void Pessoa::setPassaporte(int passp) { passaporte = passp; }
void Pessoa::setGenero(string gen) { genero = gen; }
void Pessoa::setChegada(Data cheg) { chegada = cheg; }
void Pessoa::setPartida(Data part) { partida = part; }

string Pessoa::getNome() const {
    return nome;
}
Data Pessoa::getNascimento() const {
    return nascimento;
}
int Pessoa::getPassaporte() const {
    return passaporte;
}
string Pessoa::getGenero() const {
    return genero;
}
Data Pessoa::getChegada() const {
    return chegada;
}
Data Pessoa::getPartida() const {
    return partida;
}

void Pessoa::decompose(string s) {
    s = s.substr(s.find_first_of("-") +1); // retira "Atleta -" ou "Staff -"

    nome = trim(s.substr(0, s.find_first_of("-"))); // nome = "_ _"
    s.erase(0, s.find_first_of("-") +1); // retira "nome -"

    string data = trim(s.substr(0, s.find_first_of("-"))); // data = "DD/MM/AAAA"
    Data nasci(data); // string data -> Data data
    nascimento = nasci;
    s.erase(0,s.find_first_of("-")+1); // retira "DD/MM/AAAA"

    passaporte = stoi(trim(s.substr(0,s.find_first_of("-"))));
    s.erase(0, s.find_first_of("-")+1);

    genero = trim(s.substr(0,s.find_first_of("-")));
    s.erase(0, s.find_first_of("-")+1);

    string data1 = trim(s.substr(0, s.find_first_of("-")));
    Data cheg(data1);
    chegada = cheg;
    s.erase(0, s.find_first_of("-")+1);

    string data2 = trim(s.substr(0, s.find_first_of("-")));
    Data part(data2);
    partida = part;
    s.erase(0, s.find_first_of("-")+1);
}

double Pessoa::getCusto() const {
    return 0;
}

void Pessoa::show() const {
    cout << "Nome: " << nome << endl;
    cout << "Nascimento: "; nascimento.show(); cout << endl;
    cout << "Passaporte: " << passaporte << endl;
    cout << "Genero: ";
    if (genero == "M") cout << "Masculino" << endl;
    else if (genero == "F") cout << "Feminino" << endl;
    cout << "Data chegada a Toquio: "; chegada.show(); cout << endl;
    cout << "Data partida de Toquio: "; partida.show(); cout << endl;
}