#ifndef MENU_HPP
#define MENU_HPP

#include <string>

using namespace std;

class Menu {

private:
	string localArquivo;
	string extensaoArquivo;

public:
	Menu();
	~Menu();
	void setLocalArquivo (string localArquivo);
	string getLocalArquivo();
	void setExtensaoArquivo(string extensaoArquivo);
	string getExtensaoArquivo();
	void recebeLocalArquivo();
	void atribuiExtensaoArquivo(string localArquivo);

};

#endif
