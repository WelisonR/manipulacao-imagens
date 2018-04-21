#include <iostream>
#include <fstream>
#include "arquivo.hpp"

using namespace std;

Arquivo::Arquivo(){
	Arquivo::recebeLocalArquivo();
	Arquivo::atribuiExtensaoArquivo();
	Arquivo::verificaExcecao();
}

Arquivo::~Arquivo(){}

void Arquivo::setLocalArquivo(string localArquivo){
	this->localArquivo = localArquivo;
}

string Arquivo::getLocalArquivo(){
	return localArquivo;
}

void Arquivo::setExtensaoArquivo(string extensaoArquivo){
	this->extensaoArquivo = extensaoArquivo;
}

string Arquivo::getExtensaoArquivo(){
	return extensaoArquivo;
}

void Arquivo::recebeLocalArquivo(){
	string localArquivo= "";
	cin >> localArquivo;

	Arquivo::setLocalArquivo(localArquivo);
}

void Arquivo::atribuiExtensaoArquivo(){
	string extensaoArquivo = "";
	extensaoArquivo = localArquivo.substr(Arquivo::getLocalArquivo().length()-3, 3);

	Arquivo::setExtensaoArquivo(extensaoArquivo);
}

void Arquivo::verificaExcecao(){
	if (Arquivo::getExtensaoArquivo() != "ppm" && Arquivo::getExtensaoArquivo() != "pgm"){
		throw(0);
	}

	ifstream imagem(Arquivo::getLocalArquivo().c_str());
	if (!imagem.is_open()){
		throw(1);	
	}
}
