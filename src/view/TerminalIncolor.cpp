/*
 * TerminalIncolor.cpp
 *
 *  Created on: 29/03/2014
 *      Author: thiago
 */

#include "TerminalIncolor.h"

TerminalIncolor::TerminalIncolor() {

}

// TODO: Tratar erros de digitação
virtual bool TerminalIncolor::mensagemDeConfirmacao(string msg) {
	cout << msg << " (s ou n)." << endl;
	char resposta;
	cin << resposta;
	if (resposta == "n") {
		return false;
	}
	return true;
}

virtual void TerminalIncolor::mensagemDeAlerta(string msg) {
	cout << msg << endl;
}

virtual void TerminalIncolor::mensagemDeErro(string msg) {
	cout << msg << endl;
}

virtual void TerminalIncolor::mensagemDeSucesso(string msg) {
	cout << msg << endl;
}

TerminalIncolor::~TerminalIncolor() {
}
