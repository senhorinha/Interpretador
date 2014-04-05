#include "TerminalIncolor.h"

TerminalIncolor::TerminalIncolor() {
	string identificador;
	struct utsname u_name;
	uname(&u_name);
	// Concatena login
	loginComNomeDaMaquina += getlogin();
	// Concatena @
	loginComNomeDaMaquina += "@";
	// Concatena nome da máquina
	loginComNomeDaMaquina += u_name.nodename;
}

void TerminalIncolor::parteInicialDoTerminal() {
	long size;
	char *buf;
	char *local;

	local = getcwd(buf, (size_t) size);
	cout << loginComNomeDaMaquina << " ";
	cout << local << " $ ";
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

void TerminalIncolor::limpar() {
	system("clear");
}
