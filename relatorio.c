////////////////////////////////////////
////         Módulo Relatório       ////
////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "funcionario.h"
#include "gerente.h"
#include "relatorio.h"
#include "utilidade.h"


void moduloRelatorio(void) {
	char opcao;
  Cliente* cli;
  cli = (Cliente*) malloc(sizeof(Cliente));
	do {
		opcao = menuRelatorio();
		switch(opcao) {
			case '1': 	relatorioCliente(cli);
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
	printf("///           1. Exibir relatório de Clientes                             ///\n");
	printf("///           2. Exibir relatório de Funcionários                         ///\n");
	printf("///           3. Exibir relatório de Gerentes                             ///\n");
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada: ");
	scanf("%c", &op);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return op;
}

void relatorioCliente(Cliente* cli) {
  // printf("O total de clientes cadastrados foi: %d\n", cli->cliCad);
}
