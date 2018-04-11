#ifndef PGM_HPP
#define PGM_HPP

#include "arquivo.hpp"
#include "imagens.hpp"
#include <string>

using namespace std;

class PGM : public Imagens {

private:
	char ***matrizPGM;
	int inicioMensagem;
	int tamMensagem;
	int cifraCesar;
	
	//string mensagem;
	//string mensagemDecodificada;

public:
	PGM(string localArquivo);
	~PGM();
	void setInicioMensagem(int inicioMensagem);
	int getInicioMensagem();
	void setTamMensagem(int tamMensagem);
	int getTamMensagem();
	void setCifraCesar(int cifraCesar);
	int getCifraCesar();
	
	//void setMensagem(string mensagem);
	//string getMensagem();
	//void setMensagemDecodificada(string mensagemDecodificada);
	//string getMensagemDecodificada();

	void atribuiLocalMensagem(string localArquivo);
	void atribuiValoresMatrizPGM(string localArquivo);

};

#endif
