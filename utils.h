#ifndef TOKYO2020_UTILS_H
#define TOKYO2020_UTILS_H

#include <vector>
#include <string>
#include <algorithm>
#include "Pessoa.h"
using namespace std;

///@brief Remove os espaços no início de uma dada string, passada como argumento.
///@param totrim String que deve ter os espaços à esquerda removidos.
///@return String sem espaços à esquerda.
string ltrim(string totrim);
///@brief Remove os espaços no fim de uma dada string, passada como argumento.
///@param totrim String que deve ter os espaços à direita removidos.
///@return String sem espaços à direita.
string rtrim(string totrim);
///@brief Remove os espaços de uma dada string (no início e no fim), passada como argumento.
///@param totrim String que deve ter os espaços à esquerda e à direita removidos.
///@return String sem espaços ao início nem ao fim.
string trim(string totrim);

///@brief Decompõe uma string com elementos separados por vírgula num vetor com esses elementos.
///@param s String que será transformada em vector.
///@return Vector de strings
vector <string> string_to_vector(string s);
///@brief Transforma um vetor numa string com os elementos do vetor separados por vírgula.
///@param v Vector de strings que será transformado em uma única string.
///@return String com os elementos do vector separados por vírgula.
string comp_vec_to_str(vector <string> v);

///@brief Limpa o input buffer.
void clearInput();

#endif //TOKYO2020_UTILS_H