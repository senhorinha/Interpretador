#include "ChamadasDeInformacao.h"

ChamadasDeInformacao::ChamadasDeInformacao() {

}
//executa uname
bool ChamadasDeInformacao::executarUname(string parametro){
  	utsname u_name;

  	uname(&u_name);

	if (parametro == "all") {
		cout << "         Sistema = " << u_name.sysname << endl;
  		cout << " Nome da Maquina = " << u_name.nodename << endl;
  		cout << "   Versao Kernel = " << u_name.release << endl;
  		cout << "     Versao S.O. = " << u_name.version << endl;
  		cout << "      Plataforma = " << u_name.machine << endl;
		return true;
	} else if (parametro == "system")
	{
  		cout << "\t\tSistema = " << u_name.sysname << endl;
		return true;
	}
  	
	return false;
}

;

