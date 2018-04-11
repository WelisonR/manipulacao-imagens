#include <iostream>
#include <fstream>
#include <sstream>
#include "pgm.hpp"

using namespace std;

PGM::PGM(string localArquivo){

	Imagens::leitorArquivo(localArquivo);
	PGM::atribuiLocalMensagem(localArquivo);

	int nLinhas = Imagens::getNLinhas();
	int nColunas = Imagens::getNColunas();

	matrizPGM = new char**[nLinhas];
	for (int i = 0; i < nLinhas; i++){
		matrizPGM[i] = new char*[nColunas];
		for (int j = 0; j < nColunas; j++){
			matrizPGM[i][j] = new char[1];
		}
	}

	PGM::atribuiValoresMatrizPGM(localArquivo);

}

PGM::~PGM(){
	int nLinhas = Imagens::getNLinhas();
	int nColunas = Imagens::getNColunas();

	for (int i = 0; i < nLinhas; i++){
		for (int j = 0; j < nColunas; j++){
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

void PGM::atribuiLocalMensagem(string localArquivo){
	int inicioMensagem = 0, tamMensagem = 0, cifraCesar = 0;

	ifstream imagem(localArquivo.c_str());

	string aux = "";
	getline(imagem, aux); // despreza a primeira linha
	getline(imagem, aux);
	aux.erase(0, 1);

	istringstream iss(aux);
	iss >> inicioMensagem >> tamMensagem >> cifraCesar;	

	imagem.close();

	PGM::setInicioMensagem(inicioMensagem);
	PGM::setTamMensagem(tamMensagem);
	PGM::setCifraCesar(cifraCesar);
}

void PGM::atribuiValoresMatrizPGM(string localArquivo){
	int nLinhas = Imagens::getNLinhas();
	int nColunas = Imagens::getNColunas();
	
	ifstream imagem(localArquivo.c_str());

	// ignora 4 linhas do arquivo (imagem.seekg(27))
	string aux;
	for (int i = 0; i < 4; i++){
		getline(imagem, aux);	
	}

	for (int i = 0; i < nLinhas; i++){
		for (int j = 0; j < nColunas; j++){
			char letra;
			imagem.get(letra);
			
			matrizPGM[i][j][0] = letra;		
		}
	}

	imagem.close();

}
