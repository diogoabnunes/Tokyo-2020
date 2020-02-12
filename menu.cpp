#include "menu.h"

void paginaInicial(Comitiva &comit, Medalhas &medals, Records_Tree &records) {
    int option = 0;

    do {
        try {
            while (true) {
                cout << endl;
                cout << "O que quer fazer?" << endl << endl;
                cout << "[1] Comitiva" << endl;
                cout << "[2] Procurar" << endl;
                cout << "[3] Ordenar" << endl;
                cout << "[4] Medalhas" << endl;
                cout << "[5] Recordes" << endl;
                cout << "[6] Funcionarios" << endl;
                cout << "[0] Sair" << endl;
                try {
                    if (!(cin >> option)) {
                        clearInput();
                        throw TipoInvalido();
                    }
                    break;
                }
                catch (TipoInvalido &msg) {
                    cout << msg.getMSG() << endl;
                }
            }
            switch (option) {
                case 1:
                    comit.aboutComitiva();
                    break;
                case 2:
                    comit.searchBy();
                    break;
                case 3:
                    comit.orderBy();
                    break;
                case 4:
                    medals.menuMedalhas();
                    break;
                case 5:
                    records.menuRecords();
                case 6:
                    comit.menu_funcionarios();
                case 0:
                    break;
                default:
                    clearInput();
                    throw NumeroInvalido();
            }
        }
        catch(NumeroInvalido &msg) { cout << msg.getMSG() << endl; }

    } while (option != 0);
}