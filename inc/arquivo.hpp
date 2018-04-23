#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Arquivo {

private:
	string localArquivo;
	string extensaoArquivo;

public:
	Arquivo();
	~Arquivo();
	void setLocalArquivo (string localArquivo);
	string getLocalArquivo();
	void setExtensaoArquivo(string extensaoArquivo);
	string getExtensaoArquivo();
	void recebeLocalArquivo();
	void atribuiExtensaoArquivo();
	void verificaExcecao();

};

#endif