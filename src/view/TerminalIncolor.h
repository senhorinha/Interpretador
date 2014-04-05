/*
 * TerminalIncolor.h
 *
 *  Created on: 05/04/2014
 *      Author: thiago
 */

#ifndef TERMINALINCOLOR_H_
#define TERMINALINCOLOR_H_


#include <iostream>

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/utsname.h>

using namespace std;

class TerminalIncolor {

	string inicioDaMensagem;

public:
	TerminalIncolor();
	void parteInicialDoTerminal();
	void mensagemNormal(string msg);
	void mensagemDeAlerta(string msg);
	bool mensagemDeConfirmacao(string msg);
	void mensagemDeSucesso(string msg);
	void mensagemDeErro(string msg);
	void limpar();
};



#endif /* TERMINALINCOLOR_H_ */
