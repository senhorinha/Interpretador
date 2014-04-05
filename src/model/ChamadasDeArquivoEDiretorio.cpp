#include "ChamadasDeArquivoEDiretorio.h"

ChamadasDeArquivoEDiretorio::ChamadasDeArquivoEDiretorio() {

}

bool ChamadasDeArquivoEDiretorio::verificarPermissoes(string permissoes,
		string caminho) {
	int resultado;
	int mode;
	if (permissoes.size() <= 3) {
		if (permissoes.find("r")) {
			mode += R_OK;
		}
		if (permissoes.find("w")) {
			mode += W_OK;
		}
		if (permissoes.find("x")) {
			mode += X_OK;
		}
	}
	char* path = strdup(caminho.c_str());
	resultado = access(path, mode);
	if (resultado == 0) {
		return true;
	} else {
		return false;
	}
}

bool ChamadasDeArquivoEDiretorio::alterarPermissoes(string caminho,
		mode_t mode) {
	struct stat buffer;
	char* path = strdup(caminho.c_str());
	chmod(path, mode);
	int status = stat(path, &buffer);
	if (status == 0) {
		return true;
	} else {
		return false;
	}
}

bool ChamadasDeArquivoEDiretorio::renomearArquivo(string caminhoAntigo,
		string caminhoNovo) {
	char* velho = strdup(caminhoAntigo.c_str());
	char* novo = strdup(caminhoNovo.c_str());
	int resultado = rename(velho, novo);
	delete[] velho;
	delete[] novo;
	if (resultado == 0) {
		return true;
	} else {
		return false;
	}
}
;

