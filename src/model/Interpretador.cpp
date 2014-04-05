#include "../view/TerminalColorido.cpp"
#include "Analisador.cpp"
#include "ChamadasDeArquivoEDiretorio.cpp"
#include <iostream>
#include <stdexcept>
#include <unistd.h>

using namespace std;

TerminalColorido *t = new TerminalColorido();
Analisador *a = new Analisador();
ChamadasDeArquivoEDiretorio *chamadasArquivoEDiretorio =
		new ChamadasDeArquivoEDiretorio();

void imprimirComandosDisponiveis() {
	vector<string> comandosDisponiveis = { "help", "uname", "rename", "access",
			"chmod", "execl" };
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
	imprimirComandosDisponiveis();
	cout << "Sintaxe: <help> ou <help> + <comando> ou <comando> + <parametros>"
			<< endl;
	cout << endl;
}

bool executarHelp(vector<string> partesDoComando) {
	int numeroDeParametros = partesDoComando.size() - 1;
	if (numeroDeParametros == 0) {
		imprimirComandosDisponiveis();
		cout
				<< "Sintaxe: <help> ou <help> + <comando> ou <comando> + <parametros>";
		return true;
	} else {
		string comando = partesDoComando[1];
		string descricao;
		string comoUtilizar;
		string parametros;
		string exemploDeUso;
		if (a->verificarComando(comando)) {
			if (comando == "reset") {
				descricao = "re-apresenta mensagem de boas vindas";
				comoUtilizar = "reset";
				parametros = "nenhum";
				exemploDeUso = "reset";
			} else if (comando == "uname") {
				descricao =
						"obtêm informações do sistema como kernel, nome do computador, versão do s.o, hardware...";
				comoUtilizar = "uname";
				parametros = "nenhum";
				exemploDeUso = "uname";
			} else if (comando == "rename") {
				descricao =
						"Renomeia um arquivo, movendo de diretorio se solicitado.Se o novo caminho já existir o arquivo renomeado irá substititui-lo.Quando o arquivo atual será renomeado para o mesmo nome nada é feito.";
				comoUtilizar = "rename p1 p2";
				parametros = "p1 -> nome_antigo | p2 -> nome_novo";
				exemploDeUso =
						"rename /home/fulano/documentos/nomeAntigo.txt /home/fulano/documentos/nomeNovo.txt";
			} else if (comando == "access") {
				descricao =
						"Verifica as permissões (leitura, escrita, execução) que um usuário possui para um determinado arquivo";
				comoUtilizar = "access p1";
				parametros =
						"p1 -> r,w,x em que r(leitura) w(escrita) x(executar)";
				exemploDeUso = "access rw /home/fulano/documentos/arquivo.txt";
			} else if (comando == "chmod") {
			} else if (comando == "execl") {

			}
			cout << "MANUAL: " << endl;
			cout << comando << ": " << descricao << endl;
			cout << "Como utilizar: " << comoUtilizar << endl;
			cout << "Parâmetros: " << parametros << endl;
			cout << "Exemplo de uso: " << exemploDeUso << endl;
			return true;
		} else {
			return false;
		}

	}
}

bool executar(vector<string> partesDoComando) {
	int numeroDeParametros = partesDoComando.size() - 1;
	bool ocorreuErro = false;
	string mensagem;

	if (partesDoComando[0] == "help" || numeroDeParametros <= 1) {
		if (!executarHelp(partesDoComando)) {
			ocorreuErro = true;
			mensagem = "Erro! Comando help mal especificado";
		}
	} else {
		if (partesDoComando[0] == "reset" && numeroDeParametros == 0) {
			imprimirMensagemDeBoasVindas();
		} else if (partesDoComando[0] == "uname") {

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
				mensagem = "Você tem permissão!";
			} else {
				ocorreuErro = true;
				mensagem = "Você não tem permissão!";
			}
		} else if (partesDoComando[0] == "chmod") {

		} else if (partesDoComando[0] == "execl") {

		}
	}
	if (ocorreuErro) {
		t->mensagemDeErro(mensagem);
	} else {
		t->mensagemDeSucesso(mensagem);
	}
	return false;

}

int main() {
	imprimirMensagemDeBoasVindas();
	while (true) {
		char aux[256];
		t->parteInicialDoTerminal();
		std::cin.getline(aux, 256);
		string comando = aux;
		vector<string> partesDoComando = a->separarParametros(comando);
		if (a->verificarComando(partesDoComando[0])) {
			executar(partesDoComando);
		} else {
			t->mensagemDeErro(
					"Erro! Comando não reconhecido. Digite help para ajuda");
		}

	}
}
