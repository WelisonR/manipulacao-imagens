#ifndef PPM_HPP
#define PPM_HPP

#include "imagens.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class PPM : public Imagens {

private:
	unsigned char ***matrizPPM;
	char *alfabetoCifrado;
	int inicioMensagem;
	int tamMensagem;
	string palavraChave;
	string mensagem;
	string mensagemDecodificada;
	PPM();

public:
	PPM(string localArquivo);
	~PPM();
	void setInicioMensagem(int inicioMensagem);
	int getInicioMensagem();
	void setTamMensagem(int tamMensagem);
	int getTamMensagem();
	void setPalavraChave(string palavraChave);
	string getPalavraChave();
	void setMensagem(string mensagem);
	string getMensagem();
	void setMensagemDecodificada(string mensagemDecodificada);
	string getMensagemDecodificada();
	void atribuiLocalMensagem(string localArquivo);
	void atribuiValoresMatrizPPM(string localArquivo);
	void atribuiMensagem();
	void preencheAlfabetoCifrado();
	void atribuiMensagemDecodificada();

};

#endif
