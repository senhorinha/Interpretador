/*
 * Analisador.h
 *
 *  Created on: 05/04/2014
 *      Author: thiago
 */

#ifndef ANALISADOR_H_
#define ANALISADOR_H_

#include <iostream>
#include <vector>
using namespace std;

class Analisador {

private:
	vector<string> comandosDisponiveis = { "help", "reset", "uname", "rename", "access",
			"chmod", "execl" };
public:
	Analisador();
	bool validarComando(string comandoSemParametro);
	vector<string> getComandosDisponiveis();
	vector<string> separarParametros(string);
};


#endif /* ANALISADOR_H_ */
