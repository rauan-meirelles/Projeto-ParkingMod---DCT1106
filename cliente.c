////////////////////////////////////
///        Módulo Cliente        ///
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utilidade.h"

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
	char* matr;

	matr = telaPesquisarVei();
	cli = buscarVei(matr);
  if (cli == NULL) {
    printf("Essa mátricula não está cadastrada no sistema!\n");
    printf("Você será redirecionado para a tela de Cadastro!\n");
    printf("Tecle >>>>ENTER<<<<\n");
    getchar();
    telaCadastroVei();
  } else {
	exibirVei(cli);
	free(cli); 
	free(matr);
  }
}

/// Atualização de Veículo
void atualizarVei(void) {
	Cliente* cli;
	char* matr;

	matr = telaAtualizarVei();
	cli = buscarVei(matr);
	if (cli == NULL) {
    	printf("\n\nVeículo não encontrado!\n\n");
  	} else {
		  cli = telaCadastroVei();
		  strcpy(cli->matr, matr);
		  regravarVei(cli);
		  free(cli);
	}
	free(matr);
}

/// Exclusão de Veículo
void excluirVei(void) {
	Cliente* cli;
	char *matr;

	matr = telaExcluirVei();
	cli = (Cliente*) malloc(sizeof(Cliente));
	cli = buscarVei(matr);
	if (cli == NULL) {
    	printf("\n\nVeículo não encontrado!\n\n");
  	} else {
		  cli->status = False;
		  regravarVei(cli);
      printf("Cadastro removido com sucesso!\n");
      printf("Tecle >>>Enter<<< para voltar ao Menu Principal\n");
		  free(cli);
	}
	free(matr);
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
  printf("///                                UFRN                                   ///\n");
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
  printf("///                                UFRN                                   ///\n");
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
  printf("///                                UFRN                                   ///\n");
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
  /// Mátricula 

  printf("///           Matrícula (apenas números): ");
  scanf("%[^\n]", cli->matr);
  getchar();
	while (!validarMatr(cli->matr)){
    printf("///           Matrícula invalida! Digite novamente: ");
    scanf("%[^\n]", cli->matr);
  }

  /// Nome do Cliente
  printf("///           Nome completo: ");
  scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->nome);
  getchar();
  while (!validarNome(cli->nome)){
    printf("///           Nome invalido, digite novamente: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->nome);
  }

  /// Cpf do Cliente	 
  printf("///           Digite seu CPF: ");
  scanf(" %[^\n]", cli->cpf);
  getchar();
  while(!validarCPF(cli->cpf)) {
    printf("///           CPF invalido, digite novamente: ");
    scanf(" %[^\n]", cli->cpf);
  }
	
  /// Data de nascimento do Cliente
  printf("///           Data de Nascimento (dd/mm/aaaa):  ");
  scanf("%d/%d/%d", &cli->dia, &cli->mes, &cli->ano);
  getchar();
  while (!ehData(cli->dia, cli->mes, cli->ano)){
    printf("///           Data invalida! Digite novamente (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&cli->dia, &cli->mes, &cli->ano);
  }

  /// Placa do Veículo
  printf("///           Placa do Veículo: ");
  scanf(" %[^\n]", cli->placa);
  getchar();
	while (!validarPlaca(cli->placa)) {
    printf("///           Placa invalida! Digite novamente: ");
    scanf(" %[^\n]", cli->placa);
  }

  /// Celular do Cliente
  printf("///           Celular (apenas números com DDD): ");
  scanf("%[^\n]", cli->celular);
  getchar();
  while (!validarFone(cli->celular)) {
    printf("///           Celular invalido! Digite novamente: ");
    scanf(" %[^\n]", cli->celular);
  }

  cli->status = True;
  printf("\nVeículo cadastrado! Digite > Enter < para voltar ao menu Cliente!");
  getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  return cli;
}

char* telaPesquisarVei(void) {
	char* matr;

	matr = (char*) malloc(12*sizeof(char));
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///                                UFRN                                   ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)  =   Pesquisar Veículo  =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe sua Matrícula: ");
	scanf("%[0-9]", matr);
  getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return matr;
}



char* telaAtualizarVei(void) {
	char* matr;

	matr = (char*) malloc(12*sizeof(char));
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///                                UFRN                                   ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)   =  Atualizar Veículo  =   (o ! o) =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe a Matrícula do Proprietário do Veículo:");
	scanf("%[A-Z 0-9 -]", matr);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  	return matr;
}

char* telaExcluirVei(void) {
	char *matr;

	matr = (char*) malloc(12*sizeof(char));
  limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///                                UFRN                                   ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)   =   Excluir Veículo  =   (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe a Matrícula do Proprietário do Veículo: ");
	scanf("%[A-Z 0-9 -]", matr);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return matr;
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


Cliente* buscarVei(char* matr) {
	FILE* fp;
	Cliente* cli;

	cli = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("cliente.dat", "rb");
	if (fp == NULL) {
		telaErroCliente();
	}
	while(fread(cli, sizeof(Cliente), 1, fp)) {
		if ((strcmp(cli->matr, matr) == 0) && (cli->status == True)) {
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
		printf("Matrícula: %s\n", cli->matr);
    printf("Placa: %s\n", cli->placa);
		printf("Nome do Proprietário: %s\n", cli->nome);
		printf("Data de Nasc: %d/%d/%d\n", cli->dia,cli->mes,cli->ano);
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
	fp = fopen("cliente.dat", "r+b");
	if (fp == NULL) {
		telaErroCliente();
	}
	achou = False;
	while(fread(cliLido, sizeof(Cliente), 1, fp) && !achou) {
		if (strcmp(cliLido->matr, cli->matr) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
        	fwrite(cli, sizeof(Cliente), 1, fp);
		}
	}
	fclose(fp);
	free(cliLido);
}

