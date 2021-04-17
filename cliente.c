////////////////////////////////////
///        Módulo Cliente        ///
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utillidade.h"

typedef struct cliente Cliente;

void moduloCliente(void) {
	char opcao;
	do {
		opcao = menuCliente();
		switch(opcao) {
			case '1': 	CadastrarVei();
						break;
			case '2': 	PesquisarVei();
						break;
			case '3': 	AtualizarVei();
						break;
			case '4': 	ExcluirVei();
						break;
		} 		
	} while (opcao != '0');
}

/// Cadastro de Veículo
void CadastrarVei(void) {
	Cliente* cli;

	cli = telaCadastroVei();
	gravarVei(cli);
	free(cli);
}

/// Pesquisa de Veículo
void PesquisarVei(void) {
	Cliente* cli;
	char* placa;

	placa = telaPesquisarVei();
	cli = buscarVei(placa);
	exibirVei(cli);
	free(cli); 
	free(placa);
}

/// Atualização de Veículo
void AtualizarVei(void) {
	Cliente* cli;
	char* placa;

	placa = telaAtualizarVei();
	cli = buscarVei(placa);
	if (cli == NULL) {
    	printf("\n\nVeículo não encontrado!\n\n");
  	} else {
		  cli = telaCadastroVei();
		  strcpy(cli->placa, placa);
		  regravarVei(cli);
		  // Outra opção:
		  // excluirVei(placa);
		  // gravarVei(cli);
		  free(cli);
	}
	free(placa);
}

/// Exclusão de Veículo
void ExcluirVei(void) {
	Cliente* cli;
	char *placa;

	placa = telaExcluirVei();
	cli = (Cliente*) malloc(sizeof(Cliente));
	cli = buscarVei(placa);
	if (cli == NULL) {
    	printf("\n\nVeículo não encontrado!\n\n");
  	} else {
		  cli->status = False;
		  regravarVei(cli);
		  free(cli);
	}
	free(placa);
}

///Telas

char menuCliente(void) {
  	char op;

	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o) = = = Menu Cliente  = = =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar um novo Veículo                                ///\n");
	printf("///           2. Pesquisar um Veículo cadastrado                          ///\n");
	printf("///           3. Atualizar o cadastro de um Veículo                       ///\n");
	printf("///           4. Excluir um Veículo do sistema                            ///\n");
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada:                                   ///\n");
	scanf("%c", &op);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return op;
}

void telaErroArquivo(void) {
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = =  Ops! Ocorreu em erro = = = = = =             ///\n");
	printf("///           = = =  Não foi possível acessar o arquivo = = =             ///\n");
	printf("///           = = = = com informações sobre os Veículos = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = =  Pedimos desculpas pelos inconvenientes = =             ///\n");
	printf("///           = = =  mas este programa será finalizado! = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
	exit(1);
}


Cliente* telaCadastroVei(void) {
	Cliente *cli

	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)  =  Cadastro de Veículo =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");

	cli = (Cliente*) malloc(sizeof(Cliente));
	do {
		printf("///           CPF (apenas números): ");
		scanf("%[^\n]", cli->cpf);
		getchar();
	} while (!validarCPF(cli->cpf));
	printf("///           Nome completo: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->nome);
	getchar();
	printf("///           Data de Nascimento (dd/mm/aaaa):  ");
	scanf("%[0-9/]", cli->nasc);
	getchar();
	do {
		printf("///           Celular  (apenas números com DDD): ");
		scanf("%[^\n]", cli->celular);
		getchar();
	} while (!validarFone(cli->celular));
	cada->status = True;
	printf("///           Placa do Veículo: ");
	do {
	scanf("%[A-Z 0-9]", cli->placa);
	} while (!validarPlaca(cli->placa));
	cli->status = True;
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  	return cli;
}
