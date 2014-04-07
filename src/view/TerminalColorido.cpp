#include "TerminalColorido.h"

TerminalColorido::TerminalColorido() {
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

void TerminalColorido::parteInicialDoTerminal() {
	long size;
	char *buf;
	char *local;

	local = getcwd(buf, (size_t) size);
	string l = local;

	cout << "\033[1;" << COR_AZUL << "m" << loginComNomeDaMaquina << " "
			<< "\033[0m";
	cout << "\033[1;" << COR_VERDE << "m" << l << " $ " << "\033[0m";
}

void TerminalColorido::mensagemNormal(string msg) {
	cout << msg << endl;
}

// TODO: Tratar erros de digitação
bool TerminalColorido::mensagemDeConfirmacao(string msg) {
	cout << "\033[1;" << COR_AMARELA << "m" << msg << " (s ou n)." << "\033[0m"
			<< endl;
	string resposta;
	cin >> resposta;
	if (resposta == "s") {
		return false;
	}
	return true;
}

void TerminalColorido::mensagemDeAlerta(string msg) {
	cout << "\033[1;" << COR_AMARELA << "m" << msg << "\033[0m" << endl;
}

void TerminalColorido::mensagemDeErro(string msg) {
	cout << "\033[1;" << COR_VERMELHA << "m" << msg << "\033[0m" << endl;
}

void TerminalColorido::mensagemDeSucesso(string msg) {
	cout << "\033[1;" << COR_VERDE << "m" << msg << "\033[0m" << endl;
}

void TerminalColorido::limpar() {
	system("clear");
}

