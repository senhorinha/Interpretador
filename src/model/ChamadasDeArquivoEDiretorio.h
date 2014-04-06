/*
 * ChamadasDeArquivoEDiretorio.h
 *
 *  Created on: 05/04/2014
 *      Author: thiago
 */

#ifndef CHAMADASDEARQUIVOEDIRETORIO_H_
#define CHAMADASDEARQUIVOEDIRETORIO_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

class ChamadasDeArquivoEDiretorio {

public:
	ChamadasDeArquivoEDiretorio();
	bool verificarPermissoes(string permissoes, string caminho);
	bool alterarPermissoes(string alvo, string permissoes, string caminho);
	bool renomearArquivo(string caminhoAntigo, string caminhoNovo);
};



#endif /* CHAMADASDEARQUIVOEDIRETORIO_H_ */
