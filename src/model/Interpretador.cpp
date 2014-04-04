#include "../view/TerminalColorido.cpp"

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
	TerminalColorido *t = new TerminalColorido();
	t->limpar();

	// Imprime "Interpretador" na cor verde
	// Arte feita por http://patorjk.com/software/taag/#p=display&f=Ogre&t=Interpretador
	t->mensagemDeSucesso("  _____       _                           _            _      			");
	t->mensagemDeSucesso("  \\_   \\_ __ | |_ ___ _ __ _ __  _ __ ___| |_ __ _  __| | ___  _ __ 	");
	t->mensagemDeSucesso("   / /\\/ '_ \\| __/ _ \\ '__| '_ \\| '__/ _ \\ __/ _` |/ _` |/ _ \\| '__|	");
	t->mensagemDeSucesso("/\\/ /_ | | | | ||  __/ |  | |_) | | |  __/ || (_| | (_| | (_) | |   	" );
	t->mensagemDeSucesso("\\____/ |_| |_|\\__\\___|_|  | .__/|_|  \\___|\\__\\__,_|\\__,_|\\___/|_|   	");
	t->mensagemDeSucesso("                          |_|                                       	");



	while(true) {
		string comando;
		t->parteInicialDoTerminal();
		cin >> comando;
	}
}
