#include "TerminalIncolor.h"

TerminalIncolor::TerminalIncolor() {
	string identificador;
	struct utsname u_name;
	uname(&u_name);
	// Concatena login
	inicioDaMensagem += getlogin();
	// Concatena @
	inicioDaMensagem += "@";
	// Concatena nome da máquina
	inicioDaMensagem += u_name.nodename;
}

void TerminalIncolor::parteInicialDoTerminal() {
	cout << inicioDaMensagem << " $";
}

// TODO: Tratar erros de digitação
bool TerminalIncolor::mensagemDeConfirmacao(string msg) {
	cout << msg << " (s ou n)." << endl;
	string resposta;
	cin >> resposta;
	if (resposta == "n") {
		return false;
	}
	return true;
}

void TerminalIncolor::mensagemDeAlerta(string msg) {
	cout << msg << endl;
}

void TerminalIncolor::mensagemDeErro(string msg) {
	cout << msg << endl;
}

void TerminalIncolor::mensagemDeSucesso(string msg) {
	cout << msg << endl;
}

TerminalIncolor::~TerminalIncolor() {
}
