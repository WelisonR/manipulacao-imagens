#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <string>

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
