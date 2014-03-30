#ifndef TERMINAL_H
#define TERMINAL_H
#include <iostream>

using namespace std;

// Interface básica para interação com usuário.
class Terminal {

public:
	virtual ~Terminal() {
	}
	virtual bool mensagemDeConfirmacao(string msg) = 0;
	virtual void mensagemDeSucesso(string msg) = 0;
	virtual void mensagemDeAlerta(string msg) = 0;
	virtual void mensagemDeErro(string msg) = 0;
	virtual void limpar() = 0;
};

#endif TERMINAL_H
