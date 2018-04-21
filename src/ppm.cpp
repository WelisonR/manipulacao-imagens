#include <iostream>
#include <sstream>
#include <fstream>
#include "ppm.hpp"

using namespace std;

PPM::PPM(string localArquivo){

	Imagens::leitorArquivo(localArquivo);
	PPM::atribuiLocalMensagem(localArquivo);

	matrizPPM = new unsigned char**[Imagens::getNLinhas()];
	for (int i = 0; i < Imagens::getNLinhas(); i++){
		matrizPPM[i] = new unsigned char*[Imagens::getNColunas()];
		for (int j = 0; j < Imagens::getNColunas(); j++){
			matrizPPM[i][j] = new unsigned char[3];
		}
	}

	PPM::atribuiValoresMatrizPPM(localArquivo);
	PPM::atribuiMensagem();

	alfabetoCifrado = new char[27];
	PPM::preencheAlfabetoCifrado();
	PPM::atribuiMensagemDecodificada(); 

}

PPM::~PPM(){

	for (int i = 0; i < Imagens::getNLinhas(); i++){
		for (int j = 0; j < Imagens::getNColunas(); j++){
			delete [] matrizPPM[i][j];
		}
		delete [] matrizPPM[i];
	}
	delete [] matrizPPM;

	delete [] alfabetoCifrado;
	
}

void PPM::setInicioMensagem(int inicioMensagem){
	this->inicioMensagem = inicioMensagem;
}

int PPM::getInicioMensagem(){
	return inicioMensagem;
}

void PPM::setTamMensagem(int tamMensagem){
	this->tamMensagem = tamMensagem;
}

int PPM::getTamMensagem(){
	return tamMensagem;
}

void PPM::setPalavraChave(string palavraChave){
	this->palavraChave = palavraChave;
}

string PPM::getPalavraChave(){
	return palavraChave;
}

void PPM::setMensagem(string mensagem){
	this->mensagem = mensagem;
}

string PPM::getMensagem(){
	return mensagem;
}

void PPM::setMensagemDecodificada(string mensagemDecodificada){
	this->mensagemDecodificada = mensagemDecodificada;
}

string PPM::getMensagemDecodificada(){
	return mensagemDecodificada;
}

void PPM::atribuiLocalMensagem(string localArquivo){
	int inicioMensagem = 0, tamMensagem = 0;
	string palavraChave = "";

	ifstream imagem(localArquivo.c_str());

	string aux = "";
	getline(imagem, aux); // despreza a primeira linha
	getline(imagem, aux);
	aux.erase(0, 1);

	istringstream iss(aux);
	iss >> inicioMensagem >> tamMensagem >> palavraChave;	

	imagem.close();

	PPM::setInicioMensagem(inicioMensagem);
	PPM::setTamMensagem(tamMensagem);
	PPM::setPalavraChave(palavraChave);

}

void PPM::atribuiValoresMatrizPPM(string localArquivo){

	ifstream imagem(localArquivo.c_str());

	// ignora 4 linhas do arquivo (imagem.seekg(27))
	string aux;
	for (int i = 0; i < 4; i++){
		getline(imagem, aux);	
	}

	for (int i = 0; i < Imagens::getNLinhas(); i++){
		for (int j = 0; j < Imagens::getNColunas(); j++){
			char letra;

			imagem.get(letra);
			matrizPPM[i][j][0] = (char) letra;
			imagem.get(letra);
			matrizPPM[i][j][1] = (char) letra;
			imagem.get(letra);
			matrizPPM[i][j][2] = (char) letra;		
		}
	}

	imagem.close();

}

void PPM::atribuiMensagem(){
	int contador = 0;
	string mensagem = "";

	int aux = 0, somaUnidades = 0;
	for (int i = 0; i < Imagens::getNLinhas(); i++){
		for (int j = 0; j < Imagens::getNColunas(); j++){
			for (int k = 0; k < 3; k++){
				if (contador >= getInicioMensagem() && contador < (getInicioMensagem()+3*getTamMensagem())){
					somaUnidades +=  ((int) matrizPPM[i][j][k]%10);
					aux++;
				}
				if (contador >= getInicioMensagem() && contador < (getInicioMensagem()+3*getTamMensagem()) && aux == 3){
					mensagem += (char) somaUnidades;
					somaUnidades = 0;
					aux = 0;
				}

				contador++;
			}
			
		}
	}

	PPM::setMensagem(mensagem);

}

void PPM::preencheAlfabetoCifrado(){
	
	string palavraChave = getPalavraChave();
	int tam = (int) palavraChave.length();
	palavraChave = getPalavraChave().c_str();

	alfabetoCifrado[0] = ' ';
	for (int i = 1; i < tam+1; i++){
		alfabetoCifrado[i] = palavraChave[i-1];
	}

	int aux = 0;
	for (int i = tam+1; i < 27; i++){
		for (int k = 0; k < 26; k ++){
			int flag = 0;
			for (int j = 1; j < tam+1+aux; j++){
				if (alfabetoCifrado[j] == 'a'+k){
					flag = 1;
					break;
				}
			}
			if (flag == 0){
				alfabetoCifrado[i] = (char) 'a'+k;
				break;
			}
		}
		aux++;
	}

}



void PPM::atribuiMensagemDecodificada(){
	string mensagemDecodificada = "";

	for (int i = 0; i < (int) mensagem.length(); i++){
		for (int j = 1; j < 27; j++){
			if ((int) mensagem[i] == 0){
				mensagemDecodificada+= " ";
				break;
			}
			if ((char) (mensagem[i] + 'a' - 1) == alfabetoCifrado[j]){
				mensagemDecodificada += char (j + (int) 'a' - 1) - 32;
			}
		}
	}

	PPM::setMensagemDecodificada(mensagemDecodificada);
}