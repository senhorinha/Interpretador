#ifndef CHAMADASDEEXECUCAO_H_
#define CHAMADASDEEXECUCAO_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

class ChamadasDeExecucao {

public:
	ChamadasDeExecucao();
	bool executarExecl(string caminho, string comando, string parametro);
};



#endif /* CHAMADASDEEXECUCAO_H_ */
