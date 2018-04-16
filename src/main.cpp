#include <iostream>
#include "arquivo.hpp"
#include "imagens.hpp"
#include "pgm.hpp"
#include "ppm.hpp"

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
	else if (extensaoArquivo == "ppm"){
		PPM img1(localArquivo);
		cout << "A mensagem codificada é: " << "\"" << img1.getMensagem() << "\"" << endl;	
	}

	return 0;
}
