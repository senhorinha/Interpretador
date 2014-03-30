#include "../view/Terminal.h"
#include <stdio.h>
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
	void rename(const char *oldpath, const char *newpath);
	virtual ~ChamadasDeArquivoEDiretorio();
};

