/*
 * TerminalColorido.cpp
 *
 *  Created on: 29/03/2014
 *      Author: thiago
 */

#include "TerminalColorido.h"

TerminalColorido::TerminalColorido() {
}

// TODO: Tratar erros de digitação
virtual bool TerminalColorido::mensagemDeConfirmacao(string msg) {
	cout << "\033[1;" << COR_AMARELA << "m" << msg << " (s ou n)."
			<< "\033[0m\n" << endl;
	char resposta;
	cin << resposta;
	if (resposta == "n") {
		return false;
	}
	return true;
}

virtual void TerminalColorido::mensagemDeAlerta(string msg) {
	cout << "\033[1;" << COR_AMARELA << "m" << msg << "\033[0m\n" << endl;
}

virtual void TerminalColorido::mensagemDeErro(string msg) {
	cout << "\033[1;" << COR_VERMELHA << "m" << msg << "\033[0m\n" << endl;
}

virtual void TerminalColorido::mensagemDeSucesso(string msg) {
	cout << "\033[1;" << COR_VERDE << "m" << msg << "\033[0m\n" << endl;
}

