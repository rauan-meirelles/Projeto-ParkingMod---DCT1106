///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///            Projeto Sistema de Controle de Estacionamentos               ///
///              Developed by  @rauan-meirelles - Jan, 2021                 ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cliente.h"
#include "funcionario.h"
#include "gerente.h"
#include "estaciona.h"
#include "relatorio.h" 
#include "utilidade.h"

////////////////////////////////
//// Assinatura das funções ////
////////////////////////////////

char menuPrincipal(void);
void moduloInformacoes(void);
void telaSobre(void);

void moduloRelatorio(void);
void delay(int);

////////////////////////////////
////   Programa principal   ////
////////////////////////////////

int main(void) {
	char opcao;
	do {
		opcao = menuPrincipal();
		switch(opcao) {
			case '1': 	moduloCliente();
						break;
			case '2': 	moduloEstaciona();
						break;
			case '3': 	moduloFuncionario();
						break;
			case '4': 	moduloGerente();
						break;
      case '5': 	moduloRelatorio();
            break;
			case '6': 	moduloInformacoes();
						break;
		} 
	} while (opcao != '0');
	return 0;    
}

char menuPrincipal(void) {
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
	printf("///           = (o ! o) = = =  Menu Principal = = = (o ! o) =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///     1. Módulo Cliente                                                 ///\n");
  printf("///     2. Módulo Estacionamento (Apenas para Clientes cadastrados!)      ///\n");
	printf("///     3. Módulo Funcionário                                             ///\n");
	printf("///     4. Módulo Gerente                                                 ///\n");
  printf("///     5. Módulo Relatório                                               ///\n");
  printf("///     6. Módulo Informações                                             ///\n");
  printf("///                                                                       ///\n");
  printf("///     0. Encerrar programa                                              ///\n");
  printf("///     Escolha a opção desejada: ");
  scanf("%c", &op);
  printf("///                                                                       ///\n");
  printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  delay(1);
	getchar();
  return op;
}


void telaSobre(void) {
  limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///             Universidade Federal do Rio Grande do Norte               ///\n");
	printf("///                 Centro de Ensino Superior do Seridó                   ///\n");
	printf("///               Departamento de Computação e Tecnologia                 ///\n");
	printf("///                  Disciplina DCT1106 -- Programação                    ///\n");
	printf("///            Projeto Sistema de Controle de Estacionamentos             ///\n");
  printf("///                               UFRN                                    ///\n");
 	printf("///              = == ==       PARKINGMOD        = == ==                  ///\n");
	printf("///              Developed by  @rauan-meirelles - Jan, 2021               ///\n");
	printf("///              (o ! o)          (o ! o)        (o ! o)                  ///\n");
  printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///   == == ParkingMod: Um Sistema de Controle de Estacionamentos == ==   ///\n");
	printf("///                                                                       ///\n");
	printf("///    Programa utilizado com a intenção de facilitar a admnistração dos  ///\n");
	printf("///  estacionamentos da UFRN, para fins de organização e de admnistração. ///\n");
  printf("///  O programa contém os principais módulos e funcionalidades úteis que  ///\n");
	printf("///   serão usados para tornar o estacionamneto mais viável e mais bem    ///\n");
	printf("///   avaliado por seus ultilizadores.                                    ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///    Em desenvolvimento pelo aluno de Sistemas da Informação - UFRN     ///\n");
	printf("///                 Rauan Meirelles Dantas de Araújo                      ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}



void moduloInformacoes(void) {
	telaSobre();
}
