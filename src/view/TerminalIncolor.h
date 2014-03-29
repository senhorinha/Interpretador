/*
 * TerminalIncolor.h
 *
 *  Created on: 29/03/2014
 *      Author: thiago
 */

#include <iostream>
using namespace std;

class TerminalIncolor: Terminal {

public:
	TerminalIncolor();
	virtual void mensagemDeAlerta(string msg);
	virtual bool mensagemDeConfirmacao(string msg);
	virtual void mensagemDeSucesso(string msg);
	virtual void mensagemDeAlerta(string msg);
	virtual void mensagemDeErro(string msg);
	virtual void limpar();
	virtual ~TerminalIncolor();
};

