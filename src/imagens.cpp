#include "imagens.hpp"

using namespace std;

Imagens::Imagens(){
	tipoImagem = "";
	nColunas = 0;
	nLinhas = 0;
	maxPixel = 0;
}

Imagens::~Imagens(){}

void Imagens::setTipoImagem(string tipoImagem){
	this->tipoImagem = tipoImagem;
}

string Imagens::getTipoImagem(){
	return tipoImagem;
}

void Imagens::setNColunas(int nColunas){
	this->nColunas = nColunas;
}

int Imagens::getNColunas(){
	return nColunas;
}

void Imagens::setNLinhas(int nLinhas){
	this->nLinhas = nLinhas;
}

int Imagens::getNLinhas(){
	return nLinhas;
}

void Imagens::setMaxPixel(int maxPixel){
	this->maxPixel = maxPixel;
}
	
int Imagens::getMaxPixel(){
	return maxPixel;
}

void Imagens::leitorArquivo(string localArquivo){
	string tipoImagem = "", aux = "";
	int nColunas = 0, nLinhas = 0, maxPixel = 0;	

	ifstream imagem(localArquivo.c_str());

	getline(imagem, tipoImagem);
	getline(imagem, aux); // ignora a segunda linha do arquivo (especificações sobre a criptografia)
	// Motivo: as informações apresentadas pode mudar devido a novas formas de criptografia
	// Devido a isso, decidiu-se especializar as informações sobre a criptografia presente na imagem
	imagem >> nColunas >> nLinhas >> maxPixel;
	
	imagem.close();

	Imagens::setTipoImagem(tipoImagem);
	Imagens::setNColunas(nColunas);
	Imagens::setNLinhas(nLinhas);
	Imagens::setMaxPixel(maxPixel);
}