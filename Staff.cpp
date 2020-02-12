#include "Staff.h"
using namespace std;

//Constructor
Staff::Staff(string n, Data nasc, int passp, string gen,
             Data cheg, Data part, string func, int cust, unsigned int hInd, string esp)
        : Pessoa(n, nasc, passp, gen, cheg, part) {
    this->funcao = func;
    this->custo = cust;
    this->horasIndisp = hInd;
    this->especialidade = esp;

}

//Get Functions
string Staff::getFuncao() const
{
    return funcao;
}

double Staff::getCusto() const
{
    return custo;
}

string Staff::getTipo() const
{
    return Pessoa::getTipo()+"Staff";
}

unsigned int Staff::getHorasIndisp() const
{
    return this->horasIndisp;
}

string Staff::getEspecialidade() const
{
    return this->especialidade;
}

//Set Functions
void Staff::setFuncao(string f) { funcao = f; }

void Staff::setHorasIndisp(unsigned int hInd)
{
    this->horasIndisp = hInd;
}

void Staff::setEspecialidade(string esp)
{
    this->especialidade = esp;
}

void Staff::increaseHorasIndisp(unsigned int inc)
{
    this->horasIndisp += inc;
}

void Staff::decreaseHorasIndisp(unsigned int dec)
{
    if(this->horasIndisp >= dec)
        this->horasIndisp -= dec;
}

//Other Functions
void Staff::decompose(string s) {
    Pessoa::decompose(s);

    s = s.substr(s.find_first_of("-") +1);
    for (int i = 1; i <= 6; i++)
        s.erase(0, s.find_first_of("-") +1); // retira a substring de Pessoa

    funcao = trim(s.substr(0, s.find_first_of("-"))); // função = "_ _"
    s.erase(0, s.find_first_of("-") +1); // retira "função -"
    this->horasIndisp = stoi(trim(s.substr(0,s.find_first_of("-"))));
    s.erase(0, s.find_first_of("-")+1);

    this->especialidade = trim(s);
    s.erase();

    if (funcao == "Treinador" || funcao == "Arbitro") custo += 500;
    else if (funcao == "Medico") custo += 800;
    else if (funcao == "Dirigente") custo += 750;
    else if (funcao == "Presidente") custo += 1000;
    else if (funcao == "Fisioterapeuta") custo += 700;
    else if (funcao == "Enfermeiro") custo += 600;
    else custo += 400;
}

void Staff::show() const {
    Pessoa::show();
    cout << "Funcao: " << this->getFuncao() << endl;
    cout << "Custo diario: " << this->getCusto() << endl;
    cout << "Horas Indisponíveis: " << this->getHorasIndisp() << endl;
    cout << "Especialidade: " << this->getEspecialidade() << endl;
}

//Operator overloads
bool Staff::operator <(const Staff &func) const
{
    return this->horasIndisp > func.horasIndisp;
}