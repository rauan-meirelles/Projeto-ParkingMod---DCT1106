////////////////////////////////////////
////       Módulo Funcionário       ////
////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "utilidade.h"

typedef struct funcionario Funcionario;

void moduloFuncionario(void) {
	char opcao;
	do {
		opcao = menuFuncionario();
		switch(opcao) {
			case '1': 	cadastrarFuncionario();
						break;
			case '2': 	pesquisarFuncionario();
						break;
			case '3': 	atualizarFuncionario();
						break;
			case '4': 	excluirFuncionario();
						break;
		} 		
	} while (opcao != '0');
}


///Cadastro de Funcionário
void cadastrarFuncionario(void) {
	Funcionario* funci;

	funci = telaCadastrarFuncionario();
	gravarFuncionario(funci);
	free(funci);
}


///Pesquisa de Funcionário
void pesquisarFuncionario(void) {
	Funcionario* funci;
	char* cpf;

	cpf = telaPesquisarFuncionario();
	funci = buscarFuncionario(cpf);
    if (funci == NULL) {
      printf("Esse Funcionário não está cadastrada no sistema!\n");
      printf("Você será redirecionado para a tela de Cadastro!\n");
      printf("Tecle >>>>ENTER<<<<\n");
      getchar();
      telaCadastrarFuncionario();
	}
	exibirFuncionario(funci);
	free(funci); 
	free(cpf);
}


///Atualização de Funcionário
void atualizarFuncionario(void) {
    Funcionario* funci;
	char* cpf;

	cpf = telaAtualizarFuncionario();
	funci = buscarFuncionario(cpf);
	if (funci == NULL) {
    	printf("\n\nFuncionário não encontrado!\n\n");
  	} else {
		  funci = telaCadastrarFuncionario();
		  strcpy(funci->cpf, cpf);
		  regravarFuncionario(funci);
		  free(funci);
	}
	free(cpf);	
}

/// Exclusão de Funcionário
void excluirFuncionario(void) {
	Funcionario* funci;
	char *cpf;

	cpf = telaExcluirFuncionario();
	funci = (Funcionario*) malloc(sizeof(Funcionario));
	funci = buscarFuncionario(cpf);
	if (funci == NULL) {
    	printf("\n\nFuncionário não encontrado!\n\n");
  	} else {
		  funci->status = False;
		  regravarFuncionario(funci);
		  free(funci);
	}
	free(cpf);
}

///Telas

char menuFuncionario(void) {
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
  printf("///                               UFRN                                    ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           (o ! o) = = = Menu Funcionário  = = =  (o ! o)              ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar Funcionário                                    ///\n");
	printf("///           2. Pesquisar Funcionário                                    ///\n");
	printf("///           3. Atualizar Funcionário                                    ///\n");
  printf("///           4. Excluir Funcionário                                      ///\n");
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada:                                   ///\n");
  scanf("%c", &op);
  getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  delay(1);
  return op;
}

void telaErroFuncionario(void) {
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///                               UFRN                                    ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = =  Ops! Ocorreu em erro = = = = = =             ///\n");
	printf("///           = = =  Não foi possível acessar o arquivo = = =             ///\n");
	printf("///           = = = com informações sobre os Funcionários = =             ///\n");
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

Funcionario* telaCadastrarFuncionario(void) {
  Funcionario *funci;

  limpaTela();
	printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                       ///\n");
  printf("///          ===================================================          ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
  printf("///                Sistema de Controle de Estacionamentos                 ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///                               UFRN                                    ///\n");
  printf("///          ===================================================          ///\n");
  printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                       ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///           = (o ! o) = Cadastro de Funcionário = (o ! o) =             ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///                                                                       ///\n");
  printf("///                                                                       ///\n");

  funci = (Funcionario*) malloc(sizeof(Funcionario));

  /// Nome do Funcionário
  printf("///           Nome completo: ");
  scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funci->nome);
  getchar();
  while (!validarNome(funci->nome)){
    printf("///           Nome invalido, digite novamente: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funci->nome);
  }

  /// Data de nascimento do Funcionário
  printf("///           Data de Nascimento (dd/mm/aaaa):  ");
  scanf("%d/%d/%d", &funci->dia, &funci->mes, &funci->ano);
  getchar();
  while (!ehData(funci->dia, funci->mes, funci->ano)){
    printf("///           Data invalida! Digite novamente (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&funci->dia, &funci->mes, &funci->ano);
  }

  /// Cpf do Funcionário	 
  printf("///           Digite seu CPF: ");
  scanf(" %[^\n]", funci->cpf);
  getchar();
  while(!validarCPF(funci->cpf)) {
    printf("///           CPF invalido, digite novamente: ");
    scanf(" %[^\n]", funci->cpf);
  }
	
  funci->status = True;
  printf("\nFuncionário cadastrado! Digite > Enter < para voltar ao menu Funcionário!");
  getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  delay(1);
	return funci;
}

void* telaPesquisarFuncionario(void) {
	char* cpf;

  cpf = (char*) malloc(12*sizeof(char));
  limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///                               UFRN                                    ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)  = Pesquisar Funcionário =  (o ! o) =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o cpf do Funcionário: ");
	scanf(" %[^\n]", cpf);
  getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return cpf;
}

void* telaAtualizarFuncionario(void) {
	char* cpf;

	cpf = (char*) malloc(12*sizeof(char));
  limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///                               UFRN                                    ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o) =  Atualizar Funcionário =  (o ! o) =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o cpf do Funcionário:");
	scanf(" %[^\n]", cpf);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  	return cpf;
}

void* telaExcluirFuncionario(void) {
	char *cpf;

	cpf = (char*) malloc(12*sizeof(char));
  	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///              (o ! o) == ==  PARKINGMOD   = == == (o ! o)              ///\n");
	printf("///                Sistema de Controle de Estacionamentos                 ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///                               UFRN                                    ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)  =  Excluir Funcionário  = (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o cpf do Funcionário: ");
	scanf(" %[^\n]", cpf);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return cpf;
}

void gravarFuncionario(Funcionario* funci) {
	FILE* fp;

	fp = fopen("funcionarios.dat", "ab");
	if (fp == NULL) {
		telaErroFuncionario();
	}
	fwrite(funci, sizeof(Funcionario), 1, fp);
	fclose(fp);
}

Funcionario* buscarFuncionario(char* cpf) {
	FILE* fp;
	Funcionario* funci;

	funci = (Funcionario*) malloc(sizeof(Funcionario));
	fp = fopen("funcionarios.dat", "rb");
	if (fp == NULL) {
		telaErroFuncionario();
	}
	while(fread(funci, sizeof(Funcionario), 1, fp)) {
		if ((strcmp(funci->cpf, cpf) == 0) && (funci->status == True)) {
			fclose(fp);
			return funci;
		}
	}
	fclose(fp);
	return NULL;
}


void exibirFuncionario(Funcionario* funci) {

	if (funci == NULL) {
		printf("\n= = = Funcionário Inexistente = = =\n");
	} else {
		printf("\n= = = Funcionário Cadastrado = = =\n");
		printf("Nome: %s\n", funci->nome);
		printf("CPF: %s\n", funci->cpf);
		printf("Data de Nasc: %d/%d/%d\n", funci->dia,funci->mes,funci->ano);
		printf("Status: %d\n", funci->status);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}


void regravarFuncionario(Funcionario* funci) {
	int achou;
	FILE* fp;
	Funcionario* funciLido;

	funciLido = (Funcionario*) malloc(sizeof(Funcionario));
	fp = fopen("funcionarios.dat", "r+b");
	if (fp == NULL) {
		telaErroFuncionario();
	}
	// while(!feof(fp)) {
	achou = False;
	while(fread(funciLido, sizeof(Funcionario), 1, fp) && !achou) {
		//fread(funciLido, sizeof(Funcionario), 1, fp);
		if (strcmp(funciLido->cpf, funci->cpf) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Funcionario), SEEK_CUR);
        	fwrite(funci, sizeof(Funcionario), 1, fp);
			//break;
		}
	}
	fclose(fp);
	free(funciLido);
}
