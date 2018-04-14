#include <iostream>
#include "arquivo.hpp"
#include "imagens.hpp"
#include "pgm.hpp"

using namespace std;

int main(int arc, char **argv){
	cout << "Bem-vindo ao algoritmo de descriptografia de imagens" << endl;
	cout << "Por favor, insira o diretório para a imagem com a respectiva extensão: " << endl;
	Arquivo arq1;			
	arq1.recebeLocalArquivo();

	string localArquivo = arq1.getLocalArquivo();
	string extensaoArquivo = arq1.getExtensaoArquivo();

	if (extensaoArquivo == "pgm"){
		PGM img1(localArquivo);
		cout << "A mensagem decodificada é: " << "\"" << img1.getMensagemDecodificada() << "\"" << endl;
	}

	return 0;
}
