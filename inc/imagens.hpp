#ifndef IMAGENS_HPP
#define IMAGENS_HPP

#include <string>

using namespace std;

class Imagens {

private:
	string tipoImagem;
	int nColunas;
	int nLinhas;
	int maxPixel;
public:
	Imagens();
	~Imagens();
	void setTipoImagem(string tipoImagem);
	string getTipoImagem();
	void setNColunas(int nColunas);
	int getNColunas();
	void setNLinhas(int nLinhas);
	int getNLinhas();
	void setMaxPixel(int maxPixel);	
	int getMaxPixel();
	void leitorArquivo(string localArquivo);	
	
};

#endif
