#include <iostream>
#include "arquivo.hpp"

using namespace std;

Arquivo::Arquivo(){
	cout << "Bem-vindo ao algoritmo de descriptografia de imagens" << endl;
	cout << "Por favor, insira o diretório para a imagem com a respectiva extensão: " << endl;
	Arquivo::recebeLocalArquivo();
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
	Arquivo::atribuiExtensaoArquivo(localArquivo);
}

void Arquivo::atribuiExtensaoArquivo(string localArquivo){
	string extensaoArquivo = "";
	extensaoArquivo = localArquivo.substr(localArquivo.length()-3, 3);

	Arquivo::setExtensaoArquivo(extensaoArquivo);
}
