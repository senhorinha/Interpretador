#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "../view/Terminal.h"
#include "../view/TerminalIncolor.cpp"
#include "../view/TerminalColorido.cpp"
#include "Analisador.cpp"
#include "ChamadasDeArquivoEDiretorio.cpp"
#include "ChamadasDeInformacao.cpp"
#include "ChamadasDeExecucao.cpp"
using namespace std;

Terminal *t;
Analisador *a = new Analisador();
ChamadasDeArquivoEDiretorio *chamadasArquivoEDiretorio =
		new ChamadasDeArquivoEDiretorio();
ChamadasDeInformacao *chamadasDeInformacao = new ChamadasDeInformacao();
ChamadasDeExecucao *chamadasDeExecucao = new ChamadasDeExecucao();

void imprimirComandosDisponiveis() {
	vector<string> comandosDisponiveis = a->getComandosDisponiveis();
	cout << "Comandos disponíveis: [";
	for (int i = 0; i < comandosDisponiveis.size(); i++) {
		auto& c = comandosDisponiveis[i];
		if (i == comandosDisponiveis.size() - 1) {
			cout << c << "]" << endl;
		} else {
			cout << c << ", ";
		}
	}
}

void imprimirMensagemDeBoasVindas() {
	t->limpar();

	// Imprime "Interpretador" na cor verde
	// Arte feita por http://patorjk.com/software/taag/#p=display&f=Ogre&t=Interpretador
	t->mensagemDeSucesso(
			"  _____       _                           _            _      			");
	t->mensagemDeSucesso(
			"  \\_   \\_ __ | |_ ___ _ __ _ __  _ __ ___| |_ __ _  __| | ___  _ __ 	");
	t->mensagemDeSucesso(
			"   / /\\/ '_ \\| __/ _ \\ '__| '_ \\| '__/ _ \\ __/ _` |/ _` |/ _ \\| '__|	");
	t->mensagemDeSucesso(
			"/\\/ /_ | | | | ||  __/ |  | |_) | | |  __/ || (_| | (_| | (_) | |   	");
	t->mensagemDeSucesso(
			"\\____/ |_| |_|\\__\\___|_|  | .__/|_|  \\___|\\__\\__,_|\\__,_|\\___/|_|   	");
	t->mensagemDeSucesso(
			"                          |_|                                       	");
	cout << endl;
	t->mensagemDeAlerta(
			"Código em: https://github.com/thisenrose/Interpretador");
	imprimirComandosDisponiveis();
	cout << "Sintaxe: <help> ou <help> + <comando> ou <comando> + <parametros>"
			<< endl;
	cout << endl;
}

// Imprime as mensagens de ajuda para cada comando
bool executarHelp(vector<string> partesDoComando) {
	int numeroDeParametros = partesDoComando.size() - 1;
	if (numeroDeParametros == 0) {
		imprimirComandosDisponiveis();
		cout
				<< "Sintaxe: <help> ou <help> + <comando> ou <comando> + <parametros>" << endl;
		return true;
	} else {
		string comando = partesDoComando[1];
		string descricao;
		string comoUtilizar;
		string parametros;
		string exemploDeUso;
		if (a->validarComando(comando)) {
			if (comando == "reset") {
				descricao = "Re-apresenta mensagem de boas vindas";
				comoUtilizar = "reset";
				parametros = "nenhum";
				exemploDeUso = "reset";
			} else if (comando == "uname") {
				descricao =
						"Obtêm informações do sistema como kernel, nome do computador, versão do s.o, hardware...";
				comoUtilizar = "uname";
				parametros = "system, all";
				exemploDeUso = "uname system, uname all";
			} else if (comando == "rename") {
				descricao =
						"Renomeia um arquivo, movendo de diretorio se solicitado.Se o novo caminho já existir o arquivo renomeado irá substititui-lo.Quando o arquivo atual será renomeado para o mesmo nome nada é feito.";
				comoUtilizar = "rename p1 p2";
				parametros = "\np1 -> nome_antigo\np2 -> nome_novo";
				exemploDeUso =
						"rename /home/fulano/documentos/nomeAntigo.txt /home/fulano/documentos/nomeNovo.txt";
			} else if (comando == "access") {
				descricao =
						"Verifica as permissões (leitura, escrita, execução) que um usuário possui para um determinado arquivo";
				comoUtilizar = "access p1";
				parametros =
						"\np1 -> r,w,x em que r(leitura) w(escrita) x(executar)";
				exemploDeUso = "access rw /home/fulano/documentos/arquivo.txt";
			} else if (comando == "chmod") {
				descricao =
						"Altera as permissões (leitura, escrita, execução) de um alvo (owner, group ou general) para um determinado arquivo ";
				comoUtilizar = "chmod p1 p2 p3";
				parametros =
						"\np1 -> (owner,group,general)\np2 -> r,w,x em que r(leitura) w(escrita) x(executar)\np3 -> caminho do arquivo";
				exemploDeUso =
						"chmod owner rwx /home/fulano/documentos/arquivo.txt";
			} else if (comando == "execl") {
				descricao =
						"Executa um determinado arquivo********* ";
				comoUtilizar = "execl p1 p2 p3";
				parametros =
						"\np1 -> diretorio\np2 -> arquivo**\np3 -> parametros";
				exemploDeUso =
						"execl /bin/ls ls -l";
			}
			cout << "MANUAL: " << endl;
			cout << comando << ": " << descricao << endl;
			cout << "Como utilizar: " << comoUtilizar << endl;
			cout << "Parâmetros: " << parametros << endl;
			cout << "Exemplo de uso: " << exemploDeUso << endl;
			return true;
		}
		return false;
	}
}

// Verifica qual comando foi digitado e inicia operação
void executar(vector<string> partesDoComando) {
	int numeroDeParametros = partesDoComando.size() - 1;

	bool ocorreuErro = false;
	string mensagem;

	if (partesDoComando[0] == "help") {
		if (!executarHelp(partesDoComando)) {
			ocorreuErro = true;
			mensagem = "Erro! Comando help mal especificado";
		}
	} else {
		if (partesDoComando[0] == "reset" && numeroDeParametros == 0) {
			imprimirMensagemDeBoasVindas();
		} else if (partesDoComando[0] == "uname") {
			if(numeroDeParametros == 1) {
				chamadasDeInformacao->executarUname(partesDoComando[1]);
			} else {
				ocorreuErro = true;
				mensagem = "Erro! Parâmetros necessários: system ou all";
			}

		} else if (partesDoComando[0] == "rename") {
			if (chamadasArquivoEDiretorio->renomearArquivo(partesDoComando[1],
					partesDoComando[2])) {
				mensagem = "Sucesso! Arquivo renomeado";
			} else {
				ocorreuErro = true;
				mensagem = "Erro! Não foi possível realizar operação.";
			}
		} else if (partesDoComando[0] == "access") {
			if (chamadasArquivoEDiretorio->verificarPermissoes(
					partesDoComando[1], partesDoComando[2])) {
				mensagem = "Sucesso! Você tem permissão!";
			} else {
				ocorreuErro = true;
				mensagem = "Erro! Você não tem permissão!";
			}
		} else if (partesDoComando[0] == "chmod") {
			if (chamadasArquivoEDiretorio->alterarPermissoes(partesDoComando[1],
					partesDoComando[2], partesDoComando[3])) {
				mensagem = "Sucesso! Permissão alterada";
			} else {
				ocorreuErro = true;
				mensagem = "Erro! Não foi possivel alterar permissão.";
			}
		} else if (partesDoComando[0] == "uname") {
			if (numeroDeParametros == 0) {
				ocorreuErro = true;
				mensagem = "Erro! Comando uname mal especificado";
			} else {
				if (!chamadasDeInformacao->executarUname(partesDoComando[1])) {
					ocorreuErro = true;
					mensagem = "Erro! Comando uname mal especificado";
				}
			}
		} else if (partesDoComando[0] == "execl" && numeroDeParametros == 3) {
			if (!chamadasDeExecucao->executarExecl(partesDoComando[1], partesDoComando[2], partesDoComando[3])) {
					ocorreuErro = true;
					mensagem = "Erro! Comando execl mal especificado###";
				}
		}

	}

		if (ocorreuErro) {
			t->mensagemDeErro(mensagem);
		} else {
			t->mensagemDeSucesso(mensagem);
		}
}

// Verifica se execução em terminal de sistema
void prepararTerminal(){
	if(isatty(fileno(stdout)) == 1) {
		t = new TerminalColorido();
	} else {
		t =  new TerminalIncolor();
	}
}

int main() {
	prepararTerminal();
	imprimirMensagemDeBoasVindas();
	while (true) {
		char aux[256];
		t->parteInicialDoTerminal();
		std::cin.getline(aux, 256);
		string comando = aux;
		vector<string> partesDoComando = a->separarParametros(comando);
		if (a->validarComando(partesDoComando[0])) {
			executar(partesDoComando);
		} else {
			t->mensagemDeErro(
					"Erro! Comando não reconhecido. Digite help para ajuda");
		}
	}
}
