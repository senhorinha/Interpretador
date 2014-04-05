/*
 * TerminalColorido.h
 *
 *  Created on: 05/04/2014
 *      Author: thiago
 */

#ifndef TERMINALCOLORIDO_H_
#define TERMINALCOLORIDO_H_

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/utsname.h>
#include <iostream>

using namespace std;

class TerminalColorido {

	string inicioDaMensagem;

public:
	const string COR_VERMELHA = "31";
	const string COR_VERDE = "32";
	const string COR_AMARELA = "33";
	const string COR_AZUL = "34";

	void parteInicialDoTerminal();
	void mensagemNormal(string msg);
	void mensagemDeAlerta(string msg);
	bool mensagemDeConfirmacao(string msg);
	void mensagemDeSucesso(string msg);
	void mensagemDeErro(string msg);
	void limpar();
	TerminalColorido();
};



#endif /* TERMINALCOLORIDO_H_ */
