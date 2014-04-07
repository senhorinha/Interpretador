/*
 * TerminalIncolor.h
 *
 *  Created on: 05/04/2014
 *      Author: thiago
 */

#ifndef TERMINALINCOLOR_H_
#define TERMINALINCOLOR_H_

#include "Terminal.h"

#include <iostream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/utsname.h>

using namespace std;

class TerminalIncolor : public Terminal{

	string loginComNomeDaMaquina;

public:
	TerminalIncolor();
	virtual void parteInicialDoTerminal();
	virtual void mensagemNormal(string msg);
	virtual void mensagemDeAlerta(string msg);
	virtual bool mensagemDeConfirmacao(string msg);
	virtual void mensagemDeSucesso(string msg);
	virtual void mensagemDeErro(string msg);
	virtual void limpar();
};



#endif /* TERMINALINCOLOR_H_ */
