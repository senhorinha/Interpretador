#ifndef CHAMADASDEINFORMACAO_H_
#define CHAMADASDEINFORMACAO_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>

using namespace std;

class ChamadasDeInformacao {

public:
	ChamadasDeInformacao();
	bool executarUname(string parametro);
};



#endif /* CHAMADASDEINFORMACAO_H_ */
