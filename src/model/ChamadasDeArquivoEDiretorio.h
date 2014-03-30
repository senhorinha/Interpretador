/*
 * OperacoesAvancadaDeArquivos.h
 *
 *  Created on: 29/03/2014
 *      Author: thiago
 */

#include "Terminal.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

class ChamadasDeArquivoEDiretorio {
	Terminal * terminal;

public:
	ChamadasDeArquivoEDiretorio(Terminal *t) {
		terminal = t;
	}
	void access(const char *pathname, int mode);
	void chmod(const char *path, mode_t mode);
	virtual ~ChamadasDeArquivoEDiretorio();
};

