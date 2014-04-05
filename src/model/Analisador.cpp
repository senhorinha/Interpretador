#include "Analisador.h"

Analisador::Analisador() {

}

vector<string> Analisador::separarParametros(string comando) {
	vector<string> tokens;
	std::string delimiter = " ";
	size_t pos = 0;
	std::string token;
	while ((pos = comando.find(delimiter)) != std::string::npos) {
		token = comando.substr(0, pos);
		tokens.push_back(token);
		comando.erase(0, pos + delimiter.length());
	}
	tokens.push_back(comando);
	return tokens;
}

bool Analisador::validarComando(string comandoSemParametro) {
	for (auto & c : getComandosDisponiveis()) {
		if (c == comandoSemParametro) {
			return true;
		}
	}
	return false;
}

vector<string> Analisador::getComandosDisponiveis() {
	return comandosDisponiveis;
}
