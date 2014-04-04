#include "TerminalColorido.h".

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/utsname.h>

TerminalColorido::TerminalColorido() {
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

void TerminalColorido::parteInicialDoTerminal() {
	cout << "\033[1;" << COR_AZUL << "m" << inicioDaMensagem << " $ "
			<< "\033[0m";
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

