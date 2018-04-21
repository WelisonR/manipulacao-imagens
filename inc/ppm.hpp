#ifndef PPM_HPP
#define PPM_HPP

#include "imagens.hpp"
#include <string>

class PPM : public Imagens {

private:
	unsigned char ***matrizPPM;
	int inicioMensagem;
	int tamMensagem;
	string palavraChave;
	char *alfabetoCifrado;
	
	string mensagem;
	string mensagemDecodificada;

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
