#include "ChamadasDeExecucao.h"

ChamadasDeExecucao::ChamadasDeExecucao() {

}
//executa execl
bool ChamadasDeExecucao::executarExecl(string caminho, string comando, string parametro){
  	
  	pid_t pid = fork();
  	
  	if(pid < 0){
  		cout << "Erro!" << endl;
  		return false;
  	}if(pid != 0) {
  		int status;
  		waitpid(-1, &status,0);
  		return false;
  	} else {
  		char *char1 = strdup(caminho.c_str());
  		char *char2 = strdup(comando.c_str());
  		char *char3 = strdup(parametro.c_str());
  		execl(char1, char2, char3, (char*) 	NULL);
  	}
  	
	return true;
}

;