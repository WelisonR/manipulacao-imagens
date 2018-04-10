#include "menu.hpp"
#include <iostream>

using namespace std;

Menu::Menu(){
	cout << "Bem-vindo ao algoritmo de descriptografia de imagens" << endl;
	cout << "Por favor, insira o diretório para a imagem com a respectiva extensão:" << endl;
}

Menu::~Menu(){}

void Menu::setLocalArquivo(string localArquivo){
	this->localArquivo = localArquivo;
}

string Menu::getLocalArquivo(){
	return localArquivo;
}

void Menu::setExtensaoArquivo(string extensaoArquivo){
	this->extensaoArquivo = extensaoArquivo;
}

string Menu::getExtensaoArquivo(){
	return extensaoArquivo;
}

void Menu::recebeLocalArquivo(){
	string localArquivo= "";
	cin >> localArquivo;

	Menu::setLocalArquivo(localArquivo);
	Menu::atribuiExtensaoArquivo(localArquivo);
}

void Menu::atribuiExtensaoArquivo(string localArquivo){
	string extensaoArquivo = "";
	extensaoArquivo = localArquivo.substr(localArquivo.length()-3, 3);

	Menu::setExtensaoArquivo(extensaoArquivo);
}
