#include "ChamadasDeExecucao.h"

ChamadasDeExecucao::ChamadasDeExecucao() {

}
//executa execl
bool ChamadasDeExecucao::executarExecl(string parametro){
  	execl("/bin/ls","ls","-l", (char*) NULL);
  	cout << "this is wrote" << endl;
	return false;
}

;

