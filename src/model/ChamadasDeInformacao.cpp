#include "ChamadasDeInformacao.h"

ChamadasDeInformacao::ChamadasDeInformacao() {

}
//executa uname
bool ChamadasDeInformacao::executarUname(string parametro){
  	utsname u_name;

  	uname(&u_name);

	if (parametro == "all") {
		cout << "   sysname[] = " << u_name.sysname << endl;
  		cout << "  nodename[] = " << u_name.nodename << endl;
  		cout << "   release[] = " << u_name.release << endl;
  		cout << "   version[] = " << u_name.version << endl;
  		cout << "   machine[] = " << u_name.machine << endl;
		return true;
	} else if (parametro == "system")
	{
  		cout << "   sysname[] = " << u_name.sysname << endl;
		return true;
	}
  	
	return false;
}

;

