#include "../view/TerminalColorido.cpp"

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {

	TerminalColorido *t = new TerminalColorido();
	t->limpar();
	t->parteInicialDoTerminal();
	t->mensagemDeAlerta("ALERTA!!!!");

}
