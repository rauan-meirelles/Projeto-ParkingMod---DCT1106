////////////////////////////////////////
////         Módulo Estaciona       ////
////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "estaciona.h"
#include "ultilidade.h"

typedef struct estaciona Estaciona;

void moduloEstaciona(void) {
	char opcao;
	do {
		opcao = menuEstaciona();
		switch(opcao) {
			case '1': 	telaEstacionarVei();
				break;
			case '2': 	telaRetirarVei();
				break;
		} 		
	} while (opcao != '0');
}


char menuEstaciona(void) {
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
	printf("///           = (o ! o) = = Menu Estacionamento = = (o ! o) =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Estacionar um Veículo                                    ///\n");
	printf("///           2. Retirar um Veículo estacionado                           ///\n");
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


Estaciona* telaEstacionarVei(void) {
	Estaciona *est;
  
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
	printf("///           = (o ! o)  =  Estacionar Veículo  =  (o ! o)  =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");

	est = (Estaciona*) malloc(sizeof(Estaciona));

  /// Data de nascimento do Veiculo
  printf("///           Data de Estacionamento do Veículo (dd/mm/aaaa):  ");
  scanf("%d/%d/%d", &est->dia, &est->mes, &est->ano);
  getchar();
  while (!ehData(est->dia, est->mes, est->ano)){
    printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&est->dia, &est->mes, &est->ano);
  }

  /// Placa do Veículo
  printf("///           Placa do Veículo: ");
  scanf(" %[^\n]", est->placa);
  getchar();
	while (!validarPlaca(est->placa)) {
    printf("\nPlaca invalida! Digite novamente: ");
    scanf(" %[^\n]", est->placa);
  }

  FILE* fp;

  fp = fopen("cliente.dat", "rb");
  if (fp == NULL) {
    telaErro();
  }
  Cliente* clix;
  clix = (Cliente*) malloc(sizeof(Cliente));
  int verificador = 1;
  while(fread(clix, sizeof(Cliente), 1, fp)) {
    if ((strcmp(est->placa, clix->placa) == 0) && (clix->status == True)) {
      verificador = 0;
      printf("\nVaga alocada! Digite > Enter < para voltar ao menu Estacionamento!");
      getchar();
      fclose(fp);
      free(clix);

      FILE* fp;
      fp = fopen("estacionamento.dat", "ab");

      if (fp == NULL) {
        telaErro();
        printf("Não é possível continuar o programa...\n");
        exit(1);
      }

      fwrite(est, sizeof(Estaciona), 1, fp);
      fclose(fp);

      est->status = True;
    }
  }

  if (verificador) {
    printf("\nA Vaga não foi alocada! Veículo não cadastrado no sistema! Digite > Enter < para voltar ao menu Estacionamento!");
    free(clix);
    free(est);
    getchar();
  }
  


	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  return est;
}

char* telaRetirarVei(void) {
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
  printf("///                                UFRN                                   ///\n");
	printf("///          ===================================================          ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///         = = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///         (o ! o) Retirar um Veículo do Estacionamento (o ! o)          ///\n");
	printf("///         = = = = = = = = = = = = = = = = = = = = = = = = = =           ///\n");
	printf("///                                                                       ///\n");

  /// Placa do Veículo
  printf("///           Placa do Veículo a ser retirado: ");
  scanf(" %[^\n]", placa);
  getchar();
	while (!validarPlaca(placa)) {
    printf("\nPlaca invalida! Digite novamente: ");
    scanf(" %[^\n]", placa);
    getchar();
  }
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  return placa;
}


/////////////// --------  Estacionamento de Veículo  ------ //////////////////
/*void cadastrarEst(void) {
  Estaciona* est;

	est = telaEstacionarVei();
	gravarEst(est);
	free(est);
}



void gravarEst(Estaciona* est) {
  FILE* fp;
  fp = fopen("estacionamento.dat", "ab");
  if (fp == NULL) {
    telaErro();
    printf("Não é possível continuar o programa...\n");
  exit(1);
  }
  fwrite(est, sizeof(Estaciona), 1, fp);
  fclose(fp);
} 
//////////////////////////////////////////////////////////////////////////////



/////////////// --------  Retirada de Veículo  ------ //////////////////
void retirarVei(void) {
	Estaciona* est;
	char *placa;

	placa = telaRetirarVei();
	est = (Estaciona*) malloc(sizeof(Estaciona));
	est = buscarEst(placa);
	if (est == NULL) {
    	printf("\n\nVeículo não encontrado!\n\n");
  	} else {
		  est->status = False;
	}
	free(placa);
}



void compPlaca(void) {
	Estaciona* est;
	char* placa;

	placa = telaEstacionarVei();
	est = buscarEst(placa);
	free(est); 
	free(placa);
}


Estaciona* buscarEst(char* placa) {
	FILE* fp;
	Estaciona* est;

	est = (Estaciona*) malloc(sizeof(Estaciona));
	fp = fopen("cliente.dat", "rb");
	if (fp == NULL) {
		telaErro();
	}
	while(fread(est, sizeof(Estaciona), 1, fp)) {
		if ((strcmp(est->placa, placa) == 0) && (est->status == True)) {
			fclose(fp);
			return est;
		}
	}
	fclose(fp);
	return NULL;
}
*/
/////////////////////////////////////////////////////////////////////////


void telaErro(void) {
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
