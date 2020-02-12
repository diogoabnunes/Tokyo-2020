#ifndef TOKYO2020_MENU_H
#define TOKYO2020_MENU_H

#include <iostream>
#include "Comitiva.h"
#include "utils.h"
#include "Exception.h"
#include "Medalhas.h"
#include "Records.h"


using namespace std;

///@brief Esta função é o página inicial do programa. Todos os objetivos do projeto se fazem dentro desta função. Quando sair desta função, acaba o programa.
///@param &comit Endereço de memória onde a Comitiva está.
///@param &medals Endereço de memória onde as Medalhas estão.
void paginaInicial(Comitiva &comit, Medalhas &medals, Records_Tree &records);

#endif //TOKYO2020_MENU_H