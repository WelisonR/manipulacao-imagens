#include <iostream>
#include "arquivo.hpp"
#include "imagens.hpp"

using namespace std;

int main(int arc, char **argv){
	Imagens img1;
	string localArquivo = img1.getLocalArquivo();

	img1.leitorArquivo(localArquivo);

	cout << "Tipo: " << img1.getTipoImagem() << "Colunas: " << img1.getNColunas() << "Linhas: " << img1.getNLinhas() << "Pixel: " << img1.getMaxPixel() << endl;

	return 0;
}
