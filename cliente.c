////////////////////////////////////
///        Módulo Cliente        ///
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "ultilidade.h"

typedef struct cliente Cliente;

void moduloCliente(void) {
	char opcao;
	do {
		opcao = menuCliente();
		switch(opcao) {
			case '1': 	cadastrarVei();
						break;
			case '2': 	pesquisarVei();
						break;
			case '3': 	atualizarVei();
						break;
			case '4': 	excluirVei();
						break;
		} 		
	} while (opcao != '0');
}

/// Cadastro de Veículo
void cadastrarVei(void) {
	Cliente* cli;

	cli = telaCadastroVei();
	gravarVei(cli);
	free(cli);
}

/// Pesquisa de Veículo
void pesquisarVei(void) {
	Cliente* cli;
	char* placa;

	placa = telaPesquisarVei();
	cli = buscarVei(placa);
	if (cli == NULL) {
    	printf("\n\nVeículo não encontrado!\n\n");
	}
	exibirVei(cli);
	free(cli); 
	free(placa);
}

/// Atualização de Veículo
void atualizarVei(void) {
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
void excluirVei(void) {
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

void telaErroCliente(void) {
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
	Cliente *cli;

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
  /// Nome do Cliente
  printf("///           Digite seu primeiro nome: ");
	scanf(" %[^\n]", cli->nome);
  while(!validarNome(cli->nome)) {
    printf("///           Nome inválido, digite novamente: ");
    scanf(" %[^\n]", cli->nome);
  }
  
  /// Cpf do Cliente
	printf("///           Digite seu CPF: ");
  scanf(" %[^\n]", cli->cpf);
  while(!validarCPF(cli->cpf)){
    printf("///           CPF inválido, digite novamente: ");
    scanf(" %[^\n]", cli->cpf);
  }
	
  /// Data de nascimento do Cliente
  printf("///           Digite sua data de nascimento (dd/mm/aaaa): ");
  scanf("%d/%d/%d",&cli->dia, &cli->mes, &cli->ano);
  while(!validarData(cli->dia, cli->mes, cli->ano)){
    printf("///           Data inválida! Digite novamente (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&cli->dia, &cli->mes, &cli->ano);
  }

  /// Placa do Veículo
	printf("///           Placa do Veículo: ");
  scanf(" %[^\n]", cli->placa);
	while (!validarPlaca(cli->placa)){
    printf("///           Placa inválida! Digite novamente: ");
    scanf(" %[^\n]", cli->placa);
  }

  /// Celular do Cliente
  printf("///           Celular (apenas números com DDD): ");
  scanf(" %[^\n]", cli->celular);
  while (!validarFone(cli->celular)){
    printf("///           Celular inválido! Digite novamente: ");
    scanf(" %[^\n]", cli->celular);
  }
  cli->status = '1';
  gravarVei(cli);
  printf("\nVeículo cadastrado! Digite > Enter < para voltar ao menu Cliente!");
  getchar();
  getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  	return cli;
}

char* telaPesquisarVei(void) {
	char* placa;

	placa = (char*) malloc(12*sizeof(char));
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
	printf("///           = (o ! o)  =   Pesquisar Veículo  =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe a placa do Veículo: ");
	scanf(" %[^\n]", placa);
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return placa;
}



char* telaAtualizarVei(void) {
	char* placa;

	placa = (char*) malloc(12*sizeof(char));
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
	printf("///           = (o ! o)   =  Atualizar Veículo  =   (o ! o) =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe a placa do Veículo:");
	scanf("%[A-Z 0-9 -]", placa);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  	return placa;
}

char* telaExcluirVei(void) {
	char *placa;

	placa = (char*) malloc(12*sizeof(char));
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
	printf("///           = (o ! o)   =   Excluir Veículo  =   (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe a Placa do Veículo: ");
	scanf("%[A-Z 0-9 -]", placa);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return placa;
}



void gravarVei(Cliente* cli) {
  FILE* fp;
  fp = fopen("cliente.dat", "ab");
  if (fp == NULL) {
    telaErroCliente();
    printf("Não é possível continuar o programa...\n");
  exit(1);
  }
  fwrite(cli, sizeof(Cliente), 1, fp);
  fclose(fp);
}


Cliente* buscarVei(char* placa) {
	FILE* fp;
	Cliente* cli;

	cli = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("Clientes.dat", "rb");
	if (fp == NULL) {
		telaErroCliente();
	}
	while(fread(cli, sizeof(Cliente), 1, fp)) {
		if ((strcmp(cli->placa, placa) == 0) && (cli->status == True)) {
			fclose(fp);
			return cli;
		}
	}
	fclose(fp);
	return NULL;
}

void exibirVei(Cliente* cli) {

	if (cli == NULL) {
		printf("\n= = = Veículo Inexistente = = =\n");
	} else {
		printf("\n= = = Veículo Cadastrado = = =\n");
		printf("Nome: %s\n", cli->nome);
		printf("CPF: %s\n", cli->cpf);
		printf("Data de Nasc: %d/%d/%d\n", cli->dia, cli->mes, cli->ano);
		printf("Placa do Veículo: %s\n", cli->placa);
		printf("Celular: %s\n", cli->celular);
		printf("Status: %d\n", cli->status);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}

void regravarVei(Cliente* cli) {
	int achou;
	FILE* fp;
	Cliente* cliLido;

	cliLido = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "r+b");
	if (fp == NULL) {
		telaErroCliente();
	}
	// while(!feof(fp)) {
	achou = False;
	while(fread(cliLido, sizeof(Cliente), 1, fp) && !achou) {
		//fread(cliLido, sizeof(Cliente), 1, fp);
		if (strcmp(cliLido->placa, cli->placa) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
        	fwrite(cli, sizeof(Cliente), 1, fp);
			//break;
		}
	}
	fclose(fp);
	free(cliLido);
}
