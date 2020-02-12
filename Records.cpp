#include "Records.h"

bool Record::operator<(const Record &r1) const {
    if (this->modalidade == r1.modalidade)
        return this->competicao < r1.competicao;
    return this->modalidade < r1.modalidade;
}
bool Record::operator==(const Record &r1) const {
    return this->modalidade == r1.modalidade && this->competicao == r1.competicao;
}
ostream& operator<<(ostream &os, const Record &r) {
    os << r.modalidade << " - " << r.competicao << " - " << r.realrecord << " - " << r.nome << " - "
       << r.data.getDia() << "/" << r.data.getMes() << "/" << r.data.getAno() << " - " << r.local;
    return os;
}
Record::Record(string r) {
    tipo = trim(r.substr(0, r.find_first_of("-")));
    r.erase(0, r.find_first_of("-")+1);

    modalidade = trim(r.substr(0, r.find_first_of("-")));
    r.erase(0, r.find_first_of("-")+1);

    competicao = trim(r.substr(0,r.find_first_of("-")));
    r.erase(0, r.find_first_of("-")+1);

    realrecord = trim(r.substr(0, r.find_first_of("-")));
    r.erase(0, r.find_first_of("-")+1);

    nome = trim(r.substr(0, r.find_first_of("-")));
    r.erase(0, r.find_first_of("-")+1);

    string aux = trim(r.substr(0, r.find_first_of("-")));
    Data auxdata(aux);
    data = auxdata;
    r.erase(0, r.find_first_of("-")+1);

    local = trim(r);
}
Record::Record(string t, string m, string c, string r, string n, Data d, string l) {
    tipo = t;
    modalidade = m;
    competicao = m;
    realrecord = r;
    nome = n;
    data = d;
    local = l;
}
string Record::getTipo() const { return tipo; }
string Record::getModalidade() const { return modalidade; }
string Record::getCompeticao() const { return competicao; }
string Record::getRealRecord() const { return realrecord; }
string Record::getNome() const { return nome; }
Data Record::getData() const { return data; }
string Record::getLocal() const { return local; }

Time::Time(string t) {
    int n = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '.')
            n++;
    }
    if (n == 1)
    {
        seconds = stoi(t.substr(0,t.find_first_of(".")));
        t.erase(0, t.find_first_of(".")+1);
        hundredths = stoi(t);
    }
    else if (n == 2)
    {
        minutes = stoi(t.substr(0,t.find_first_of(".")));
        t.erase(0, t.find_first_of(".")+1);
        seconds = stoi(t.substr(0,t.find_first_of(".")));
        t.erase(0, t.find_first_of(".")+1);
        hundredths = stoi(t);
    }
    else if (n == 3)
    {
        hours = stoi(t.substr(0,t.find_first_of(".")));
        t.erase(0, t.find_first_of(".")+1);
        minutes = stoi(t.substr(0,t.find_first_of(".")));
        t.erase(0, t.find_first_of(".")+1);
        seconds = stoi(t.substr(0,t.find_first_of(".")));
        t.erase(0, t.find_first_of(".")+1);
        hundredths = stoi(t);
    }
}
Time::Time(int h, int m, int s, int hs) {
    hours = h;
    minutes = m;
    seconds = s;
    hundredths = hs;
}
bool Time::operator<(const Time &t) const {
    if (this->hours == t.hours)
    {
        if (this->minutes == t.minutes)
        {
            if (this->seconds == t.seconds)
            {
                return this->hundredths < t.hundredths;
            }
            return this->seconds < t.seconds;
        }
        return this->minutes < t.minutes;
    }
    return this->hours < t.hours;
}

Distance::Distance(string d) {
    meters = stoi(d.substr(0,d.find_first_of(".")));
    d.erase(0, d.find_first_of(".")+1);
    centimeters = stoi(d);
}
Distance::Distance(int m, int c) {
    meters = m;
    centimeters = c;
}
bool Distance::operator<(const Distance &d) const {
    if (this->meters == d.meters)
        return this->centimeters < d.centimeters;
    return this->meters < d.meters;
}

Points::Points(string p) {
    int n = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (to_string(p[i]) == ".") n++;
    }
    if (n == 0)
    {
        units = stoi(p);
        decimals = 0;
    }
    else if (n == 1)
    {
        units = stoi(p.substr(0,p.find_first_of(".")));
        p.erase(0, p.find_first_of(".")+1);
        decimals = stoi(p);
    }
}
Points::Points(int u, int d) {
    units = u;
    decimals = d;
}
bool Points::operator<(const Points &p) const {
    if (this->units == p.units)
        return this->decimals < p.decimals;
    return this->units < p.units;
}

Records_Tree::Records_Tree(string recs) : recordes(Record("","","","","",(0,0,0),"")) {
    ifstream file;
    file.open(recs + ".txt");

    string line;
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, line);
            Record rec(line);
            recordes.insert(rec);
        }
        file.close();
        line.erase();
        cout << "'records.txt' lido com sucesso!\n";
    }
    else cout << "'records.txt' nao encontrado...\n";
}
void Records_Tree::showRecords() const {
    BSTItrIn<Record> it(recordes);
    while (!it.isAtEnd())
    {
        cout << it.retrieve() << endl;
        it.advance();
    }
}
void Records_Tree::addResult() {
    int option = 0;
    cout << "Tipo:\n[1] Tempo (Natacao, Maratona, ...)\n[2] Distancia (Triplo salto, Lancamento do Peso, ...)\n"
            "[3] Pontos (Ginastica, Natacao Artistica, ...)\n[4] Apenas resultado (nao ha recordes nestas modalidades)\n";
    cout << "[0] Voltar\n";
    cin >> option;

    if (option == 0) return;
    if (option == 4)
    {
        cout << "Como estas modalidades nao tem recordes, nao faz sentido adicionar "
                "este resultado, porque nada vai alterar no programa\n";
        return;
    }

    string tipo;
    switch(option)
    {
        case 1: tipo = "Tempo"; break;
        case 2: tipo = "Distancia"; break;
        case 3: tipo = "Pontos"; break;
        case 4: break;
    }
    clearInput();
    BSTItrIn<Record> it(recordes);
    Record oldRecord("","","","","",(0,0,0),"");

    string mod, competition;
    cout << "Modalidade: ";
    getline(cin, mod);
    cout << "Competicao: ";
    getline(cin, competition);

    bool checkAtualizationNeed = false;

    while (!it.isAtEnd())
    {
        if (it.retrieve().getModalidade() == mod && it.retrieve().getCompeticao() == competition && it.retrieve().getTipo() != tipo)
        {
            cout << "Essa competicao nao se realiza nesse sistema.\n";
            return;
        }
        if (it.retrieve().getModalidade() == mod && it.retrieve().getCompeticao() == competition)
        {
            cout << "Essa competicao ja tem recorde na base de dados\n";
            checkAtualizationNeed = true;
            oldRecord = it.retrieve();
            recordes.remove(it.retrieve());
            break;
        }
        it.advance();
    }

    string result;
    cout << "Resultado: ";
    getline(cin, result);
    string nome;
    cout << "Nome: ";
    getline(cin, nome);
    int d, m, a;
    cout << "Data:\nDia: "; cin >> d; cout << "Mes: "; cin >> m; cout << "Ano: "; cin >> a;
    Data data(d, m, a);
    clearInput();
    string loc; cout << "Local: "; getline(cin, loc);

    Record thisResult(tipo, mod, competition, result, nome, data, loc);
    thisResult.setCompeticao(competition);

    if (!checkAtualizationNeed)
    {
        cout << "Como nao havia este recorde, adicionado\n";
        recordes.insert(thisResult);
    }
    else
    {
        if (tipo == "Tempo")
        {
            Time oldTime(oldRecord.getRealRecord());
            Time newTime(result);
            if (newTime < oldTime) {
                cout << "New world record!\n";
                recordes.insert(thisResult);
            }
            else {
                cout << "This result was not better than the record...\n";
                recordes.insert(oldRecord);
            }
        }
        else if (tipo == "Distancia")
        {
            Distance oldDistance(oldRecord.getRealRecord());
            Distance newDistance(result);
            if (oldDistance < newDistance)
            {
                cout << "New world record!\n";
                recordes.insert(thisResult);
            }
            else {
                cout << "This result was not better than the record...\n";
                recordes.insert(oldRecord);
            }
        }
        else if (tipo == "Pontos")
        {
            Points oldPoints(oldRecord.getRealRecord());
            Points newPoints(result);
            if (oldPoints < newPoints)
            {
                cout << "New world record!\n";
                recordes.insert(thisResult);
            }
            else {
                cout << "This result was not better than the record...\n";
                recordes.insert(oldRecord);
            }
        }
    }
}

void Records_Tree::recSearchByTipo() {
    vector<Record> aux;
    BSTItrIn<Record> it(recordes);

    int option2;
    cout << "Tipo:\n[1] Tempo\n[2] Distancia\n[3] Pontos\n[0] Voltar";
    cin >> option2;

    string tipo;
    switch(option2)
    {
        case 0: return;
        case 1: tipo = "Tempo"; break;
        case 2: tipo = "Distancia"; break;
        case 3: tipo = "Pontos"; break;
        default: return;
    }
    while (!it.isAtEnd())
    {
        if (it.retrieve().getTipo() == tipo)
            aux.push_back(it.retrieve());
        it.advance();
    }
    for (int i = 0; i < aux.size(); i++)
        cout << aux[i] << endl;
}
void Records_Tree::recSearchByModalidade() {
    vector<Record> aux;
    BSTItrIn<Record> it(recordes);
    clearInput();

    string moda; cout << "Modalidade: "; getline(cin, moda);
    while (!it.isAtEnd())
    {
        if (it.retrieve().getModalidade() == moda)
            aux.push_back(it.retrieve());
        it.advance();
    }
    for (int i = 0; i < aux.size(); i++)
        cout << aux[i] << endl;
}
void Records_Tree::recSearchByCompeticao() {
    vector<Record> aux;
    BSTItrIn<Record> it(recordes);
    clearInput();

    string compe; cout << "Competicao: "; getline(cin, compe);
    while (!it.isAtEnd())
    {
        if (it.retrieve().getCompeticao() == compe)
            aux.push_back(it.retrieve());
        it.advance();
    }
    for (int i = 0; i < aux.size(); i++)
        cout << aux[i] << endl;
}
void Records_Tree::recSearchByNome() {
    vector<Record> aux;
    BSTItrIn<Record> it(recordes);
    clearInput();

    string nome; cout << "Nome: "; getline(cin, nome);
    while (!it.isAtEnd())
    {
        if (it.retrieve().getNome() == nome)
            aux.push_back(it.retrieve());
        it.advance();
    }
    for (int i = 0; i < aux.size(); i++)
        cout << aux[i] << endl;
}
void Records_Tree::recSearchByData() {
    vector<Record> aux;
    BSTItrIn<Record> it(recordes);
    clearInput();

    int di, mi, ai, df, mf, af;
    cout << "Data inicial:\nDia: "; cin >> di; cout << "Mes: "; cin >> mi; cout << "Ano: "; cin >> ai;
    cout << "Data final:\nDia: "; cin >> df; cout << "Mes: "; cin >> mf; cout << "Ano: "; cin >> af;
    Data i(di-1,mi,ai);
    Data f(df+1,mf,af);

    while (!it.isAtEnd())
    {
        if (i < it.retrieve().getData() && it.retrieve().getData() < f)
            aux.push_back(it.retrieve());
        it.advance();
    }
    for (int i = 0; i < aux.size(); i++)
        cout << aux[i] << endl;
}
void Records_Tree::recSearchByLocal() {
    vector<Record> aux;
    BSTItrIn<Record> it(recordes);
    clearInput();

    string loca; cout << "Local: "; getline(cin, loca);
    while (!it.isAtEnd())
    {
        if (it.retrieve().getNome() == loca)
            aux.push_back(it.retrieve());
        it.advance();
    }
    for (int i = 0; i < aux.size(); i++)
        cout << aux[i] << endl;
}

bool compareNomes(const Record &r1, const Record &r2) { return r1.getNome() < r2.getNome(); }
void Records_Tree::recOrderByNome() {
    vector<Record> aux;
    BSTItrIn<Record> it(recordes);
    while (!it.isAtEnd())
    {
        aux.push_back(it.retrieve());
        it.advance();
    }
    sort(aux.begin(), aux.end(), compareNomes);
    for (int i = 0; i < aux.size(); i++)
        cout << aux[i] << endl;
}
bool compareDatas(const Record &r1, const Record &r2) { return r1.getData() < r2.getData(); }
void Records_Tree::recOrderByData() {
    vector<Record> aux;
    BSTItrIn<Record> it(recordes);
    while (!it.isAtEnd())
    {
        aux.push_back(it.retrieve());
        it.advance();
    }
    sort(aux.begin(), aux.end(), compareDatas);
    for (int i = 0; i < aux.size(); i++)
        cout << aux[i] << endl;
}
bool compareLocais(const Record &r1, const Record &r2) { return r1.getLocal() < r2.getLocal(); }
void Records_Tree::recOrderByLocal() {
    vector<Record> aux;
    BSTItrIn<Record> it(recordes);
    while (!it.isAtEnd())
    {
        aux.push_back(it.retrieve());
        it.advance();
    }
    sort(aux.begin(), aux.end(), compareLocais);
    for (int i = 0; i < aux.size(); i++)
        cout << aux[i] << endl;
}

void Records_Tree::searchBy() {
    int option = 0;
    cout << "Procurar por:\n";
    cout << "[1] Tipo\n[2] Modalidade\n[3] Competicao\n[4] Nome\n[5] Data\n[6] Local\n[0] Voltar\n";
    cin >> option;
    switch(option)
    {
        case 0: break;
        case 1: recSearchByTipo(); break;
        case 2: recSearchByModalidade(); break;
        case 3: recSearchByCompeticao(); break;
        case 4: recSearchByNome(); break;
        case 5: recSearchByData(); break;
        case 6: recSearchByLocal(); break;
        default: break;
    }

}
void Records_Tree::orderBy() {
    int option = 0;
    cout << "Ordenar por:\n";
    cout << "[1] Nome\n[2] Data\n[3] Local\n[0] Voltar";
    cin >> option;
    switch(option)
    {
        case 0: break;
        case 1: recOrderByNome(); break;
        case 2: recOrderByData(); break;
        case 3: recOrderByLocal(); break;
        default: break;
    }
}
void Records_Tree::menuRecords() {
    int option5 = 0;

    do {
        try {
            while (true) {
                cout << endl;
                cout << "[1] Ver Recordes\n";
                cout << "[2] Adicionar resultado\n";
                cout << "[3] Procurar\n";
                cout << "[4] Ordenar\n";
                cout << "[0] Voltar\n";

                try {
                    if (!(cin >> option5)) {
                        clearInput();
                        throw TipoInvalido();
                    }
                    break;
                }
                catch (TipoInvalido &msg) {
                    cout << msg.getMSG() << endl;
                }
            }

            switch (option5) {
                case 1:
                    showRecords();
                    break;
                case 2:
                    addResult();
                    break;
                case 3:
                    searchBy();
                    break;
                case 4:
                    orderBy();
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        }
        catch (NumeroInvalido &msg) { cout << msg.getMSG() << endl; }
        catch (TipoInvalido &msg) { cout << msg.getMSG() << endl; }

    } while (option5 != 0);
}
void Records_Tree::refreshRecords(string recs) {
    ofstream file;
    file.open(recs + ".txt");
    BSTItrIn<Record> it(recordes);

    if (it.retrieve().getTipo() == "Tempo") file << "Tempo - ";
    if (it.retrieve().getTipo() == "Distancia") file << "Distancia - ";
    if (it.retrieve().getTipo() == "Pontos") file << "Pontos - ";
    file << it.retrieve();
    it.advance();

    while (!it.isAtEnd())
    {
        file << endl;
        if (it.retrieve().getTipo() == "Tempo") file << "Tempo - ";
        if (it.retrieve().getTipo() == "Distancia") file << "Distancia - ";
        if (it.retrieve().getTipo() == "Pontos") file << "Pontos - ";
        file << it.retrieve();
        it.advance();
    }

    file.close();
    cout << "'records.txt' atualizado com sucesso!\n";
}