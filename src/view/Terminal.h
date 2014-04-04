#include <iostream>

using namespace std;

// Interface básica para interação com usuário.
class Terminal {

public:
	virtual ~Terminal() {
	}

	// imprime nomeDoUsuario@nomeDaMaquina (ex: fulano@timemachine)
	virtual void parteInicialDoTerminal() = 0;
	virtual bool mensagemDeConfirmacao(string msg) = 0;
	virtual void mensagemDeSucesso(string msg) = 0;
	virtual void mensagemDeAlerta(string msg) = 0;
	virtual void mensagemDeErro(string msg) = 0;
	virtual void limpar() = 0;
};

