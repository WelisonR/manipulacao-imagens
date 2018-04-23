#include "ppm.hpp"
#include "imagens.hpp"

using namespace std;

PPM::PPM(){}

PPM::PPM(string localArquivo){
	Imagens::leitorArquivo(localArquivo);

	matrizPPM = new unsigned char **[Imagens::getNLinhas()];
	for (int i = 0; i < Imagens::getNLinhas(); i++){
		matrizPPM[i] = new unsigned char *[Imagens::getNColunas()];
		for (int j = 0; j < Imagens::getNColunas(); j++){
			matrizPPM[i][j] = new unsigned char[3];
		}
	}
	alfabetoCifrado = new char[27];
	inicioMensagem = 0;
	tamMensagem = 0;
	palavraChave = "";
	mensagem = "";
	mensagemDecodificada = "";

	PPM::atribuiLocalMensagem(localArquivo);
	PPM::atribuiValoresMatrizPPM(localArquivo);
	PPM::atribuiMensagem();
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

// define as variáveis que indicam o inicio da mensagem, sua extensão e a palavra-chave
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

// recebe e atribui a imagem na matriz 3d de pixels
void PPM::atribuiValoresMatrizPPM(string localArquivo){
	string aux = "";

	ifstream imagem(localArquivo.c_str());

	// ignora o cabeçalho da imagem
	for (int i = 0; i < 4; i++)
		getline(imagem, aux);

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

// guarda em uma string (criptografada) a conversão das somas das unidades (tríade) em um char
void PPM::atribuiMensagem(){
	int contador = 0, somaUnidades = 0, aux = 0;
	string mensagem = "";

	for (int i = 0; i < Imagens::getNLinhas(); i++){
		for (int j = 0; j < Imagens::getNColunas(); j++){
			for (int k = 0; k < 3; k++){
				if (contador >= getInicioMensagem() && contador < (getInicioMensagem()+3*getTamMensagem())){
					somaUnidades +=  ((int) matrizPPM[i][j][k] % 10); // toma a unidade do respectivo inteiro
					aux++;
				}
				if (contador >= getInicioMensagem() && contador < (getInicioMensagem()+3*getTamMensagem()) && aux == 3){
					mensagem += (char) somaUnidades + 'a' - 1; // atingido a triade, guarda a letra em "mensagem"
					somaUnidades = 0;
					aux = 0;
				}

				contador++;
			}
			
		}
	}

	PPM::setMensagem(mensagem);
}

// define o array de chars do alfabeto com a palavra-chave informada
void PPM::preencheAlfabetoCifrado(){
	int aux = 0;

	alfabetoCifrado[0] = ' ';
	for (int i = 1; i < (int) PPM::getPalavraChave().length() + 1; i++)
		alfabetoCifrado[i] = palavraChave[i-1];

	for (int i = (int) PPM::getPalavraChave().length() + 1; i < 27; i++){
		for (int k = 0; k < 26; k++){
			int flag = 0;
			for (int j = 1; j < (int) PPM::getPalavraChave().length() + 1 + aux; j++){
				if (alfabetoCifrado[j] == 'a' + k){
					flag = 1;
					break;
				}
			}
			if (flag == 0){
				alfabetoCifrado[i] = (char) 'a' + k;
				break;
			}
		}
		
		// amplia a área de vistoria conforme cresce alfabetoCifrado
		aux++;
	}
}

// Desvenda a mensagem através da procura do correspondente da letra cifrada no alfabeto original
void PPM::atribuiMensagemDecodificada(){
	string mensagemDecodificada = "";

	for (int i = 0; i < (int) PPM::getMensagem().length(); i++){
		for (int j = 1; j < 27; j++){
			if (mensagem[i] == 'a'- 1){
				mensagemDecodificada+= " ";
				break;
			}
			if (mensagem[i] == alfabetoCifrado[j])
				mensagemDecodificada += (j + 'a' - 1) - 32;
		}
	}

	PPM::setMensagemDecodificada(mensagemDecodificada);
}
