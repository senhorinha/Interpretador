#ifndef CHAMADASDEEXECUCAO_H_
#define CHAMADASDEEXECUCAO_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>


using namespace std;

class ChamadasDeExecucao {

public:
	ChamadasDeExecucao();
	bool executarExecl(string parametro);
};



#endif /* CHAMADASDEEXECUCAO_H_ */
