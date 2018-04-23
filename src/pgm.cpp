#include "pgm.hpp"
#include "imagens.hpp"

using namespace std;

PGM::PGM(){}

PGM::PGM(string localArquivo){
	Imagens::leitorArquivo(localArquivo);

	matrizPGM = new char **[Imagens::getNLinhas()];
	for (int i = 0; i < Imagens::getNLinhas(); i++){
		matrizPGM[i] = new char *[Imagens::getNColunas()];
		for (int j = 0; j < Imagens::getNColunas(); j++){
			matrizPGM[i][j] = new char[1];
		}
	}
	inicioMensagem = 0;
	tamMensagem = 0;
	cifraCesar = 0;
	string mensagem = "";
	string mensagemDecodificada = "";

	PGM::atribuiLocalMensagem(localArquivo);
	PGM::atribuiValoresMatrizPGM(localArquivo);
	PGM::atribuiMensagem();
	PGM::atribuiMensagemDecodificada();
}

PGM::~PGM(){
	for (int i = 0; i < Imagens::getNLinhas(); i++){
		for (int j = 0; j < Imagens::getNColunas(); j++){
			delete [] matrizPGM[i][j];
		}
		delete [] matrizPGM[i];
	}
	delete [] matrizPGM;
}

void PGM::setInicioMensagem(int inicioMensagem){
	this->inicioMensagem = inicioMensagem;
}

int PGM::getInicioMensagem(){
	return inicioMensagem;
}

void PGM::setTamMensagem(int tamMensagem){
	this->tamMensagem = tamMensagem;
}

int PGM::getTamMensagem(){
	return tamMensagem;
}

void PGM::setCifraCesar(int cifraCesar){
	this->cifraCesar = cifraCesar;
}

int PGM::getCifraCesar(){
	return cifraCesar;
}

void PGM::setMensagem(string mensagem){
	this->mensagem = mensagem;
}

string PGM::getMensagem(){
	return mensagem;
}

void PGM::setMensagemDecodificada(string mensagemDecodificada){
	this->mensagemDecodificada = mensagemDecodificada;
}

string PGM::getMensagemDecodificada(){
	return mensagemDecodificada;
}

void PGM::atribuiLocalMensagem(string localArquivo){
	int inicioMensagem = 0, tamMensagem = 0, cifraCesar = 0;
	string aux = "";

	ifstream imagem(localArquivo.c_str());

	getline(imagem, aux); // despreza a primeira linha do arquivo
	getline(imagem, aux);

	aux.erase(0, 1); // apaga a sinalização de comentário (#)
	istringstream iss(aux);
	iss >> inicioMensagem >> tamMensagem >> cifraCesar;	

	imagem.close();

	PGM::setInicioMensagem(inicioMensagem);
	PGM::setTamMensagem(tamMensagem);
	PGM::setCifraCesar(cifraCesar);
}

void PGM::atribuiValoresMatrizPGM(string localArquivo){
	string aux = "";

	ifstream imagem(localArquivo.c_str());

	// ignora o cabeçalho da imagem
	for (int i = 0; i < 4; i++)
		getline(imagem, aux);	

	for (int i = 0; i < Imagens::getNLinhas(); i++){
		for (int j = 0; j < Imagens::getNColunas(); j++){
			char letra;
			imagem.get(letra);
			
			matrizPGM[i][j][0] = letra;		
		}
	}

	imagem.close();
}

void PGM::atribuiMensagem(){
	int contador = 0;
	string mensagem = "";

	for (int i = 0; i < Imagens::getNLinhas(); i++){
		for (int j = 0; j < Imagens::getNColunas(); j++){
			if (contador>= PGM::getInicioMensagem() && contador< (PGM::getInicioMensagem()+PGM::getTamMensagem()))
				mensagem+= matrizPGM[i][j][0];
			contador++;
		}
	}

	PGM::setMensagem(mensagem);
}

void PGM::atribuiMensagemDecodificada(){
	string mensagemDecodificada = "";

	for (int i= 0; i < (int) mensagem.length(); i++){
		char letraResultante = mensagem[i], letraPadrao = 'a';
		
		if (isupper(mensagem[i]))
			letraPadrao = 'A';

		if (isalpha(mensagem[i]))
			letraResultante = ((mensagem[i] - (char) PGM::getCifraCesar() - letraPadrao + 26) % 26) + letraPadrao;

		mensagemDecodificada+= letraResultante;
	}

	PGM::setMensagemDecodificada(mensagemDecodificada);
}