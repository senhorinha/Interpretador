/*
 * TerminalColorido.h
 *
 *  Created on: 29/03/2014
 *      Author: thiago
 */

#ifndef TERMINALCOLORIDO_H_
#define TERMINALCOLORIDO_H_

#include "Terminal.h"
#include <iostream>

using namespace std;

class TerminalColorido: Terminal {

public:
	const string COR_VERMELHA = "31";
	const string COR_VERDE = "32";
	const string COR_AMARELA = "33";

	virtual void mensagemDeAlerta(string msg);
	virtual bool mensagemDeConfirmacao(string msg);
	virtual void mensagemDeSucesso(string msg);
	virtual void mensagemDeAlerta(string msg);
	virtual void mensagemDeErro(string msg);
	virtual void limpar();
	TerminalColorido();
	virtual ~TerminalColorido();
};

#endif /* TERMINALCOLORIDO_H_ */
