#include "Medalhas.h"

Medalhas::Medalhas(string ficheiro) {
    ifstream file;
    file.open(ficheiro + ".txt");

    string line;
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, line);
            string pais;
            int g = 0, s = 0, b = 0;
            pais = trim(line.substr(0, line.find_first_of(" - ")));
            line.erase(0, line.find_first_of(" - ") + 3);
            g = stoi(trim(line.substr(0, line.find_first_of(","))));
            line.erase(0, line.find_first_of(",") + 2);
            s = stoi(trim(line.substr(0, line.find_first_of(","))));
            line.erase(0, line.find_first_of(",") + 2);
            b = stoi(line);
            line.erase();
            Pais country(pais, g, s, b);
            paises.push_back(country); // Ja lê tudo direito
            totalGold += g; totalSilver += s; totalBronze += b;
        }
        file.close();
        line.erase();
        cout << "'medalhas.txt' lido com sucesso!\n";
    }
    else cout << "'medalhas.txt' nao encontrado...\n";
}

vector<Pais> Medalhas::getPaises() {
    return paises;
}

bool compareMedals(Pais p1, Pais p2)
{
    if (p1.getGold() == p2.getGold())
    {
        if (p1.getSilver() == p2.getSilver())
        {
            return p1.getBronze() > p2.getBronze();
        }
        return p1.getSilver() > p2.getSilver();
    }
    return p1.getGold() > p2.getGold();
}
void Medalhas::showMedalTable() {
    vector<Pais> v = paises;
    sort(v.begin(), v.end(), compareMedals);

    cout << setw(20) << "Pais" << "\tOuro\tPrata\tBronze\tTotal\n\n";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        int totalMedalCountry = (*it).getGold() + (*it).getSilver() + (*it).getBronze();

        cout << setw(20) << (*it).getPais() << "\t"
             << (*it).getGold() << "\t" << (*it).getSilver() << "\t" << (*it).getBronze() << "\t" << totalMedalCountry << "\n";
    }
    int restGold = maxGold - totalGold, restSilver = maxSilver - totalSilver, restBronze = maxBronze - totalBronze;
    cout << "\nEstao por entregar: " << restGold << " medalhas de ouro, "
    << restSilver << " de prata e " << restBronze << " de bronze!" << endl << endl;
}

void Medalhas::addMedals() {

    clearInput();
    string pais;
    cout << "Escolha um pais para adicionar medalhas: ";
    getline(cin, pais);
    if (pais == "") throw StringVazia();

    int tipo;
    cout << "[1] Ouro\n[2] Prata\n[3] Bronze\n";
    if (!(cin >> tipo)) throw TipoInvalido();
    if (tipo == 0 || tipo > 3) throw NumeroInvalido();

    int q;
    cout << "Quantidade: ";
    if (!(cin >> q)) throw TipoInvalido();

    for (auto it = paises.begin(); it != paises.end(); it++) {
        if ((*it).getPais() == pais) {
            if ((tipo == 1) && (getTotalGold() + q <= getMaxGold())) { (*it).addGold(q); return; }
            else if ((tipo == 2) && (getTotalSilver() + q <= getMaxSilver())) { (*it).addSilver(q); return; }
            else if ((tipo == 3) && (getTotalBronze() + q <= getMaxBronze())) { (*it).addBronze(q); return; }
            else throw NoMoreMedalhas();
        }
    }
    if (tipo == 1 && q <= getMaxGold()) { Pais country(pais, q, 0, 0); paises.push_back(country); return; }
    else if (tipo == 2 && q <= getMaxSilver()) { Pais country(pais, 0, q, 0); paises.push_back(country); return; }
    else if (tipo == 3 && q <= getMaxBronze()) { Pais country(pais, 0, 0, q); paises.push_back(country); return; }
    else throw NoMoreMedalhas();
}

void Medalhas::elimMedals() {

    clearInput();
    string pais;
    cout << "Escolha um pais para remover medalhas: ";
    getline(cin, pais);
    if (pais == "") throw StringVazia();

    bool found = false;
    for (auto it = paises.begin(); it != paises.end(); it++)
    {
        if ((*it).getPais() == pais) found = true;
    }
    if (!found) throw NoSuchCountry();

    int tipo;
    cout << "[1] Ouro\n[2] Prata\n[3] Bronze\n";
    if (!(cin >> tipo)) throw TipoInvalido();
    if (tipo == 0 || tipo > 3) throw NumeroInvalido();

    int q;
    cout << "Quantidade: ";
    if (!(cin >> q)) throw TipoInvalido();

    for (auto it = paises.begin(); it != paises.end(); it++) {
        if ((*it).getPais() == pais) {
            found = true;
            if ((tipo == 1) && ((*it).getGold() - q >= 0)) { (*it).removeGold(q); return; }
            else if ((tipo == 2) && ((*it).getSilver() - q >= 0)) { (*it).removeSilver(q); return; }
            else if ((tipo == 3) && ((*it).getBronze() - q >= 0)) { (*it).removeBronze(q); return; }
            else throw NoSuchMedalhas();
        }
    }
    throw NoSuchCountry();
}

void Medalhas::menuMedalhas() {
    clearInput();
    int option = 0;

    do {
        try {
            while (true) {
                cout << "O que pretende fazer?" << endl;
                cout << "[1] Consultar Quadro de Medalhas\n"
                        "[2] Atribuir Medalhas a um pais\n"
                        "[3] Retirar Medalhas a um pais\n"
                        "[0] Voltar\n";
                try {
                    if (!(cin >> option)) { clearInput(); throw TipoInvalido(); }
                    break;
                }
                catch (TipoInvalido &msg) { cout << msg.getMSG() << endl; }
            }
            switch (option) {
                case 1:
                    showMedalTable();
                    break;
                case 2:
                    addMedals();
                    break;
                case 3:
                    elimMedals();
                    break;
                case 0:
                    break;
                default:
                    clearInput();
                    throw NumeroInvalido();
            }
        }
        catch(NumeroInvalido &msg) { cout << msg.getMSG()<< endl; }
        catch(TipoInvalido &msg) { cout << msg.getMSG()<< endl; }
        catch(NoMoreMedalhas &msg) { cout << msg.getMSG()<< endl; }
        catch(NoSuchMedalhas &msg) { cout << msg.getMSG()<< endl; }
        catch(NoSuchCountry &msg) { cout << msg.getMSG()<< endl; }
        catch(StringVazia &msg) { cout << msg.getMSG() << endl; }

    } while (option != 0);
}

void Medalhas::refreshMedalhas(const string& ficheiro) {

    ofstream file;
    file.open( ficheiro + ".txt");

    auto it = paises.begin();
    file << (*it).getPais() << " - " << (*it).getGold() << ", " << (*it).getSilver() << ", " << (*it).getBronze();
    for (auto it = paises.begin() + 1; it != paises.end(); it++)
    {
        file << endl;
        file << (*it).getPais() << " - " << (*it).getGold() << ", " << (*it).getSilver() << ", " << (*it).getBronze();
    }
    file.close();
    cout << "'medalhas.txt' atualizado com sucesso!\n";
}