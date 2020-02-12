#include "Exception.h"

NumeroInvalido::NumeroInvalido() {
    msg = "************************************\nMENSAGEM DE ERRO: NUMERO INVALIDO! \n************************************";
}
string NumeroInvalido::getMSG(){
    return this->msg;
}
TipoInvalido::TipoInvalido() {
    msg = "************************************\nMENSAGEM DE ERRO: TIPO INVALIDO! \n************************************";
}
string TipoInvalido::getMSG() {
    return this->msg;
}
NoMoreMedalhas::NoMoreMedalhas() {
    msg = "************************************\nMENSAGEM DE ERRO: O NUMERO DE MEDALHAS INTRODUZIDAS ULTRAPASSA O MAXIMO PERMITIDO! \n************************************";
}
string NoMoreMedalhas::getMSG() {
    return this->msg;
}
NoSuchMedalhas::NoSuchMedalhas() {
    msg = "************************************\nMENSAGEM DE ERRO: O PAIS QUE ESCOLHEU NAO TEM TANTAS MEDALHAS DESSE TIPO! \n************************************";
}
string NoSuchMedalhas::getMSG() {
    return this->msg;
}
NoSuchCountry::NoSuchCountry() {
    msg = "************************************\nMENSAGEM DE ERRO: ESSE PAIS NAO EXXISTE! \n************************************";
}
string NoSuchCountry::getMSG() {
    return this->msg;
}
NomeInexistente::NomeInexistente(){
    msg = "***************************************\nMENSAGEM DE ALERTA: NOME INEXISTENTE! \n***************************************";
};
string NomeInexistente::getMSG() {{
        return this->msg;
    }}
DataNascimentoNaoEncontrado::DataNascimentoNaoEncontrado() {
    msg = "*********************************************\nMENSAGEM DE ALERTA: NAO FOI POSSIVEL \nENCONTRAR PESSOA COM DATA DE NASCIMENTO INSERIDO! \n*********************************************";
}
string DataNascimentoNaoEncontrado::getMSG() {
    return this->msg;
}
PassaporteInexistente::PassaporteInexistente() {
    msg = "*****************************************\nMENSAGEM DE ALERTA: PASSAPORTE INEXISTENTE! \n*****************************************";
}
string PassaporteInexistente::getMSG() {
    return this->msg;
}
PassaporteJaExistente::PassaporteJaExistente() {
    msg = "*****************************************\nMENSAGEM DE ALERTA: PASSAPORTE INEXISTENTE! \n*****************************************";
}
string PassaporteJaExistente::getMSG() {
    return this->msg;
}
GeneroNaoEncontrado::GeneroNaoEncontrado() {
    msg = "***************************************\nMENSAGEM DE ALERTA: GENERO NAO ENCONTRADO! \n***************************************";
}
string GeneroNaoEncontrado::getMSG() {
    return this->msg;
}
ChegadaInexistente::ChegadaInexistente() {
    msg = "*****************************************\nMENSAGEM DE ALERTA: CHEGADA INEXISTENTE! \n*****************************************";
}
string ChegadaInexistente::getMSG() {
    return this->msg;
}
PartidaInexistente::PartidaInexistente() {
    msg = "*****************************************\nMENSAGEM DE ALERTA: PARTIDA INEXISTENTE! \n*****************************************";
}
string PartidaInexistente::getMSG() {
    return this->msg;
}
DiaInvalido::DiaInvalido() {
    msg = "************************************\nMENSAGEM DE ERRO: DIA INVALIDO! \n************************************";
}
string DiaInvalido::getMSG() {
    return this->msg;
}
MesInvalido::MesInvalido() {
    msg = "************************************\nMENSAGEM DE ERRO: MES INVALIDO! \n************************************";
}
string MesInvalido::getMSG() {
    return this->msg;
}
AnoInvalido::AnoInvalido() {
    msg = "************************************\nMENSAGEM DE ERRO: ANO INVALIDO! \n************************************";
}
string AnoInvalido::getMSG() {
    return this->msg;
}
DataInvalida::DataInvalida() {
    msg = "************************************\nMENSAGEM DE ERRO: DATA INVALIDA! \n************************************";
}
string DataInvalida::getMSG() {
    return this->msg;
}
StringVazia::StringVazia() {
    msg = "************************************\nMENSAGEM DE ERRO: INSERIU UMA STRING VAZIA! \n************************************";
}
string StringVazia::getMSG() {
    return this->msg;
}
DataChegadaPartida::DataChegadaPartida() {
    msg = "************************************\nMENSAGEM DE ERRO: DATA DE CHEGADA POSTERIOR A DATA DE PARTIDA! \n************************************";
}
string DataChegadaPartida::getMSG() {
    return this->msg;
}
FuncionarioInexistente::FuncionarioInexistente() {
    msg = "************************************\nMENSAGEM DE ERRO: FUNCIONARIO NAO EXISTE! \n************************************";
}
string FuncionarioInexistente::getMSG() {
    return this->msg;
}

FuncionarioJaExistente::FuncionarioJaExistente() {
    msg = "************************************\nMENSAGEM DE ERRO: ESTE FUNCIONARIO JA EXISTE! \n************************************";
}
string FuncionarioJaExistente::getMSG() {
    return this->msg;
}