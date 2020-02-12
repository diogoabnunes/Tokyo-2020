// Tokyo2020 | ProjetoParte1

#include <iostream>
#include "Comitiva.h"
#include "Medalhas.h"
#include "Records.h"
#include "menu.h"
using namespace std;

int main() {
    cout << "\nDelegacao Olimpica de Portugal - Toquio 2020" << endl << endl;

    string pais = "portugal";
    string medals = "medalhas";
    string recs = "records";


    Comitiva comitiva(pais); //creates a comitiva of class Comitiva with info in file portugal.txt
    Medalhas medalhas(medals); //creates a medal table with info in file medalhas.txt
    Records_Tree records(recs); // creates a bst tree with the records


    cout << "The beginning" << endl;
    paginaInicial(comitiva, medalhas, records);

    comitiva.refreshComitiva(pais);
    medalhas.refreshMedalhas(medals);
    records.refreshRecords(recs);

    cout << "\nTHE END!" << endl;
    return 0;
}