#include "ChamadasDeInformacao.h"

ChamadasDeInformacao::ChamadasDeInformacao() {

}
//executa uname
bool ChamadasDeInformacao::executarUname(vector<string> partesDoComando){
	int z;
  	utsname u_name;

  	uname(&u_name);

  	int numeroDeParametros = partesDoComando.size() - 1;
	if (numeroDeParametros == 0) {
		cout << "   sysname[] = " << u_name.sysname << endl;
		return true;
	} else if (partesDoComando[1] == "all")
	{
  		cout << "   sysname[] = " << u_name.sysname << endl;
  		cout << "  nodename[] = " << u_name.nodename << endl;
  		cout << "   release[] = " << u_name.release << endl;
  		cout << "   version[] = " << u_name.version << endl;
  		cout << "   machine[] = " << u_name.machine << endl;
		return true;
	}
  	
	return false;
}

;

