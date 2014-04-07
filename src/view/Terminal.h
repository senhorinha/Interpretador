/*
 * Terminal.h
 *
 *  Created on: 06/04/2014
 *      Author: thiago
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <iostream>

using namespace std;


class Terminal {

public:
	virtual void parteInicialDoTerminal() = 0;
	virtual void mensagemNormal(string msg) = 0;
	virtual void mensagemDeAlerta(string msg) = 0;
	virtual bool mensagemDeConfirmacao(string msg) = 0;
	virtual void mensagemDeSucesso(string msg) = 0;
	virtual void mensagemDeErro(string msg) = 0;
	virtual void limpar() = 0;
};


#endif /* TERMINAL_H_ */
