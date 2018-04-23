#include "arquivo.hpp"
#include "imagens.hpp"
#include "pgm.hpp"
#include "ppm.hpp"

#include <iostream>

using namespace std;

int main(int arc, char **argv){
	cout << "Bem-vindo ao algoritmo de decodificação de mensagens de imagens '.pgm' e '.ppm'." << endl;
	cout << "Abaixo, insira o diretório para a imagem com a sua respectiva extensão." << endl;
	cout << "Diretório: ";

	Arquivo *arq1;

	bool satisfeito = false;
	while (!satisfeito){
		try{
			arq1 = new Arquivo();
			satisfeito = true;
		}
		catch (int excecao){
			if (excecao == 0)
				cout << "Tipo de arquivo não aceito." << endl << "Informe um arquivo '.pgm' ou '.ppm': ";
			else if (excecao == 1)
				cout << "O arquivo não pôde ser aberto." << endl << "Digite um diretório válido: ";
		}
	}
	
	if (arq1->getExtensaoArquivo() == "pgm"){
		PGM *img1 = new PGM(arq1->getLocalArquivo());
		cout << endl <<"A mensagem decodificada é: " << "\"" << img1->getMensagemDecodificada() << "\"" << "." << endl;
		delete img1;
	}
	else if (arq1->getExtensaoArquivo() == "ppm"){
		PPM *img1 = new PPM(arq1->getLocalArquivo());
		cout << endl <<"A mensagem decodificada é: " << "\"" << img1->getMensagemDecodificada() << "\"" << "." << endl;
		delete img1;
	}
	
	delete arq1;

	return 0;
}
