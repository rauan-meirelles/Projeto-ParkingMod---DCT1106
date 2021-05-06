////////////////////////////////////////
////         Módulo Relatório       ////
////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estaciona.h"
#include "relatorio.h"
#include "utilidade.h"


void moduloRelatorio(void) {

	char opcao;
	do {
		opcao = menuRelatorio();
		switch(opcao) {
			case '1': veiPorDia();
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
	printf("///       1. Gerar relatório de Veículos estacionados por dia             ///\n");
	printf("///       2. Gerar relatório de Veículos estacionados por ano             ///\n");
	printf("///       3. Gerar relatório de Veículos estacionados ao todo             ///\n");
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

void veiPorDia(void) {
  char* dia;

  dia = telaVeiPorDia();
  relatVeiPorDia(dia);
  free(dia);
}


char* telaVeiPorDia(void) {
	char* dia;

  dia = (char*) malloc(11*sizeof(char));

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
	printf("///   = (o ! o) = Relatório Veículos estacionados por dia = (o ! o) =     ///\n");
	printf("///   = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =     ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o dia desejado: ");
	scanf("%[0-9]", dia);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  return dia;
}

void relatVeiPorDia(char* dia) {
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
	printf("///           = = = = (o ! o) = =  Dia: %s  = = (o ! o) = = =             ///\n", dia);
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
  listaVeiPorDia(dia);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
  printf("///           Tecle <ENTER> para continuar...                             ///");
  getchar();
}

void listaVeiPorDia(char* dia) {
  FILE* fp;
  Estaciona* esta;

  esta = (Estaciona*) malloc(sizeof(Estaciona));
  fp = fopen("estacionamento.dat", "rb");
  while (fread(esta, sizeof(Estaciona), 1, fp)) {
    if (strcmp(esta->dia, dia) == 0) {
		printf("Data de Estacionamento: %d/%d/%d\n", esta->dia,esta->mes,esta->ano);
    printf("Placa: %s\n", esta->placa);
    }
  }
  fclose(fp);
  free(esta);
}





