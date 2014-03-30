/*
 * OperacoesAvancadaDeArquivos.cpp
 *
 *  Created on: 29/03/2014
 *      Author: thiago
 */

#include "ChamadasDeArquivoEDiretorio.h"

void ChamadasDeArquivoEDiretorio::access(const char *pathname, int mode) {
	int resultado;
	resultado = access(pathname, mode);
	if (resultado == 0) {
		terminal->mensagemDeSucesso("Sucesso! Você possui permissão!");
	} else {
		terminal->mensagemDeErro("Erro! Você não possui permissão!");
	}
}

void ChamadasDeArquivoEDiretorio::chmod(const char *path, mode_t mode) {
	int status;
	struct stat buffer;
	chmod(path, mode);
	status = stat(path, &buffer);
	if (status == 0) {
		terminal->mensagemDeSucesso("Sucesso! Permissão alterada.");
	} else {
		terminal->mensagemDeErro("Erro! Permissão não alterada!");
	}
}
