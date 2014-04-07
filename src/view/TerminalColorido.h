#ifndef TERMINALCOLORIDO_H_
#define TERMINALCOLORIDO_H_

#include "Terminal.h"

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/utsname.h>

using namespace std;

class TerminalColorido : public Terminal{

	string loginComNomeDaMaquina;

public:
	const string COR_VERMELHA = "31";
	const string COR_VERDE = "32";
	const string COR_AMARELA = "33";
	const string COR_AZUL = "34";
	
	TerminalColorido();
	virtual void parteInicialDoTerminal();
	virtual void mensagemNormal(string msg);
	virtual void mensagemDeAlerta(string msg);
	virtual bool mensagemDeConfirmacao(string msg);
	virtual void mensagemDeSucesso(string msg);
	virtual void mensagemDeErro(string msg);
	virtual void limpar();
	
};



#endif /* TERMINALCOLORIDO_H_ */
