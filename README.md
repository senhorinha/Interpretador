# Atividade Prática 1 - Sistemas Operacionais I

## Envolvidos

### Autor

* [Thiago Senhorinha Rose](https://github.com/thisenrose)
* [Rodrigo Aguiar Costa](https://github.com/rodrigoacosta02)

### Orientador

* [Rafael Luiz Cancian](http://www.inf.ufsc.br/~cancian)


## O que fazer

A atividade prática A1 corresponde à implementação de um programa de computador que funcione como um interpretador de comandos simplificado para o sistema operacional Linux. Ele deve mostrar um prompt na tela e aguardar a digitação de uma string pelo usuário. Quando o usuário inserir uma string de comando, o programa deve interpretá-la, separar o comando propriamento dito (primeira palavra) de possíveis parâmetros que tenham sido digitados (palavras seguintes, separadas por espaços). O programa então deve verificar se o comando digitado é válido, ou seja, corresponde a um dos comandos conhecidos. Caso não, apresentar uma mensagem de erro na tela e voltar a apresentar o prompt e aguardar nova string. Caso sim, então deve invocar a chamada de sistema do Linux que corresponde ao comando digitado, incluindo os possíveis parâmetros passados. Os resultados da chamada de sistema  devem então ser apresentados na tela e o procedimento se repete (mostrar o prompt e aguardar a digitação do usuário).

## O que são chamadas de sistema

"Em computação, uma chamada de sistema (system call) é o mecanismo usado pelo programa para requisitar um serviço do sistema operacional, ou mais especificamente, do núcleo do sistema operacional." - [Wiki-Chamada de Sistema](https://pt.wikipedia.org/wiki/Chamada_de_sistema)

Chamada de sistema pode ser resumido como um mecanismo disponível aos aplicativos de um sistema operacional que fornece acesso à recursos que normalmente não teria permissão para usar. É uma interface entre o Sistema Operacional e seus aplicativos.

![Linux Kernel System Call](https://upload.wikimedia.org/wikipedia/commons/4/45/Linux_kernel_System_Call_Interface_and_glibc.svg) 


# Funções Escolhidas

## Uname 

Utilizado para obter informações do sistema.

Para mais detalhes: 

* [Linux Programmer's Manual (uname)](http://www.unix.com/man-page/linux/2/uname/)
* [Linux Socket Programming by Example (uname)](http://alas.matf.bg.ac.rs/manuals/lspe/snode=75.html)

### Sintaxe

``` cpp 
#include <sys/utsname.h>
int uname(struct utsname *buf);
```

``` cpp 
struct utsname {

	// Sistema operacional em uso
    char    sysname[SYS_NMLN];
    //	Nome do computador na rede
    char    nodename[SYS_NMLN];
    // Versão do kernel
    char    release[SYS_NMLN];
    // Versão do sistema operacional. No linux mostra a e sua data de lançamento.
    char    version[SYS_NMLN];
    // Descreve o hardware (exemplo: x86_64)
    char    machine[SYS_NMLN];
    // Nome do host de NIS/YP
    char    domainname[SYS_NMLN];
};
```

### Como usar

``` cpp
// Código retirado de: http://alas.matf.bg.ac.rs/manuals/lspe/snode=75.html
	struct utsname u_name;

	int z = uname(&u_name);

	if (z == -1) {
		fprintf(stderr, "%s: uname(2)\n", strerror(errno));
		exit(1);
	}

	printf("   sysname[] = '%s';\n", u_name.sysname);
	printf("  nodename[] = '%s';\n", u_name.nodename);
	printf("   release[] = '%s';\n", u_name.release);
	printf("   version[] = '%s';\n", u_name.version);
	printf("   machine[] = '%s';\n", u_name.machine);
	printf("domainname[] = '%s';\n", u_name.domainname);
	
```

**output:** 

```
   sysname[] = 'Linux';
  nodename[] = 'timemachine';
   release[] = '3.11.0-12-generic';
   version[] = '#19-Ubuntu SMP Wed Oct 9 16:20:46 UTC 2013';
   machine[] = 'x86_64';
domainname[] = '(none)';
```

## Rename

Renomeia um arquivo, movendo de diretorio se solicitado. Se o novo caminho já existir o arquivo renomeado irá substititui-lo.
Quando o arquivo atual será renomeado para o mesmo nome nada é feito. 

Para mais detalhes: [Linux Programmer's Manual (rename)](http://www.unix.com/man-page/linux/2/rename/)

### Sintaxe
``` cpp
#include <stdio.h>
int rename(const char *oldpath, const char *newpath);
```

### Como usar

Para um projeto com uma pasta resource na pasta raiz temos o seguinte código para renomeação.

``` cpp
	int resultado;
	char nomeAntigo[] = "resources/nomeAntigo.txt";
	char nomeNovo[] = "resources/nomeNovo.txt";
	resultado = rename(nomeAntigo, nomeNovo);
	if (resultado == 0) {
		cout << "Arquivo renomeado com Sucesso! :)" << endl;
	} else {
		cout << "Ocorreu um erro durante a renomeação! :(" << endl;
	}
```

## Access 

Verifica as permissões (leitura, escrita, execução) que um usuário possui para um determinado arquivo.

Para mais detalhes: 

* [Linux Programmer's Manual (access)](http://man7.org/linux/man-pages/man2/access.2.html)
* [Understanding Linux File Permissions](http://www.linux.com/learn/tutorials/309527-understanding-linux-file-permissions)

### Sintaxe
``` cpp
#include <unistd.h>
int access(const char *pathname, int mode);
```

Modos existentes:

* R_OK - Leitura (read) 
* W_OK - Escrita (write)
* X OK - Execução (execute)
* F_OK - Arquivo existente?

### Como usar

``` cpp
	int resultado;
	char caminho[] = "resources/arquivo.txt";
	// Retorna 0 se usuário possuir acesso ao modo R_OK (Read) ou -1 caso contrário
	resultado = access(caminho, R_OK);
	if (resultado == 0) {
		cout << "Usuário com permissão de leitura sobre o arquivo!" << endl;
	} else {
		cout << "Usuário sem tenho permissão de leitura!"
	}
``` 

**Para o arquivo:**

```
-rw-r--r-- 1 thiago thiago    0 Mar 28 20:29 arquivo.txt
``` 

**output:**

```
Tenho permissão de leitura sobre o arquivo!
``` 

## Chmod

Modifica as pemissões de um arquivo

Para mais detalhes:

* [IBM: Change File Authorizations](https://publib.boulder.ibm.com/infocenter/iseries/v5r4/index.jsp?topic=%2Fapis%2Fchmod.htm)

### Sintaxe
``` cpp
#include <sys/stat.h>
int chmod(const char *path, mode_t mode);
```

### Como usar

Atribuindo permissão de leitura e escrita para todos.
``` cpp
	char caminho[] = "resources/arquivo.txt";
	int status;
	struct stat buffer;
	chmod(caminho, S_IROTH | S_IWOTH);
	status = stat(caminho, &buffer);
	cout << status << endl;
```

**Resultado:**
	
```
-------rw- 1 thiago thiago    0 Mar 28 20:29 arquivo.txt
```

## Execl

### Sintaxe

``` cpp
#include <unistd.h>
int execl(const char *path, const char *arg, ...);
```

### Como usar

#### Exemplo 1

Utiliza o comando shell mkdir para criar uma pasta com nome novaPasta

``` cpp
execl ("/bin/mkdir", "mkdir", "novaPasta", (char *)0);
```

#### Exemplo 2

Utiliza o comando shell ls passando o paramêtro -la (lista no formato [l]ongo e mosta os arquivos ocultos [a])

``` cpp
execl ("/bin/ls", "ls", "-la", (char *)0);
```