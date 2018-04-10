#include <iostream>
#include <fstream>
#include <sstream>
#include "pgm.hpp"
#include "arquivo.hpp"

using namespace std;

PGM::PGM(){
	string localArquivo = Arquivo::getLocalArquivo();
	PGM::atribuiLocalMensagem(localArquivo);
}

PGM::~PGM(){}

void PGM::setInicioMensagem(int inicioMensagem){
	this->inicioMensagem = inicioMensagem;
}

int PGM::getInicioMensagem(){
	return inicioMensagem;
}

void PGM::setTamMensagem(int tamMensagem){
	this->tamMensagem = tamMensagem;
}

int PGM::getTamMensagem(){
	return tamMensagem;
}

void PGM::setCifraCesar(int cifraCesar){
	this->cifraCesar = cifraCesar;
}

int PGM::getCifraCesar(){
	return cifraCesar;
}

void PGM::atribuiLocalMensagem(string localArquivo){
	int inicioMensagem = 0, tamMensagem = 0, cifraCesar = 0;

	ifstream imagem(localArquivo.c_str());

	string aux = "";
	getline(imagem, aux); // despreza a primeira linha
	getline(imagem, aux);
	aux.erase(0, 1);

	istringstream iss(aux);
	iss >> inicioMensagem >> tamMensagem >> cifraCesar;	

	imagem.close();

	PGM::setInicioMensagem(inicioMensagem);
	PGM::setTamMensagem(tamMensagem);
	PGM::setCifraCesar(cifraCesar);
}
