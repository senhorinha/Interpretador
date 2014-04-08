#ifndef ANALISADOR_H_
#define ANALISADOR_H_

#include <iostream>
#include <vector>
using namespace std;

class Analisador {

private:
	vector<string> comandosDisponiveis = { "help", "cd", "reset", "uname", "rename", "access",
			"chmod", "mkdir", "rmdir", "execl" };
public:
	Analisador();
	bool validarComando(string comandoSemParametro);
	vector<string> getComandosDisponiveis();
	vector<string> separarParametros(string);
};


#endif /* ANALISADOR_H_ */
