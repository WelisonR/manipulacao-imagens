#include "arquivo.hpp"

using namespace std;

Arquivo::Arquivo(){
	localArquivo = "";
	extensaoArquivo = "";

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

// recebe a localização da imagem com a sua extensão (ppm ou pgm)
void Arquivo::recebeLocalArquivo(){
	string localArquivo= "";
	getline(cin, localArquivo);

	Arquivo::setLocalArquivo(localArquivo);
}

// armazena a extensão da imagem, isto é, "ppm" ou "pgm"
void Arquivo::atribuiExtensaoArquivo(){
	string extensaoArquivo = "";
	extensaoArquivo = localArquivo.substr(Arquivo::getLocalArquivo().length()-3, 3);

	Arquivo::setExtensaoArquivo(extensaoArquivo);
}

// trata exceções que podem ser geradas em tempo de execução
void Arquivo::verificaExcecao(){
	if (Arquivo::getExtensaoArquivo() != "ppm" && Arquivo::getExtensaoArquivo() != "pgm")
		throw(0);

	ifstream imagem(Arquivo::getLocalArquivo().c_str());
	if (!imagem.is_open())
		throw(1);
	else
		imagem.close();
}
