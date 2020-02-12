#include "Data.h"
using namespace std;

bool Data::validDia(int d, int m, int a)
{
    bool bissexto = false;
    if (a % 4 == 0 && (a % 400 == 0 || a % 100 != 0)) bissexto = true;
    if(m == 1 || m == 3 || m == 5 || m == 7 || m ==8 || m == 10 || m ==12) return (d > 0 && d <= 31);
    else if(m == 2) return ((bissexto && d <= 29 && d > 0) || (!bissexto && d <= 28 && d > 0));
    else return (d > 0 && d <= 30);
}
bool Data::validMes(int m) { return (m > 0 && m <= 12); }
bool Data::validAno(int a) { return (a > 1899 && a < 2100); }

Data::Data(int d, int m, int a) {
    dia = d;
    mes = m;
    ano = a;
}

int Data::getDia() const {
    return dia;
}
int Data::getMes() const {
    return mes;
}
int Data::getAno() const {
    return ano;
}

void Data::show() const {
    cout << getDia() << "/" << getMes() << "/" << getAno();
}

Data::Data(string s) {
    dia = stoi(s.substr(0, s.find_first_of('/')));
    s = s.substr(s.find_first_of('/') + 1);
    mes = stoi(s.substr(0, s.find_first_of('/')));
    s = s.substr(s.find_first_of('/') + 1);
    ano = stoi(s);
}

bool Data::operator==(Data d1) {
    return d1.ano == this->ano && d1.mes == this->mes && d1.dia == this->dia;
}

bool Data::operator<(Data d1) {
    if (this->ano < d1.ano) return true;
    else if (this->ano > d1.ano) return false;
    else
    {
        if (this->mes < d1.mes) return true;
        else if (this->mes > d1.mes) return false;
        else
        {
            if (this->dia < d1.dia) return true;
            else return false;
        }
    }
}

bool Data::validData(int d, int m, int a) {
    return (validDia(d, m, a) && validMes(m) && validAno(a));
}