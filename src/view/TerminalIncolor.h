#include <iostream>
#include "Terminal.h"

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/utsname.h>

using namespace std;

class TerminalIncolor: public Terminal {

	string inicioDaMensagem;

public:
	TerminalIncolor();
	virtual void parteInicialDoTerminal();
	virtual void mensagemDeAlerta(string msg);
	virtual bool mensagemDeConfirmacao(string msg);
	virtual void mensagemDeSucesso(string msg);
	virtual void mensagemDeErro(string msg);
	virtual void limpar();
};

