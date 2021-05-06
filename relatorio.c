////////////////////////////////////////
////         Módulo Relatório       ////
////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "gerente.h"
#include "estaciona.h"
#include "relatorio.h"
#include "utilidade.h"

typedef struct relatorio Relatorio;

void moduloRelatorio(void) {

	char opcao;

	do {
		opcao = menuRelatorio();
		switch(opcao) {
			case '1': veiPorData();
        break;
      case '2': totalVeiEstacionado();
      break;
      case '3': totalFunciCadastrados();
      break;
      case '4': totalGerCadastrados();
      break;
		} 		
	} while (opcao != '0');
}

//////////////////////
///      Telas     ///
//////////////////////


char menuRelatorio(void) {
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
	printf("///           = (o ! o) = =  Menu Relatório   = =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///       1. Gerar relatório de Veículos estacionados por data            ///\n");
	printf("///       2. Gerar relatório de Veículos                                  ///\n");
  printf("///       3. Gerar relatório de Funcionários                              ///\n");
  printf("///       4. Gerar relatório de Gerentes                                  ///\n");
	printf("///       0. Voltar ao menu anterior                                      ///\n");
	printf("///                                                                       ///\n");
	printf("///       Escolha a opção desejada: ");
	scanf("%c", &op);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return op;
}

///////////////////////////////////////////////////////////////////////////////
//////////////// -----  Veículos por Data (Funções)  ------ ///////////////////
///////////////////////////////////////////////////////////////////////////////

void veiPorData(void) {
  Relatorio* rel;

  rel = telaVeiPorData();
  relatVeiPorData(rel);
  free(rel);
}


Relatorio* telaVeiPorData(void) {
  Relatorio* rel;
  rel = (Relatorio*) malloc(11*sizeof(Relatorio));

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
	printf("///   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =     ///\n");
	printf("///   = (o ! o) = Relatório Veículos estacionados por data = (o ! o)=     ///\n");
	printf("///   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =     ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe a data desejada (dd/mm/aaaa): ");
	scanf("%d/%d/%d", &rel->dia, &rel->mes, &rel->ano);
  getchar();
  while (!ehData(rel->dia, rel->mes, rel->ano)){
    printf("///           Data invalida! Digite novamente (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&rel->dia, &rel->mes, &rel->ano);
  }
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  return rel;
}

void relatVeiPorData(Relatorio* rel) {
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
	printf("///        = = = = = = = = = = = = = = = = = = = = = = = =                ///\n");
	printf("///        = =  (o ! o)  Data de Nasc: %d/%d/%d  (o ! o)                  ///\n", rel->dia,rel->mes,rel->ano);
	printf("///        = = = = = = = = = = = = = = = = = = = = = = = =                ///\n");
	printf("///                                                                       ///\n");
  listaVeiPorData(rel);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("///        Tecle <ENTER> para continuar...                                ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  getchar();
}



void listaVeiPorData(Relatorio* rel) {
  FILE* fp;
  Estaciona* est;
  int verifica;

  est = (Estaciona*) malloc(sizeof(Estaciona));
  fp = fopen("estacionamento.dat", "rb");
    if (fp == NULL) {
		telaErroRelatório();
	}
  verifica = 0;
  while (fread(est, sizeof(Estaciona), 1, fp)) {
    if ((est->dia == rel->dia) && (est->mes == rel->mes) && (est->ano == (rel->ano) && (est->status == True))) {
      verifica = 1;
		  printf("///        Data de Estacionamento: %d/%d/%d                               ///\n", est->dia,est->mes,est->ano);
      printf("///        Placa: %s                                                 ///\n", est->placa);
    }
  }
  if (!verifica) {
    printf("Nenhum veículo foi estacionado na data desejada!");
  }
  fclose(fp);
  free(est);
}
/////////////////////////////////////////////////////////////////////////////
/////////////                                                ////////////////
/////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
//////////////// -----  Total de Veículos (Funções)  ------ ///////////////////
///////////////////////////////////////////////////////////////////////////////

void totalVeiEstacionado(void) {

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
	printf("///          = = = = = = = = = = = = = = = = = = = = = = =                ///\n");
	printf("///          (o ! o)  Total de Veículos Estacionados  (o ! o)             ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
	printf("///                                                                       ///\n");
  listaVeiTotal();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("///        Tecle <ENTER> para continuar...                                ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  getchar();

}

void listaVeiTotal(void) {
  FILE* fp;
  Estaciona* est;
  int verifica;

  verifica = 0;

  est = (Estaciona*) malloc(sizeof(Estaciona));
  fp = fopen("estacionamento.dat", "rb");
  if (fp == NULL) {
		telaErroRelatório();
	}
  while (fread(est, sizeof(Estaciona), 1, fp)) {
    if (est->status == True) {
      verifica = 1;
		  printf("///          Data de Estacionamento: %d/%d/%d                               ///\n", est->dia,est->mes,est->ano);
      printf("///          Placa: %s                                                 ///\n", est->placa);
    }
  }
  if (!verifica) {
    printf("Não há Veículos	estacionados no momento");
  }
  fclose(fp);
  free(est);
}

///////////////////////////////////////////////////////////////////////////////
////////////////                                            ///////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/////////////// ----- Total de Funcionários (Funções) ------ //////////////////
///////////////////////////////////////////////////////////////////////////////

void totalFunciCadastrados(void) {

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
	printf("///         = = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///         (o ! o) Total de Funcionários Cadastrados (o ! o)             ///\n");
	printf("///         = = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
  listaFunciTotal();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("///         Tecle <ENTER> para continuar...                               ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  getchar();

}

void listaFunciTotal(void) {
  FILE* fp;
  Funcionario* funci;
  int verifica;

  verifica = 0;

  funci = (Funcionario*) malloc(sizeof(Funcionario));
  fp = fopen("funcionarios.dat", "rb");
  if (fp == NULL) {
		telaErroRelatório();
	}
  while (fread(funci, sizeof(Funcionario), 1, fp)) {
    if (funci->status == True) {
      verifica = 1;
		  printf("///          Nome: %s\n", funci->nome);
		  printf("///          CPF: %s\n", funci->cpf);
		  printf("///          Data de Nasc: %d/%d/%d\n", funci->dia,funci->mes,funci->ano);
    }
  }
  if (!verifica) {
    printf("Não há Funcionários cadastrados no momento");
  }
  fclose(fp);
  free(funci);
}

///////////////////////////////////////////////////////////////////////////////
////////////////                                            ///////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
///////////////   ----- Total de Gerentes (Funções) ------   //////////////////
///////////////////////////////////////////////////////////////////////////////

void totalGerCadastrados(void) {

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
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
	printf("///          =(o ! o) Total de Gerentes Cadastrados (o ! o)=              ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
	printf("///                                                                       ///\n");
  listaGerTotal();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("///          Tecle <ENTER> para continuar...                              ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  getchar();

}

void listaGerTotal(void) {
  FILE* fp;
  Gerente* ger;
  int verifica;

  verifica = 0;

  ger = (Gerente*) malloc(sizeof(Gerente));
  fp = fopen("gerentes.dat", "rb");
    if (fp == NULL) {
		telaErroRelatório();
	}
  while (fread(ger, sizeof(Gerente), 1, fp)) {
    if (ger->status == True) {
      verifica = 1;
		  printf("///          Nome: %s\n", ger->nome);
		  printf("///          CPF: %s\n", ger->cpf);
    }
  }
  if (!verifica) {
    printf("Não há Gerentes cadastrados no momento");
  }
  fclose(fp);
  free(ger);
}

///////////////////////////////////////////////////////////////////////////////
////////////////                                            ///////////////////
///////////////////////////////////////////////////////////////////////////////


void telaErroRelatório(void) {
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
	printf("///           =  com informações sobre o Relatório desejado =             ///\n");
  printf("///           = = = =  Erro: Arquivo não existente  = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = =  Pedimos desculpas pelos inconvenientes = =             ///\n");
	printf("///           = = =  mas este programa será finalizado! = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Tecle <ENTER> para encerrar...                              ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
	getchar();
	exit(1);
}
