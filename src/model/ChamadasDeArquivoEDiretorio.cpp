#include "ChamadasDeArquivoEDiretorio.h"

ChamadasDeArquivoEDiretorio::ChamadasDeArquivoEDiretorio() {

}

bool ChamadasDeArquivoEDiretorio::criarDiretorio(string caminho) {
	char* path = strdup(caminho.c_str());
	// Cria diretório com permissões padrão.
	int resultado = mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if(resultado == 0) {
		return true;
	} else {
		return false;
	}
}

bool ChamadasDeArquivoEDiretorio::removerDiretorio(string caminho) {
	char* path = strdup(caminho.c_str());
	int resultado = rmdir(path);
	if(resultado == 0) {
		return true;
	} else {
		return false;
	}
}

bool ChamadasDeArquivoEDiretorio::trocarDeDiretorio(string caminho) {
	char* path = strdup(caminho.c_str());
	int resultado = chdir(path);
	if(resultado == 0) {
		return true;
	} else {
		return false;
	}
}

bool ChamadasDeArquivoEDiretorio::verificarPermissoes(string permissoes,
		string caminho) {
	int resultado;
	int mode;
	if (permissoes.size() <= 3) {
		if (permissoes.find("r") != string::npos) {
			mode += R_OK;
		}
		if (permissoes.find("w") != string::npos) {
			mode += W_OK;
		}
		if (permissoes.find("x") != string::npos) {
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

// Alvo = owner, group ou general.
bool ChamadasDeArquivoEDiretorio::alterarPermissoes(string alvo,
		string permissoes, string caminho) {
	mode_t mode = 0;
	if (alvo == "owner") {
		if (permissoes.find("r") != string::npos) {
			mode = mode | S_IRUSR;
		}
		if (permissoes.find("w") != string::npos) {
			mode = mode | S_IWUSR;
		}
		if (permissoes.find("x") != string::npos) {
			mode = mode | S_IXUSR;
		}
	} else if (alvo == "group") {
		if (permissoes.find("r") != string::npos) {
			mode = mode | S_IRGRP;
		}
		if (permissoes.find("w") != string::npos) {
			mode = mode | S_IWGRP;
		}
		if (permissoes.find("x") != string::npos) {
			mode = mode | S_IXGRP;
		}
	} else if (alvo == "general") {
		if (permissoes.find("r") != string::npos) {
			mode = mode | S_IROTH;
		}
		if (permissoes.find("w") != string::npos) {
			mode = mode | S_IWOTH;
		}
		if (permissoes.find("x") != string::npos) {
			mode = mode | S_IXOTH;
		}
	}
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

