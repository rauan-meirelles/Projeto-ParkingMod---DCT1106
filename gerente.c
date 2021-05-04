////////////////////////////////////////
////         Módulo Gerençia        ////
////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerente.h"
#include "ultilidade.h"

typedef struct gerente Gerente;

void moduloGerente(void) {
	char opcao;
	do {
		opcao = menuGerente();
		switch(opcao) {
			case '1': 	cadastrarGerente();
						break;
			case '2': 	pesquisarGerente();
						break;
			case '3': 	atualizarGerente();
						break;
			case '4': 	excluirGerente();
						break;
		} 		
	} while (opcao != '0');
}


///Cadastro de Gerente
void cadastrarGerente(void) {
	Gerente* ger;

	ger = telaCadastrarGerente();
	gravarGerente(ger);
	free(ger);
}


///Pesquisa de Gerente
void pesquisarGerente(void) {
	Gerente* ger;
	char* cpf;

	cpf = telaPesquisarGerente();
	ger = buscarGerente(cpf);
    if (ger == NULL) {
    	printf("\n\nGerente não encontrado!\n\n");
	}
	exibirGerente(ger);
	free(ger); 
	free(cpf);
}

///Atualização de Gerente
void atualizarGerente(void) {
    Gerente* ger;
	char* cpf;

	cpf = telaAtualizarGerente();
	ger = buscarGerente(cpf);
	if (ger == NULL) {
    	printf("\n\nGerente não encontrado!\n\n");
  	} else {
		  ger = telaCadastrarGerente();
		  strcpy(ger->cpf, cpf);
		  regravarGerente(ger);
		  // Outra opção:
		  // excluirGerente(cpf);
		  // gravarGerente(ger);
		  free(ger);
	}
	free(cpf);	
}

/// Exclusão de Gerente
void excluirGerente(void) {
	Gerente* ger;
	char *cpf;

	cpf = telaExcluirGerente();
	ger = (Gerente*) malloc(sizeof(Gerente));
	ger = buscarGerente(cpf);
	if (ger == NULL) {
    	printf("\n\nGerente não encontrado!\n\n");
  	} else {
		  ger->status = False;
		  regravarGerente(ger);
		  free(ger);
	}
	free(cpf);
}

///Telas

char menuGerente(void) {
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
	printf("///           (o ! o)  =  = =   Menu Gerente  = = =  (o ! o)              ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar Gerente                                        ///\n");
	printf("///           2. Pesquisar Gerente                                        ///\n");
	printf("///           3. Atualizar Gerente                                        ///\n");
  printf("///           4. Excluir Gerente                                          ///\n");
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

void telaErroGerente(void) {
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
	printf("///           = = = com informações sobre os Gerentes = = = =             ///\n");
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

Gerente* telaCadastrarGerente(void) {
  Gerente *ger;
  
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
	printf("///           = (o ! o) = Cadastro de Gerente = (o ! o) = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
  printf("///                                                                       ///\n");
  ger = (Gerente*) malloc(sizeof(Gerente));

  /// Nome do Gerente
  do{
    printf("///           Nome completo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", ger->nome);
    getchar();
  } while (!validarNome(ger->nome));
  /// Data de nascimento do Gerente
  printf("///           Data de Nascimento (dd/mm/aaaa):  ");
	scanf("%[0-9/]", ger->nasc);
	getchar();
  /// Cpf do Gerente
	printf("///           Digite seu CPF: ");
  scanf(" %[^\n]", ger->cpf);
  while(!validarCPF(ger->cpf)){
    printf("CPF invalido, digite novamente: ");
    scanf(" %[^\n]", ger->cpf);
  }
  ger->status = True;
  printf("\nGerente cadastrado! Digite > Enter < para voltar ao menu Gerente!");
  getchar();
  getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  delay(1);
	return ger;
}

void* telaPesquisarGerente(void) {
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
  printf("///                                UFRN                                   ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)  = Pesquisar Gerente =  (o ! o) = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o cpf do Gerente: ");
	scanf(" %[^\n]", cpf);
  getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return cpf;
}

void* telaAtualizarGerente(void) {
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
  printf("///                                UFRN                                   ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o) =  Atualizar Gerente =  (o ! o) = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o cpf do Gerente:");
	scanf(" %[^\n]", cpf);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  	return cpf;
}

void* telaExcluirGerente(void) {
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
  printf("///                                UFRN                                   ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = (o ! o)  =  Excluir Gerente  = (o ! o)  = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o cpf do Gerente: ");
	scanf(" %[^\n]", cpf);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return cpf;
}

void gravarGerente(Gerente* ger) {
	FILE* fp;

	fp = fopen("gerentes.dat", "ab");
	if (fp == NULL) {
		telaErroGerente();
	}
	fwrite(ger, sizeof(Gerente), 1, fp);
	fclose(fp);
}

Gerente* buscarGerente(char* cpf) {
	FILE* fp;
	Gerente* ger;

	ger = (Gerente*) malloc(sizeof(Gerente));
	fp = fopen("gerentes.dat", "rb");
	if (fp == NULL) {
		telaErroGerente();
	}
	while(fread(ger, sizeof(Gerente), 1, fp)) {
		if ((strcmp(ger->cpf, cpf) == 0) && (ger->status == True)) {
			fclose(fp);
			return ger;
		}
	}
	fclose(fp);
	return NULL;
}

void exibirGerente(Gerente* ger) {

	if (ger == NULL) {
		printf("\n= = = Gerente Inexistente = = =\n");
	} else {
		printf("\n= = = Gerente Cadastrado = = =\n");
		printf("Nome: %s\n", ger->nome);
		printf("CPF: %s\n", ger->cpf);
		printf("Data de Nasc: %s\n", ger->nasc);
		printf("Status: %d\n", ger->status);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}


void regravarGerente(Gerente* ger) {
	int achou;
	FILE* fp;
	Gerente* gerLido;

	gerLido = (Gerente*) malloc(sizeof(Gerente));
	fp = fopen("gerentes.dat", "r+b");
	if (fp == NULL) {
		telaErroGerente();
	}
	// while(!feof(fp)) {
	achou = False;
	while(fread(gerLido, sizeof(Gerente), 1, fp) && !achou) {
		//fread(gerLido, sizeof(Gerente), 1, fp);
		if (strcmp(gerLido->placa, ger->placa) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Gerente), SEEK_CUR);
        	fwrite(ger, sizeof(Gerente), 1, fp);
			//break;
		}
	}
	fclose(fp);
	free(gerLido);
}
